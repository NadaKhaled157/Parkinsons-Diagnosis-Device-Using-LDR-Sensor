#include <LiquidCrystal.h>

#define sensorOnePin A0
#define sensorTwoPin A1
#define sensorThreePin A2

#define ledOne 6
#define ledTwo 7
#define ledThree 8

LiquidCrystal lcd (12,11,5,4,3,2);
 
 int sensorOneValue=0;
 int sensorTwoValue=0;
 int sensorThreeValue=0;

 const float GAMMA = 0.7;
 const float RL10 = 50;
 const float time=10;
 int count=0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Stage Two: ");
  delay (2000);
  lcd.clear();
  lcd.print("Begin Testing...");
  delay(2000);
  lcd.clear();
  pinMode(sensorOnePin, INPUT);
  pinMode(sensorTwoPin,INPUT);
  pinMode (sensorThreePin, INPUT);

  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo,OUTPUT);
  pinMode(ledThree, OUTPUT);

//   digitalWrite(ledOne,HIGH);
//  digitalWrite(ledTwo, HIGH);
//  digitalWrite(ledThree,HIGH);

}

void loop() {

 //sensorOneValue= analogRead(A0);
//  sensorTwoValue= analogRead(A1);
//  sensorThreeValue= analogRead(A2);

//  float voltageOne = sensorOneValue / 1024. * 5;
//  float resistanceOne = 2000 * voltageOne / (1 - voltageOne / 5);
//  float luxOne = pow(RL10 * 1e3 * pow(10, GAMMA) / resistanceOne, (1 / GAMMA));

//  float voltageTwo = sensorTwoValue / 1024. * 5;
//  float resistanceTwo = 2000 * voltageTwo / (1 - voltageTwo / 5);
//  float luxTwo = pow(RL10 * 1e3 * pow(10, GAMMA) / resistanceTwo, (1 / GAMMA));

//  float voltageThree = sensorThreeValue / 1024. * 5;
//  float resistanceThree = 2000 * voltageThree / (1 - voltageThree / 5);
//  float luxThree = pow(RL10 * 1e3 * pow(10, GAMMA) / resistanceThree, (1 / GAMMA));

 delay (100);

//first sensor
Serial.println("TEST 1");
       lcd.clear();
       lcd.print("Test One: ");
    delay(5000);
 for(int i=0;i<=5;i++){
    
   sensorOneValue= analogRead(A0);
   float voltageOne = sensorOneValue / 1024. * 5;
  float resistanceOne = 2000 * voltageOne / (1 - voltageOne / 5);
  float luxOne = pow(RL10 * 1e3 * pow(10, GAMMA) / resistanceOne, (1 / GAMMA));

 Serial.println();
Serial.print("Current Illumination= ");
Serial.print(luxOne);
Serial.println(" lux");

delay(100); //one second

  if (luxOne>500){
   Serial.print("00:0");
   Serial.println(i);

   lcd.clear();
   lcd.print("Test One: ");
   lcd.setCursor(0,1);
   lcd.print("00:0");
   lcd.print(i);
   delay(1000);

   digitalWrite(ledOne, HIGH);
   digitalWrite (ledTwo, LOW);
   digitalWrite (ledThree, LOW);

   if(i==5){
     count=count+1;
     Serial.println("TEST ONE: PASSED");
       lcd.clear();
       lcd.print("TEST ONE: ");
       lcd.setCursor(0,1);
       lcd.print("PASSED");
       delay (2000);
       lcd.clear();
   }
 } 
 else {
   digitalWrite(ledOne, LOW);
   digitalWrite(ledTwo, LOW);
   digitalWrite (ledThree, LOW);

   lcd.clear();
   lcd.print("Test One: ");
  delay (2000);
    Serial.println("TEST ONE: FAILED");
      lcd.clear();
      lcd.print("TEST ONE: ");
       lcd.setCursor(0,1);
       lcd.print("FAILED");
       delay (2000);
       lcd.clear();
    break;
 }
 }
 delay(4000);
 //test 2
 Serial.println("TEST 2");
       lcd.clear();
       lcd.print("Test Two: ");
    delay(5000);
  for(int i=0;i<=5;i++){
    

   sensorTwoValue= analogRead(A1);
   float voltageTwo = sensorTwoValue / 1024. * 5;
 float resistanceTwo = 2000 * voltageTwo / (1 - voltageTwo / 5);
 float luxTwo = pow(RL10 * 1e3 * pow(10, GAMMA) / resistanceTwo, (1 / GAMMA));

 Serial.println();
Serial.print("Current Illumination= ");
Serial.print(luxTwo);
Serial.println(" lux");

delay(1000); //one second

  if (luxTwo>500){
   Serial.print("00:0");
   Serial.println(i);

   lcd.clear();
   lcd.print("Test Two: ");
   lcd.setCursor(0,1);
   lcd.print("00:0");
   lcd.print(i);
   delay(1000);

   digitalWrite(ledTwo, HIGH);
   digitalWrite (ledOne, LOW);
   digitalWrite (ledThree, LOW);

   if(i==5){
     count=count+1;
     Serial.println("TEST TWO: PASSED");
       lcd.clear();
       lcd.print("TEST TWO: ");
       delay(2000);
       lcd.setCursor(0,1);
       lcd.print("PASSED");
       delay (2000);
       lcd.clear();
   }
 } 
 else {
   digitalWrite(ledOne, LOW);
   digitalWrite(ledTwo, LOW);
   digitalWrite (ledThree, LOW);
   lcd.clear();
   lcd.print("Test Two: ");
   delay (2000);
    Serial.println("TEST TWO: FAILED");
     lcd.clear();
    lcd.print("TEST TWO: ");
       lcd.setCursor(0,1);
       lcd.print("FAILED");
       delay (2000);
       lcd.clear();
    break;
 }
 }
 delay(4000);
 lcd.clear();

  //test 3
 Serial.println("TEST 3");
       lcd.clear();
       lcd.print("Test Three: ");
    delay(5000);
  for(int i=0;i<=5;i++){
    

   sensorThreeValue= analogRead(A2);
   float voltageThree = sensorThreeValue / 1024. * 5;
 float resistanceThree = 2000 * voltageThree / (1 - voltageThree / 5);
 float luxThree = pow(RL10 * 1e3 * pow(10, GAMMA) / resistanceThree, (1 / GAMMA));

 Serial.println();
Serial.print("Current Illumination= ");
Serial.print(luxThree);
Serial.println(" lux");

delay(1000); //one second

  if (luxThree>500){
   Serial.print("00:0");
   Serial.println(i);
   lcd.clear();
   lcd.print("Test Three: ");
   lcd.setCursor(0,1);
   lcd.print("00:0");
   lcd.print(i);
   delay(1000);

   digitalWrite(ledThree, HIGH);
   digitalWrite (ledOne, LOW);
   digitalWrite (ledTwo, LOW);

   if(i==5){
     count=count+1;
     Serial.println("TEST THREE: PASSED");
       lcd.clear();
       lcd.print("TEST THREE: ");
       lcd.setCursor(0,1);
       lcd.print("PASSED");
       delay (2000);
       lcd.clear();
   }
 } 
 else {
   lcd.clear();
   lcd.print("Test Three: ");
   delay (2000);
   digitalWrite(ledOne, LOW);
   digitalWrite(ledTwo, LOW);
   digitalWrite (ledThree, LOW);
    
    Serial.println("TEST THREE: FAILED");
       lcd.clear();
       lcd.print("TEST THREE: ");
       lcd.setCursor(0,1);
       lcd.print("FAILED");
       delay (2000);
       lcd.clear();
    break;
 }
 }
 delay(1000);
 lcd.clear();
 Serial.print("Patient passed ");
 Serial.print(count);
 Serial.println(" test(s).");
 lcd.clear();
 lcd.print("Patient passed ");
 lcd.setCursor(0,1);
 lcd.print(count);
 lcd.setCursor(1,1);
 lcd.print(" test(s).");
 delay(5000);
}