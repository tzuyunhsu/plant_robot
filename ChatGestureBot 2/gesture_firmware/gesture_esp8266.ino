#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

ESP8266WebServer server(80);
Servo servo;

void handleGesture() {
  if (!server.hasArg("cmd")) {
    server.send(400, "text/plain", "Missing gesture command");
    return;
  }

  String gesture = server.arg("cmd");
  gesture.trim();
  gesture.toLowerCase();

  if (gesture == "nod") {
    for (int i = 0; i < 2; i++) {
      servo.write(0);
      delay(300);
      servo.write(90);
      delay(300);
    }
  } else if (gesture == "tilt") {
    servo.write(45);
    delay(600);
    servo.write(90);
  } else {
    servo.write(90);
  }

  server.send(200, "text/plain", "Gesture executed: " + gesture);
}

void setup() {
  Serial.begin(115200);
  servo.attach(D1);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wi-Fi connected");
  Serial.println(WiFi.localIP());

  server.on("/gesture", handleGesture);
  server.begin();
}

void loop() {
  server.handleClient();
}