
#include <camera.hpp>
#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <tuple>


TEST(CameraTest, take_image) {
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	EXPECT_TRUE(camera->takeImage());
}

TEST(CameraTest, get_boundary) {

	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	camera->takeImage();
	std::vector<cv::Point> boundaryPts = camera->getBoundary();

	// TODO: Change this length to the correct number of points when I get a test image working
	EXPECT_EQ(10, boundaryPts.size());
}


TEST(CameraTest, get_area) {

	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	camera->takeImage();

	// Test image object has an area of 176042. Make sure to change if image is changed
	EXPECT_NEAR(176042, camera->getObjectArea(), 1);
}
