#include <laserRangeFinder.hpp>
#include <gtest/gtest.h>
#include <memory>

TEST(LaserRangeFinderTest, read_distance) {
	std::shared_ptr<LaserRangeFinder> laserRangeFinder = std::make_shared<LaserRangeFinder>(0);

	laserRangeFinder->takeDistanceReading();
	EXPECT_LT(0, laserRangeFinder->getDistance());
}

TEST(LaserRangeFinderTest, get_distance) {
	std::shared_ptr<LaserRangeFinder> laserRangeFinder = std::make_shared<LaserRangeFinder>(0.1);

	EXPECT_EQ(100.1, laserRangeFinder->getDistance());
}

TEST(LaserRangeFinderTest, get_max_distance) {
	std::shared_ptr<LaserRangeFinder> laserRangeFinder = std::make_shared<LaserRangeFinder>(10);

	EXPECT_EQ(10, laserRangeFinder->getMaxDetectionDistance());
}
