#include "tSistema.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_ARQ_AMIZADES "amizade.txt"
#define NOME_ARQ_PLAYLISTS "playlists.txt"
#define NOME_ARQ_SIMILARIDADES "similaridades.txt"
#define NOME_ARQ_PLAYED_REFATORADA "played-refatorada.txt"

#define MAXTAM_NOME_PLAYLIST 81
#define TAM_MAX_LINHA_AMIZADETXT 151

struct Sistema {
    tListaUser* usuarios;
};


//FUNCOES AUXILIARES

/// @brief Cria dinamicamente um sistema vazio 
/// @return uma variavel do tipo tSistema 
static tSistema* CriaSistema(){
    tSistema *s = (tSistema*) calloc(1, sizeof(tSistema));
    if(!s) TratarFalhaAlocacao("sistema");

    s->usuarios = CriaListaUser();

    return s;
}

/// @brief Cria dinamicamente e cadastra um user no sistema
/// @param sis um sistema valido
/// @param nomeUser o nome do user que sera cadastrado
static void CadastraUserSistema(tSistema* sis, char* nomeUser){
    if(!sis || !nomeUser) TratarStructNula("cadastrauser", "sistema ou char*");

    tUser *u = CriaUser(nomeUser);
    InsereUserLista(sis->usuarios, u);
    SetIDuser(u, getTamListaUser(sis->usuarios));
}

/// @brief Le quais serao os usuarios do sistema
/// e suas amizades, fazendo os cadastros e 
/// setando as amizades necessarias
/// @param sis um sistema valido sem usuarios
/// @param arq o arquivo valido onde constam as informacoes
/// acerca dos futuros usuarios do sistema
static void LeUsersSistema(tSistema* sis, FILE* arq){
    if(!sis || !arq) TratarStructNula("leUsersSistema", "sistema ou file*");
    while(1){
        char nomeUser[MAXTAM_NOME_USER];
        fscanf(arq, " %[^;\n]", nomeUser); 
        //printf("%s\n", nomeUser);
        CadastraUserSistema(sis, nomeUser);

        if(fgetc(arq) == '\n') break;
    }//leitura da primeira linha
    
    char nome1[MAXTAM_NOME_USER], nome2[MAXTAM_NOME_USER];
    char linha[TAM_MAX_LINHA_AMIZADETXT];
    while (fgets(linha, TAM_MAX_LINHA_AMIZADETXT, arq) != NULL){ //Lê o arquivo linha a linha
        sscanf(linha, "%[^;];%s", nome1, nome2);
    
        tUser *user1 = GetUserLista(sis->usuarios, nome1);
        tUser *user2 = GetUserLista(sis->usuarios, nome2);

        if(GetIDUser(user1) < GetIDUser(user2)) SetAmizadeUser(user1, user2);
        else SetAmizadeUser(user2, user1);
    }
}

/// @brief Le as informacoes das playlists que irao compor
/// sistema, aloca elas e as atribui aos respectivos donos
/// @param sis um sistema valido
/// @param dir um caminho valido para o diretorio
/// onde esta o arquivo com as playlists
static void LePlaylistsSistema(tSistema *sis, char *dir){
    if(!sis || !dir) TratarStructNula("leMusicasSistema", "Sistema ou char*");
    
    char pathPlst[strlen(dir) + strlen(NOME_ARQ_PLAYLISTS) + 2];
    sprintf(pathPlst, "%s/%s", dir, NOME_ARQ_PLAYLISTS);

    FILE *arqPlsts = fopen(pathPlst, "r");
    if(!arqPlsts) TratarFalhaAbertura("arqPlsts");

    char nomeUser[MAXTAM_NOME_USER], nomePlst[MAXTAM_NOME_PLAYLIST];
    int qtdPlst, c;
    tUser *user = NULL;
    while(1){
        fscanf(arqPlsts, "%[^;];%d;", nomeUser, &qtdPlst);
        user = GetUserLista(sis->usuarios, nomeUser);
    
        for(int i = 1; i <= qtdPlst; i++){
            if(i <= (qtdPlst - 1)){ // essa "gambiarra" se deu pela falta do \no fim do arquivo
                fscanf(arqPlsts, "%[^;]", nomePlst);
            }
            else{
                fscanf(arqPlsts, "%s", nomePlst);
            }
            AddPlaylistUser(user, nomePlst, dir);
            c = fgetc(arqPlsts);
        }
        if(c == EOF) break;
    }

    fclose(arqPlsts);
}

