//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <iostream>
#include <string>

using namespace std;

#include <cassert>
#include "StaticArray.h"


void output(std::string);

int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;


	//START OF INT///////////////////////////////////////////////////////////////
	StaticArray <int, 100> sI;
	const int int1 = 12356;
	const int int2 = 7654321;
	const int int3 = 123123;

	std::cout << "Integer Static Array test:" << std::endl
		<< "-------------------------------" << std::endl;

	//StaticArray::capacity()
	std::cout << "Testing StaticArray::capacity()" << std::endl
		<< "Expected: 100" << std::endl
		<< "Actual: " << sI.capacity() << std::endl << std::endl;
	assert(sI.capacity() == 100);

	//StaticArray::Array default constructor
	std::cout << "\nTesting StaticArray::StaticArray\n";
	for (int i = 0; i < sI.capacity(); i++)
		assert(sI[i] == int());
	std::cout << "Pass!\n\n";

	//StaticArray::operator[] setter
	sI[6] = int1;
	std::cout << "\nTesting StaticArray::operator[] setter\n";
	std::cout << "Expected: " << int1 << " for sI[6]\n";
	std::cout << "Actual: " << sI[6] << std::endl << std::endl;
	assert(sI[6] == int1);

	sI[7] = int2;
	std::cout << "Expected: " << int2 << " for sI[7]\n";
	std::cout << "Actual: " << sI[7] << std::endl << std::endl;
	assert(sI[7] == int2);

	sI[-1000] = int3;
	std::cout << "Expected: " << int3 << " for sI[-1000]\n";
	std::cout << "Actual: " << sI[-1000] << std::endl << std::endl;
	assert(sI[-1000] == int3);


	assert(int1 == sI[6]);
	assert(int2 == sI[7]);
	assert(int3 == sI[-6]); // any out of range uses dummy
	assert(int3 == sI[100]); // checks upper end of range
	assert(int3 != sI[99]); //checks upper end of range
	assert(int3 != sI[0]); // checks lower end of range


	//StaticArray::Operator[] getter
	std::cout << "\nTesting the StaticArray::operator[] getter\n";
	const StaticArray<int, 100> sIC = sI;
	for (int i = 0; i < sIC.capacity(); i++)
		assert(sI[i] == sIC[i]);
	std::cout << "Pass!\n\n";


	//START OF DOUBLE////////////////////////////////////////////////
	StaticArray <double, 100> sD;
	const double double1 = 6.6;
	const double double2 = 666.6;
	const double double3 = 6666669.420;

	std::cout << "Double Static Array test:" << std::endl
		<< "-------------------------------" << std::endl;

	//StaticArray::capacity()
	std::cout << "Testing StaticArray::capacity()" << std::endl
		<< "Expected: 100" << std::endl
		<< "Actual: " << sD.capacity() << std::endl << std::endl;
	assert(sD.capacity() == 100);

	//StaticArray::Array default constructor
	std::cout << "\nTesting StaticArray::StaticArray\n";
	for (int i = 0; i < sD.capacity(); i++)
		assert(sD[i] == double());
	std::cout << "Pass!\n\n";

	//StaticArray::operator[] setter
	sD[6] = double1;
	std::cout << "\nTesting StaticArray::operator[] setter\n";
	std::cout << "Expected: " << double1 << " for sD[6]\n";
	std::cout << "Actual: " << sD[6] << std::endl << std::endl;
	assert(sD[6] == double1);

	sD[7] = double2;
	std::cout << "Expected: " << double2 << " for sD[7]\n";
	std::cout << "Actual: " << sD[7] << std::endl << std::endl;
	assert(sD[7] == double2);

	sD[-1000] = double3;
	std::cout << "Expected: " << double3 << " for sD[-1000]\n";
	std::cout << "Actual: " << sD[-1000] << std::endl << std::endl;
	assert(sD[-1000] == double3);


	assert(double1 == sD[6]);
	assert(double2 == sD[7]);
	assert(double3 == sD[-6]); // any out of range uses dummy
	assert(double3 == sD[100]); // checks upper end of range
	assert(double3 != sD[99]); //checks upper end of range
	assert(double3 != sD[0]); // checks lower end of range


	//StaticArray::Operator[] getter
	std::cout << "\nTesting the StaticArray::operator[] getter\n";
	const StaticArray<double, 100> sDC = sD;
	for (int i = 0; i < sDC.capacity(); i++)
		assert(sD[i] == sDC[i]);
	std::cout << "Pass!\n\n";


	//START OF Character////////////////////////////////////////////////
	StaticArray <char, 100> sC;
	const char char1 = 's';
	const char char2 = 'u';
	const char char3 = 'h';

	std::cout << "Character Static Array test:" << std::endl
		<< "-------------------------------" << std::endl;

	//StaticArray::capacity()
	std::cout << "Testing StaticArray::capacity()" << std::endl
		<< "Expected: 100" << std::endl
		<< "Actual: " << sC.capacity() << std::endl << std::endl;
	assert(sC.capacity() == 100);

	//StaticArray::Array default constructor
	std::cout << "\nTesting StaticArray::StaticArray\n";
	for (int i = 0; i < sC.capacity(); i++)
		assert(sC[i] == char());
	std::cout << "Pass!\n\n";

	//StaticArray::operator[] setter;
	sC[6] = char1;
	std::cout << "\nTesting StaticArray::operator[] setter\n";
	std::cout << "Expected: " << char1 << " for sC[6]\n";
	std::cout << "Actual: " << sC[6] << std::endl << std::endl;
	assert(sC[6] == char1);

	sC[7] = char2;
	std::cout << "Expected: " << char2 << " for sC[7]\n";
	std::cout << "Actual: " << sC[7] << std::endl << std::endl;
	assert(sC[7] == char2);

	sC[-1000] = char3;
	std::cout << "Expected: " << char3 << " for sC[-1000]\n";
	std::cout << "Actual: " << sC[-1000] << std::endl << std::endl;
	assert(sC[-1000] == char3);


	assert(char1 == sC[6]);
	assert(char2 == sC[7]);
	assert(char3 == sC[-6]); // any out of range uses dummy
	assert(char3 == sC[100]); // checks upper end of range
	assert(char3 != sC[99]); //checks upper end of range
	assert(char3 != sC[0]); // checks lower end of range


	//StaticArray::Operator[] getter
	std::cout << "\nTesting the StaticArray::operator[] getter\n";
	const StaticArray<char, 100> sCC = sC;
	for (int i = 0; i < sCC.capacity(); i++)
		assert(sC[i] == sCC[i]);
	std::cout << "Pass!\n\n";

	
	//START OF String////////////////////////////////////////////////
	StaticArray <string, 100> sS;
	const string string1 = "Suh ";
	const string string2 = "Dude";
	const string string3 = "!!!!!!!!!!!!!!!!!!";

	std::cout << "Character Static Array test:" << std::endl
		<< "-------------------------------" << std::endl;

	//StaticArray::capacity()
	std::cout << "Testing StaticArray::capacity()" << std::endl
		<< "Expected: 100" << std::endl
		<< "Actual: " << sS.capacity() << std::endl << std::endl;
	assert(sS.capacity() == 100);

	//StaticArray::Array default constructor
	std::cout << "\nTesting StaticArray::StaticArray\n";
	for (int i = 0; i < sS.capacity(); i++)
		assert(sS[i] == std::string());
	std::cout << "Pass!\n\n";

	//StaticArray::operator[] setter;
	sS[6] = string1;
	std::cout << "\nTesting StaticArray::operator[] setter\n";
	std::cout << "Expected: " << string1 << " for sS[6]\n";
	std::cout << "Actual: " << sS[6] << std::endl << std::endl;
	assert(sS[6] == string1);

	sS[7] = string2;
	std::cout << "Expected: " << string2 << " for sS[7]\n";
	std::cout << "Actual: " << sS[7] << std::endl << std::endl;
	assert(sS[7] == string2);

	sS[-1000] = string3;
	std::cout << "Expected: " << string3 << " for sS[-1000]\n";
	std::cout << "Actual: " << sS[-1000] << std::endl << std::endl;
	assert(sS[-1000] == string3);


	assert(string1 == sS[6]);
	assert(string2 == sS[7]);
	assert(string3 == sS[-6]); // any out of range uses dummy
	assert(string3 == sS[100]); // checks upper end of range
	assert(string3 != sS[99]); //checks upper end of range
	assert(string3 != sS[0]); // checks lower end of range


	//StaticArray::Operator[] getter
	std::cout << "\nTesting the StaticArray::operator[] getter\n";
	const StaticArray<string, 100> sSC = sS;
	for (int i = 0; i < sSC.capacity(); i++)
		assert(sS[i] == sSC[i]);
	std::cout << "Pass!\n\n";

	std::string pause;
	std::cin >> pause;
}



