import json
from pprint import pprint
from datetime import datetime

with open('test', 'r') as file:
    data = file.read()

# print(data)

my_dict = json.loads(data)

# my_dict['time'] = my_dict['time'][:10]
my_dict['time'] = my_dict['time'].split(' ')[0]
# print(my_dict['time'])
my_dict['time'] = datetime.strptime(my_dict['time'], '%Y-%m-%d')

pprint(my_dict['time'].date())
