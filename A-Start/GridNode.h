#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GridNode {
	// Node Object for CSV map path finding
public:

	int nodeID = 0;
	int pos_x = 0;
	int pos_y = 0;
	double cost = 0;			// g(x) -> Shortest path for the node
	double heu = 0;				// h(x) -> Euclidian/Mahattan distance of the node with the destination
	double tcost = 0;			// f(x) -> Total cost

	// Unused variables yet
	bool visited = false;
	bool obstacle = false;

	vector<int> nNeighbours; // 
	int parent;


	// Set node position
	void Position(int y, int x) {
		pos_x = x;
		pos_y = y;
	}

	void heuristic(GridNode n, int sel = 0) {

		if (sel == 0)
		{
			// Euclid's distance heuristic
			heu = Euclid(n);

		}
		else if (sel == 1)
		{
			// Manhattan's distance heuristic
			heu = Manhattan(n);
		}
	}

	double Manhattan(GridNode n) {
		// Manhattan's distance heu
		return (double)abs(pos_x - n.pos_x) + abs(pos_y - n.pos_y);
	}

	double Euclid(GridNode n)
	{
		return sqrt(pow(pos_x - n.pos_x, 2) + pow(pos_y - n.pos_y, 2));
	}

	void lookForNeighbours(vector<string>& map, GridNode EndNode, vector<GridNode>& nPool) {

		/*
		This function finds neighbours withing the CSV read map from the current location,
		updates the occupancy in the map variable and adds the existing nodes to nPool.
		*/

		GridNode n;
		// int adder = 1;
		// Directions for node search:

		// UP = X-1 || Y
		if (map[pos_y][pos_x - 1] == '0' || map[pos_y][pos_x - 1] == 'E' ) {
			// Assing nodeID to search in nPool
			n.nodeID = nPool.size();
			// Set parent ID
			n.parent = nodeID;
			// Declare it as a neighbour
			nNeighbours.push_back(n.nodeID);
			// increase adder for correcting future nodeIDs
			//adder++;
			// Build node properties, add to the nPool and set the nNeighbours 
			n.Position(pos_y, pos_x - 1);
			n.heuristic(EndNode);
			nPool.push_back(n);

			// Change the char value from 0 to 2
			map[pos_y][pos_x - 1] = '2';

		}
		// LEFT = X || Y-1
		if (map[pos_y - 1][pos_x] == '0' || map[pos_y - 1][pos_x] == 'E') {

			n.nodeID = nPool.size();
			n.parent = nodeID;
			nNeighbours.push_back(n.nodeID);
			//adder++;

			n.Position(pos_y - 1, pos_x);
			n.heuristic(EndNode);
			nPool.push_back(n);

			map[pos_y - 1][pos_x] = '2';

		}
		// DOWN = X+1 || Y
		if (map[pos_y][pos_x + 1] == '0' || map[pos_y][pos_x + 1] == 'E') {

			n.nodeID = nPool.size();
			n.parent = nodeID;
			nNeighbours.push_back(n.nodeID);
			//adder++;

			n.Position(pos_y, pos_x + 1);
			n.heuristic(EndNode);
			nPool.push_back(n);

			map[pos_y][pos_x + 1] = '2';
		}
		// RIGHT = X || Y+1
		if (map[pos_y + 1][pos_x] == '0' || map[pos_y + 1][pos_x] == 'E') {

			n.nodeID = nPool.size();
			n.parent = nodeID;
			nNeighbours.push_back(n.nodeID);

			n.Position(pos_y + 1, pos_x);
			n.heuristic(EndNode);
			nPool.push_back(n);

			map[pos_y + 1][pos_x] = '2';
		}


	}

	void ComputeTotalCost(GridNode n)
	{
		cost = Euclid(n);
		tcost = heu + cost;
	}

	// For Debbuging
	void ShowNodeInfo()
	{
		cout << endl;
		cout << "NodeID:" << nodeID << endl;
		cout << "Y:" << pos_y << endl;
		cout << "X:" << pos_x << endl;
		cout << "Heuristic:" << heu << endl;
		cout << "Cost:" << cost << endl;
		cout << "Total Cost:" << tcost << endl;
		cout << endl;
	}

};