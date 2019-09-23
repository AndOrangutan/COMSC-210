//Programmer: Von Mueller
//Programmer's ID: 1735441

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring> // for strtok and strcpy

int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	// for parsing the inputfile
	char* token;
	char buf[1000];
	const char* const tab = "\t";

	// open the input file
	ifstream fin;
	fin.open("dvc-schedule.txt");
	if (!fin.good()) std::cout << "I/O error";

	int count = 0;
	// read the input file
	while (fin.good())
	{
		// read the line
		string line;
		getline(fin, line);
		strcpy(buf, line.c_str());

		if (buf[0] == 0) continue; // skip blank lines

		//parse the line
		const string term(token = strtok(buf, tab));
		const string section((token = strtok(0, tab)) ? token : "");
		const string course((token = strtok(0, tab)) ? token : "");
		const string instructor((token = strtok(0, tab)) ? token : "");
		const string whenWhere((token = strtok(0, tab)) ? token : "");
		if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
		const string subjectCode(course.begin(), course.begin() + course.find('-'));

		
		// if I get this far, then it's a valid record
		cout << term << '|' << section << '|'
			<< course << '|' << instructor << '|'
			<< whenWhere << '|' << subjectCode << endl;

		
		count++;
	}
	fin.close();

	std::cout << "\nTotal " << count << " Lines processed";

	std::string pause;
	std::cin >> pause;
}