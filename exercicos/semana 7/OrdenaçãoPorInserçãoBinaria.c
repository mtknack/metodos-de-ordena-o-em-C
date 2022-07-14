#include <stdio.h>
#define quant 5

int OrdenacaoPorInsercaoDireta(int vet[]);
void PrintVet(int vet[]);

int main(){
    int vet[quant];

    for(int i=0; i< quant; i++){
        printf("digite o valor %d\n", i);
        scanf("%d", &vet[i]);
    }

    OrdenacaoPorInsercaoDireta(&vet);
    PrintVet(&vet);

    return 0;
}

int OrdenacaoPorInsercaoDireta(int vet[]){
    
    int aux, i, j, esq, dir, meio, rot=1;

    for(i = 1; i < quant ; i++){
        printf("laco : %d\n", rot); //extra
        aux = vet[i];
        printf("valor de aux: %d\n", aux);//extra
        esq = 0;
        dir = i;
        while(esq < dir){
            meio = (esq + dir)/2;
            printf("valor do meio %d\n", meio);//extra
            if(vet[meio] <= aux){
                esq = meio + 1;
                printf("valor da esq: %d\n", esq);//extr
            }
            else{
                dir = meio;
                printf("valor da dir: %d\n", dir);//extr
            }   
        }
        for(j = i; j > esq ; j--){
            vet[j] = vet[j-1];
            printf("valor de vet na posicao %d: %d\n", j,vet[j]); //extra
        }
        vet[dir] = aux;
        rot ++; //extra
        PrintVet(vet);
        printf("\n");
    }

    return vet;
}

void PrintVet(int vet[]){
    for(int i=0; i< quant; i++){
        printf("%d, ", vet[i]);
    }
}