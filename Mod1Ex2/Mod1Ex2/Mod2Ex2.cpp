#include <iostream>
#include <string>

void output(std::string input);

int main()
{
	output("Please input what you want the output() fuction to output: ");

	std::string input;
	std::getline(std::cin, input);
	
	output("Your string: ");
	output(input);

	std::string pause;
	std::cin >> pause;
}

void output(std::string input)
{
	std::cout << input << std::endl;
}