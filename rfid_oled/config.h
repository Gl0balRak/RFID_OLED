// Bot
//#include "token.h"

// Wifi
#define WIFI_SSID "Fight Club 2.4GHz"
#define WIFI_PASS "firstrule"

// Data
#define DATA_LEN 40 // Max number of users !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ОТ ТОЙ ХУЕТЫ ЗАВИСИТ ЕЕПРОМ ДАЖЕ НЕ ДУМАЙ МЕНЯТЬ А ТО ВСЕ НАХУЙ УМРЕТ НАВСЕГДА ПУСТЬ БУДЕТ 300 ЕСЛИ НАДО НЕ 300 ТО ОТСОСИ У ТРАКТОРИСТА ДЕНИС
#define NAME_LEN 30 // Name len !!!!!!!!!!!!!!!!!!!! ЭТО ДЛИННА ИМЕНИ 40 СИМВОЛОВ ДЕНИС СУКА БЛЯТЬ ДАЖЕ НЕ ДУМАЙ ЭТО МЕНЯТЬ ЕСЛИ У КАКОГОТО КЛОУНА БУДЕТ ИМЯ БОЛЬШЕ 40 СИМВОЛОВ ТО ПУСТЬ ОН МЕНЯЕТ ПАССПОРТ НЕ МЕНЯТЬ !!! НЕ МЕНЯТЬ !!!
// ЕЩЕ ТУТ ВЫДЕЛЯЕТСЯ ПО 2 БАЙТА НА СИМВОЛ ТАК КАК РУССКИЙ ЕСЛИ БУКВА НА АНГЛИСКОМ ТО 1 БАЙТ И ТОГДА 80 СИМВОЛОВ
#define UUID_LEN 10 // ДЛИННА ЮЮАДИШНИКА ТОЖЕ НЕ МЕНЯЙ НЕ МЕНЯЙ НЕ МЕНЯЙ  УБЬЁТ !!!!!!!!!!!!
#define COOLDOWN 10000 // time in milliseconds for cooldown between lessons

// RFID
#define RX 15
#define TX 4

// Beeper
#define beeper 13

// OLED
#define CLEAR_CD 8000

#define DEBUG_MODE 0x3f
/*
  0x00 - No debug
  0x01 - Network
  0x02 - RFID
  0x04 - Display
  0x08 - Bot
  0x10 - Data storage
  0x20 - Error messages

  Cross debug example:
  0x03 - netowrk + rfid
*/
