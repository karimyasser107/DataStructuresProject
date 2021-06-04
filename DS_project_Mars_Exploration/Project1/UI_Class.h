#pragma once
#include <fstream>
#include"LinkedList.h"
#include"Event.h"

using namespace std;
class UI_Class
{
private:

public:
	UI_Class();
	//void Read_InputFile_UI(ifstream &inputFile, int* array_of_info_inputfile,LinkedList<Event*>& Events_List);
	void Save_InputFile_UI(ofstream& outputFile);
	~UI_Class();



};

