#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa(int array[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void stampaFrequenza(int array[], int dim) 
{
    int cnt = 0;
    for (int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(array[i] == array[j])
            {
                cnt++;
            }
        }
        printf("Numero: %d, ripetizioni %d.\n", array[i], cnt);
        cnt = 0;
    }
}

void eliminaDoppioni(int array[], int *dim)
{
 
    int cnt = 0;
    for (int i = 0; i < (*dim) - cnt ; i++)
    {
        for(int j = i+1; j < (*dim) -cnt; j++)
        {
            if(array[i] == array[j])
            {
                for(int k = j; k < (*dim)- cnt -1; k++) 
                {
                    array[k] = array[k+1];
                }
                cnt++;
                i--;
            }
            
        }
    }
    (*dim) -= cnt;
}

int main() {
    int dim;
    int scelta;
    printf("Inserisci dimensione dell'array\n");
    scanf("%d", &dim);
    printf("1) Stampa la frequenza dei caratteri\n"
    "2) Elimina i numeri che si ripetono\n"
    "3) Ordini i numeri dispari in ordine crescente e i pari in ordine decrescente\n");
    scanf("%d", &scelta);
    int array[dim], numero;
    srand(time(NULL));
    for(int i = 0; i < dim; i++) {
        numero = rand() % dim;
        array[i] = numero;
        printf("\n%d", array[i]);
    }
    if(scelta == 1) {
        printf("\n1) Stampa la frequenza dei caratteri\n");
        stampaFrequenza(array, dim);
    }
    else if(scelta == 2) {
        printf("\n2) Elimina i numeri che si ripetono\n");
        eliminaDoppioni(array, &dim);
        stampa(array, dim);
    }
    else if(scelta == 3) {

        printf("\n3) Ordini i numeri dispari in ordine crescente e i pari in ordine decrescente\n");
        for(int i = 0; i < dim; i++) {
            for(int j = i+1; j < dim; j++){
                if(array[j] %2 == 0 && array[i] %2 == 0 && array[i] < array[j]){
                    int k = array[i];
                    array[i] = array[j];
                    array[j] = k;
                }
                else if(array[j] %2 != 0 && array[i] %2 != 0 && array[i] > array[j]){
                    int k = array[i];
                    array[i] = array[j];
                    array[j] = k;
                }
            }
        }

        stampa(array, dim);
    }
}
