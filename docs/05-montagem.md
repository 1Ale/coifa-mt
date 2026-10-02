# Montagem

Fazer as medidas de [07-medicoes.md](07-medicoes.md) antes de fechar valor de resistor e polaridade do opto.

## Ordem

1. Desligar da tomada. Confirmar ausência de tensão no borne.
2. Abrir o corpo e achar o flat do painel e a fonte da placa. Fotografar os dois conectores antes de soltar qualquer fio.
3. Medir botão e LED conforme o roteiro. Anotar no próprio repositório, em `docs/medicoes-bancada.md`, quando houver número.
4. Montar os oito PC817 na proto, ainda na bancada, alimentando o lado do rádio por USB e o lado da coifa por uma fonte de bancada isolada. Não misturar os GNDs.
5. Só então levar a proto para o bolso. Fixar com abraçadeira na barra ou em suporte colado na parede do tubo, longe do motor.
6. Passar o pigtail para o forro. Não dobrar o U.FL fechado.
7. Primeiro comissionamento com a coifa desligada da rede e o XIAO no USB, para gravar. Comissionar Matter. Só depois cortar o USB e passar a alimentar pelo B0505S.

## Fiação do botão

Para a hipótese ativa em baixo:

- Coletor do PC817 no fio do botão.
- Emissor no GND da placa da coifa.
- LED do mesmo PC817, com resistor de 470 Ω, entre o GPIO de pulso e o GND do XIAO.
- GPIO em alto por 100 ms fecha o contato. Em baixo, o botão original segue intacto.

## Fiação do LED

- Resistor de 1 kΩ em série com o LED do segundo PC817, entre o fio que acende o LED do botão e o GND da placa.
- Escolher o resistor para não apagar o LED do painel. Se o brilho cair, subir o resistor ou ler em um ponto depois do resistor original do painel.
- Coletor do PC817 no GPIO de sentido, com pull-down. Emissor no GND do XIAO. Alto significa função ligada.

## Fonte

- 5 V da coifa entra no B0505S-2W.
- Saída isolada no pino 5 V do XIAO e no GND do lado do rádio.
- Capacitor de 10 µF na saída do B0505S ajuda no pico do rádio. O regulador do módulo é frouxo (±8% no de 1 W).

## Reversão

Conector, não solda permanente no flat. Tirar a proto devolve a coifa ao comportamento de fábrica.
