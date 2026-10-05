# Lista de materiais

Preços de referência em outubro de 2026, em reais, para compra no Brasil. Conferir na hora. Links de busca continuam válidos quando o anúncio some.

## Comprar

| Qtd | Peça | Por que | Tamanho | Referência | Onde |
|---|---|---|---|---|---|
| 1 | Seeed XIAO ESP32-C6, SKU 113991254 | Wi-Fi 6, BLE e Thread no mesmo rádio, U.FL de fábrica | 21 × 17,8 mm | US$ 5,20 na Seeed; no Brasil costuma ficar R$ 80–140 | [Seeed](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C6-p-5884.html), [wiki](https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/), [busca ML](https://lista.mercadolivre.com.br/xiao-esp32-c6) |
| 1 | Haste 2,4 GHz com pigtail U.FL, ou pigtail U.FL–SMA de 15–20 cm mais haste 3 dBi | A antena cerâmica não sai do aço | haste ~110 mm | R$ 20–40 o kit; haste Seeed SKU 103990623 ~US$ 2,20 | [busca ML](https://lista.mercadolivre.com.br/pigtail-ufl-antena-2.4) |
| 10 | PC817 (ou EL817) DIP-4 | 8 usados, 2 reserva. Saída pulsa o botão, entrada lê o LED | 6,5 × 4,6 mm | R$ 10–18 o kit de 10 | [busca ML](https://lista.mercadolivre.com.br/pc817-dip) |
| 1 | Fonte 5 V de tomada, 1 A, no forro | Alimenta o XIAO sem tirar corrente da coifa. O opto já isola o sinal | carregador pequeno | R$ 15–30 | qualquer fonte USB de 5 V / 1 A |
| 1 | Cabo USB fino até o bolso, pelo mesmo caminho do pigtail | Só alimentação. Dados não são necessários depois de gravar | — | — | — |
| 8 | Resistor 470 Ω a 1 kΩ, 1/4 W | Limita o LED do opto | — | centavos | loja local |
| 1 | Protoboard perfurada ~30 × 70 mm, ou PCB própria | Cabe no bolso ao lado do XIAO | ver espaço | R$ 10–20 | loja local |
| 1 | Conector no flat ou garra, mais fio 0,25 mm² | Reversível. Não soldar direto no flat se der para evitar | — | — | — |

Total estimado: R$ 140–220, sem o conversor isolado.

## Fonte, o que não usar

O B0505S-2W (5 V para 5 V, 400 mA) era o especificado e não apareceu no varejo. As trocas abaixo não o substituem.

- A0505S-2W. Saída dupla ±5 V, ±200 mA. Só o positivo entrega 1 W, o mesmo que um B0505S-1W. O negativo não se soma ao positivo: entre +Vo e −Vo há 10 V, não 5 V. Não usar.
- Dois B0505S-1W em paralelo. O datasheet Mornsun dessas séries diz para não ligar saídas em paralelo. A regulação é frouxa e um módulo acaba carregando o outro.
- Um B0505S-1W sozinho. São 200 mA. O ESP32-C6 em 802.15.4 a 20 dBm puxa 305 mA de pico, e a 12 dBm puxa 187 mA, já no limite. Wi-Fi passa de 280 mA. Cabe só se a potência de TX for limitada perto de 0 dBm (119 mA) e ainda assim o comissionamento BLE pode derrubar a tensão.

Se aparecer um B0505S-2W, B0505S-2WR2 ou IB0505S-2W de saída única, aí sim dá para alimentar pelo rail da coifa. Até lá a fonte é a do forro.

## Não comprar para este projeto

- ESP32-C6-DevKitC com módulo **WROOM-1** (sem U). Exemplo: [SmartKits, R$ 69,90](https://www.smartkits.com.br/placa-esp32-c6-devkitc-wifi-zigbee-n4). Antena de PCB, sem conector. Dentro do tubo não alcança o Apple TV.
- ESP32-C6-MINI-1U. O conector é W.FL / IPEX MHF III, não o U.FL do pigtail comum.
- Módulo relé de um canal Matter. Liga carga. Aqui o que se precisa é pulsar um contato de painel e ler um LED.
- Módulo opto de 8 canais pronto, se o espaço apertar. Serve eletricamente ([Fermarc, R$ 42,50](https://www.fermarc.com/produto/modulo-optoacoplador-8-canais-pc817.html)), mas são dois módulos de ~45 × 38 mm. O DIP avulso cabe melhor.

## Antena

O XIAO tem cerâmica e U.FL, comutados por RF switch. Sem firmware a cerâmica fica selecionada. Para o U.FL, no boot: GPIO3 em baixo (habilita o switch) e GPIO14 em alto (seleciona o externo). Esses dois GPIO não entram no mapa dos optos.

Wi-Fi, BLE e 802.15.4 saem pela mesma antena. Um pigtail cobre Thread e Wi-Fi.
