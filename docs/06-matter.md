# Matter

Dois endpoints no mesmo nó.

| Endpoint | Tipo | Atributos usados |
|---|---|---|
| 1 | On/Off Light | OnOff. O LED da luz é a verdade. |
| 2 | Fan | FanMode Off / Low / Medium / High. PercentSetting 0, 33, 66, 100. SpeedSetting 0 a 3 se o controller pedir marcha. |

Fan Control é cluster Matter desde a 1.1. A biblioteca Matter do Arduino-ESP32 expõe `MatterOnOffLight` e `MatterFan`. É o caminho previsto no `firmware/`. ESP-Matter em ESP-IDF é a alternativa se o Arduino não cobrir o atributo que o Apple Home ler.

## Thread e os dois controles

O Apple TV a cerca de 7 m é o border router. O nó entra na malha Thread dele.

Matter é multi-admin. O mesmo nó aceita Apple Home e Home Assistant, cada um com o próprio fabric. Os dois leem e escrevem os mesmos atributos.

Para o Home Assistant enxergar o nó Thread, importar a credencial Thread do Apple TV (ou do iPhone) no HA. Sem essa credencial o Apple Home funciona e o HA não alcança o dispositivo.

Wi-Fi Matter fica disponível no mesmo C6 se o Thread falhar. Não usar os dois rádios como caminho principal ao mesmo tempo. A antena é uma só, com coexistência.

## Sincronismo

Comando Matter que não bate com o LED gera pulso. Mudança de LED sem comando Matter (botão físico) gera report do atributo. Sem esse report o Apple Home mente.

Depois de um pulso, esperar o bip e reler o LED antes de declarar sucesso. Uma retentativa. Se a segunda falhar, reportar o estado lido, não o desejado.

## Comissionamento

BLE no primeiro pareamento, antena externa já selecionada. Código de pareamento e QR saem no serial. Anotar fora deste repositório público. Não commitar discriminator, salt nem código de pareamento.
