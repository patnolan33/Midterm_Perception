/**
* @file laserRangeFinder.hpp
* @brief LaserRangeFinder Class implementation
* @details Definition of the LaserRangeFinder class to take depth measurements
* @author Patrick Nolan (patnolan33)
* @copyright MIT License.
*/

/**
 * @brief LaserRangeFinder class handles taking depth measurements via single point lasers
 */
class LaserRangeFinder {
 public:
	/**
	 * @brief LaserRangeFinder constructor
	 * @param maxDetectionDistance The cutoff distance where we lose confidence in a measurement
	 */
    explicit LaserRangeFinder(double maxDetectionDistance);

	/**
	 * @brief Take a distance measurement
	 */
    void takeDistanceReading();

	/**
	 * @brief Get the current distance measurement
	 * @return measured distance
	 */
    double getDistance();

	/**
	 * @brief Get the maximum detection distance value
	 * @return maximum detection distance
	 */
    double getMaxDetectionDistance();


 private:
	/**
	 * @brief Maximum detection distance
	 */
    double maxDetectionDistance;

	/**
	 * @brief Current distance measurement
	 */
    double currentReading;
};
