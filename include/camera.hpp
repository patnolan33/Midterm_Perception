
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <memory>

#include <objectDetection.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


class Camera {
public:

	Camera();

	bool takeImage();

	std::vector<cv::Point> getBoundary();

	double getObjectArea();


private:
	cv::VideoCapture videoCapture;

	std::string currentImage;

	std::shared_ptr<ObjectDetection> boundaryDetection;

};
