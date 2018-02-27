#include <SoftwareSerial.h>
#include<LiquidCrystal.h>

SoftwareSerial GPRS(7,8);
LiquidCrystal lcd(12,11,5,4,3,2);

const int ledPin=13;
const int ldrPin=A0;


void setup() {
  // put your setup code here, to run once:
  GPRS.begin(9600);
Serial.begin(9600);
lcd.begin(16,2);
pinMode(ledPin,OUTPUT);
pinMode(ldrPin,INPUT);

GPRS.println("AT");
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
while(GPRS.available()){
  Serial.write(GPRS.read());
  }
  
int ldrStatus=analogRead(ldrPin);
if(ldrStatus>=700)
{
  sendSMS();
  digitalWrite(ledPin,HIGH);
  lcd.begin(16,2);
  lcd.print("ANOOP..");
  lcd.print("it's DARK ");
  }
  else
  {
  digitalWrite(ledPin,LOW);
   lcd.begin(16,2);
   lcd.print("ANOOP.");
  lcd.print("it's LIGHT");  
    }

  // put your main code here, to run repeatedly:
int SensorValue= analogRead(A1);
if(SensorValue>=950)
{
 lcd.setCursor(0,1);
lcd.print("Moderate Moisture"); 
  }
else
{
  senddSMS();
   lcd.setCursor(0,1);
lcd.print("high Moisture");
  }
delay(100);
}

void sendSMS()
{
    GPRS.println("AT+CMGF=1");
  delay(500);

  GPRS.println("AT+CMGS=\"+917907519269\"");
  delay(500);
  GPRS.print("It's too dark.");
  GPRS.write(0x1a);
  }

  void senddSMS()
{
    GPRS.println("AT+CMGF=1");
  delay(500);

  GPRS.println("AT+CMGS=\"+917907519269\"");
  delay(500);
  GPRS.print("Moisture content is too high");
  GPRS.write(0x1a);
  }
