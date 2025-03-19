#pragma once
#include <vector>
#include <string>
#include <pangolin/pangolin.h>

class PointCloudVisualizer {
public:
    PointCloudVisualizer(const std::string& window_name = "Point Cloud Visualization");
    ~PointCloudVisualizer();
    void updatePointCloud(const std::vector<float>& points, const std::vector<float>& colors = std::vector<float>());
    void render();
    bool shouldClose();
private:
    pangolin::OpenGlRenderState camera_state_;
    pangolin::View* display_;
    std::vector<float> points_;
    std::vector<float> colors_;
    bool has_colors_;
};
