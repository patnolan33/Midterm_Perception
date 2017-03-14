/**
 * @file laserRangeFinder.cpp
 * @brief LaserRangeFinder Class implementation
 * @details Implementation of the LaserRangeFinder class to take depth measurements
 * @author Patrick Nolan (patnolan33)
 * @copyright MIT License.
 */

#include <laserRangeFinder.hpp>

#include <time.h>
#include <iostream>

/**
 * @brief LaserRangeFinder constructor
 * @param maxDetectionDistance The cutoff distance where we lose confidence in a measurement
 */
LaserRangeFinder::LaserRangeFinder(double maxDetectionDistance) :
        maxDetectionDistance(maxDetectionDistance) {
    // Default currentReading to a large value over the maxDetectionDistance:
    currentReading = maxDetectionDistance + 100;
}

/**
 * @brief Take a distance measurement
 */
void LaserRangeFinder::takeDistanceReading() {
    srand(static_cast<unsigned>(time(NULL)));
    double noise = (static_cast<double>(rand()) / (RAND_MAX));

    if (noise > 0.1 && noise < 0.9) {
        currentReading = 4.5 + noise;
    } else {
        currentReading = maxDetectionDistance + 100;
    }
}

/**
 * @brief Get the current distance measurement
 * @return measured distance
 */
double LaserRangeFinder::getDistance() {
    return currentReading;
}

/**
 * @brief Get the maximum detection distance value
 * @return maximum detection distance
 */
double LaserRangeFinder::getMaxDetectionDistance() {
    return maxDetectionDistance;
}
