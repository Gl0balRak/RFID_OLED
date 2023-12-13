#include <Arduino.h>

#include "config.h"

bool online = false; // Work mode (if true get messages from telegramm)
bool adding_name = false;
String uuid;
unsigned long clear_disp_timer = 0;

#include "oled.h"
#include "wifi.h"
#include "rfid.h"
#include "manage_data.h"
#include "bot.h"
#include "beeper.h"

void setup() {

  delay(2000);

  if (DEBUG_MODE) Serial.begin(115200);

  //if (!display.begin(SSD1306_SWITCHCAPVCC) && (0x04 & DEBUG_MODE)) Serial.println(F("SSD1306 allocation failed"));
  //d_print(5);

  byte _restart = 0x04 * !init_rfid() + 0x40 * !init_eeprom() + 0x08 * !init_oled();


  if (DEBUG_MODE & 0x20 && _restart & 0x04) Serial.println("[ERROR] RFID initialization failed!");
  if (DEBUG_MODE & 0x20 && _restart & 0x08) Serial.println("[WARNING] OLED initialization failed!");

  online = init_wifi();

  if (online) {
    _restart = 0x02 * !init_bot();
    if (DEBUG_MODE & 0x20 && _restart & 0x02) Serial.println("[WARNING] Bot initialization failed!");
  }
  else {
    if (DEBUG_MODE & 0x20 && _restart & 0x01) {
      Serial.println("[WARNING] WiFi initialization failed!");
    }
    if (DEBUG_MODE & 0x01) Serial.println("[INFO] Offline mode");
  }

  //if (_restart & 0x04) ESP.restart();
}



void loop() {
  update_bot();

  /*
  if (millis() - clear_disp_timer > CLEAR_CD) {
    clear_disp();  
  }
  */
  
  if (!adding_name) {
    uuid = "";

    while (RFID.available() > 0) {
      delay(5);
      uuid += RFID.read();
    }
    if (uuid) {
      if (uuid.length() > 20) {
        uuid = uuid.substring(1, 11);

        beep(0, 128);
        delay(100);
        beep(0, 0);

        int i = get_id();

        if (i != -1) {
          if (millis() - cooldowns[i] > COOLDOWN) {
            attendances[i]++;
            cooldowns[i] = millis();

            if (DEBUG_MODE & 0x10) {
              Serial.println("_____Get uuid_____");
              Serial.println(names[i]);
              Serial.println(attendances[i]);
              Serial.println(cooldowns[i]);
              Serial.println(cooldowns[i]);
              Serial.println("__________________");
            }

            d_print(names[i] + " " + String(attendances[i]));
            
            bot.sendMessage(names[i] + " " + String(attendances[i]));

            set_data();
          }
          else {
            d_print(names[i] + "    COOLDOWN: " + String(COOLDOWN - (millis() - cooldowns[i])));
            bot.sendMessage(names[i] + "    COOLDOWN: " + String(COOLDOWN - (millis() - cooldowns[i])));
          }
          if (DEBUG_MODE & 0x02) Serial.println(uuid);
        }
        else {
          adding_name = add_uuid();

          if (adding_name) bot.sendMessage("Write name:");
        }
      }
    }
  }
  delay(100);
}
