/**
 * @file verification.c
 * @brief Contém as implementações das verificações das primitivas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "primitives.h"
#include "verification.h"

/**
* Checa se o nome da primitiva existe e chama as respectivas funções passando os respectivos argumentos
* @param name Nome da primitiva
* @param arguments Argumentos da primitiva
*/
void checkPrimitive(char *name, char *arguments[100]) {
    if (strcmp(name, "image") == 0){
        image(atoi(arguments[0]), atoi(arguments[1]));
    }
    if (strcmp(name, "color") == 0){
        color(atoi(arguments[0]), atoi(arguments[1]), atoi(arguments[2]));
    }
    if (strcmp(name, "clear") == 0){
        clear(atoi(arguments[0]), atoi(arguments[1]), atoi(arguments[2]));
    }
    if (strcmp(name, "circle") == 0){
        cicle(atoi(arguments[0]), atoi(arguments[1]), atoi(arguments[2]));
    }
    if (strcmp(name, "polygon") == 0){
        polygon(arguments);
    }
    if (strcmp(name, "fill") == 0){
        fill(atoi(arguments[0]), atoi(arguments[1]));
    }
    if (strcmp(name, "save") == 0){
        save(arguments[0]);
    }
    if (strcmp(name, "line") == 0){
        line(atoi(arguments[0]), atoi(arguments[1]), atoi(arguments[2]), atoi(arguments[3]));
    }
    if (strcmp(name, "open") == 0){
        open(arguments[0]);
    }
    if (strcmp(name, "flip") == 0) {
        flip(arguments[0]);
    }
    if (strcmp(name, "rotate") == 0){
        rotate(atoi(arguments[0]));
    }
    if (strcmp(name, "move") == 0){
        move(arguments[0], atoi(arguments[1]));
    }
}

/**
* Extrai os argumentos da primitiva através da linha lida através da função readPrimitesFile
* @param primitiveLine Linha recebida pela função readPrimitesFile, que contém os argumentos da primitiva separados por espaço
*/
void extractArgumentsPrimitive(char *primitiveLine) {
	char delimiter[] = " ";
	char *primitiveName = strtok(primitiveLine, delimiter);
	char *primitiveArgument = strtok(NULL, delimiter);
    char *primitiveArguments[100] = {};
    int i = -1;

    while (primitiveArgument != NULL) {
        i++;
        primitiveArguments[i] = removeBreakLine(primitiveArgument);
		primitiveArgument = strtok(NULL, delimiter);
	}
    checkPrimitive(primitiveName, primitiveArguments);
}

/**
* Ler o arquivo de primitivas, e chama a função extractArgumentsPrimitive para extrair as primitivas encontradas
*/
void readPrimitesFile() {
    char primitiveLine[100];
  
    FILE *arq;
    // Abre um arquivo TEXTO para LEITURA
    arq = fopen("primitives", "r");
    // Se houve erro na abertura
    if (arq == NULL) {
        printf("Problemas na abertura do arquivo\n");
        exit(0);
    }
    while (fgets(primitiveLine, 100, arq) != NULL){
        extractArgumentsPrimitive(primitiveLine);
    }
    fclose(arq);
}