#include <Wire.h>
#include <SoftwareSerial.h>


SoftwareSerial RFID(RX, TX); // RX and TX


bool init_rfid() {
  RFID.begin(9600);

  return true;
}
