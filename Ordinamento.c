#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
 
#define DIM 100

void riordinaCrescente(int array[], int partenza, int fine) {
    int temp;
    for(int i = partenza; i < fine; i++) {
        for(int j = partenza; j < fine; j++) {
       	    if(array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void riordinaDecrescente(int array[], int partenza, int fine) {
    int temp;
    for(int i = partenza; i < fine; i++) {
        for(int j = partenza; j < fine; j++) {
       	    if(array[j] < array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
  int a[DIM];
  int cntPari = 0;
  int cntDispari = 0;
  int temp;
  srand(time(0)); 
  
  for(int i = 0; i < DIM; i++) {
    a[i] = 1 + rand()%223;
    for(int j = 0; j < i; j++) {
       	if(a[i] == a[j]) {
           i--;
        }
    }
  }

    riordinaCrescente(a, 0, DIM);


  for(int i = 0; i < DIM; i++) {
      if(a[i] % 2 == 0){
        cntPari++;
      }
      else{
        cntDispari++;
      }
    }

    int p = 0;
    for(int i = 0; i < DIM; i++) {
        if(a[i] % 2 == 0) {
            if(p < cntPari || p < 20) {
                temp = a[p];
                a[p] = a[i];
                a[i] = temp;
                p++; 
            } 
            else{
                i = DIM;
            }	                  
        }            
    }

    int d = 20;
    for(int i = (DIM -1); i > 19; i--) {
        if(a[i] % 2 != 0) {
            if(d < (cntDispari + 20) || d < 40) {
                temp = a[d];
                a[d] = a[i];
                a[i] = temp;
                d++; 
            } 
            else{
                i = 19;
            }	                  
        }            
    }
    
    riordinaDecrescente(a, 20, 40);

    riordinaCrescente(a, 40, DIM);

    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", a[i]);
        if(i == 19 || i == 39) {
            printf("\n\n");
        }
    }
    printf("\n");

}
