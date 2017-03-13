#include <objectDetection.hpp>
#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <tuple>

#include <cv.h>

const std::string filename = "../blackBorder.jpg";

TEST(ObjectDetectionTest, get_boundary) {
	std::shared_ptr<ObjectDetection> objectDetection = std::make_shared<ObjectDetection>();
	objectDetection->detectObjectBoundary(filename, false);

	std::vector<cv::Point> boundaryPts =
	  objectDetection->getBoundaryPixels();

	// TODO: Change this length to the correct number of points when I get a test image working
	EXPECT_EQ(10, boundaryPts.size());
}

TEST(ObjectDetectionTest, detect_boundary) {
	std::shared_ptr<ObjectDetection> objectDetection = std::make_shared<ObjectDetection>();

	EXPECT_TRUE(objectDetection->detectObjectBoundary(filename, false));
}

