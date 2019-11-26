//Programmer: Von Mueller
//Programmer's ID: 1735441

// includes
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
//using namespace std;

// .h includes
#include "Queue.h"
#include "DynamicArray.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

//Functions
Queue<float> readFile();

//classes
class Simulation
{
public:
	class Customer
	{
	public:
		char idTag = '!';
		int arrivalTime = 1;
		int endTime = 1;
	};
	int numOfServers;
	float arrivalRate;
	int maxQueueLength;
	int minServiceTime;
	int maxServiceTime;
	int arrivalStop;

	Queue<Customer> waitQueue;
	DynamicArray<Customer> nowServing; //set.idTag to '!' or ascii 33
	//DynamicArray<bool> isNowServing; // true = servingSomeone false = idle

	Simulation();
	Simulation(Queue<float>&);
	void dispConf();
	void finishService(int);
	int getRandomNumberOfArrivals(double);
	void updateQueue(int);
	void startService(int);
	void drawSim(int);
	bool shouldEnd(int);
	
};


int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl << std::endl;
	
	srand(time(0)); rand();

	Queue<float> bbq = readFile();
	Simulation sim(bbq);

	sim.dispConf();
	
	bool flag = false;
	for (int time = 0; ; time++)
	{

		sim.finishService(time);
		sim.updateQueue(time);
		sim.startService(time);
		sim.drawSim(time);
		if (flag == true)
			break;
		if(sim.shouldEnd(time))
			flag = true;
	}
	
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

	while(myfile.good())
	{
		std::string line;
		std::getline(myfile, line);
		

		bbQueue.push(atof(line.c_str()));
	}
	myfile.close();
	return bbQueue;
}

Simulation::Simulation()
{
	//default values;

	numOfServers = 1;
	arrivalRate = 1;
	maxQueueLength = 1;
	minServiceTime = 1;
	maxServiceTime = 2;
	arrivalStop = 1;

}

Simulation::Simulation(Queue<float> &bbq)
{

	//set values
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
}

void Simulation::dispConf()
{
	const int SPACE1 = 23;
	std::cout << std::setw(SPACE1) << std::left << "Number of Servers: " << numOfServers << std::endl
		<< std::setw(SPACE1) << std::left << "Customer Arrival Rate: " << arrivalRate << " per minute, for " << arrivalStop << " minutes" << std::endl
		<< std::setw(SPACE1) << std::left << "Maximum Queue length: " << maxQueueLength << std::endl
		<< std::setw(SPACE1) << std::left << "Minimum Service Time: " << minServiceTime << " minutes" << std::endl
		<< std::setw(SPACE1) << std::left << "Maximum Service Time: " << maxServiceTime << " minutes" << std::endl;
}

void Simulation::finishService(int time)
{
	int dummy = 0;
	for (int i = 0; i < numOfServers; i++)
	{
		if (nowServing[i].idTag != '!') // "idles" the server if it is the end time.
		{
			if (nowServing[i].endTime == time)
				nowServing[i].idTag = '!';
		}
		else
			dummy++;
	}
}

int Simulation::getRandomNumberOfArrivals(double averageArrivalRate)
{
	int arrivals = 0;
	double probOfnArrivals = exp(-averageArrivalRate);
	for (double randomValue = (double)rand() / RAND_MAX;
		(randomValue -= probOfnArrivals) > 0.0;
		probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
	return arrivals;
}

void Simulation::updateQueue(int time)
{
	if (time < arrivalStop)
	{
		static bool isFirst = true;
		static char dummy;
		int arrivals = getRandomNumberOfArrivals(arrivalRate);
		while (arrivals > 0)
		{
			if (waitQueue.size() < maxQueueLength)
			{
				Customer c;
				if (waitQueue.empty() == true && isFirst == true) // 0 check
				{
					dummy = 'A';
					isFirst = false;
				}
				else if (dummy == 'Z')// z check
					dummy = 'A';
				else
					dummy = char(1 + int(dummy));
				c.idTag = dummy;
				c.arrivalTime = time;
				waitQueue.push(c);
				
			}
			arrivals--;
		}
	}
}

void Simulation::startService(int time)
{
	
	for (int i = 0; i < numOfServers; i++)
		if (nowServing[i].idTag == '!' && !waitQueue.empty()) // checks if idle ('!')
		{
			nowServing[i] = waitQueue.front(); // copy

			waitQueue.pop(); //reomvoce from waitQ
			nowServing[i].endTime = (time + (rand() % (maxServiceTime - minServiceTime) + 3)); //set service end time
			
		}
		
}

void Simulation::drawSim(int time)
{
	const int SCALE1 = 6;
	const int SCALE2 = 11;
	const int SCALE3 = 10;

	Queue<Customer> newQ = waitQueue;

	std::cout << std::endl << "Time: " << time << std::endl
		<< " _____________________________" << std::endl
		<< "|Server|Now Serving|Wait Queue|" << std::endl
		<< "|------|-----------|----------|" << std::endl;
	for (int i = 0; i < numOfServers; i++)
	{
		if (i == 0)
		{ 
			std::cout << std::right << '|' << std::setw(SCALE1) << i << '|' << std::setw(SCALE2);
			if(nowServing[i].idTag != '!')
				std::cout << nowServing[i].idTag;
			else
				std::cout << ' ';
			
			std::string s;
			if (!newQ.empty())//might not need this
			{
				while (!newQ.empty())
				{
					s.push_back(newQ.front().idTag);
					newQ.pop();
				}
			}
			
			std::cout << '|' << std::setw(SCALE3) << s;
			std::cout << '|' << std::endl;
		}
		else
		{
			std::cout << std::right << '|' << std::setw(SCALE1) << i << '|' << std::setw(SCALE2);
			if (nowServing[i].idTag != '!')
				std::cout << nowServing[i].idTag;
			else
				std::cout << ' ';
			std::cout << '|' << std::setw(SCALE3+1) << '|' << std::endl;
		}
	}
	std::cout << "|______|___________|__________|" << std::endl
		<< "Press ENTER to continue..." << std::endl;
	std::getchar();
}

bool Simulation::shouldEnd(int time)
{
	//to be empty
		// waitQ must be emtpy
		// nowServing must be empty
		// time must be greater= arrival stop
	int dummy = 0;
	bool isServerEmpty = false;

	for (int i = 0; i < numOfServers; i++)
		if(nowServing[i].idTag == '!')
			dummy++;
	
	if (dummy == numOfServers - 1)
		isServerEmpty = true;
	else
		isServerEmpty = false;

	if(arrivalStop < time && (isServerEmpty && waitQueue.empty()))
		return true;
	else 
		return false;
}