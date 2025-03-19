# pangolin-pybind11-pointcloud
# Configure and build
cmake -B build
cmake --build build

# install pybind11
pip install pybind11


# GIVEME THE PYTHON STUFF!!!! (Check the output to verify selected python version)
cmake --build build -t pypangolin_pip_install

