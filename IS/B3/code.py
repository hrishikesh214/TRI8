'''
PE06 Hrishikesh Vaze
IS Lab5 Digital Signature and Digital Signature Verification
'''

from Crypto.PublicKey import DSA
from Crypto.Hash import SHA256
from Crypto.Signature import DSS

KEY_SIZE = 1024
message = input('Enter message: ')
message = message.encode()

# generate a key-pair
key = DSA.generate(KEY_SIZE)

# print public key
public_key = key.publickey()
print('Public key: \n\n', public_key.exportKey(), '\n\n')

# hash msg
message = SHA256.new(message)
signer = DSS.new(key, 'fips-186-3')
signature = signer.sign(message)
print(f'Signature: {int.from_bytes(signature, "big")}', '\n\n')

# start verification
verifier = DSS.new(public_key, 'fips-186-3')
try:
    verifier.verify(message, signature)
    print('Signature verified\n')
except ValueError:
    print('Verification failed: \n')
