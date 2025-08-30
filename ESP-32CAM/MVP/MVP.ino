#include <Arduino.h>
#include "esp_camera.h"
#include "camera_config.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting camera...");

  camera_config_t config = get_default_camera_config();

  if(esp_camera_init(&config) != ESP_OK){
    Serial.println("Camera init failed");
    return;
  }

  camera_fb_t * fb = esp_camera_fb_get();
  if(!fb) {
    Serial.println("Camera capture failed");
    return;
  }

  Serial.printf("Picture taken, size: %u bytes\n", fb->len);

  // Print first few bytes
  for(int i=0; i<16 && i<fb->len; i++){
    Serial.printf("%02X ", fb->buf[i]);
  }
  Serial.println();

  esp_camera_fb_return(fb);
}

void loop() {
  delay(100000);
}
