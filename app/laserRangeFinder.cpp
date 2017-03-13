#include <laserRangeFinder.hpp>

LaserRangeFinder::LaserRangeFinder(double maxDetectionDistance)
: maxDetectionDistance(maxDetectionDistance) {

}

bool LaserRangeFinder::takeDistanceReading() {
	return true;
}

double LaserRangeFinder::getDistance() {
	return 5;
}
