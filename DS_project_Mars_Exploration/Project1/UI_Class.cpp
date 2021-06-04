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
	//Print Action Message 
	string File_Name;
	cout << ("Load an Exicting Input File: Please enter File Name (.txt)  ") << endl;
	cin >> File_Name;
	//open the file
	inputFile.open(File_Name);
	if (inputFile.is_open())
		cout << "Load Input File was Done successfully " << endl;
	else
		cout << ("Error: File was not Found") << endl;

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
			F_event = NULL;
		}
	}

	//close file
	inputFile.close();
	return;
}
void UI_Class::Save_InputFile_UI(ofstream &outputFile)
{
	//Print Action Message 
	string File_Name;
	cout<<("Save Output File: Please enter File Name (example.txt)  ")<<endl;
	cin >> File_Name;
	//open the file
	outputFile.open(File_Name, ios::out);
	cout << ("Output File is generated and Saved succesfully ") << endl;
	return;
	
}

UI_Class::~UI_Class()
{
}