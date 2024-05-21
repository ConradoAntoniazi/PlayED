#ifndef TMUSICA_H_
#define TMUSICA_H_

#define MAXTAM_NOME_ARTISTA 101
#define MAXTAM_NOME_DESCRICAO_MUSICA 201

#include <stdio.h>

typedef struct Musica tMusica;

/// @brief Cria uma musica dinamicamente, inicializando
/// a mesma com os parametros passados
/// @param artista o artista respectivo a musica
/// @param descricao a descricao respectiva a musica
/// @return A musica criada.
/// @pre artista e descricao devem ser diferentes de NULL
/// @post uma variavel do tipo tMusica ocupara um espaco
/// valido na memoria. Se a alocacao der errado, o programa 
/// sera encerrado
tMusica* CriaMsc(char* artista, char* descricao);

/// @brief Desaloca a memoria alocada para uma
/// variavel da estrutura tMusica
/// @param msc a musica que sera desalocada
/// @pre msc deve ser diferente de NULL
/// @post a memoria ocupada por msc sera liberada
void DesalocaMsc(tMusica* msc);

/// @brief Obtem o artista respectivo a musica
/// @param msc uma musica valida
/// @return o nome da mmusica passada por parametro
/// @pre msc precisa ser diferente de NULL
/// @post msc permanecera intacta
char* GetArtistaMsc(tMusica* msc);

/// @brief Obtem a descricao respectiva a musica
/// @param msc uma musica valida
/// @return a descricao da mmusica passada por parametro
/// @pre msc deve ser diferente de NULL
/// @post msc permanecera intacta
char* GetDescricaoMsc(tMusica* msc);

/// @brief Imprime a musica em um arquivo
/// @param arq um arquivo válido aberto em modo escrita
/// @param msc a musica que será impressa no arquivo
/// @pre arq e msc devem ser diferentes de NULL
/// @post msc permanecera intacta e informacoes serao
/// impressas em arq
void ImprimeMscArquivo(FILE* arq, tMusica* msc);

/// @brief Compara duas musicas e retonar se são iguais ou não
/// @param msc1 primeira musica da comparação
/// @param msc2 segunda musica da comparação
/// @return 1 se as musicas forem iguais, 0 caso contrário
/// @pre msc1 e msc2 devem ser diferentes de NULL
int EhMesmaMusica(tMusica* msc1, tMusica* msc2);

#endif