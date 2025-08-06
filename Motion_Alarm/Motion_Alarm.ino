// Include Libraries
#include "Arduino.h"
#include "Buzzer.h"
#include "PIR.h"

// Pin Definitions
#define BUZZER_PIN_SIG 2
#define PIR_PIN_SIG    3

// Object initialization
Buzzer buzzer(BUZZER_PIN_SIG);
PIR pir(PIR_PIN_SIG);

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for serial port to connect
  Serial.println("Motion Detection System Initialized");
}

void loop() {
  bool motionDetected = pir.read();

  if (motionDetected) {
    Serial.println("Motion detected!");

    // Beep for 5 seconds with 0.5s period (0.25s on, 0.25s off)
    for (int i = 0; i < 10; i++) {
      buzzer.on();
      delay(250);  // ON for 0.25s
      buzzer.off();
      delay(250);  // OFF for 0.25s
    }

    // Optional: small delay to avoid retriggering immediately
    delay(1000);
  } else {
    Serial.println("No motion");
    delay(200);  // Short delay to reduce serial output spam
  }
}
