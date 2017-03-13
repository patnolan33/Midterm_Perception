#include <objectDetection.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

ObjectDetection::ObjectDetection() {

}

std::vector<cv::Point> ObjectDetection::getBoundaryPixels() {
	return boundaryPixels;
}

bool ObjectDetection::detectObjectBoundary(const std::string filename, bool displayImage) {
	// Define image processing constants:
	int threshold = 100;

	cv::Mat srcImg = cv::imread(filename);
	cv::Mat srcImgGray;
	cv::cvtColor(srcImg, srcImgGray, CV_RGB2GRAY);
	cv::blur(srcImgGray, srcImgGray, cv::Size(3,3));

	cv::Mat cannyImg;
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;

	// Detect edges using a Canny edge detector:
	cv::Canny( srcImgGray, cannyImg, threshold, threshold*2, 3 );
	// Find all contours:
	cv::findContours( cannyImg, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE );


	// TODO: Find if the fixation point is within a contour, then set the boundary
	//			pixels to the pixels of that contour
	boundaryPixels = contours[0];


	if(boundaryPixels.size() > 0) {
		std::cout << "Found " << contours.size() << " contours." << std::endl;
		std::cout << "Boundary pixels for the first contour: " << boundaryPixels.size() << std::endl;

		if(displayImage) {
			drawBoundary(boundaryPixels, srcImg);
		}

		return true;
	}
	else {
		return false;
	}
}

void ObjectDetection::drawBoundary(std::vector<cv::Point> boundary, cv::Mat srcImg) {

	cv::RNG rng(12345);
	const cv::Point *pts = (const cv::Point*) cv::Mat(boundary).data;
	int npts = cv::Mat(boundary).rows;
	cv::Mat drawing = cv::Mat::zeros( srcImg.size(), CV_8UC3 );
	cv::polylines(srcImg, &pts, &npts, 1, true, cv::Scalar(0, 255, 0), 3, CV_AA, 0);
	namedWindow( "Contours", cv::WINDOW_AUTOSIZE );
	imshow( "Boundary", srcImg );

	// Wait for close or press 0 to close
	cv::waitKey(0);
}
