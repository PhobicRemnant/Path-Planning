#include <iostream>
#include "GridNode.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Display.h"

using namespace std;

int main(int argc, char ** argv)
{
    // TO DO:

    // 1.- Create a Menu to display map
    sf::RenderWindow window(sf::VideoMode(800,600), "Path Planner 2D");

    //
    Grid* map = new Grid;

    // Main GUI thread 
    while(window.isOpen())
    {

        // Check all of the events
        sf::Event event;

        // clear window with black color
        window.clear(sf::Color::Black);
        
        while (window.pollEvent(event))
        {
            window.close();
        }
        
        // Draw the map
        MapDisplay(window,map);

        
        // Display
        window.display();
        
    }

    /*
    GridNode node1;
    node1.Position(0,0);
    node1.nodeID = 0;
    nPool.push_back(node1);

    GridNode node2;
    node2.Position(0,1);
    node2.nodeID = 1;
    nPoolls.push_back(node2);
    node1.nNeighbours.push_back(&node2.nodeID);

    GridNode node3;
    node3.Position(1,0);
    node3.nodeID = 2;
    nPool.push_back(node3);
    node1.nNeighbours.push_back(&node3.nodeID);

    GridNode node4;
    node4.Position(1,1);
    node4.nodeID = 3;
    nPool.push_back(node4);
    node4.nNeighbours.push_back(&node2.nodeID);

    cout << *(node1.nNeighbours[0]) << endl;
    cout << *(node1.nNeighbours[1]) << endl;
    cout << *(node4.nNeighbours[0]) << endl;
    */

    return 0x00;
}