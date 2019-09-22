//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "DynamicArray.h"
#include "DynamicArray.h" //#ifndef check


int main()
{/*
	//START OF TYPE///////////////////////////////////////////////////////////////
	DynamicArray <TYPE> sI(100);
	
	const TYPE val1 = value1;
	const TYPE val2 = value2;ss
	const TYPE val3 = value3; //dummy

	std::cout << "TYPE Dynamic Array test:" << std::endl
		<< "-------------------------------" << std::endl;

	//DynamicArray::capacity() getter
	std::cout << "Testing DynamicArray::capacity() getter" << std::endl
		<< "Expected: 100" << std::endl
		<< "Actual: " << sI.capacity() << std::endl << std::endl;
	assert(sI.capacity() == 100);

	//DynamicArray::capacity() setter
	sI.capacity(120);
	std::cout << "Testing DynamicArray::capacity() setter" << std::endl
		<< "Expected: 120" << std::endl
		<< "Actual: " << sI.capacity() << std::endl << std::endl;
	assert(sI.capacity() == 120);

	//DynamicArray::DynamicArray default constructor
	std::cout << "\nTesting DynamicArray::DynamicArray\n";
	for (int i = 0; i < sI.capacity(); i++)
		assert(sI[i] == TYPE());
	std::cout << "Pass!\n\n";

	//DynamicArray::DynamicArray Copy constructor
	std::cout << "\nTesting Copy Constructor\n";
	DynamicArray <TYPE> s2 = sI;
	for (int i = 0; i < s2.capacity(); i++)
		assert(sI[i] == s2[i]);
	std::cout << "Pass!\n\n";

	//DynamicArray::operator=
	std::cout << "\nTesting Assignment operator\n";
	sI[5] = val1;
	s2 = sI;
	for (int i = 0; i < s2.capacity(); i++)
		assert(sI[i] == s2[i]);
	std::cout << "Pass!\n\n";

	//DynamicArray::operator[] setter
	sI[6] = val1;
	std::cout << "\nTesting DynamicArray::operator[] setter\n";
	std::cout << "Expected: " << val1 << " for sI[6]\n";
	std::cout << "Actual: " << sI[6] << std::endl << std::endl;
	assert(sI[6] == val1);

	sI[7] = val2;
	std::cout << "Expected: " << val2 << " for sI[7]\n";
	std::cout << "Actual: " << sI[7] << std::endl << std::endl;
	assert(sI[7] == val2);

	sI[-1000] = val3;
	std::cout << "Expected: " << val3 << " for sI[-1000]\n";
	std::cout << "Actual: " << sI[-1000] << std::endl << std::endl;
	assert(sI[-1000] == val3);


	assert(val1 == sI[6]);
	assert(val2 == sI[7]);
	assert(val3 == sI[-6]); // any out of range uses dummy
	assert(val3 == sI[120]); // checks upper end of range
	assert(val3 != sI[119]); //checks upper end of range
	assert(val3 != sI[0]); // checks lower end of range


	//DynamicArray::Operator[] getter
	std::cout << "\nTesting the DynamicArray::operator[] getter\n";
	const DynamicArray<TYPE> sIC = sI;
	for (int i = 0; i < sIC.capacity(); i++)
		assert(sI[i] == sIC[i]);
	std::cout << "Pass!\n\n";
	*/
	
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	

	//START OF int///////////////////////////////////////////////////////////////
	DynamicArray <int> dyArrI(100);

	const int int1 = 8008135;
	const int int2 = 42069;
	const int int3 = 987654321; //dummy

	std::cout << "int Dynamic Array test:" << std::endl
		<< "-------------------------------" << std::endl;

	//DynamicArray::capacity() getter
	std::cout << "Testing DynamicArray::capacity() getter" << std::endl
		<< "Expected: 100" << std::endl
		<< "Actual: " << dyArrI.capacity() << std::endl << std::endl;
	assert(dyArrI.capacity() == 100);

	//DynamicArray::capacity() setter
	dyArrI.capacity(120);
	std::cout << "Testing DynamicArray::capacity() setter" << std::endl
		<< "Expected: 120" << std::endl
		<< "Actual: " << dyArrI.capacity() << std::endl << std::endl;
	assert(dyArrI.capacity() == 120);

	//DynamicArray::DynamicArray default constructor
	std::cout << "\nTesting DynamicArray::DynamicArray\n";
	for (int i = 0; i < dyArrI.capacity(); i++)
		assert(dyArrI[i] == int());
	std::cout << "Pass!\n\n";

	//DynamicArray::DynamicArray Copy constructor
	std::cout << "\nTesting Copy Constructor\n";
	DynamicArray <int> dyArrI2 = dyArrI;
	for (int i = 0; i < dyArrI2.capacity(); i++)
		assert(dyArrI[i] == dyArrI2[i]);
	std::cout << "Pass!\n\n";

	//DynamicArray::operator=
	std::cout << "\nTesting Assignment operator\n";
	dyArrI[5] = int1;
	dyArrI2 = dyArrI;
	for (int i = 0; i < dyArrI2.capacity(); i++)
		assert(dyArrI[i] == dyArrI2[i]);
	std::cout << "Pass!\n\n";

	//DynamicArray::operator[] setter
	dyArrI[6] = int1;
	std::cout << "\nTesting DynamicArray::operator[] setter\n";
	std::cout << "Expected: " << int1 << " for dyArrI[6]\n";
	std::cout << "Actual: " << dyArrI[6] << std::endl << std::endl;
	assert(dyArrI[6] == int1);

	dyArrI[7] = int2;
	std::cout << "Expected: " << int2 << " for dyArrI[7]\n";
	std::cout << "Actual: " << dyArrI[7] << std::endl << std::endl;
	assert(dyArrI[7] == int2);

	dyArrI[-1000] = int3;
	std::cout << "Expected: " << int3 << " for dyArrI[-1000]\n";
	std::cout << "Actual: " << dyArrI[-1000] << std::endl << std::endl;
	assert(dyArrI[-1000] == int3);


	assert(int1 == dyArrI[6]);
	assert(int2 == dyArrI[7]);
	assert(int3 == dyArrI[-6]); // any out of range uses dummy
	assert(int3 == dyArrI[120]); // checks upper end of range
	assert(int3 != dyArrI[119]); //checks upper end of range
	assert(int3 != dyArrI[0]); // checks lower end of range


	//DynamicArray::Operator[] getter
	std::cout << "\nTesting the DynamicArray::operator[] getter\n";
	const DynamicArray<int> dyArrIC = dyArrI;
	for (int i = 0; i < dyArrIC.capacity(); i++)
		assert(dyArrI[i] == dyArrIC[i]);
	std::cout << "Pass!\n\n";
	

	//START OF double///////////////////////////////////////////////////////////////
	DynamicArray <double> dyArrD(100);

	const double double1 = 0.00023;
	const double double2 = 23456.7;
	const double double3 = 1.2; //dummy

	std::cout << "double Dynamic Array test:" << std::endl
		<< "-------------------------------" << std::endl;

	//DynamicArray::capacity() getter
	std::cout << "Testing DynamicArray::capacity() getter" << std::endl
		<< "Expected: 100" << std::endl
		<< "Actual: " << dyArrD.capacity() << std::endl << std::endl;
	assert(dyArrD.capacity() == 100);

	//DynamicArray::capacity() setter
	dyArrD.capacity(120);
	std::cout << "Testing DynamicArray::capacity() setter" << std::endl
		<< "Expected: 120" << std::endl
		<< "Actual: " << dyArrD.capacity() << std::endl << std::endl;
	assert(dyArrD.capacity() == 120);

	//DynamicArray::DynamicArray default constructor
	std::cout << "\nTesting DynamicArray::DynamicArray\n";
	for (int i = 0; i < dyArrD.capacity(); i++)
		assert(dyArrD[i] == double());
	std::cout << "Pass!\n\n";

	//DynamicArray::DynamicArray Copy constructor
	std::cout << "\nTesting Copy Constructor\n";
	DynamicArray <double> dyArrD2 = dyArrD;
	for (int i = 0; i < dyArrD2.capacity(); i++)
		assert(dyArrD[i] == dyArrD2[i]);
	std::cout << "Pass!\n\n";

	//DynamicArray::operator=
	std::cout << "\nTesting Assignment operator\n";
	dyArrD[5] = double1;
	dyArrD2 = dyArrD;
	for (int i = 0; i < dyArrD2.capacity(); i++)
		assert(dyArrD[i] == dyArrD2[i]);
	std::cout << "Pass!\n\n";

	//DynamicArray::operator[] setter
	dyArrD[6] = double1;
	std::cout << "\nTesting DynamicArray::operator[] setter\n";
	std::cout << "Expected: " << double1 << " for dyArrD[6]\n";
	std::cout << "Actual: " << dyArrD[6] << std::endl << std::endl;
	assert(dyArrD[6] == double1);

	dyArrD[7] = double2;
	std::cout << "Expected: " << double2 << " for dyArrD[7]\n";
	std::cout << "Actual: " << dyArrD[7] << std::endl << std::endl;
	assert(dyArrD[7] == double2);

	dyArrD[-1000] = double3;
	std::cout << "Expected: " << double3 << " for dyArrD[-1000]\n";
	std::cout << "Actual: " << dyArrD[-1000] << std::endl << std::endl;
	assert(dyArrD[-1000] == double3);


	assert(double1 == dyArrD[6]);
	assert(double2 == dyArrD[7]);
	assert(double3 == dyArrD[-6]); // any out of range uses dummy
	assert(double3 == dyArrD[120]); // checks upper end of range
	assert(double3 != dyArrD[119]); //checks upper end of range
	assert(double3 != dyArrD[0]); // checks lower end of range


	//DynamicArray::Operator[] getter
	std::cout << "\nTesting the DynamicArray::operator[] getter\n";
	const DynamicArray<double> dyArrDC = dyArrD;
	for (int i = 0; i < dyArrDC.capacity(); i++)
		assert(dyArrD[i] == dyArrDC[i]);
	std::cout << "Pass!\n\n";


	//START OF std::string///////////////////////////////////////////////////////////////
	DynamicArray <std::string> sI(100);

	const std::string string1 = "(* >*)";
	const std::string string2 = "string";
	const std::string string3 = "123four5"; //dummy

	std::cout << "std::string Dynamic Array test:" << std::endl
		<< "-------------------------------" << std::endl;

	//DynamicArray::capacity() getter
	std::cout << "Testing DynamicArray::capacity() getter" << std::endl
		<< "Expected: 100" << std::endl
		<< "Actual: " << sI.capacity() << std::endl << std::endl;
	assert(sI.capacity() == 100);

	//DynamicArray::capacity() setter
	sI.capacity(120);
	std::cout << "Testing DynamicArray::capacity() setter" << std::endl
		<< "Expected: 120" << std::endl
		<< "Actual: " << sI.capacity() << std::endl << std::endl;
	assert(sI.capacity() == 120);

	//DynamicArray::DynamicArray default constructor
	std::cout << "\nTesting DynamicArray::DynamicArray\n";
	for (int i = 0; i < sI.capacity(); i++)
		assert(sI[i] == std::string());
	std::cout << "Pass!\n\n";

	//DynamicArray::DynamicArray Copy constructor
	std::cout << "\nTesting Copy Constructor\n";
	DynamicArray <std::string> s2 = sI;
	for (int i = 0; i < s2.capacity(); i++)
		assert(sI[i] == s2[i]);
	std::cout << "Pass!\n\n";

	//DynamicArray::operator=
	std::cout << "\nTesting Assignment operator\n";
	sI[5] = string1;
	s2 = sI;
	for (int i = 0; i < s2.capacity(); i++)
		assert(sI[i] == s2[i]);
	std::cout << "Pass!\n\n";

	//DynamicArray::operator[] setter
	sI[6] = string1;
	std::cout << "\nTesting DynamicArray::operator[] setter\n";
	std::cout << "Expected: " << string1 << " for sI[6]\n";
	std::cout << "Actual: " << sI[6] << std::endl << std::endl;
	assert(sI[6] == string1);

	sI[7] = string2;
	std::cout << "Expected: " << string2 << " for sI[7]\n";
	std::cout << "Actual: " << sI[7] << std::endl << std::endl;
	assert(sI[7] == string2);

	sI[-1000] = string3;
	std::cout << "Expected: " << string3 << " for sI[-1000]\n";
	std::cout << "Actual: " << sI[-1000] << std::endl << std::endl;
	assert(sI[-1000] == string3);


	assert(string1 == sI[6]);
	assert(string2 == sI[7]);
	assert(string3 == sI[-6]); // any out of range uses dummy
	assert(string3 == sI[120]); // checks upper end of range
	assert(string3 != sI[119]); //checks upper end of range
	assert(string3 != sI[0]); // checks lower end of range


	//DynamicArray::Operator[] getter
	std::cout << "\nTesting the DynamicArray::operator[] getter\n";
	const DynamicArray<std::string> sIC = sI;
	for (int i = 0; i < sIC.capacity(); i++)
		assert(sI[i] == sIC[i]);
	std::cout << "Pass!\n\n";


	std::string pause;
	std::cin >> pause;
}
