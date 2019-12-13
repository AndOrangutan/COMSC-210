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
	map<std::string, set<int>> allClass;

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

		//const std::string classCode = term + section;

		std::string cpyTerm = term;
		const char* const space = " ";
		strcpy(buf, cpyTerm.c_str());

		std::string season(token = strtok(buf, space));
		std::string year((token = strtok(0, space)) ? token : "");
		/*
		for (unsigned int i = 0; i < cpyTerm.size(); i++) // find space index;
			if (cpyTerm.at(i) == ' ')
				spaceIndex = i;

		std::string season, year;
		bool flag = false;

		for (int i = 0; i < cpyTerm.size(); i++)
			if (cpyTerm[i] == ' ')
				flag = true;
			else if (flag == false)
				season.push_back(cpyTerm[i]);
			else if (flag == true)
				year.push_back(cpyTerm[i]);
		*/

		//std::cout << season << " " << year << std::endl;
		//getchar();

		if (season == "Spring") // make a string of integers
			year.push_back('1');
		else if (season == "Summer")
			year.push_back('2');
		else if (season == "Fall")
			year.push_back('3');
		else
			std::cout << "Shits fucked" << std::endl;

		//std::cout << course << " " << year << std::endl;

		allClass[course].insert(atoi(year.c_str())); // push an integer value created from that string into the map allClass

	}
	fin.close();

	std::string input = "PlaceHolder";
	do
	{
		std::cout << "Enter a course name (like, COMSC-210) to search for the first/last semester course offered [X/x to exit]:" << std::endl << "\t";
		cin >> input;
		if (allClass.find(input) == allClass.end())
			std::cout << "I didn't find " << input << std::endl << std::endl;
		else
		{
			std::string seasons[] = { "Spring", "Summer", "Fall" };
			//std::cout << *(allClass[input].begin()) << " " << *allClass[input].rbegin() << std::endl;
			int ind1 = *allClass[input].begin() - (10*int(*(allClass[input].begin()) * 0.1)); // 20182 -> 2018.2 -> 2018 -> 20180 -> 20182-20180 = season
			int ind2 = *allClass[input].rbegin() - (10*int(*(allClass[input].rbegin()) * 0.1));
			
			std::cout << input << " was first offered in " << seasons[ind1-1] << " " << int(*(allClass[input].begin()) * 0.1) << std::endl
				<< input << " was laast offered in " << seasons[ind2-1] << " " << int(*(allClass[input].rbegin()) * 0.1) << std::endl << std::endl;
		}
	} while (input != "x" && input != "X");
}
