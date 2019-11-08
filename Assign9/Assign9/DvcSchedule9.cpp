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
#include "AssociativeArray.h"
#include <cstring> // for strtok and strcpy



struct subject
{
	string subjectCode;
	int count;
};

int check_term(const string, const DynamicArray<SectionsForTerm> &, int); //string term for parcing, DyArray,
bool check_section(const string, const SectionsForTerm&); //
bool subjectExists(const DynamicArray<subject> &, const int, const std::string);
void subjectSort(DynamicArray<subject>&, const int);

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

	// open the input file
	ifstream fin;
	fin.open("dvc-schedule.txt");
	if (!fin.good())
		cout << "I/O error. File can't find!\n";

	// read the input file
	while (fin.good())
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




		//////////////////////////////////////
		//Check if alreadySeen has term
			// if has term, add section number
			//else, add new term, add section number

		const int check_termInt = check_term(term, alreadySeen, numberOfTermsSeen); //less function calls.
		if (check_termInt != -1) // checks if it exists
		{
			if (check_section(section, alreadySeen[check_termInt]) == false) //if section doesn't exist
			{
				alreadySeen[check_termInt].seenSectionNumber[alreadySeen[check_termInt].numberOfSectionsSeen++] = section;

				//update subjectCount
				if (subjectExists(subjectCount, subjectIndex, subject) == false)
				{
					subjectCount[subjectIndex].subjectCode = subject;
					subjectCount[subjectIndex++].count++;
				}
				else
				{
					for (int i = 0; i < subjectIndex; i++)
						if (subjectCount[i].subjectCode == subject)
							subjectCount[i].count++;
				}
			}
			else
				duplicates++;
		}
		else
		{
			alreadySeen[numberOfTermsSeen].term = term;
			alreadySeen[numberOfTermsSeen].seenSectionNumber[0] = section;
			alreadySeen[numberOfTermsSeen++].numberOfSectionsSeen++;

			//update subjectCount
			if (subjectExists(subjectCount, subjectIndex, subject) == false)
			{
				subjectCount[subjectIndex].subjectCode = subject;
				subjectCount[subjectIndex++].count++;
			}
			else
			{
				for (int i = 0; i < subjectIndex; i++)
					if (subjectCount[i].subjectCode == subject)
						subjectCount[i].count++;
			}
		}


		if ((linesParsed % 1000) == 0) //Progress Bar...............
			cout << '.'; cout.flush();

		linesParsed++;
	}
	fin.close();

	subjectSort(subjectCount, subjectIndex);
	std::cout << "\nFinnished!!!\n";
	for (int i = 0; i < subjectIndex; i++)
		std::cout << subjectCount[i].subjectCode << ", " << subjectCount[i].count << std::endl;
	std::cout << "\nTotal Duplicates: " << duplicates << std::endl
		<< "Total Count: " << linesParsed << std::endl
		<< "Total Subjects: " << subjectIndex;

	std::string pause;
	std::cin >> pause;
}

int check_term(const string term, const DynamicArray<SectionsForTerm> & alreadySeen, int numberOfTermsSeen)
{
	for (int i = 0; i < numberOfTermsSeen; i++)
	{
		if (alreadySeen[i].term == term)
			return i;

	}
	return -1;

}
bool check_section(const string section, const SectionsForTerm& alreadySeenObj)
{
	for (int i = 0; i < alreadySeenObj.numberOfSectionsSeen; i++)
		if (alreadySeenObj.seenSectionNumber[i] == section)
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

void subjectSort(DynamicArray<subject>& subArray, const int cap)
{

	for (int i = 0; i < cap - 1; i++)
	{
		int lowest = i;
		for (int j = i + 1; j < cap; j++)
		{
			if (subArray[j].subjectCode < subArray[lowest].subjectCode)
				lowest = j;
		}
		subject temp = subArray[lowest];
		subArray[lowest] = subArray[i];
		subArray[i] = temp;
	}
}