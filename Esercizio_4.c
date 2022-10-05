#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DIM 50

void stampaStringa(char stringa[]) {
    for (int i = 0; i < strlen(stringa); i++)
    {
        printf("%c", stringa[i]);
    }
    printf("\n");
}

int controllaLettere(char stringa[])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (isalpha(stringa[i]) == 0)
        {
            return -1;
        }
    }
    return 1;
}

int contaVocali(char stringa[])
{
    char lett[1];
    int cnt = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        char lett[1] = Tolower(stringa[i]);
        if (lett[0] == 'a' || lett[0] == 'i' || lett[0] == 'e' || lett[0] == 'o' || lett[0] == 'u')
        {
            cnt++;
        }
    }
    return cnt;
}

int contaConsonanti(char stringa[])
{
    char lett[1];
    int cnt = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        lett[0] = tolower(stringa[i]);
        if (lett[0] != 'a' || lett[0] != 'i' || lett[0] != 'e' || lett[0] != 'o' || lett[0] != 'u')
        {
            cnt++;
        }
    }
    return cnt;
}

int contaLettera(char stringa[])
{
    char lett[1];
    int cnt = 0;
    printf("Inserisci la lettera da cercare\n");
    scanf("%s", lett);
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (lettera[0] == stringa[i])
        {
            cnt++;
        }
    }
    if(cnt == 0) {
        printf("Lettera non presente nella stringa perchè\n");
    }
    else {
        printf("Lettera presente nella stringa,\n");
    }
    return cnt;
}

void creaNuoveStringhe(char stringa[], char s1[], char s2[])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if ((i % 2) == 0)
        {
            strncat(s1, &stringa[i], 1);
        }
        else
        {
            strncat(s2, &stringa[i], 1);
        }
    }
}

int controllaDoppie(char stringa[])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        for (int j = i + 1; j < strlen(stringa); j++)
        {
            if (stringa[i] == stringa[j])
            {
                return 1;
            }
        }
    }
    return -1;
}

int controllaLunghezza(char stringa1[], char stringa2[])
{
    int diff = (strlen(stringa1) - strlen(stringa2));
    return diff;
}

void contaDoppie(char s1[], char s2[], int *salvaIndirizzo[])
{
    int *salvaIndirizzo[DIM];
    salvaIndirizzo[0] = -1;
    int k = 0;
    for (int i = 0; i < strlen(s1); i++)
    {
        for (int j = 0; j < strlen(s2); j++)
        {
            if (s1[i] == s2[j])
            {
                salvaIndirizzo[k] = i;
                k++;
            }
        }
    }
}

int main()
{
    char stringa1[DIM], stringa2[DIM], stringaPari[DIM], stringaDispari[DIM];
    int salvaIndice[DIM];
    int scelta, l, v1, v2, c1, c2;

    printf("Inserisci prima stringa\n");
    scanf("%s", stringa1);
    printf("1) verifica che contenga solo lettere\n");
    printf("2) conta il numero di vocali nella stringa\n");
    printf("3) conta il numero di consonanti\n");
    printf("4) conta una lettera (se presente) scelta dell'utente\n");
    printf("5) crea 2 ulteriori stringhe che contengono 1 le lettere di posizione pari; la 2° le lettere di posizione dispari\n");
    printf("6) verifica se contiene lettere doppie\n");
    scanf("%d", &scelta);
    printf("Ecco la prima stringa:\n");
    stampaStringa(stringa1);

    switch (scelta)
    {
        case 1:
            if (controllaLettere(stringa1) == -1)
            {
                printf("Errore, non ci sono solo lettere\n");
            }
            else
            {
                printf("Ci sono solo lettere\n");
            }
            break;
        case 2:
            printf("Vocali presenti: %d\n", contaVocali(stringa1));
            break;
        case 3:
            printf("Consonanti presenti: %d\n", contaConsonanti(stringa1));
            break;
        case 4:
            printf("Trovata %d volte\n", contaLettera(stringa1));
            break;
        case 5:
            creaNuoveStringhe(stringa1, stringaPari, stringaDispari);
            printf("Stringa che contiene le lettere di posizione pari: %s\n", stringaPari);
            printf("Stringa che contiene le lettere di posizione dispari: %s\n", stringaDispari);
            break;
        case 6:
            if (controllaDoppie(stringa1) == -1)
            {
                printf("La stringa non contiene lettere doppie\n");
            }
            else
            {
                printf("La stringa contiene lettere doppie\n");
            }
            break;
    }

    printf("Inserisci una seconda stringa\n");
    scanf("%s", stringa2);
    printf("1) verifica quale delle due stringhe è la più lunga e più corta\n");
    printf("2) verifica quali sono le lettere contenute in ambedue le stringhe\n");
    printf("3) verifica quale delle due stringhe contentiene più vocali\n");
    printf("4) verifica quale delle due stringhe contentiene più consonanti\n");
    scanf("%d", &scelta);
    printf("Ecco la seconda stringa:\n");
    stampaStringa(stringa1);

    switch (scelta)
    {
        case 1:
            if (l == (controllaLunghezza(stringa1, stringa2)) > 0){
                printf("La stringa più lunga è la prima");
            }
            else if(l == 0){
                printf("Le stringhe hanno la stessa lunghezza\n");
            }
            else {
                printf("La stringa più lunga è la seconda\n");
            }
            break;

        case 2:
            contaDoppie(stringa1, stringa2, salvaIndice);
            if(salvaIndice[0] == -1) {
                printf("non ci sono lettere comuni tra le due stringhe");
            }
            else{
                printf("Le lettere contenute in ambedue le stringhe sono:");
                for(int i = 0; i < strlen(*salvaIndice); i++) {  
                    int j =  salvaIndice[i];      
                    printf("%c", stringa1[j]); 
                }
            }  
            break;
        case 3:
            if ((v1 = contaVocali(stringa1)) > (v2 = contaVocali(stringa2)))
            {
                printf("La prima stringa contiene più vocali\n");
            }
            else if (v1 < v2)
            {
                printf("La seconda stringa contiene più vocali\n");
            }
            else
            {
                printf("Le stringhe contengono lo stesso numero di vocali\n");
            }
            break;
        case 4:
            if ((c1 = contaConsonanti(stringa1)) > (c2 = contaConsonanti(stringa2)))
            {
                printf("La prima stringa contiene più consonanti\n");
            }
            else if (c1 < c2)
            {
                printf("La seconda stringa contiene più consonanti\n");
            }
            else
            {
                printf("Le stringhe contengono lo stesso numero di consonanti\n");
            }
            break;
    }
    return 0;
}

