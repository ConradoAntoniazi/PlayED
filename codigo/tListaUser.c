#include "tListaUser.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CelulaUser tCelulaUser;

struct CelulaUser {
    tUser* user;
    tCelulaUser* prox;
};

struct ListaUser {
    tCelulaUser* prim;
    tCelulaUser* ult;
    int tam;
};

// FUNÇÕES DO TIPO TCELULA
static tCelulaUser* CriaCelUser(tUser* user){
    if(!user) TratarStructNula("criaCelUser", "user");
    
    tCelulaUser* celUser = (tCelulaUser*) calloc(1, sizeof(tCelulaUser));

    if(!celUser) TratarFalhaAlocacao("celUser");

    celUser->prox = NULL;
    celUser->user = user;

    return celUser;
}

static void DesalocaCelUser(tCelulaUser* cel){
    if(cel != NULL) free(cel);
}

static void CalculaSimilaridadeAmigosUser(tUser* user, tListaUser *amigos, FILE* arq){
    if(!amigos) TratarStructNula("CalculaSimilaridades", "ListaUser");
    tCelulaUser *cel = NULL;

    for(cel = amigos->prim; cel != NULL; cel = cel->prox){
        CalculaSimilaridadeUsers(user, cel->user, arq);
    }
}
////

tListaUser* CriaListaUser() {
    tListaUser* listaUser = (tListaUser*) calloc(1, sizeof(tListaUser));

    if(!listaUser) TratarFalhaAlocacao("listaUser");

    listaUser->prim = listaUser->ult = NULL;
    listaUser->tam = 0;

    return listaUser;
}

void DesalocaListaUser(tListaUser* listaUser) {
    if(!listaUser) TratarStructNula("desaloca", "listaUser");

    if(listaUser != NULL) {
        tCelulaUser* aux = listaUser->prim;
        tCelulaUser* ant = NULL;
        while(aux != NULL) {
            ant = aux;
            aux = aux->prox;
            DesalocaCelUser(ant);
        }
        free(listaUser);
    }
}

void InsereUserLista(tListaUser* listaUser, tUser* user) {
    if(!listaUser || !user) TratarStructNula("insereUserLista", "tlistaUser ou tUser");
    
    tCelulaUser* celUser = CriaCelUser(user);

    if(listaUser->prim == NULL && listaUser->ult == NULL){ //lista vazia:
        listaUser->prim = listaUser->ult = celUser;
        (listaUser->tam)++;
    }
    
    else {
        listaUser->ult->prox = celUser;
        listaUser->ult = celUser;
        (listaUser->tam)++;
    }
}

tUser* GetUserLista(tListaUser* listaUser, char* nomeUser) {
    if(!listaUser || !nomeUser) TratarStructNula("GetUserLista", "tlistaUser ou char*");
    
    for(tCelulaUser* cel = listaUser->prim; cel != NULL; cel = cel->prox) {
        if(EhMesmoTermo(GetNomeUser(cel->user), nomeUser)) return cel->user;
    }

    printf("Nao foi possivel encontrar o user desejado na lista\n");
    tUser *u = NULL;
    return u;
}

int getTamListaUser(tListaUser *listaUser){
    if(!listaUser) TratarStructNula("getTam", "listaUser");
    return listaUser->tam;
}

void dumpUsersLista(tUser **vet, tListaUser *listaUser){
    if(!vet || !listaUser) TratarStructNula("dumpUsersLista", "vet ou listaUser");
    
    int i = 0;
    for(tCelulaUser *cel = listaUser->prim; cel != NULL; cel = cel->prox){
        vet[i] = cel->user;
        i++;
    }
}

void GeraArquivosListaUser(tListaUser* listaUser, char* pathSaida){
    if(!listaUser || !pathSaida) TratarStructNula("GeraArquivosListaUser", "listaUser ou char*");

    char *operandosComando = "mkdir -p";
    tUser *u = NULL;
    for(tCelulaUser* cel = listaUser->prim; cel != NULL; cel = cel->prox) {
        u = cel->user;
        
        char comando[strlen(operandosComando) + strlen(pathSaida) + MAXTAM_NOME_USER + 2];
        sprintf(comando, "%s %s/%s", operandosComando, pathSaida, GetNomeUser(u));
        system(comando);
        
        GeraArquivosPlstsUser(u, pathSaida);
    }
}

void RefatoraListaUser(tListaUser *listaUser, FILE* arq) {
    if(!listaUser) TratarStructNula("RefatoraListaUser", "listaUser");

    for(tCelulaUser* cel = listaUser->prim; cel != NULL; cel = cel->prox) {
        RefatoraPlstsUser(cel->user);
        InserePlstUserArquivoPLAYED(cel->user, arq);
    }
}

void CalculaSimilaridadesListaUser(tListaUser* listaUser, FILE* arq) {
    if(!listaUser) TratarStructNula("CalculaSimilaridadesListaUser", "listaUser");

    for(tCelulaUser* cel = listaUser->prim; cel != NULL; cel = cel->prox) {
        CalculaSimilaridadeAmigosUser(cel->user, GetAmigosUser(cel->user), arq);
    }
}