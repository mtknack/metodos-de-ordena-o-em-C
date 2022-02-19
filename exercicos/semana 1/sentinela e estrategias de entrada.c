#include <stdio.h>
#include <stdlib.h>
#define n 5

int BuscarSequencial(int *vetor, int x);
int BuscarSequencialEstrategias(int *vetor, int x);
int BuscarSequencialEstrategias2(int *vetor, int x);
void PrintNum(int *retorno);
void PrintVet(int *vetor);

int main(){
    int vet[n], i, chave, retorno, es;

    for(i=0; i<n; i++){
        printf("digite o valor %d\n", i);
        scanf("%d", &vet[i]);
    }

    do{
        printf("1: para busca sequencial com sentinela\n2: busca com estrategias de entrada\n3: busca sequencial de estrategias de entrada 2\n4: printar vetor\n5: encerrar o progama\n");
        scanf("%d", &es);
        switch(es){  
        case 1:
            printf("digite o valor a procurar\n");
            scanf("%d", &chave);
            retorno = BuscarSequencial(vet, chave);
            PrintNum(retorno);
            break;
        case 2:
            printf("digite o valor a procurar\n");
            scanf("%d", &chave);
            retorno =  BuscarSequencialEstrategias(vet, chave);
            PrintNum(retorno);
            break;
        case 3:
            printf("digite o valor a procurar\n");
            scanf("%d", &chave);
            retorno = BuscarSequencialEstrategias2(vet, chave);
            PrintNum(retorno);
            break;
        case 4:
            PrintVet(vet);
            break;
        default:
            printf("opcao invalida\n");
            break;
        }
        system("PAUSE");
        system("cls");
    }while(es != 5);
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

int BuscarSequencialEstrategias(int *vetor, int x){
    int i, j, aux;
    for(i=0; i<n; i++){
        if(vetor[i] == x){
            for(j=0; j<i; j++){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
            return vetor[0];
        }
    }
    return -1;
}

int BuscarSequencialEstrategias2(int *vetor, int x){
    int i, aux;
    for(i=0; i<n; i++){
        if(vetor[i] == x){
            aux = vetor[i-1];
            vetor[i-1] = vetor[i];
            vetor[i] = aux;
            return vetor[i-1];
        }
    }
}

void PrintVet(int *vetor){
    int i;
    for(i=0; i<n; i++){
        printf("%d :", vetor[i]);
    }
    printf("\n");
}

void PrintNum(int *retorno){
    if(retorno == -1){
        printf("nao existe\n");
    }
    else{
        printf("encontrado : %d\n", retorno);
    }
}