#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI   23
#define OLED_CLK    18
#define OLED_DC     16
#define OLED_CS     5
#define OLED_RESET  17
#define beeper 13

#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, OLED_CLK, OLED_MOSI, OLED_CS, OLED_DC, OLED_RESET);

bool init_oled () {
  u8g2.begin();
  // enable UTF8 support for the Arduino print() function
  u8g2.enableUTF8Print();

  return true;
}

void d_print(String _text) {
  u8g2.setFont(u8g2_font_cu12_t_cyrillic);
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 40);
    u8g2.print(_text);
  } while (u8g2.nextPage());
}

void clear_disp() {
    d_print("                                                                      ");
}
