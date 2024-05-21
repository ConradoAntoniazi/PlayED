#ifndef TSISTEMA_H_
#define TSISTEMA_H_

#include "tListaUser.h"

/// @brief Estrutura que interliga todos
/// os tads e sera a interface para a main
/// contem uma lista de usuarios
typedef struct Sistema tSistema;

/// @brief Inicializa o sistema com base nas 
/// informacoes de usuarios passadas por arquivo
/// @param dir o caminho para o diretorio onde estara o 
/// arquivo com as informacoes do usuario
/// @return o sistema devidamente inicializado
/// @pre dir precisa ser um caminho valido de diretorio
/// @post uma variavel do tipo tSistema ocupara um espaco
/// valido de memoria 
tSistema* InicializaSistema(char* dir);

/// @brief Realiza o refatoramento e o calculo de similaridades
/// entre usuarios amigos (e imprime esses resultados em arquivos)
/// @param sis um sistema valido
/// @param pathSaida uma string valida
/// @pre sis e pathSaida devem ser diferentes de NULL e pathSaida deve
/// ser um caminho valido de diretorio
/// @post os usuarios do sistema terao suas playlists refatoradas, e arquivos
/// serao gerados no diretorio indicado por pathSaida
void ExecutaSistema(tSistema *sis, char* pathSaida);

/// @brief encerra o sistema, desalocando a memoria utilizando por
/// ele apos imprimir os dados dos seus usuarios
/// @param sis um sistema valido
/// @param pathSaida uma string valida 
/// @pre sis e pathSaida devem ser diferentes de NULL e pathSaida deve
/// ser um caminho valido de diretorio
/// @post arquivos serao gerados no diretorio indicado por pathSaida
/// e a memoria ocupada por sis sera liberada
void EncerraSistema(tSistema *sis, char *pathSaida);

#endif