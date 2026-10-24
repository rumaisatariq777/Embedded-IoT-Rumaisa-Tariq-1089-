
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

