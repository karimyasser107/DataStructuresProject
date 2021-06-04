#include "Event.h"

Event::Event()
{
	eventday = 0;
	missionID = 0;
}

int Event::get_EventDay()
{
	return eventday;
}

void Event::set_EventDay(int ED)
{
	eventday = ED;
}
void Event::set_MissionID(int ID)
{
	missionID=ID;
}

int Event::get_MissionID()
{
	return missionID;
}


