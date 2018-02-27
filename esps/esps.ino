#include<SoftwareSerial.h>
#include <DHT.h>

SoftwareSerial esp(2, 3);

#define ssid "LG"
#define pass "81608344"
#define IP "184.106.153.149"
//#define IP "52.5.13.84"
//#define IP "34.231.200.253"
String GET = "GET /update?api_key=KYR2N4AQUCVA0XMI&field1=";
String GET1 = "GET /update?api_key=KYR2N4AQUCVA0XMI&field2=";
DHT dht;

float humidity;
float temperature;
void setup() {
  // put your setup code here, to run once:
  esp.begin(115200);
  Serial.begin(115200);
  sendDebug("AT");
  delay(5000);
  connectWifi();
  //Serial.println("Status\tHumidity(%)\tTemperature(C)");
  dht.setup(8); // data pin 8

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(1200);
  humidity = dht.getHumidity();
  temperature = dht.getTemperature();
  updated(String(humidity));
  delay(2000);
  updated1(String(temperature));
  delay(5000);

  /*Serial.print("Humidity :");
    Serial.print(humidity,1);
    Serial.print("%");

    Serial.print("Temp:");
    Serial.print(temperature,1);
    Serial.print("C");*/
}



void sendDebug(String cmd) {
  esp.println(cmd);
  Serial.println(cmd);
}
void updated(String lm) {
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  sendDebug(cmd);
  delay(2000);
  cmd = GET;
  cmd += lm;
  cmd += "\r\n";
  String cmd2 = "AT+CIPSEND=";
  cmd2 += cmd.length();
  cmd2 += "\r\n";
  Serial.println(cmd2);
  esp.println(cmd2);
  delay(5000);
  esp.println(cmd);
  Serial.println(cmd);
  esp.println(cmd);
  delay(10000);
}

void connectWifi()
{
  Serial.println("AT+CWMODE=3");
  esp.println("AT+CWMODE=3");
  delay(2000);
  String cmd = "AT+CWJAP=\"";
  cmd += ssid;
  cmd += "\",\"";
  cmd += pass;
  cmd += "\"";
  cmd += "\r\n";
  sendDebug(cmd);
  delay(5000);
}

void updated1(String lm) {
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  sendDebug(cmd);
  delay(2000);
  cmd = GET1;
  cmd += lm;
  cmd += "\r\n";
  String cmd2 = "AT+CIPSEND=";
  cmd2 += cmd.length();
  cmd2 += "\r\n";
  Serial.println(cmd2);
  esp.println(cmd2);
  delay(5000);
  esp.println(cmd);
  Serial.println(cmd);
  esp.println(cmd);
  delay(10000);
}

