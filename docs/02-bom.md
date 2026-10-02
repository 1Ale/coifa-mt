# Lista de materiais

Preços de referência em outubro de 2026, em reais, para compra no Brasil. Conferir na hora. Links de busca continuam válidos quando o anúncio some.

## Comprar

| Qtd | Peça | Por que | Tamanho | Referência | Onde |
|---|---|---|---|---|---|
| 1 | Seeed XIAO ESP32-C6, SKU 113991254 | Wi-Fi 6, BLE e Thread no mesmo rádio, U.FL de fábrica | 21 × 17,8 mm | US$ 5,20 na Seeed; no Brasil costuma ficar R$ 80–140 | [Seeed](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C6-p-5884.html), [wiki](https://wiki.seeedstudio.com/xiao_esp32c6_getting_started/), [busca ML](https://lista.mercadolivre.com.br/xiao-esp32-c6) |
| 1 | Haste 2,4 GHz com pigtail U.FL, ou pigtail U.FL–SMA de 15–20 cm mais haste 3 dBi | A antena cerâmica não sai do aço | haste ~110 mm | R$ 20–40 o kit; haste Seeed SKU 103990623 ~US$ 2,20 | [busca ML](https://lista.mercadolivre.com.br/pigtail-ufl-antena-2.4) |
| 10 | PC817 (ou EL817) DIP-4 | 8 usados, 2 reserva. Saída pulsa o botão, entrada lê o LED | 6,5 × 4,6 mm | R$ 10–18 o kit de 10 | [busca ML](https://lista.mercadolivre.com.br/pc817-dip) |
| 1 | B0505S-2W, 5 V para 5 V isolado | 400 mA cobrem o pico do rádio. O de 1 W (200 mA) é justo | SIP ~12 × 6 × 10 mm | 1 W a R$ 15,20; 2 W na casa de R$ 20–30 | [Easytronics 1 W](https://www.easytronics.com.br/conversor-dc-dc-isolador-5v-b0505s-1w), [busca ML](https://lista.mercadolivre.com.br/b0505s) |
| 8 | Resistor 470 Ω a 1 kΩ, 1/4 W | Limita o LED do opto | — | centavos | loja local |
| 1 | Protoboard perfurada ~30 × 70 mm, ou PCB própria | Cabe no bolso ao lado do XIAO | ver espaço | R$ 10–20 | loja local |
| 1 | Conector no flat ou garra, mais fio 0,25 mm² | Reversível. Não soldar direto no flat se der para evitar | — | — | — |

Total estimado: R$ 140–220.

## Não comprar para este projeto

- ESP32-C6-DevKitC com módulo **WROOM-1** (sem U). Exemplo: [SmartKits, R$ 69,90](https://www.smartkits.com.br/placa-esp32-c6-devkitc-wifi-zigbee-n4). Antena de PCB, sem conector. Dentro do tubo não alcança o Apple TV.
- ESP32-C6-MINI-1U. O conector é W.FL / IPEX MHF III, não o U.FL do pigtail comum.
- Módulo relé de um canal Matter. Liga carga. Aqui o que se precisa é pulsar um contato de painel e ler um LED.
- Módulo opto de 8 canais pronto, se o espaço apertar. Serve eletricamente ([Fermarc, R$ 42,50](https://www.fermarc.com/produto/modulo-optoacoplador-8-canais-pc817.html)), mas são dois módulos de ~45 × 38 mm. O DIP avulso cabe melhor.

## Antena

O XIAO tem cerâmica e U.FL, comutados por RF switch. Sem firmware a cerâmica fica selecionada. Para o U.FL, no boot: GPIO3 em baixo (habilita o switch) e GPIO14 em alto (seleciona o externo). Esses dois GPIO não entram no mapa dos optos.

Wi-Fi, BLE e 802.15.4 saem pela mesma antena. Um pigtail cobre Thread e Wi-Fi.
