# Robotics

Competition code for our VEX V5 robot (team 750C) for the VRC **High Stakes** season. Built on PROS with [LemLib](https://lemlib.readthedocs.io/) for odometry and motion control, it covers both the autonomous routines and the driver-control layout.

## Features

- **Odometry-based movement** — IMU-tracked pose with LemLib lateral and angular PID controllers for accurate autonomous navigation.
- **Six-motor drivetrain** — two motor groups on blue (600 RPM) gearsets, 2.75" omni wheels.
- **Subsystem control** — ring intake motor, pneumatic mobile-goal clamp, and a lady-brown scoring arm.
- **Autonomous routines** — defined in `auton.cpp` / `autonControl.cpp`.
- **Driver control** — mapped in `driverControl.cpp`.
- **Live telemetry** — pose (X, Y, θ) streamed to the V5 brain screen.

## Tech stack

- **Language:** C++
- **Framework:** [PROS](https://pros.cs.purdue.edu/) (VEX V5 kernel ^4.1.0)
- **Library:** LemLib 0.5.4
- **Build:** PROS CLI / Make

## Project layout

| File | Purpose |
| --- | --- |
| `src/globals.cpp` / `globals.hpp` | Motor, sensor, and chassis definitions |
| `src/main.cpp` | Entry points (init, autonomous, opcontrol) |
| `src/auton.cpp` / `auton.hpp` | Autonomous routines |
| `src/autonControl.cpp` / `autonControl.hpp` | Autonomous selection / control |
| `src/driverControl.cpp` / `driverControl.hpp` | Driver-control bindings |

## Setup

Requires the [PROS CLI](https://pros.cs.purdue.edu/v5/getting-started/) and the LemLib template.

```bash
pros make            # build
pros upload          # upload to a connected V5 brain
pros mu              # build, upload, and open the terminal
```

## Screenshots

<!-- Add a robot photo or field layout here -->
_coming soon_
