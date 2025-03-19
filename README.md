# pangolin-pybind11-pointcloud
# Results
![Point Cloud](./Screenshot_from_2025-03-20_01-40-02.png)


# Configure and build
cmake -B build
cmake --build build

# install pybind11
pip install pybind11


# GIVEME THE PYTHON STUFF!!!! (Check the output to verify selected python version)
cmake --build build -t pypangolin_pip_install

