#ifndef TLISTAPLST_H_
#define TLISTAPLST_H_

#include "tPlaylist.h"

/// @brief uma lista de variaveis do tipo
/// tPlaylist
typedef struct ListaPlst tListaPlst;

/// @brief Cria uma lista, duplamente encadeada com sentinela,
/// de playlists.
/// @return A lista vazia criada.
/// @post uma variavel do tipo tListaPlst ocupando
/// um espaco valido de memoria
/// se a alocacao der errado, o programa sera encerrado
tListaPlst* CriaListaPlst();

/// @brief Libera a memoria alocada para uma lista valida
/// @param listaPlst a lista a ser deslocada
/// @pre listaPlst precisa ser diferente de NULL
/// @post o espaco de memoria usado por listaPlst
/// sera liberado
void DesalocaListaPlst(tListaPlst* listaPlst);

/// @brief Insere uma playlist numa lista de playlists
/// @param listaPlst uma lista valida de playlists que sera preenchida
/// @param plst uma playlisy valida que sera inserida
/// @pre listaPlst e plst precisam ser diferentes de NULL
/// @post listaPlst tera mais um elemento, sendo plst
/// adicionada em seu final
void InserePlstLista(tListaPlst* listaPlst, tPlaylist* plst);

/// @brief Obtem uma playlist de uma lista de playlists
/// com base em seu nome
/// @param listaPlst uma lista valida de playlists
/// @param nomePlst o nome da playlist desejada
/// @return o endereco da playlist obtida, NULL caso ela nao exista
/// @pre listaPlst e nomePlst precisam ser diferente de NULL
/// @post listaPlst permanecera intacta
tPlaylist* GetPlstLista(tListaPlst* listaPlst, char* nomePlst);

/// @brief Varre a lista de playlist e gera os arquivos
/// .txt de cada playlist com suas musicas
/// @param listaPLst uma lista de playlist valida
/// @param path caminho para a pasta do usuario que detem as playlists
/// @pre listaPlst e path precisam ser diferentes de NULL e path deve 
/// ser um caminho de diretorio valido 
/// @post listaPlst permanecera intacta, novos arquivos serao criados
/// no diretorio indicado por path
void GeraTodosArquivosComPlsts(tListaPlst* listaPlst, char* path);

/// @brief Retira o primeiro item da lista de palylists
/// @param listaPlst uma lista de palylists valida
/// @return a palylist retirada do inicio da lista
/// @pre listaPlst deve ser diferente de NULL
/// @post listaPlst tera um elemento a menos, com seu
/// tamanho decrementado e o primeiro elemento substituido
tPlaylist *PopPlstLista(tListaPlst* listaPlst);

/// @brief Realiza o refatoramento da playlist atual, inserindo o resultado
/// em refatorada
/// @param atual uma playlist valida que desaparecera 
/// @param refatorada uma playlist vazia valida
/// @pre atual e refatorada devem ser diferentes de NULL
/// @post atual (bem como suas playlists) sera desalocada, refatorada
/// sera preenchida com novas playlists, criadas com base em atual
void RefatoraListaPlaylist(tListaPlst* atual, tListaPlst* refatorada);

/// @brief Calcula a quantidade de musicas iguais entre as
/// playlists de duas listas de playlists
/// @param lUser1 uma lista valida de playlists
/// @param lUser2 uma lista valida de playlists
/// @return a quantidade de musicas iguais entre lUser1 e Luser2
/// @pre lUser1 e lUser2 devem ser diferente de NULL
/// @post lUser1 e lUser2 ficarao intactas
int CalculaSimilaridadeListasPlst(tListaPlst* lUser1, tListaPlst* lUser2);

/// @brief Imprime uma lista de playlist num arquivo
/// @param lPlst uma lista de playlists valida
/// @param arq um arquivo valido
/// @pre lPlst e arq devem ser diferentes de NULL
/// @post lPlst permanecera intacta, arq sera preenchido
/// com as informacoes impressas
void ImprimePlstArq(tListaPlst* lPlst, FILE* arq);

#endif