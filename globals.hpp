#pragma once

#include "lemlib/api.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"

// Controller
extern pros::Controller controller;

// Drive Motors
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern pros::Motor intake_motor;

// LemLib
extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Chassis chassis;
extern pros::adi::Pneumatics clamp;

// Clamp
extern bool clampClosed;
extern bool buttonPressed;

// Ring Grabber
extern pros::Motor lb_motor;
extern int lb_position; // 0=low, 1=medium, 2=high
extern bool lb_pressed;
