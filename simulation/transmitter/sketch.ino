#include <WiFi.h>
#include <esp_now.h>

const int SOS_BUTTON = 4;
const int LED = 2;
const int BUZZER = 5;

uint8_t broadcastAddress[] = {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

const char message[] = "EMERGENCY ALERT";

void setup() {
  Serial.begin(115200);

  pinMode(SOS_BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println();
  Serial.println("================================");
  Serial.println("OFFLINE EMERGENCY TRANSMITTER");
  Serial.println("================================");

  Serial.print("ESP32 MAC Address: ");
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK) {
    Serial.println("ERROR: ESP-NOW initialization failed!");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("ERROR: Failed to add ESP-NOW peer!");
    return;
  }

  Serial.println("ESP-NOW initialized successfully.");
  Serial.println("System Ready.");
  Serial.println("Press SOS button...");
}

void loop() {
  if (digitalRead(SOS_BUTTON) == LOW) {

    Serial.println();
    Serial.println("!!! EMERGENCY ALERT !!!");
    Serial.println("SOS BUTTON PRESSED");

    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);

    for (int i = 0; i < 3; i++) {

      esp_err_t result = esp_now_send(
        broadcastAddress,
        (uint8_t *)message,
        strlen(message) + 1
      );

      if (result == ESP_OK) {
        Serial.println("Emergency message sent.");
      } else {
        Serial.println("Message transmission failed.");
      }

      delay(200);
    }

    Serial.println("Emergency transmission completed.");

    delay(3000);

    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);

    Serial.println("System Ready.");
    Serial.println("Press SOS button...");

    while (digitalRead(SOS_BUTTON) == LOW) {
      delay(50);
    }

    delay(200);
  }
}
