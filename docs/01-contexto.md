# Contexto

Coifa de ilha redonda EOS Maxxi Air, modelos **EMCO41IRI** e **EMCO41IRP**.

Dados do manual de instruções (público, eos.com.br / revendedores):

- 127 V ou 220 V, 60 Hz
- Sucção 1200 m³/h
- Potência até 415 W (algumas fichas de loja citam 375 W ou 410 W; tratar o motor como carga de centenas de watts)
- Corpo Ø 38 cm, altura do conjunto 68,8 cm a 126,2 cm
- Três velocidades e lâmpada de LED
- Filtro de carvão e tela de alumínio
- Garantia contratual de 12 meses, já incluindo os 90 dias legais
- Manual: https://blog.frigelar.com.br/manuais/EOS/Manual_EOS_EMCO41IRI_EMCO41IRP.pdf

## Painel

Quatro botões momentâneos, de cima para baixo no desenho da página 10:

| Botão | Comportamento documentado |
|---|---|
| Baixa | Um toque liga a marcha baixa. Outro toque no mesmo botão desliga o motor. |
| Média | Igual, na marcha média. |
| Alta | Igual, na marcha alta. |
| Luz | Alterna a lâmpada a cada toque. |

Cada botão acende o próprio LED quando a função está ligada e apaga quando está desligada. Há um bip ao aceitar a velocidade.

O manual não diz o que acontece se, com a baixa acesa, se aperta média. O firmware precisa descobrir isso na bancada e tratar o LED como verdade. Hipótese de trabalho: as marchas são exclusivas e apertar outra marcha troca direto.

O manual diz que o produto não foi projetado para timer externo nem controle remoto. Não há receptor de IR nem rádio de fábrica.

## O que este retrofit faz

- Mantém os quatro botões.
- Simula um toque de 80 a 150 ms em paralelo com o contato.
- Lê o fio que acende o LED de cada botão.
- Publica luz e ventilador em Matter.
- Quando alguém aperta o painel, o atributo Matter é atualizado.

## O que não fazer

- Não cortar o flat cable do painel.
- Não comandar o motor por relé próprio. São centenas de watts, possivelmente triac, e a placa original já faz isso.
- Não alimentar o rádio no mesmo GND da placa da coifa até ter certeza de que a fonte é isolada. Partir do isolamento.
- Não colocar a antena dentro do tubo de aço.
