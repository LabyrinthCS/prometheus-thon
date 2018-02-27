#include<Servo.h>
Servo servo;
int a=8;
void setup() {
  // put your setup code here, to run once:
  servo.attach(7);
  pinMode(a,INPUT);
}

void loop() {
  int b=digitalRead(a);
if(b==1)
{
  servo.write(0);
  delay(500);
  servo.write(30);
  delay(500);
    servo.write(60);
    delay(500);
  servo.write(90);
  delay(500);
    servo.write(120);
    delay(500);
  servo.write(150);
  delay(500);
    servo.write(180);
}
else
{
  servo.write(0);
  delay(200);
}
}
