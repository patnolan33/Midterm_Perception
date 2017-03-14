#include <visionSystem.hpp>
#include <gtest/gtest.h>
#include <memory>

TEST(VisionSystemTest, determine_control) {
	std::shared_ptr<VisionSystem> visionSystem = std::make_shared<VisionSystem>(10, 200000);

	EXPECT_EQ("turn right 45 degrees", visionSystem->determineControlAction());
}

TEST(VisionSystemTest, get_action) {
	std::shared_ptr<VisionSystem> visionSystem = std::make_shared<VisionSystem>(10, 200000);
	visionSystem->determineControlAction();

	EXPECT_EQ("turn right 45 degrees", visionSystem->getSuggestedAction());
}

TEST(VisionSystemTest, get_vehicle_cross_section) {
	std::shared_ptr<VisionSystem> visionSystem = std::make_shared<VisionSystem>(10, 100);

	EXPECT_EQ(100, visionSystem->getVehicleCrossSection());
}
