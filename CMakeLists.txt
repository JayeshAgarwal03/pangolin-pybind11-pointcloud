cmake_minimum_required(VERSION 3.10)
project(slam_visualizer)

set(CMAKE_CXX_STANDARD 14)

# Find packages
find_package(pybind11 REQUIRED)
find_package(Pangolin REQUIRED)

# Add the binary
pybind11_add_module(slam_visualizer 
    bindings.cpp
    point_cloud_visualizer.cpp
)

# Include directories
target_include_directories(slam_visualizer PRIVATE ${Pangolin_INCLUDE_DIRS})

# Link libraries
target_link_libraries(slam_visualizer PRIVATE ${Pangolin_LIBRARIES})

add_custom_command(TARGET slam_visualizer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:slam_visualizer>
    ${CMAKE_SOURCE_DIR}/$<TARGET_FILE_NAME:slam_visualizer>)
