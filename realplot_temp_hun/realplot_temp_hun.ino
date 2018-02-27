#include <DHT.h>

DHT dht;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(dht.getMinimumSamplingPeriod());
  float hum = dht.getHumidity();
  float temp = dht.getTemperature();
  //Serial.print(dht.getStatusString());
  //Serial.print();
  Serial.print(hum,1);
  Serial.print(", ");
  Serial.print(temp,1);
  Serial.print(", ");
  Serial.println(dht.toFahrenheit(temp),1);
}
