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
#include <cstdlib>

struct SectionsForTerm
{
	string term;
	int numberOfSectionsSeen = 0;
	DynamicArray<string> seenSectionNumber;
};

struct subject
{
	string subjectCode;
	int count;
};

int main()
{
	//Programmer Info
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	//Vars
	int linesParsed = 0; //# of lines parsed
	int duplicates = 0; // # of duplicates.

	int numberOfTermsSeen = 0; // # of Terms Seen, used to check for duplicates
	DynamicArray<SectionsForTerm> alreadySeen(200); // Used to check for duplicates
	int subjectIndex = 0;
	DynamicArray<subject> subjectCount;


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
			// read the line
			string line;
			getline(fin, line);
			strcpy(buf, line.c_str());

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
	

	


	getchar();
}

