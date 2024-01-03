# from pymodbus.client.sync import ModbusTcpClient

# from pymodbus.server import StartTcpServer
# from pymodbus.datastore import ModbusSequentialDataBlock

# # Create a Modbus data store with some example data
# store = ModbusSequentialDataBlock(0, [0] * 100)

# # Create a Modbus TCP server
# StartTcpServer(store)

from pymodbus.server import StartTcpServer
from pymodbus.datastore import ModbusSequentialDataBlock, ModbusSlaveContext, ModbusServerContext

# Create a Modbus data store with some example data
store = ModbusSlaveContext(
    di=ModbusSequentialDataBlock(0, [0] * 100),  # Discrete Inputs
    co=ModbusSequentialDataBlock(0, [0] * 100),  # Coils (Output)
    hr=ModbusSequentialDataBlock(0, [0] * 100),  # Holding Registers
    ir=ModbusSequentialDataBlock(0, [0] * 100)   # Input Registers
)

context = ModbusServerContext(slaves={1: store}, single=True)
print('created store'); 

# Create a Modbus TCP server
# StartTcpServer(context, address=("192.168.128.99", 502))  # Change IP address and port as needed


# from pymodbus.client import ModbusTcpClient

# # Modbus TCP/IP server address and port
# server_ip = '192.168.129.99'
# server_port = 502

# # Create a Modbus TCP client
# client = ModbusTcpClient(server_ip, server_port)

# # Connect to the Modbus server
# client.connect()

# # Modbus slave device address
# slave_address = '192.168.129.100'

# # Address of the holding register to read (e.g., 40001 in Modbus notation)
# register_address = 200

# # Number of registers to read
# num_registers = 1

# try:
#     # Send a Modbus message to read holding registers
#     response = client.read_holding_registers(register_address, num_registers, unit=slave_address)

#     # Check if the response is valid
#     if response.isError():
#         print(f"Modbus error: {response}")
#     else:
#         # Print the received data
#         print(f"Received data: {response.registers}")

# finally:
#     # Close the Modbus connection
#     client.close()
