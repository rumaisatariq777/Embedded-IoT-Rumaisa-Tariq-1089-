
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// LED pins
const int LED1_PIN = 18;
const int LED2_PIN = 19;

// Different PWM frequencies
const uint32_t LED1_FREQ = 1000;
const uint32_t LED2_FREQ = 5000;

// 8-bit resolution: duty values from 0 to 255
const int PWM_RESOLUTION = 8;
const int MAX_DUTY = 255;

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
    SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET
);

// Current duty-cycle values
int duty1 = 0;
int duty2 = 0;

// Independent fading directions
int direction1 = 1;
int direction2 = 1;

// Non-blocking update timers
unsigned long lastFade1 = 0;
unsigned long lastFade2 = 0;
unsigned long lastOLED = 0;

const unsigned long FADE_INTERVAL_1 = 12;
const unsigned long FADE_INTERVAL_2 = 20;
const unsigned long OLED_INTERVAL = 150;

void updateOLED() {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("DUAL PWM MONITOR");

    display.setCursor(0, 16);
    display.print("LED1: ");
    display.print((duty1 * 100 + 127) / 255);
    display.print("% F:");
    display.print(ledcReadFreq(LED1_PIN));
    display.println("Hz");

    display.setCursor(0, 32);
    display.print("LED2: ");
    display.print((duty2 * 100 + 127) / 255);
    display.print("% F:");
    display.print(ledcReadFreq(LED2_PIN));
    display.println("Hz");

    display.setCursor(0, 50);
    display.println("PWM: 8-bit");

    display.display();
}

void updateFade(
    int &duty,
    int &direction,
    int ledPin
) {
    duty += direction;

    if (duty >= MAX_DUTY) {
        duty = MAX_DUTY;
        direction = -1;
    } else if (duty <= 0) {
        duty = 0;
        direction = 1;
    }

    ledcWrite(ledPin, duty);
}

void setup() {
    Serial.begin(115200);
    delay(200);

    Wire.begin(21, 22);

    bool led1Ready =
        ledcAttach(LED1_PIN, LED1_FREQ, PWM_RESOLUTION);

    bool led2Ready =
        ledcAttach(LED2_PIN, LED2_FREQ, PWM_RESOLUTION);

    if (!led1Ready || !led2Ready) {
        Serial.println("ERROR: PWM initialization failed.");
        while (true) {
            delay(1000);
        }
    }

    ledcWrite(LED1_PIN, 0);
    ledcWrite(LED2_PIN, 0);

    if (!display.begin(
            SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
        Serial.println("ERROR: OLED initialization failed.");
        while (true) {
            delay(1000);
        }
    }

    display.clearDisplay();
    updateOLED();

    Serial.println("Dual LED PWM and OLED monitor ready.");
    Serial.printf(
        "LED1 frequency: %lu Hz\n",
        (unsigned long)ledcReadFreq(LED1_PIN)
    );
    Serial.printf(
        "LED2 frequency: %lu Hz\n",
        (unsigned long)ledcReadFreq(LED2_PIN)
    );
}

void loop() {
    unsigned long now = millis();

    if (now - lastFade1 >= FADE_INTERVAL_1) {
        lastFade1 = now;
        updateFade(duty1, direction1, LED1_PIN);
    }

    if (now - lastFade2 >= FADE_INTERVAL_2) {
        lastFade2 = now;
        updateFade(duty2, direction2, LED2_PIN);
    }

    if (now - lastOLED >= OLED_INTERVAL) {
        lastOLED = now;
        updateOLED();
    }
}