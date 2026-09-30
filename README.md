# DIY House Cleaner Robot 🧹🤖

A beginner-friendly DIY floor-sweeping robot built with Arduino UNO, an L298N motor driver, an L9110S dual motor driver, Witty Fox Li-ion batteries, BO/DC gear motors, rotating side brushes and a cardboard chassis.

> **Project scope:** This version is a basic powered floor-sweeper. It drives forward and rotates the two side brushes. It does **not** autonomously detect obstacles or follow a person.

## What the robot does

1. Turn the main ON/OFF switch ON.
2. The two side brushes start rotating.
3. The two drive motors start moving the robot forward.
4. The rotating brushes sweep small dry debris inward.
5. The front scoop guides/collects the swept debris.

The project is intentionally simple so it can be built and understood by beginners.

## Components

### Electronics
- Arduino UNO ×1
- L298N dual H-bridge motor driver ×1
- L9110S dual motor driver ×1
- Witty Fox 3.7V 2600mAh Li-ion battery ×2
- 5V buck converter ×1
- ON/OFF switch ×1
- BO/DC gear motors for drive ×2
- DC motors for side brushes ×2
- Side cleaning brush assemblies ×2
- Jumper wires
- Suitable connectors/terminals

### Mechanical parts
- Corrugated cardboard chassis
- 2 drive wheels
- 1 caster wheel
- White plastic/cardboard front collection scoop
- Motor brackets
- Screws, nuts and washers
- Hot glue/adhesive
- Brush mounting discs/couplers
- Battery holder suitable for the chosen cells

## Power architecture

The two Witty Fox 3.7V cells are used as a 2S battery pack:

**3.7V + 3.7V = 7.4V nominal**

A 2S Li-ion pack reaches approximately **8.4V when fully charged**.

### Motor power
Battery positive → ON/OFF switch → L298N motor supply

Battery negative → common ground

The L298N powers the two drive motors.

### Regulated 5V
Battery → 5V buck converter → regulated 5V

Use the regulated 5V output to power:
- Arduino UNO 5V
- L9110S VCC

Connect all grounds together.

**Do NOT connect the 7.4V battery directly to the Arduino 5V pin.**

## Drive motor wiring

### L298N → Arduino UNO

| L298N pin | Arduino UNO |
|---|---|
| ENA | D5 |
| IN1 | D8 |
| IN2 | D9 |
| IN3 | D10 |
| IN4 | D11 |
| ENB | D6 |
| GND | Common GND |

Remove the ENA/ENB jumpers if you want Arduino PWM speed control.

### Drive motors

- Left drive motor → OUT1 and OUT2
- Right drive motor → OUT3 and OUT4

If a motor turns opposite to the desired direction, reverse that motor's two wires.

## Side brush wiring

Use the L9110S for the two brush motors.

| L9110S pin | Arduino UNO |
|---|---|
| A-IA | D3 |
| A-IB | D4 |
| B-IA | D7 |
| B-IB | D12 |
| VCC | Regulated 5V |
| GND | Common GND |

- Left brush motor → L9110S Channel A
- Right brush motor → L9110S Channel B

If a brush rotates in the wrong direction, reverse that motor's two wires.

## Common ground

These grounds must be electrically common:

- Battery negative
- Buck converter negative
- Arduino GND
- L298N GND
- L9110S GND

## Arduino code

The code in `code/house_cleaner.ino`:
- Starts both brushes
- Drives both wheels forward
- Runs the cleaning cycle for 5 seconds
- Stops the drive motors
- Keeps the brushes running briefly
- Stops the brushes
- Repeats

The speed value is PWM-controlled through the L298N ENA/ENB pins.

## Assembly overview

1. Cut a rigid cardboard base.
2. Mount the two drive motors on opposite sides.
3. Attach the two drive wheels.
4. Add a caster wheel to support the chassis.
5. Build the front scoop between/behind the two side brushes.
6. Mount one brush motor on each front side.
7. Attach the circular brushes securely to the motor shafts.
8. Mount the Arduino UNO on the upper deck.
9. Mount the L298N and L9110S where they have airflow and cannot short against the chassis.
10. Secure the Witty Fox battery pack in a proper holder/enclosure.
11. Install the main ON/OFF switch.
12. Complete the wiring using the wiring guide.
13. Check every connection before inserting/powering the battery.
14. Test the wheels with the robot lifted off the floor.
15. Test the brushes.
16. Place the robot on the floor and test at low speed.

## How the cleaning mechanism works

The two front circular brushes rotate continuously.

The left brush sweeps debris inward from the left side.

The right brush sweeps debris inward from the right side.

The front scoop then guides the swept debris into the collection area as the robot moves forward.

This is a **sweeping mechanism**, not a vacuum system. It does not use suction.

## Important electrical and battery safety

- Use a proper **2S Li-ion charger/balancing setup** for two 3.7V cells connected in series.
- Do not charge the two cells with a single-cell 4.2V charger while they are connected as a 2S pack.
- Use cells that are appropriate for the required current.
- Insulate exposed battery terminals.
- Never allow the battery wires to short.
- Use a suitable fuse/protection/BMS where appropriate.
- Do not connect the 7.4V pack directly to the Arduino 5V pin.
- Verify the actual motor current and driver ratings before final assembly.
- The L298N has significant voltage loss and heat generation; provide ventilation and avoid prolonged stall conditions.
- Disconnect the battery when working on the wiring.

## Important limitation

The L298N has two motor channels. This design therefore uses it for the **two drive motors only**.

The two side-brush motors are handled separately by the L9110S.

This is preferable to putting four motors across the two L298N channels, because the current demand of multiple motors can exceed what the driver can safely handle.

## Future upgrades

Possible upgrades include:
- HC-SR04 obstacle detection
- Automatic turning
- Edge/cliff detection
- Battery voltage monitoring
- Speed control
- Servo-controlled collection flap
- Better dust/debris container
- Rechargeable charging dock

These are not part of the base version.

## Project structure

```
DIY-House-Cleaner/
├── README.md
├── code/
│   └── house_cleaner.ino
└── docs/
    ├── components.md
    ├── wiring.md
    ├── assembly.md
    └── working.md
```

## License

This project is shared for educational and DIY purposes. Check component manufacturer documentation for electrical limits and safe operating procedures.
