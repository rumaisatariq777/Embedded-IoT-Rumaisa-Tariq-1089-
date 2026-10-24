
#include <Arduino.h>

// Task 1: Two LEDs fading with different PWM frequencies

const int LED1_PIN = 18;
const int LED2_PIN = 19;

const int LED1_FREQ = 1000;
const int LED2_FREQ = 5000;

const int PWM_RESOLUTION = 8;
const int MAX_DUTY = 255;

int duty1 = 0;
int duty2 = 0;

int direction1 = 1;
int direction2 = 1;

unsigned long previousTime = 0;
const unsigned long fadeInterval = 10;

void setup() {
    Serial.begin(115200);

    // Configure PWM outputs (Arduino-ESP32 Core 3.x)
    bool led1Ready = ledcAttach(
        LED1_PIN, LED1_FREQ, PWM_RESOLUTION
    );

    bool led2Ready = ledcAttach(
        LED2_PIN, LED2_FREQ, PWM_RESOLUTION
    );

    if (!led1Ready || !led2Ready) {
        Serial.println("PWM setup failed!");
        while (true) {
            delay(1000);
        }
    }

    ledcWrite(LED1_PIN, 0);
    ledcWrite(LED2_PIN, 0);

    Serial.println("Task 1: Dual LED PWM Started");
}

void loop() {
    unsigned long currentTime = millis();

    if (currentTime - previousTime >= fadeInterval) {
        previousTime = currentTime;

        duty1 += direction1 * 5;

        if (duty1 >= MAX_DUTY) {
            duty1 = MAX_DUTY;
            direction1 = -1;
        } else if (duty1 <= 0) {
            duty1 = 0;
            direction1 = 1;
        }

        duty2 += direction2 * 3;

        if (duty2 >= MAX_DUTY) {
            duty2 = MAX_DUTY;
            direction2 = -1;
        } else if (duty2 <= 0) {
            duty2 = 0;
            direction2 = 1;
        }

        ledcWrite(LED1_PIN, duty1);
        ledcWrite(LED2_PIN, duty2);

        int percent1 = (duty1 * 100) / MAX_DUTY;
        int percent2 = (duty2 * 100) / MAX_DUTY;

        Serial.printf(
            "LED1: %d%% | %d Hz | LED2: %d%% | %d Hz\n",
            percent1, LED1_FREQ,
            percent2, LED2_FREQ
        );
    }
}
