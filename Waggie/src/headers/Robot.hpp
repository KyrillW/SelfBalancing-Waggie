#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Driver.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

/**
 * @class Robot
 * @brief Represents a robot with a name and a set of drivers.
 *
 * The Robot class contains information about the robot's name and drivers,
 * and provides methods to control the robot's movements and speech.
 */
class Robot {
private:
  const string name;
  const vector<Driver> drivers;

public:
  /**
   * @brief Constructs a new Robot object.
   *
   * @param name The name of the robot.
   * @param drivers The vector of drivers for the robot.
   */
  Robot(const string &name, const vector<Driver> &drivers)
      : name(name), drivers(drivers){};

  /**
   * @brief Gets the name of the robot.
   *
   * @return The name of the robot.
   */
  string getName() const;

  /**
   * @brief Gets the drivers of the robot.
   *
   * @return The vector of drivers.
   */
  vector<Driver> getDrivers() const;

  /**
   * @brief Moves the robot forward at a specified speed.
   *
   * @param speed The speed at which the robot should move forward.
   */
  void forward(const int speed);

  /**
   * @brief Moves the robot backward at a specified speed.
   *
   * @param speed The speed at which the robot should move backward.
   */
  void backward(const int speed);

  /**
   * @brief Makes the robot say a specified message.
   *
   * @param message The message the robot should say.
   */
  void say(string message);
}

#endif // ROBOT_HPP
