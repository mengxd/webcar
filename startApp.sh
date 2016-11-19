#!/bin/bash

while !(ifconfig wlan0|grep Bcast>/dev/null); do 
echo 'wlan0 not ready, waiting...'
sleep 10

done

echo 'wlan0 has been configured, starting web services...'

sudo node /home/pi/work/webcar/app.js 2>&1 > /dev/null &
sudo python /home/pi/work/webcar/car.py 2>&1 > /dev/null &

exit 0
