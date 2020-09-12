
#%%
import numpy as np 
import Cell
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from FastMarchingMethod import *

def rgb2gray(rgb):
    # Convert 
    return np.dot(rgb[...,:3], [0.2989, 0.5870, 0.1140])



# Read image 
imName = "ImageTest.png"

# Declare a list for holding the cells
cellList = []

img = mpimg.imread(imName)
# Set to gray scale for obstacle detection
map = rgb2gray(img)

# InitFM in starting point
startPoint = ( 300, 300)
map = InitFM(startPoint, map)


# There will be three sets of cells

# Frozen
frozen = []
# Narrow band
nBand = []
# Unknown
unknown = []

# InitFMLoop
cell = Cell(startPoint)
# FM loop


# Show resulting img
plt.imshow(map)

# %%


