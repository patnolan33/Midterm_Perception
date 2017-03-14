/**
* @file cameraTest.cpp
* @brief Unit tests
* @details This file is used to run all unit tests for the Camera class
* @author Patrick Nolan (patnolan33)
* @copyright MIT License.
*/

#include <camera.hpp>
#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <tuple>

/**
 * @brief Test the camera's ability to take an image (or use the default image if the webcam has issues)
 */
TEST(CameraTest, take_image) {
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	EXPECT_TRUE(camera->takeImage());
}

/**
 * @brief Test the ability for the camera to grab the boundary from its object detector algorithm
 */
TEST(CameraTest, get_boundary) {

	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	camera->takeImage();
	std::vector<cv::Point> boundaryPts = camera->getBoundary();

	// TODO: Change this length to the correct number of points when I get a test image working
	EXPECT_EQ(10, boundaryPts.size());
}

/**
 * @brief Test the ability for the camera to grab the detected object area for subsequent decision making
 */
TEST(CameraTest, get_area) {

	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	camera->takeImage();

	// Test image object has an area of 176042. Make sure to change if image is changed
	EXPECT_NEAR(176042, camera->getObjectArea(), 1);
}
