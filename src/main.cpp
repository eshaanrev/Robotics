#include "main.h"
#include "pros/rtos.hpp"
#include <string>


using namespace std;

void initialize() {
    chassis.calibrate(); 

    pros::delay(50);
    controller.clear();
    pros::lcd::initialize(); 

    pros::delay(100);

    // Display position
    pros::Task screenTask([]() {
        while (true) {
            pros::lcd::print(0, "X: %f", chassis.getPose().x);
            pros::lcd::print(1, "Y: %f", chassis.getPose().y);
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);
            pros::delay(50);
        }
    });
}

void disabled() {}

void competition_initialize() {}

void opcontrol() {
    while (true) {
        drive();
        intake_toggle();
        clamp_toggle();
        lb_cycle();
        pros::delay(50);
    }

}
