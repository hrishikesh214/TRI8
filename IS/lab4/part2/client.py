import asyncio
import socketio

io = socketio.AsyncClient()

@io.event
def message(m):
    print('message: ', m)


async def start_client():
    await io.connect('http://localhost:8080')
    await io.emit('message', {'data': 'Hello World!'})
    await io.disconnect()

asyncio.run(start_client())