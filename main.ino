#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include <C:\Users\felix\dev\Arduino\esp-light\main\rgb.h>

ESP8266WebServer server(80);

const char* ssid = "FRITZ!";
const char* password = "0962432444989020";

bool interrupt = true;
int angle = 0;


void setup() {
  Serial.begin(9600);
  analogWriteRange(255);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/start", HTTP_GET, []() {
    server.send(200, "text/plain", "started\r\n");
    interrupt = false;
    Serial.println("loop started");
  });

  server.on("/stop", HTTP_GET, [](){
    interrupt = true;
    server.send(200, "text/plain", "stopped\r\n");
    Serial.println("loop stopped");
  });

  server.begin();
  Serial.println("HTTP server started");
  HSV(0);
}

void loop() {
  server.handleClient();
  nextColor();
  delay(30);
}

void nextColor(){
  if(!interrupt){
    HSV(angle);
    if (angle > 360) {
      angle = 0;
    }
    angle++;
  }
}

