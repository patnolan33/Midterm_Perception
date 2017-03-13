#include <objectDetection.hpp>
#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <tuple>

#include <cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


TEST(ObjectDetectionTest, get_boundary) {
	std::shared_ptr<ObjectDetection> objectDetection = std::make_shared<ObjectDetection>();

	cv::Mat image = cv::imread("checkerboard.jpg");
	objectDetection->detectObjectBoundary(image);

	std::vector < std::tuple<double, double> > boundaryPts =
	  objectDetection->getBoundaryPixels();

	// TODO: Change this length to the correct number of points when I get a test image working
	EXPECT_EQ(4, boundaryPts.size());
}

TEST(ObjectDetectionTest, detect_boundary) {
	std::shared_ptr<ObjectDetection> objectDetection = std::make_shared<ObjectDetection>();

	cv::Mat image = cv::imread("testImage.jpg");
	EXPECT_TRUE(objectDetection->detectObjectBoundary(image));
}

