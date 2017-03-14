/**
 * @file visionSystemTest.cpp
 * @brief Unit tests
 * @details This file is used to run all unit tests for the VisionSystem class
 * @author Patrick Nolan (patnolan33)
 * @copyright MIT License.
 */

#include <visionSystem.hpp>
#include <gtest/gtest.h>
#include <memory>

/**
 * @brief Test the ability for the vision system to determine a suggested control action
 */
TEST(VisionSystemTest, determine_control) {
    std::shared_ptr<VisionSystem> visionSystem = std::make_shared < VisionSystem
            > (10, 200000);

    EXPECT_EQ("turn right 45 degrees", visionSystem->determineControlAction());
}

/**
 * @brief Test getting the current suggested action
 */
TEST(VisionSystemTest, get_action) {
    std::shared_ptr<VisionSystem> visionSystem = std::make_shared < VisionSystem
            > (10, 200000);
    visionSystem->determineControlAction();

    EXPECT_EQ("turn right 45 degrees", visionSystem->getSuggestedAction());
}

/**
 * @brief Test getting the vehicle cross section
 */
TEST(VisionSystemTest, get_vehicle_cross_section) {
    std::shared_ptr<VisionSystem> visionSystem = std::make_shared < VisionSystem
            > (10, 100);

    EXPECT_EQ(100, visionSystem->getVehicleCrossSection());
}
