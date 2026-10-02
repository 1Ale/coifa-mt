#include "hood.h"

#include <Arduino.h>

#include "pins.h"

void Hood::begin() {
  pinMode(kPins.pulseLight, OUTPUT);
  pinMode(kPins.pulseLow, OUTPUT);
  pinMode(kPins.pulseMid, OUTPUT);
  pinMode(kPins.pulseHigh, OUTPUT);
  digitalWrite(kPins.pulseLight, LOW);
  digitalWrite(kPins.pulseLow, LOW);
  digitalWrite(kPins.pulseMid, LOW);
  digitalWrite(kPins.pulseHigh, LOW);

  pinMode(kPins.senseLight, INPUT_PULLDOWN);
  pinMode(kPins.senseLow, INPUT_PULLDOWN);
  pinMode(kPins.senseMid, INPUT_PULLDOWN);
  pinMode(kPins.senseHigh, INPUT_PULLDOWN);

  // Antena externa. Tem de acontecer antes do rádio subir.
  pinMode(kPins.rfSwitchEnable, OUTPUT);
  pinMode(kPins.rfExternalAntenna, OUTPUT);
  digitalWrite(kPins.rfSwitchEnable, LOW);
  digitalWrite(kPins.rfExternalAntenna, HIGH);
}

bool Hood::sense(uint8_t pin) const { return digitalRead(pin) == HIGH; }

void Hood::pulse(uint8_t pin) const {
  digitalWrite(pin, HIGH);
  delay(kPulseMs);
  digitalWrite(pin, LOW);
  delay(kSettleMs);
}

HoodState Hood::read() const {
  HoodState state{sense(kPins.senseLight), FanSpeed::Off};
  const bool low = sense(kPins.senseLow);
  const bool mid = sense(kPins.senseMid);
  const bool high = sense(kPins.senseHigh);
  if (high) {
    state.fan = FanSpeed::High;
  } else if (mid) {
    state.fan = FanSpeed::Mid;
  } else if (low) {
    state.fan = FanSpeed::Low;
  }
  return state;
}

HoodState Hood::setLight(bool on) {
  for (uint8_t attempt = 0; attempt < kMaxTries; ++attempt) {
    if (read().light == on) {
      return read();
    }
    pulse(kPins.pulseLight);
  }
  return read();
}

HoodState Hood::setFan(FanSpeed speed) {
  // TODO: se a bancada mostrar que apertar outra marcha não troca direto,
  // desligar a marcha atual antes de pulsar a nova.
  uint8_t pin = kPins.pulseLow;
  if (speed == FanSpeed::Mid) {
    pin = kPins.pulseMid;
  } else if (speed == FanSpeed::High) {
    pin = kPins.pulseHigh;
  } else if (speed == FanSpeed::Off) {
    const HoodState now = read();
    if (now.fan == FanSpeed::Mid) {
      pin = kPins.pulseMid;
    } else if (now.fan == FanSpeed::High) {
      pin = kPins.pulseHigh;
    } else if (now.fan == FanSpeed::Off) {
      return now;
    }
  }

  for (uint8_t attempt = 0; attempt < kMaxTries; ++attempt) {
    if (read().fan == speed) {
      return read();
    }
    pulse(pin);
  }
  return read();
}
