#ifndef TUSER_H_
#define TUSER_H_

/// @brief Estrutura que simula um usuario.
/// contem um nome, uma lista de usuarios 
/// (tlistaUser) para armazenar seus amigos
/// e uma lista de playlists (tListaPlst)
/// para armazenar suas playlists
typedef struct User tUser;

#define MAXTAM_NOME_USER 51

#include "tListaPlst.h"
#include "tListaUser.h"

/// @brief Cria dinamicamente um user
/// @param nomeUser o nome do user
/// @return um user inicializado com nome 
/// @pre nomeUser deve ser diferente de NULL
/// @post uma porcao valida do tamanho de tUser 
/// da memoria devera ser ocupada. Caso a alocao
/// de errado, o programa sera encerrado 
tUser* CriaUser(char* nomeUser);

/// @brief Desaloca a memória utilizada por um user
/// @param user o use que será desalocado
/// @pre user deve ser diferente de NULL
/// @post a memoria ocupada por user sera liberada
void DesalocaUser(tUser* user);

/// @brief Define amizade entre o user e seu amigo, 
/// inserindo este na lista de amigos daquele
/// @param user o user que ganhara um amigo
/// @param amigo o amigo do user
/// @pre user e amigo devem ser diferentes de NULL
/// @post amigo foi inserido na lista de amigos de user e,
/// apesar da amizade ser reciproca, o contrario nao acontecera
void SetAmizadeUser(tUser* user, tUser* amigo);

/// @brief Define um ID como ID do user
/// @param user um user válido
/// @param id um ID correspondente
/// @pre user precisa ser diferente de NULL
/// @post o user tera seu id modificado
void SetIDuser(tUser* user, int id);

/// @brief Define uma lista de playlists como 
/// a lista do user
/// @param user um user valido
/// @param plst uma playlist valida
/// @pre user e plst devem ser diferentes de NULL
/// @post a lista de playlists do user sera modificada
void SetListaPlstsUser(tUser *user, tListaPlst *plst);

/// @brief Verifica se o user2 esta na lista de amigos do user1
/// @param user1 um user valido
/// @param user2 um user valido supostamente amigo do user1
/// @return 1 se a amizade existir, 0 caso contrario
/// @pre user1 e user2 devem ser diferentes de NULL
int EhAmigoUser(tUser* user1, tUser* user2);

/// @brief Obtem o nome de um user valido
/// @param user um user valido
/// @return o nome do user
/// @pre user precisa ser diferente de NULL
char* GetNomeUser(tUser* user);

/// @brief Obtem a lista de playlists de um user
/// @param user um user valido
/// @return a lista de playlists de user
/// @pre user precisa ser diferente de NULL
tListaPlst* GetListaPlstUser(tUser* user);

/// @brief Obtem a lista de amigos de um user
/// @param user um user valido
/// @return a lista de amigos de user
/// @pre user precisa ser diferente de NULL
tListaUser* GetListaAmigosUser(tUser* user);

/// @brief Cria dinamicamente uma playlist e a insere
/// na lista de playlists do usuario
/// @param user um usuario valido
/// @param nomePlst o nome da playlist que sera criada
/// @param pathPlst o caminho para o arquivo da playlist em questao
/// @pre user, nomePlst e pathPlsts devem ser
/// diferentes de NULL
/// @post uma playlist criada e inserida 
/// no fim da lista de playlists de user
void AddPlaylistUser(tUser *user, char *nomePlst, char *pathPlsts);

/// @brief Gera todos os arquivos .txt das playlist de um usuario.
/// Esses arquivos contem as musicas da playlist.
/// @param user um usuario valido
/// @pre user e pathSaida precisam ser diferentes de NULL
/// @post arquivos serao gerados no diretorio apontado por 
/// pathSaida, user permanecera intacta
void GeraArquivosPlstsUser(tUser* user, char *pathSaida);

/// @brief Cria uma lista de playlists nova, refatora
/// refatora as playlists atuais do usuario e seta uma nova
/// lista de musicas
/// @param user 
/// @pre user deve ser diferente de NULL
/// @post user possui uma nova playlist, refatorada; 
/// a memoria ocupada pela antiga foi liberada
void RefatoraPlstsUser(tUser* user);

/// @brief Obtem o id de um usuario 
/// @param user um usuario valido
/// @return o id do usuario fornecido
/// @pre user precisa ser diferente de NULL
int GetIDUser(tUser *user);

/// @brief Obtem a lista de amigos de user 
/// @param user um usuario valido
/// @return a lista de amigos de user
/// @pre user precisa ser diferente de NULL
tListaUser* GetAmigosUser(tUser* user);

/// @brief Calcula a quantidade de musicas iguais entre
/// user1 e user2, e imprime o resultado em arq
/// @param user1 um usuario valido
/// @param user2 um usuario valido
/// @param arq um arquivo valido
/// @pre user1, user2 e arq precisam ser diferentes de NULL
/// @post arq preenchido com o resultado do calculo feito
void CalculaSimilaridadeUsers(tUser *user1, tUser *user2, FILE* arq);

/// @brief imprime as playlists de user em arq
/// @param user um usuario valido
/// @param arq um arquivo valido
/// @pre user e arq precisam ser diferentes de NULL
/// @post as playlists do user impressas em arq 
void InserePlstUserArquivoPLAYED(tUser* user, FILE* arq);

#endif