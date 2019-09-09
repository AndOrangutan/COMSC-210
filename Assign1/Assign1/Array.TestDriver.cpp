//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <iostream>
#include <string>

using namespace std;

#include <cassert>
#include "Array.h"


void AMD(std::string, int, int); //417373657274204d65204461646479	;)
void AMD(int, int);

int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	 Array a;
	 
	 std::cout << "\nTesting Array::Array\n" << std::endl;
	 for (int i = 0; i < a.capacity(); i++)
	 {
		  assert(a[i] == 0);
	 }
	 
	 AMD("Array::capacity()", 100, a.capacity());
	 
	 AMD("Array::operator[](int) const", 0, a[5]); //get

	 a[5] = 69420;
	 AMD("Array::operator[](int)", 69420, a[5]); //set

	 a[-1000] = 8008135;
	 AMD("a[-1000] = 8008135", 8008135, a[-1000]); // out of range test

	 AMD("a[-3] == dummy", 8008135, a[-3]); // Makes sure all out of range use dummy
	 AMD("a[99] == 0", 0, a[99]);
	 
	 std::string pause;
	 std::cin >> pause;
}


void AMD(std::string functName, int expect, int actual)
{
	 std::cout << "\nTesting " << functName << std::endl
		  << "EXPECTED: " << expect << std::endl
		  << "ACTUAL: " << actual << std::endl << std::endl;
	 assert(expect == actual);
}

void AMD(int expect, int actual)
{
	 std::cout << "EXPECTED: " << expect << std::endl
		  << "ACTUAL: " << actual << std::endl << std::endl;
	 assert(expect == actual);
}

