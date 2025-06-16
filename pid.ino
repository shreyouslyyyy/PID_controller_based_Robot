#include <Motor_Shield.h>

// Create motor objects
DCMotor motorLeft(1);   // M1
DCMotor motorRight(2);  // M2

// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// PID parameters
float Kp = 0.8;
float Ki = 0.05;
float Kd = 0.2;

// PID variables
float error = 0, previousError = 0;
float integral = 0, derivative = 0;
float output = 0;

// Target distance (in cm)
int setPoint = 20;  // Change this as per your target

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  motorLeft.setSpeed(0);
  motorRight.setSpeed(0);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}

void loop() {
  int distance = getDistance();

  // Compute PID terms
  error = distance - setPoint;
  integral += error;
  integral = constrain(integral, -100, 100);  // Anti-windup
  derivative = error - previousError;

  // PID output for speed
  output = (Kp * error) + (Ki * integral) + (Kd * derivative);
  output = constrain(output, -255, 255); // Limit speed

  previousError = error;

  Serial.print("Distance: "); Serial.print(distance);
  Serial.print(" | Error: "); Serial.print(error);
  Serial.print(" | Output: "); Serial.println(output);

  int pwm1 = abs(output);
pwm1 = constrain(pwm1, 80, 255);  // ensure motors get enough power

if (abs(error) <= 2) {
  stopMotors();
  integral = 0;
  derivative = 0;
  return;
}

// Move based on PID output
int pwm = abs(output);
pwm = constrain(pwm, 80, 255);  // Minimum torque

if (output > 0) {
  motorLeft.setSpeed(pwm);
  motorRight.setSpeed(pwm);
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);
} else {
  motorLeft.setSpeed(pwm);
  motorRight.setSpeed(pwm);
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
}



  delay(100);  // Loop delay
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void setMotorSpeed(int speed) {
  motorLeft.setSpeed(speed);
  motorRight.setSpeed(speed);
}

void stopMotors() {
  motorLeft.setSpeed(0);
  motorRight.setSpeed(0);
  motorLeft.run(RELEASE);
  motorRight.run(RELEASE);
}
