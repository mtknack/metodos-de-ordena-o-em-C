#include <stdio.h>
#include <stdlib.h>
#define N 5
#define True 1
#define False 0

void sortBolha(int *dados);
void imprime(int *dados);

int main(){
    int i, dados[N];
    for(i=0; i<N; i++){
        scanf("%d", &dados[i]);
    }

    sortBolha(&dados);
    imprime(dados); 
    return 0;
}

void sortBolha(int *dados){
    int i, j, aux, mudou ,indice, n = N;
    mudou = True;
    indice = n;
    while(mudou == True){
        j = 1;
        mudou = False;
        while(j < n){
            if(dados[j-1] > dados[j]){
                aux = dados[j-1];
                dados[j-1] = dados[j];
                dados[j] = aux;
                mudou = True;
            }
            indice = j;
            j = j + 1;
        }
        n = indice; //professor pq sem isso aki funciona normalmente?
    } 
}

void imprime(int *dados){
    int i;
    for(i=0; i<N; i++){
        printf(" %d,", dados[i]);
    }
}