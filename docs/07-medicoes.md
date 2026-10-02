# Como medir

O arquivo que recebe os números é [medicoes-bancada.md](medicoes-bancada.md). Este aqui é o procedimento. Não sobrescrever este arquivo com resultado de bancada.

Coifa desligada da tomada para achar fios e medir resistência. Para tensão de LED e rail, a placa precisa estar energizada: gabinete o bastante fechado para não encostar na fase, uma mão só, ponta de prova isolada. Não ligar o USB do XIAO nessa sessão.

## Botões

Para luz, baixa, média e alta:

1. Achar no flat os dois condutores que mudam quando o botão é apertado. Continuidade com o botão solto e apertado.
2. Solto: esperar circuito aberto, ou resistência de megaohms.
3. Apertado: ver para onde fecha. Uma ponta no sinal, a outra no GND da placa. Se der perto de 0 Ω, é ativo em baixo e o esquema vale.
4. Se apertado não fechar para o GND, medir contra o rail de 3,3 V e contra o de 5 V. Anotar qual. Não montar o opto até isso estar escrito.
5. Não cortar nada para esta medida. A ponta encosta no pad ou num fio descascado só na janela da prova.

## LEDs

Para cada botão, função desligada e depois ligada:

1. Achar o fio cuja tensão muda junto com o símbolo aceso. Medir contra o GND da placa.
2. Anotar a tensão aceso e apagado. Esperado algo como 0 V e 3,3 V, ou 0 V e 5 V.
3. Confirmar que esse fio não é o mesmo do contato do botão.
4. Com a função ligada, encostar 1 kΩ desse fio para o GND da placa. O símbolo tem de continuar visível. Se apagar, o ponto está no meio do resistor original do LED: procurar o nó depois desse resistor, do lado do LED.
5. Não cortar o fio. A prova é em paralelo.

## Fonte

1. Tensão do rail de lógica contra o GND da placa.
2. Tensão de um rail que aguente o B0505S: 5 V direto, ou 12 V com buck antes.
3. Não decidir se o GND da lógica é neutro ou fase. Manter o B0505S de qualquer jeito.

## Marchas

Com a coifa fechada o bastante para funcionar:

1. Ligar baixa. Apertar média. Anotar se a baixa apaga e a média acende, ou se as duas ficam independentes.
2. Ligar alta. Apertar alta de novo. Confirmar que desliga, como o manual diz.
3. Cronometrar do toque até o LED estável. Esse número vira `kPulseMs` e `kSettleMs` em `firmware/include/pins.h`.
