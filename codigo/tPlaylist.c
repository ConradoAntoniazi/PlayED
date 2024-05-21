#include "tPlaylist.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Playlist {
    char* nomePlst;
    tListaMsc* musicas;
};

tPlaylist* CriaPlst(char* nomePlst) {
    tPlaylist* plst = (tPlaylist*) calloc(1, sizeof(tPlaylist));

    if(plst == NULL) {
        TratarFalhaAlocacao("Playlist");
    }

    plst->nomePlst = strdup(nomePlst);
    plst->musicas = CriaListaMsc();

    return plst;
}

void DesalocaPlst(tPlaylist* plst) {
    if(!plst) TratarStructNula("Desaloca", "playlist");

    if(plst != NULL) {
        free(plst->nomePlst);
        DesalocaListaMsc(plst->musicas);
        free(plst);
    }
}

char* GetNomePlst(tPlaylist* plst) {
    if(!plst) TratarStructNula("getNome", "playlist");
    return plst->nomePlst; 
}

tListaMsc* GetListaMscPlst(tPlaylist* plst) {
    if(!plst) TratarStructNula("getListamscplyalist", "playlist");
    return plst->musicas;
}

void InsereMusicaPlst(tPlaylist *plst, tMusica *msc){
    if(!(plst && msc))TratarStructNula("addMusicaPlst", "playlist ou musica");
    InsereMscLista(plst->musicas, msc);
}

void GeraArquivoComPlst(tPlaylist* plst, char* path) {
    if(!plst) TratarStructNula("GeraArquivoComPlst", "tPlaylist");

    char pathPlst[strlen(path) + strlen(plst->nomePlst) + 6];
    sprintf(pathPlst, "%s/%s.txt", path, plst->nomePlst);

    FILE* arqPlst = fopen(pathPlst, "w");
    if(!arqPlst) TratarFalhaAbertura("arqPlst");

    ImprimeListaMscArquivo(plst->musicas, arqPlst);

    fclose(arqPlst);
}

int ContemMscPlst(tPlaylist* plst, tMusica* msc) {
    if(!plst || !msc) TratarStructNula("ContemMscPlst", "tPlaylist ou tMusica");

    return (ContemMscLista(plst->musicas, msc));
}

tMusica *PopMusicaPlaylist(tPlaylist *plst){
    if(!plst) TratarStructNula("popMusicaPlst", "tPlaylist");
    return PopMusicaLista(plst->musicas);
}

int CalculaSimilaridadePlsts(tPlaylist* plst1, tPlaylist* plst2) {
    if(!plst1 || !plst2) TratarStructNula("CalculaSimilaridadeEntrePlsts", "tPlaylist");

    return CalculaSimilaridadeListasMsc(plst1->musicas, plst2->musicas);
}