# Arduino-Light-Control
A python script that controls a multi-color LED attached to an Arduino. 
## Overview
I have an Arduino Uno with an ethernet shield attached. The Arduino is running a script that listens to commands sent over UDP to a specified ip and port. I also have a python script that sends the commands. The Arduino will read in the message and change the color of an LED depending on what it has recieved. 

## Setup
Hardware
This was made using a 3rd party Arduino Ethernet Shield V2. Different shields use different pins so you may need to change what pins you are using for the RGB LED. In my case, I used pin 8, A0, and A1. Place the shield on top of the Arduino and connect the LED to the Arduino as diagrammed below. 

Once that is all connected, use the Arduino IED to load the ino file to the Arduino. Plug the Arduino into power and an ethernet connection. 

Software
The python script sends commands to the Arduino. Download the script, navigate to its directory and use the command `python3 arduino_controller` to run the script. 


## Screenshots
![Screenshot of python script running](python-script.png)


## Helpful Websites
[Arduino Ethernet Shield V2 Documentation](https://www.arduino.cc/en/Main/ArduinoEthernetShieldV2)

[Stack Overflow Post](https://stackoverflow.com/questions/18743962/python-send-udp-packet#18746406)



