#!python

import json

# Load canbus.json
try:
    with open('data.json') as file:
        try:
            message = json.load(file)
        except:
            print("Failed to read and parse the json file")
            exit(1)
except:
    print("Failed to open the json file")
    exit(1)

signals = message['signals']
del message

title = {
    "name": "Signal",
    "type": "Type",
    "length": "Length",
    "comment": "Description"
}

size = {}
for key in title:
    size[key] = len(title[key])

for siganl in signals:
    for key in siganl:
        length = len(str(siganl[key]))
        if size[key] < length:
            size[key] = length

print("\n{} | {} | {} | {}".format(
    title['name'].ljust(size['name']),
    title['type'].ljust(size['type']),
    title['length'].ljust(size['length']),
    title['comment'].ljust(size['comment'])))

print('-' * (sum(size.values()) + 9))

for siganl in signals:
    length = str(siganl['length']).rjust(size['length'] // 2 + 1)
    print("{} | {} | {} | {}".format(
        siganl['name'].ljust(size['name']),
        siganl['type'].ljust(size['type']),
        length.ljust(size['length']),
        siganl['comment'].capitalize().ljust(size['comment'])))
