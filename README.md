# coifa-mt

Retrofit Matter para a coifa de ilha EOS Maxxi Air **EMCO41IRI** (inox) e **EMCO41IRP** (preta).

O painel original permanece. Quatro optoacopladores pulsam os botões momentâneos em paralelo. Outros quatro leem o LED de cada botão, que é o estado real da função. Um XIAO ESP32-C6 publica isso como luz On/Off e ventilador de três marchas, em Thread ou Wi-Fi.

Não há vínculo com a EOS. Abrir o aparelho encerra a garantia de 12 meses do termo do fabricante.

## O que este repositório guarda

| Caminho | Conteúdo |
|---|---|
| [docs/01-contexto.md](docs/01-contexto.md) | Aparelho, botões, o que não fazer |
| [docs/02-bom.md](docs/02-bom.md) | Lista de materiais e links de compra |
| [docs/03-espaco-mecanico.md](docs/03-espaco-mecanico.md) | Bolso entre as barras em L e a parede do tubo |
| [docs/04-esquema.md](docs/04-esquema.md) | Esquema e hipótese de polaridade |
| [docs/05-montagem.md](docs/05-montagem.md) | Ordem de montagem e isolamento |
| [docs/06-matter.md](docs/06-matter.md) | Endpoints, Thread, Apple Home e Home Assistant |
| [docs/07-medicoes.md](docs/07-medicoes.md) | Medidas obrigatórias antes de soldar |
| [hardware/schematic.svg](hardware/schematic.svg) | Esquema da hipótese ativa em baixo |
| [firmware/](firmware/) | Esqueleto PlatformIO para completar depois |

## Decisões já tomadas

- Não interromper o triac do motor (~410 W). Só simular o toque e ler o LED.
- Placa: Seeed XIAO ESP32-C6. O DevKitC barato com WROOM-1 não tem conector de antena.
- Antena externa U.FL fora do tubo de aço, no forro. Wi-Fi 6, BLE e Thread compartilham o mesmo rádio.
- Alimentação isolada (B0505S-2W). A fonte da coifa pode ser não isolada.
- Border router previsto: Apple TV a cerca de 7 m. Home Assistant entra como segundo fabric Matter.

## O que ainda depende de medida

A polaridade dos botões e dos LEDs não está no manual. O esquema assume botão fechando para GND e LED ativo em alto. Confirmar com [docs/07-medicoes.md](docs/07-medicoes.md) antes de fechar a placa.

## Firmware

O diretório `firmware/` compila a estrutura, não o produto. Pinos, pulso, confirmação pelo LED e os endpoints Matter estão marcados. Clonar e continuar a partir daí:

```sh
git clone https://github.com/1Ale/coifa-mt.git
cd coifa-mt/firmware
```

## Segurança

Desligar da tomada antes de abrir. Não alimentar o ESP por USB com a coifa ligada na rede. Não há GND em comum entre o lado da coifa e o lado do rádio.
