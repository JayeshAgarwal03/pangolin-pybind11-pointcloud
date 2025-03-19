#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  // Required for std::vector conversion
#include <pybind11/numpy.h> // For NumPy arrays
#include "point_cloud_visualizer.h"

namespace py = pybind11;

PYBIND11_MODULE(slam_visualizer, m) {
    py::class_<PointCloudVisualizer>(m, "PointCloudVisualizer")
        .def(py::init<const std::string&>())
        .def("updatePointCloud", &PointCloudVisualizer::updatePointCloud)
        .def("render", &PointCloudVisualizer::render)
        .def("shouldClose", &PointCloudVisualizer::shouldClose);
}
