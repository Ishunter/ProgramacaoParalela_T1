#include <math.h>
#include <pthread.h>
#include "lib/Lista.c"

typedef struct{
	int ini;
	int fim;
	lista_t* listaPrimos;
	lista_t* retorno;
} thread_data_t;

lista_t* crivo(int nThreads, int FIM);
void *threadCrivo(void* arg); 

/*
	Compilar: gcc -Wall Crivo_Pthread.c -o Crivo_Pthread -lpthread -lm;
	Entrada: int nThread, int FIM;
		nThread é o númerod e threads a serem utilizadas;
		FIM é o número limite a ser verificado os números primos de 2 até FIM;
*/
 
int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf(KRED "\tErro: Numero incorreto de argumentos.\n" KRESET);
		return 1; 
	}
		
	lista_t* primos = NULL;
	primos = criaLista(primos);
	primos = crivo(atoi(argv[1]), atoi(argv[2]));
	
	/* Caso queira imprimir os números primos descomente a linha abaixo */
	//exibe(primos);
	printf("\t\tQuantidade: %d\t\t\tTempo(s): ", primos->quantidade);
	return 0;
}

lista_t* crivo(int nThreads, int FIM){
	lista_t* primos;
	primos = NULL;

	/* Se FIM for menor que 5 retornamos uma lista com {2, 3} */
	if(FIM < 5){
		primos = criaLista(primos);
		insereInicio(primos, 3);
		insereInicio(primos, 2);
		return primos;
	}
	
	/* Senão, calculamos a raiz do FIM para aplicar o crivo de eratóstenes */
	int MAX = (int) sqrt(FIM);
	primos = crivo(nThreads, MAX);
	
	pthread_t tCrivos[nThreads];
	thread_data_t data_threads[nThreads];
	int i;

	/* Divide e calcula o resto das divisões dos valores acima do MAX nas threads */
	for(i=0; i < nThreads; i++){
		data_threads[i].ini = MAX;
		data_threads[i].fim = MAX+(FIM-MAX)/(nThreads-i);
		data_threads[i].listaPrimos = primos;
		pthread_create(&tCrivos[i], NULL, threadCrivo, &data_threads[i]);
		MAX = MAX+(FIM-MAX)/(nThreads-i)+1;
	}
	
	for(i=0; i < nThreads; i++){
		pthread_join(tCrivos[i], NULL);
	}	
	
	// União do resultado das Threads
	for(i=0; i < nThreads; i++){
		uniListas(primos, data_threads[i].retorno);
	}
	return primos;
}

/* Calcula a lista de primos de MAX até FIM dividindo pela lista de primos já existente*/
void *threadCrivo(void* arg) {
	thread_data_t *data = (thread_data_t *) arg;
	data->retorno = criaLista(data->retorno);

	short int flag;
	node_t* j;
	int i = data->ini;
	
	if(i%2 == 0) i++;
	for(; i <= data->fim; i+=2){
		flag = 1;
		for(j = data->listaPrimos->primeiro; j != NULL; j = j->proximo){
			if(i % j->valor == 0){
				flag = 0;
				break;
			}
		}
		if(flag) insereInicio(data->retorno, i);
	}

	pthread_exit(NULL);
}
