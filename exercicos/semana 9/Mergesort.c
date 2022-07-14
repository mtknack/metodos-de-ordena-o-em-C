#include <stdio.h>
#define quant 12

int Intercala(int *vet[], int inicio, int meio, int fim);
void MergeSort(int *vet, int inicio, int fim);
void PrintVet(int vet[]);

int main(){

    int i, vet[quant];

    for(i=0; i<quant; i++){
        printf("digite o %d elemntor\n", i+1);
        scanf("%d", &vet[i]);
    }

    MergeSort(vet, 0, 4);
    PrintVet(vet);
    return 0;
}

int Intercala(int *vet[], int inicio, int meio, int fim){
    
    int i, j, k, Tpm[quant];
    i = inicio;
    j = meio + 1;
    k = 0;
    while((i <= meio) || (j <= fim)){
        if((i == (meio + 1)) || ((vet[j] < vet[i]) && (j != (fim+1)))){
            Tpm[k] = vet[j];
            j = j + 1;
            k = k + 1;
        }
        else{
            Tpm[k] = vet[i];
            i = i + 1;
            k = k + 1;
        }
    }
    for(i = inicio; i <= fim; i++){
        vet[i] = Tpm[i - inicio];
    }
}

void MergeSort(int *vet, int inicio, int fim){

    int meio = (inicio + fim)/2;
    if(inicio < fim){
        MergeSort(vet, inicio, meio);
        MergeSort(vet, meio + 1, fim);
        Intercala(vet, inicio, meio, fim);
    }
}

void PrintVet(int vet[]){
    for(int i=0; i< quant; i++){
        printf("%d, ", vet[i]);
    }
}