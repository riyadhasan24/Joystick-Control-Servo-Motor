#include <Servo.h>

#define SW_Pin 2
#define X_Pin A0
#define Y_Pin A1
#define Led_Pin 13

int X_Value;
int Y_Value;
int SW_State;
int X_Servo_Pos;
int Y_Servo_Pos;


Servo X_Servo;
Servo Y_Servo;

void setup()
{
  Serial.begin(9600);
  pinMode(SW_Pin, INPUT);
  pinMode(X_Pin, INPUT);
  pinMode(Y_Pin, INPUT);
  pinMode(Led_Pin, OUTPUT);
  digitalWrite(SW_Pin, HIGH);
  X_Servo.attach(6);
  Y_Servo.attach(9);
}

void loop()
{
  SW_State = digitalRead(SW_Pin);

  X_Value = analogRead(X_Pin);
  Y_Value = analogRead(Y_Pin);
  
  X_Servo_Pos = map(X_Value, 0, 1023, 0, 180);
  Y_Servo_Pos = map(Y_Value, 0, 1023, 0, 180);

  if (SW_State == LOW)
  {
    digitalWrite(Led_Pin, HIGH);
  }
  else
  {
    digitalWrite(Led_Pin, LOW);
  }

  X_Servo.write(X_Servo_Pos);
  Y_Servo.write(Y_Servo_Pos);

}