#include"Mars_Station.h"
#include"UI_Class.h"
#include <fstream>
#include"Mission.h"
#include"Rovers.h"
using namespace std;


Mars_Station::Mars_Station()	
{
	Read_InputFile(Events_List,Available_Emergency_Rovers, Available_Polar_Rovers);
}

void Mars_Station::Read_InputFile(LinkedList<Event>Event_List , LinkedQueue<Rovers>&Available_Emergency_Rovers, LinkedQueue<Rovers>&Available_Polar_Rovers)
{
	ifstream inputFile;
	int array_of_info_inputfile[8];
	UI1.Read_InputFile_UI(inputFile, array_of_info_inputfile,Event_List);

	//read first line (number of rovers)
	int N_Rovers[2];//array contains number of Rovers of each type : Polar , Emergency (respectively)
	N_Rovers[0]= array_of_info_inputfile[0]; N_Rovers[1]= array_of_info_inputfile[1];

	//read second line (rovers speed)
	int Speed_Rovers[2];//array contains the Rovers speed of each type : Polar , Emergency (respectively)
	Speed_Rovers[0]= array_of_info_inputfile[2];Speed_Rovers[1]= array_of_info_inputfile[3];

	//read third line (N, CP, CE)
	N_mission_before_checkup= array_of_info_inputfile[4];//N: is the number of missions the rover completes before performing a checkup
	int Check_up_Duration_Polar_Rov= array_of_info_inputfile[5];//CP: is the checkup duration in days for polar rovers 
	int Check_up_Duration_Emerg_Rov= array_of_info_inputfile[6];//CE: is the checkup duration in days for emergency rovers
	
	//read the fourth line (E: number of events)
	int N_Events= array_of_info_inputfile[7];

	//fill the polar rover Queue
	for(int i=0;i< N_Rovers[0];i++)
	{
		Rovers* rover1= new Rovers;
		rover1->setSpeed(Speed_Rovers[0]);
		rover1->setCheckupDuration(Check_up_Duration_Polar_Rov);
		rover1->setType('P');
		Available_Polar_Rovers.enqueue(*rover1);
		rover1 = NULL;
	}
	//fill the emergency rover Queue
	for (int i = 0;i < N_Rovers[1];i++)
	{
		Rovers* rover1 = new Rovers;
		rover1->setSpeed(Speed_Rovers[1]);
		rover1->setCheckupDuration(Check_up_Duration_Emerg_Rov);
		rover1->setType('E');
		Available_Emergency_Rovers.enqueue(*rover1);
		rover1 = NULL;
	}

	//close file
	inputFile.close();
}
void Mars_Station::Save_OutputFile()
{
	int arr[5] = { 18,1,7,5,6 };
	//Create new Output File
	ofstream outputFile;
	UI1.Save_InputFile_UI(outputFile);//call function save of class UI_Class
	outputFile << "CD   ID   FD   WD   ED "<< endl;
	outputFile << arr[0] << "   ";
	outputFile << arr[1] << "    ";
	outputFile << arr[2] << "    ";
	outputFile << arr[3] << "    ";
	outputFile << arr[4] <<endl;
	outputFile << "………………………………………………" << endl << "………………………………………………" << endl<<endl;
	outputFile << "Missions:" << endl;
	outputFile << "Rovers:" << endl;
	outputFile << "Avg Wait = " <<7<<", Avg Exec ="<< endl;
	if (outputFile.is_open())
		outputFile.close();

}



void Mars_Station::checkinExcec(int Day)
{
	Nodo<Rovers>* RR = CHX.getHead();
	while (RR)
	{
		if (RR->getitem().finishmission(Day))
		{
			if (RR->getitem().putinchecko())
			{
				RR->getitem().putinchecko();
				CHR.InsertEnd(RR->getitem());
				CHX.DeleteNode(RR);
			}
			else
			{
				if (RR->getitem().getType() == 'P')
					Available_Polar_Rovers.enqueue(RR->getitem());
				else
					Available_Emergency_Rovers.enqueue(RR->getitem());
				CHX.DeleteNode(RR);
			}
		}
		else
		{
			RR = RR->getnext();
		}
	}
}

void Mars_Station::checkinMissinExcec(int Day)
{
	Nodo<Mission>* MM = ExcM.getHead();
	if (MM->getitem().finishmission())
	{
		if (MM->getitem().getType() == 'P')
		{

			CompP.enqueue(MM->getitem());
		}
		else
		{
			CompEm.enqueue(MM->getitem());
		}
		ExcM.DeleteNode(MM);
	}
	else
	{
		MM = MM->getnext();
	}
	
}

void Mars_Station::EventsinDay(int Day)
{
	while (EVEVE.isEmpty())
	{
		
	}
}

void Mars_Station::scanEmergencyMissions()
{
	while (!waitingEm.isEmpty())
	{
		if (!RFEm.isEmpty())
		{
			Mission EX;
			Rovers ER;
			RFEm.dequeue(ER);
			CHX.InsertEnd(ER);
			waitingEm.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			ExcM.InsertEnd(EX);
		}
		else if (!RFP.isEmpty())
		{
			Mission EX;
			Rovers ER;
			RFP.dequeue(ER);
			CHX.InsertEnd(ER);
			waitingEm.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			ExcM.InsertEnd(EX);
		}
		else
			return;
	}
}

void Mars_Station::scanPolarMissions()
{
	while (!waitingPola.isEmpty())
	{
		if (!RFP.isEmpty())
		{
			Mission EX;
			Rovers ER;
			RFEm.dequeue(ER);
			CHX.InsertEnd(ER);
			waitingEm.dequeue(EX);
			EX.setIDofRoverExcecuting(ER.getID());
			ExcM.InsertEnd(EX);
		}
		else
			return;
	}
}



void Mars_Station::checkinCheckup(int Day)
{
	Nodo<Rovers>* RR = CHR.getHead();
	while (RR)
	{
		if (RR->getitem().getfromchecko(Day))
		{
			RR->getitem().getfromchecko(Day);
			if (RR->getitem().getType() == 'P')
				Available_Polar_Rovers.enqueue(RR->getitem());
			else
				Available_Emergency_Rovers.enqueue(RR->getitem());
			CHR.DeleteNode(RR);
		}
		else
		{
			RR = RR->getnext();
		}
	}
}


Mars_Station::~Mars_Station()
{
}

int main()
{
	Mars_Station M1;
	///*M1.Save_OutputFile();*/
	////M1.Read_InputFile();
	

}
