#pragma once

#include <string>
#include <vector>

#include <opencv2/core.hpp>

typedef struct apriltag_detector apriltag_detector_t;
class Parameters;

class AprilTagWrapper
{
public:
    explicit AprilTagWrapper(const Parameters* parameters);

    ~AprilTagWrapper();

    void convertToSingleChannel(const cv::Mat& src, cv::Mat& dst);

    void detectMarkers(
        const cv::Mat& frame,
        std::vector<std::vector<cv::Point2f> >* corners,
        std::vector<int>* ids,
        std::vector<cv::Point2f>* centers);

    std::vector<std::string> getTimeProfile();
    void drawTimeProfile(cv::Mat& image, const cv::Point& textOrigin);

private:
    apriltag_detector_t*const td;
    const Parameters*const parameters;
};
