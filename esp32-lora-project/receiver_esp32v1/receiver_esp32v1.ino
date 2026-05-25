#include <SPI.h>
#include <LoRa.h>

// =========================
// SX1278 Pins
// =========================
#define LORA_SCK   18
#define LORA_MISO  19
#define LORA_MOSI  23
#define LORA_SS    5
#define LORA_RST   14
#define LORA_DIO0  27

void setup() {

  Serial.begin(115200);

  delay(2000);

  Serial.println("=== ESP32 V1 RECEIVER ===");
  SPI.begin(
    LORA_SCK,
    LORA_MISO,
    LORA_MOSI,
    LORA_SS
  );
  LoRa.setPins(
    LORA_SS,
    LORA_RST,
    LORA_DIO0
  );

  if (!LoRa.begin(433E6)) {

    Serial.println("LORA FAIL");

    while (1);
  }

  Serial.println("LORA OK");
}

void loop() {

  // =========================
  // Kiểm tra packet
  // =========================
  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    String received = "";

   
    while (LoRa.available()) {

      received += (char)LoRa.read();
    }

    Serial.println();
    Serial.println("===== RECEIVED =====");

    Serial.print("Message: ");
    Serial.println(received);

    Serial.print("RSSI: ");
    Serial.println(LoRa.packetRssi());

    Serial.println("====================");
  }
}