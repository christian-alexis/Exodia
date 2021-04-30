//ARDUINO CARRO SEGUIDOR DE LINEA//

 
//INCLUIMOS LA LIBRERIA 
#include <AFMotor.h>

//definicion pins y variables
#define left A0
#define right A1

//definicion de motores
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);


 
void setup() {
  //declaramos el tipos de pines (entranda)
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  // nos muestra los valores de los sensores en pantalla
  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));

  if(digitalRead(left)==0 && digitalRead(right)==0){
    //adelante
    motor1.run(FORWARD);
    motor1.setSpeed(150);
    motor2.run(FORWARD);
    motor2.setSpeed(150);
    motor3.run(FORWARD);
    motor3.setSpeed(150);
    motor4.run(FORWARD);
    motor4.setSpeed(150);
  }
  
  else if(digitalRead(left)==0 && digitalRead(right)==1){
    //izquierda
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(BACKWARD);
    motor3.setSpeed(200);
    motor4.run(BACKWARD);
    motor4.setSpeed(200);
    
  }
  
  else if(digitalRead(left)==1 && digitalRead(right)==0){
    //derecha
    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(BACKWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
   
  }
  // no detecta ninguna linea
  else if(digitalRead(left)==1 && digitalRead(right)==1){
    //alto
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
   
  }
  
}
