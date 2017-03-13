
class LaserRangeFinder {
public:

	LaserRangeFinder(double maxDetectionDistance);

	void takeDistanceReading();

	double getDistance();

	double getMaxDetectionDistance();


private:
	double maxDetectionDistance;

	double currentReading;

};
