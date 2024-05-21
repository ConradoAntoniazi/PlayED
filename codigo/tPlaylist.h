#ifndef TPLAYLIST_H_
#define TPLAYLIST_H_

#include "tMusica.h"
#include "tListaMsc.h"

/// @brief Estrutura que contem um nome e 
/// uma lista de musicas (tListaMsc) 
typedef struct Playlist tPlaylist;

/// @brief Inicializa uma playlist vazia
/// @param nomePlst nome que sera atribuido a playlist
/// @return Uma playlist vazia alocada e nomeada
/// @pre nomePlst deve ser diferente de NULL
/// @post uma variavel do tipo tPlaylist ocupara um espaco
/// valido na memoria. Se a alocacao der errado, o programa
/// sera encerrado
tPlaylist* CriaPlst(char* nomePlst);

/// @brief Desaloca uma playlist valida
/// @param plst playlist a ser deslocada
/// @pre plst deve ser diferente de NULL
/// @post a memoria ocupada por plst sera liberada
void DesalocaPlst(tPlaylist* plst);

/// @brief obtem o nome de uma playlist valida
/// @param plst playlist a qual se busca nome
/// @return A nome da playlist
/// @pre plst deve ser diferente de NULL
char* GetNomePlst(tPlaylist* plst);

/// @brief obtem a lista de musicas de uma playlist valida
/// @param plst playlist a qual se busca lista de musicas
/// @return A lista de musicas da playlist
/// @pre plst deve ser diferente de NULL
tListaMsc* GetListaMscPlst(tPlaylist* plst);

/// @brief Adiciona uma musica a uma playlist
/// @param plst uma playlist valida
/// @param msc uma musica valida 
/// @pre plst e msc devem ser diferentes de NULL
/// @post plst tera seu tamanho incrementado, sendo msc
/// adicionada no seu fim
void InsereMusicaPlst(tPlaylist* plst, tMusica* msc);

/// @brief Gera o arquivo .txt com mesmo nome da playlist dada
/// e escreve todas as musicas da playlist no arquivo 
/// @param plst uma playlist valida
/// @param path caminho ate a pasta de nome igual ao do
/// usuario que contem a playlist dada
/// @pre plst e path devem ser diferentes de NULL
/// @post plst permanecera intacta, arquivos serao gerados no 
/// diretorio indicado por path
void GeraArquivoComPlst(tPlaylist* plst, char* path);

/// @brief verifica se uma playlist contém uma musica específica
/// @param plst uma playlist válida
/// @param msc uma música válida
/// @return  retorna 1 para caso a musica esteja na playlist e 0 para o caso contrário
/// @pre plst e msc devem ser diferentes de NULL
int ContemMscPlst(tPlaylist* plst, tMusica* msc);

/// @brief Retira a primeira musica da playlist
/// @param plst uma playlist valida
/// @return a primeira musica da playlist
/// (ou NULL caso ela nao existir)
/// @pre plst precisa ser diferente de NULL
/// @post o primeiro item de plst sera desalocado, e
/// o tamanho de plst sera decrementado
tMusica *PopMusicaPlaylist(tPlaylist *plst);

/// @brief Calcula a quantidade de musicas iguais 
/// entre duas playlists
/// @param plst1 uma playlist valida
/// @param plst2 uma playlist valida
/// @return a quantidade de musicas iguais entre 
/// plst1 e plst2
/// @pre plst1 e plst2 devem ser diferentes de NULL
/// @post plst1 e plst2 permanecerao intactos
int CalculaSimilaridadePlsts(tPlaylist* plst1, tPlaylist* plst2);

#endif