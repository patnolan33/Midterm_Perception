#include <visionSystem.hpp>
#include <gtest/gtest.h>
#include <memory>

TEST(VisionSystemTest, determine_control) {
	std::shared_ptr<VisionSystem> visionSystem = std::make_shared<VisionSystem>(10);

	EXPECT_EQ("turn right", visionSystem->determineControlAction());
}

TEST(VisionSystemTest, get_action) {
	std::shared_ptr<VisionSystem> visionSystem = std::make_shared<VisionSystem>(10);
	visionSystem->determineControlAction();

	EXPECT_EQ("turn right", visionSystem->getSuggestedAction());
}
