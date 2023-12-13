bool init_beeper() {
  ledcSetup(0, 5000, 8);
  ledcAttachPin(beeper, 0);
}

void beep(byte i, byte value) {  
  //ledcWrite(i, value);
}
