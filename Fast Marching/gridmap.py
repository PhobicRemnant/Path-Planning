import numpy as np

class Cell: 
    """
    This class defines a cell, it's coordinates on a plane/space and the general 
    of the algorithm for it's processing

    VARIABLES:
        - X, Y, Z   -> Spatial coordinates
        - Cost      -> Arrival time for FMM
        - Empty     -> Wheater the cell is an occupation or not
    """

    # Varibles defining the location of the cells
    def __init__(self, x, y, z, cost,empty=True):
        super().__init__()
        self.x = x
        self.y = y
        self.z = z
        self.cost = cost
        self.empty = empty

    def GetLocation(self):
        return (self.x, self.y, self.z)

    def GetNeighbors(self, cellList):

        # Explore surrounding cells for occupation 
        # Add them to 
        print("potato")

class GridMap:
    """
    This class reads the map and acts as a main processing entity

    Is a (M x N) matrix of cell objects, created from a map (NumPy array usually).

    """
    def __init__(self,map):
        super().__init__()
        self.map = map
        self.grid = np.array(map.shape, dtype=Cell)

    def processMap(self):

        for i in range(0,self.grid.shape[0]):
            for j in range(0,self.grid.shape[1]):

                self.grid[i,j] = Cell(i,j,0,0, False)
                """
                # If the value is less than the threshold declare occupation
                if(self.map[i][j] < 0.5):
                    self.grid[i][j] = Cell(i,j,0,0, False)
                # Set cell as empty when below threshold
                else:
                    self.grid[i][j] = Cell(i,j,0,0,True)
                """
                


    def GetGridSize(self):
        return ( len(self.grid), len(self.grid[0]) )


    
