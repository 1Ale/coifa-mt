# Alimentação

A fonte do XIAO é um carregador de tomada de 5 V e 1 A, ligado direto no USB-C. Fica no forro, fora do tubo. O cabo desce pelo mesmo vão do pigtail da antena.

1 A sobra. O pico do ESP32-C6 fica em torno de 300 mA no rádio. O LDO da placa faz os 3,3 V a partir dos 5 V do USB.

Serve um carregador comum de celular que entregue 5 V sem negociar tensão maior. USB-A com cabo A-para-C é o caso mais previsível: o 5 V está sempre no VBUS. USB-C para USB-C também funciona no XIAO, que tem os resistores de CC de dispositivo. Não usar carregador que só acorda em USB Power Delivery acima de 5 V e não fecha 5 V com um sink simples.

Não ligar o cabo do forro e o cabo do computador ao mesmo tempo. Para gravar, sai o carregador e entra o USB do computador. Para o uso normal, só o carregador.

O GND desse carregador não se junta ao GND da coifa. O sinal continua passando só pelos PC817.
