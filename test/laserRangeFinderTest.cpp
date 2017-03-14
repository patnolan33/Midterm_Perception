/**
 * @file laserRangeFinderTest.cpp
 * @brief Unit tests
 * @details This file is used to run all unit tests for the LaserRangeFinder class
 * @author Patrick Nolan (patnolan33)
 * @copyright MIT License.
 */
#include <laserRangeFinder.hpp>
#include <gtest/gtest.h>
#include <memory>

/**
 * @brief Test the laser's ability to take a distance reading and set the appropriate value
 */
TEST(LaserRangeFinderTest, read_distance) {
    std::shared_ptr<LaserRangeFinder> laserRangeFinder = std::make_shared
            < LaserRangeFinder > (0);

    laserRangeFinder->takeDistanceReading();
    EXPECT_LT(0, laserRangeFinder->getDistance());
}

/**
 * @brief Test getting the current laser reading
 */
TEST(LaserRangeFinderTest, get_distance) {
    std::shared_ptr<LaserRangeFinder> laserRangeFinder = std::make_shared
            < LaserRangeFinder > (0.1);

    EXPECT_EQ(100.1, laserRangeFinder->getDistance());
}

/**
 * @brief Test getting the max detection distance parameter
 */
TEST(LaserRangeFinderTest, get_max_distance) {
    std::shared_ptr<LaserRangeFinder> laserRangeFinder = std::make_shared
            < LaserRangeFinder > (10);

    EXPECT_EQ(10, laserRangeFinder->getMaxDetectionDistance());
}
