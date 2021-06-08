#include"Mars_Station.h"
#include"UI_Class.h"
#include <fstream>
#include"Mission.h"
#include"Rovers.h"
#include <time.h>
using namespace std;

Mars_Station::Mars_Station()
{
	Current__Day = 0;
	Read_InputFile(Events_List,Available_Emergency_Rovers, Available_Polar_Rovers);
	ModeNo = UI1.choosingInterfaceMode();
}

void Mars_Station::increase_Current__Day()
{
	Current__Day ++;
}

int Mars_Station::get_Current__Day()
{
	return Current__Day;
}

void Mars_Station::Read_InputFile(LinkedList<Event*>&Event_List , LinkedQueue<Rovers>&Available_Emergency_Rovers, LinkedQueue<Rovers>&Available_Polar_Rovers)
{
	ifstream inputFile;
	int array_of_info_inputfile[8];
	UI1.Read_InputFile_UI(inputFile, array_of_info_inputfile,Event_List);

	//read first line (number of rovers)
	int N_Rovers[2];//array contains number of Rovers of each type : Polar , Emergency (respectively)
	N_Rovers[0]= array_of_info_inputfile[0]; 
	N_Rovers[1]= array_of_info_inputfile[1];

	//read second line (rovers speed)
	int Speed_Rovers[2];//array contains the Rovers speed of each type : Polar , Emergency (respectively)
	Speed_Rovers[0]= array_of_info_inputfile[2];Speed_Rovers[1]= array_of_info_inputfile[3];

	//read third line (N, CP, CE)
	N_mission_before_checkup= array_of_info_inputfile[4];//N: is the number of missions the rover completes before performing a checkup
	int Check_up_Duration_Polar_Rov= array_of_info_inputfile[5];//CP: is the checkup duration in days for polar rovers 
	int Check_up_Duration_Emerg_Rov= array_of_info_inputfile[6];//CE: is the checkup duration in days for emergency rovers
	
	//read the fourth line (E: number of events)
	int N_Events= array_of_info_inputfile[7];
	
	//unique ID for each Rover
	int Unique_ID_Rover = 0;
	//fill the polar rover Queue
	for(int i=0;i< N_Rovers[0];i++)
	{
		Unique_ID_Rover++;
		Rovers* rover1= new Rovers;
		rover1->setSpeed(Speed_Rovers[0]);
		rover1->setCheckupDuration(Check_up_Duration_Polar_Rov);
		rover1->setType('P');
		rover1->setID(Unique_ID_Rover);
		rover1->setN_mission_before_checkup(N_mission_before_checkup);
		rover1->setCurrentDay(Current__Day);
		Available_Polar_Rovers.enqueue(*rover1);
		rover1 = NULL;
	}
	//fill the emergency rover Queue
	Unique_ID_Rover = 0;
	for (int i = 0;i < N_Rovers[1];i++)
	{
		Unique_ID_Rover++;
		Rovers* rover1 = new Rovers;
		rover1->setSpeed(Speed_Rovers[1]);
		rover1->setCheckupDuration(Check_up_Duration_Emerg_Rov);
		rover1->setType('E');
		rover1->setID(Unique_ID_Rover);
		rover1->setN_mission_before_checkup(N_mission_before_checkup);
		rover1->setCurrentDay(Current__Day);
		Available_Emergency_Rovers.enqueue(*rover1);
		rover1 = NULL;
	}

	//close file
	inputFile.close();
	return;
}
void Mars_Station::Save_OutputFile()
{
	//call function save of class UI_Class
	UI1.Save_InputFile_UI(ModeNo,Available_Polar_Rovers, Available_Emergency_Rovers, Completed_Polar_Misssions, Completed_Emergency_Missions);
}



void Mars_Station::checkinExcecRovers(int Day)
{
	Nodo<Rovers>* RR = InExcecution_Rovers.getHead();
	while (RR)
	{
		RR->getitem().setCurrentDay(Day);
		RR = RR->getnext();
	}
	RR = InExcecution_Rovers.getHead();
	while (RR)
	{
		if (RR->getitem().finishmission(Day))
		{
			if (RR->getitem().putinchecko())
			{
				RR->getitem().setstartcheckupday(Day);
				RR->getitem().putinchecko();
				RR->getitem().setstartcheckupday(Day);
				Checkup_Rovers.InsertEnd(RR->getitem());
				InExcecution_Rovers.DeleteNode(RR);
			}
			else
			{
				if (RR->getitem().getType() == 'P')
					Available_Polar_Rovers.enqueue(RR->getitem());
				else
					Available_Emergency_Rovers.enqueue(RR->getitem());
				InExcecution_Rovers.DeleteNode(RR);
			}
		}
		else
		{
			RR = RR->getnext();
		}
	}
}

