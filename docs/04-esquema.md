# Esquema

Desenho: [hardware/schematic.svg](../hardware/schematic.svg).

Não se corta fio do painel. O condutor original segue de ponta a ponta. O opto entra em paralelo, num ponto descascado ou, de preferência, num pad do conector.

## PC817, DIP-4, visto de cima

O ponto ou chanfro marca o pino 1. A contação desce no lado esquerdo e sobe no direito.

| Pino | Nome | Lado |
|---|---|---|
| 1 | anodo do LED interno | entrada, o que acende o opto |
| 2 | catodo do LED interno | entrada |
| 3 | emissor | saída, transistor |
| 4 | coletor | saída, transistor |

Pinos 1–2 e 3–4 não têm condução elétrica entre si. É essa a barreira.

## Pulso do botão

Hipótese, até medir: o botão fecha o sinal para o GND da placa.

Não cortar os dois fios do botão. Descascar os dois, ou soldar no pad do conector, e ligar o transistor em paralelo com o contato.

| Pino | Liga em |
|---|---|
| 4 coletor | fio de sinal do botão, o mesmo que o contato original usa |
| 3 emissor | GND da placa da coifa, o mesmo GND do botão |
| 1 anodo | resistor de 470 Ω e, depois dele, o GPIO de pulso do XIAO |
| 2 catodo | GND do XIAO, lado isolado |

GPIO em alto por 100 ms acende o LED do opto, o transistor conduz e a placa vê um toque. GPIO em baixo deixa o transistor aberto. O dedo no botão continua fechando o mesmo par de fios.

Quatro optos, um por função: luz no D0/GPIO0, baixa no D1/GPIO1, média no D2/GPIO2, alta no D3/GPIO21.

Só faria sentido cortar e inserir em série se a medida mostrasse que o "botão" não é contato. Não é o plano. Se acontecer, anotar em [medicoes-bancada.md](medicoes-bancada.md) e parar.

## Leitura do LED

Não cortar o fio que acende o LED do botão. Descascar e derivar. O opto fica em paralelo com o LED do painel, com resistor, para não roubar corrente a ponto de apagar o símbolo.

| Pino | Liga em |
|---|---|
| 1 anodo | resistor de 1 kΩ e, depois dele, o fio que sobe quando o LED do botão acende |
| 2 catodo | GND da placa da coifa |
| 4 coletor | GPIO de sentido do XIAO, pull-down interno |
| 3 emissor | GND do XIAO |

Alto no GPIO significa função ligada. Luz no D4/GPIO22, baixa no D5/GPIO23, média no D6/GPIO16, alta no D7/GPIO17.

Não colocar este opto em série com o LED. Série exige corte e, se o opto abrir, o painel fica às escuras.

## Alimentação

A fonte do XIAO não sai da coifa. Um carregador de 5 V / 1 A fica no forro, no mesmo caminho do pigtail, e o cabo entra no USB do XIAO. O opto isola o sinal. A fonte separada isola a alimentação. Não há GND em comum.

O B0505S-2W (400 mA) serviria se aparecesse, ligado ao rail de 5 V da coifa. Não apareceu.

- A0505S-2W é ±5 V, 200 mA por trilho. Usar só o positivo dá 1 W, igual a um B0505S-1W. Não juntar +Vo com −Vo.
- Dois B0505S-1W não se colocam em paralelo. O fabricante veta.
- Um B0505S-1W (200 mA) não cobre o pico de 305 mA do 802.15.4 a 20 dBm, nem o do Wi-Fi.

GPIO3 em baixo habilita o RF switch. GPIO14 em alto seleciona o U.FL. Esses dois não recebem opto.
