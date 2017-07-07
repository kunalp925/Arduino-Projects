#include <AFMotor.h> //requires the AFMotor.h library

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int input=0;


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
 
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  motor4.setSpeed(200);
  motor4.run(RELEASE);
}


void loop() {
  if(Serial.available()){ // make sures that the Serial is available to recieve input
    input=Serial.read();
    Serial.println(input);
    if(input==102){  //102 is the ASCII value for 'f'
      forward(motor1,motor2,motor3,motor4);
      delay(1000);  //delay dictates the lenght of time that the motor will run for
      stopMotor(motor1,motor2,motor3,motor4);
    }
    if(input==98){  //98 is the ASCII value for 'b'
      reverse(motor1,motor2,motor3,motor4);
      delay(1000);
      stopMotor(motor1,motor2,motor3,motor4);
    }
    if(input==108){  //108 is the ASCII value for 'l'
      left(motor1,motor2,motor3,motor4);
      delay(1000);
      stopMotor(motor1,motor2,motor3,motor4);
    }
    if(input==114){  //114 is the ASCII value for 'r'
      right(motor1,motor2,motor3,motor4);
      delay(1000);
      stopMotor(motor1,motor2,motor3,motor4);
    }
    if(input==97){  //97 is the ASCII value for 'a'
      stopMotor(motor1,motor2,motor3,motor4);
      delay(1000);
    }
  }
}

void stopMotor(AF_DCMotor m1, AF_DCMotor m2, AF_DCMotor m3, AF_DCMotor m4){
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}

void forward(AF_DCMotor m1, AF_DCMotor m2, AF_DCMotor m3, AF_DCMotor m4){
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void reverse(AF_DCMotor m1, AF_DCMotor m2, AF_DCMotor m3, AF_DCMotor m4){
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void left(AF_DCMotor m1, AF_DCMotor m2, AF_DCMotor m3, AF_DCMotor m4){
  m1.run(BACKWARD);
  m4.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
}

void right(AF_DCMotor m1, AF_DCMotor m2, AF_DCMotor m3, AF_DCMotor m4){
  m1.run(FORWARD);
  m4.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
}



