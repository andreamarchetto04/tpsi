
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 1000000

int main()
{
    int numeri[DIM], numero = 0;
    FILE *file;
    srand(time(NULL));
    for (int i = 0; i < DIM; i++)
    {
        numero = rand() % DIM;
        for (int j = 0; j < i; j++)
        {
            if (numero == numeri[j])
            {
                i--;
                break;
            }
            else if (j == i - 1)
            {
                numeri[i] = numero;
                fprintf(file, "%d\n", numeri[i]);
            }
        }

    }

    fclose(file);
    return 0;
}
