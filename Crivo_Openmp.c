#include <math.h>
#include <omp.h>
#include "lib/Lista.c"

lista_t* crivo(int nThreads, int MAX);

/*
	Compilar: gcc -Wall Crivo_Openmp.c -o Crivo_Openmp -fopenmp -lm;
	Entrada: int nThread, int FIM;
		nThread é o númerod e threads a serem utilizadas;
		FIM é o número limite a ser verificado os números primos de 2 até FIM;
*/

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf(KRED "\tErro: Numero incorreto de argumentos.\n" KRESET);
		return 0; 
	}
	
	// Iniciando variaveis
	int nThreads = atoi(argv[1]);
	int FIM = atoi(argv[2]);	
	lista_t* primos = NULL;
	omp_set_num_threads(nThreads);

	primos = crivo(nThreads, FIM);

	/* Caso queira imprimir os números primos descomente a linha abaixo */
	//exibe(primos);
	printf("\t\tQuantidade: %d\t\t\tTempo(s): ", quantidade(primos));
	
	return 0;
}

lista_t* crivo(int nThreads, int MAX) {
	lista_t* primos = NULL;
	primos = criaLista(primos);
	lista_t* p;

	if(MAX < 5){
		insereInicio(primos,2);
		insereInicio(primos,3);
		return primos;
	}
	
	int flag = 1, i, MIN = (int) sqrt(MAX);
	primos = crivo(nThreads, MIN);
	MIN++;
	
	if(MIN%2==0) MIN++;
	#pragma omp parallel private (p)
	{
		node_t* node = NULL;
		p = NULL;
		p = criaLista(p);
		#pragma omp for private (node, i, flag) schedule (dynamic)
		for(i = MIN; i <= MAX; i+=2){
			flag = 1;
			node = primos->primeiro;
			do{
				if(i % node->valor == 0){
					flag = 0;
					break;			
				}
				node = node->proximo;
			} while (node != NULL);		
			if(flag) {
				insereInicio(p, i);
			}
		}
		#pragma omp critical
		{
			uniListas(primos,p);
		}
	}
	return primos;
}
