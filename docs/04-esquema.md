# Esquema

Desenho: [hardware/schematic.svg](../hardware/schematic.svg).

Há uma barreira de isolamento. Do lado da coifa ficam os contatos dos botões, os LEDs do painel e o primário do B0505S. Do lado do rádio ficam o XIAO, os LEDs dos optos e a antena. Nenhum GND cruza.

## Hipótese, até medir

A maioria dos painéis desses exaustores fecha o botão para GND e acende o LED a partir de 3,3 V ou 5 V. O esquema e o firmware assumem isso. Se a medida disser o contrário, inverte-se o opto de saída ou o divisor, não a arquitetura.

| Sinal | Ligação assumida | Opto |
|---|---|---|
| Botão | contato momentâneo para GND | transistor do PC817 em paralelo com o contato, coletor no sinal, emissor no GND da placa |
| LED do botão | anode em rail de 3,3/5 V quando aceso | LED do segundo PC817, com resistor, entre esse fio e o GND da placa |

O PC817 de saída só precisa afundar poucos miliamperes por 80–150 ms. Não usar relé.

## Pinos do XIAO ESP32-C6

GPIO3 e GPIO14 são do RF switch. Não usar para opto.

| Função | Header | GPIO | Direção |
|---|---|---|---|
| Pulso luz | D0 | 0 | saída, ativo em alto, para o LED do opto |
| Pulso baixa | D1 | 1 | saída |
| Pulso média | D2 | 2 | saída |
| Pulso alta | D3 | 21 | saída |
| Sentido luz | D4 | 22 | entrada, pull-down, coletor do opto de leitura |
| Sentido baixa | D5 | 23 | entrada |
| Sentido média | D6 | 16 | entrada |
| Sentido alta | D7 | 17 | entrada |
| RF switch enable | pad | 3 | saída, baixo para habilitar |
| RF antena externa | pad | 14 | saída, alto para U.FL |

D8, D9 e D10 ficam livres. Conferir a serigrafia. O mapa acima é o da wiki Seeed do XIAO ESP32-C6.

## Alimentação

Achar 5 V ou 12 V depois da fonte da coifa. Se for 12 V, um buck para 5 V **do lado da coifa**, e só então o B0505S. A saída isolada de 5 V entra no pino 5 V do XIAO. O LDO da placa faz 3,3 V. Não ligar 5 V no pino de 3,3 V.

O B0505S-1W entrega 200 mA. O pico de TX Wi-Fi do C6 encosta nisso. O de 2 W (400 mA) é o especificado. Thread sozinho cabe no de 1 W, mas não há motivo para ficar no limite.

Isolação do B0505S: 1 kV. Separa o rádio de uma fonte não isolada. Não autoriza medir a placa com o ESP no USB.

## Lógica que o esquema tem de permitir

- Luz: se o LED lido não é o desejado, pulsar o botão da luz e reler.
- Ventilador: para ir a uma marcha, pulsar o botão dela. Para desligar, pulsar o botão cujo LED está aceso.
- Botão físico continua em paralelo. O LED é a verdade dos dois lados.
