// MQ-135 AIR QUALITY :: http://fitrox.lnwshop.com
// BASIC MQ-135 WITH ANALOGREAD

// กำหนด MQ-135 ต่อกันขา A0
#define MQ135_PIN A0

// กำหนดตัวแปรเก็บค่าที่อ่านได้จากเซ็นเซอร์
int SENSOR_VALUE;

void setup() {
  Serial.begin(115200);

  // Pre heat 20 วินาที
  Serial.println("Pre-heat sensor 20 seconds");
    delay(20000);
  Serial.println("Sensor ready start reading");
}

void loop() {
  SENSOR_VALUE = analogRead(MQ135_PIN);
  Serial.print("Air quality value : ");
  Serial.println(SENSOR_VALUE);
  delay(5000);
}
