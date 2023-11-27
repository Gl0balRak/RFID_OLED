#include <WiFi.h>


bool init_wifi() {
  delay(2000);

  if (DEBUG_MODE & 0x01) Serial.println("[INFO] Network connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (millis() > 15000) return false;
  }

  if (DEBUG_MODE & 0x01) Serial.println("[INFO] Network connected");

  return true;
}
