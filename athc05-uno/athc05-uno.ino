/*
 * HC-05 AT Mode for Arduino UNO
 * Uses SoftwareSerial for Rx/Tx
 * Pin EN in HC-05 must be on +3V3
 * Arduino Rx connected to HC-05 Tx
 * Arduino Tx connected to HC-05 Rx
 *
 * Serial Monitor: Both NL & CR
 * 
 * HC-05 common commands:
 * AT             OK
 * AT+NAME?       Returns device name
 * AT+NAME=XXXX   Set device name
 * AT+VERSION?    Returns device version
 * AT+UART?       Returns device baud rate
 * AT+UART=X,X,X  Set device Baud rate, stop bit, parity bit (e.g., AT+UART=9600,1,0)
 * AT+PSWD?       Returns device password
 * AT+PSWD=XXXX   Set device password
 */

#define RX 6  // RX of bluetooth module goes to 7 on board
#define TX 7  // TX of bluetooth module goes to 6 on board

#define BAUDHC06 9600
#define BAUDHC05 38400

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(RX, TX);

void setup() {
  Serial.begin(9600);

  while (!Serial)
    ;

  Serial.println("Enter AT commands:");
  BTSerial.begin(BAUDHC05);
}

void loop() {
  // Keep reading from HC-05 and send to Arduino
  // Serial Monitor
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }

  // Keep reading from Arduino Serial Monitor
  //  and send to HC-05
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
