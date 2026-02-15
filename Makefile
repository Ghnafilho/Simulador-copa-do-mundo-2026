# Variáveis de Configuração
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = simulador_copa

# Arquivos Fonte e Objetos
# Adicione aqui outros arquivos .c se houver (ex: funcoes_amigo.c)
SRCS = main.c data.c
OBJS = $(SRCS:.c=.o)
HEADERS = utils.h

# Regra padrão (compila tudo)
all: $(TARGET)

# Linkagem final do executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilação dos arquivos .c em .o
# A dependência $(HEADERS) garante que se o .h mudar, tudo seja recompilado
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos temporários e do executável
clean:
	rm -f $(OBJS) $(TARGET)

# Regra para rodar o programa após compilar
run: all
	./$(TARGET)