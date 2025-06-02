#include "main.h"
#include "globals.cpp"

void drive(){
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    chassis.arcade(leftY, rightY);
}

void intake_toggle() {
    static int intake_state = 0; // 0 = off, 1 = in, -1 = out
    
    bool toggle_in = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1);
    bool toggle_out = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2);
    
    if (toggle_in) {
        intake_state = (intake_state == 1) ? 0 : 1;
    }
    else if (toggle_out) {
        intake_state = (intake_state == -1) ? 0 : -1;
    }
    
    if (intake_state == 1) {
        intake_motor.move(127);
    }
    else if (intake_state == -1) {
        intake_motor.move(-127);
    }
    else {
        intake_motor.move(0);
    }
}

void clamp_toggle() {
    if (clampClosed) {
        // Open the clamp
        clamp.retract();
        clampClosed = false;
        controller.print(0, 0, "Clamp: OPEN   ");
    } else {
        // Close the clamp
        clamp.extend();
        clampClosed = true;
        controller.print(0, 0, "Clamp: CLOSED ");
    }
}

void lb_cycle() {
    // A button cycles through positions
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) && !lb_pressed) {
        lb_position = (lb_position + 1) % 3; // Cycle 0→1→2→0
        
        // Move to position
        if (lb_position == 0) {
            lb_motor.move_absolute(0, 100);    // Low - default
            controller.print(1, 0, "Grab: LOW  ");
        } else if (lb_position == 1) {
            lb_motor.move_absolute(90, 100);   // Medium - grab ready
            controller.print(1, 0, "Grab: READY");
        } else {
            lb_motor.move_absolute(180, 100);  // High - place rings
            controller.print(1, 0, "Grab: HIGH ");
        }
        lb_pressed = true;
    } else if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        lb_pressed = false;
    }
}

void opcontrol() {
    while (true) {
        drive();
        intake_toggle();
        clamp_toggle();
        lb_cycle();
        pros::delay(50);
    }
}