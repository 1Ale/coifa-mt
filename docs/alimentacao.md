# Alimentação

Duas formas válidas. As duas isolam o XIAO da placa da coifa. Não usar as duas ao mesmo tempo.

## 1. Carregador no forro

Carregador de tomada de 5 V e 1 A, direto no USB-C do XIAO. Fica no forro, fora do tubo. O cabo desce pelo mesmo vão do pigtail. Não depende de achar um rail de 5 V na coifa.

1 A sobra. O pico do ESP32-C6 fica em torno de 300 mA no rádio. O LDO da placa faz os 3,3 V a partir dos 5 V do USB.

USB-A com cabo A-para-C é o caso mais previsível. USB-C para USB-C também funciona: o XIAO tem os resistores de CC. Não usar carregador que só acorda acima de 5 V.

Não ligar o cabo do forro e o cabo do computador ao mesmo tempo. Para gravar, sai o carregador e entra o USB do computador.

## 2. HLK-B0505S-2WR3, se houver 5 V na placa

É o conversor de 2 W que faltava. Só esta variante.

| Modelo | Entrada | Saída | Corrente | Uso aqui |
|---|---|---|---|---|
| HLK-B0505S-2WR3 | 5 V (4,5–5,5 V) | 5 V | 400 mA | sim, no pino 5 V do XIAO |
| HLK-B0509S-2WR3 | 5 V | 9 V | 222 mA | não |
| HLK-B0512S-2WR3 | 5 V | 12 V | 166 mA | não |

O nome se lê assim: B saída única, 05 entrada de 5 V, 05 saída de 5 V, S encapsulamento SIP, 2W, R3 terceira geração. Isolação 1500 V. Saída não regulada. Carga mínima de 10% (40 mA). O XIAO em repouso costuma ficar acima disso. Capacitor de 10 µF na saída.

Pinos: +Vin no 5 V da coifa, −Vin no GND da coifa, +Vo no pino 5 V do XIAO, −Vo no GND do XIAO. Não ligar +Vo no pino de 3,3 V.

Se o rail da coifa for 12 V, este módulo não serve. Aí seria um B1205S-2WR3, ou o carregador do forro.

A0505S-2W e dois B0505S-1W em paralelo continuam fora. O de 1 W (200 mA) não cobre o pico de 305 mA do 802.15.4 a 20 dBm.
