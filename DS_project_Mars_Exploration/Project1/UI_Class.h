#pragma once
#include <fstream>
#include"LinkedList.h"
#include"Event.h"
#include"Mission.h"
#include"Rovers.h"
#include<iostream>
#include<Windows.h>
using namespace std;
class UI_Class
{
private:

public:
	UI_Class();
	void Read_InputFile_UI(ifstream &inputFile, int* array_of_info_inputfile,LinkedList<Event*>& Events_List);

	void Save_InputFile_UI(LinkedQueue<Rovers>Available_Polar_Rovers, LinkedQueue<Rovers>Available_Emergency_Rovers, LinkedQueue<Mission>Completed_Polar_Missions, LinkedQueue<Mission>Completed_Emergency_Missions);
	void Output_Screen_Console(int ModeNo,int current_Day,LinkedQueue<Mission>WaitingPolar,PriorityQueue<Mission>WaitingEmergency,LinkedQueue<Rovers>Available_Polar_Rovers, LinkedQueue<Rovers>Available_Emergency_Rovers, LinkedList<Mission>InExcecution_Missions, LinkedList<Rovers>Checkup_Rovers, LinkedQueue<Mission>Completed_Polar_Missions, LinkedQueue<Mission>Completed_Emergency_Missions);
	int choosingInterfaceMode();
	~UI_Class();



};

