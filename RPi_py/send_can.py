
# from pymodbus.client.sync import ModbusTcpClient

from pymodbus.client import ModbusTcpClient

# Define the Modbus TCP/IP server address and port
server_ip = '192.168.129.99'  # Replace with the IP address of your Modbus server
server_port = 502  # Default Modbus TCP/IP port

# Create a Modbus TCP/IP client
client = ModbusTcpClient(server_ip, server_port)

try:
    # Connect to the Modbus server
    client.connect()

    # Read a holding register (you can change the address and quantity)
    result = client.read_holding_registers(0, 1, unit=1)

    if result.isError():
        print(f"Error reading Modbus data: {result.message}")
    else:
        data = result.registers[0]
        print(f"Read data: {data}")

except Exception as e:
    print(f"An error occurred: {e}")
finally:
    # Close the Modbus TCP/IP client connection
    client.close()

# SEND The recieved modbus msg as a CAN msg 

import can
# Create a CAN bus interface
bus = can.interface.Bus(channel='can0', bustype='socketcan')

# Create a CAN message
message = can.Message(
    arbitration_id=0x123,  # Arbitration ID
    data=[0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08],  # Data bytes
    extended_id=False  # Standard CAN frame
)

# Send the CAN message
bus.send(message)

message = "CAM MSG SENT"
print(message)

