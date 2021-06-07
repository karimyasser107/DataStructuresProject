#include"UI_Class.h"
#include"Event.h"
#include"formulationEvent.h"
#include"LinkedList.h"
#include<iostream>
#include <fstream>
using namespace std;

UI_Class::UI_Class()
{
}

void UI_Class::Read_InputFile_UI(ifstream & inputFile, int* array_of_info_inputfile, LinkedList<Event*>& Events_List)
{
	cout << "                    Mars Station" << endl << endl;
	//Print Action Message 
	string File_Name;
	cout << ("Load an Exicting Input File: Please enter File Name (.txt)  ") << endl;
	cin >> File_Name;
	//open the file
	inputFile.open(File_Name);
	if (inputFile.is_open())
		cout << "Load Input File was Done successfully " << endl<<endl;
	else
	{
		do
		{
			cout << ("Error: File was not Found") << endl;
			cout << "Please enter File Name (.txt)  " << endl;
			cin >> File_Name;
			inputFile.open(File_Name);
		} while (!inputFile.is_open());
		cout <<"Load Input File was Done successfully " << endl<<endl;
	}
		

	//read first line (number of rovers)
	//NOW first 2 elements of the array contains number of Rovers of each type : Polar , Emergency (respectively)
	inputFile >> array_of_info_inputfile[0]>> array_of_info_inputfile[1];

	//read second line (rovers speed)
	//array contains the Rovers speed of each type : Polar , Emergency (respectively)
	inputFile >> array_of_info_inputfile[2];inputFile >> array_of_info_inputfile[3];

	//read third line (N, CP, CE)
	//N: is the number of missions the rover completes before performing a checkup
	//CP: is the checkup duration in days for polar rovers 
	//CE: is the checkup duration in days for emergency rovers
	inputFile >> array_of_info_inputfile[4] >> array_of_info_inputfile[5] >> array_of_info_inputfile[6];

	//read the fourth line (E: number of events)
	inputFile >> array_of_info_inputfile[7];

	//read the Events lines (one line for each event)
	char event_or_mission_type;
	int temp_input;
	
	while (!inputFile.eof())
	{
		inputFile >> event_or_mission_type;
		if (event_or_mission_type == 'F')
		{
			//creat an object of type FormulationEvent
			formulationEvent **F_event=new formulationEvent*;
			*F_event = new formulationEvent;
			//insert the created formulationEvent to the Events_List (LinkedList)(insert at end)
			//Events_List.
			inputFile >> event_or_mission_type;//read the mission type
			(*F_event)->set_Type(event_or_mission_type);
			inputFile >> temp_input;//read event day
			(*F_event)->set_EventDay(temp_input);
			inputFile >> temp_input;//read mission ID
			(*F_event)->set_MissionID(temp_input);
			inputFile >> temp_input;//read Target Location
			(*F_event)->set_TargetLocation(temp_input);
			inputFile >> temp_input;//read mission Duration
			(*F_event)->set_MissionDuration(temp_input);
			inputFile >> temp_input;//read mission Significance
			(*F_event)->set_Significance(temp_input);
			Events_List.InsertEnd((*F_event));
			delete F_event;
			F_event = NULL;
		}
	}

	//close file
	//inputFile.close();
	return;
}
void UI_Class::Save_InputFile_UI(LinkedQueue<Rovers>Available_Polar_Rovers, LinkedQueue<Rovers>Available_Emergency_Rovers, LinkedQueue<Mission>Completed_Polar_Missions, LinkedQueue<Mission>Completed_Emergency_Missions)
{
	//Print Action Message
	//Create new Output File
	ofstream outputFile;

	//Print Action Message 
	string File_Name;
	cout<<("Save Output File: Please enter File Name (example.txt)  ")<<endl;
	cin >> File_Name;

	//open the file
	outputFile.open(File_Name, ios::out);

	//Clculate total number of missions
	int TOT_number_Emerg_Missions = Completed_Emergency_Missions.getQueueSize();
	int TOT_number_Polar_Missions = Completed_Polar_Missions.getQueueSize();

	//calculate total number of Rovers
	int total_Available_Polar_Rovers = Available_Polar_Rovers.getQueueSize();
	int total_Available_Emerg_Rovers = Available_Emergency_Rovers.getQueueSize();
	int Total_No_Missions = TOT_number_Emerg_Missions + TOT_number_Polar_Missions;

	//create a new list
	while (true)
	{

	}
	int arr[5] = { 18,1,7,5,6 };

	outputFile << "CD   ID   FD   WD   ED " << endl;
	

	outputFile << arr[0] << "   ";
	outputFile << arr[1] << "    ";
	outputFile << arr[2] << "    ";
	outputFile << arr[3] << "    ";
	outputFile << arr[4] << endl;


	outputFile << "������������������" << endl << "������������������" << endl << endl;
	
	

	outputFile << "Missions: " << Total_No_Missions;
	outputFile << "     [P: " << TOT_number_Polar_Missions << ", E: " << TOT_number_Emerg_Missions << "]" << endl;
	outputFile << "Rovers: " << total_Available_Emerg_Rovers+total_Available_Polar_Rovers ;
	outputFile << "      [P: " << total_Available_Polar_Rovers << ", E: " << total_Available_Emerg_Rovers << "]" << endl;
	outputFile << "Avg Wait = " << 7 << ", Avg Exec =" << endl;
	if (outputFile.is_open())
		outputFile.close();
	cout << ("Output File is generated and Saved succesfully ") << endl;
	return;
	
}

