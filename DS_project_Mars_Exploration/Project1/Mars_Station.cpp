#include"Mars_Station.h"
#include"UI_Class.h"
#include <fstream>
#include"Mission.h"
#include"Rovers.h"
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
		Available_Emergency_Rovers.enqueue(*rover1);
		rover1 = NULL;
	}

	//close file
	inputFile.close();
	return;
}
void Mars_Station::Save_OutputFile()
{
	int arr[5] = { 18,1,7,5,6 };
	//Create new Output File
	ofstream outputFile;
	UI1.Save_InputFile_UI(outputFile);//call function save of class UI_Class
	outputFile << "CD   ID   FD   WD   ED "<< endl;
	outputFile << arr[0] << "   ";
	outputFile << arr[1] << "    ";
	outputFile << arr[2] << "    ";
	outputFile << arr[3] << "    ";
	outputFile << arr[4] <<endl;
	outputFile << "������������������" << endl << "������������������" << endl<<endl;
	outputFile << "Missions:" << endl;
	outputFile << "Rovers:" << endl;
	outputFile << "Avg Wait = " <<7<<", Avg Exec ="<< endl;
	if (outputFile.is_open())
		outputFile.close();

}



void Mars_Station::checkinExcecRovers(int Day)
{
	Nodo<Rovers>* RR = InExcecution_Rovers.getHead();
	while (RR)
	{
		if (RR->getitem().finishmission(Day))
		{
			if (RR->getitem().putinchecko())
			{
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
	if (MM->getitem().finishmission())
	{
		if (MM->getitem().getType() == 'P')
		{

			Completed_Polar_Missions.enqueue(MM->getitem());
		}
		else
		{
			Completed_Emergency_Missions.enqueue(MM->getitem());
		}
		MM->getitem().startofExcecutiondayo(0);
		InExcecution_Missions.DeleteNode(MM);
	}
	else
	{
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
	event_->Execute(waitingEmergency_Missions, waitingPolar_Missions);
	//delete (*event_)
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
		if (RR->getitem().getfromchecko(Day))
		{
			RR->getitem().getfromchecko(Day);
			if (RR->getitem().getType() == 'P')
				Available_Polar_Rovers.enqueue(RR->getitem());
			else
				Available_Emergency_Rovers.enqueue(RR->getitem());
			Checkup_Rovers.DeleteNode(RR);
		}
		else
		{
			RR = RR->getnext();
		}
	}
}
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
	UI1.Output_Screen_Console(ModeNo ,Current__Day , waitingPolar_Missions, waitingEmergency_Missions, Available_Polar_Rovers, Available_Emergency_Rovers, Completed_Polar_Missions, Completed_Emergency_Missions);
}

Mars_Station::~Mars_Station()
{
}

int main()
{
	//HERE we call functions ONLY
	Mars_Station M1;
	while (!(M1.The_Simulation_Is_Completed()))
	{
		M1.increase_Current__Day();
		//ahmed heikal CALL el fn assign rover w kol el fn el tania bta3t simulation hena
		M1.checkinCheckup(M1.get_Current__Day());
		M1.checkinExcecRovers(M1.get_Current__Day());
		M1.Loop_On_Events_In_Same_Day();
		M1.scanEmergencyMissions(M1.get_Current__Day());
		M1.scanPolarMissions(M1.get_Current__Day());
		
		
	

		//output daily
		if(M1.getModeNo()!=3)
			M1.Program_Output_Modes();       

		//break;
	}
	///*M1.Save_OutputFile();*/
	return 0;
}
