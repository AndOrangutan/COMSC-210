//Programmer: Von Mueller
//Programmer's ID: 1735441

//use stream strin
//strtok() uses cstring, is a char array
//Use Release not debug otherwise it will take a long ass time


#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "DynamicArray.h"
#include <cstring> // for strtok and strcpy
#include <ctime>
struct subject
{
	string subjectCode;
	int count;
};

bool isDupe(const DynamicArray<string>&, const int, const std::string); //a function to check for duplicates.


int main()
{
	//Programmer Info
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	//vars
	DynamicArray<std::string> nonDuplicateClass;
	DynamicArray<subject> subjectCount;
	int linesParsed = 0; //classIndex + duplicates should equal linesParsed
	int subjectIndex = 0;
	int classIndex = 0;
	int duplicates = 0;


	// for parsing the inputfile
	char* token;
	char buf[1000];
	const char* const tab = "\t";


	// for file and time testing
	ifstream fin;

	int n = 12000;
	int times = 4;

	// read the input file
	for (int i = 0; i < times; i++)
	{
		fin.open("dvc-schedule.txt"); // open file 
		if (!fin.good())
			cout << "I/O error. File can't find!\n";



		clock_t startTime = clock(); // start the virtual stop watch...
		for (int j = 0; j < n; j++)
		{

			if (buf[0] == 0) continue; // skip blank lines

			//.term	section	course	instructor	whenWhere
			//Spring 2016	1236	MATH - 142	Abaalhareth	MTWTH 3:00 - 3 : 50pm MA - 251
			//parse the line
			const string term(token = strtok(buf, tab));
			const string section((token = strtok(0, tab)) ? token : "");
			const string course((token = strtok(0, tab)) ? token : "");
			const string instructor((token = strtok(0, tab)) ? token : "");
			const string whenWhere((token = strtok(0, tab)) ? token : "");
			if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
			const string subject(course.begin(), course.begin() + course.find('-'));

			const std::string classCode = term + section;

			if (isDupe(nonDuplicateClass, classIndex, classCode) == false)
			{
			}
			else //true
				duplicates++;

		}
		clock_t endTime = clock(); // ...stop the virtual stop watch

		double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;


		static double elapsedSecondsFirst;

		if (i == 0) // gets elapsedSecondsFirst setup;
			elapsedSecondsFirst = elapsedSeconds;

		if (i == 0)
			std::cout << elapsedSeconds << "(expected O(n)) for n=" << n << std::endl;
		else
			std::cout << elapsedSeconds << "(expected " << elapsedSecondsFirst << ") for n=" << n << std::endl;

		fin.close(); // close file

		elapsedSecondsFirst = elapsedSecondsFirst * 2;
		n = n * 2;
	}
	

	
	std::string pause;
	std::cin >> pause;
}


bool isDupe(const DynamicArray<string> &nonDuplicateClass, const int classIndex, const std::string classCode)
{
	for (int i = 0; i < classIndex; i++)
		if (classCode == nonDuplicateClass[i])
			return true;
	return false;
}


