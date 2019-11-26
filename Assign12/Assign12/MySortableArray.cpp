// Programmer: Von Mueller
// Programmer's ID: 1735441

#include <iostream>
#include <string>

using namespace std;

#include "SortableArray.h"

int main()
{
	// input
	std::cout << "Input value pairs or type Q to quit. " << std::endl
		<< "Example: INDEX VALUE" << std::endl;

	SortableArray<double> values;
	SortableArray<bool> parallel;
	int largest = 0;
	int size = 0;

	// input;
	std::cout << "Input an index and a value [Q to quit]: ";
	bool flag = true;
	do
	{
		std::string inpOne, inpTwo;
		std::cin >> inpOne >> inpTwo;
		cin.ignore(1000, 10);

		if (inpOne != "q" && inpOne != "Q" && inpTwo != "Q" && inpTwo != "Q")
		{
			int index = atoi(inpOne.c_str());
			values[index] = atof(inpTwo.c_str());
			parallel[index] = true;
			if (index > largest)
				largest = index;
			size++;
		}
		else
			flag = false;
	} 
	while (flag == true);

	std::cout << "You stored this many values: " << size << std::endl;
	
	// display
	std::cout << "The index-values pairs are: " << std::endl;
	for (int i = 0; i < largest; i++)
	{
		if (parallel[i] == true)
		{
			std::cout << i << " => " << values[i] << std::endl;
		}
	}

	// sort
	std::cout << "Input the largest to be sort [Q to quit]: ";
	std::string sortTo;
	std::cin >> sortTo;
	int sortIndex = atoi(sortTo.c_str());
	std::cout << "Sorted till " << sortIndex << ":" << std::endl;
	values.sort(sortIndex);

	// display again
	std::cout << "The index-values pairs are: " << std::endl;
	for (int i = 0; i < largest; i++)
	{
		if (parallel[i] == true)
		{
			std::cout << i << " => " << values[i] << std::endl;
		}
	}

	// lookup
	while (true)
	{
		std::string input;
		std::cout << "Input an index to lookup [Q to quit]: ";
		std::cin >> input;
		int index = atoi(input.c_str());
		if (input == "Q" || input == "q")
			break;
		else if(index > largest || parallel[index] == false)
			std::cout << "Sorry, but there is no value stored at index " << index << std::endl;
		else
			std::cout << "Found it -- the value stored in " << index << " is " << values[index] << std::endl;
	}

}

