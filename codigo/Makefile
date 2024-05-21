# Nome do compilador
CC = gcc

# Nome do executável
TARGET = main

# Lista de arquivos fonte (usando expansão de shell para pegar todos os .c)
SRCS = $(wildcard *.c)

# Regra padrão para criar o executável
$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS)

# Regra para rodar o programa com um argumento
.PHONY: run
run: $(TARGET)
	@read -p "Caminho para o diretorio da pasta 'Entrada': " arg; \
	./$(TARGET) $$arg

# Limpa os arquivos gerados durante a compilação
.PHONY: clean
clean:
	rm -f $(TARGET)

