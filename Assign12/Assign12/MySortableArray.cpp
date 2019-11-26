// Programmer: Von Mueller
// Programmer's ID: 1735441

#include <iostream>
#include <string>

using namespace std;

#include "SortableArray.h"

class psudoArray
{
public:
	int index;
	double value;
};

int main()
{
	// input
	std::cout << "Input value pairs or type Q to quit. " << std::endl
		<< "Example: INDEX VALUE" << std::endl;

	SortableArray<psudoArray> values;
	int size = 0;

	// input;
	std::cout << "Input an index and a value [Q to quit]: " << std::endl;
	bool flag = true;
	do
	{
		std::string inpOne, inpTwo;
		std::cin >> inpOne >> inpTwo;
		cin.ignore(1000, 10);

		if (inpOne != "q" && inpOne != "Q" && inpTwo != "Q" && inpTwo != "Q")
		{
			int index = atoi(inpOne.c_str());
			values[size].index = index;
			values[size].value = atof(inpTwo.c_str());
			size++;
		}
		else
			flag = false;
	} 
	while (flag == true);

	std::cout << "You stored this many values: " << size << std::endl;
	
	// display
	std::cout << "The index-values pairs are: " << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << values[i].index << " => " << values[i].value << std::endl;

	// sort
	std::cout << "Input the largest to be sort [Q to quit]: ";
	std::string sortTo;
	std::cin >> sortTo;
	int sortIndex = atoi(sortTo.c_str());
	std::cout << "Sorted till " << sortIndex << ":" << std::endl;

	SortableArray<double> sortSortArray;
	for (int i = 0; i < size; i++)
		sortSortArray[i] = values[i].value;
	sortSortArray.sort(sortIndex-1);
	for (int i = 0; i < size; i++)
		values[i].value = sortSortArray[i];


	// display again
	std::cout << "The index-values pairs are: " << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << values[i].index << " => " << values[i].value << std::endl;


	// lookup
	while (true)
	{
		std::string input;
		std::cout << "Input an index to lookup [Q to quit]: ";
		std::cin >> input;
		int index = atoi(input.c_str());
		if (input == "Q" || input == "q")
			break;
		int tempInd;
		for (int i = 0; i < size; i++)
		{
			tempInd = -1;
			if (values[i].index == index)
			{
				tempInd = i;
				break;
			}
		}
		if (tempInd == -1)
			std::cout << "Sorry, but there is no value stored at index " << index << std::endl;
		else
			std::cout << "Found it -- the value stored in " << values[tempInd].index << " is " << values[tempInd].value << std::endl;
	}

}

