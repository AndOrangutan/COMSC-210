
//Solution file for COMSC-210
//Module 13 - Graph Searches
// LabExercise 13 Part 1
//BFS_Shortest.cpp (use a queue to build up the to-do list)

//Modified into the cheapest by:
//Programmer: Von Mueller
//Programmer's ID: 1735441

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

struct Node
{
  string name;

  int prev; //new
  double cost; // new
  bool isVisited;
  list<pair<int, double>> neighbors;
};

struct Terminus
{
	int index;
	int prev;
	double cost;

};

bool operator<(const Terminus& a, const Terminus& b)
{
	return b.cost < a.cost;	
}

// BFS return a queue contains the indexes of all reachable nodes
pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Node>& database)
{
  stack<int> result; // return this queue of indices
  queue<int> toDo;   // queue

  // initialization of the database
  for(int i = 0; i < database.size(); i++)
  {
    database[i].prev = -1; //new
    database[i].cost = 0; //new
    database[i].isVisited = false;
  }

  // mark start node
  database[iOriginNode].isVisited = true;
  // push to result
//  result.push(iOriginNode);
  // push to "to do" list
  toDo.push(iOriginNode);

  while(!toDo.empty())
  {
    int i = toDo.front(); //node under consideration
    toDo.pop();
    list<int> neighbors = database[i].neighbors;

    for(list<int>::const_iterator it = neighbors.begin(); it != neighbors.end(); ++it)
    {
      if(!database[*it].isVisited)
      {
        database[*it].prev = i; //new
        database[*it].cost = 1 +  database[i].cost; //new
        database[*it].isVisited = true;
    //    result.push(*it);
        toDo.push(*it);
      }
      if (*it == iEndNode)
      { //empty the queue
        while (!toDo.empty())
          toDo.pop();
        break;
      }
    }
  }
  
 // result.push(iEndNode);
  int index = iEndNode;
  while (index != -1){
    result.push(index);
    index = database[index].prev;
  }
  return result;
}

int main()
{
	std::cout << "Programmer: Von Mueller" << std::endl
		<< "Programmer's ID: 1735441" << std::endl
		<< "File: " << __FILE__ << std::endl << std::endl;

  ifstream fin;
  fin.open("cities.txt");
  if(!fin.good()) throw "I/O error";

  // process the input file to build up the database****
  vector<Node> database;
  while(fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
	 getline(fin, cost);
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator

    // add vertices for new cities included in the edge
    int iToNode = -1, iFromNode = -1, i;
    for(i = 0; i < database.size(); i++) // seek "to" city
      if(database[i].name == fromCity)
        break;
    if(i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = {fromCity};
      database.push_back(fromNode);
    }
    iFromNode = i;

    for(i = 0; i < database.size(); i++) // seek "from" city
      if(database[i].name == toCity)
        break;
    if(i == database.size()) // not in vector yet
    {
      // store the node if it is new
      Node toNode = {toCity};
      database.push_back(toNode);
    }
    iToNode = i;

    // store bi-directional edges
	 pair<int, double> edge;
	 edge.first = iToNode;
	 edge.second = atof(cost.c_str());
    database[iFromNode].neighbors.push_back(iToNode);
	 edge.first = iFromNode;
    database[iToNode].neighbors.push_back(iFromNode);
  }
  fin.close();
  cout << "Input file processed\n\n";
  // End of process the input file to build up the database****
    
  while(true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if(startCity.length() == 0) break;

    // find the start city
    int i;
    for(i = 0; i < database.size(); i++)
      if(database[i].name == startCity)
        break;
        
// get the end city for the shortest route
    string endCity;
    cout << "\nEnter the end city [blank to exit]: ";
    getline(cin, endCity);
    if(endCity.length() == 0) break;

    // find the end city
    int j;
    for(j = 0; j < database.size(); j++)
      if(database[j].name == endCity)
        break;
        
    //
	 double cost
  }
}
