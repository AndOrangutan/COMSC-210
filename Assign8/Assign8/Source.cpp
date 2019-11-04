#include <iostream>
#include <ctime>

int main()
{
	clock_t start = clock();
	while (true)
	{
		if (start == clock())
			std::cout << "I" << std::endl;
		else if (start + 399 == clock())
		{
			std::cout << "DIE!!!" << std::endl;
			break;
		}
		else
		{
			std::cout << "DIE!!!" << std::endl;
			break;
		}
	}
	getchar();
		
}