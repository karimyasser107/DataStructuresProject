#pragma once
#include"UI_Class.h"
#include"Event.h"
#include"LinkedList.h"
#include"LinkedQueue.h"
#include"Mission.h"
#include"Rovers.h"
#include"Node.h"
#include<queue>
class Mars_Station
{
	
private:
	UI_Class UI1;
	LinkedList<Event>*EVEVE;
	LinkedList<Rovers>CHX;
	LinkedList<Rovers>CHR;
	LinkedQueue<Rovers>PolR;
	LinkedQueue<Rovers>EmR;
	LinkedList<Mission>ExcM;
	LinkedQueue<Mission>CompP;
	LinkedQueue<Mission>CompEm;
	priority_queue<Mission>waitingEm;
	LinkedQueue<Mission>waitingPola;
public:
	Mars_Station(LinkedList<Event>X);
	//read input file function
	void Read_InputFile();
	void Save_OutputFile();
	void checkinCheckup( int Day);
	void checkinExcec(int Day);
	void checkinMissinExcec(int Day);
	void EventsinDay(int Day);
	void lookforEmergMissio();
	~Mars_Station();


};

