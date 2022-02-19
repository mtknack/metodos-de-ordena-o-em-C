#include <stdio.h>
#include <stdlib.h>
#define n 5

int BuscarSequencial(int *vetor, int x);

int main(){
    int vet[n+1], i, chave, retorno;

    for(i=0; i<n; i++){
        printf("digite o valor %d\n", i);
        scanf("%d", &vet[i]);
    }

    printf("digite o valor a procurar\n");
    scanf("%d", &chave);

    retorno = BuscarSequencial(vet, chave);
    
    if(retorno == -1){
        printf("nao existe\n");
    }
    else{
        printf("encontrado : %d\n", retorno);
    }

    return 0;
}

int BuscarSequencial(int *vetor, int x){
    int i;
    vetor[n] = x;
    for(i=0; vetor[i] != x; i++){
    }

    if(i < n){
        return vetor[i];
    }
    else{
        return -1;
    }
}