#include <stdio.h>
#include <stdlib.h>
#define n 5

int BuscarSequencial(int *vetor, int x);
void PrintVet(int *vetor);

int main(){
    int vet[n], i, chave, retorno;

    for(i=0; i<n; i++){
        printf("digite o valor %d\n", i);
        scanf("%d", &vet[i]);
    }

    // vet[0]= 1;
    // vet[1]= 2;
    // vet[2]= 3;
    // vet[3]= 4;
    // vet[4]= 5;

    printf("digite o valor a procurar\n");
    scanf("%d", &chave);

    // chave = 4;

    retorno = BuscarSequencial(vet, chave);
    
    if(retorno == -1){
        printf("nao existe\n");
    }
    else{
        printf("encontrado : %d\n", retorno);
    }

    PrintVet(vet);

    return 0;
}

int BuscarSequencial(int *vetor, int x){
    int i, j, aux;
    for(i=0; i<n; i++){
        if(vetor[i] == x){
            for(j=i; j>0; j--){
                vetor[j] = vetor[j-1];
            }
            vetor[j] = x;
        }
    }
    return -1;
}

void PrintVet(int *vetor){
    int i;
    for(i=0; i<n; i++){
        printf("%d :", vetor[i]);
    }
}