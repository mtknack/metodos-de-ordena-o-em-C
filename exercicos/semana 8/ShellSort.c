#include <stdio.h>
#define quant 5

int SellSort(int vet[]);
void PrintVet(int vet[]);

int main(){

    int i, vet[quant];

    for(i=0; i<quant; i++){
        printf("digite o %d elemntor\n", i+1);
        scanf("%d", &vet[i]);
    }

    SellSort(vet);
    PrintVet(vet);
    return 0;
}

int SellSort(int vet[]){
    int h, i, j, aux;
    h = 1;
    while(h < quant){
       h = 3 * h + 1;
    }
    while(h > 1){
        h = h/3;
        for(i=h; i< quant; i++){
            aux = vet[i];
            j = i - h;
            while((j >= 0) & (aux < vet[j])){
                vet[j+h] = vet[j];
                j -= h;
            }
        vet[j+h] = aux;   
        }
    }
    return vet[quant];
}

void PrintVet(int vet[]){
    for(int i=0; i< quant; i++){
        printf("%d, ", vet[i]);
    }
}