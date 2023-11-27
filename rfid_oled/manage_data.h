#include <EEPROM.h>


// Data storaged in memory
/*
Data struct in eeprom (flash):

0         2                 NAME_LEN*i+2                       DATA_LEN*NAME_LEN+2   DATA_LEN*NAME_LEN+2+UUID_LEN*i    (NAME_LEN+UUID_LEN)*DATA_LEN + 2 (NAME_LEN+UUID_LEN)*DATA_LEN + 2 + i
|         |                      |                                         |                    |                                     |                   |
| 2 bytes | 2*NAME_LEN bytes |...| 2*NAME_LEN bytes |...| 2*NAME_LEN bytes | UUID_LEN bytes |...| UUID_LEN bytes |...| UUID_LEN bytes | 1 byte | ........ | 1 byte | ... | 1 byte |
|         |                      |                      |                  |                    |                    |                |                   |              |
data len  name 0                 name i                 name DATA_LEN-1    uuid 0               uuid i               uuid DATA_LEN-1  attandance 1        attandance i   attandace DATA_LEN-1

*/

String uuids[DATA_LEN] = {};
String names[DATA_LEN] = {};
byte attendance[DATA_LEN] = {};
int data_len = 0;

unsigned long cooldowns[DATA_LEN] = {}; // Without clocks( with clock to memory)


// ЭТА ХУЕТА КАК ОЧЕВИДНО ИЗ НАЗВАНИЯ УДАЛЯЕТ ВСЕ ДАННЫЕ НАХУЙ ДАЖЕ НЕ ДУМАЙ СУКА ЕЕ ЗАПУСКАТЬ
void clear_all_data() {
  EEPROM.write(0, 0);
  EEPROM.write(1, 0);
}

bool init_eeprom() {
  EEPROM.begin((NAME_LEN+UUID_LEN+1)*DATA_LEN + 2);

  return true;
}

void load_data(int i) {
  
}
