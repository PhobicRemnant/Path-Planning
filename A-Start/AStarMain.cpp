/* PathPlanning.cpp : This file contains the 'main' function. Program execution begins and ends there.

	Here is an implementation of A-Star Path Planning algorithm using an STL priotity queue.


*/


#include "Display.h"
#include "Initializer.h"
#include <queue> 
#include <fstream>
#include <string>
#include "Windows.h"



// Macro to remember the output parameters on a function
#define OUT
// Macro to define Infity
#define INFINITY std::numeric_limits<double>::infinity()


// Start position
const int START_Y = 2;
const int START_X = 2;

// End position
const int END_Y = 7;
const int END_X = 2;


const int startP[2] = {START_X, START_Y};
const int endP[2] = { END_X, END_Y };

using namespace std;


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
	// Create end and start node
	
	GridNode startNode;
	GridNode endNode;

	// Create the display window object	
	sf::RenderWindow AWindow(sf::VideoMode(800, 600), "Path Planning Display");

	//Test MapDisplay
	// MapDisplay(AWindow, main_map);

	// Initialize nodes accorind to start and end
	initStartEndNodes(startNode, endNode, startP, endP);

	// Insert startNode into nPool
	nPool.push_back(startNode);

	// Insert startNode into the nQueue
	nQueue.push(startNode);

	startNode.lookForNeighbours(OUT main_map,endNode, OUT nPool);
	
	
	GridNode searchNode = startNode;

	// SEARCH LOOP
	while(true)
	{
		// A-star path finding algorithm loop
		// Exit loop when the w_node position is the same and the endNode

		// Search for posible nodes
		searchNode.lookForNeighbours(OUT main_map, endNode, OUT nPool);

		cout << searchNode.nodeID << endl;
		cout << searchNode.parent << endl;

		// Break loop when solution is found
		if ((searchNode.pos_y == endNode.pos_y) && (searchNode.pos_x == endNode.pos_x))
		{
			cout << "Goal reached." << endl;
			break;
		}

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




		//If the priority queue is empty
		if (nQueue.empty())
		{
			// Break loop if it is
			cout << "No more feasible routes." << endl;
			break;
		}

		// Take the lowest tcost node
		searchNode = nQueue.top();
		nQueue.pop();
		Sleep(500);

		// Display 
		MapDisplay( AWindow, main_map);
		

	}// Search loop bracket
	

	// OBTAIN SOLUTION VECTOR 
	int n = searchNode.nodeID;
	cout << "SN node ID:"<<searchNode.nodeID << endl;
	cout << "SN parent ID:"<<searchNode.parent << endl;
	// Solution Pool 
	vector<GridNode> solution;
	
	while (true) 
	{
		// Add node to solution vector
		solution.push_back( nPool[n] );

		cout << nPool[n].parent << endl;

		// Change map to show the path solution
		main_map[nPool[n].pos_y][nPool[n].pos_x] = 'P';

		// Set n to look for parent of the next
		n = nPool[n].parent;



		//If the node is the source then break loop
		if (nPool[n].nodeID == 0)
		{
			break;
		}

	}


	// Display 
	print_map_terminal(main_map);
	MapDisplay(AWindow, main_map);

	system("PAUSE");
	
	// End program
	return 0x00;
}

// Debbuging stuff
	// searchNode.ShowNodeInfo();
	// cout << "Lowest total cost in queue: "<< nQueue.top().tcost << endl;
