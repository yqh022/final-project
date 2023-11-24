#include <WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(33, 32); // 创建软串口对象
const char* ssid = "MyESP32Hotspot"; // 热点的SSID，需要与热点ESP32一致
const char* password = "12345678"; // 热点的密码，需要与热点ESP32一致
const char* serverIP = "192.168.4.1"; // 热点的IP地址
WiFiClient client;
void setup() {
  Serial.begin(115200);
  delay(1000);
  mySerial.begin(9600);
  WiFi.begin(ssid, password); // 连接到热点
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
}

void loop() {
while (mySerial.available()) {
    String receivedChar = mySerial.readStringUntil('#');
    Serial.print("Received: ");
    Serial.println(receivedChar);
    if (!client.connected()) {
    if (client.connect(serverIP, 80)) { // 连接到热点服务器
      client.println(receivedChar);
      client.stop(); // 断开与热点的连接
    }
  }
  }
  
}