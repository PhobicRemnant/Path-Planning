### Fast Marching Methods

The level set methods proposed by Sethian in his papers are used un path planning nowadays in robotics, Fast Marching acts as a wave propagation using the Eikonal Equation to calculate distance form the propagation point. The workspace around the robot is discretized, divided into multiple cells with a constant size *h*. The algorithm defines 3 different subsets that compromise the whole workspace of the robot, freeze, unknown and narrow band.

  - Unknown: Cells with arrival time is unknown, therefore waiting to be processed in the future.

  - Narrow band: Comprises the frontier between the cells with calculated arrival time and the unknown ones, acts as the wave front of the propagation.
  
  - Freeze: The set with all the processed cells, arrival time has been calculated and will be used for narrow band cells time calculation.
  

  
This section tries to implement from scrat the Fast Marching Method.


#State - 09/16/2020

  - Currently the development is ongoing in Python to try some proof concepts.

#Goals 

  - Implement a Fast Marching Method propagation.
  - Shortest Path extraction from the FMM processing.
  - Create the solution in Julia programming language.

References: (This is the real work done by other people)

1.- J. A. Sethian, Fast marching methods, SIAM review, vol. 41, no. 2,
pp. 199235, 1999.

2.- J. V. Gomez, D. Alvarez, S. Garrido, and L. Moreno, Fast methods for eikonal equations: an experimental survey, arXiv preprint
arXiv:1506.03771, 2015.

