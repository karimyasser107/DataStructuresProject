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

	void virtual set_EventDay(int ED)=0;

	void virtual set_MissionID(int ID)=0;

	int virtual get_EventDay()=0;

	int virtual get_MissionID()=0;

	void virtual Execute(LinkedQueue<Mission*>& EmergQ, LinkedQueue<Mission*>& PolarQ) =0;
};

