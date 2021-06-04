#include "formulationEvent.h"

formulationEvent::formulationEvent()
{
}

void formulationEvent::set_EventDay(int ED)
{
	eventday = ED;
}

int formulationEvent::get_EventDay()
{
	return eventday;
}

void formulationEvent::set_MissionID(int ID)
{
	missionID = ID;
}

int formulationEvent::get_MissionID()
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

void formulationEvent::Execute(LinkedQueue<Mission*>&EmergQ, LinkedQueue<Mission*>&PolarQ)
{
	Mission* FM = new Mission() ;
	FM->setFormulationDay(eventday);
	FM->setID(missionID);
	FM->setType(type);
	FM->setMissinDuration(missionDuration);
	FM->settargetLoction(targetLocation);
	FM->setSignificance(significance);

	if (type == 'E')
		EmergQ.enqueue(FM);

	if (type == 'P')
		PolarQ.enqueue(FM);

}