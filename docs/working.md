# Working Principle

The base robot uses the Arduino UNO to control two independent motor drivers.

## Drive system

The L298N controls the two drive motors:

- Channel A → left drive motor
- Channel B → right drive motor

The Arduino uses PWM on ENA and ENB to control drive speed.

## Cleaning system

The L9110S controls the two side-brush motors:

- Channel A → left brush
- Channel B → right brush

Both brushes are commanded to rotate continuously.

## Cleaning process

1. The main switch is turned ON.
2. The Arduino starts the brush motors.
3. The drive motors move the robot forward.
4. The left brush sweeps debris inward.
5. The right brush sweeps debris inward.
6. The front scoop guides the debris into the collection area.
7. The programmed drive cycle ends and the robot stops.

## What this version does NOT do

This base version is not autonomous.

It does not:
- Detect obstacles
- Measure distance
- Automatically turn
- Map a room
- Follow a person
- Detect dirt electronically
- Return to a charging station

Those functions require additional hardware and software.

## Future upgrade

An HC-SR04 ultrasonic sensor can be added later for basic obstacle detection and autonomous turning.
