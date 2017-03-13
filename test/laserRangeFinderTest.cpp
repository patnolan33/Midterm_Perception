#include <laserRangeFinder.hpp>
#include <gtest/gtest.h>
#include <memory>

TEST(LaserRangeFinderTest, read_distance) {
	std::shared_ptr<LaserRangeFinder> laserRangeFinder = std::make_shared<LaserRangeFinder>(10);

	EXPECT_TRUE(laserRangeFinder->takeDistanceReading());
}

TEST(LaserRangeFinderTest, get_distance) {
	std::shared_ptr<LaserRangeFinder> laserRangeFinder = std::make_shared<LaserRangeFinder>(10);

	EXPECT_NEAR(5, laserRangeFinder->getDistance(), 0.01);
}
