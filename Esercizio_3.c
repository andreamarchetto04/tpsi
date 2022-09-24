#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int main() {
    int dim;
    printf("Inserisci dimensione dell'array\n");
    scanf("%d", &dim);
    int array[dim], numero;
    srand(time(NULL));
    for(int i = 0; i < dim; i++) {
        numero = rand() % dim;
        array[i] = numero;
    }
    printf("1) Stampa degli elementi array\n");
    for(int i = 0; i < dim; i++) {
        printf("%d\n", array[i]);
    }
    printf("2) Stampa inversa degli elementi dell’array\n");
    for(int i = dim-1; i > -1; i--) {
        printf("%d\n", array[i]);
    }
    printf("3) Somma e media degli elementi del vettore\n");
    int somma;
    int media;
    for(int i = 0; i < dim; i++) {
        somma += array[i];
    }
    media = somma/dim;
    printf("la somma e':%d\nla media e':%d\n", somma, media);
    printf("4) Stampa tutti i numeri pari\n");
    for(int i = 0; i < dim; i++) {
        if(array[i] % 2 == 0) {
            printf("%d\n", array[i]);
        }       
    }
    printf("5) Stampa tutti i numeri dispari\n");
    for(int i = 0; i < dim; i++) {
        if(array[i] % 2 != 0) {
            printf("%d\n", array[i]);
        }       
    }
    printf("6) Ricerca di un numero nell’array (letto in input)\nInserisci il numero da cercare\n");
    int n;
    int cont = 0;
    scanf("%d", &n);
    for(int i = 0; i < dim; i++) {
        if(array[i] == n) {
            cont = cont + 1;
        }       
    }
    printf("Trovato %d volte\n", cont);
    printf("7) Eliminare un elemento dell’array (se esistente)\nInserisci numero da eliminare\n");
    int e;
    int dime;
    scanf("%d", &e);
    for(int i = 0; i < dim; i++) {
        while(array[i] = e) {
            dime = dim - 1;
            for(int j = i; j < dime; j++) {
                array[j] = array[j+1];                    
            }   
        }       
    }
    for(int i = 0; i < dime; i++) {
        printf("%d\n", array[i]);
    }
    
 }
