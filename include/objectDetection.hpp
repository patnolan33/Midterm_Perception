
#include <iostream>
#include <vector>
#include <string>

#include <cv.h>


class ObjectDetection {
public:

	ObjectDetection();

	std::vector<cv::Point> getBoundaryPixels();

	double getObjectArea();

	bool detectObjectBoundary(const std::string filename, bool displayImage);


private:

	void drawBoundary(std::vector<cv::Point> boundary, cv::Mat cannyImg);

	std::vector<cv::Point> boundaryPixels;

	double objectArea;

	cv::Point fixationPoint;

};
