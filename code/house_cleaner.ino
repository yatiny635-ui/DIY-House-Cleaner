// DIY HOUSE CLEANER
// Arduino UNO
// L298N  -> 2 drive motors
// L9110S -> 2 side-brush motors
//
// Base version:
// - Both brushes run continuously
// - Robot drives forward for 5 seconds
// - Drive motors stop
// - Brushes run for another second
// - Cycle repeats
//
// IMPORTANT:
// Use a regulated 5V supply for the Arduino.
// Do not connect a 7.4V battery pack directly to the Arduino 5V pin.

const int ENA = 5;
const int IN1 = 8;
const int IN2 = 9;

const int ENB = 6;
const int IN3 = 10;
const int IN4 = 11;

// L9110S brush channels
const int LEFT_BRUSH_A  = 3;
const int LEFT_BRUSH_B  = 4;

const int RIGHT_BRUSH_A = 7;
const int RIGHT_BRUSH_B = 12;

const int DRIVE_SPEED = 150;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LEFT_BRUSH_A, OUTPUT);
  pinMode(LEFT_BRUSH_B, OUTPUT);

  pinMode(RIGHT_BRUSH_A, OUTPUT);
  pinMode(RIGHT_BRUSH_B, OUTPUT);

  stopRobot();
  stopBrushes();

  delay(1000);
}

void moveForward(int speedValue) {
  // Left drive motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speedValue);

  // Right drive motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speedValue);
}

void stopRobot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void startBrushes() {
  // Left brush
  digitalWrite(LEFT_BRUSH_A, HIGH);
  digitalWrite(LEFT_BRUSH_B, LOW);

  // Right brush
  digitalWrite(RIGHT_BRUSH_A, HIGH);
  digitalWrite(RIGHT_BRUSH_B, LOW);
}

void stopBrushes() {
  digitalWrite(LEFT_BRUSH_A, LOW);
  digitalWrite(LEFT_BRUSH_B, LOW);

  digitalWrite(RIGHT_BRUSH_A, LOW);
  digitalWrite(RIGHT_BRUSH_B, LOW);
}

void loop() {
  startBrushes();

  moveForward(DRIVE_SPEED);
  delay(5000);

  stopRobot();
  delay(1000);

  stopBrushes();
  delay(1000);
}
