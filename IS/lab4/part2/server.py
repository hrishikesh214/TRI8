'''
PE06 Hrishikesh Vaze
IS B2 Part 2 Client Server Authentication Challenge Response Architecture

Server.py
'''

from aiohttp import web
from aiohttp.web_response import json_response
import socketio, random

io = socketio.AsyncServer(async_mode='aiohttp')
server = web.Application()
io.attach(server)

user_challenges = {} # will store challenge number

# challenge function
def challenge_parse(x):
    return x*x+1

async def index(req):
    return json_response({'message': 'Hello World!'})

@io.event
async def connect(sid, environ):
    print('[server] connection request from ', sid)
    # challenge with random positive int
    # generate a positive int
    user_challenges[sid] = random.randint(1, 100)
    await io.emit('challenge', {'arg': user_challenges[sid]}, room=sid)
    print('[server] challenge sent to ', sid)

@io.event
async def challenge_response(sid, data):
    if(data['response'] == challenge_parse(user_challenges[sid])):
        await io.emit('auth', {'ok':True, 'msg': 'Authenticated!'}, room=sid)
        print('[server] authenticated ', sid)
    else:
        #disconnect user
        await io.emit('auth', {'ok': False, 'msg': 'Authentication Failed!'}, room=sid)
        await io.disconnect(sid)
        print('[server] authentication failed ', sid)

@io.event
async def disconnect(sid):
    print('[server] disconnected ', sid)

server.router.add_get('/', index)

web.run_app(server)