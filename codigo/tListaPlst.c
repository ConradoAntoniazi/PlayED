#include "tListaPlst.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CelulaPlst tCelulaPlst;

struct CelulaPlst {
    tPlaylist* plst;
    tCelulaPlst* prox;
};


struct ListaPlst {
    tCelulaPlst* prim;
    tCelulaPlst* ult;
    int tam;
};

// FUNÇÕES DO TIPO TCELULA 
static tCelulaPlst* CriaCelPlst(tPlaylist* plst) {
    if(!plst) TratarStructNula("criaCel", "playlist");
    tCelulaPlst* celPlst = (tCelulaPlst*) calloc(1, sizeof(tCelulaPlst));

    if(!celPlst)TratarFalhaAlocacao("celPlst");

    celPlst->prox = NULL;
    celPlst->plst = plst;

    return celPlst;
}

static void DesalocaCelPlst(tCelulaPlst* cel) {
    if(!cel) TratarStructNula("DesalocaCelPlst", "celPlst"); 
    free(cel);
}

////

static int EstaVaziaListaPlst(tListaPlst *lp){
    if(!lp)TratarStructNula("EstaVaziaListaPlst", "ListaPlst");
    return(lp->tam == 0);
}

tListaPlst* CriaListaPlst() {
    
    tListaPlst* listaPlst = (tListaPlst*) calloc(1, sizeof(tListaPlst));
    if(!listaPlst) TratarFalhaAlocacao("listaPlst");

    listaPlst->prim = listaPlst->ult = NULL;
    listaPlst->tam = 0;

    return listaPlst;
}

void DesalocaListaPlst(tListaPlst* listaPlst) {
    if(!listaPlst) TratarStructNula("desaloca", "listaPlst");
    
    if(listaPlst != NULL) {
        tCelulaPlst* aux = listaPlst->prim;
        tCelulaPlst* ant = NULL;
        while (aux != NULL) {
            ant = aux;
            aux = aux->prox;
            DesalocaPlst(ant->plst);
            DesalocaCelPlst(ant); 
        }
        free(listaPlst);
    }
}

void InserePlstLista(tListaPlst* listaPlst, tPlaylist* plst) {
    if(!listaPlst || ! plst) TratarStructNula("inserePlst", "listaPlst ou Playlist");
    
    tCelulaPlst* celPlst = CriaCelPlst(plst);

    if(listaPlst->prim == NULL && listaPlst->ult == NULL){//lista vazia:
        listaPlst->prim = listaPlst->ult = celPlst;
        (listaPlst->tam)++;
    }

    else {
        listaPlst->ult->prox = celPlst;
        listaPlst->ult = celPlst;
        (listaPlst->tam)++;
    }
}

tPlaylist* GetPlstLista(tListaPlst* listaPlst, char* nomePlst) {
    if(!listaPlst || !nomePlst) TratarStructNula("getPlst", "listaPlst ou char*");

    for(tCelulaPlst* cel = listaPlst->prim; cel != NULL; cel = cel->prox) {
        if(EhMesmoTermo(nomePlst, GetNomePlst(cel->plst))) return cel->plst;
    }

    tPlaylist *p = NULL;
    return p;
}

void GeraTodosArquivosComPlsts(tListaPlst* listaPlst, char* path) {
    if(!listaPlst || !path) TratarStructNula("getPlst", "listaPlst ou char*");

    for(tCelulaPlst* cel = listaPlst->prim; cel != NULL; cel = cel->prox) {
        GeraArquivoComPlst(cel->plst, path);
    }
}

tPlaylist *PopPlstLista(tListaPlst* listaPlst){
    if(!listaPlst)TratarStructNula("popPlstLista", "ListaPlst");
    
    tCelulaPlst *cel = NULL;
    tPlaylist *p = NULL;
    
    if(EstaVaziaListaPlst(listaPlst)){
        return p;
    }

    cel = listaPlst->prim;
    listaPlst->prim = cel->prox;
    p = cel->plst;
    (listaPlst->tam)--;

    DesalocaCelPlst(cel);
    return p;
}

void RefatoraListaPlaylist(tListaPlst* atual, tListaPlst* refatorada){
    if(!atual || !refatorada)TratarStructNula("refatoraListaPlst", "tlistaPlst");
    
    while(1){
        tPlaylist *p = PopPlstLista(atual);
        if(!p) break;
        ///    
        while(1){
            tMusica *m = PopMusicaPlaylist(p);
            if(!m) break;
            
            char *nome = GetArtistaMsc(m);
            tPlaylist* plstAux = GetPlstLista(refatorada, nome);

            if(!plstAux){ //nao foi possivel encontrar uma playlist correspondente ao artista
                tPlaylist *nova = CriaPlst(nome);
                InsereMusicaPlst(nova, m);
                InserePlstLista(refatorada, nova);
            }
            else{
                if(!ContemMscPlst(plstAux, m)) InsereMusicaPlst(plstAux, m);
                else DesalocaMsc(m);
            }
        }
        DesalocaPlst(p);
    }
    DesalocaListaPlst(atual);
}

int CalculaSimilaridadeListasPlst(tListaPlst* lPlst1, tListaPlst* lPlst2) {
    if(!lPlst1 || !lPlst2)TratarStructNula("CalculaSimilaridadeEntreListasPlst", "tlistaPlst");

    int similaridade = 0;

    for(tCelulaPlst* cel = lPlst1->prim; cel != NULL; cel = cel->prox) {
        for(tCelulaPlst* cel2 = lPlst2->prim; cel2 != NULL; cel2 = cel2->prox) {
            if(EhMesmoTermo(GetNomePlst(cel->plst), GetNomePlst(cel2->plst))) similaridade += CalculaSimilaridadePlsts(cel->plst, cel2->plst);
        }
    }

    return similaridade;
}

void ImprimePlstArq(tListaPlst* lPlst, FILE* arq) {
    if(!lPlst)TratarStructNula("ImprimePlstArq", "tlistaPlst");

    fprintf(arq, "%d", lPlst->tam);
    for(tCelulaPlst* cel = lPlst->prim; cel != NULL; cel = cel->prox) {
        fprintf(arq, ";%s.txt", GetNomePlst(cel->plst));
    }
    fprintf(arq, "\n");
}