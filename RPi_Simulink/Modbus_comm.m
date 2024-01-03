% clear all; 
% clc; 
% close all; 

m = modbus('tcpip', '192.168.128.29', 502,'ByteOrder','little-endian',  ...
    'NumRetries',1, 'Timeout',10, 'WordOrder','little-endian'); 

% moddata = read(m,target,address,count,serverId,precision) 
% specifies both the address of the server and the data format precision of the register.

% Read 8 holding registers starting at address 1 using a precision of 'uint32' from Server ID 3.
moddata = read(m,'holdingregs',4113,8,1,'single');

