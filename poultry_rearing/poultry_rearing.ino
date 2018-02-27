#include <DHT.h>
DHT dht;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature(); // temperature in celsius
  float tempf = temperature * 1.8 + 32;
  /*
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity,1);
  Serial.print("\t\t");
  Serial.print(temperature,1);
  Serial.print("\t");
  Serial.println(tempf,1);
  */
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
    if (voice == "*temprature") {
      if (temperature <= 34 && temperature >= 20) { // recommended temperatures for broilers
       digitalWrite(led, HIGH); 
      } else {
        digitalWrite(led, LOW);
      }
    } else if (voice == "*okay" || voice == "*ok") {
      digitalWrite(led, LOW);
    }
  }
  voice = "";
}

