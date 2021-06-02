#pragma once
template <class T>
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
	void setType(char c);
	char getType();

	void setID(int id);
	int getID();

	int setMissinDuration(int d);

};

template<class T>
inline Mission<T>::Mission()
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

template<class T>
inline void Mission<T>::setType(char c)
{
	Type = c;
}

//template<class T>
//inline char Mission<T>::getType()
//{
//	char P;   // polar
//	char E;   // emergency
//
//	if (Type == p)
//	{
//		return p;
//	}
//	if (Type==E)
//	{
//		return E;
//	}
//	
//}

template<class T>
inline void Mission<T>::setID(int id)
{
	ID = id;
}

template<class T>
inline int Mission<T>::getID()
{
	return ID;
}

template<class T>
inline int Mission<T>::setMissinDuration(int d)
{
	MissionDuration = d;
}
