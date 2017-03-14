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

	EXPECT_EQ(10, boundaryPts.size());
}

TEST(ObjectDetectionTest, get_area) {
	std::shared_ptr<ObjectDetection> objectDetection = std::make_shared<ObjectDetection>();
	objectDetection->detectObjectBoundary(filename, false);

	// Test image object has an area of 176042. Make sure to change if image is changed
	EXPECT_NEAR(176042, objectDetection->getObjectArea(), 1);
}

TEST(ObjectDetectionTest, detect_boundary) {
	std::shared_ptr<ObjectDetection> objectDetection = std::make_shared<ObjectDetection>();

	EXPECT_TRUE(objectDetection->detectObjectBoundary(filename, false));
}

