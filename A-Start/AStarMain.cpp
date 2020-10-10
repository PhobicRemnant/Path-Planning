/* PathPlanning.cpp : This file contains the 'main' function. Program execution begins and ends there.

	Here is an implementation of A-Star Path Planning algorithm using an STL priotity queue.


*/


#include "Display.h"
#include "Initializer.h"
#include "AStar.h"
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
const int END_Y = 5;
const int END_X = 13;


const int startP[2] = {START_X, START_Y};
const int endP[2] = { END_X, END_Y };

using namespace std;


bool operator< (const GridNode& a, const GridNode& b) {
	return ((a.tcost ) > (b.tcost ));
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
	vector<string> main_map = load_map("map10.csv");
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
	sf::RenderWindow AWindow(sf::VideoMode(600, 800), "Path Planning Display");

	// Initialize nodes accorind to start and end
	initStartEndNodes(startNode, endNode, startP, endP);

	// Insert startNode into nPool
	nPool.push_back(startNode);

	// Insert startNode into the nQueue
	nQueue.push(startNode);

	startNode.lookForNeighbours(OUT main_map,endNode, OUT nPool);
	
	// Solution Pool
	vector<GridNode> solution;

	// If a solution is found
	if( AStar(startNode, endNode, main_map, nPool, nQueue, solution, AWindow) )
	{
		cout << "Solution found, displayed on green." << endl;
	}
	else
	{
		cout << "Solution unavailable, check map." << endl;
	}

	
	system("PAUSE");
	
	// End program
	return 0x00;
}

// Debbuging stuff
	// searchNode.ShowNodeInfo();
	// cout << "Lowest total cost in queue: "<< nQueue.top().tcost << endl;
