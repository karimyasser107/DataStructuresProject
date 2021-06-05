//#include "formulationEvent.h"
//
//formulationEvent::formulationEvent()
//{
//}
//
//
//
//void formulationEvent::set_Type(char T)
//{
//	type = T;
//}
//
//int formulationEvent::get_Type()
//{
//	return type;
//}
//
//void formulationEvent::set_TargetLocation(int TLoc)
//{
//	targetLocation = TLoc;
//}
//
//int formulationEvent::get_TargetLocation()
//{
//	return targetLocation;
//}
//
//void formulationEvent::set_MissionDuration(int MDur)
//{
//	missionDuration = MDur;
//}
//
//int formulationEvent::get_MissionDuration()
//{
//	return missionDuration;
//}
//
//void formulationEvent::set_Significance(int Sig)
//{
//	significance = Sig;
//}
//
//int formulationEvent::get_Significance()
//{
//	return significance;
//}
//
//void formulationEvent::Execute(LinkedQueue<Mission>&EmergQ, LinkedQueue<Mission>&PolarQ)
//{
//	Mission* FM = new Mission() ;
//	FM->setFormulationDay(get_EventDay());
//	FM->setID(get_EventDay());
//	FM->setType(type);
//	FM->setMissinDuration(missionDuration);
//	FM->settargetLoction(targetLocation);
//	FM->setSignificance(significance);
//	/*if (type == 'E')
//		EmergQ.enqueue(*FM);
//
//	if (type == 'P')
//		PolarQ.enqueue(*FM);*/
//
//}