#include <camera.hpp>

Camera::Camera() {

}

bool Camera::takeImage() {
	return true;
}

std::vector<std::tuple<double, double> > Camera::getBoundary() {
	// TODO: Use the image from the takeImage function
	std::vector<std::tuple<double, double> > boundaryPixels = { std::make_tuple(1.0, 2.0), std::make_tuple(3.0, 4.0), std::make_tuple(1.0, 2.0), std::make_tuple(3.0, 4.0) };
	return boundaryPixels;
}
