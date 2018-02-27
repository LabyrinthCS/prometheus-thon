int led[] = {4,5,6,7,8,9,10,11,12,13};
int pir = 3;
int buzz = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir, INPUT);
  pinMode(buzz, OUTPUT);
  for (int i = 0; i < 10; i++) {
    digitalWrite(led[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(pir);
  if (val == HIGH) {
    digitalWrite(buzz, HIGH);
    for (int i = 0; i < 10; i+=1) {
      digitalWrite(led[i], HIGH);
      delay(100);
      digitalWrite(led[i], LOW);
    }
    /*digitalWrite(led[0], HIGH);
    digitalWrite(led[0], HIGH);
    digitalWrite(led[0], HIGH);*/
  } else {
    //digitalWrite(led, LOW);
    digitalWrite(buzz, LOW);
  }
}
