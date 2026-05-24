# ESP32 LoRa Communication

Project test giao tiếp LoRa SX1278 giữa:

- ESP32-C3 Super Mini
- ESP32 V1

## Hardware

### ESP32-C3
| SX1278 | GPIO |
|---|---|
| MISO | GPIO5 |
| MOSI | GPIO6 |
| SCK | GPIO4 |
| NSS | GPIO7 |
| RST | GPIO8 |
| DIO0 | GPIO9 |

### ESP32 V1
| SX1278 | GPIO |
|---|---|
| SCK | GPIO18 |
| MISO | GPIO19 |
| MOSI | GPIO23 |
| NSS | GPIO5 |
| RST | GPIO14 |
| DIO0 | GPIO27 |

## Features

- LoRa send/receive
- Serial communication
- RSSI monitor

## Library

- LoRa by Sandeep Mistry
