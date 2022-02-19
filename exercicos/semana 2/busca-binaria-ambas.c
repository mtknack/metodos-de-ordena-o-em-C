#include <stdio.h>
#include <stdlib.h>
#define quant 5

int BuscaBinaria(int vet[], int x);
int BuscaBinariaRecursiva(int vet[], int x, int inicio, int fim);
void PrintResultado(int resultado);

int main(){
    int vet[quant], x, i, resultado, es;
    
    for(i=0; i<quant; i++){
        printf("digite o valor %d\n", i);
        scanf("%d", &vet[i]);
    }

    printf("digite a valor a procurar\n");
    scanf("%d", &x);

    do
    {
        printf("digite oque deseja fazer\n");
        printf("1: para busca binaria normal\n");
        printf("2: para busca binaria recursiva\n");
        printf("3: para sair\n");
        scanf("%d", &es);
        switch(es){
        case 1:
            resultado = BuscaBinaria(vet, x);
            PrintResultado(resultado);
            break;
        case 2:
            resultado = BuscaBinariaRecursiva(vet, x, 0, quant - 1);
            PrintResultado(resultado);
            break;
        
        default:
            break;
        }
    }while(es != 3);
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

int BuscaBinariaRecursiva(int vet[], int x, int inicio, int fim){

    int meio;
    meio = (fim + inicio)/2;
    
    if(inicio > fim){
        return -1;
    }
    else if(vet[meio] == x){
        return vet[meio];
    }
    else if(vet[meio] > x){
        fim = meio -1;
        return BuscaBinariaRecursiva(vet, x, inicio, fim);
    }
    else{
        inicio = meio + 1;
        return BuscaBinariaRecursiva(vet, x, inicio, fim);
    }
}

void PrintResultado(int resultado){
    if(resultado != -1){
        printf("encontrou: %d\n", resultado);
    }
    else{
        printf("nao achado\n");
    }
}
