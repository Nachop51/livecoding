import json
from pprint import pprint
from datetime import datetime

time = datetime.now()

my_dict = {
    'id': 12,
    'name': "John",
    'places': [ "San Francisco", "Tokyo" ],
    'is_active': True,
    'info': {
        'age': 36,
        'average': 3.14
    },
    'time': str(time)
}

l = [my_dict for i in range(5)]

# print(str(time))

with open('test', 'w') as f:
    json.dumps(f)
