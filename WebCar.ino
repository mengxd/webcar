// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

//Left side
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);

//Right side
AF_DCMotor motor1(1);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor1.setSpeed(255);
  motor4.setSpeed(255);    

  motor2.setSpeed(255);
  motor3.setSpeed(255);
}

// duration for output
int time = 800;
int time1 = 500;
int command = 0;


void loop() {
  if (Serial.available() > 0){
    command = Serial.read();
    Serial.print(command);
    enableMotors();
  }
  else{
    reset();
  }
  send_command(command,time);
}

void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 1: forward(time); break;
     case 2: backward(time); break;
     case 3: turnRight(time1); break;
     case 4: turnLeft(time1); break;

     default: Serial.print("Inalid Command\n");
    }
}

void reset() {
  disableMotors();
  enableMotors();  
}
 
void enableMotors(){
  motor1.setSpeed(255);
  motor4.setSpeed(255);    

  motor2.setSpeed(255);
  motor3.setSpeed(255);  
}

void disableMotors(){
  motor1.run(RELEASE);
  motor4.run(RELEASE);  

  motor2.run(RELEASE);
  motor3.run(RELEASE);  
}

//Define high-level H-bridge commands
 
void forward(int time)
{
  motor1.run(FORWARD);
  motor4.run(FORWARD);

  motor2.run(FORWARD);
  motor3.run(FORWARD);
  delay(time);
}
 
void backward(int time)
{
  motor1.run(BACKWARD);
  motor4.run(BACKWARD);

  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  delay(time);
}
 
void turnRight(int time)
{
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);

  motor1.run(FORWARD);
  motor4.run(FORWARD);
  delay(time);
}
 
void turnLeft(int time)
{
  motor2.run(FORWARD);
  motor3.run(FORWARD);

  motor1.run(BACKWARD);
  motor4.run(BACKWARD);
 delay(time);
}

void brake(int time)
{
  motor1.setSpeed(0);
  motor4.setSpeed(0);    

  motor2.setSpeed(0);
  motor3.setSpeed(0); 
  
  delay(time);
  enableMotors();
}


