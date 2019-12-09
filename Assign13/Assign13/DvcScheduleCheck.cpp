//Programmer: Von Mueller
//Programmer's ID: 1735441

#define _CRT_SECURE_NO_WARNINGS

// includes
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

// .h includes


// classes

// functions

int main()
{
	//Programmer Info
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	//vars
	int linesParsed = 0; //classIndex + duplicates should equal linesParsed
	map<std::string, set<std::string>> allKeys;

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
		//const string subject(course.begin(), course.begin() + course.find('-'));
		const std::string classCode = term + "-" + section;

		allKeys[classCode].insert(course);

	}
	fin.close();

	map<string, set<string>>::iterator it;
	for (it = allKeys.begin(); it != allKeys.end(); it++)
	{
		if(it -> second.size() > 1)
		{
			std::cout << "Multiple courses found for key (term-section) - " << it->first << ":" << std::endl; // display the key
			set<string>::iterator it2;
			for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
				std::cout << *it2 << std::endl;
		}
	}
	getchar();
}
