#pragma once

#include <stdint.h>

// Marcha vista pelos LEDs. Off é nenhum LED de velocidade aceso.
enum class FanSpeed : uint8_t { Off = 0, Low = 1, Mid = 2, High = 3 };

struct HoodState {
  bool light;
  FanSpeed fan;
};

// Dono do hardware. Matter pede, Hood confirma no LED.
class Hood {
 public:
  void begin();
  HoodState read() const;

  // Pulsa até o LED concordar, ou desiste e devolve o estado lido.
  HoodState setLight(bool on);
  HoodState setFan(FanSpeed speed);

 private:
  void pulse(uint8_t pin) const;
  bool sense(uint8_t pin) const;
};
