#include "esp_camera.h"
#include "camera_config.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  camera_config_t camera_config = get_default_camera_config();


}

void loop() {
  // put your main code here, to run repeatedly:

}
