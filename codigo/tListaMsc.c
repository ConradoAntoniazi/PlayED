#include "tListaMsc.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

typedef struct CelulaMsc tCelulaMsc;

struct CelulaMsc {
    tMusica* msc;
    tCelulaMsc* prox;
};

struct ListaMsc {
    tCelulaMsc* prim;
    tCelulaMsc* ult;
    int tam;
};

// FUNÇÕES DO TIPO TCELULA 
static tCelulaMsc* CriaCelMsc(tMusica* msc) {
    if(!msc) TratarStructNula("criaCelMsc", "tMusica");
    
    tCelulaMsc* celMsc = (tCelulaMsc*)calloc(1,sizeof(tCelulaMsc));
    if(!celMsc) TratarFalhaAlocacao("celulaMsc");

    celMsc->prox = NULL;
    celMsc->msc = msc;

    return celMsc;
}

static void DesalocaCelMsc(tCelulaMsc* cel) {
    if(!cel) TratarStructNula("DesalocaCelMsc", "celMsc"); 
    free(cel);
}

////

static int EstaVaziaListaMsc(tListaMsc *lm){
    if(!lm) TratarStructNula("EstaVaziaLista", "ListaMsc");
    return (lm->tam == 0);
}

tListaMsc* CriaListaMsc() {
    tListaMsc* listaMsc = (tListaMsc*)calloc(1,sizeof(tListaMsc));

    if(!listaMsc) TratarFalhaAlocacao("listaMsc");

    listaMsc->prim = listaMsc->ult = NULL;
    listaMsc->tam = 0;

    return listaMsc;
}

void DesalocaListaMsc(tListaMsc* listaMsc) {
    if(!listaMsc) TratarStructNula("desaloca", "listaMsc");

    if(listaMsc != NULL) {
        tCelulaMsc* aux = listaMsc->prim;
        tCelulaMsc* ant = NULL;
        while(aux != NULL){
            ant = aux;
            aux = aux->prox;
            DesalocaMsc(ant->msc);
            DesalocaCelMsc(ant);
        }
        free(listaMsc);
    }
}

void InsereMscLista(tListaMsc* listaMsc, tMusica* msc) {
    if(!listaMsc || !msc) TratarStructNula("insere", "tListaMsc ou tMusica");
    
    tCelulaMsc* celMsc = CriaCelMsc(msc);

    if(listaMsc->prim == NULL && listaMsc->ult == NULL){//lista vazia:
        listaMsc->prim = listaMsc->ult = celMsc;
        (listaMsc->tam)++;
    }
    
    else {
        listaMsc->ult->prox = celMsc;
        listaMsc->ult = celMsc;
        (listaMsc->tam)++;
    }
}

void ImprimeListaMscArquivo(tListaMsc* listaMsc, FILE* arq) {
    if(!listaMsc || !arq) TratarStructNula("ImprimeListaMscArquivo", "tListaMsc ou FILE");

    for(tCelulaMsc* cel = listaMsc->prim; cel != NULL; cel = cel->prox) {
        ImprimeMscArquivo(arq, cel->msc);
    }
}

int ContemMscLista(tListaMsc* listaMsc, tMusica* msc) {
    if(!listaMsc || !msc) TratarStructNula("ContemMscLista", "tListaMsc ou tMusica");

    for(tCelulaMsc* cel = listaMsc->prim; cel != NULL; cel = cel->prox) {
        if(EhMesmaMusica(cel->msc, msc)) return 1;
    }
    return 0;
}

tMusica *PopMusicaLista(tListaMsc* listaMsc){
    if(!listaMsc) TratarStructNula("PopMusicaLista", "listaMsc");

    tCelulaMsc *cel = NULL;
    tMusica *m = NULL;

    if(EstaVaziaListaMsc(listaMsc)){
        return m;
    }

    cel = listaMsc->prim;
    listaMsc->prim = cel->prox;
    m = cel->msc;

    DesalocaCelMsc(cel);
    (listaMsc->tam)--;
    
    return m;
}

int CalculaSimilaridadeListasMsc(tListaMsc* lMsc1, tListaMsc* lMsc2) {
    if(!lMsc1 || !lMsc2) TratarStructNula("CalculaSimilaridadeEntreListasMsc", "listaMsc");

    int similaridade = 0;

    for(tCelulaMsc* cel = lMsc1->prim; cel != NULL; cel = cel->prox) {
        if(ContemMscLista(lMsc2, cel->msc)) similaridade++;
    }

    return similaridade;
}