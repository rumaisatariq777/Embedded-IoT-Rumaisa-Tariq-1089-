// Ye code ESP32 ke liye hai jo ek LED ko PWM ke zariye fade in aur fade out karta hai.
// Rumaisa Tariq
// 24_NTU_CS_FL_1089
// Embedded Systems 

#include <Arduino.h>
 
constexpr uint8_t LED_PIN = 2;
constexpr uint8_t PWM_CHANNEL = 0;     // Version 2 mein channel zaroori hai (0 se 15 tak koi bhi)
constexpr uint32_t PWM_FREQUENCY = 5000;
constexpr uint8_t PWM_RESOLUTION = 8;
constexpr uint16_t PWM_MAX_DUTY = 255;
 
void setup()
{
    Serial.begin(115200);
 
    //Pehle channel ko configure karein: channel, frequency, resolution
    ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
 
    //Phir us configured channel ko apni physical Pin ke sath jorein
    ledcAttachPin(LED_PIN, PWM_CHANNEL);
 
    // Version 2 mein pin ke bajaye CHANNEL par write kiya jata hai
    ledcWrite(PWM_CHANNEL, 0); 
    
    Serial.println("ESP32 PWM LED Fade Started (Version 2.x Compatible)");
}
 
void loop()
{
    // Fade IN: Roshni barhana
    for (int duty = 0; duty <= PWM_MAX_DUTY; duty++)
    {
        ledcWrite(PWM_CHANNEL, duty); // Pin ki jagah PWM_CHANNEL use hoga
        delay(10); // Aap ka delay 100 tha jo bohat slow tha, 10-15 smooth fade ke liye behtar hai
    }
 
    // Fade OUT: Roshni kam karna
    for (int duty = PWM_MAX_DUTY; duty >= 0; duty--)
    {
        ledcWrite(PWM_CHANNEL, duty); // Pin ki jagah PWM_CHANNEL use hoga
        delay(10);
    }
}