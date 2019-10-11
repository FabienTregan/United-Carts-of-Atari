# Atari 2600 PlusCart

## Description
the Atari 2600 PlucCart ist based upon Robin Edwards Unocart-2600 (https://github.com/robinhedwards/UnoCart-2600). The PlusCart has no SD-Card, but an ESP8266 to connect to a local WiFi Network and the Internet.
The PlusCart downloads the ROM-files from an Server in the Internet called the "PlusStore". The way this is done is similar to the way the Unocart-2600 loads ROMs from the FAT filesystem on the SD-card.

Additionally  the PlusCart has one more ROM emulator routine to emulate online ROMs called "PlusROM".
In the first bytes of the PlusROM the backend hostname or IP-Adress has to be encoded (as string terminated by '\0'). Sending and receiving bytes to the host does not need a waitroutine in the VCS RAM!
At the moment the PlusROM is a normal 4K cartrige with 4 special adresses (before the bankswitching area):
- $fff0 is for writing a byte to the send buffer (max 256 bytes)
- $fff1 is for writing a byte to the send buffer and submit the buffer to the Backend API
- $fff2 contains the response from the host in a receive buffer (max 255 bytes !) 
- $fff3 contains the receive buffer size

The bytes are send to the backend as content of an HTTP 1.0 POST request with "Content-Type: application/octet-stream". The response of the backend should also be a "Content-Type: application/octet-stream" and the response-body should contain the payload and the first byte of the response should be the length of the payload, so "Content-Length" is payload + 1 byte. This is a workaround, because we don't have enough time in the emulator routine to analyse the "Content-Length" header of the response.

These definitions may (or certainly will) change in the future. Especially bankswitching and RAM should be added to the PlusROM definition (depending on the suggestions of experienced VCS Programmer).

## To-do and ..
- clean up the code and publish under GPL v3
- Where and who wants to host the PlusStore ?
- Use STM UniqueDeviceID in Requests to PlusStore and PlusROM Backend (User-Agent header?)
- Fota ?
- Test Uploadform for PlusROMs
- switch to HTTP 1.1 and parse chunked responses..
- switch to https ?
- 

## Installation
The GPIOs of the STM32 board are connected similar to the Unocart-2600 except for the SD card. The ESP8266 is connected to USART1 (PA9 TX and PA10 RX ) of the STM32 Board.

## Software
- STM32CubeIDE
- STM32CubeProgrammer

## Hardware:
- STM32F407VGT6 breakout board (https://www.diymore.cc/products/stm32f4-discovery-stm32f407vgt6-microcontroller-32bit-flash-mcu-arm-cortex-m4-core-development-board?_pos=7&_sid=3f87534b6&_ss=r)
- ESP8266 

Copyright:
(c) Firmaplus(+) Ltd.
Dipl.Ing.(FH) Wolfgang Stubig