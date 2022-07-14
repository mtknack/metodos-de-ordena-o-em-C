#include <stdio.h>
#define quant 10
#define qbaldes 10
#define True 1
#define False 0

typedef struct Bucketsort{
    int balde[10];
    int top;
} BS;

void Bucksoret(int *vet);
void sortBolha(int *dados, int n);
void imprime(int *dados);

int main(){
    
    int i, vet[quant];

    printf("digite numeros entre 0 e manores que %d", qbaldes * qbaldes);

    for(i=0; i<quant; i++){
        printf("digite o %d elemnto\n", i+1);
        scanf("%d", &vet[i]);
    }
    Bucksoret(vet);
    imprime(vet);

    return 0;
}

void Bucksoret(int *vet){

    BS baldes[quant];
    int i, j;
    
    for(i = 0; i < qbaldes; i++){
        baldes[i].top = 0;
    }

    for(i = 0; i < quant; i++){
        j = qbaldes-1;
        while(j >= 0){                  // aki tem que ser maior ou igual a zero pois tem o indice 0 do j
            if(vet[i] >= j*10){
                baldes[j].balde[baldes[j].top] = vet[i];
                baldes[j].top ++;
                printf("j*10 = %d\n", j*10);
                break;                                  // aki tem que ter o break pois sempre vai ser maior que j*10 para os baldes seguintes ao que achou primeiro
            }
            j = j - 1;
        }
    }
    
    for(i = 0; i < qbaldes; i++){   
        if(baldes[i].top > 1){                      // botei 1 em vez de zero pois quando for 1, não ira precisar de ordenar pois só tem 1 elementor
            sortBolha(baldes[i].balde, baldes[i].top);
        }
    }
    
    i = 0;
    int k;

    for(j = 0; j < qbaldes; j++){
        for (k = 0; k < baldes[j].top; k++){
            vet[i] = baldes[j].balde[k];
            i ++;
        }
    } 
   
}

void sortBolha(int *dados, int n){
    int i, j, aux, mudou ,indice;
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
        n = indice;
    } 
}

void imprime(int *dados){
    int i;
    for(i=0; i<quant; i++){
        printf(" %d,", dados[i]);
    }
}