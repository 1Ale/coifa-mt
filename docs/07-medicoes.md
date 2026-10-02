# Medidas antes de soldar

Coifa desligada da tomada. Multímetro e, se houver, continuidade com a placa alimentada por variac ou pela própria rede só depois de o gabinete estar fechado o bastante para não encostar na fase. Não ligar o USB do XIAO nessa sessão.

Anotar os números em `docs/medicoes-bancada.md` quando existirem. Esse arquivo ainda não está no repositório de propósito.

## Botões

Para cada um dos quatro:

1. Achar os dois fios do contato no flat.
2. Em repouso, medir resistência. Esperado: aberto.
3. Apertado, medir para onde fecha: GND da placa, ou um rail.
4. Anotar se é ativo em baixo (hipótese do esquema) ou ativo em alto.

## LEDs

Para cada botão, com a função ligada e desligada:

1. Tensão do fio do LED em relação ao GND da placa.
2. Se é o mesmo fio do contato ou um fio separado. No painel com LED integrado costuma ser separado.
3. Queda de brilho ao pôr 1 kΩ para o GND. Se apagar, o ponto de leitura está errado.

## Fonte

1. Tensão do rail de lógica: 3,3 V ou 5 V.
2. Tensão de um rail de potência utilizável: 5 V ou 12 V.
3. Se o GND da lógica está no neutro ou na fase. Se não der para saber com segurança, manter o B0505S. Não é opcional até essa medida existir.

## Marchas

Com a coifa montada e segura:

1. Baixa ligada. Apertar média. O LED de baixa apaga e o de média acende, ou os dois ficam independentes?
2. Alta ligada. Apertar alta de novo. Confirmar que desliga, como o manual diz.
3. Tempo entre o toque e o LED estável. Vira a constante `kPulseMs` e `kSettleMs` do firmware.
