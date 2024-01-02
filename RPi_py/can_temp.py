import can

# Define the CAN interface and channel (you may need to change this based on your setup)
can_interface = 'socketcan'  # Use 'socketcan' for Linux SocketCAN or 'pcan' for Windows PCAN
channel = 'can0'  # Change this to match your CAN channel

# Create a CAN bus object
bus = can.interface.Bus(channel=channel, bustype=can_interface)

# Define the CAN message
can_id = 0x123  # Change this to your desired CAN identifier
data = [0x01, 0x02, 0x03, 0x04]  # Change this to your desired data bytes

# Create a CAN message object
message = can.Message(
    arbitration_id=can_id,
    data=data,
    extended_id=False  # Set to True if using extended CAN identifiers
)

# Send the CAN message
try:
    bus.send(message)
    print(f"Sent CAN message: ID=0x{message.arbitration_id:04X}, Data={message.data}")
except can.CanError:
    print("Error sending CAN message")

# Close the CAN bus when done
bus.shutdown()
