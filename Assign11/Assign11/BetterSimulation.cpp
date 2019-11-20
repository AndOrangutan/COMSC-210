// Programmer: Von Mueller
// Programmer's ID: 1735441

// includes
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// .h includes
#include "Queue.h"
#include "DynamicArray.h"
#include "PriorityQueue.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

// Functions
Queue<float> readFile();
bool operator<(const serviceEvent&, const serviceEvent&);
int getRandomNumberOfArrivals(double);

// Class
class Customer
{
public:
	char id = '!';
	int arrivalTime = 1;
};

class serverInfo
{
public:
	Customer customer;
	bool idle;
};

class serviceEvent
{
public:
	int serverNum;
	int endTime;
};


int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl << std::endl;

	srand(time(0)); rand(); // srand() seed

	int numOfServers = 1;
	float arrivalRate = 1;
	int maxQueueLength = 1;
	int minServiceTime = 1;
	int maxServiceTime = 2;
	int arrivalStop = 1;

	Queue<Customer> waitLine;
	DynamicArray<serverInfo> servers;
	PriorityQueue<serviceEvent> eventList;


	//set values
	Queue<float> bbq = readFile();

	numOfServers = bbq.front();
	bbq.pop();
	arrivalRate = bbq.front();
	bbq.pop();
	maxQueueLength = bbq.front();
	bbq.pop();
	minServiceTime = bbq.front();
	bbq.pop();
	maxServiceTime = bbq.front();
	bbq.pop();
	arrivalStop = bbq.front();
	bbq.pop();

	const int SPACE1 = 23;
	std::cout << std::setw(SPACE1) << std::left << "Number of Servers: " << numOfServers << std::endl
		<< std::setw(SPACE1) << std::left << "Customer Arrival Rate: " << arrivalRate << " per minute, for " << arrivalStop << " minutes" << std::endl
		<< std::setw(SPACE1) << std::left << "Maximum Queue length: " << maxQueueLength << std::endl
		<< std::setw(SPACE1) << std::left << "Minimum Service Time: " << minServiceTime << " minutes" << std::endl
		<< std::setw(SPACE1) << std::left << "Maximum Service Time: " << maxServiceTime << " minutes" << std::endl;
	

	bool flag = false;
	for (int time = 0; ; time++)
	{
		// Finish Service//////////////////////////////////////////////////////////////////////////////////////////
		
		for (int i = 0; i < numOfServers; i++)
			if (servers[i].idle == false) // if busy
				if (eventList.top().serverNum == i && eventList.top().endTime == time) // stuff
					servers[i].idle = true;
		

		// Update Queue////////////////////////////////////////////////////////////////////////////////////////////
		bool isFirst = true;
		char dummy;
		int arrivals = getRandomNumberOfArrivals(arrivalRate);
		while (arrivals > 0)
		{
			if (waitLine.size() < maxQueueLength)
			{
				Customer c;
				if (waitLine.empty == true && isFirst == true)
				{
					dummy = 'A';
					isFirst = false;
				}
				else if (dummy == 'Z')
					dummy = 'A';
				else
					dummy = char(1 + int(dummy));
				c.id = dummy;
				c.arrivalTime = time;
				waitLine.push(c);
			}
			arrivals--;
		}

		// Start Service///////////////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < numOfServers; i++)
		{
			if (servers[i].idle == true && !waitLine.empty())
			{
				servers[i].customer = waitLine.front();
				waitLine.pop();

				serviceEvent c;
				c.endTime = (time + (rand() % (maxServiceTime - minServiceTime) + 3));
				c.serverNum = 0;
				eventList.push(c);
			}
		}

		// Draw Sim////////////////////////////////////////////////////////////////////////////////////////////////
		//  __________________________________
		// | Server | Time for End-of-Service |
		// |--------|-------------------------|
		// |       0|                        3|
		// |       1|                        3|
		// |________|_________________________|
		// Timer:                            
		//  __________________________________
		// | Server | Now Serving | Wait Line |
		// |--------|-------------|-----------|
		// |       0|            A|           |
		// |       1|            B|           |
		// |________|_____________|___________|
		
		const int SCALE1 = 1;
		const int SCALE2 = 1;
		const int SCALE3 = 6;
		const int SCALE4 = 11;
		const int SCALE5 = 10;

		Queue<Customer> newQ = waitLine;
		PriorityQueue<serviceEvent> newPQ= eventList;

		std::cout << " __________________________________" << std::endl
			<< "| Server | Time for End-of-Service |" << std::endl
			<< "|--------|-------------------------|" << std::endl;
		for (int i = 0; i < numOfServers; i++)
		{
			std::cout << std::right << '|' << std::setw(SCALE1) << newPQ.top().serverNum << '|' << std::setw(SCALE2) << newPQ.top().endTime << "|" << std::endl;
			newPQ.pop;
		}
		std::cout << std::endl << "Time: " << time << std::endl
			<< " __________________________________" << std::endl
			<< "| Server | Now Serving | Wait Line |" << std::endl
			<< "|--------|-------------|-----------|" << std::endl;
		for (int i = 0; i < numOfServers; i++)
		{
			if (i == 0)
			{
				std::cout << std::right << '|' << std::setw(SCALE3) << i << '|' << std::setw(SCALE4);
				if (servers[i].idle == false)
					std::cout << servers[i].customer.id;
				else
					std::cout << ' ';

				std::string s;
				if (!newQ.empty())//might not need this
				{
					while (!newQ.empty())
					{
						s.push_back(newQ.front().id);
						newQ.pop();
					}
				}
				std::cout << '|' << std::setw(SCALE5) << s;
				std::cout << '|' << std::endl;
			}
			else
			{
				std::cout << std::right << '|' << std::setw(SCALE3) << i << '|' << std::setw(SCALE4);
				if (servers[i].idle == false)
					std::cout << servers[i].customer.id;
				else
					std::cout << ' ';
				std::cout << '|' << std::setw(SCALE5 + 1) << '|' << std::endl;
			}
		}
		std::cout << "|______|___________|__________|" << std::endl
			<< "Press ENTER to continue..." << std::endl;
		std::getchar();

	std::cout << "Done!";

	std::getchar();
	// read the input file
	//while (fin.good())
}

Queue<float> readFile()
{
	// open the input file
	std::ifstream myfile("simulation.txt");

	if (!myfile.good())
		std::cout << "I/O error. File can't find!\n";

	Queue<float> bbQueue;

	while (myfile.good())
	{
		std::string line;
		std::getline(myfile, line);


		bbQueue.push(atof(line.c_str()));
	}
	myfile.close();
	return bbQueue;
}

bool operator<(const serviceEvent& a, const serviceEvent& b)
{
	return a.endTime < b.endTime ? false : true;
}

int getRandomNumberOfArrivals(double averageArrivalRate)
{
	int arrivals = 0;
	double probOfnArrivals = exp(-averageArrivalRate);
	for (double randomValue = (double)rand() / RAND_MAX;
		(randomValue -= probOfnArrivals) > 0.0;
		probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
	return arrivals;
}