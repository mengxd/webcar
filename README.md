# Web Car Project

Usage: Visit the web server hosted on the raspberry pi 3 from a client device to get access to the toy car.  

## Topology
Client:
  Browser == WiFi AP

Toy Car:
  Motor === L293D(stacked with Arduino) === Ardunio (UNO or Mega, connected with Pi via USB) 
  === Raspberry Pi 3(runs webcar node.js app and the car.py program) === WiFi AP

-The L293D controls the movement and speed of the DC motors, which in turn drives the car 
-The Arduino receives command from the serial and instructs L293D motor controller to take corresponding actions 
-The car.py communicates with Arduino via the serial interface over USB connection.
-The car.py communicate with webcar node.js App via the WebSocket
-And the operator controls the toycar from the web UI exposed by webcar node.js App

## Run the app locally

1. [Install Node.js][]
2. Download and extract the starter code from the Bluemix UI
3. cd into the app directory
4. Run `npm install` to install the app's dependencies
5. Run `npm start` to start the app
6. Run `python car.py` to start the python program that receives input and sends command to Arduino
7. Access the running app in a browser at http://192.168.2.102

[Install Node.js]: https://nodejs.org/en/download/

## TODO

1. Improve the webpage to allow the direct mouse click on the direction panel
2. Improve the program to allow peer-to-peer communication between the client device and the raspberry Pi to get rid of
the dependency on a Wi-Fi AP.
3. Add more control logic to allow more intelligent control of the toy car (e.g. add in sensor to detect road blocker...)
