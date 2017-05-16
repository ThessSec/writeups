from itertools import izip, cycle
import base64
import json

def xor_crypt_string(data, key, encode=False, decode=False):
    if decode:
        data = base64.decodestring(data)
    xored = ''.join(chr(ord(x) ^ ord(y)) for (x,y) in izip(data, cycle(key)))
    if encode:
        return base64.encodestring(xored).strip()
    return xored

key =  json.dumps(
			{'showpassword':'no', 'bgcolor':'#ffffff'}
			)
orig_cookie = 'ClVLIh4ASCsCBE8lAxMacFMZV2hdVVotEhhUJQNVAmhSEV4sFxFeaAw='
print "Getting key for:\n {} (XOR) {}".format(key, orig_cookie)
key = xor_crypt_string(orig_cookie, key, decode=True)
print "Key derived from XOR encryption: {}".format(key)
key = key[0:4]
print "Using only the first 4 characters: {}".format(key)
cookie =  json.dumps(
			{'showpassword':'yes', 'bgcolor':'#ffffff'}
			)
print "Getting desired cookie for: {}".format(cookie)
flag = xor_crypt_string(cookie, key, encode=True)
print "Insert {} as a cookie in your browser".format(flag)

