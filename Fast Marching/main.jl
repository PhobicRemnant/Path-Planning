# Fast Marching Method

using Images 
using Colors

map = load("ImageTest.png")

# 
println(typeof(map))


grid_map = Gray.(map)
println(map[1,2])