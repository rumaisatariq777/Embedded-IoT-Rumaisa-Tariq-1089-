# Homework 2 — Task 1
## Dual LED PWM Fading Using ESP32

### 1. Objective
The objective is to control two LEDs independently using PWM (Pulse Width Modulation). Both LEDs gradually fade from minimum brightness to maximum brightness and then back to minimum brightness.

### 2. Components
- ESP32 development board
- Two LEDs
- Two separate current-limiting resistors
- Breadboard
- Jumper wires

### 3. Circuit Connections

| Component | ESP32 Connection |
|---|---|
| LED 1 | GPIO 18 |
| LED 2 | GPIO 19 |
| Both LED cathodes | GND |

Each LED uses its own current-limiting resistor.

### 4. PWM Configuration

| Parameter | LED 1 | LED 2 |
|---|---|---|
| GPIO Pin | 18 | 19 |
| PWM Frequency | 1000 Hz | 5000 Hz |
| Duty Resolution | 8-bit | 8-bit |
| Duty Cycle Range | 0–255 | 0–255 |

### 5. Working Principle
The ESP32 generates PWM signals for both LEDs using separate PWM channels. The program gradually increases and decreases each LED's duty-cycle value to produce a smooth fading effect.

### 6. Effect of Duty Cycle on Brightness
Duty cycle is the percentage of one PWM cycle during which the signal remains HIGH. At 0% duty cycle, the LED is off. As the duty cycle increases, the LED appears brighter. At 100% duty cycle, the LED operates at maximum brightness.

With 8-bit resolution, the duty values range from 0 to 255.

### 7. Effect of PWM Frequency
PWM frequency is the number of PWM cycles generated per second. LED 1 uses 1000 Hz, while LED 2 uses 5000 Hz. Duty cycle controls the LED's apparent brightness, whereas frequency determines how frequently the PWM signal repeats.

### 8. Simulation and Hardware Testing
The circuit was tested in Wokwi and on the physical ESP32 hardware. Both LEDs were observed fading from minimum to maximum brightness and back. The Serial Monitor displays the changing duty-cycle percentages and configured PWM frequencies.

### 9. Evidence
The `screenshots` folder contains the Wokwi circuit and simulation evidence. Add the physical hardware photograph to the same folder.

### 10. Wokwi Project Link
Paste the public Wokwi project URL here:
(https://wokwi.com/projects/478759317910340609)

### 11. Git Commit
First commit message: `task1 completed`
