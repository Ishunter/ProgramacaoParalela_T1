CC = gcc
CFLAGS = -Wall -lm
DEPS = lib/Lista.c lib/Lista.h lib/Colours.h

all: Crivo_Sequencial Crivo_Pthread Crivo_Openmp
	@echo "\tExecutando ..."
	@sh run.sh
	@echo "\tExecução Terminada."

Crivo_Pthread: Crivo_Pthread.c $(DEPS)
	@echo "Compilando Pthread."
	@$(CC) Crivo_Pthread.c -o Crivo_Pthread -lpthread $(CFLAGS)

Crivo_Openmp: Crivo_Openmp.c $(DEPS)
	@echo "Compilando Openmp."
	@$(CC) Crivo_Openmp.c -o Crivo_Openmp -fopenmp $(CFLAGS)

Crivo_Sequencial: Crivo_Sequencial.c $(DEPS)
	@echo "Compilando Sequencial."
	@$(CC) Crivo_Sequencial.c -o Crivo_Sequencial $(CFLAGS)


