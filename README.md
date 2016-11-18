# Web Car Project

Usage: Browse http://<raspberrypi3> on a client device to get access to the toy car.  

## Topology
Client:
  Browser == WiFi AP

Toy Car:
  Motor === L293D(stacked with Arduino) === Ardunio (UNO or Mega, connected with Pi via USB) 
  === Raspberry Pi 3 === WiFi AP

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
