
# Homework 2 - Task 1
## Dual LED PWM Fading with ESP32

### Objective
Control two LEDs independently using PWM and fade
their brightness from minimum to maximum and back.

### Components
- ESP32 DevKit V1
- Two LEDs
- Two 220-ohm resistors
- Jumper wires
- Wokwi simulator

### Pin Configuration

| Component | ESP32 Pin | PWM Frequency |
|---|---|---|
| LED 1 | GPIO 18 | 1000 Hz |
| LED 2 | GPIO 19 | 5000 Hz |

PWM resolution: 8-bit  
Duty-cycle range: 0 to 255

### Working
Both LEDs fade gradually by changing their PWM duty
cycles. The program increases and decreases each duty
value independently.

Duty cycle controls the average power delivered to
the LED and therefore its apparent brightness.
PWM frequency determines how often the signal repeats.

### Simulation
Wokwi Project: PASTE_YOUR_WOKWI_LINK_HERE

### Evidence
See the Screenshots folder for circuit, simulation,
build, upload, and hardware evidence.

### Test Results
Record the actual results after testing the Wokwi
simulation and physical circuit.


### Wokwi Project Link
https://wokwi.com/projects/478759317910340609


### Git Commit
Required Task 1 commit message: task1 completed







## Task 2: Dual LED PWM with OLED Monitoring

### Objective
The objective of Task 2 is to extend Task 1 by adding an SSD1306 OLED display to monitor the PWM duty cycle of two LEDs. The display shows the duty-cycle percentage and configured PWM frequency of each LED.

### Components Used
- ESP32 DevKit C V4
- 2 LEDs (Red and Green)
- 2 × 220Ω current-limiting resistors
- SSD1306 OLED display (128 × 64 pixels, I2C)
- Wokwi simulator
- PlatformIO with Arduino framework

### Connections

| Component | ESP32 Pin |
|---|---|
| LED 1 (Red) | GPIO 19 |
| LED 2 (Green) | GPIO 18 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| OLED VCC | 3.3V |
| OLED GND | GND |

Each LED is connected in series with a 220Ω resistor to limit current.

### PWM Configuration

| Parameter | LED 1 | LED 2 |
|---|---|---|
| GPIO Pin | GPIO 18 | GPIO 19 |
| PWM Channel | 0 | 1 |
| Configured Frequency | 1000 Hz | 5000 Hz |
| Resolution | 8-bit | 8-bit |
| Duty-Cycle Range | 0–255 | 0–255 |
| Fading Interval | 12 ms | 20 ms |

**Note:** The GPIO assignments in the PWM configuration table follow the code. In the current `diagram.json`, the red LED is connected to GPIO 19 and the green LED is connected to GPIO 18, so the physical LED labels are swapped relative to the code's LED 1 and LED 2 names.

### OLED Display Features

The SSD1306 OLED displays:
- A heading: `DUAL PWM MONITOR`
- LED 1 duty-cycle percentage and configured frequency
- LED 2 duty-cycle percentage and configured frequency
- PWM resolution (8-bit)

The duty-cycle percentage is calculated from the 8-bit duty value using:

`Duty Cycle (%) = (Duty Value × 100) / 255`

The OLED refreshes approximately every 150 milliseconds.

### Implementation Details

1. The ESP32 configures two LEDC PWM channels using the Arduino-ESP32 2.x API.
2. Each LED's duty value increases and decreases to produce a fading effect.
3. The `millis()` function schedules LED updates and OLED refreshes without using long delays in the main loop.
4. The `Wire` library initializes I2C communication using GPIO 21 for SDA and GPIO 22 for SCL.
5. The Adafruit GFX and Adafruit SSD1306 libraries control the OLED display.
6. The duty-cycle percentage is calculated from the current duty value and displayed on the OLED.

### Technical Note: PWM Timer Sharing

On the classic ESP32, LEDC channels share timer resources. Therefore, configuring different frequencies on channels 0 and 1 may not provide two independent PWM frequencies because these channels can share a timer.

The OLED code displays the configured frequency constants (1000 Hz and 5000 Hz), not a measurement of the actual output frequencies. Actual frequency independence must be verified separately.

### Expected Result

- Both LEDs fade in and out continuously.
- The OLED displays the current duty-cycle percentages.
- The OLED displays the configured PWM frequency values.
- The display updates periodically while the LEDs continue fading.

### Libraries Used

- `Wire.h` — I2C communication
- `Adafruit_GFX.h` — graphics and text rendering
- `Adafruit_SSD1306.h` — SSD1306 OLED control

### Conclusion

Task 2 extends the dual-LED PWM project by integrating an I2C OLED display. It demonstrates PWM duty-cycle control, periodic updates using `millis()`, and displaying live duty-cycle calculations on an OLED. The actual independence of the two PWM frequencies requires separate verification due to ESP32 LEDC timer-sharing limitations.