int UI_Class::choosingInterfaceMode()
{
	cout << "Please enter the mode you want:" << endl;
	cout << "1- Interactive Mode" << endl;
	cout << "2- Step-By-Step Mode" << endl;
	cout << "3- Silent Mode" << endl;

	cout << "Your Choice:";
	int choice;
	cin >> choice;

	return choice;
}

void UI_Class::Output_Screen_Console(int ModeNo,int current_Day,LinkedQueue<Mission>WaitingPolar, PriorityQueue<Mission>WaitingEmergency, LinkedQueue<Rovers>Available_Polar_Rovers, LinkedQueue<Rovers>Available_Emergency_Rovers,  LinkedQueue<Mission>Completed_Polar_Missions, LinkedQueue<Mission>Completed_Emergency_Missions)
{

	//kareem el sheikh
	cout << endl;
	cout << "Current Day :" << current_Day << endl;
	Mission X;
	Rovers Y;
	int totalWaitingMissions = WaitingPolar.getQueueSize() + WaitingEmergency.getprioQueueSize();
	cout << totalWaitingMissions<< " " << "Waiting Missions:" << "   " << "[";
	while (WaitingEmergency.dequeue(X))
	{
		cout << X.getID() << "";
		if (!WaitingEmergency.isEmpty())
			cout << ",";
	}
	cout << "]" << "       " << "(";
	while (WaitingPolar.dequeue(X))
	{
		cout << X.getID() << "";
		if (!WaitingPolar.isEmpty())
			cout << ",";
	}
	cout << ")" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	//int inExecutionMission = InExcecution_Missions.getListSize();
	//cout << inExecutionMission<< " " << "In-Execution Missions/Rovers:" << "   ";
	//Nodo<Mission>* ptrME = InExcecution_Missions.getHead();
	//cout << "[" << "";
	///*cout << endl << endl << endl << endl << endl << endl << endl;*/
	//while (ptrME)
	//{
	//	if (ptrME->getitem().getType() == 'E')
	//	{
	//		cout << ptrME->getitem().getID() << "/" << ptrME->getitem().getIDofRoverExcecuting() << " ";
	//		if (ptrME->getnext())
	//			if (ptrME->getnext()->getitem().getType() == 'E')
	//				   cout << ",";
	//	}
	//	ptrME = ptrME->getnext();
	//}
	//cout << "]" << "      ";
	/*Nodo<Mission>* ptrMP = InExcecution_Missions.getHead();
	cout << "(" << "";
	while (ptrMP)
	{
		if (ptrMP->getitem().getType() == 'P')
		{
			cout << ptrMP->getitem().getID() << "/" << ptrMP->getitem().getIDofRoverExcecuting() << " ";
			if (ptrMP->getnext())
				if(ptrMP->getnext()->getitem().getType()=='P')
				    cout << ",";
		}
		ptrMP = ptrMP->getnext();
	}*/
	cout << ")" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	int totalAvailableRovers = Available_Emergency_Rovers.getQueueSize() + Available_Polar_Rovers.getQueueSize();
	cout << totalAvailableRovers<< " " << " Available Rovers:" << "      " << "[";
	while (Available_Emergency_Rovers.dequeue(Y))
	{
		cout << Y.getID() << "";
		if (!Available_Emergency_Rovers.isEmpty())
			cout << ",";
	}
	cout << "]" << "        " << "(";
	while (Available_Polar_Rovers.dequeue(Y))
	{
		cout << Y.getID() << "";
		if (!Available_Polar_Rovers.isEmpty())
			cout << ",";
	}
	cout << ")" << endl;
	cout<<"--------------------------------------------------------------------------------------------"<<endl;
	/*int totalCheckupRovers = Checkup_Rovers.getListSize();
	cout << totalCheckupRovers<< " " << "In-Checkup Rovers:" << "      ";
	Nodo<Rovers>* ptrRE = Checkup_Rovers.getHead();
	cout << "[" << "  ";
	while (ptrRE != nullptr)
	{
		if (ptrRE->getitem().getType() == 'E')
		{
			cout << ptrRE->getitem().getID() << "  ";
			if (ptrRE->getnext()!=nullptr)
				cout << ",";
		}
	}
	cout << ']' << "       ";
	Nodo<Rovers>* ptrRP = Checkup_Rovers.getHead();
	cout << "(" << "  ";
	while (ptrRP != nullptr)
	{
		if (ptrRP->getitem().getType() == 'P')
		{
			cout << ptrRP->getitem().getID() << "  ";
			if (ptrRP->getnext()!=nullptr)
				cout << ",";
		}
		ptrRP=ptrRP->getnext();
	}*/
	cout << ')' << endl ;
	cout << "--------------------------------------------------------------------------------------------" << endl;

	int totalCompletedMissions = Completed_Emergency_Missions.getQueueSize() + Completed_Polar_Missions.getQueueSize();
	cout << totalCompletedMissions<< " " << "Completed Missions:" << "      ";
	cout << "[" << "";
	while (Completed_Emergency_Missions.dequeue(X))
	{
		cout << X.getID() << "";
		if (!Completed_Emergency_Missions.isEmpty())
			cout << ",";
	}
	cout << "]" << "     ";

	cout << "(" << " ";
	while (Completed_Polar_Missions.dequeue(X))
	{
		cout << X.getID() << "";
		if (!Completed_Polar_Missions.isEmpty())
			cout << ",";
	}
	cout << ")" << endl;

	if (ModeNo == 1)
	{
		cout << "please enter any key to show next day's output:" << endl;
		char wait_user;
		cin >> wait_user;
	}
	if (ModeNo == 2)
	{
		Sleep(2000);
	}
}


UI_Class::~UI_Class()
{
}