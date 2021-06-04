#pragma once
#include "Event.h"
#include"LinkedQueue.h"
class formulationEvent : public Event
{
private:
	char type;
	int targetLocation;
	int missionDuration;
	int significance;
public:
	formulationEvent();
	//void set_EventDay(int ED);
    //void set_MissionID(int ID);
	void set_Type(char T);
	void set_TargetLocation(int TLoc);
	void set_MissionDuration(int MDur);
	void set_Significance(int Sig);
	//int  get_EventDay();
	//int get_MissionID();
	int get_Type();
	int get_TargetLocation();
	int get_MissionDuration();
	int get_Significance();

	void Execute(LinkedQueue<Mission>&EmergQ, LinkedQueue<Mission>&PolarQ);

};

