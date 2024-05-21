#include "tMusica.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

struct Musica {
    char* artista;
    char* descricao;
};

tMusica* CriaMsc(char* artista, char* descricao) {
    if(!artista || !descricao) TratarStructNula("cria", "musica");
    
    tMusica* msc = (tMusica*) calloc(1, sizeof(tMusica));
    if(!msc) TratarFalhaAlocacao("musica");
    
    msc->artista = strdup(artista);
    msc->descricao = strdup(descricao);

    return msc;
}

void DesalocaMsc(tMusica* msc) {
    if(!msc) TratarStructNula("desaloca", "musica");
    
    if(msc != NULL) {
        free(msc->artista);
        free(msc->descricao);
        free(msc);
    }
}

char* GetArtistaMsc(tMusica* msc) {
    if(!msc) TratarStructNula("getArtista", "musica");
    return msc->artista;
}

char* GetDescricaoMsc(tMusica* msc) {
    if(!msc) TratarStructNula("getDescricao", "musica");
    return msc->descricao;
}

void ImprimeMscArquivo(FILE* arq, tMusica* msc) {
    fprintf(arq, "%s - %s\n", msc->artista, msc->descricao);
}

int EhMesmaMusica(tMusica* msc1, tMusica* msc2) {
    if(!msc1 || !msc2) TratarStructNula("EhMesmaMusica", "tMusica");

    if(!strcmp(msc1->artista, msc2->artista) && !strcmp(msc1->descricao, msc2->descricao)) return 1;

    return 0;
}