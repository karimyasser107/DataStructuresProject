#include "Event.h"

Event::Event()
{
	eventday = 0;
	missionID = 0;
	type = 'A';
	targetLocation = 0;
	missionDuration = 0;
	significance = -1;
}

void Event::set_EventDay(int ED)
{
	eventday = ED;
}

void Event::set_MissionID(int ID)
{
	missionID = ID;
}

void Event::set_Type(char T)
{
	type = T;
}

void Event::set_TargetLocation(int TLoc)
{
	TLoc= targetLocation ;
}

void Event::set_MissionDuration(int MDur)
{
	missionDuration = MDur;
}

void Event::set_Significance(int Sig)
{
	significance = Sig;
}

int Event::get_EventDay()
{
	return eventday;
}

int Event::get_MissionID()
{
	return missionID;
}

int Event::get_Type()
{
	return type;
}

int Event::get_TargetLocation()
{
	return targetLocation;
}

int Event::get_MissionDuration()
{
	return missionDuration;
}

int Event::get_Significance()
{
	return significance;
}
