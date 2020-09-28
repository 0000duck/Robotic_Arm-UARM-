#include <Servo.h> //add servo library. this library is standard library

//define the servos
Servo servo1;
Servo servo2;
Servo servo3;

//define the buttons
const int button1 = 3;
const int button2 = 4;

//define variable for values of the button
int button1Pressed = 0;
boolean button2Pressed = false;

//define potentiometers
const int pot1 = A0;
const int pot2 = A1;
const int pot3 = A2;

//define variable for values of the potentiometers
int pot1Val;
int pot2Val;
int pot3Val;

//define variable for angles of the potentiometer
int pot1Angle;
int pot2Angle;
int pot3Angle;

//define variable for saved position of the servos
int servo1PosSave[]={1,1,1,1,1};
int servo2PosSave[]={1,1,1,1,1};
int servo3PosSave[]={1,1,1,1,1};

void setup() {
  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  pot1Val = analogRead(pot1);
  pot1Angle = map (pot1Val, 0, 1023, 0, 179);
  pot2Val = analogRead(pot2);
  pot2Angle = map (pot2Val, 0, 1023, 0, 179);
  pot3Val = analogRead(pot3);
  pot3Angle = map (pot3Val, 0, 1023, 0, 90);

  servo1.write(pot1Angle);
  servo2.write(pot2Angle);
  servo3.write(pot3Angle);

  
  if(digitalRead(button1) == HIGH){
    button1Pressed++;
    switch(button1Pressed){
      case 1:
        servo1PosSave[0] = pot1Angle;
        servo2PosSave[0] = pot2Angle;
        servo3PosSave[0] = pot3Angle;
        Serial.println("Position #1 Saved");
       break;
       case 2:
        servo1PosSave[1] = pot1Angle;
        servo2PosSave[1] = pot2Angle;
        servo3PosSave[1] = pot3Angle;
        Serial.println("Position #2 Saved");
       break;
       case 3:
        servo1PosSave[2] = pot1Angle;
        servo2PosSave[2] = pot2Angle;
        servo3PosSave[2] = pot3Angle;
        Serial.println("Position #3 Saved");
       break;
       case 4:
        servo1PosSave[3] = pot1Angle;
        servo2PosSave[3] = pot2Angle;
        servo3PosSave[3] = pot3Angle;
        Serial.println("Position #4 Saved");
       break;
       case 5:
        servo1PosSave[4] = pot1Angle;
        servo2PosSave[4] = pot2Angle;
        servo3PosSave[4] = pot3Angle;
        Serial.println("Position #5 Saved");
       break;
    }
  }
 
  if(digitalRead(button2) == HIGH){
    button2Pressed = true;
  }
  if(button2Pressed){
    for(int i=0; i<5; i++){
      servo1.write(servo1PosSave[i]);
      servo2.write(servo2PosSave[i]);
      servo3.write(servo3PosSave[i]);
      delay(2000);
    }
  }
  delay(500);
}
