//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <iostream>
#include <string>


//using namespace std;

#include "Stack.h"

bool impProc(Stack<double>);
void RPN(std::string, Stack<double>);
void prompt(const Stack<double>);

int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl << std::endl;

	std::cout << "Welcome to my Reverse Polish Notation calculator!" << std::endl << std::endl;

	Stack<double> RPNStack;
	do
	{
		bool exit = false;

		prompt(RPNStack);
		exit = impProc(RPNStack); // handles input and processes it. Calls RPN().
	} 
	while (exit == false);
	

}

bool impProc(Stack<double> stack)
{
	while (true)
	{
		std::string inpOne;
		std::getline(std::cin, inpOne);
		
		for (int i = 0; i < inpOne.size(); i++)
			if (inpOne[i] == ' ')
				i++;
			else if (inpOne[i] == 'q' || inpOne[i] == 'Q')
				return true;
			else if (inpOne[i] == '+' || inpOne[i] == '-' || inpOne[i] == '*' || inpOne[i] == '/')
				RPN(inpOne, stack);
			else
			{
				std::string temp;
				while (inpOne[i] != ' ' || inpOne[i] != '\n')
				{
					temp.push_back(inpOne[i]);
					i++;
				}
				stack.push(atof(temp.c_str()));
			}
		return false;
	}
}

void RPN(char sign, Stack<double> stack)
{
	double sec = stack.peek();
	stack.pop();
	double first = stack.peek();
	stack.pop();

	if (sign == '+')
		stack.push(first + sec);
	else if (sign == '-')
		stack.push(first - sec);
	else if (sign == '*')
		stack.push(first * sec);
	else if (sign == '/')
		stack.push(first / sec);
}

void prompt(const Stack<double> stack)
{
	Stack<double> popper = stack;
	Stack<double> holder;
	while (0 < popper.size())
	{
		holder.push(popper.peek());
		popper.pop();
	}

	std::cout << "ENTER: ";
	while (0 < holder.size())
	{
		std::cout << holder.peek() << " ";
		holder.pop();
	}
}