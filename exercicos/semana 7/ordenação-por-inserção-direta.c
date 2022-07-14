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
    
    int aux, i, j, rot=1;

    for(i = 1; i < quant ; i++){
        printf("laco : %d\n", rot); //extra
        aux = vet[i];
        printf("valor de aux: %d\n", aux);//extra
        j = i - 1;
        printf("valor de j: %d\n", j);//extra
        while(j >= 0 && aux < vet[j]){
            vet[j+1] = vet[j];
            printf("valor de vet na posicao %d : %d\n", j+1, vet[j+1]);//extra
            j = j-1;
            printf("valor de j: %d\n", j);//extra
        }
        if(j != (i-1)){
            vet[j+1] = aux;
            printf("valor de vet na posicao %d: %d\n", j+1,vet[j+1]); //extra
        }
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