# Medições de bancada

Preencher aqui depois de seguir [07-medicoes.md](07-medicoes.md). Enquanto os campos estiverem vazios, o esquema continua na hipótese de botão ativo em baixo e LED ativo em alto. Não soldar o opto em definitivo antes desta tabela.

Não cortar fio para medir. Ponta no pad do conector, ou numa janela descascada de 5 mm que depois recebe a derivação.

Data da sessão:

Tensão de rede do aparelho medido: 127 V ou 220 V.

## Botões

Para cada linha: resistência solto, resistência apertado contra o GND da placa, e para onde fecha se não for o GND.

| Função | Fio ou pad no flat | Solto | Apertado contra GND | Fecha para | Confirma ativo em baixo? |
|---|---|---|---|---|---|
| Luz | | | | | |
| Baixa | | | | | |
| Média | | | | | |
| Alta | | | | | |

Se alguma linha não fechar para o GND, o transistor do PC817 não pode ir como está em [04-esquema.md](04-esquema.md). Anotar o rail e parar a montagem desse canal.

## LEDs do painel

Tensão contra o GND da placa. A coluna do resistor diz se 1 kΩ em paralelo apagou o símbolo.

| Função | Fio ou pad | Tensão apagado | Tensão aceso | Mesmo fio do botão? | 1 kΩ apagou o símbolo? |
|---|---|---|---|---|---|
| Luz | | | | | |
| Baixa | | | | | |
| Média | | | | | |
| Alta | | | | | |

Resistor de leitura escolhido depois da prova: 1 kΩ, ou o valor que não esmoreceu o símbolo.

## Fonte

| Ponto | Tensão | Serve para o B0505S? |
|---|---|---|
| Rail de lógica contra GND da placa | | não, só referência |
| Rail de 5 V, se existir | | sim, direto no +Vin |
| Rail de 12 V, se o de 5 V não existir | | sim, depois de buck para 5 V |

## Marchas

- Baixa ligada, aperta média: a baixa apaga e a média acende, ou as duas ficam acesas?
- Alta ligada, aperta alta de novo: desliga? sim ou não.
- Tempo do toque até o LED estável, em ms:

Esses dois resultados decidem o `TODO` de `Hood::setFan` e os valores `kPulseMs` / `kSettleMs`.

## Fotos

Guardar fora do git, ou neste diretório se não mostrarem série, nota fiscal nem ambiente identificável:

- Flat do painel, os dois lados do conector.
- Pads usados na derivação, com o fio original ainda contínuo.
- Rail de onde sai o 5 V para o B0505S.
