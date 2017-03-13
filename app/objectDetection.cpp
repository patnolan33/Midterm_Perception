#include <objectDetection.hpp>


ObjectDetection::ObjectDetection() {

}

std::vector<std::tuple<double, double> > ObjectDetection::getBoundaryPixels() {
	return boundaryPixels;
}

bool ObjectDetection::detectObjectBoundary(cv::Mat image) {
	// TODO: actually set these to a proper boundary based on the image provided
	boundaryPixels = { std::make_tuple(1.0, 2.0), std::make_tuple(3.0, 4.0), std::make_tuple(1.0, 2.0), std::make_tuple(3.0, 4.0) };


	return true;
}
