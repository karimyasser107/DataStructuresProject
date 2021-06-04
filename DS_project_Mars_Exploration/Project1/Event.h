#pragma once
#include"LinkedQueue.h"
#include"Mission.h"
class Event
{
private:
	int eventday;
	int missionID;
public:
	Event();

	void virtual setEventDay(int ED)=0;

	void virtual setMissionID(int ID)=0;

	int virtual getEventDay()=0;

	int virtual getMissionID()=0;

	void virtual Execute(LinkedQueue<Mission*>& EmergQ, LinkedQueue<Mission*>& PolarQ) =0;
};

