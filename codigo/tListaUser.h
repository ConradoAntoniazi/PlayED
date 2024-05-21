#ifndef TLISTAUSER_H_
#define TLISTAUSER_H_

/// @brief Uma lista de variaveis do tipo tUser
typedef struct ListaUser tListaUser;

#include "tUser.h"

/// @brief Cria uma lista, simplamente encadeada com sentinela,
/// de users.
/// @return A lista vazia criada.
/// @post uma variavel do tipo tListaUser ocupara um espaco
/// valido na memoria. Caso a alocacao nao de certo, o programa 
/// sera encerrado.
tListaUser* CriaListaUser();

/// @brief Desaloca a memoria alocada para 
/// uma lista de users
/// @param listaUser uma lista valida de users
/// @pre listaUser deve ser diferente de NULL
/// @post a memoria usada por listaUser sera liberada
void DesalocaListaUser(tListaUser* listaUser);

/// @brief Insere um user numa lista de users
/// @param listaUser uma lista valida de users
/// @param user um user valido que sera incluido
/// @pre listaUser e user devem ser diferentes de NULL
/// @post listaUser tera um elemento a mais, sendo user
/// adicionado em seu final
void InsereUserLista(tListaUser* listaUser, tUser* user);

/// @brief Obtem um user da lista com base em seu nome
/// @param listaUser uma lista valida de users
/// @param nomeUser o nome do user procurado
/// @return O user com o nome procurado, NULL caso ele 
/// nao seja encontrado
/// @pre listaUser e nomeUser devem ser diferentes de NULL
/// @post listaUser permancera intacta
tUser* GetUserLista(tListaUser* listaUser, char* nomeUser);

/// @brief Obtem o tamanho de uma lista de users
/// @param listaUser uma lista valida de users
/// @return o temanho de listaUser
/// @pre listaUser precisa ser diferente de NULL
int getTamListaUser(tListaUser *listaUser);

/// @brief Faz um dump dos usuarios de uma lista em um vetor
/// @param vet um vetor valido com um tamanho apropriado
/// @param listaUser uma variavel listaUser valida
/// @pre vet e listaUser devem ser diferentes de NULL
/// @post listaUser permanecera intacta, vet sera incrementada
/// com os usuarios de listaUser
void dumpUsersLista(tUser **vet, tListaUser *listaUser);

/// @brief Gera os arquivos de todos os usuarios da lista de usuarios
/// @param listaUser  uma listaUser válida
/// @param pathSaida um caminho de diretorio valido
/// @pre listaUser e pathSaida devem ser diferentes de NULL
/// @post listaUser permanecera intacta, arquivos serao gerados
/// no diretorio indicaod por pathSaida
void GeraArquivosListaUser(tListaUser* listaUser, char* pathSaida);

/// @brief Refatora as playlist de todos os usuarios da lista de usuarios
/// @param listaUser uma listaUser válida
/// @param arq um arquivo valido
/// @pre listaUser e arq devem ser diferentes de NULL
/// @post listaUser permanecera intacta, informacoes serao escritas
/// em arq
void RefatoraListaUser(tListaUser *listaUser, FILE* arq);

/// @brief Calcula a quantidade de musicas iguais entre os usuarios
/// de uma lista e seus respectivos amigos
/// @param listaUser uma lista valida de usuarios
/// @param arq um arquivo valido
/// @pre listaUser e arq devem ser diferentes de NULL
/// @post listaUser permanecera intacta, informacoes serao escritas
/// em arq
void CalculaSimilaridadesListaUser(tListaUser* listaUser, FILE* arq);

#endif