void Mars_Station::checkinMissinExcec(int Day)
{
	Nodo<Mission>* MM = InExcecution_Missions.getHead();
	while (MM)
	{
		if (MM->getitem().finishmission(Day))
		{
			if (MM->getitem().getType() == 'P')
			{

				Completed_Polar_Misssions.enqueue(MM->getitem());
			}
			else
			{
				Completed_Emergency_Missions.enqueue(MM->getitem());
			}
			MM->getitem().startofExcecutiondayo(0);
			InExcecution_Missions.DeleteNode(MM);
		}
		MM = MM->getnext();
	}
}

bool Mars_Station::EventsList_is_Not_Empty()
{
	if (Events_List.isEmpty())
		return false;
	return true;
}

void Mars_Station::Excute_Event_In_Certain_Day()
{
	Event* event_;
	Events_List.DeleteHead(event_);
	//call function excute of Event class
	event_->Execute(waitingEmergency_Missions, waitingPolar_Missions);
	delete event_;
}

void Mars_Station::Loop_On_Events_In_Same_Day()
{
	if (!EventsList_is_Not_Empty())//karim yasser ghayar di 
		return;
	
	SameDay = Events_List.getHead()->getitem()->get_EventDay();
	if (SameDay != Current__Day)
		return;
	do
	{
		Excute_Event_In_Certain_Day();
	} while (Events_List.getHead() && Events_List.getHead()->getitem()->get_EventDay() == SameDay);
	
}

void Mars_Station::scanEmergencyMissions(int Day)
{
	while (!waitingEmergency_Missions.isEmpty())
	{
		if (!Available_Emergency_Rovers.isEmpty())
		{
			Mission EX;
			Rovers ER;
			Available_Emergency_Rovers.dequeue(ER);
			ER.setstartofMissionday(Day);
			int missionduration = int(2 * (EX.getTargetLocation() / ER.getspeed()) / 24) + EX.getMDUR();
			EX.setCompletionday(missionduration + Day);
			EX.setMissinDuration(missionduration);
			InExcecution_Rovers.InsertEnd(ER);
			waitingEmergency_Missions.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			EX.startofExcecutiondayo(Day);
			InExcecution_Missions.InsertEnd(EX);
		}
		else if (!Available_Polar_Rovers.isEmpty())
		{
			Mission EX;
			Rovers ER;
			int missionduration = int(2 * (EX.getTargetLocation() / ER.getspeed()) / 24) + EX.getMDUR();
			EX.setCompletionday(missionduration + Day);
			EX.setMissinDuration(missionduration);
			Available_Polar_Rovers.dequeue(ER);
			InExcecution_Rovers.InsertEnd(ER);
			waitingEmergency_Missions.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			InExcecution_Missions.InsertEnd(EX);
			EX.startofExcecutiondayo(Day);
			ER.setstartofMissionday(Day);
		}
		else
			return;
	}
	return;
}

void Mars_Station::scanPolarMissions(int Day)
{
	while (!waitingPolar_Missions.isEmpty())
	{
		if (!Available_Polar_Rovers.isEmpty())
		{
			Mission EX;
			Rovers ER;
			int missionduration = int(2 * (EX.getTargetLocation() / ER.getspeed()) / 24) + EX.getMDUR();
			EX.setCompletionday(missionduration + Day);
			EX.setMissinDuration(missionduration);
			Available_Polar_Rovers.dequeue(ER);
			InExcecution_Rovers.InsertEnd(ER);
			waitingPolar_Missions.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			InExcecution_Missions.InsertEnd(EX);
			EX.startofExcecutiondayo(Day);
			ER.setstartofMissionday(Day);
		}
		else
			return;
	}
	return;
}



