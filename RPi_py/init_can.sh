#!/bin/bash

sudo modprobe spi-bcm2835
sudo modprobe can
sudo modprobe can-dev
sudo modprobe can-raw
sudo modprobe mcp251x

sudo ip link set can0 type can bitrate 500000
sudo ip link set up can0

python3 send_can.py 