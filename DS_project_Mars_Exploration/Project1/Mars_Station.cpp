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
	N_Rovers[0]= array_of_info_inputfile[0]; N_Rovers[1]= array_of_info_inputfile[1];

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
	int Unique_ID_Rover = 11899;
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
	outputFile << "………………………………………………" << endl << "………………………………………………" << endl<<endl;
	outputFile << "Missions:" << endl;
	outputFile << "Rovers:" << endl;
	outputFile << "Avg Wait = " <<7<<", Avg Exec ="<< endl;
	if (outputFile.is_open())
		outputFile.close();

}



void Mars_Station::checkinExcec(int Day)
{
	Nodo<Rovers>* RR = CHX.getHead();
	while (RR)
	{
		if (RR->getitem().finishmission(Day))
		{
			if (RR->getitem().putinchecko())
			{
				RR->getitem().putinchecko();
				CHR.InsertEnd(RR->getitem());
				CHX.DeleteNode(RR);
			}
			else
			{
				if (RR->getitem().getType() == 'P')
					Available_Polar_Rovers.enqueue(RR->getitem());
				else
					Available_Emergency_Rovers.enqueue(RR->getitem());
				CHX.DeleteNode(RR);
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
	Nodo<Mission>* MM = ExcM.getHead();
	if (MM->getitem().finishmission())
	{
		if (MM->getitem().getType() == 'P')
		{

			CompP.enqueue(MM->getitem());
		}
		else
		{
			CompEm.enqueue(MM->getitem());
		}
		ExcM.DeleteNode(MM);
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
	event_->Execute(waitingEm, waitingPola);
	//delete (*event_)
	delete event_;
}

void Mars_Station::Loop_On_Events_In_Same_Day()
{
	if (!EventsList_is_Not_Empty())//karim yasser ghayar di 
		return;
	SameDay = Events_List.getHead()->getitem()->get_EventDay();
	do
	{
		Excute_Event_In_Certain_Day();
	} while (Events_List.getHead() && Events_List.getHead()->getitem()->get_EventDay() == SameDay);
	
}

void Mars_Station::scanEmergencyMissions()
{
	while (!waitingEm.isEmpty())
	{
		if (!RFEm.isEmpty())
		{
			Mission EX;
			Rovers ER;
			RFEm.dequeue(ER);
			CHX.InsertEnd(ER);
			waitingEm.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			ExcM.InsertEnd(EX);
		}
		else if (!RFP.isEmpty())
		{
			Mission EX;
			Rovers ER;
			RFP.dequeue(ER);
			CHX.InsertEnd(ER);
			waitingEm.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			ExcM.InsertEnd(EX);
		}
		else
			return;
	}
}

void Mars_Station::scanPolarMissions()
{
	while (!waitingPola.isEmpty())
	{
		if (!RFP.isEmpty())
		{
			Mission EX;
			Rovers ER;
			RFEm.dequeue(ER);
			CHX.InsertEnd(ER);
			waitingEm.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			ExcM.InsertEnd(EX);
		}
		else
			return;
	}
}



void Mars_Station::checkinCheckup(int Day)
{
	Nodo<Rovers>* RR = CHR.getHead();
	while (RR)
	{
		if (RR->getitem().getfromchecko(Day))
		{
			RR->getitem().getfromchecko(Day);
			if (RR->getitem().getType() == 'P')
				Available_Polar_Rovers.enqueue(RR->getitem());
			else
				Available_Emergency_Rovers.enqueue(RR->getitem());
			CHR.DeleteNode(RR);
		}
		else
		{
			RR = RR->getnext();
		}
	}
}

bool Mars_Station::The_Simulation_Is_Completed()
{
	if (Events_List.isEmpty() && waitingEm.isEmpty() && waitingPola.isEmpty())//complete this karim yasser
		return true;
	else
		return false;
}

void Mars_Station :: Program_Output_Modes()
{
	UI1.Output_Screen_Console(waitingPola, waitingEm, Available_Polar_Rovers, Available_Emergency_Rovers);
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
		
		M1.Loop_On_Events_In_Same_Day();

		
	

		//output daily
		M1.Program_Output_Modes();
		break;
	}

	//M1.EventsList_is_Not_Empty();

	///*M1.Save_OutputFile();*/
	////M1.Read_InputFile();
	

}
