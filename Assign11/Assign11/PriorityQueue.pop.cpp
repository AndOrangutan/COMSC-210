//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <iostream>

using namespace std;

#include "PriorityQueue.h"
#include <time.h>
#include <stdlib.h>
#include <assert.h> // error checking stuff

int main()
{
	//Programmer Info
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl;

	std::srand(time(0)); std::rand(); // seed the random number gernerator (in case you need it)

	// programmer customization go here
	int n = 1000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
	const int reps = n / 100; // one percent of starting n;

	std::cout.setf(std::ios::fixed);
	std::cout.precision(4);
	double elapsedSecondsNorm = 0;
	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		// problem setup goes herer -- create a data structure
		PriorityQueue<int> queue(n + reps); // enough capacity that doubling is not needed
		for (int i = 0; i < n; i++)
			queue.push(std::rand());

		// assert that n is the size of the data structure if applicable
		assert(queue.size() == n); // or something like that...

		// start the timer, do something, and stop the timer
		clock_t startTime = clock();
		for (int rep = 0; rep < reps; rep++)
		{
			// do something where n is the "size" of the problem
			queue.pop();
		}
		clock_t endTime = clock();

		// validation block -- assure that process worked if applicable
		//assert(queue.size() == n + reps);

		//compute timing results
		double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
		double factor = pow(2.0, double(cycle));
		double myFactor = 1;
		if (cycle == 0)
			elapsedSecondsNorm = elapsedSeconds;
		double expectedSecondsLog = log(double(n)) / log(n / factor) * elapsedSecondsNorm;

		if (cycle == 0)
			std::cout << elapsedSeconds << " (expectd) for n=" << n << std::endl;
		else
			std::cout << elapsedSeconds << " (expected " << elapsedSecondsNorm << " to  " << expectedSecondsLog << ") for n=" << n << std::endl;
	}
	getchar();
}
