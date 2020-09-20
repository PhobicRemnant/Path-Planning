
#%%
import numpy as np 
import gridmap as gm  
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from fastmarchingmethod import *

def rgb2gray(rgb):
    # Convert 
    return np.dot(rgb[...,:3], [0.2989, 0.5870, 0.1140])

# Read image 
imName = "ImageTest.png"
OriginalMap = mpimg.imread(imName)
map = rgb2gray(OriginalMap)


# Create GridMap and set the grid

gmap = gm.GridMap(map)
gmap.processMap()


# Prepare cell grid
startPoint =np.divide(map.shape[0:2],2)

print(gmap.grid[0,0].GetLocation() )
print(gmap.grid[350,300].GetLocation())

print()
print()

# InitFM in starting point
# There will be three sets of cells

# Frozen
frozen = []
# Narrow band
nBand = []
# Unknown
unknown = []

# InitFMLoop
#cell = Cell(startPoint)
# FM loop


# Show resulting img
#plt.imshow(map)

# %%
