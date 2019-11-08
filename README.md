# PaintC
Ferramenta de desenho gráfico em C

## Tipos de dados utilizados
 - typedef
 - struct
 - int
 - char
 - void

## Considerações iniciais
***
O programa possui um arquivo chamado `primitives`, em que nele são específicados as primitivas suportadas descritas mais adiante

## Como compilar o programa
***
```
gcc main.c -o main
```

## Como executar o programa
***
```
./main
```

## Primitivas suportadas
***
### Criar uma nova “imagem”, com a largura e altura especificadas
```
image 100 100
```
> Irá criar uma imagem com o nome padrão "image.ppm" nas dimensões especificadas, largura e altura, respectivamente

### Salvar a imagem atual em um arquivo usando o formato ppm
```
save imageTest.ppm
```
> Irá salvar uma imagem com o nome especificado

### Abre uma imagem no formato ppm e carrega essa imagem no programa para futuras operações de desenho
```
open imageTest.ppm
```
> Irá abrir um arquivo PPM para operações

### Especifica os dois pontos das extremidades da linha a ser desenhada, cada um com suas coordenadas (x, y) - `WIP`
```
line 0 400 600 200
```
