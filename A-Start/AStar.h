#pragma once

#include "Display.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue> 
#include "GridNode.h"

#define OUT

bool AStar(	GridNode searchNode,
			GridNode endNode,
			vector<string> main_map,
			vector<GridNode> nPool,
			priority_queue<GridNode, vector<GridNode>, less<vector<GridNode>::value_type>  > nQueue,
			vector<GridNode>& solution,
			sf::RenderWindow& Window,
			bool bDisplay = 1)
{

	// SEARCH LOOP
	// A-star path finding algorithm loop
	// Exit loop when the w_node position is the same and the endNode
	while (true)
	{


		
		if ((searchNode.pos_y == endNode.pos_y) && (searchNode.pos_x == endNode.pos_x))
		{
			cout << "Goal reached." << endl;
			break;
		}

		// Search for posible nodes
		searchNode.lookForNeighbours(OUT main_map, endNode, OUT nPool);

		// If there are neighbours
		if (!(searchNode.nNeighbours.empty()))
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
			return false;
		}

		// Take the lowest tcost node
		searchNode = nQueue.top();
		nQueue.pop();
		searchNode.ShowNodeInfo();
		
		if(bDisplay)
		{
			MapDisplay(Window, main_map);
		}
	}// Search loop bracket

	// OBTAIN SOLUTION VECTOR 
	int n = searchNode.nodeID;

	while (true)
	{
		// Add node to solution vector
		solution.push_back(nPool[n]);
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

	if (bDisplay)
	{
		MapDisplay(Window, main_map);
	}


}



