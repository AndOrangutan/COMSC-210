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
bool subjectExists(const DynamicArray<subject>&, const int, const std::string);


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

	// open the input file///////////////////////////////////////////////////////////
	ifstream fin;
	fin.open("dvc-schedule.txt");
	if (!fin.good())
		cout << "I/O error. File can't find!\n";

	int n = 1200;

	clock_t startTime = clock(); // start the virtual stop watch...
	// read the input file
	for (int i = 0; i < n; i++)
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

		const std::string classCode = term + section;

		if (isDupe(nonDuplicateClass, classIndex, classCode) == false)
		{
			nonDuplicateClass[classIndex++] = classCode;
		}
		else //true
			duplicates++;
	}
	clock_t endTime = clock(); // ...stop the virtual stop watch

	double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	double elapsedSecondsFirst = elapsedSeconds;
	fin.close();

	std::cout << elapsedSeconds << "(expected O(n) for n=" << n << std::endl;
	elapsedSecondsFirst = elapsedSecondsFirst * 2;
	///////////////////////////////////////////////////////////////////////////////
	
	// open the input file///////////////////////////////////////////////////////////
	
	fin.open("dvc-schedule.txt");
	if (!fin.good())
		cout << "I/O error. File can't find!\n";

	n = n*2;

	startTime = clock(); // start the virtual stop watch...
	// read the input file
	for (int i = 0; i < n; i++)
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

		const std::string classCode = term + section;

		if (isDupe(nonDuplicateClass, classIndex, classCode) == false)
		{
			nonDuplicateClass[classIndex++] = classCode;
		}
		else //true
			duplicates++;
	}
	endTime = clock(); // ...stop the virtual stop watch

	elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	
	fin.close();

	std::cout << elapsedSeconds << "(expected " << elapsedSecondsFirst << ") for n=" << n << std::endl;
	elapsedSecondsFirst = elapsedSecondsFirst * 2;
	///////////////////////////////////////////////////////////////////////////////

	// open the input file///////////////////////////////////////////////////////////

	fin.open("dvc-schedule.txt");
	if (!fin.good())
		cout << "I/O error. File can't find!\n";

	n = n * 2;

	startTime = clock(); // start the virtual stop watch...
	// read the input file
	for (int i = 0; i < n; i++)
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

		const std::string classCode = term + section;

		if (isDupe(nonDuplicateClass, classIndex, classCode) == false)
		{
			nonDuplicateClass[classIndex++] = classCode;
		}
		else //true
			duplicates++;
	}
	endTime = clock(); // ...stop the virtual stop watch

	elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	fin.close();

	std::cout << elapsedSeconds << "(expected " << elapsedSecondsFirst << ") for n=" << n << std::endl;
	elapsedSecondsFirst = elapsedSecondsFirst * 2;
	///////////////////////////////////////////////////////////////////////////////

	// open the input file///////////////////////////////////////////////////////////

	fin.open("dvc-schedule.txt");
	if (!fin.good())
		cout << "I/O error. File can't find!\n";

	n = n * 2;

	startTime = clock(); // start the virtual stop watch...
	// read the input file
	for (int i = 0; i < n; i++)
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

		const std::string classCode = term + section;

		if (isDupe(nonDuplicateClass, classIndex, classCode) == false)
		{
			nonDuplicateClass[classIndex++] = classCode;
		}
		else //true
			duplicates++;
	}
	endTime = clock(); // ...stop the virtual stop watch

	elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	fin.close();

	std::cout << elapsedSeconds << "(expected " << elapsedSecondsFirst << ") for n=" << n << std::endl;
	elapsedSecondsFirst = elapsedSecondsFirst * 2;
	///////////////////////////////////////////////////////////////////////////////


	getchar();
}


bool isDupe(const DynamicArray<string> &nonDuplicateClass, const int classIndex, const std::string classCode)
{
	for (int i = 0; i < classIndex; i++)
		if (classCode == nonDuplicateClass[i])
			return true;
	return false;
}

bool subjectExists(const DynamicArray<subject> &subjectCode, const int subjectIndex, const std::string course)
{
	for (int i = 0; i < subjectIndex; i++)
		if (subjectCode[i].subjectCode == course)
			return true;
	return false;
}
