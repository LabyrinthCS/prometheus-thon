
#include<DHT.h>
DHT dht;

int sensor_pin = A0;
int output_value;

int safe = 12;
int danger = 11;

int activate = 4;
int PIR = 7;
int buzzer = 2;

void setup() {
   Serial.begin(9600);
   pinMode(safe, OUTPUT);
   pinMode(danger, OUTPUT);
   pinMode(activate, OUTPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(PIR, INPUT);
   dht.setup(8);
   //Serial.println("Reading From the Sensor ...");
   delay(2000);
}

void loop() {
   output_value = analogRead(sensor_pin);
   output_value = map(output_value,550,0,0,100);

   int value = digitalRead(PIR); // read the signal of the PIR sensor
   //Serial.println(value);
   if (value == HIGH) {
    digitalWrite(activate, HIGH);
    digitalWrite(buzzer, HIGH);
   } else {
    digitalWrite(activate, LOW);
    digitalWrite(buzzer, LOW);
   }
   
   float humidity = dht.getHumidity();
   float temperature = dht.getTemperature();
   float tempf = temperature * 1.8 + 32;
   if (tempf <= 80 && tempf >= 50) { // suitable temperature for plants to sustain
    //Serial.println("Temperature stable");
    Serial.print("");
   } else {
    //Serial.println("Temperature unstable");
    Serial.print("");
   }   
   
   Serial.print(humidity,1);
   Serial.print(", ");
   //Serial.print(temperature,1);
   //Serial.print(", ");
   Serial.print(tempf,1);
   Serial.print(", ");   
   Serial.println(output_value);
   
   if (output_value <= -60) {
    //Serial.println("Moisture is stable");
    //Serial.print(output_value);
    digitalWrite(danger, LOW);
    digitalWrite(safe, HIGH);
   } else {
    //Serial.println("Moisture is high");
    digitalWrite(safe, LOW);
    digitalWrite(danger, HIGH);
   }
   delay(1000);
   
}
