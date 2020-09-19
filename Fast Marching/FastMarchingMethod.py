
def InitFM(startPoint, map):
    # Initialize FM propagation with T = 0
    map[startPoint[0],startPoint[1]] = 0    
    return map

def Eikonal(startPoint, currentCell, cellMap):

    ## Calculate arrival time from the propagation point
    time = 0

    # Calculate dx and dy 
    dx = currentCell.x - startPoint[0]
    dy = currentCell.y - startPoint[1]

    # Get Tx and Ty

    # If dx or dy are negatives then select the cell on the right (-1) of the map
    # else select the cell on the left (+1)
    if(dx < 0):
        xCell = cellMap[currentCell.x - 1][currentCell.y]
    else:
        xCell = cellMap[currentCell.x + 1][currentCell.y]
    
    if(dy < 0):
        yCell = cellMap[currentCell.x][currentCell.y - 1]
    else:
        yCell = cellMap[currentCell.x][currentCell.y + 1]
    

    if( not yCell and not xCell):
        return False

    # If the cell is occupied the corresponding time is set to 0
    if(yCell == False):
        # dx/F = dx ; F=1
        return (xCell.cost + dx)
    else:
        Ty = yCell.cost

    if(xCell == False):
        # dx/F = dx ; F=1
        Tx = (yCell.cost + dy)
    else:
        Tx = xCell.cost

    # Calculate

    return time
