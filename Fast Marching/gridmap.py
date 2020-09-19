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
    def __init__(self, x, y, z, cost):
        super().__init__()
        self.x = x
        self.y = y
        self.z = z
        self.cost = cost
        self.empty = True


    def getNeighbors(self, cellList):

        # Explore surrounding cells for occupation 
        # Add them to 

        return None

class GridMap:
    """
    This class reads the map and acts as a main processing entity

    Is a (M x N) matrix of cell objects, created from a map (NumPy array usually).

    """
    def __init__(self,map):
        super().__init__()
        self.map = map
        self.grid = []

    def processMap(self):
        size = self.map.shape[0:2]

        # Create a None type list of MxN map size
        grid = [[None]*size[1]]*size[0]
                
        for i in range(0,len(grid)):
            for j in range(0,len(grid[i])):
                grid[i][j] = Cell(j,i,0,0)       

    def GetGridSize(self):
        return ( len(self.grid), len(self.grid[0]) )