void Mars_Station::checkinCheckup(int Day)
{
	if (Checkup_Rovers.isEmpty())
		return;
	Nodo<Rovers>* RR = Checkup_Rovers.getHead();
	while (RR)
	{
		RR->getitem().setCurrentDay(Day);
		RR = RR->getnext();
	}
	
	while (RR)
	{
		if (RR->getitem().getfromchecko(Day))
		{
			RR->getitem().getfromchecko(Day);
			if (RR->getitem().getType() == 'P')
				Available_Polar_Rovers.enqueue(RR->getitem());
			else
				Available_Emergency_Rovers.enqueue(RR->getitem());
			Checkup_Rovers.DeleteNode(RR);
		}
			RR = RR->getnext();
	}
}
//BONUS //Ahmed Fayez
void Mars_Station::Mission_Failure()
{
	if (InExcecution_Missions.isEmpty())
		return;

	//generate a random position in list of Missions 
	srand(time(NULL));
	int N_missions = InExcecution_Missions.getListSize();
	int Random_Pos_Mission = rand() % N_missions + 1;
	Nodo<Mission>* Node_Mission_to_be_Failed = NULL;
	Node_Mission_to_be_Failed = InExcecution_Missions.getNode_With_Pos(Random_Pos_Mission);
	Mission Mission_to_be_Failed = Node_Mission_to_be_Failed->getitem();

	//generate a random number to indicate the probability of a Mission to be Failed
	int Failure_Prob = rand() % 100 + 1;

	if (Failure_Prob > 90 && Node_Mission_to_be_Failed->getitem().getTargetLocation() > 500)
	{
		//3 things MUST happen to enter here (to make the Mission Failure Probability very low)
		//1. failure prob must be > 95 %
		//2. target location must be > 500 km
		//3. Current day must be divisible by 3 


		//InExcecution_Missions.DeleteNode(Node_Mission_to_be_Failed);
		int x = Mission_to_be_Failed.getIDofRoverExcecuting();
		Rovers FRover;
		Nodo<Rovers>* F_ptr = InExcecution_Rovers.getHead();

		if (Mission_to_be_Failed.getType() == 'E')
		{
			Mission_to_be_Failed.setIDofRoverExcecuting(-1);
			waitingEmergency_Missions.push(Mission_to_be_Failed, Mission_to_be_Failed.getSignificance());
			
			// set day to be ZERO
			InExcecution_Missions.DeleteNode(Node_Mission_to_be_Failed);

			/////////////////////

			while (F_ptr)
			{
				if (F_ptr->getitem().getID() == x)
				{
					FRover = F_ptr->getitem();
					Checkup_Rovers.InsertEnd(FRover);
					InExcecution_Rovers.DeleteNode(F_ptr);
					break;
				}
				F_ptr = F_ptr->getnext();
			}
		}

		if (Mission_to_be_Failed.getType() == 'P')
		{
			Mission_to_be_Failed.setIDofRoverExcecuting(-1);
			waitingPolar_Missions.enqueue(Mission_to_be_Failed);
			
			// set day to be ZERO
			InExcecution_Missions.DeleteNode(Node_Mission_to_be_Failed);

			/////////////////////

			while (F_ptr)
			{
				if (F_ptr->getitem().getID() == x)
				{
					FRover = F_ptr->getitem();
					Checkup_Rovers.InsertEnd(FRover);
					InExcecution_Rovers.DeleteNode(F_ptr);
					break;
				}
				F_ptr = F_ptr->getnext();
			}
		}
	}
	return;
}


//Output

int Mars_Station::getModeNo()
{
	return ModeNo;
}

bool Mars_Station::The_Simulation_Is_Completed()
{
	if (Events_List.isEmpty() && waitingEmergency_Missions.isEmpty() && waitingPolar_Missions.isEmpty() && InExcecution_Rovers.isEmpty() && Checkup_Rovers.isEmpty())//complete this karim yasser
		return true;
	else
		return false;
}

void Mars_Station :: Program_Output_Modes()
{
	UI1.Output_Screen_Console(ModeNo ,Current__Day , waitingPolar_Missions, waitingEmergency_Missions, Available_Polar_Rovers, Available_Emergency_Rovers,InExcecution_Missions,Checkup_Rovers ,Completed_Polar_Misssions, Completed_Emergency_Missions);
}

Mars_Station::~Mars_Station()
{
	
}

int main()
{
	//HERE we call functions ONLY
	Mars_Station M1;
	if (M1.getModeNo() == 3)

	while (!(M1.The_Simulation_Is_Completed()))
	{
		M1.increase_Current__Day();
		//ahmed heikal CALL el fn assign rover w kol el fn el tania bta3t simulation hena
		M1.checkinCheckup(M1.get_Current__Day());
		M1.checkinExcecRovers(M1.get_Current__Day());
		M1.checkinMissinExcec(M1.get_Current__Day());
		M1.Loop_On_Events_In_Same_Day();
		M1.scanEmergencyMissions(M1.get_Current__Day());
		M1.scanPolarMissions(M1.get_Current__Day());
		
	


		//BONUS
		if (M1.get_Current__Day() % 3 == 0)
			M1.Mission_Failure();

		//output daily
		if(M1.getModeNo()!=3)
			M1.Program_Output_Modes();       
		

			
	}
	M1.Save_OutputFile();
	return 0;
}
