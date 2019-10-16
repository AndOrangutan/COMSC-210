//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <iostream>
#include <string>

using namespace std;

#include <cassert>
#include "Queue.h"
#include "Queue.h" // ifndef check

int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl << std::endl;
	/*
	////Start of string test////////////////////////////////////////////////////
	const string string1 = 1.1;
	const string string2 = 2.2;
	const string string3 = 3.333;
	Queue<string> qstring;
	
	//Intro
	std::cout << "Queue test: string" << std::endl
		<< "-------------------------------" << std::endl;

	//Queue::size() test
	std::cout << "Testing Queue::size()" << std::endl
		<< "Expected: " << string() << std::endl
		<< "Actual: " << qstring.size() << std::endl;
	assert(qstring.size() == string());
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::push() & Queue::front() test
	qstring.push(string1);
	std::cout << "Testing Queue::push() and Queue::front()" << std::endl
		<< "Expected: " << string1 << std::endl
		<< "Actual: " << qstring.front() << std::endl;
	assert(qstring.front() == string1);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::pop() test
	qstring.push(string2);
	std::cout << "Testing Queue::pop()" << std::endl
		<< "Before pop: " << qstring.front() << std::endl;
	qstring.pop();
	std::cout << "After pop: " << qstring.front() << std::endl;
	assert(qstring.front() == string2);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::back() test
	qstring.push(string3);
	std::cout << "Testing Queue::back()" << std::endl
		<< "Expected: " << string3 << std::endl
		<< "Actual: " << qstring.back() << std::endl;
	assert(qstring.back() == string3);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue copy constructor test
	Queue<string> qstring2 = qstring;
	std::cout << "Testing Copy Constructor" << std::endl;
	assert(qstring2.size() == qstring.size());
	assert(qstring2.front() == qstring.front());
	assert(qstring2.back() == qstring.back());
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue assignment operator test
	qstring.pop();
	qstring2 = qstring;
	std::cout << "Testing Assignment Operator" << std::endl;
	assert(qstring2.size() == qstring.size());
	assert(qstring2.front() == qstring.front());
	assert(qstring2.back() == qstring.back());
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::clear() & Queue::empty() test
	qstring.clear();
	std::cout << "Testing Queue::clear() and Queue::empty()" << std::endl;
	assert(qstring.size() == 0);
	assert(qstring.empty() == true);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue constant object test
	qstring.push(string1);
	qstring.push(string2);
	qstring.push(string3);
	const Queue<string> qstring3 = qstring;
	std::cout << "Testing const object" << std::endl
		<< "Size: " << qstring3.size() << std::endl;
	assert(qstring3.size() == qstring.size());
	if (qstring3.empty() == true)
		std::cout << "It is empty!" << std::endl;
	else
		std::cout << "It is NOT empty!" << std::endl;
	assert(qstring3.empty() == qstring.empty());
	////End of string test////////////////////////////////////////////////////
	*/


	////Start of double test////////////////////////////////////////////////////
	const double double1 = 1.1;
	const double double2 = 2.2;
	const double double3 = 3.333;
	Queue<double> qdouble;

	//Intro
	std::cout << "Queue test: double" << std::endl
		<< "-------------------------------" << std::endl;

	//Queue::size() test
	std::cout << "Testing Queue::size()" << std::endl
		<< "Expected: " << double() << std::endl
		<< "Actual: " << qdouble.size() << std::endl;
	assert(qdouble.size() == double());
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::push() & Queue::front() test
	qdouble.push(double1);
	std::cout << "Testing Queue::push() and Queue::front()" << std::endl
		<< "Expected: " << double1 << std::endl
		<< "Actual: " << qdouble.front() << std::endl;
	assert(qdouble.front() == double1);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::pop() test
	qdouble.push(double2);
	std::cout << "Testing Queue::pop()" << std::endl
		<< "Before pop: " << qdouble.front() << std::endl;
	qdouble.pop();
	std::cout << "After pop: " << qdouble.front() << std::endl;
	assert(qdouble.front() == double2);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::back() test
	qdouble.push(double3);
	std::cout << "Testing Queue::back()" << std::endl
		<< "Expected: " << double3 << std::endl
		<< "Actual: " << qdouble.back() << std::endl;
	assert(qdouble.back() == double3);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue copy constructor test
	Queue<double> qdouble2 = qdouble;
	std::cout << "Testing Copy Constructor" << std::endl;
	assert(qdouble2.size() == qdouble.size());
	assert(qdouble2.front() == qdouble.front());
	assert(qdouble2.back() == qdouble.back());
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue assignment operator test
	qdouble.pop();
	qdouble2 = qdouble;
	std::cout << "Testing Assignment Operator" << std::endl;
	assert(qdouble2.size() == qdouble.size());
	assert(qdouble2.front() == qdouble.front());
	assert(qdouble2.back() == qdouble.back());
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::clear() & Queue::empty() test
	qdouble.clear();
	std::cout << "Testing Queue::clear() and Queue::empty()" << std::endl;
	assert(qdouble.size() == 0);
	assert(qdouble.empty() == true);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue constant object test
	qdouble.push(double1);
	qdouble.push(double2);
	qdouble.push(double3);
	const Queue<double> qdouble3 = qdouble;
	std::cout << "Testing const object" << std::endl
		<< "Size: " << qdouble3.size() << std::endl;
	assert(qdouble3.size() == qdouble.size());
	if (qdouble3.empty() == true)
		std::cout << "It is empty!" << std::endl;
	else
		std::cout << "It is NOT empty!" << std::endl;
	assert(qdouble3.empty() == qdouble.empty());
	////End of double test////////////////////////////////////////////////////

	////Start of string test////////////////////////////////////////////////////
	const string string1 = "Hello";
	const string string2 = "Big";
	const string string3 = "World!";
	Queue<string> qstring;

	//Intro
	std::cout << std::endl << std::endl << "Queue test: string" << std::endl
		<< "-------------------------------" << std::endl;

	//Queue::size() test
	std::cout << "Testing Queue::size()" << std::endl
		<< "Expected: " << 0 << std::endl
		<< "Actual: " << qstring.size() << std::endl;
	assert(qstring.size() == 0);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::push() & Queue::front() test
	qstring.push(string1);
	std::cout << "Testing Queue::push() and Queue::front()" << std::endl
		<< "Expected: " << string1 << std::endl
		<< "Actual: " << qstring.front() << std::endl;
	assert(qstring.front() == string1);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::pop() test
	qstring.push(string2);
	std::cout << "Testing Queue::pop()" << std::endl
		<< "Before pop" << qstring.front() << std::endl;
	qstring.pop();
	std::cout << "After pop: " << qstring.front() << std::endl;
	assert(qstring.front() == string2);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::back() test
	qstring.push(string3);
	std::cout << "Testing Queue::back()" << std::endl
		<< "Expected: " << string3 << std::endl
		<< "Actual: " << qstring.back() << std::endl;
	assert(qstring.back() == string3);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue copy constructor test
	Queue<string> qstring2 = qstring;
	std::cout << "Testing Copy Constructor" << std::endl;
	assert(qstring2.size() == qstring.size());
	assert(qstring2.front() == qstring.front());
	assert(qstring2.back() == qstring.back());
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue assignment operator test
	qstring.pop();
	qstring2 = qstring;
	std::cout << "Testing Assignment Operator" << std::endl;
	assert(qstring2.size() == qstring.size());
	assert(qstring2.front() == qstring.front());
	assert(qstring2.back() == qstring.back());
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue::clear() & Queue::empty() test
	qstring.clear();
	std::cout << "Testing Queue::clear() and Queue::empty()" << std::endl;
	assert(qstring.size() == 0);
	assert(qstring.empty() == true);
	std::cout << "Pass!" << std::endl << std::endl;

	//Queue constant object test
	qstring.push(string1);
	qstring.push(string2);
	qstring.push(string3);
	const Queue<string> qstring3 = qstring;
	std::cout << "Testing const object" << std::endl
		<< "Size: " << qstring3.size() << std::endl;
	assert(qstring3.size() == qstring.size());
	if (qstring3.empty() == true)
		std::cout << "It is empty!" << std::endl;
	else
		std::cout << "It is NOT empty!" << std::endl;
	assert(qstring3.empty() == qstring.empty());
	////End of string test////////////////////////////////////////////////////

	int pause;
	std::cin >> pause;
}