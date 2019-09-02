#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main()
{
	 char sign[4] = { '+', '-', '*', '/' };
	 srand(time(NULL));

	 int nums[2] = { (rand() % 98 + 1), (rand() % 98 + 1) };
	 int randVal = (rand() % 4);

	 int answer;


	 switch (randVal)
	 {
	 case 0:
		  answer = nums[0] + nums[1];
		  break;
	 case 1:
		  answer = nums[0] - nums[1];
		  break;
	 case 2:
		  answer = nums[0] * nums[1];
		  break;
	 case 3:
		  answer = nums[0] / nums[1];
		  break;
	 default:
		  answer = 1000000;
	 }

	 std::string buf;

	 std::cout << "What is the value of " << nums[0] << " " << sign[randVal] << " " << nums[1] << " (round to a down to a whole number if needed): " << answer << std::endl;
	 std::cin >> buf;

	 if (answer == atoi(buf.c_str()))
		  std::cout << "Correct!";
	 else
		  std::cout << "Incorrect!";

	 bool temp;
	 std::cin >> temp;
}

