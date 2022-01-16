'''
PE06 Hrishikesh Vaze
IS B2 Part 1 Use of Digest Function

code.py (md5)
'''

import hashlib

str2hash = input('Enter msg to hash: ')

result = hashlib.md5(str2hash.encode())

print("Cipher Text : ", result.hexdigest(), '\n')