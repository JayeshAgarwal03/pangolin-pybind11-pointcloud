#!/usr/bin/env python3

import os
import sys

# Add the current directory to Python's path
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

# Import the module
import slam_visualizer
import numpy as np
import time

# Generate random points and colors
num_points = 1000
points = np.random.uniform(-2, 2, (num_points, 3)).astype(np.float32)
colors = np.random.uniform(0, 1, (num_points, 3)).astype(np.float32)

# Initialize visualizer with a window name (string argument)
visualizer = slam_visualizer.PointCloudVisualizer("Point Cloud Demo")

# Update point cloud
visualizer.updatePointCloud(points.flatten().tolist(), colors.flatten().tolist())

# Render loop
while not visualizer.shouldClose():
    visualizer.render()
    time.sleep(0.01)
