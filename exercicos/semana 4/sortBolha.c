#include <stdio.h>
#include <stdlib.h>
#define N 5

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
    int i, j, aux;
    for(i=N-1; i>=1; i--){ 
        for(j=0; j<i; j++){
            if(dados[j] > dados[j+1]){
                aux = dados[j];
                dados[j] = dados[j+1];
                dados[j+1] = aux;
            }
        }
    }
}

void imprime(int *dados){
    int i;
    for(i=0; i<N; i++){
        printf(" %d,", dados[i]);
    }
}