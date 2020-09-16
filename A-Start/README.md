# A-Star search

The A* or A-Star is a search algorithm, developed in 1968 by the Shaky Project (the first general-purpose mobile robot) to solve the path planning problem of the shortest path. This implemenation is more of an exercise in implementing the available priority queues in the C++ STL, reading the map from a CSV file.

### The map

The map is a raster data type where there are only static occupations, represented by a '1' and an empty cell as a '0'.

Ex.:

<center>
|  1 | 1  | 1  | 1  | 1  | 1  | 1  | 1  | 1  | 1  |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 1  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  |
| 1  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  |
| 1  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  |
| 1  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  |
| 1  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 1  |
|  1 | 1  | 1  | 1  | 1  | 1  | 1  | 1  | 1  | 1  |
</center>

### Status - 09/17/2020

  - The starting position and goal are edited with each complilation, it would e
  - The map display is implemented using SFML library. 
  - A* finds the shortest path to goal.

 ### Goals 
 
  - Considerable time overhead during planning, need to optimize running time. Evaluate SFML display implementation.
  - Is it possible to implement a menu? Maybe SFML has a way.

This A-Star path planning implementation uses priority queues and a Euclidian distance heuristic to find the goal of one robot from it's current position.
