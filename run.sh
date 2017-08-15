#!/bin/bash

# Define as variaveis
OUTPUT="resultados"					# Arquivo de saida
VEZES="3"							# Quantas repetições cada thread vai fazer
THREADS="10"						# Fazer de 1 até quantas threads?
NUMERO="100000000"					# Numero a ser visto os Primos

(
echo "De 2 até $NUMERO"
for a in $(seq $VEZES);
do 
	echo -n "    Sequencial";
	bash -c "TIMEFORMAT='%3R'; time ./Crivo_Sequencial "$NUMERO"";
done;
echo "";
echo "Número de Threads: 1";
for b in $(seq $VEZES);
do
	echo -n "    Pthread\t";
	bash -c "TIMEFORMAT='%3R'; time ./Crivo_Pthread "1" "$NUMERO""; 
done; 
echo "";
for c in $(seq $VEZES);
do
	echo -n "    OpenMP\t";
	bash -c "TIMEFORMAT='%3R'; time ./Crivo_Openmp "1" "$NUMERO"";
done; 
for i in $(seq 2 $THREADS);
do 
	echo "\nNúmero de Threads: $i";
	for j in $(seq $VEZES);
	do 
		echo -n "    Pthread\t";  
		bash -c "TIMEFORMAT='%3R'; time  ./Crivo_Pthread "$i" "$NUMERO"";
	done;
	echo "";
	for j in $(seq $VEZES);
	do
		echo -n "    OpenMP\t";
		bash -c "TIMEFORMAT='%3R'; time ./Crivo_Openmp "$i" "$NUMERO"";
	done;
done;
) > $OUTPUT 2>&1
