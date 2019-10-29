//Programmer: Von Mueller
//Programmer's ID: 1735441


#include <iostream>
#include <string>

//using namespace std;

#include "DynamicArray.h"
#include <ctime>
#include <cstdlib>

// Function Protypes
double rand(int);


int main()
{
	//Programmer Info
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	srand(time(0));

	DynamicArray<double> sortMe;
	int nVal = 700;

	int n = nVal;
	for (int i = 0; i < n; i++)
	{
		sortMe[i] = rand(64);// lol techically doesn't work properly, but it should work well enough...
		//std::cout << sortMe[i] << std::endl;
	}

	clock_t startTime = clock(); // start the virtual stop watch...
	double smallest = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			if (sortMe[j] < sortMe[smallest])
				smallest = j;

		bool temp = sortMe[i];
		sortMe[i] = sortMe[smallest];
		sortMe[smallest] = temp;
	}
	clock_t endTime = clock(); // ...stop the virtual stop watch

	double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	double elapsedSecondsFirst = elapsedSeconds * 2;
	std::cout << elapsedSeconds << "(expected O(n)) for n=" << n << std::endl;

	////////////////////////////////////////////////////////////////////////////////////////////
	
	for(int iter = 2; iter < 5; iter++)
	{
		n = nVal * iter;
		for (int i = 0; i < n; i++)
		{
			sortMe[i] = rand(64);// lol techically doesn't work properly, but it should work well enough...
			//std::cout << sortMe[i] << std::endl;
		}

		startTime = clock(); // start the virtual stop watch...
		smallest = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
				if (sortMe[j] < sortMe[smallest])
					smallest = j;

			bool temp = sortMe[i];
			sortMe[i] = sortMe[smallest];
			sortMe[smallest] = temp;
		}
		endTime = clock(); // ...stop the virtual stop watch

		elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

		
		std::cout << elapsedSeconds << "(expected " << elapsedSecondsFirst << ") for n=" << n << std::endl;
		elapsedSecondsFirst = elapsedSeconds * 2;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////

	getchar();
}

double rand(int places)
{
	
	rand();
	int initRand = rand() % (10^places);
	double randDouble = double(initRand) / (10^places-1);
	return randDouble;
}
/*
clock_t startTime = clock(); // start the virtual stop watch...
//stuff
clock_t endTime = clock(); // ...stop the virtual stop watch

double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

fin.close();

std::cout << elapsedSeconds << "(expected " << elapsedSecondsFirst << ") for n=" << n << std::endl;
double elapsedSecondsFirst = elapsedSecondsFirst * 2;
*/