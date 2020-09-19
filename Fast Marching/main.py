
#%%
import numpy as np 
import gridmap as gm
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from fastmarchingmethod import *

def rgb2gray(rgb):
    # Convert 
    return np.dot(rgb[...,:3], [0.2989, 0.5870, 0.1140])

def processMap(map):
    
    gmap = []
    size = map.shape[0:2]

    # Create a None type list of MxN map size
    gmap = [[None]*size[1]]*size[0]
            
    for i in range(0,len(gmap)):
        for j in range(0,len(gmap[i])):
            gmap[i][j] = gm.Cell(j,i,0,0)            
    return gmap

# Read image 
imName = "ImageTest.png"
map = mpimg.imread(imName)

# Create GridMap
gmap = gm.GridMap(map)

# Prepare cell grid
startPoint =np.divide(map.shape[0:2],2)


# InitFM in starting point

#map = InitFM(startPoint, map)


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
plt.imshow(map)

# %%



# %%
