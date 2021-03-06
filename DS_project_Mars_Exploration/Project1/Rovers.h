#pragma once
class Rovers
{
private:
	int NoOfMissionsNow;
	int NoOfMissionsMax;
	char Type;
	int speed;
	int checkupDuration;
	int ID;
	int state;  //free:0 InExcecution:1  Checkup:-1
	int CurrentDay;
	int startofmissionday;
	int startofcheckupday;
	int MDUR;
	int TLOC;
	int misionDuration;
public:
	Rovers();
	void setType(char S);
	char getType();
	void setSpeed(int x);
	//int get__Speed();
	void setState(int x);
	int getState();
	void setCheckupDuration(int d);
	void setID(int x);
	int getID();
	void AssignRover();
	bool putinchecko();
	bool getfromchecko(int x);
	bool finishmission(int Day);
	void setstartcheckupday(int day);
	void incrementnumberofmissionsnow();
	void setstartofMissionday(int Day);
	void setCurrentDay(int y);
	int getspeed();
	void setN_mission_before_checkup(int x);
	void setMissionDuration(int x);
};


inline Rovers::Rovers()
{
	startofcheckupday = 0;
	startofmissionday = 0;
	NoOfMissionsNow = 0;
	state = 0;
	/*misionDuration = 2 * (TLOC / speed) + MDUR;*/
}

inline void Rovers::setType(char S)
{
	Type = S;
}

inline char Rovers::getType()
{
	return Type;
}


inline void Rovers::setSpeed(int x)
{
	speed = x;
}

//int Rovers::get__Speed()
//{
//	return speed;
//}

inline void Rovers::setState(int x)
{
	state = x;
}

inline int Rovers::getState()
{
	return state;
}


inline void Rovers::setCheckupDuration(int d)
{
	checkupDuration = d;
}

inline void Rovers::setID(int x)
{
	ID = x;
}

inline int Rovers::getID()
{
	return ID;
}


inline void Rovers::AssignRover()
{
	startofmissionday = CurrentDay;
	state = 1;
}


inline bool Rovers::putinchecko()
{
	if (NoOfMissionsNow == NoOfMissionsMax)
	{
		startofcheckupday = CurrentDay;
		state = -1;
		NoOfMissionsNow = 0;
		return true;
	}
	else {
		state = 0;
		return false;
	}
}

inline bool Rovers::getfromchecko(int x)
{
	if (x - startofcheckupday == checkupDuration)
	{
		state = 0;
		return true;
	}
	else
		return false;
}


inline bool Rovers::finishmission(int Day)
{
	if (Day - startofmissionday == misionDuration)
	{
		NoOfMissionsNow++;
		putinchecko();
		return true;
	}
	return false;
}

inline void Rovers::setstartcheckupday(int day)
{
	startofcheckupday = day;
}

inline void Rovers::incrementnumberofmissionsnow()
{
	NoOfMissionsNow++;
}

inline void Rovers::setstartofMissionday(int Day)
{
	startofmissionday = Day;
}

inline void Rovers::setCurrentDay(int y)
{
	CurrentDay = y;
}

inline int Rovers::getspeed()
{
	return speed;
}

inline void Rovers::setN_mission_before_checkup(int x)
{
	NoOfMissionsMax = x;
}

inline void Rovers::setMissionDuration(int x)
{
	misionDuration = x;
}
