'''
PE06 Hrishikesh Vaze
IS B2 Part 2 Client Server Authentication Challenge Response Architecture

Client.py
'''


import asyncio
import socketio

io = socketio.AsyncClient()

@io.event
async def challenge(m):
    print('[client] challenge recieved, n = ', m['arg'])
    # send response
    await asyncio.sleep(1)
    await io.emit('challenge_response', {'response': m['arg']*m['arg'] + 1})
    print('[client] challenge response sent')

@io.event
async def auth(m):
    print('[client] authentication: ', m['msg'])


async def start_client():
    print('[client] connecting to server...')
    await io.connect('http://localhost:8080')
    print('[client] waiting for authentication (timeout 5 seconds)...')
    await asyncio.sleep(5) # wait for server to authenticate
    print('[client] disconnecting...')
    await io.disconnect()
    
asyncio.run(start_client())