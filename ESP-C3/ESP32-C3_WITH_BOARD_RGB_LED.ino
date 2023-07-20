/**
 * 分别用 红、绿、蓝三种颜色点亮
 * ESP-C3 板载的 RGB LED 灯
 * 每个颜色之间间隔2秒
 */
uint8_t ledR = 3;
uint8_t ledG = 4;
uint8_t ledB = 5;

void setup() {

  // 将RGB引脚关联到相应的通道
  // assign RGB led pings to channels
  ledcAttachPin(ledR, 1);
  ledcAttachPin(ledG, 2);
  ledcAttachPin(ledB, 3);

  delay(10);
  // Initialize channels 
  // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
  // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  ledcSetup(1, 12000, 8); // 12 kHz PWM, 8-bit resolution
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);
}

void loop() {
      //红色
      ledcWrite(1, 255);
      ledcWrite(2, 0);
      ledcWrite(3, 0);
      delay(2000);
      //绿色
      ledcWrite(1, 0);
      ledcWrite(2, 255);
      ledcWrite(3, 0);
      delay(2000);
      //蓝色
      ledcWrite(1, 0);
      ledcWrite(2, 0);
      ledcWrite(3, 255);
      delay(2000); 

}
