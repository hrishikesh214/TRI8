from aiohttp import web
from aiohttp.web_response import json_response
import socketio

io = socketio.AsyncServer(async_mode='aiohttp')
server = web.Application()
io.attach(server)

async def index(req):
    return json_response({'message': 'Hello World!'})

@io.event
async def connect(sid, environ):
    print('connected ', sid)
    # sid.emit('message')

@io.event
async def message(sid):
    print('message ', sid)
    sid.emit('message')

@io.event
async def disconnect(sid):
    print('disconnected ', sid)

server.router.add_get('/', index)

web.run_app(server)