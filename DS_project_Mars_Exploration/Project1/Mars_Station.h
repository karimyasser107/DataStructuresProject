#pragma once
#include"UI_Class.h"
#include"Event.h"
#include"formulationEvent.h"
#include"LinkedList.h"
#include"LinkedQueue.h"
#include"PriorityQueue.h"
#include"Mission.h"
#include"Rovers.h"
//#include"Node.h"
//#include<queue>

class Mars_Station
{
	
private:
	UI_Class UI1;
	LinkedList<Event*> Events_List;
	LinkedQueue<Rovers>Available_Polar_Rovers;
	LinkedQueue<Rovers>Available_Emergency_Rovers;
	int N_mission_before_checkup;//is the number of missions the rover completes before performing a checkup
public:
	Mars_Station();
	/*Read input file function*/
	
	LinkedList<Event*>&EVEVE;
	LinkedList<Rovers>CHX;
	LinkedList<Rovers>CHR;
	LinkedQueue<Rovers>RFP;
	LinkedQueue<Rovers>RFEm;
	LinkedList<Mission>ExcM;
	LinkedQueue<Mission>CompP;
	LinkedQueue<Mission>CompEm;
	PriorityQueue<Mission>waitingEm;
	LinkedQueue<Mission>waitingPola;
	//Mars_Station(LinkedList<Event>X);
	//read input file function

	void Read_InputFile(LinkedList<Event*>& Event_List, LinkedQueue<Rovers>&Available_Emergency_Rovers, LinkedQueue<Rovers>&Available_Polar_Rovers);
	/*Generate the Output File function*/
	void Save_OutputFile();
	void checkinCheckup( int Day);
	void checkinExcec(int Day);
	void checkinMissinExcec(int Day);
	void EventsinDay(int Day);	
	void scanEmergencyMissions();
	void scanPolarMissions();
	~Mars_Station();


};

