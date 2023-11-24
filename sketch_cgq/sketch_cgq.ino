#include <Servo.h>
#include <SoftwareSerial.h>
const int rxPin = 6;  // RX引脚
const int txPin = 5;  // TX引脚

SoftwareSerial mySerial(rxPin, txPin); // 创建软串口对象

int dataIndex = 0;
int pos = 0;
// Change these constants according to your project's design
const int flexPin1 = A0; 
const int flexPin2 = A1;        
const float VCC = 5;                        // voltage at Ardunio 5V line
const float R_DIV = 206.0;        // resistor used to create a voltage divider
const float flatResistance = 9000.0;        // resistance when flat
const float bendResistance = 14000.0;        // resistance at 90 deg
#define PIN_TRIG 12
#define PIN_ECHO 11
float cm;
float temp;
void setup() {  
  mySerial.begin(9600);  // 初始化软串口，选择适当的波特率
  Serial.begin(9600);  
  pinMode(A3, OUTPUT); 
  pinMode(PIN_TRIG, OUTPUT);  
  pinMode(PIN_ECHO, INPUT);  
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  Serial.begin(9600);

}  
  
void loop() {
  delay(1000);
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  temp = float(pulseIn(PIN_ECHO, HIGH));
  cm = (temp * 17 )/1000;
  Serial.print("Distance=");  
  Serial.print(cm);
  Serial.println("cm");  
  delay(300);  
 int ADCflex1 = analogRead(flexPin1);
 float Vflex1 = ADCflex1 * VCC / 1023.0;
 float Rflex1 = R_DIV * (VCC / Vflex1 - 1.0);
 int ADCflex2 = analogRead(flexPin2);
 float Vflex2 = ADCflex2 * VCC / 1023.0;
  float  Rflex2 = R_DIV * (VCC / Vflex2 - 1.0);
 Serial.println("Resistance2: " + String(Rflex2) + " ohms");
  float angle1 = map(Rflex1, flatResistance, bendResistance, 0, 90.0);
  float angle2 = map(Rflex2, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend1: " + String(angle1) + " degrees");
  //if(cm>30){
mySerial.print("A");
mySerial.print(cm);
mySerial.print("#");
  //}else if(Rflex2<6000){
mySerial.print("B");
mySerial.print(Rflex2);
mySerial.print("#");
 // }else if(angle1>-30){
mySerial.print("C");
mySerial.print(angle1);
mySerial.print("#");
mySerial.print("A");
mySerial.print(cm);
mySerial.print("#");
  //}else if(Rflex2<6000){
mySerial.print("B");
mySerial.print(Rflex2);
mySerial.print("#");
 // }else if(angle1>-30){
mySerial.print("C");
mySerial.print(angle1);
mySerial.print("#");
mySerial.print("A");
mySerial.print(cm);
mySerial.print("#");
  //}else if(Rflex2<6000){
mySerial.print("B");
mySerial.print(Rflex2);
mySerial.print("#");
 // }else if(angle1>-30){
mySerial.print("C");
mySerial.print(angle1);
mySerial.print("#");
  //}
  if(cm>20 || Rflex2<10000 || angle1 <-40){
    digitalWrite(A3, HIGH);
  delay(1000);
  digitalWrite(A3, LOW);
  delay(40000);
  }
  delay(500);
}