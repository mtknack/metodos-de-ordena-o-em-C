#include <stdio.h>
#define quant 5

int SelectionSort(int vet[]);
void PrintVet(int vet[]);

int main(){

    int i, vet[quant];

    for(i=0; i<quant; i++){
        printf("digite o %d elemntor\n", i+1);
        scanf("%d", &vet[i]);
    }

    SelectionSort(vet);
    PrintVet(vet);
    return 0;
}

int SelectionSort(int vet[]){

    int i, j, menor, aux;
    for(i = 0; i < quant-1; i++){
        menor = i;
        for(j = i+1; j < quant; j++){
            if(vet[j] < vet[menor]){
                menor = j;
            }
        }
        if(i != menor){
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
        }
    }
    return vet[quant];
}

void PrintVet(int vet[]){
    for(int i=0; i< quant; i++){
        printf("%d, ", vet[i]);
    }
}