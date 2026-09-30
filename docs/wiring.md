# Wiring Guide

## 1. Battery pack

Connect the two Witty Fox 3.7V 2600mAh cells in series:

```
Battery 1 (+) ─── Battery 2 (-)
```

The remaining Battery 1 (-) and Battery 2 (+) terminals are the pack negative and positive.

Nominal voltage: **7.4V**

Fully charged 2S voltage: **8.4V**

Use an appropriate 2S protection/charging solution.

## 2. Main power

```
Battery + → ON/OFF switch → L298N motor supply
Battery - → Common GND
```

## 3. Arduino power

Use the buck converter:

```
Battery → 5V buck converter → regulated 5V
```

Then:

```
Buck 5V → Arduino 5V
Buck GND → Arduino GND
```

Do not feed the 7.4V battery directly into Arduino 5V.

## 4. L298N

| L298N | Arduino |
|---|---|
| ENA | D5 |
| IN1 | D8 |
| IN2 | D9 |
| IN3 | D10 |
| IN4 | D11 |
| ENB | D6 |
| GND | Common GND |

Motor outputs:

- OUT1/OUT2 → Left drive motor
- OUT3/OUT4 → Right drive motor

Remove ENA/ENB jumpers when using PWM speed control.

## 5. L9110S

The L9110S module's supply must match the exact module and the brush-motor voltage/current rating. If your chosen brush motors are 5V-rated, use the regulated 5V rail shown below. Do not connect the 7.4V battery directly to the L9110S unless the exact module and motors are rated for it.

| L9110S | Arduino / Power |
|---|---|
| A-IA | D3 |
| A-IB | D4 |
| B-IA | D7 |
| B-IB | D12 |
| VCC | Regulated 5V* |
| GND | Common GND |

*Use 5V here only with a 5V-compatible L9110S module and brush motors. Check the exact hardware datasheets before powering it.

Motor outputs:

- Channel A → Left brush motor
- Channel B → Right brush motor

## 6. Common ground

Connect:

- Battery -
- Buck converter GND
- Arduino GND
- L298N GND
- L9110S GND

to the same electrical ground.

## Important

Motor polarity can be reversed depending on how each motor is mounted. If a drive motor turns the wrong direction, swap its two motor wires. If a brush rotates in the wrong direction, swap its two motor wires.
