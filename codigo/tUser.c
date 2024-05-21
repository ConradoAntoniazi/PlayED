#include "tUser.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM_LINHA_PLTS_TXT (MAXTAM_NOME_ARTISTA + MAXTAM_NOME_DESCRICAO_MUSICA + 4)

struct User{
    char* nome;
    int id;
	tListaUser* amigos;
	tListaPlst* playlists;
};

tUser* CriaUser(char* nomeUser){
    if(!nomeUser) TratarStructNula("criaUser", "char*");
    
    tUser *u = (tUser*)calloc(1, sizeof(tUser));
    if(!u) TratarFalhaAlocacao("user");

    u->nome = strdup(nomeUser);
    if(!u->nome) TratarFalhaAlocacao("nomeUser");
    u->amigos = CriaListaUser();
    u->playlists = CriaListaPlst();

    return u;
}

void DesalocaUser(tUser* user){
    if(!user) TratarStructNula("desaloca", "user");

    free(user->nome);
    DesalocaListaUser(user->amigos);
    DesalocaListaPlst(user->playlists);
    free(user);
}

void SetListaPlstsUser(tUser *user, tListaPlst *listaPlsts){
    if(!user || !listaPlsts) TratarStructNula("SetListaPlstUser", "user ou plst");

    user->playlists = listaPlsts;
}

void SetAmizadeUser(tUser* user, tUser* amigo){
    if(!user || !amigo) TratarStructNula("setAmizadeUser", "User");

    InsereUserLista(user->amigos, amigo);
}

void SetIDuser(tUser* user, int id) {
    if(!user) TratarStructNula("setAmizadeUser", "user");

    user->id = id;
}

int EhAmigoUser(tUser* user1, tUser* user2){
    if(!user1 || !user2) TratarStructNula("ehamigouser", "user");

    return(GetUserLista(user1->amigos, user2->nome) != NULL);
}

char* GetNomeUser(tUser* user){
    if(!user)TratarStructNula("getnome", "user");
    return user->nome;
}

tListaPlst* GetListaPlstUser(tUser* user){
    if(!user)TratarStructNula("getListaPlt", "user");
    return user->playlists;
}

tListaUser* GetListaAmigosUser(tUser* user){
    if(!user)TratarStructNula("getListaAmigos", "user");
    return user->amigos;
}

static void preenchePlaylistUser(tPlaylist *plst, FILE *arqPlst){
    if(!plst || !arqPlst) TratarStructNula("preenchePlaylistUser", "playlist ou file");
    
    char linha[MAX_TAM_LINHA_PLTS_TXT];
    char artista[MAXTAM_NOME_ARTISTA], desc[MAXTAM_NOME_DESCRICAO_MUSICA];
    char *separador = " - ";
    char *fimNomeArtista = NULL;
    int tamNomeArtista = 0;
    
    while (fgets(linha, MAX_TAM_LINHA_PLTS_TXT, arqPlst) != NULL){
        int fimLinha = strlen(linha);
        if(fimLinha > 0 && linha[fimLinha - 1] == '\n'){
        	linha[strlen(linha) -1] = '\0';
        }
        
        fimNomeArtista = strstr(linha, separador);
        tamNomeArtista = fimNomeArtista - linha;//distancia do comeco ao separador " - "
        strncpy(artista, linha, tamNomeArtista);
        artista[tamNomeArtista] = '\0';
        
        strcpy(desc, (fimNomeArtista + strlen(separador)));
        tMusica *nova = CriaMsc(artista, desc);
        InsereMusicaPlst(plst, nova);
    }
}

void AddPlaylistUser(tUser *user, char *nomePlst, char *pathPlsts){
    if(!(user && nomePlst && pathPlsts)) TratarStructNula("addPlstUser", "user ou char*");

    tPlaylist *p = CriaPlst(nomePlst);

    char pathPlst[strlen(pathPlsts) + strlen(nomePlst) + 2];
    sprintf(pathPlst, "%s/%s", pathPlsts, nomePlst);

    FILE *arqPlst = fopen(pathPlst, "r");
    if(!arqPlst) TratarFalhaAbertura("arqPlst");

    preenchePlaylistUser(p, arqPlst);
    fclose(arqPlst);

    InserePlstLista(user->playlists, p);
}

void GeraArquivosPlstsUser(tUser* user, char *pathSaida){
    if(!user || !pathSaida)TratarStructNula("GeraArquivosPlstsUser", "user ou char*");

    char pathUser[strlen(user->nome) + strlen(pathSaida) + 3];
    sprintf(pathUser, "%s/%s", pathSaida, user->nome);

    GeraTodosArquivosComPlsts(user->playlists, pathUser);
}

void RefatoraPlstsUser(tUser* user){
    tListaPlst* listaRef = CriaListaPlst();

    RefatoraListaPlaylist(user->playlists, listaRef);

    user->playlists = listaRef;
}

int GetIDUser(tUser *user){
    if(!user)TratarStructNula("getID", "user");
    return user->id;
}

tListaUser* GetAmigosUser(tUser* user) {
    if(!user)TratarStructNula("GetAmigosUser", "user");
    return user->amigos;
}

void CalculaSimilaridadeUsers(tUser *user1, tUser *user2, FILE* arq){
    int similaridade = 0;

    similaridade = CalculaSimilaridadeListasPlst(user1->playlists, user2->playlists);

    fprintf(arq, "%s;%s;%d\n", GetNomeUser(user1), GetNomeUser(user2), similaridade);
}

void InserePlstUserArquivoPLAYED(tUser* user, FILE* arq) {
    if(!user)TratarStructNula("GeraArquivoPLAYED", "user");

    fprintf(arq, "%s;", user->nome);
    ImprimePlstArq(user->playlists, arq);
}