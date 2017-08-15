## Trabalho 1 de Programação Paralela

Trabalho desenvolvido para a disciplina de programação paralela.

## Descrição

Código para descobrir números primos de 2 até N utilizando o Crivo de Eratóstenes feito sequencial, utilizando threads e o openmp para analisar e testar o desempenho entre eles. 

https://pt.wikipedia.org/wiki/N%C3%BAmero_primo<br />
https://pt.wikipedia.org/wiki/Crivo_de_Eratóstenes<br />
http://www.openmp.org/<br />
https://pt.wikipedia.org/wiki/OpenMP<br />

## Configurações e Observações

As configurações de entrada (input) e saída (output) estão dentro no run.sh

./Crivo_Sequencial<br />
	Entrada: int FIM<br />
		FIM é o número limite a ser verificado os números primos de 2 até FIM<br />

./Crivo_Openmp e ./Crivo_Pthread possuem:<br />
	Entrada: int nThread, int FIM<br />
		nThread é o número de threads a serem utilizadas<br />
		FIM é o número limite a ser verificado os números primos de 2 até FIM<br />

Os números primos estão sendo armazenados em uma variável int, então FIM não pode ser maior do que o limite da variável, alterando o tipo para long pode aumentar este limite mais também aumente significativamente o tempo de execução.

## Compilação e Execução

Pra compilar individualmente utilize os comandos:<br />
	make Crivo_Sequencial<br />
	make Crivo_Pthread<br />
	make Crivo_Openmp<br />

Também é possível utilizar o comando 'make all' onde ele vai compilar e executar.

Para executar utilize:<br />
	sh run.sh<br />

## Resultados

Com 8 Threads				Quantidade de Primos<br />
10⁸		0m5.722s			5,761,455<br />
10⁹		2m11.397s			50,874,534<br />
10¹⁰	3m36.136s 			455,052,511	(achou só 70,462,980)<br />

## Licença

MIT License

Copyright (c) [2016] [github.com/Ishunter/ - Lucas Martins Petroski]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

