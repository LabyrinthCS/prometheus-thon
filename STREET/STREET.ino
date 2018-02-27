int ir1 = 3;
int ir2 = 2;

int led1 = 7;
int led2 = 6;

int proxy1 = 0;
int proxy2 = 0;

void setup() {
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  proxy1 = digitalRead(ir1);
  proxy2 = digitalRead(ir2);

  if (proxy1 == LOW) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  } if (proxy2 == LOW) {
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}

