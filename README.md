# 🎶 PlayED 🎶
## 1º trabalho prático - Estruturas de dados
Alunos: Conrado Antoniazi dos Santos e Raphael Correia Dornelas.

# Índice 

* [Introdução](#intro)
* [Guia de Instalação](#instalacao)
* [Arquitetura e implementação](#implementacao)
* [Conclusão](#conclusao)
* [Bibliografia](#bibliografia)

<a id="intro"></a>
## 1. Introdução 📘

Este documento descreve o primeiro trabalho prático da disciplina de Estruturas de Dados, desenvolvido pelos alunos Conrado Antoniazi dos Santos e Raphael Correia Dornelas. O projeto consiste na criação de um sistema básico de amizades para um aplicativo de streaming de músicas, utilizando conceitos de estrutura de dados em linguagem C. O programa lê dados de amizade e playlists de uma pasta "Entrada" e realiza diversas operações, como refatoração de playlists e cálculo de similaridade entre amigos.

<a id="instalacao"></a>
## 2. Guia de Instalação 🛠️

### Pré-requisitos:
- **GCC (GNU Compiler Collection):** Compilador utilizado para compilar os arquivos fonte em C.
- **Make:** Ferramenta para automatizar o processo de compilação.

### Instruções de Instalação:
1. Abra o terminal no diretório do projeto.
2. Execute o comando `make` para compilar o projeto, gerando o executável `main`.
3. Execute o comando `make run`, que solicitará o caminho para o diretório da pasta "Entrada" e executará o programa com esse caminho como argumento.
4. Para excluir o executável gerado, use o comando `make clean`.

<a id="implementacao"></a>
## 3. Arquitetura do Sistema 🏗️

O sistema utiliza uma lista simplesmente encadeada com sentinela como estrutura de dados principal. A modularidade e clareza são garantidas através do uso de Tipos Abstratos de Dados (TADs), e a alocação dinâmica é empregada para gerenciar eficientemente a memória.

### Tipos Abstratos Implementados:
- **tMusica** 🎵
- **tPlaylist** 📜
- **tUser** 👤
- **tSistema** 🖥️

### Estruturas de Dados:
- **tListaMsc:** Manipulação de listas de músicas.
- **tListaPlst:** Manipulação de listas de playlists.
- **tListaUser:** Manipulação de listas de usuários.

### Visão Geral das Bibliotecas e Funções Principais:

#### tMusica.h / tMusica.c
- **GetArtistaMsc:** Retorna o campo de artista de uma música.
- **GetDescricaoMsc:** Retorna o campo de descrição de uma música.
- **EhMesmaMusica:** Compara duas músicas e verifica se são iguais.

---

#### tListaMsc.h / tListaMsc.c
- **InsereMscLista:** Insere uma música em uma lista de músicas.
- **ImprimeListaMscArquivo:** Imprime todas as músicas de uma lista em um arquivo.
- **ContemMscLista:** Verifica se uma lista de músicas contém uma música específica.
- **PopMusicaLista:** Retira o primeiro item da lista de músicas.

---

#### tPlaylist.h / tPlaylist.c
- **GetNomePlst:** Retorna o nome da playlist.
- **GetListaMscPlst:** Retorna a lista de músicas da playlist.
- **InsereMusicaPlst:** Adiciona uma música a uma playlist.
- **ContemMscPlst:** Verifica se uma playlist contém uma música específica.
- **PopMusicaPlaylist:** Retira a primeira música da playlist.
- **CalculaSimilaridadePlsts:** Calcula a quantidade de músicas iguais entre duas playlists.

---

#### tListaPlst.h / tListaPlst.c
- **InserePlstLista:** Insere uma playlist em uma lista de playlists.
- **GeraTodosArquivosComPlsts:** Gera arquivos texto de cada playlist com suas músicas.
- **RefatoraListaPlaylist:** Refatora a lista de playlists, gerando novas listas separadas por artistas.
- **PopPlstLista:** Retira o primeiro item da lista de playlists.

---

#### tUser.h / tUser.c
- **GetNomeUser:** Retorna o nome de um usuário.
- **GetListaAmigosUser:** Retorna a lista de amigos de um usuário.
- **GetListaPlaylistsUser:** Retorna a lista de playlists de um usuário.
- **SetAmizadeUser:** Adiciona um amigo à lista de amigos de um usuário.
- **EhAmigoUser:** Verifica se dois usuários são amigos.
- **AddPlaylistUser:** Cria e adiciona uma playlist à lista de playlists do usuário.
- **GeraArquivosPlstsUser:** Gera arquivos texto das playlists de um usuário.
- **RefatoraPlstsUser:** Refatora e substitui a lista de playlists do usuário.
- **CalculaSimilaridadeUsers:** Calcula a quantidade de músicas iguais entre amigos e imprime no arquivo "similaridade.txt".

---

#### tListaUser.h / tListaUser.c
- **dumpUsersLista:** Insere todos os usuários de uma lista em um vetor.
- **RefatoraListaUser:** Refatora todos os usuários de uma lista e insere seus dados em um arquivo.
- **CalculaSimilaridadesListaUser:** Calcula a quantidade de músicas iguais entre todos os usuários e seus amigos.

#### tSistema.h / tSistema.c
- **inicializaSistema:** Inicializa e retorna uma nova instância do sistema.
- **executaSistema:** Realiza o refatoramento das playlists, calcula similaridades entre usuários e gera arquivos de saída.
- **EncerraSistema:** Finaliza o sistema, gerando arquivos de saída e liberando recursos alocados.

---

#### Utils.c / Utils.h
- **TratarStructNula:** Encerra o programa se uma variável não inicializada for detectada.
- **TratarFalhaAlocacao:** Encerra o programa em caso de falha na alocação de memória.
- **TratarFalhaAbertura:** Encerra o programa se um arquivo não puder ser aberto.
- **EhMesmoTermo:** Verifica se duas strings são idênticas.
- **tratarFaltaPath:** Encerra o programa se o caminho para a pasta "Entrada" não for fornecido.

<a id="conclusao"></a>
## 4. Conclusão 📊

A execução do projeto demonstrou a importância de uma compreensão sólida dos conceitos de estruturas de dados. Desafios como a leitura precisa das informações das músicas e a alocação eficiente de memória foram superados. A colaboração em equipe foi essencial para o sucesso do projeto, promovendo clareza no código e trabalho conjunto eficiente.

<a id="bibliografia"></a>
## 5. Bibliografia 📚

C library function - strstr() - Tutorialspoint. Disponível em: <https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm>.

Conversa com o ChatGPT sobre leitura de arquivos e defines a partir de outros defines, usada como suporte: 
https://chatgpt.com/share/9beb410c-71aa-49d4-901d-a254a941b153 