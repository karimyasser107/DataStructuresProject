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
	UI1.Read_InputFile_UI(inputFile);

	//read first line (number of rovers)
	int N_Rovers[2];//array contains number of Rovers of each type : Polar , Emergency (respectively)
	inputFile >> N_Rovers[0];inputFile >> N_Rovers[1];

	//read second line (rovers speed)
	int Speed_Rovers[2];//array contains the Rovers speed of each type : Polar , Emergency (respectively)
	inputFile >> Speed_Rovers[0];inputFile >> Speed_Rovers[1];

	//read third line (N, CP, CE)
	int N_mission_before_checkup;//N: is the number of missions the rover completes before performing a checkup
	int Check_up_Duration_Polar_Rov;//CP: is the checkup duration in days for polar rovers 
	int Check_up_Duration_Emerg_Rov;//CE: is the checkup duration in days for emergency rovers
	inputFile >> N_mission_before_checkup >> Check_up_Duration_Polar_Rov >> Check_up_Duration_Emerg_Rov;
	
	//read the fourth line (E: number of events)
	int N_Events;
	inputFile >> N_Events;

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
	outputFile << "������������������" << endl << "������������������" << endl<<endl;
	outputFile << "Missions:" << endl;
	outputFile << "Rovers:" << endl;
	outputFile << "Avg Wait = " <<7<<", Avg Exec ="<< endl;
	if (outputFile.is_open())
		outputFile.close();

}

Mars_Station::~Mars_Station()
{
}

int main()
{
	Mars_Station M1;
	/*M1.Save_OutputFile();*/
	//M1.Read_InputFile();
}
