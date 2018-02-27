#include <LiquidCrystal.h>
#include <DHT.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht;

#define buzz 13
#define led 7

String voice;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");

  lcd.begin(16, 2);

  pinMode(buzz, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);

  dht.setup(8);
}

void loop() {
  fluctuations();
  delay(500);
}

void fluctuations() {
  delay(1000);
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  //Serial.print(dht.getStautusString());
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.println(temperature, 1);
  if (humidity < 40 && temperature < 12) {
    lcd.setCursor(0, 0);
    lcd.print("Land your Plane");
    lcd.setCursor(5, 1);
    lcd.print("nearby");
  } else {
    saferunway();
  }
}

void beeper() {
  analogWrite(buzz, 50);
  delay(100);
  analogWrite(buzz, 0);
  delay(100);
}

void saferunway() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  //Serial.println(distance);

  if (distance < 60 && distance >= 50) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance = 50");
    //lcd.print(distance);
  } else if (distance < 50 && distance >= 40) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance = 40");
    //lcd.print(distance);
  } else if (distance < 40 && distance >= 30) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance = 30");
    //lcd.print(distance);
  } else if (distance < 30 && distance >= 20) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance = 20");
    //lcd.print(distance);
  } else if (distance < 20 && distance >= 6) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Approaching");
    lcd.setCursor(9, 1);
    lcd.print("Minimum");
    //lcd.print(distance);
  } else if (distance < 6 && distance >= 0) {
    voiceyBT();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Successful");
    //lcd.print(distance);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Signs");
    //lcd.print(distance);
  }
}

void voiceyBT() {
  while (Serial.available()) {
    delay(10);
    char chr = Serial.read();
    if (chr == '#') {
      break;
    }
    voice += chr;
  }
  int len = voice.length();
  if (len > 0) {
    if (voice == "*landed") {
      digitalWrite(led, HIGH);
    } else if (voice == "*okay" || voice == "*ok") {
      digitalWrite(led, LOW);
    }
  }
  voice = "";
}
