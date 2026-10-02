# Firmware

Esqueleto. Não comissiona e não pulsa de verdade até os `TODO` saírem.

Alvo: Seeed XIAO ESP32-C6, Arduino-ESP32 com a biblioteca Matter (`MatterOnOffLight`, `MatterFan`). PlatformIO.

```sh
cd firmware
pio run -e seeed_xiao_esp32c6
```

O ambiente pede `platform = espressif32` recente o bastante para o board `seeed_xiao_esp32c6` e para Matter no core Arduino. Se o board não existir na plataforma instalada, usar o core Arduino-ESP32 3.x da Espressif e a placa XIAO_ESP32C6.

## O que já está decidido

- Pinos em `include/pins.h`. GPIO3 e GPIO14 são da antena.
- `Hood` é o dono do pulso e da leitura. Matter só pede estado.
- A verdade é o LED. Comando que não confirmar em duas tentativas publica o estado lido.
- Não commitar código de pareamento, salt nem discriminator fixo de produção.

## O que falta implementar

1. Selecionar a antena externa no `setup`, antes do rádio subir.
2. Instanciar os endpoints e ligar os callbacks a `Hood::setLight` e `Hood::setFan`.
3. No `loop`, ler os quatro LEDs e, se mudaram sem comando, reportar o atributo.
4. Ajustar `kPulseMs` e `kSettleMs` com o número de [docs/07-medicoes.md](../docs/07-medicoes.md).
5. Tratar o caso, ainda não medido, de marcha que não troca direto.

Referência da API de fan: https://docs.espressif.com/projects/arduino-esp32/en/latest/matter/ep_fan.html
