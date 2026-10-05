# Montagem

Medir antes, pelo roteiro de [07-medicoes.md](07-medicoes.md). Anotar em [medicoes-bancada.md](medicoes-bancada.md).

## Não cortar o fio original

O flat e os fios do painel continuam inteiros. O opto é uma derivação.

1. Preferir o pad do conector do flat. Estanhar o pad e soldar um fio fino, sem levantar o condutor original.
2. Se o conector não der acesso, descascar 5 mm no meio do fio, estanhar a janela e soldar o fio de derivação em cima. O cobre original não é interrompido.
3. Cobrir a emenda com termoencolhível.
4. Não inserir PC817 em série. Série só existiria se a bancada mostrasse que não há contato seco, e aí o plano para.

## Ordem

1. Desligar da tomada. Confirmar ausência de tensão no borne.
2. Abrir o corpo. Fotografar o flat e a fonte antes de soltar qualquer fio.
3. Preencher [medicoes-bancada.md](medicoes-bancada.md).
4. Montar os oito PC817 na proto, ainda na bancada. Lado do rádio no USB. Lado da coifa numa fonte de bancada isolada. Não misturar os GNDs.
5. Levar a proto para o bolso, acima do motor. Fixar na barra ou num suporte colado na parede do tubo.
6. Passar o pigtail e o cabo USB da fonte do forro pelo mesmo vão, sem dobra fechada no U.FL.
7. Gravar e comissionar com a coifa desligada da rede e o XIAO no USB do computador. Depois, o USB do computador sai e entra o cabo da fonte de 5 V / 1 A do forro.

## Conferência de cada canal

Para cada função, luz, baixa, média e alta:

- Opto de pulso: pino 4 no sinal do botão, pino 3 no GND da coifa, pino 1 no GPIO via 470 Ω, pino 2 no GND do XIAO.
- Opto de leitura: pino 1 no fio do LED via 1 kΩ, pino 2 no GND da coifa, pino 4 no GPIO de sentido, pino 3 no GND do XIAO.
- Apertar o botão físico e ver o LED do painel acender como antes.
- Pulsar o GPIO e ver o mesmo efeito.
- Com a função ligada, o GPIO de sentido fica alto. Se o símbolo do painel esmorecer, trocar 1 kΩ por 2,2 kΩ ou 4,7 kΩ.

## Fonte

Não derivar o rail da coifa. A fonte de 5 V fica no forro, fora do tubo. O cabo só entra no USB do XIAO.

A0505S-2W e dois B0505S-1W não substituem o B0505S-2W que não foi achado. Detalhe em [02-bom.md](02-bom.md).

## Reversão

Tirar os fios de derivação devolve a coifa ao circuito de fábrica. Por isso a solda é na derivação, não um corte no flat.
