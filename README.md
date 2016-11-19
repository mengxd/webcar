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
2. Download and extract the starter code and extract to /home/pi/work/
3. cd into the webcar directory
4. Run `npm install` to install the app's dependencies
5. modify /etc/rc.local to start /home/pi/work/webcar/startApp.sh on reboot
6. Turn on your mobile phone's Wifi into hotspot mode (no need to turn on mobile 3G/4G to use your data plan)
7. Turn on your raspberry Pi 3 and check its IP address from your mobile phone hotspot management UI
7. Navigate to the website hosted on your raspberry pi 3 and enjoy it.

[Install Node.js]: https://nodejs.org/en/download/

## TODO

1. Improve the webpage to allow the direct mouse click on the direction panel
2. Create a mobile Android App to control the toycar
3. Add more control logic to allow more intelligent control of the toy car (e.g. add in sensor to detect road blocker...)
