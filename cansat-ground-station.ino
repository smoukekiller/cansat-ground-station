#include "config.h"
#include "globals.h"
#include "servo_control.h"
#include "data_processing.h"
#include "panic_mode.h"
#include <ESP32Servo.h>
#include <math.h>
#include "CanSatNeXT.h"

void setup() {
  // Initialize timers for the servos
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  panic_mode_timer = millis();

  antennaservo.setPeriodHertz(50);    // standard 50 hz servo
  antennaservo.attach(ANTENNA_SERVO_PIN, 500, 2500);
  baseservo.setPeriodHertz(50);
  baseservo.attach(BASE_SERVO_PIN, 500, 2500);

  Serial.begin(115200);
  CanSatInit(RADIO_KEY);
}

void loop() {
  // Example usage of servo movements (replace with actual logic)
  baseservo.write(90);
  antennaservo.write(90);
  delay(1000);
  baseservo.write(180);
  antennaservo.write(180);
  delay(1000);
  baseservo.write(0);
  antennaservo.write(0);
  delay(2000);

  // In actual code, you'd call CalculateDeltas(), WriteToServos(), 
  // CheckForPanic() and so on, from here as needed.
}
