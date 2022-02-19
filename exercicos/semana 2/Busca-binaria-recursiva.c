#include <stdio.h>
#include <stdlib.h>
#define quant 5

int BuscaBinaria(int vet[], int x, int inicio, int fim);

int main(){
    int vet[quant], x, i, resultado, inicio, fim;
    
    for(i=0; i<quant; i++){
        printf("digite o valor %d\n", i);
        scanf("%d", &vet[i]);
    }

    printf("digite a valor a procurar\n");
    scanf("%d", &x);

    inicio = 0;
    fim = quant - 1;
    resultado = BuscaBinaria(vet, x, inicio, fim);

    if(resultado != -1){
        printf("encontrou: %d\n", vet[resultado]);
    }
    else{
        printf("nao achado\n");
    }

    return 0;
}

int BuscaBinaria(int vet[], int x, int inicio, int fim){

    int meio;
    meio = (fim + inicio)/2;
    
    if(inicio > fim){
        return -1;
    }
    else if(vet[meio] == x){
        return meio;
    }
    else if(vet[meio] > x){
        fim = meio -1;
        return BuscaBinaria(vet, x, inicio, fim);
    }
    else{
        inicio = meio + 1;
        return BuscaBinaria(vet, x, inicio, fim);
    }
}