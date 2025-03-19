#include "point_cloud_visualizer.h"

PointCloudVisualizer::PointCloudVisualizer(const std::string& window_name) {
    pangolin::CreateWindowAndBind(window_name, 1024, 768);
    glEnable(GL_DEPTH_TEST);
    
    // Define camera parameters
    camera_state_ = pangolin::OpenGlRenderState(
        pangolin::ProjectionMatrix(1024, 768, 420, 420, 512, 384, 0.1, 1000),
        pangolin::ModelViewLookAt(0, -10, -10, 0, 0, 0, pangolin::AxisY)
    );
    
    // Create interactive view
    display_ = &pangolin::CreateDisplay()
                    .SetBounds(0.0, 1.0, 0.0, 1.0, -1024.0f/768.0f)
                    .SetHandler(new pangolin::Handler3D(camera_state_));
    
    has_colors_ = false;
}

PointCloudVisualizer::~PointCloudVisualizer() {
    pangolin::FinishFrame();
    pangolin::DestroyWindow("Point Cloud Visualization");
}

void PointCloudVisualizer::updatePointCloud(const std::vector<float>& points, const std::vector<float>& colors) {
    points_ = points;
    if (!colors.empty()) {
        colors_ = colors;
        has_colors_ = true;
    } else {
        has_colors_ = false;
    }
}

void PointCloudVisualizer::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    display_->Activate(camera_state_);
    
    glPointSize(2);
    glBegin(GL_POINTS);
    
    for (size_t i = 0; i < points_.size() / 3; ++i) {
        if (has_colors_ && i * 3 + 2 < colors_.size()) {
            glColor3f(colors_[i * 3], colors_[i * 3 + 1], colors_[i * 3 + 2]);
        } else {
            glColor3f(1.0f, 1.0f, 1.0f);
        }
        glVertex3f(points_[i * 3], points_[i * 3 + 1], points_[i * 3 + 2]);
    }
    
    glEnd();
    pangolin::FinishFrame();
}

bool PointCloudVisualizer::shouldClose() {
    return pangolin::ShouldQuit();
}
