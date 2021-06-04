#pragma once
#include "Event.h"
#include"LinkedQueue.h"
class formulationEvent : public Event
{
private:
	int eventday;
	int missionID;
	char type;
	int targetLocation;
	int missionDuration;
	int significance;
public:
	formulationEvent();
	void setEventDay(int ED);
    void setMissionID(int ID);
	void setType(char T);
	void setTargetLocation(int TLoc);
	void setMissionDuration(int MDur);
	void setSignificance(int Sig);
	int  getEventDay();
	int getMissionID();
	int getType();
	int getTargetLocation();
	int getMissionDuration();
	int getSignificance();

	void Execute(LinkedQueue<Mission>&EmergQ, LinkedQueue<Mission>&PolarQ);

};

