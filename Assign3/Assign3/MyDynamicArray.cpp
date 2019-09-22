//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <iostream>
#include <string>

using namespace std;

#include "DynamicArray.h"

void input(DynamicArray<double>&);
void display(DynamicArray<double>&);
void lookup(DynamicArray<double>&);

int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	DynamicArray<double> a(5);

	input(a);
	display(a);
	lookup(a);

	std::string pause;
	std::cin >> pause;
}
/**/
void input(DynamicArray<double>& arr)
{
	while (true)
	{
		std::string inpOne, inpTwo;
		std::cout << "Input an index and a value [Q to quit]: ";
		std::cin >> inpOne >> inpTwo;
		cin.ignore(1000, 10);

		if (inpOne == "q" || inpOne == "Q")
			return;

		arr[atof(inpOne.c_str())] = atof(inpTwo.c_str());

	}
}

void display(DynamicArray<double>& arr)
{
	int count = 0;

	for (int i = 0; i < arr.capacity(); i++)
		if (arr[i] != 0)
			count++;

	std::cout << "you stored this many varues: " << count << std::endl
		<< "The endex value paris are: " << std::endl << std::endl;

	for (int i = 0; i < arr.capacity(); i++)
		if (arr[i] != 0)
			std::cout << "\t" << i << "=> " << arr[i] << std::endl;
	std::cout << std::endl << std::endl;

}

void lookup(DynamicArray<double>& arr)
{
	while (true)
	{
		std::string inpOne;
		std::cout << "Input an index for me to look up [Q to quit]: ";
		std::cin >> inpOne;
		cin.ignore(1000, 10);

		if (inpOne == "q" || inpOne == "Q")
			return;

		double index = atof(inpOne.c_str());

		if ((arr[index] == 0) && (arr[index] != arr[-1]))
			std::cout << "I didn't find it" << std::endl;
		else
			std::cout << "Found it -- the value stored at " << index << " is " << arr[index] << std::endl;

	}
}