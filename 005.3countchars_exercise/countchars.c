/*
 * countchar.c
 *
 *  Created on: 24 mar 2020
 *      Author: utente
 */
#include <stdio.h>


int main(int argc, char *argv[]) {

	// ESERCIZIO 1:
	// leggi da stdin fino a EOF e conta i caratteri: '\n', '\t' e ' '
	// dopo EOF, scrive su stdout il numero di occorrenze di ciascun carattere
	//
	printf("ASCII TABLE\n");
	printf("Dec 9  / char TAB   / HX 9 \n");
	printf("Dec 10 / char LF    / HX A \n");
	printf("Dec 32 / char Space / HX 20 \n");
	char SPECIAL[3] = {9,10,32};
	unsigned long counter[3] = {0, 0, 0};
	char c;
	printf("Inserisci caratteri: \n");
	while((c = getchar()) != EOF){
		for (int i = 0; i <sizeof(SPECIAL); i++){
			if(c == SPECIAL[i]){
				counter[i]++;
			}
		}
	}

	printf("Stampo numero di occorrenze per carattere speciale:");

	for (int j = 0; j < 3; j++){
		printf("\nPer carattere ASCII Dec '%d' ho %lu occorrenze.",SPECIAL[j], counter[j]);
		//printf("\nPer carattere ASCII '%c' ho %lu occorrenze.",SPECIAL[j], counter[j]);
	}

	return 0;
}


