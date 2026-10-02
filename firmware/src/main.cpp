#include <Arduino.h>

#include "hood.h"
#include "pins.h"

// TODO: incluir Matter.h do Arduino-ESP32 e criar:
//   MatterOnOffLight light;
//   MatterFan fan;
// Callbacks chamam hood.setLight / hood.setFan e publicam o estado devolvido,
// não o estado pedido. Ver docs/06-matter.md.

static Hood hood;
static HoodState published{};

void setup() {
  Serial.begin(115200);
  hood.begin();
  published = hood.read();
  Serial.println("coifa-mt: antena externa selecionada, Matter ainda não instanciado");
}

void loop() {
  const HoodState now = hood.read();
  if (now.light != published.light || now.fan != published.fan) {
    published = now;
    // TODO: reportar OnOff e FanMode/PercentSetting.
    Serial.printf("estado luz=%d fan=%u\n", now.light, static_cast<unsigned>(now.fan));
  }
  delay(50);
}
