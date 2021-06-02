#pragma once
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
	float AvgWaitDays;
	float AvgExecDays;

	int MissionDuration;
	int TargetLocation;
	char Type;
	int Significance;

	int NoOfEmergencyMissions;
	int NoOfPolarMissions;
	int NoOfMountainousMissions;
	int TOTALNoOfMissions;
	int NoOfMissionsBeforeCHECKUP = 0;
	int AutoPromotedPercentage;  // Mountainous Missions only
	//Missionfailure ===>> BONUS

	int NoOfWaitingMissions;
	int NoOfInExecutionMission;
	int NoOfCompletedMissions;

	int NoOfAvailableRovers;

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

	NoOfEmergencyMissions = 0;
	NoOfPolarMissions = 0;
	NoOfMountainousMissions = 0;
	TOTALNoOfMissions = 0;
	// AutoPromotedPercentage; Mountainous Missions only

	NoOfWaitingMissions = 0;
	NoOfInExecutionMission = 0;
	NoOfCompletedMissions = 0;
	NoOfMissionsBeforeCHECKUP = 0;

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

