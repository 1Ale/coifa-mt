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

B0505S-2W, SIP de quatro pinos, marcação no corpo:

| Pino do módulo | Liga em |
|---|---|
| +Vin | 5 V da coifa, depois de um buck se o rail for 12 V |
| −Vin | GND da placa da coifa |
| +Vo | pino 5 V do XIAO |
| −Vo | GND do XIAO |

Não ligar +Vo no pino de 3,3 V. Capacitor de 10 µF entre +Vo e −Vo segura o pico do rádio.

GPIO3 em baixo habilita o RF switch. GPIO14 em alto seleciona o U.FL. Esses dois não recebem opto.
