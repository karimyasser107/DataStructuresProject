#pragma once
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

	void virtual Execute() =0;
};

