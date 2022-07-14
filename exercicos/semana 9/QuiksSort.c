#include <stdio.h>
#define quant 5

void Particao(int *vet, int esq, int dir, int *i, int *j);
int QuicksSort(int *vet, int esq, int dir);
void PrintVet(int vet[]);

int main(){

    int i, vet[quant];

    for(i=0; i<quant; i++){
        printf("digite o %d elemntor\n", i+1);
        scanf("%d", &vet[i]);
    }

    QuicksSort(vet, 0, 4);
    PrintVet(vet);
    return 0;
}

void Particao(int *vet, int esq, int dir, int *i, int *j){

    int pivo, aux;

    *i = esq;
    *j = dir;
    pivo = vet[(esq + dir)/2];

    while(*i <= *j){
        while(vet[*i] < pivo && *i < dir){
            (*i)++;
        }
        while(vet[*j] > pivo && *j > esq){
            (*j)--;
        }
        if(*i <= *j){
            aux = vet[*i];
            vet[*i] = vet[*j];
            vet[*j] = aux;
            (*i)++;
            (*j)--;
        }       
    }  
}

int QuicksSort(int *vet, int esq, int dir){
    
    int i, j;

    Particao(vet, esq, dir, &i, &j);

    if(i < dir){
        QuicksSort(vet, i, dir);
    }
    if(j > esq){
        QuicksSort(vet, esq, j);
    }
}

void PrintVet(int vet[]){
    for(int i=0; i< quant; i++){
        printf("%d, ", vet[i]);
    }
}