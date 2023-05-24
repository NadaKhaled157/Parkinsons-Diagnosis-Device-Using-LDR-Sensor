#define greenLed 4
#define redLed 2 
#define sensorPin A4

int sensorValue=0;

// Characteristics related to LDR
const float GAMMA = 0.7;
const float RL10 = 50;
const float time=10;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(greenLed,OUTPUT);
 pinMode (redLed, OUTPUT);
 pinMode(sensorPin, INPUT);
 digitalWrite(greenLed,LOW);
 digitalWrite(redLed, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
 sensorValue= analogRead(A4);
float voltage = sensorValue / 1024. * 5;
float resistance = 2000 * voltage / (1 - voltage / 5);
float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

if (lux>600){Serial.println("PASSED");
delay(1000);}
else {
Serial.println("FAILED");
delay(1000);
}
}
