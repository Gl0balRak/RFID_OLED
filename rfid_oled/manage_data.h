#include <EEPROM.h>


// Data storaged in memory
/*
  Data struct in eeprom (flash):

  0         2                 NAME_LEN*i+2                       DATA_LEN*NAME_LEN+2   DATA_LEN*NAME_LEN+2+UUID_LEN*i    (NAME_LEN+UUID_LEN)*DATA_LEN + 2 (NAME_LEN+UUID_LEN)*DATA_LEN + 2 + i
  |         |                    |                                     |                    |                                     |                            |
  | 2 bytes | NAME_LEN bytes |...| NAME_LEN bytes |...| NAME_LEN bytes | UUID_LEN bytes |...| UUID_LEN bytes |...| UUID_LEN bytes | 1 byte | ........ | 1 byte | ... | 1 byte |
  |         |                    |                                     |                  |                    |                    |                |                   |              |
  data len  name 0             name i                        name DATA_LEN-1    uuid 0               uuid i               uuid DATA_LEN-1  attandance 1        attandance i   attandace DATA_LEN-1

*/

String uuids[DATA_LEN] = {};
String names[DATA_LEN] = {};
byte attendances[DATA_LEN] = {};
int data_len = 0;

unsigned long cooldowns[DATA_LEN] = {}; // Without clocks( with clock to memory)


// ЭТА ХУЕТА КАК ОЧЕВИДНО ИЗ НАЗВАНИЯ УДАЛЯЕТ ВСЕ ДАННЫЕ НАХУЙ ДАЖЕ НЕ ДУМАЙ СУКА ЕЕ ЗАПУСКАТЬ
void clear_all_data() {
  EEPROM.write(0, 0);
  EEPROM.write(1, 0);

  EEPROM.commit();

  data_len = 0;
  
  Serial.println("Data cleaned.");
}


int EEPROM_int_read(int addr) {
  byte raw[2];
  for (byte i = 0; i < 2; i++) raw[i] = EEPROM.read(addr + i);
  return (int)(raw[0] * 256 + raw[1]);
}


void load_data() {  
  data_len = EEPROM_int_read(0);

  for (int i = 0; i < data_len; i++) {
    char _uuid[UUID_LEN];
    char _name[NAME_LEN];
    byte attendance = EEPROM.read((NAME_LEN + UUID_LEN) * DATA_LEN + 2 + i);

    for (int j = 0; j < UUID_LEN; j++) {
      _uuid[j] =  EEPROM.read(DATA_LEN * NAME_LEN + 2 + UUID_LEN * i + j);
    }

    for (int j = 0; j < NAME_LEN; j++) {
      _name[j] =  EEPROM.read(NAME_LEN * i + 2 + j);
    }
    
    uuids[i] = String(_uuid);
    names[i] = String(_name);
    attendances[i] = attendance;
  }
}

void set_data() {
  EEPROM.write(1, data_len%256);
  EEPROM.write(0, data_len/256);
  for (int i = 0; i < data_len; i++) {
    EEPROM.write((NAME_LEN + UUID_LEN) * DATA_LEN + 2 + i, attendances[i]);

    for (int j = 0; j < UUID_LEN; j++) {
      EEPROM.write(DATA_LEN * NAME_LEN + 2 + UUID_LEN * i + j, uuids[i][j]);
    }

    for (int j = 0; j < NAME_LEN; j++) {
      EEPROM.write(NAME_LEN * i + 2 + j, names[i][j]);
    }
  }

  EEPROM.commit();
}

bool init_eeprom() {
  EEPROM.begin((NAME_LEN + UUID_LEN + 1)*DATA_LEN + 2);
  
  //clear_all_data();  // ДАЖЕ НЕ ДУМАЙ РАССКОМЕНЧИВАТЬ ЭТУ ХУЕТУ ДЕНИС
  //while (1) {}
  
  load_data();
  return true;
}
