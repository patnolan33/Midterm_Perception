#include <objectDetection.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

ObjectDetection::ObjectDetection() : objectArea(0) {
	fixationPoint.x = 0;
	fixationPoint.y = 0;
}

std::vector<cv::Point> ObjectDetection::getBoundaryPixels() {
	return boundaryPixels;
}

double ObjectDetection::getObjectArea() {
	return objectArea;
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

	// Determine the middle of the image as the fixation point:
	fixationPoint.x = srcImg.size().width / 2;
	fixationPoint.y = srcImg.size().height / 2;


	// Determine which contour the fixation point is contained in:
	for(auto &contour : contours) {
		double isContained = cv::pointPolygonTest(contour, cv::Point2f((float)fixationPoint.x,(float)fixationPoint.y), false);
		if(isContained > 0) {
			boundaryPixels = contour;
			break;
		}
	}

	if(boundaryPixels.size() > 0) {
		// Set object area:
		objectArea = cv::contourArea(boundaryPixels);

		// If desired, show the image and the contour that was found:
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
	cv::polylines(srcImg, &pts, &npts, 1, true, cv::Scalar(0, 255, 0), 3, CV_AA, 0);
	circle(srcImg, fixationPoint,1,CV_RGB(255,0,0),3);
	namedWindow( "Contours", cv::WINDOW_AUTOSIZE );
	imshow( "Boundary", srcImg );

	// Wait for close or press 0 to close
	cv::waitKey(0);
}
