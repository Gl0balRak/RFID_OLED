#include <FastBot.h>

#define BOT_TOKEN "6697865450:AAEHNK4HxZb_sFfouSUnv6Pn_ATL1kbdcCY"
#define CHAT_ID "-1002020426153"

FastBot bot(BOT_TOKEN);


void get_msg(FB_msg& msg) {
  if (adding_name) {
    names[data_len] = msg.text;
    attendances[data_len] = 0;
    cooldowns[data_len] = 0;
    data_len++;
    adding_name = false;
    set_data();
  }

  if (msg.text == "/all") {
      String _text = "";
      for (int i = 0; i < data_len; i++) {
        _text += names[i] + " " + String(attendances[i]) + "\n";
      }
      bot.sendMessage(_text);
  }

  if (msg.text == "/clear") {
      clear_all_data();
      bot.sendMessage("Все данные удалены :)");
  }
}

bool init_bot() {
  if (DEBUG_MODE & 0x08) Serial.println("[INFO] Starting bot...");

  bot.setChatID(CHAT_ID);
  bot.skipUpdates();
  bot.sendMessage("[INFO] Bot started!");
  bot.attach(get_msg);

  return true;
}

void update_bot() {
  bot.tick();
}

int get_id() {
  for (int i = 0; i < data_len; i++)
    if (uuid == uuids[i]) return i;
  return -1;
}

bool add_uuid() { //!!!!!!!!!!!!!!!!!!!!!!!!
  if (data_len >= DATA_LEN) return false;

  uuids[data_len] = uuid;
  return true;
}
