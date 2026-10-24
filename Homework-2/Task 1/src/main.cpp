#include <Arduino.h>

// LED GPIO pins
const int LED1_PIN = 18;
const int LED2_PIN = 19;

// Different PWM frequencies
const int LED1_FREQ = 1000;
const int LED2_FREQ = 5000;

// PWM channels for ESP32 Core 2.x
const int LED1_CHANNEL = 0;
const int LED2_CHANNEL = 1;

// 8-bit resolution: duty cycle 0 to 255
const int PWM_RESOLUTION = 8;
const int MAX_DUTY = 255;

// Brightness values
int duty1 = 0;
int duty2 = 0;

// Fade directions
int direction1 = 1;
int direction2 = 1;

unsigned long previousTime = 0;
const unsigned long fadeInterval = 10;

void setup() {
  Serial.begin(115200);

  // Configure PWM channels
  ledcSetup(LED1_CHANNEL, LED1_FREQ, PWM_RESOLUTION);
  ledcSetup(LED2_CHANNEL, LED2_FREQ, PWM_RESOLUTION);

  // Attach GPIO pins to PWM channels
  ledcAttachPin(LED1_PIN, LED1_CHANNEL);
  ledcAttachPin(LED2_PIN, LED2_CHANNEL);

  // Start with both LEDs off
  ledcWrite(LED1_CHANNEL, 0);
  ledcWrite(LED2_CHANNEL, 0);

  Serial.println("Task 1: Dual LED PWM Started");
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= fadeInterval) {
    previousTime = currentTime;

    // LED 1: fade up and down
    duty1 += direction1 * 5;

    if (duty1 >= MAX_DUTY) {
      duty1 = MAX_DUTY;
      direction1 = -1;
    } else if (duty1 <= 0) {
      duty1 = 0;
      direction1 = 1;
    }

    // LED 2: fade up and down
    duty2 += direction2 * 3;

    if (duty2 >= MAX_DUTY) {
      duty2 = MAX_DUTY;
      direction2 = -1;
    } else if (duty2 <= 0) {
      duty2 = 0;
      direction2 = 1;
    }

    // Apply brightness values
    ledcWrite(LED1_CHANNEL, duty1);
    ledcWrite(LED2_CHANNEL, duty2);

    // Convert duty values to percentages
    int percent1 = (duty1 * 100) / MAX_DUTY;
    int percent2 = (duty2 * 100) / MAX_DUTY;

    // Print values to Serial Monitor
    Serial.printf(
      "LED1: %d%% | %d Hz | LED2: %d%% | %d Hz\n",
      percent1, LED1_FREQ, percent2, LED2_FREQ
    );
  }
}
