# import time
# import asyncio


# async def hello():
#     await asyncio.sleep(2)
#     print("Se durmio dos segundos")

# print("Hello World!")


# async def main():
#     # start = asyncio.get_event_loop().time()
#     start = time.perf_counter()
#     task = hello()
#     await task
#     # end = asyncio.get_event_loop().time()
#     end = time.perf_counter()
#     print(end - start)


# # print("Termino")

# # if __name__ == '__main__':
# #     asyncio.run(main())

import asyncio


async def say_hello():
    await asyncio.sleep(1)
    print("Hello")


async def say_world():
    await asyncio.sleep(1)
    print("World")


async def main():
    await asyncio.gather(say_hello(), say_world())
    # await say_hello()
    # await say_world()

asyncio.run(main())


# import requests
# import time

# start = time.perf_counter()

# res = requests.get("http://www.omdbapi.com/?apikey=b8826283&t=Disney")

# print(res.json())

# res = requests.get("http://www.omdbapi.com/?apikey=b8826283&t=Avengers")

# print(res.json())
# end = time.perf_counter()

# print(f"Total time: {end - start}")
