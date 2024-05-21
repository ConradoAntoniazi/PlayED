#ifndef TLISTAMSC_H_
#define TLISTAMSC_H_

#include "tMusica.h"
#include <stdio.h>

/// @brief Estrutura que funcionara como uma lista de 
/// variaves do tipo tMusica 
typedef struct ListaMsc tListaMsc;

/// @brief Cria uma lista, simplamente encadeada com sentinela,
/// de musicas.
/// @return A lista vazia criada.
/// @post Uma lista corretamente alocada sera criada
/// se a alocacao der errado, o programa sera encerrado
tListaMsc* CriaListaMsc();

/// @brief Desaloca a memoria
/// usada por uma lista de musicas valida
/// @param listaMsc a lista a ser deslocada
/// @pre listaMsc precisa estar devidamente alocada na memoria
/// @post a memoria alocada para listaMsc eh liberada
void DesalocaListaMsc(tListaMsc* listaMsc);

/// @brief Insere uma musica valida numa lista valida de musicas
/// @param listaMsc a lista que sera preenchida
/// @param msc a musica a ser incluida
/// @pre listaMsc e msc precisam estar devidamente alocadas na memoria
/// @post msc sera inserida em listaMsc
void InsereMscLista(tListaMsc* listaMsc, tMusica* msc);

/// @brief Imprime todas as musicas de uma lista de musicas
/// em um arquivo dado
/// @param listaMsc Lista que contem todas as musicas que serao
/// imprimidas no arquivo
/// @param arq arquivo valido aberto no modo escrita
/// @pre listaMsc e arq precisam ser diferente de NULL
/// @post a lista permanecera intacta e o arquivo continuara aberto
void ImprimeListaMscArquivo(tListaMsc* listaMsc, FILE* arq);

/// @brief verifica se uma lista de musicas contém uma musica específica
/// passada como parâmetro
/// @param listaMsc uma lista de musicas válida
/// @param msc uma musica válida
/// @return retorna 1 para caso a musica esteja na lista e 0 para o caso contrário
/// @pre listaMsc e msc precisa ser diferente de NULL
/// @post listaMsc msc continuarao intactas
int ContemMscLista(tListaMsc* listaMsc, tMusica* msc);

/// @brief Retira o primeiro item da lista de musicas
/// @param listaMsc uma lista de musicas valida
/// @return a musica retirada do inicio da lista
/// @pre listaMsc precisa ser diferente de NULL
/// @post listaMsc tera seu primeiro elemento retirado, ficando menor
/// seu tamanho sera decrementado e sua primeira celula desalocada
tMusica *PopMusicaLista(tListaMsc* listaMsc);

/// @brief Calcula a quantidade de musicas iguais entre as
/// playlist de dois users
/// @param lUser1 um user valido
/// @param lUser2 um user valido
/// @return A quantidade de musicas iguais entre os dois users
/// passados por parametro
/// @pre lUser1 e lUser2 precisam ser diferentes de NULL
/// @post lUser1 e lUser2 continuarao intactos 
int CalculaSimilaridadeListasMsc(tListaMsc* lUser1, tListaMsc* lUser2);

#endif