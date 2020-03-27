/*
 * getchar_reverse.c
 *
 *  Created on: 24 mar 2020
 *      Author: utente
 */
#include <stdio.h>
#include <stdlib.h>


void swap(char *x, char *y);
char * reverse(char * array, unsigned int i, unsigned int j);
char * complete_reverse(char * array, unsigned int array_len);



int main(int argc, char *argv[]) {

	// ESERCIZIO 2:

	// scrivere il seguente programma:

	// legge e salva tutti i dati provenienti da stdin fino a EOF
	int counter = 0;
	int size = 10;
	char c;
	char* str;
	str = calloc(size, sizeof(char));

	// è necessario controllare se calloc ha funzionato:
	if (str == NULL) {
		perror("calloc error!");
		exit(EXIT_FAILURE);
	}

	while ((c = getchar()) != EOF) {

				counter++;
				if(counter >= size){
					str = realloc(str,(size+1)*sizeof(char)); // rialloca spazio lasciando inalter
					printf("La dimensione adesso è %d\n", size+1);
					if (str == NULL) {
						perror("realloc error!");
						exit(EXIT_FAILURE);
					}
					//rato i valori nelle posizioni precedenti
					size++;
				}
				str[counter] = c;
			}

	// poi scrive su stdout i dati accumulati ma all'incontrario (dall'ultimo al primo)

	// suggerimenti: .....
	complete_reverse(str, size);

	printf("contenuto dell'array char_array dopo complete_reverse():\n");
	for (int i = 0; i < size; i++) {
		//printf("'%c'(%d) ", str[i], str[i]);
		printf("%c", str[i]);
	}
	printf("\n");

	free(str);

	return 0;
}

// function to swap two char
void swap(char *x, char *y) {
	char t = *x;
	*x = *y;
	*y = t;
}

// function to reverse array[i..j]
char * reverse(char * array, unsigned int i, unsigned int j)
{
//	while (i < j)
//		swap(&array[i++], &array[--j]);

	while (i < j) {
		j--;
		swap(&array[i], &array[j]);
		i++;
	}

	return array;
}

char * complete_reverse(char * array, unsigned int array_len) {
	return reverse(array, 0, array_len);
}
