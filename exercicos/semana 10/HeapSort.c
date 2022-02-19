#include <stdio.h>
#define quant 5

void HeapSort(int *vet);
int CriaHeap(int *vet, int i, int f);
void PrintVet(int vet[]);

int main(){

    int i, vet[quant];

    for(i=0; i<quant; i++){
        printf("digite o %d elemntor\n", i+1);
        scanf("%d", &vet[i]);
    }

    HeapSort(vet);
    PrintVet(vet);
    return 0;
}

void PrintVet(int vet[]){
    for(int i=0; i< quant; i++){
        printf("%d, ", vet[i]);
    }
}

void HeapSort(int *vet){

    int i, aux;
    for(i = (quant - 1)/2; i >= 0; i--){
        CriaHeap(vet, i, quant - 1);
        //i = i - 1; //pra que essa linha?, estava dando erro com ela no meu codigo
    }

    for(i = (quant - 1); i >= 1; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        CriaHeap(vet, 0, i - 1);
    }
}

int CriaHeap(int *vet, int i, int f){

    int aux, j;

    aux = vet[i]; // pai da funcão
    j = (i * 2) + 1;
    while(j <= f){
        // if(j < f && (j+1) < f)
        if(j < f){
            if(vet[j] < vet[j + 1]){
                j = j + 1;
            }
        }
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }
        else{
            j = f + 1;
        }
    }
    vet[i] = aux;
}