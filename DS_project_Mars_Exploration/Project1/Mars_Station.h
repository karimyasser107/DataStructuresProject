#pragma once
#include"UI_Class.h"
#include"Event.h"
#include"formulationEvent.h"
#include"LinkedList.h"
#include"LinkedQueue.h"
#include"PriorityQueue.h"
#include"Mission.h"
#include"Rovers.h"
#include"Nodo.h"

class Mars_Station
{
	
private:
	UI_Class UI1;
	LinkedList<Event*> Events_List;
	LinkedQueue<Rovers>Available_Polar_Rovers;
	LinkedQueue<Rovers>Available_Emergency_Rovers;
	LinkedList<Rovers>InExcecution_Rovers;
	LinkedList<Rovers>Checkup_Rovers;
	LinkedList<Mission>InExcecution_Missions;
	LinkedQueue<Mission>Completed_Polar_Misssions;
	LinkedQueue<Mission>Completed_Emergency_Missions;
	PriorityQueue<Mission>waitingEmergency_Missions;
	LinkedQueue<Mission>waitingPolar_Missions;
	bool Simulation_Is_Completed;
	int Current__Day;//this integer is increased each day by 1 (Not related to the event days)-it is like a calender
	//so it starts with 1 (means day 1) after the first loop is completed it is increased to be 2 (means day 2) and so on 
	int SameDay;//to check on the EventsList what are the events that have same EventDay 
	int N_mission_before_checkup;//is the number of missions the rover completes before performing a checkup
	int ModeNo;
public:
	Mars_Station();
	//Read input file function
	void Read_InputFile(LinkedList<Event*>& Event_List, LinkedQueue<Rovers>&Available_Emergency_Rovers, LinkedQueue<Rovers>&Available_Polar_Rovers);
	//Generate the Output File function
	void Save_OutputFile();
	void checkinCheckup( int Day);
	void checkinExcecRovers(int Day);
	void checkinMissinExcec(int Day);
	bool EventsList_is_Not_Empty();
	//Functions necessary to excute an Event
	void Excute_Event_In_Certain_Day();//call Appropriate version of Excute according to the event type
	void Loop_On_Events_In_Same_Day();//This function loops on the EventsList 
	//and out all events that are in SAME DAY ONLY
	//in order to be excuted
	//functions on Current__Day
	void increase_Current__Day();
	int get_Current__Day();
	void scanEmergencyMissions(int Day);
	void scanPolarMissions(int Day);
	//BONUS Mission Fail
	void Mission_Failure();
	//Output Modes
	int getModeNo();
	void Program_Output_Modes();
	bool The_Simulation_Is_Completed();
	~Mars_Station();
};

