
#include <AFMotor.h>
#define trigPin 13 // define the pins of your sensor
#define echoPin 12
//creates two objects to control the terminal 3 and 4 of motor shield 
AF_DCMotor motor1(2); 
AF_DCMotor motor2(1); 
int speed = 255;
char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.

  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
}

void loop(){
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration, distance;
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  if (distance < 25){
    back(speed);
  }
  else{ 
  Serial.println(command);
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    switch(command){
      Serial.println(command);
      case 'F':
        forward(speed);
        Serial.println(command);
        Serial.println(speed);
        break;
      case 'B':  
        back(speed);
        break;
      case 'L':  
        left(speed);
        break;
      case 'R':
        right(speed);
        break;
      case 'G':
        forwardleft(speed);
        break;
      case 'I':
        forwardright(speed);
        break;
      case 'H':
        backleft(speed);
        break;
      case 'J':
        backright(speed);
        break;
///////////setspeed////////        
      case '1':
        speed=100;
        break;
      case '2':
        speed=120;
        break;
      case '3':
        speed=140;
        break;
      case '4':
        speed=160;
        break;
      case '5':
        speed=180;
        break;
      case '6':
        speed=200;
        break;
      case '7':
        speed=220;
        break;
      case '8':
        speed=235;
        break;
      case '9':
        speed=245;
        break;
      case 'q':
        speed=255;
        break;  
    }
  } 
}
}

void forward(int speed)
{
   motor1.setSpeed(speed); //Define maximum velocity
   motor1.run(FORWARD); //rotate the motor clockwise
   motor2.setSpeed(speed); //Define maximum velocity
   motor2.run(FORWARD); //rotate the motor clockwise
}

void back(int speed)
{
  motor1.setSpeed(speed); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(speed); 
  motor2.run(BACKWARD); //rotate the motor counterclockwise
}

void left(int speed)
{
  motor1.setSpeed(speed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}

void right(int speed)
{
  motor1.setSpeed(0);
  motor1.run(RELEASE); //turn motor1 off
  motor2.setSpeed(speed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}

void forwardleft(int speed)
{
  int speed2= speed/2;
  motor1.setSpeed(speed); 
  motor1.run(FORWARD);
  motor2.setSpeed(speed2);
  motor2.run(FORWARD);
  Serial.println(speed);
  Serial.println(speed2);
}

void forwardright(int speed)
{
  int speed2= speed/2;
  motor1.setSpeed(speed2); 
  motor1.run(FORWARD);
  motor2.setSpeed(speed);
  motor2.run(FORWARD);
}

void backleft(int speed)
{
  int speed2= speed/2;
  motor1.setSpeed(speed); 
  motor1.run(BACKWARD);
  motor2.setSpeed(speed2);
  motor2.run(BACKWARD);
}

void backright(int speed)
{
  int speed2= speed/2;
  motor1.setSpeed(speed2); 
  motor1.run(BACKWARD);
  motor2.setSpeed(speed);
  motor2.run(BACKWARD);
}

