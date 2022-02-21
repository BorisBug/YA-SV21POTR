/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief UART Over BLE.
 *        Install Bluetooth for Arduino on your phone
 *        Connect to UART_OVER_BLE and then open terminal and send a message.
 *        The message will be converted to uppercase and returned to your phone.
 * @version 0.1
 * @date 2021-04-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>
#include <BLEDevice.h>

#define STRLEN (16U)

static char string[STRLEN] = {0};
static volatile bool ready = false;
static bool deviceConnected = false;
static BLECharacteristic *txCharacteristic;

// UUIDs from https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v14.0.0%2Fble_sdk_app_nus_eval.html
#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"           // UART Over BLE Service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E" // Charactristic UUID for WRITE
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E" // Charactristic UUID for READ and NOTIFY

class ServerCallbacks : public BLEServerCallbacks
{
    void onConnect(BLEServer *pServer)
    {
        ready = false;
        deviceConnected = true;
    }

    void onDisconnect(BLEServer *pServer)
    {
        deviceConnected = false;
    }
};

class CharactristicCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic)
    {
        std::string rxValue = pCharacteristic->getValue();

        bzero(string, STRLEN);
        for (uint8_t i = 0; i < STRLEN - 1; i++)
        {
            string[i] = toupper(rxValue.c_str()[i]);
        }

        ready = true;
    }
};

void setup()
{
    Serial.begin(9600);
    delay(2000);

    pinMode(LED_BUILTIN, OUTPUT);

    // Create the BLE Device
    BLEDevice::init("UART_OVER_BLE");

    // Create the BLE Server
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new ServerCallbacks());

    // Create the BLE Service
    BLEService *pService = pServer->createService(SERVICE_UUID);

    // Create a BLE Characteristic for TX
    txCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);

    // Create a BLE Characteristic for RX
    BLECharacteristic *rxCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);

    rxCharacteristic->setCallbacks(new CharactristicCallbacks());

    // Start the service
    pService->start();

    // Start advertising
    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->start();

    Serial.println("Waiting a client connection to notify...");
}

void loop()
{
    if (deviceConnected && ready)
    {
        txCharacteristic->setValue(string);
        txCharacteristic->notify(); // Send the value to the client!
        ready = false;
    }
}