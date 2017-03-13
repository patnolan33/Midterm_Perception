
#include <iostream>


class LaserRangeFinder {
public:

	LaserRangeFinder(double maxDetectionDistance);

	bool takeDistanceReading();

	double getDistance();


private:
	double maxDetectionDistance;

	double currentReading;

};
