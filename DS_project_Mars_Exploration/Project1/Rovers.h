#pragma once
template <class T>
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
	void setSpeed(int x);
	void setCheckupDuration(int d);
	void setID(int x);
	int getID();
	void AssignRover();
	bool putinchecko();
	bool getfromchecko();
	bool finishmission();
};

template<class T>
inline Rovers<T>::Rovers()
{
	startofcheckupday = 0;
	startofmissionday = 0;
	NoOfMissionsNow = 0;
	state = 0;
	misionDuration = 2 * (TLOC / speed) + MDUR;
}

template<class T>
inline void Rovers<T>::setType(char S)
{
	Type = S;
}

template<class T>
inline void Rovers<T>::setSpeed(int x)
{
	speed = x;
}

template<class T>
inline void Rovers<T>::setCheckupDuration(int d)
{
	checkupDuration = d;
}

template<class T>
inline void Rovers<T>::setID(int x)
{
	ID = x;
}

template<class T>
inline int Rovers<T>::getID()
{
	return ID;
}

template<class T>
inline void Rovers<T>::AssignRover()
{
	startofmissionday = CurrentDay;
	state = 1;
}

template<class T>
inline bool Rovers<T>::putinchecko()
{
	if (NoOfMissionsNow == NoOfMissionsMax)
	{
		startofcheckupday = CurrentDay;
		state = -1;
		return true;
	}
	else {
		state = 0;
		return false;
	}
}

template<class T>
inline bool Rovers<T>::getfromchecko()
{
	if (CurrentDay - startofcheckupday == checkupDuration)
	{
		state = 0;
		return true;
	}
	else
		return false;
}

template<class T>
inline bool Rovers<T>::finishmission()
{
	if (CurrentDay - startofmissionday == misionDuration)
	{
		NoOfMissionsNow++;
		putinchecko();
	}
}