#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Driver.hpp"
#include "PosSensor.hpp"
#include <Arduino.h> // Include for String class when using Arduino platform

/**
 * @class Robot
 * @brief Represents a robot with a name and a set of drivers.
 *
 * The Robot class contains information about the robot's name and drivers,
 * and provides methods to control the robot's movements and speech.
 */
class Robot {
private:
  const String name;
  Driver driver_a;
  PosSensor pos_sensor;
public:
  /**
   * @brief Constructs a new Robot object.
   *
   * @param name The name of the robot.
   * @param drivers The array of drivers for the robot.
   * @param count The number of drivers in the array.
   */
  Robot(const String &name, const Driver & driver_a, const PosSensor & pos_sensor)
      : name(name), driver_a(driver_a), pos_sensor(pos_sensor) {}

  /**
   * @brief Gets the name of the robot.
   *
   * @return The name of the robot.
   */
  String getName() const;

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
  void say(const String &message);

  int getAngle
};

#endif // ROBOT_HPP
