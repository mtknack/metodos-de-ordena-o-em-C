#include <stdio.h>
#include <stdlib.h>
#define quant 5

int BuscaBinaria(int vet[], int x);

int main(){
    int vet[quant], x, i, resultado;
    
    for(i=0; i<quant; i++){
        printf("digite o valor %d\n", i);
        scanf("%d", &vet[i]);
    }

    printf("digite a valor a procurar\n");
    scanf("%d", &x);

    resultado = BuscaBinaria(vet, x);

    if(resultado != -1){
        printf("encontrou: %d\n", resultado);
    }
    else{
        printf("nao achado\n");
    }
    

    return 0;
}

int BuscaBinaria(int vet[], int x){
    
    int esquerda, direita, meio;
    esquerda = 0;
    direita = quant - 1;
    while(esquerda <= direita){
        meio = (esquerda + direita)/2;
        if(x < vet[meio]){
            direita = meio - 1;
        }
        else if(x > vet[meio]){
            esquerda = meio + 1;
        }
        else{
            return vet[meio];
        }
    }
    return -1;
}