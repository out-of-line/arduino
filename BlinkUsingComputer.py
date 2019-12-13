import serial
import time

arduino = serial.Serial('COM25', 9600)
time.sleep(2) # waiting the initialization...
print("Initialising Serial Connection")

while True:
    arduino.write('H') # turns LED ON
    print("Computer : LED ON")
    time.sleep(1) # waits for 1 second
    arduino.write('L') # turns LED OFF
    print("Computer : LED OFF")
    time.sleep(1) # waits for 1 second