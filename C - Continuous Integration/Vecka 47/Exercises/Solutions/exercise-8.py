#!python

message = {
    "id": "0x100",
    "signals": [
        {
            "name": "temperature",
            "type": "float",
            "length": 10,
            "comment": "the ambient temperature"
        },
        {
            "name": "humidity",
            "type": "uint8_t",
            "length": 7,
            "comment": "the ambient humidity percentage"
        },
        {
            "name": "dht_sensor_status",
            "type": "uint8_t",
            "length": 2,
            "comment": "the dht sensor status"
        },
        {
            "name": "flow_rate",
            "type": "uint16_t",
            "length": 9,
            "comment": "the flow rate in milliliter per second"
        },
        {
            "name": "flow_meter_sensor_status",
            "type": "uint8_t",
            "length": 2,
            "comment": "the flow meter sensor status"
        },
        {
            "name": "light_intensity",
            "type": "uint8_t",
            "length": 7,
            "comment": "the light intensity percentage"
        },

        {
            "name": "light_intensity_sensor_status",
            "type": "uint8_t",
            "length": 2,
            "comment": "the light intensity sensor status"
        },
        {
            "name": "water_level",
            "type": "uint8_t",
            "length": 7,
            "comment": "the water level percentage"
        },
        {
            "name": "water_level_sensor_status",
            "type": "uint8_t",
            "length": 2,
            "comment": "the water level sensor status"
        },
        {
            "name": "soil_moisture",
            "type": "uint8_t",
            "length": 7,
            "comment": "the soil moisture percentage"
        },
        {
            "name": "soil_moisture_sensor_status",
            "type": "uint8_t",
            "length": 2,
            "comment": "the soil moisture sensor status"
        }
    ]
}

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
    length = str(siganl['length']).rjust(size['length']//2 + 1)
    print("{} | {} | {} | {}".format(
        siganl['name'].ljust(size['name']),
        siganl['type'].ljust(size['type']),
        length.ljust(size['length']),
        siganl['comment'].capitalize().ljust(size['comment'])))
