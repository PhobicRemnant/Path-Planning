#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "GridNode.h"

void MapDisplay(sf::RenderWindow& window, vector<string> map)
{

	// Get pixel number for cell for height and width
	sf::Vector2u size = window.getSize();
	unsigned int nh = size.y / map.size();
	unsigned int nw = size.x / map[0].size();

	// Declare Rectangle template for storing in cells vector
	sf::RectangleShape rect(sf::Vector2f(nw, nh));
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(5);

	// clear the window with black color
	window.clear(sf::Color::Black);

	// Change square colors
	for (int i = 0; i < map.size() - 1; i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			// Set origin and state(color) of the rectangle
			rect.setPosition(sf::Vector2f(j * nw, i * nh));
			rect.setSize(sf::Vector2f(nw, nh));

			if (map[i][j] == '0')
			{
				rect.setFillColor(sf::Color::White);
			}
			else if (map[i][j] == '1')
			{
				//Gray
				rect.setFillColor(sf::Color(192, 192, 192));
			}
			else if (map[i][j] == '2')
			{
				//Orange
				rect.setFillColor(sf::Color(255, 165, 0));
			}
			else if (map[i][j] == 'E')
			{
				//Blue
				rect.setFillColor(sf::Color(212, 175, 55));
			}
			else if (map[i][j] == 'S')
			{

				rect.setFillColor(sf::Color(0, 0, 128));
			}
			else if (map[i][j] == 'P')
			{

				rect.setFillColor(sf::Color::Green);
			}



			// Add rect to the vector
			//cells.push_back(rect);
			// Draw shape
			window.draw(rect);
			//

		}
	}
	window.display();


	/*
	// Draw the cells
	for (auto& cell : cells)
	{
		window.draw(cell);
	}*/
	
	// end the current frame
	

}
