#include"Mars_Station.h"
#include"UI_Class.h"
#include <fstream>
using namespace std;

//constructor
Mars_Station::Mars_Station()	
{

}

void Mars_Station::Read_InputFile()
{
	ifstream inputFile;
	int array_of_info_inputfile[8];
	//UI1.Read_InputFile_UI(inputFile, array_of_info_inputfile,Events_List);

	//read first line (number of rovers)
	int N_Rovers[2];//array contains number of Rovers of each type : Polar , Emergency (respectively)
	N_Rovers[0]= array_of_info_inputfile[0]; N_Rovers[1]= array_of_info_inputfile[1];

	//read second line (rovers speed)
	int Speed_Rovers[2];//array contains the Rovers speed of each type : Polar , Emergency (respectively)
	Speed_Rovers[0]= array_of_info_inputfile[2];Speed_Rovers[1]= array_of_info_inputfile[3];

	//read third line (N, CP, CE)
	int N_mission_before_checkup= array_of_info_inputfile[4];//N: is the number of missions the rover completes before performing a checkup
	int Check_up_Duration_Polar_Rov= array_of_info_inputfile[5];//CP: is the checkup duration in days for polar rovers 
	int Check_up_Duration_Emerg_Rov= array_of_info_inputfile[6];//CE: is the checkup duration in days for emergency rovers
	
	//read the fourth line (E: number of events)
	int N_Events= array_of_info_inputfile[7];

	//read the Events lines (one line for each event)
	/*while (!inputFile.eof())
	{
		
	}*/

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
	Node<Rovers>* RR = CHX.getHead();
	while (RR)
	{
		if (RR->getItem().finishmission(Day))
		{
			if (RR->getItem().putinchecko())
			{
				RR->getItem().putinchecko();
				CHR.InsertEnd(RR->getItem());
				CHX.DeleteNode(RR);
			}
			else
			{
				if (RR->getItem().getType() == 'P')
					PolR.enqueue(RR->getItem());
				else
					EmR.enqueue(RR->getItem());
				CHX.DeleteNode(RR);
			}
		}
		else
		{
			RR = RR->getNext();
		}
	}
}

void Mars_Station::checkinMissinExcec(int Day)
{
	Node<Mission>* MM = ExcM.getHead();
	if (MM->getItem().finishmission())
	{
		if (MM->getItem().getType() == 'P')
		{

			CompP.enqueue(MM->getItem());
		}
		else
		{
			CompEm.enqueue(MM->getItem());
		}
		ExcM.DeleteNode(MM);
	}
	else
	{
		MM = MM->getNext();
	}
	
}

void Mars_Station::EventsinDay(int Day)
{
	Node<Event>* EVC = EVEVE->getHead();
	//if()
}

void Mars_Station::lookforEmergMissio()
{
	/*if (!EmR.isEmpty()&&!waitingEm.empty())
	{
		Mission X = waitingEm.top();
		Rovers Y; 
		EmR.dequeue(Y);
		
	}*/
}

void Mars_Station::checkinCheckup(int Day)
{
	Node<Rovers>* RR = CHR.getHead();
	while (RR)
	{
		if (RR->getItem().getfromchecko(Day))
		{
			RR->getItem().getfromchecko(Day);
			if (RR->getItem().getType() == 'P')
				PolR.enqueue(RR->getItem());
			else
				EmR.enqueue(RR->getItem());
			CHR.DeleteNode(RR);
		}
		else
		{
			RR = RR->getNext();
		}
	}
}


Mars_Station::~Mars_Station()
{
}

int main()
{
	/*Mars_Station M1;*/
	/*M1.Save_OutputFile();*/
	//M1.Read_InputFile();
}
