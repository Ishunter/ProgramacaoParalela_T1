#include <math.h>
#include "lib/Lista.c"

lista_t* crivo(int FIM);
 
/* 
	Compilar: gcc -Wall Crivo_Sequencial.c -o Crivo_Sequencial -lm;
	Entrada: int FIM;
		FIM é o número limite a ser verificado os números primos de 2 até FIM;
*/
int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf(KRED "\tErro: Numero incorreto de argumentos.\n" KRESET);
		return 1; 
	}
			
	lista_t* primos = NULL;
	primos = criaLista(primos);
	primos = crivo(atoi(argv[1]));
	
	/* Caso queira imprimir os números primos descomente a linha abaixo */
	//exibe(primos);
	printf("\t\tQuantidade: %d\t\t\tTempo(s): ", primos->quantidade);
	return 0;
}

lista_t* crivo(int FIM){
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
	primos = crivo(MAX);
	
	lista_t* retorno = NULL;
	retorno = criaLista(retorno);
	short int flag;
	node_t* j;
	
	int i = MAX++;
	if(i%2 == 0) i++;
	for(; i <= FIM; i+=2){
		flag = 1;
		for(j = primos->primeiro; j != NULL; j = j->proximo){
			if(i % j->valor == 0){
				flag = 0;
				break;
			}
		}
		if(flag) insereInicio(retorno, i);
	}
	
	// União do resultado
	uniListas(primos, retorno);

	return primos;
}

