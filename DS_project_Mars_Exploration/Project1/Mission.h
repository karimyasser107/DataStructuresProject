#pragma once
#include"Rovers.h"
class Mission
{
private:
	int ID;
	int FormulationDay;
	int currentDay;
	int EndDay;
	int NoOfWaitingDays;
	int NoOfExecutionDays;
	int CompletionDay;  // CompletionDay = FormulationDay + NoOfWaitingDays + NoOfExecutionDays
	int TLOCR;
	float AvgWaitDays;
	float AvgExecDays;
	int IDofRoverExcecuting;
	int MissionDuration;
	int TargetLocation;
	char Type;
	int Significance;
	int MDUR;
	int NoOfEmergencyMissions;
	int NoOfPolarMissions;
	int NoOfMountainousMissions;
	int TOTALNoOfMissions;
	int NoOfMissionsBeforeCHECKUP = 0;
	int AutoPromotedPercentage;  // Mountainous Missions only
	//Missionfailure ===>> BONUS
	Rovers ER;
	int NoOfWaitingMissions;
	int NoOfInExecutionMission;
	int NoOfCompletedMissions;

	int NoOfAvailableRovers;
	int startofExcecutionday;
	int state;  //free:0 InExcecution:1  Checkup:-1

public:

	Mission();
	void setFormulationDay(int FD);
	int getFormulationDay();

	void setType(char c);
	char getType();

	void setID(int id);
	int getID();

	void setMissinDuration(int d);
	int getMissionDuration();

	void settargetLoction(int Tloc);
	int getTargetLocation();

	void setSignificance(int Sig);
	int getSignificance();
	void startofExcecutiondayo(int Day);
	bool finishmission(int s);
	int getPriority();
	void setIDofRoverExcecuting(int x);
	int getIDofRoverExcecuting();
	void setMDUR(int x);
	int getMDUR();
	void setCompletionday(int x);
};

inline Mission::Mission()
{
	state = 0;
	NoOfWaitingDays = 0;
	NoOfExecutionDays = 0;
	AvgWaitDays = 0;
	AvgExecDays = 0;
	EndDay = -1;
	CompletionDay = FormulationDay + NoOfWaitingDays + NoOfExecutionDays;

	startofExcecutionday = 0;
	NoOfEmergencyMissions = 0;
	NoOfPolarMissions = 0;
	NoOfMountainousMissions = 0;
	TOTALNoOfMissions = 0;
	// AutoPromotedPercentage; Mountainous Missions only
	NoOfWaitingMissions = 0;
	NoOfInExecutionMission = 0;
	NoOfCompletedMissions = 0;
	NoOfMissionsBeforeCHECKUP = 0;
	IDofRoverExcecuting = 0;
	NoOfAvailableRovers = 0;
}

inline void Mission::setFormulationDay(int FD)
{
	FormulationDay = FD;
}

inline int Mission::getFormulationDay()
{
	return FormulationDay;
}


inline void Mission::setType(char c)
{
	Type = c;
}

inline char Mission::getType()
{
	return Type;
	
}

inline void Mission::setID(int id)
{
	ID = id;
}

inline int Mission::getID()
{
	return ID;
}

inline void Mission::setMissinDuration(int d)
{
	MissionDuration = d;
}

inline int Mission::getMissionDuration()
{
	return MissionDuration;
}

inline void Mission::settargetLoction(int TLoc)
{
	TargetLocation = TLoc;
}

inline int Mission::getTargetLocation()
{
	return TargetLocation;
}

inline void Mission::setSignificance(int Sig)
{
	Significance = Sig;
}

inline int Mission::getSignificance()
{
	return Significance;
}

inline void Mission::startofExcecutiondayo(int Day)
{
	startofExcecutionday = Day;
}

inline bool Mission::finishmission(int s)
{
	currentDay = s;
	if (currentDay == CompletionDay)
	{
		state = 1;
		return true;
	}
	else
		return false;
}

inline int Mission::getPriority()
{
	return(int(2 * Significance + 0.5 * MissionDuration + 0.25 * FormulationDay + 0.125 * TLOCR));
}

inline void Mission::setIDofRoverExcecuting(int x)
{
	IDofRoverExcecuting = x;
}

inline int Mission::getIDofRoverExcecuting()
{
	return IDofRoverExcecuting;
}

inline void Mission::setMDUR(int x)
{
	MDUR = x;
}

inline int Mission::getMDUR()
{
	return MDUR;
}

inline void Mission::setCompletionday(int x)
{
	CompletionDay = x;
}

