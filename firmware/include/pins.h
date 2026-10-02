#pragma once

#include <stdint.h>

// XIAO ESP32-C6, mapa da wiki Seeed.
// GPIO3 e GPIO14 pertencem ao RF switch. Não atribuir opto a eles.

struct PinMap {
  uint8_t pulseLight;
  uint8_t pulseLow;
  uint8_t pulseMid;
  uint8_t pulseHigh;
  uint8_t senseLight;
  uint8_t senseLow;
  uint8_t senseMid;
  uint8_t senseHigh;
  uint8_t rfSwitchEnable;  // ativo em baixo
  uint8_t rfExternalAntenna;  // alto = U.FL
};

inline constexpr PinMap kPins{
    0,   // D0 pulso luz
    1,   // D1 pulso baixa
    2,   // D2 pulso média
    21,  // D3 pulso alta
    22,  // D4 sentido luz
    23,  // D5 sentido baixa
    16,  // D6 sentido média
    17,  // D7 sentido alta
    3,
    14,
};

inline constexpr uint16_t kPulseMs = 100;
inline constexpr uint16_t kSettleMs = 250;
inline constexpr uint8_t kMaxTries = 2;
