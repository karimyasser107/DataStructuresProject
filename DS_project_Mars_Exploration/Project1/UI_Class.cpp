#include"UI_Class.h"
#include<iostream>
#include <fstream>
using namespace std;

UI_Class::UI_Class()
{
}

void UI_Class::Read_InputFile_UI(ifstream & inputFile)
{
	//Print Action Message 
	string File_Name;
	cout << ("Load an Exicting Input File: Please enter File Name (.txt)  ") << endl;
	cin >> File_Name;
	//open the file
	inputFile.open(File_Name);
	if (inputFile.is_open())
	{
		cout << "Load Input File was Done successfully " << endl;
		return;
	}
	else
		cout << ("Error: File was not Found") << endl;
}
void UI_Class::Save_InputFile_UI(ofstream &outputFile)
{
	//Print Action Message 
	string File_Name;
	cout<<("Save Output File: Please enter File Name (example.txt)  ")<<endl;
	cin >> File_Name;
	//open the file
	outputFile.open(File_Name, ios::out);
	cout << ("Output File is generated and Saved succesfully ") << endl;
	return;
	
}

UI_Class::~UI_Class()
{
}