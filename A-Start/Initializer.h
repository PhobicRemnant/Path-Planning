#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "GridNode.h"

void initStartEndNodes( GridNode& startNode, GridNode& endNode, const int start[], const int end[])
{
	// Update position for the end node
	endNode.Position(end[1], end[0]);
	endNode.heuristic(endNode);
	endNode.ShowNodeInfo();
	
	// Update position
	startNode.Position(start[1], start[0]);
	// Set the cost to the maximum a double can have
	startNode.heu = INFINITY;
	startNode.ComputeTotalCost(endNode);
	// Set parent as nullptr for reference
	startNode.parent = 0;
}
