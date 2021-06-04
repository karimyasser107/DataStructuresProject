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

	void virtual set_EventDay(int ED);

	void virtual set_MissionID(int ID);

	int virtual get_EventDay();

	int virtual get_MissionID();

	void virtual Execute(LinkedQueue<Mission>& EmergQ, LinkedQueue<Mission>& PolarQ) =0;
};

