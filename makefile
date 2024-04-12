# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Alvo padrão
all: programa_hello

# Regra de compilação
programa_hello: programa_hello.o
	$(CC) $(CFLAGS) programa_hello.o -o programa_hello

# Regra de compilação de objeto
programa_hello.o: programa_hello.c
	$(CC) $(CFLAGS) -c programa_hello.c

# Limpeza
clean:
	rm -f programa_hello programa_hello.o
