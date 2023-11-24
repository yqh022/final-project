#include <Servo.h>
Servo baseServo;
Servo forearmServo;
Servo wristServo;
Servo rearServo;  // 后壁舵机

int baseServoPin = 7;    // 底座舵机连接到D9引脚
int forearmServoPin = 8;  // 前臂舵机连接到D10引脚
int wristServoPin = 10;    // 手腕舵机连接到D11引脚
int rearServoPin = 9;     // 后壁舵机连接到D12引脚

void setup() {
  Serial3.begin(115200);
  Serial.begin(115200);
  baseServo.attach(baseServoPin);
  forearmServo.attach(forearmServoPin);
  wristServo.attach(wristServoPin);
  rearServo.attach(rearServoPin);
  baseServo.write(90);     // 底座舵机角度
  forearmServo.write(90);  // 前臂舵机角度
  wristServo.write(90);    // 手腕舵机角度
  rearServo.write(90);     // 后壁舵机角度
  delay(1000);
}

void loop() {
  if (Serial3.available() > 0) {
    String receivedChars = Serial3.readStringUntil('\r');
       int sideLength = 10;   // 正方形的边长
          int delayTime = 1000;  // 每个边上停留的时间（毫秒）
          int stepAngle = 1;     // 每次移动的角度步进
      if(receivedChars[0]  == 'A'){Serial.print("a");
        float arr = receivedChars.substring(1,receivedChars.indexOf('#')).toFloat();
        Serial.print(arr);Serial.print("  ");
        arr = map(arr,0,140,35,85);
        if(arr>40){Serial.print(arr);
       
          Serial.print("stat");
          forearmServo.write(arr);
          baseServo.write(0+40); 
          for (int angle = 0+40; angle <= arr; angle += stepAngle) {
          baseServo.write(angle);     // 底座舵机角度
          delay(300);                 // 增加延迟以减慢运动
          }delay(delayTime);
          for (int angle = arr; angle >= 0+40; angle -= stepAngle) {
          baseServo.write(angle);     // 底座舵机角度
          forearmServo.write(angle); 
          delay(300);                 // 增加延迟以减慢运动
          }delay(delayTime);
          for (int angle = 0+40; angle <= arr; angle += stepAngle) {
          baseServo.write(angle);     // 底座舵机角度
          delay(300);                 // 增加延迟以减慢运动
          }delay(delayTime);
          Serial3.flush();
        }
        
      }else if(receivedChars[1]  == 'B'){Serial.print("b");
        float arr = receivedChars.substring(2,receivedChars.indexOf('#')).toFloat();
        Serial.println(arr);
        arr = map(arr,40000,200000,40,85);
        if(arr<=74){
          Serial.println(arr);
          forearmServo.write(arr);
  baseServo.write(40);
  for (int angle = 0+40; angle <= arr; angle += stepAngle) {
    baseServo.write(angle);// 底座舵机角度
      delay(300); // 增加延迟以减慢运动
  }
  delay(delayTime);
  for (int angle = arr; angle >= 0+40; angle -= stepAngle) {
    forearmServo.write(angle);// 前臂舵机角度
      delay(300);// 增加延迟以减慢运动
  }
  for (int angle = arr; angle >= 0+40; angle -= stepAngle) {
    baseServo.write(angle);// 底座舵机角度
      delay(300);// 增加延迟以减慢运动
  }
  for (int angle = 0+40 ;angle <= arr; angle += stepAngle) {
    forearmServo.write(angle);// 前臂舵机角度
      delay(300);// 增加延迟以减慢运动
  }
        }
      }else if(receivedChars[1]  == 'C'){
        Serial.print("c");
        float arr = receivedChars.substring(2,receivedChars.indexOf('#')).toFloat();
        Serial.println(arr);
        arr = map(arr,-130,50,85,40);
        if(arr>50){
Serial.println(arr);
forearmServo.write(arr);
baseServo.write(0+40); 
for (int angle = 0+40; angle <= arr; angle += stepAngle) {
baseServo.write(angle);
delay(300);
}delay(delayTime);
for (int angle = arr; angle >= 0+40; angle -= stepAngle) {
baseServo.write(angle);
forearmServo.write(angle); 
delay(300);
}delay(delayTime);
for (int angle = 0+40; angle <= arr; angle += stepAngle) {
forearmServo.write(angle); 
delay(300);
}delay(delayTime);
        }
        
      }
  }
}