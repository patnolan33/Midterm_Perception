#include <camera.hpp>

#include <iostream>

Camera::Camera() {
	boundaryDetection = std::make_shared<ObjectDetection>();
}

bool Camera::takeImage() {
	// Capture image from webcam:
	videoCapture = cv::VideoCapture(0);

	// Get the image frame:
	cv::Mat img;
	videoCapture >> img;

	if(img.empty()) {
		std::cout << "There is something wrong with the webcam, using default test image blackBorder.jpg..." << std::endl;
		currentImage = "../blackBorder.jpg";

		boundaryDetection->detectObjectBoundary(currentImage, false);
	}
	else {
		cv::imwrite("webcamImage.jpg", img);
		currentImage = "webcamImage.jpg";

		boundaryDetection->detectObjectBoundary(currentImage, false);
	}


	// Only return true if our boundary has been found
	if(getBoundary().size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

std::vector<cv::Point> Camera::getBoundary() {
	return boundaryDetection->getBoundaryPixels();
}

double Camera::getObjectArea() {
	return boundaryDetection->getObjectArea();
}