/// @brief Chama a função RefatoraListaUser para que
/// todos os usuarios do sistema tenham suas playlists
/// refatoradas
/// @param sis um sistema válido
static void RefatoraSistema(tSistema *sis, char* pathSaida){
    char path[strlen(pathSaida) + strlen(NOME_ARQ_PLAYED_REFATORADA) + 2];
    sprintf(path, "%s/%s", pathSaida, NOME_ARQ_PLAYED_REFATORADA);
    FILE* arq = fopen(path, "w");
    if(!arq) TratarFalhaAbertura("arq");

    RefatoraListaUser(sis->usuarios, arq);

    fclose(arq);
}

static void CalculaSimilaridadeSistema(tSistema *sis, char *pathSaida){
    char path[strlen(pathSaida) + strlen(NOME_ARQ_SIMILARIDADES) + 2];
    sprintf(path, "%s/%s", pathSaida, NOME_ARQ_SIMILARIDADES);
    FILE* arq = fopen(path, "w");
    if(!arq) TratarFalhaAbertura("arq");

    CalculaSimilaridadesListaUser(sis->usuarios, arq);
    fclose(arq);
}

/// @brief Chama a função GeraArquivosListaUser para que
/// seja gerado todos os arquivos de saida de casa usuario
/// do sistema
/// @param sis 
static void GeraArquivosSistema(tSistema* sis, char *pathSaida){
    if(!sis || !pathSaida)TratarStructNula("GeraArquivosSistema", "Sistema ou char");
    GeraArquivosListaUser(sis->usuarios, pathSaida);
}

////////

tSistema* InicializaSistema(char* dir){
    if(!dir) TratarStructNula("inicializaSistema", "char*");

    tSistema *sis = CriaSistema();

    char pathAmzd[strlen(dir) + strlen(NOME_ARQ_AMIZADES) + 2];
    sprintf(pathAmzd, "%s/%s", dir, NOME_ARQ_AMIZADES);

    FILE *arqAmzd = fopen(pathAmzd, "r");
    if(!arqAmzd)TratarFalhaAbertura("arqAmzd");

    LeUsersSistema(sis, arqAmzd);
    fclose(arqAmzd);

    LePlaylistsSistema(sis, dir);

    return sis;
}

/// @brief Desaloca a memoria ocupada por uma variavel 
/// do tipo sistema
/// @param sis um sistema valido
/// @pre sis precisa ser diferente de NULL
/// @post a memoria ocupada por sis sera liberada
static void DesalocaSistema(tSistema* sis){
    if(!sis) TratarStructNula("desaloca", "sistema");

    int tam = getTamListaUser(sis->usuarios);
    tUser *vet[tam];
    dumpUsersLista(vet, sis->usuarios);
    
    DesalocaListaUser(sis->usuarios);
    
    for(int i = 0; i < tam; i++){
        DesalocaUser(vet[i]);
    }
    free(sis);
}

void ExecutaSistema(tSistema *sis, char* pathSaida) {
    if(!sis)TratarStructNula("ExecutaSistema", "Sistema");

    RefatoraSistema(sis, pathSaida);
    CalculaSimilaridadeSistema(sis, pathSaida);
}

void EncerraSistema(tSistema *sis, char *pathSaida){
    if(!sis || !pathSaida)TratarStructNula("ExecutaSistema", "Sistema ou char*");
    
    GeraArquivosSistema(sis, pathSaida);
    DesalocaSistema(sis);
}