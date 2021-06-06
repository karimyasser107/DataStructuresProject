#pragma once
#include <fstream>
#include"LinkedList.h"
#include"Event.h"
#include"Mission.h"
#include"Rovers.h"
using namespace std;
class UI_Class
{
private:

public:
	UI_Class();
	void Read_InputFile_UI(ifstream &inputFile, int* array_of_info_inputfile,LinkedList<Event*>& Events_List);
	void Save_InputFile_UI(ofstream& outputFile);
	void Output_Screen_Console(LinkedQueue<Mission>WaitingPolar,PriorityQueue<Mission>WaitingEmergency,LinkedQueue<Rovers>AvailablePolarRover, LinkedQueue<Rovers>AvailableEmergencyRover);
	~UI_Class();



};

