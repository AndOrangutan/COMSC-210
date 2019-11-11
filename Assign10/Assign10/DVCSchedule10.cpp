//Programmer: Von Mueller
//Programmer's ID: 1735441

//use stream strin
//strtok() uses cstring, is a char array
//Use Release not debug otherwise it will take a long ass time


#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

#include "HashTable.h"
#include <cstring> // for strtok and strcpy

struct subject
{
	string subjectCode;
	int count;
};

class Node
{
public:
	std::string key;
	std::string value;
};

int d_hashCode(const std::string&);
int hashCode(const std::string&);

int main()
{
	//Programmer Info
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	HashTable<std::string, bool, 75000> record(d_hashCode);
	HashTable<std::string, int, 100> subClass(hashCode);
	std::vector<std::string> subList;

	//Counting Vars
	int linesParsed = 0; //classIndex + duplicates should equal linesParsed
	int duplicates = 0;
	
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


		const std::string classCode = term + section;

		if (record[classCode])
			duplicates++;
		else
		{
			bool flag = false;
			record[classCode] = true;
			subClass[subject]++;
			for (int i = 0; i < subList.size(); i++)
				if (subList[i] == subject)
					flag = true;
			if (flag == false)
				subList.push_back(subject);
		}

		if ((linesParsed % 1000) == 0)
			cout << '.'; cout.flush();
		linesParsed++;
	}
	fin.close();

	for (int i = 0; i < subList.size(); i++)
	{
		int lowest = i;
		for (int j = i; j < subList.size(); j++)
			if (subList[lowest] > subList[j])
				lowest = j;
		std::string temp = subList[i];
		subList[i] = subList[lowest];
		subList[lowest] = temp;
	}
	std::cout << "\nFinnished!!!\n";
	for (int i = 0; i < subList.size(); i++)
		std::cout << subList[i] << ", " << subClass[subList[i]] << std::endl;

	std::cout << "\nTotal Duplicates: " << duplicates << std::endl
		<< "Total Count: " << linesParsed << std::endl
		<< "Total Subjects: " << subList.size();

	std::string pause;
	std::cin >> pause;
}
int d_hashCode(const std::string& input)
{
	int result = 0;
	int i;
	for (i = 0; i < input.length() - 4; i++)
		result += input.at(i);

	for (int j = 0; j < 4; j++)
		result += (int)(input.at(i + j)) * pow(10, j);
}

int hashCode(const std::string& input)
{
	int result = 0;
	for (int i = 0; i < input.length(); i++)
		result += input.at(i);
	return result;
}

