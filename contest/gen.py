import numpy as np
import matplotlib.pyplot as plt
import sys

num_vertices = int(sys.stdin.readline().strip())

# Initialize an empty array to store vertices
vertices = []

# Read vertex coordinates from input and store them in the vertices array
for _ in range(num_vertices):
    line = sys.stdin.readline().strip().split()
    x, y = map(float, line)
    vertices.append([x, y])


vertices.append(vertices[0])
# Plot the polygon
x_coords = [vertex[0] for vertex in vertices]
y_coords = [vertex[1] for vertex in vertices]

# Plot the polygon
plt.plot(x_coords, y_coords, '.-')
plt.axis('equal')
plt.show()


