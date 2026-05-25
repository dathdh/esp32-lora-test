#include <SPI.h>
#include <LoRa.h>

// =========================
// SX1278 Pins
// =========================
#define LORA_MISO 3
#define LORA_MOSI 6
#define LORA_SCK  4
#define LORA_SS   7
#define LORA_RST  8
#define LORA_DIO0 9

String message = "";

void setup() {

  Serial.begin(115200);

  delay(2000);

  Serial.println("=== ESP32-C3 SENDER ===");

 
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
  Serial.println("Nhap du lieu:");
}

void loop() {

 
  if (Serial.available()) {

    // Đọc chuỗi đến Enter
    message = Serial.readStringUntil('\n');

    // Xóa khoảng trắng/ký tự thừa
    message.trim();

    // Không gửi chuỗi rỗng
    if (message.length() > 0) {

      
      LoRa.beginPacket();

      LoRa.print(message);

      LoRa.endPacket();

      Serial.print("Sent: ");
      Serial.println(message);
    }
  }
}