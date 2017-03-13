
#include <iostream>
#include <vector>
#include <string>

#include <cv.h>


class ObjectDetection {
public:

	ObjectDetection();

	std::vector<cv::Point> getBoundaryPixels();

	bool detectObjectBoundary(const std::string filename, bool displayImage);


private:

	void drawBoundary(std::vector<cv::Point> boundary, cv::Mat cannyImg, std::vector<cv::Vec4i> hierarchy);

	std::vector<cv::Point> boundaryPixels;

};
