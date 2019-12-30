#include <Rotary.h>

const byte ROTARY_EN1_PIN = 33;
const byte ROTARY_EN2_PIN = 31;

Rotary R1(ROTARY_EN1_PIN, ROTARY_EN2_PIN, true);
int R1Value;

void setup() {
  Serial.begin(115200);
}

void loop() {
  R1Value = R1.Read();
  if (R1.Changed()) Serial.println(R1Value);
}

