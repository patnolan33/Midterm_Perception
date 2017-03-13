#include <laserRangeFinder.hpp>

#include <iostream>
#include <time.h>

LaserRangeFinder::LaserRangeFinder(double maxDetectionDistance)
: maxDetectionDistance(maxDetectionDistance),
  currentReading(maxDetectionDistance*10){
}

void LaserRangeFinder::takeDistanceReading() {

	srand((unsigned)time(NULL));
	double noise = ((double) rand() / (RAND_MAX));

	if(noise > 0.1 && noise < 0.9) {
		currentReading = 4.5 + noise;
	}
	else {
		currentReading = maxDetectionDistance*10;
	}
}

double LaserRangeFinder::getDistance() {
	return currentReading;
}

double LaserRangeFinder::getMaxDetectionDistance() {
	return maxDetectionDistance;
}
