#pragma once
#include"UI_Class.h"
#include"Event.h"
#include"LinkedList.h"
#include"LinkedQueue.h"
class Mars_Station
{
private:
	UI_Class UI1;
	//LinkedList<Event*> Events_List;
public:
	Mars_Station();
	//Read input file function
	void Read_InputFile();
	//Generate the Output File function
	void Save_OutputFile();

	~Mars_Station();


};

