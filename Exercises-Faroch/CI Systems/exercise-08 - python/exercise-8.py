#Beskrivning
#Make a program to display the signals in a table exact like the image.

message = {
    "id":"0x100",
    "signals":[
        {"name":"temperature",                   "type":"float",    "length":10, "comment":"the ambient temperature"},
        {"name":"humidity",                      "type":"uint8_t",  "length":7,  "comment":"the ambient humidity percentage"},
        {"name":"dht_sensor_status",             "type":"uint8_t",  "length":2,  "comment":"the dht sensor status"},
        {"name":"flow_rate",                     "type":"uint16_t", "length":9,  "comment":"the flow rate in milliliter per second"},
        {"name":"flow_meter_sensor_status",      "type":"uint8_t",  "length":2,  "comment":"the flow meter sensor status"},
        {"name":"light_intensity",               "type":"uint8_t",  "length":7,  "comment":"the light intensity percentage"},
        {"name":"light_intensity_sensor_status", "type":"uint8_t",  "length":2,  "comment":"the light intensity sensor status"},
        {"name":"water_level",                   "type":"uint8_t",  "length":7,  "comment":"the water level percentage"},
        {"name":"water_level_sensor_status",     "type":"uint8_t",  "length":2,  "comment":"the water level sensor status"},
        {"name":"soil_moisture",                 "type":"uint8_t",  "length":7,  "comment":"the soil moisture percentage"},
        {"name":"soil_moisture_sensor_status",   "type":"uint8_t",  "length":2,  "comment":"the soil moisture sensor status"}
    ]
}

signals = message["signals"]

# calculate dynamic widths
title = ["Signal", "Type", "Length", "Description"]
width = {"name":len(title[0]), "type":len(title[1]), "length":len(title[2]), "comment":len(title[3])}
for row in signals:
    for col in row:
        width[col] = max(width[col], len(str(row[col])))

# rigid solution
# fmt = "{:<29} | {:<8} | {:^6} | {:<30}"

# dynamic solution
lim = " | "
fmt = f"{{:<{width['name']}}}{lim}{{:<{width['type']}}}{lim}{{:^{width['length']}}}{lim}{{:<{width['comment']}}}"

# print header
print(fmt.format(title[0], title[1], title[2], title[3]))

# print division
print("-"*(3*len({lim}) + width['name']+width['type']+width['length']+width['comment']))

# print rows
for row in signals:
    print(fmt.format(row["name"], row["type"], row["length"], str(row["comment"]).capitalize()))
print()