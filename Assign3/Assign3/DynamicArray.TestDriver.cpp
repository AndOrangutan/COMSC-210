//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <iostream>
#include <string>

using namespace std;

#include "DynamicArray.h"
#include <cassert>
#include "DynamicArray.h" //#ifndef check


int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	DynamicArray <int> sI(100);
	DynamicArray <const int> sIC(100);
	DynamicArray <char> sC(100);

	/*
	std::cout << "\nTesting " << "" << std::endl
		<< "Expected: " << "" << std::endl
		<< "ACTUAL: " << << std::endl << std::endl;
		assert();
	*/

	std::cout << "\nTesting Array::Array\n" << std::endl;
	for (int i = 0; i < sI.capacity(); i++)
	{
		assert(sI[i] == 0);
	}


	std::cout << "\nTesting " << "DynamicArray::capacity()" << std::endl
		<< "EXPECTED: " << 100 << std::endl
		<< "ACTUAL: " << sI.capacity << std::endl << std::endl;
	assert(100 == sI.capacity);



	sI[5] = 69420;
	//set
	std::cout << "\nTesting " << "DynamicArray::operator[](int)" << std::endl
		<< "EXPECTED: " << 69420 << std::endl
		<< "ACTUAL: " << sI[5] << std::endl << std::endl;
	assert(69420 == sI[5]);

	sI[-1000] = 8008135;
	// out of range test
	std::cout << "\nTesting " << "Assignment of out of range" << std::endl
		<< "Expected: " << "8008135" << std::endl
		<< "ACTUAL: " << sI[-1000] << std::endl << std::endl;
	assert(8008135 == sI[-1000]);

	// Makes sure all out of range use dummy
	std::cout << "\nTesting " << "All out of range return dummy" << std::endl
		<< "Expected: " << "8008135" << std::endl
		<< "ACTUAL: " << sI[-3] << std::endl << std::endl;
	assert(8008135 == sI[-3]);


	std::cout << "\nTesting " << "sI[99] and sI[0] both are in range, thus not equal to dummy" << std::endl
		<< "Expected: " << "0" << std::endl
		<< "Actual: " << sI[99] << std::endl << std::endl;
	assert((sI[99] != sI[-1]) && (sI[0] != sI[-1]));

	std::cout << "\nTesting " << "DynamicArray::capacity()" << std::endl
		<< "Expected: " << "5" << std::endl
		<< "Actual: " << sC.capacity << std::endl << std::endl;
	assert(5 == sC.capacity());

	sC[4] = 'h';
	std::cout << "\nTesting " << "DynamicArray::operator[]" << std::endl
		<< "Expected: " << "'h'" << std::endl
		<< "Actual: " << sC[4] << std::endl << std::endl;
	assert('h' == sC[4]);

	DynamicArray <char> sC2 = sC;
	std::string pause;
	std::cin >> pause;
}
