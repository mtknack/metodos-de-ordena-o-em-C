#include <stdio.h>
#include <stdlib.h>
#define n 20
#define m 10

int ForcaBruta(char vet[],char x[]);

int main(){
    
    char vet[n], x[m];
    int retorno;

    printf("digite o texto\n");
    scanf("%s", vet);
    
    printf("digite o texto a preocurar\n");
    scanf("%s", x);

    retorno = ForcaBruta(vet, x);
    if(retorno == -1){
        printf("não existe substring em (vet) igual na (x)\n");
    }else{
        printf("existe uma substring que comeca no caractere(%d)\n", retorno); 
    }
    return 0;
}

int ForcaBruta(char vet[],char x[]){

    int i, j;
    for(i=0; i<(n-m); i++){
        j=0;
        while(j < m && (vet[i+j]==x[j])){
            j += 1;
            if(j == m){
                return i;
            }
        } 
    }
    return -1;
}