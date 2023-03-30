/*
 * HC-06 AT Mode for Arduino UNO
 * Uses SoftwareSerial for Rx/Tx
 * Arduino Rx connected to HC-06 Tx
 * Arduino Tx connected to HC-06 Rx
 *
 * Serial Monitor: No Line Ending
 * 
 * HC-06 common commands:
 * AT               OK
 * AT+NAME<name>    Set device name (e.g., AT+NAMEPhoenix)
 * AT+VERSION       Returns device version
 * AT+BAUD<number>  Set device Baud rate (e.g., AT+BAUD4)
 *                  1 -  1200, 2 -  2400, 3 -  4800, 4 -   9600
 *                  5 - 19200, 6 - 38400, 7 - 57600, 8 - 115200
 * AT+PN            Set no parity
 * AT+PO            Set odd parity
 * AT+PE            Set even parity
 * AT+PIN<pin>      Set device password (e.g., AT+PIN1465)
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
  BTSerial.begin(BAUDHC06);
}

void loop() {
  // Keep reading from HC-06 and send to Arduino
  // Serial Monitor
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }

  // Keep reading from Arduino Serial Monitor
  //  and send to HC-06
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
