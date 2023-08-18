echo off

mode
rem see all ports.
mode com4 baud=96 data=8 parity=n stop=1 dtr=on
rem set configuration for serial port com4

echo "Hello" > com4
rem send string ("Hello") to serial port com4
type COM4
rem Read from serial port com4 and print it into the command window.
pause