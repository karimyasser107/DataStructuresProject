#include "formulationEvent.h"

formulationEvent::formulationEvent()
{
}

void formulationEvent::setEventDay(int ED)
{
	eventday = ED;
}

int formulationEvent::getEventDay()
{
	return eventday;
}

void formulationEvent::setMissionID(int ID)
{
	missionID = ID;
}

int formulationEvent::getMissionID()
{
	return missionID;
}

void formulationEvent::setType(char T)
{
	type = T;
}

int formulationEvent::getType()
{
	return type;
}

void formulationEvent::setTargetLocation(int TLoc)
{
	targetLocation = TLoc;
}

int formulationEvent::getTargetLocation()
{
	return targetLocation;
}

void formulationEvent::setMissionDuration(int MDur)
{
	missionDuration = MDur;
}

int formulationEvent::getMissionDuration()
{
	return missionDuration;
}

void formulationEvent::setSignificance(int Sig)
{
	significance = Sig;
}

int formulationEvent::getSignificance()
{
	return significance;
}

void formulationEvent::Execute(LinkedQueue<Mission>&EmergQ, LinkedQueue<Mission>&PolarQ)
{
	Mission* FM = new Mission() ;
	FM->setFormulationDay(eventday);
	FM->setID(missionID);
	FM->setType(type);
	FM->setMissinDuration(missionDuration);
	FM->settargetLoction(targetLocation);
	FM->setSignificance(significance);

	if (type == 'E')
		EmergQ.enqueue(*FM);

	if (type == 'P')
		PolarQ.enqueue(*FM);

}