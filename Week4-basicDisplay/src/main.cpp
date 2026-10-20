#include <Arduino.h>
#include <Wire.h>                // I2C library for cummincation
#include <Adafruit_GFX.h>        // graphics library 
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128        // OLED display width, in pixels
#define SCREEN_HEIGHT 64        // OLED display height, in pixels

#define OLED_SDA 21             // GPIO pin for OLED SDA  . data send krne ke liye
#define OLED_SCL 22             // GPIO pin for OLED SCL  . communication ke liye clock signal
#define OLED_ADDR 0x3C          // I2C address of the OLED display

Adafruit_SSD1306 display(       // initialize the OLED display object
    SCREEN_WIDTH,
    SCREEN_HEIGHT,              
    &Wire,
    -1
);

void setup() {
    Serial.begin(115200);       // terminal mein print krne ke liye . serial communication start krna . Close to highest

    Wire.begin(OLED_SDA, OLED_SCL); // I2C communication start krna(initialize kr rhi) . SDA and SCL pins ko initialize krna

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("OLED initialization failed!");
        while (true) {
            delay(100);
        }
    }

    display.clearDisplay();
    display.setTextSize(1);     //Text size set krna . 1 means normal size
    display.setTextColor(SSD1306_WHITE);    //Text color set krna . white color

    display.setCursor(0, 0);        // Set the cursor position to the top-left corner of the display. First 0 for x cordinate(left se position), second 0 for y cordinate(top se position) . 0,0 ak pixel dot hai
    display.println("ESP32 + OLED");

    display.println("PlatformIO Ready!");
    display.println("I2C Address: 0x3C");

    display.display();      // yeh command display ki memory ka content ko actual OLED screen par show krta hai . display ki memory mein jo bhi content hai usko OLED screen par show krna

    Serial.println("OLED initialized successfully.");   // Print a success message to the serial monitor
}

void loop() {       
    display.clearDisplay();           // Clear the display buffer
    display.setTextSize(1);          // Set the text size
    display.setTextColor(SSD1306_WHITE);    // Set the text color
    display.setCursor(40,20);
    display.print("Hello, IoT!");
    display.display();              // Set the cursor position to the top-left corner of the display
    // Add your application code here.
}