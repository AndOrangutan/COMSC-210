#include <iostream>
#include <string>

//Change: Added prototype to the proper place.
bool invert(bool);

int main()
{
	

	bool testVar = true;

	std::cout << "Test variable starting value: " << testVar << std::endl << std::endl;

	testVar = invert(testVar);

	std::cout << "Test variable ending value: " << testVar << std::endl << std::endl;

	std::string t;
	std::cin >> t;
}

bool invert(bool val)
bool invert(bool val)
{
	std::cout << "Inverting test variable." << std::endl << std::endl;
	return !val;
}