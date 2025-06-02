#include "main.h"
#include "pros/adi.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "globals.hpp"

// IMU and Controller
pros::Imu imu(19);
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drive Motors
pros::MotorGroup left_motors({-5, -8, 10}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({3, 6, -9}, pros::MotorGearset::blue);

// LemLib Drivetrain (track width 12.5 inches, omniwheel type NEW_275)
lemlib::Drivetrain drivetrain(&left_motors, &right_motors, 12.5, lemlib::Omniwheel::NEW_275, 450, 2);

// Odom (not used)
lemlib::OdomSensors sensors(nullptr, nullptr, nullptr, nullptr, &imu);

// PID 
lemlib::ControllerSettings lateral_controller(12.6, 0, 3, 0, 0, 0, 0, 0, 0);
lemlib::ControllerSettings angular_controller(4, 0, 27, 0, 0, 0, 0, 0, 127);

// Chassis 
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);

// Intake
pros::Motor intake_motor(1);

// Clamp
pros::adi::Pneumatics clamp('A');

// Clamp state variables
bool clampClosed = false;
bool buttonPressed = false;

//LB
pros::Motor lb_motor(2, pros::MotorGearset::red);
int lb_position = 0; // Start at low position
bool lb_pressed = false;
