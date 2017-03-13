
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include <objectDetection.hpp>


class Camera {
public:

	Camera();

	bool takeImage();

	std::vector<std::tuple<double, double> > getBoundary();


private:
//	cv::VideoCapture videoCapture;

	cv::Mat currentImage;

	ObjectDetection boundaryDetection;

};
