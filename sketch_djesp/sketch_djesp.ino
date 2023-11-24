#include <WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(16, 5); // 创建软串口对象
int dataIndex = 0;
int pos = 0;
const char* ssid = "MyESP32Hotspot"; // 设置热点的SSID
const char* password = "12345678"; // 设置热点的密码
WiFiServer server(80); // 创建一个服务器对象，监听端口80
void setup() {
  Serial.begin(115200);
  delay(1000);
  mySerial.begin(115200);
  WiFi.softAP(ssid, password); // 将ESP32配置为热点
  server.begin(); // 启动服务器
  IPAddress IP = WiFi.softAPIP(); // 获取热点的IP地址
  Serial.print("Hotspot IP address: ");
  Serial.println(IP);
}
void loop() {
  WiFiClient client = server.available(); // 等待客户端连接
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        String request = client.readStringUntil('\r'); // 读取客户端发送的数据
      //  mySerial.print("Received: ");
        Serial.println(request);
        mySerial.println(request+"#");
        client.println("Hello, ESP32 Client!"); // 向客户端发送响应
        break;
      }
    }
    client.stop(); // 断开与客户端的连接
  }
}