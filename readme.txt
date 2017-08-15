As configurações de input e output estão dentro no run.sh
Para compilar e executar é só ir até a pasta e usar o make (compila e executa o run.sh)

Pra compilar individualmente é só usar os comandos:
	make Crivo_Sequencial
	make Crivo_Pthread
	make Crivo_Openmp

./Crivo_Sequencial
	Entrada: int FIM
	FIM é o número limite a ser verificado os números primos de 2 até FIM

./Crivo_Openmp e ./Crivo_Pthread possuem:
		Entrada: int nThread, int FIM
		nThread é o númerod e threads a serem utilizadas
		FIM é o número limite a ser verificado os números primos de 2 até FIM
