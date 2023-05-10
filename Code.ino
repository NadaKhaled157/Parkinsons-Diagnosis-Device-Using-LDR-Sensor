#include <LiquidCrystal.h>

#define greenLed 4
#define redLed 2 
#define sensorPin A0

int sensorValue=0;

// Characteristics related to LDR
const float GAMMA = 0.7;
const float RL10 = 50;
const float time=10;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("Initialization...");
 delay(1000);
 pinMode(greenLed,OUTPUT);
 pinMode (redLed, OUTPUT);
 pinMode(sensorPin, INPUT);
 digitalWrite(greenLed,LOW);
 digitalWrite(redLed, LOW);

}

void loop() {
  Serial.println("Initialization...");
  Serial.println("Start testing: ");
  delay(5000);
  for(int i=0; i<=10;i++){
 int analogValue = analogRead(A0);
float voltage = analogValue / 1024. * 5;
float resistance = 2000 * voltage / (1 - voltage / 5);
float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

Serial.println();
Serial.print("Current Illumination= ");
Serial.print(lux);
Serial.print(" lux");

delay(1000);
lcd.setCursor(0,0);
lcd.print("Patient Status: " );
lcd.setCursor(0,1);
lcd.print("Testing");

Serial.println();
// Serial.print("Patient Status: " );
// Serial.println("Testing");

 if(lux>=200){
    digitalWrite(greenLed,HIGH);
   digitalWrite(redLed, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Patient Status: ");
    lcd.setCursor(0,1);
    lcd.print("Testing ");
    lcd.print(" 00:0");
    lcd.print(i);

    Serial.print("Patient Status: ");
    Serial.println("Testing ");
    Serial.print(" 00:0");
    Serial.print(i);

    if(i==10){
   digitalWrite(greenLed,HIGH);
   digitalWrite(redLed, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Patient Status: ");
    lcd.setCursor(0,1);
    lcd.print("Passed");

    Serial.println();
    // Serial.print(" 00:");
    // Serial.print(i);
    Serial.print("Patient Status: ");
    Serial.println("Passed");

    delay(3000);
    
    }
  }
  else{
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Patient Status: ");
    Serial.print("Patient Status: ");
    delay (4000);
    Serial.println("Failed");
    lcd.setCursor(0,1);
    lcd.print("Failed");
   
    Serial.println();
    
  

    delay(3000);
    break;
  }
}
delay(7000);
}
