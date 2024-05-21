#ifndef _UTILS_H_
#define UTILS_H_

/**
 * Encerra o programa apos avisar a funcao onde isso
 * ocorreu e de qual estrutura se trata
 * @pre nomeFuncao e nomeStruct precisam ser 
 * diferentes de NULL
 * @post o programa encerrado
*/
void TratarStructNula(const char *nomeFuncao, const char *nomeStruct);

/**
 * Encerra o programa apos indicar o tipo 
 * de dado que iria ser alocado
 * @pre nomeSruct deve ser diferente de NULL
 * @post o programa encerrado
*/
void TratarFalhaAlocacao(const char *nomeStruct);

/**
 * Encerra o programa apos indicar o nome
 * do arquivo que iria ser aberto
 * @pre nomeArquivo deve ser diferente de NULL
 * @post o programa encerrado
*/
void TratarFalhaAbertura(const char *nomeArquivo);

/**
 * Compara dois termos validos e diz se sao iguais.
 * @pre str1 e str2 devem ser diferentes de NULL
*/
int EhMesmoTermo(char *str1, char*str2);

/**
 * Informa ao usuario sobre a falta de um caminho
 * para o diretorio de entrada e encerra o programa
 * @post o programa encerrado
*/
void tratarFaltaPath();

#endif