#pragma once
#include <fstream>
using namespace std;
class UI_Class
{
private:

public:
	UI_Class();
	void Read_InputFile_UI(ifstream &inputFile);
	void Save_InputFile_UI(ofstream& outputFile);
	~UI_Class();



};

