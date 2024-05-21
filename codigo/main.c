#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSistema.h"
#include "utils.h"

int main(int argc, char *argv[]){
    if(argc <= 1){
        tratarFaltaPath();
    }

    char *nomePastaEntrada = "Entrada";
    char *nomePastaSaida = "Saida";
    
    char *operandos = "mkdir -p";
    char comando[strlen(argv[1]) + strlen(operandos) + strlen(nomePastaSaida) + 2];
    sprintf(comando, "%s %s/%s", operandos, argv[1], nomePastaSaida);
    system(comando);

    char pathEntrada[strlen(argv[1]) + strlen(nomePastaEntrada) + 1];
    char pathSaida[strlen(argv[1]) + strlen(nomePastaSaida) + 1];

    sprintf(pathEntrada, "%s/%s", argv[1], nomePastaEntrada);
    sprintf(pathSaida, "%s/%s", argv[1], nomePastaSaida);

    tSistema *s = InicializaSistema(pathEntrada);
    ExecutaSistema(s, pathSaida);
    EncerraSistema(s, pathSaida);

    return 0;
}