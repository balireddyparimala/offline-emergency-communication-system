#include <WiFi.h>
#include <esp_now.h>

const int LED = 2;
const int BUZZER = 5;

void onDataReceive(const esp_now_recv_info_t *info, const uint8_t *data, int len) {

  Serial.println();
  Serial.println("================================");
  Serial.println("!!! EMERGENCY MESSAGE RECEIVED !!!");
  Serial.println("================================");

  Serial.print("Message: ");
  Serial.println((char *)data);

  digitalWrite(LED, HIGH);
  digitalWrite(BUZZER, HIGH);

  Serial.println("Emergency alarm activated.");

  delay(5000);

  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.println("Alarm stopped.");
  Serial.println("Waiting for emergency message...");
}

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println();
  Serial.println("================================");
  Serial.println("OFFLINE EMERGENCY RECEIVER");
  Serial.println("================================");

  Serial.print("ESP32 MAC Address: ");
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK) {
    Serial.println("ERROR: ESP-NOW initialization failed!");
    return;
  }

  esp_now_register_recv_cb(onDataReceive);

  Serial.println("ESP-NOW initialized successfully.");
  Serial.println("Waiting for emergency message...");
}

void loop() {
  delay(100);
}
