/* PathPlanning.cpp : This file contains the 'main' function. Program execution begins and ends there.

	Here is an implementation of A-Star Path Planning algorithm using an STL priotity queue.


*/

#include <iostream>
#include <math.h>
#include <queue> 
#include <list>
#include <fstream>
#include <string>
#include "GridNode.h"
#include "Windows.h"

#define OUT
#define INFINITY std::numeric_limits<double>::infinity()

const int START_Y = 2;
const int START_X = 2;


const int END_Y = 7;
const int END_X = 2;


using namespace std;

// For Debbuging
void NodeInfo(GridNode n)
{
	cout << endl;
	cout << "NodeID:" << n.nodeID << endl;
	cout << "X:" << n.pos_x << endl;
	cout << "Y:" << n.pos_y << endl;
	cout << "Heuristic:" << n.heu << endl;
	cout << "Cost:" << n.cost << endl;
	cout << "Total Cost:" << n.tcost << endl;
	cout << endl;
}


bool operator< (const GridNode& a, const GridNode& b) {
	return ((a.tcost) > (b.tcost));
}

// Priority queue for ordering the lowest tcost
priority_queue<GridNode, vector<GridNode>, less<vector<GridNode>::value_type>  > nQueue;
// Pool containing all the found feasible nodes
vector<GridNode> nPool;

vector<string> load_map(string a) {
	 
	 vector<string> map;
	 string str, temp;
	 ifstream data;
	 int size, d;

	 data.open(a);

	 if (!data.is_open()) {
		 cout << "File not found or broken." << endl;
		 return map;
	 }

	 while( !data.eof() ) {

		 getline(data, temp);

		 for(int i = 0; i < temp.size() ;i++){
		
			 if(temp[i] != ','){
				 
				 str.push_back(temp[i]); 
			 
			 }
		 
		 }

		 map.push_back(str);
		 str = "";

	 }


	 return map;

}

 void print_map_terminal(vector<string> map) {

	 if(!map.empty()){
	 cout << "Map: "<< endl;
	 cout << endl;

	 for (int i = 0; i < map.size(); i++) {
		 cout << map[i] << endl;
	 }

	 }else {
		 cout << "Map emtpy, check CSV file." << endl;
	 }
 }


	
int main() {

	// -----------------------------------------------
	// Initialize map
	// -----------------------------------------------
	
	// Load the map from the CSV file
	vector<string> main_map = load_map("map1.csv");
	if (main_map.empty()) {
		cout << "Map empty, check CSV file." << endl;
		// If the map is empty terminate program
		return 0x10;
	}

	// Put 'S' in the starting position on the loaded map strings
	main_map[START_Y][START_X] = 'S';
	// Put 'E' in the starting position on the loaded map strings
	main_map[END_Y][END_X] = 'E';
	

	// -----------------------------------------------
	// Initialize start and end
	// -----------------------------------------------
	// Create end node as a referece for all the heus
	GridNode endNode;
	// Update position for the end node
	endNode.Position(END_Y, END_X);
	// Create start node
	GridNode startNode;
	// Update position
	startNode.Position(START_Y, START_X);
	// Set the cost to the maximum a double can have
	startNode.heu = INFINITY;
	startNode.ComputeTotalCost(endNode);
	// Set parent as nullptr for reference
	startNode.parent = 0;

	// Insert startNode into nPool
	nPool.push_back(startNode);

	// Insert startNode into the nQueue
	nQueue.push(startNode);

	startNode.lookForNeighbours(OUT main_map,endNode, OUT nPool);
	
	cout << "The number of neighboors is:" << startNode.nNeighbours.size() << endl;
	cout << "The number of nodes is:" << nPool.size() << endl;
	cout << "Starting distance:" << startNode.Euclid(endNode) << endl;

	// SEARCH LOOP
	GridNode searchNode = startNode;

	//cout << "State:" << ( (searchNode.pos_y == END_Y) && (searchNode.pos_x == END_X) ) << endl;
	
	// Exit loop when the w_node position is the same and the endNode
	while(true)
	{

		if( (searchNode.pos_y == END_Y) && (searchNode.pos_x == END_X) )
		{	
			cout << "Goal reached." << endl;
			break;	
		}

		// Clean console
		// system("CLS");
		// Show the current map status
		print_map_terminal(main_map);
		cout << "PQ size:" << nQueue.size() << endl,
		cout << "nPool size:" << nPool.size() << endl,
			// Search for posible nodes
		searchNode.lookForNeighbours(OUT main_map, endNode, OUT nPool);

		// If there are neighbours
		if ( !(searchNode.nNeighbours.empty()) )
		{
			// Iterate through the node's Neighbours
			for (int node : searchNode.nNeighbours)
			{
				// Compute total cost with parent's as a reference, this will always be the search node
				nPool[node].ComputeTotalCost(searchNode);
				// Add the nodes to the priority queue
				nQueue.push(nPool[node]);
			}	
		}
		//If the priority queue is not empty
		if (!nQueue.empty())
		{
			// Take the lowest tcost node
			searchNode = nQueue.top();
			nQueue.pop();
			searchNode.ShowNodeInfo();
			Sleep(2000);
		}
		else
		{
			// Break loop if it is
			cout << "No more feasible routes." << endl;
			break;
		}

	}// Search loop bracket
	
	// Display searchNode, should be end node
	searchNode.ShowNodeInfo();
	
	// End program
	return 0x00;
}

// Debbuging stuff
	// searchNode.ShowNodeInfo();
	// cout << "Lowest total cost in queue: "<< nQueue.top().tcost << endl;
