//Programmer: Von Mueller
//Programmer's ID: 1735441


#include <string>
#include <iostream>

using namespace std;

#include <assert.h>
#include "Stack.h"
#include "Stack.h" // ifndef test

int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	/*
	//Stack TYPE test
	const TYPE TYPE1 = 1.1;
	const TYPE TYPE2 = 2.2;
	const TYPE TYPE3 = 3.333;
	Stack<TYPE> sTYPE;

	std::cout << "Stack test: (TYPE)" << std::endl
		<< "-----------------" << std::endl;

	//Testing Stack::size()
	std::cout << "Testing Stack::size()" << std::endl
		<< "Expected: " << 0 << std::endl
		<< "Actual: " << sTYPE.size() << std::endl;
	assert(sTYPE.size() == 0); // size
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::peek & Stack::push
	sTYPE.push(TYPE1);
	std::cout << "Testing Stack::peek() & Stack::push()" << std::endl
		<< "Expected: " << TYPE1 << std::endl
		<< "Actual: " << sTYPE.peek() << std::endl;
	assert(sTYPE.peek() == TYPE1); //Peek and push probably work
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::pop
	std::cout << "Testing Stack::pop()" << std::endl;
	sTYPE.push(TYPE2);
	std::cout << "Before pop: " << sTYPE.peek() << std::endl;
	assert(sTYPE.peek() == TYPE2); // I think pop works lol
	sTYPE.pop();
	std::cout << "After pop: " << sTYPE.peek()<< std::endl;
	assert(sTYPE.peek() == TYPE1); // I think pop works lol
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Copy Constuctor
	std::cout << "Testing copy constructor()" << std::endl;
	Stack<TYPE>sTYPE2 = sTYPE;
	assert(sTYPE2.peek( ) == sTYPE.peek());
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Assignment
	std::cout << "Testing assignment opperator()" << std::endl;
	sTYPE.push(TYPE2);
	sTYPE2 = sTYPE;
	assert(sTYPE.peek() == sTYPE2.peek());
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::size()
	std::cout << "Testing Stack::size()" << std::endl;
	sTYPE.push(TYPE3);
	std::cout << "After pushing 3 elements, size is now: " << sTYPE.size();
	assert(sTYPE.size() == 3);
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::clear() and Stack::empty()
	std::cout << "Testing Stack::clear() & Stack::empty()" << std::endl;
	const Stack<TYPE> sTYPE3 = sTYPE;
	sTYPE.clear();
	assert(sTYPE.empty() == true);
	std::cout << "Pass!" << std::endl << std::endl;

	// Const object test
	//HOW IT JUST SAYS THAT NONE OF MY FUNCTIONS CAN MODIFY IT SINCE IT IS CONST!!!
	/*std::cout << "Constant object test: " << std::endl;
	std::cout << "Size: " << sTYPE3.size();
	sTYPE3 = sTYPE;
	if (sTYPE3.size() > 0)
		std::cout << "It's NOT empty" << std::endl << std::endl;
	else
		std::cout << "Fail!" << std::endl << std::endl;
	*/
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	//Stack double test
	const double double1 = 1.1;
	const double double2 = 2.2;
	const double double3 = 3.333;
	Stack<double> sdouble;

	std::cout << "Stack test: (double)" << std::endl
		<< "-----------------" << std::endl;

	//Testing Stack::size()
	std::cout << "Testing Stack::size()" << std::endl
		<< "Expected: " << 0 << std::endl
		<< "Actual: " << sdouble.size() << std::endl;
	assert(sdouble.size() == 0); // size
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::peek & Stack::push
	sdouble.push(double1);
	std::cout << "Testing Stack::peek() & Stack::push()" << std::endl
		<< "Expected: " << double1 << std::endl
		<< "Actual: " << sdouble.peek() << std::endl;
	assert(sdouble.peek() == double1); //Peek and push probably work
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::pop
	std::cout << "Testing Stack::pop()" << std::endl;
	sdouble.push(double2);
	std::cout << "Before pop: " << sdouble.peek() << std::endl;
	assert(sdouble.peek() == double2); // I think pop works lol
	sdouble.pop();
	std::cout << "After pop: " << sdouble.peek()<< std::endl;
	assert(sdouble.peek() == double1); // I think pop works lol
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Copy Constuctor
	std::cout << "Testing copy constructor()" << std::endl;
	Stack<double>sdouble2 = sdouble;
	assert(sdouble2.peek( ) == sdouble.peek());
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Assignment
	std::cout << "Testing assignment opperator()" << std::endl;
	sdouble.push(double2);
	sdouble2 = sdouble;
	assert(sdouble.peek() == sdouble2.peek());
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::size()
	std::cout << "Testing Stack::size()" << std::endl;
	sdouble.push(double3);
	std::cout << "After pushing 3 elements, size is now: " << sdouble.size();
	assert(sdouble.size() == 3);
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::clear() and Stack::empty()
	std::cout << "Testing Stack::clear() & Stack::empty()" << std::endl;
	const Stack<double> sdouble3 = sdouble;
	sdouble.clear();
	assert(sdouble.empty() == true);
	std::cout << "Pass!" << std::endl << std::endl;

	// Const object test
	//HOW IT JUST SAYS THAT NONE OF MY FUNCTIONS CAN MODIFY IT SINCE IT IS CONST!!!
	/*std::cout << "Constant object test: " << std::endl;
	std::cout << "Size: " << sdouble3.size();
	sdouble3 = sdouble;
	if (sdouble3.size() > 0)
		std::cout << "It's NOT empty" << std::endl << std::endl;
	else
		std::cout << "Fail!" << std::endl << std::endl;
		*/

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Stack string test
	const string string1 = "Hello";
	const string string2 = "Big";
	const string string3 = "World";
	Stack<string> sstring;

	std::cout << "Stack test: (string)" << std::endl
		<< "-----------------" << std::endl;

	//Testing Stack::size()
	std::cout << "Testing Stack::size()" << std::endl
		<< "Expected: " << 0 << std::endl
		<< "Actual: " << sstring.size() << std::endl;
	assert(sstring.size() == 0); // size
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::peek & Stack::push
	sstring.push(string1);
	std::cout << "Testing Stack::peek() & Stack::push()" << std::endl
		<< "Expected: " << string1 << std::endl
		<< "Actual: " << sstring.peek() << std::endl;
	assert(sstring.peek() == string1); //Peek and push probably work
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::pop
	std::cout << "Testing Stack::pop()" << std::endl;
	sstring.push(string2);
	std::cout << "Before pop: " << sstring.peek() << std::endl;
	assert(sstring.peek() == string2); // I think pop works lol
	sstring.pop();
	std::cout << "After pop: " << sstring.peek() << std::endl;
	assert(sstring.peek() == string1); // I think pop works lol
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Copy Constuctor
	std::cout << "Testing copy constructor()" << std::endl;
	Stack<string>sstring2 = sstring;
	assert(sstring2.peek() == sstring.peek());
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Assignment
	std::cout << "Testing assignment opperator()" << std::endl;
	sstring.push(string2);
	sstring2 = sstring;
	assert(sstring.peek() == sstring2.peek());
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::size()
	std::cout << "Testing Stack::size()" << std::endl;
	sstring.push(string3);
	std::cout << "After pushing 3 elements, size is now: " << sstring.size();
	assert(sstring.size() == 3);
	std::cout << "Pass!" << std::endl << std::endl;

	//Testing Stack::clear() and Stack::empty()
	std::cout << "Testing Stack::clear() & Stack::empty()" << std::endl;
	const Stack<string> sstring3 = sstring;
	sstring.clear();
	assert(sstring.empty() == true);
	std::cout << "Pass!" << std::endl << std::endl;

	// Const object test
	/*std::cout << "Constant object test: " << std::endl;
	std::cout << "Size: " << sstring3.size();
	sstring3 = sstring;
	if (sstring3.size() > 0)
		std::cout << "It's NOT empty" << std::endl << std::endl;
	else
		std::cout << "Fail!" << std::endl << std::endl;
	*/
		

	std::string pause;
	std::cin >> pause;
}
