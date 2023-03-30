/*
 * HC-05 AT Mode for Arduino Nano 33 BLE
 * Uses Serial1 (hardware serial) for Rx/Tx
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

#define BAUDHC06 9600
#define BAUDHC05 38400

void setup() {
  Serial.begin(9600);

  while (!Serial)
    ;

  Serial.println("Enter AT commands:");
  Serial1.begin(BAUDHC05);
}

void loop() {
  // Keep reading from HC-05 and send to Arduino
  // Serial Monitor
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }

  // Keep reading from Arduino Serial Monitor
  // and send to HC-05
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }
}
