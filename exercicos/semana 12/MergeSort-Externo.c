#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

struct Arquivo{
    FILE *f;
    int pos, MAX, *buffer;
};

void CriaArquivoTeste(char *nome);
void MergeSortExterno(char *nome);
int CriaArquivoOrdenados(char *nome);
int compara(const void *a, const void *b);
void SalvaArquivo(char *nome, int *V, int tam, int MudaLinhaFinal);
void merge(char *nome, int numArgs, int k);
int ProcuraMenor(struct Arquivo* arq, int numArqs, int k, int* menor);
void PreencherBuffer(struct Arquivo* arq, int k);

int main(){

    CriaArquivoTeste("dados.txt");
    MergeSortExterno("dados.txt");
    return 0;
}

void CriaArquivoTeste(char *nome){

    int i;
    FILE *f = fopen(nome, "w");
    srand(time(NULL));
    for(i = 1; i < 1000; i++){

        fprintf(f, "%d\n", rand());
    }
    fprintf(f, "%d\n", rand());
    fclose(f);
    
}

void MergeSortExterno(char *nome){

    char novo[20];
    int numArqs = CriaArquivoOrdenados(nome);
    int i, k = N/(numArqs + 1);

    remove(nome);
    merge(nome, numArqs, k);

    for(i = 0; i < numArqs; i++){
       
       sprintf(novo, "Temp%d.txt", i+1);
       remove(novo);
    }
}

int CriaArquivoOrdenados(char *nome){

    int V[N], cont = 0, total = 0;
    char novo[20];
    FILE *f = fopen(nome, "r");
    while(!feof(f)){
        
        fscanf(f, "%d", &V[total]);
        total++;
        if(total == N){

            cont++;
            sprintf(novo, "Temp%d.txt", cont);
            qsort(V, total, sizeof(int), compara);
            SalvaArquivo(novo, V, total, 0);
            total = 0;
        }
    }
    if(total > 0){

        cont++;
        sprintf(novo, "Temp%d.txt", cont);
        qsort(V, total, sizeof(int), compara);
        SalvaArquivo(novo, V, total, 0);
    }
    fclose(f);
    return cont;
}

int compara(const void *a, const void *b){
    if(*(int*)a == *(int*)b){
        return 0;//iguais
    }   
    else{
        if(*(int*)a < *(int*)b){
            return -1; //vem antes
        }   
        else{
            return 1; //vem depois
        } 
    }        
}

void SalvaArquivo(char *nome, int *V, int tam, int MudaLinhaFinal){

    int i;
    FILE *f = fopen(nome, "a");
    for(i = 0; i < (tam-1); i++){
        fprintf(f, "%d\n", V[i]);
    }    
        

    if(MudaLinhaFinal == 0){
        fprintf(f, "%d\n", V[tam-1]);
    }
    else{
        fprintf(f, "%d\n", V[tam-1]);
    }
    
    fclose(f);
}

void merge(char *nome, int numArgs, int k){

    char novo[20];
    int i;
    int *buffer = (int*) malloc(k*sizeof(int));

    struct Arquivo* arq;
    arq = (struct Arquivo*) malloc(numArgs*sizeof(struct Arquivo));

    for(i = 0; i < numArgs; i++){
        
        sprintf(novo, "Temp%d.txt", i+1);
        arq[i].f = fopen(novo, "r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*)malloc(k*sizeof(int));
        PreencherBuffer(&arq[i], k);
    }
    
    int menor, qtdBuffer = 0;
    while(ProcuraMenor(arq, numArgs, k, &menor) == 1){

        buffer[qtdBuffer] = menor;
        qtdBuffer++;
        if(qtdBuffer == k){
            SalvaArquivo(nome, buffer, k, 1);
            qtdBuffer = 0;
        }
    }

    if(qtdBuffer != 0){
        SalvaArquivo(nome, buffer, qtdBuffer, 1);
    }

    for(i = 0; i < numArgs; i++){
        
        free(arq[i].buffer);
    }

    free(arq);
    free(buffer);
}

int ProcuraMenor(struct Arquivo* arq, int numArqs, int k, int* menor){

    int i, idx = -1;
    for(i = 0; i < numArqs; i++){
        
        if(arq[i].pos < arq[i].MAX){
            if(idx == -1){
                idx = i;
            }
            else{
                if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos]){
                    idx = i;
                }
            }
        }
        
    }

    if(idx != -1){

        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if(arq[idx].pos == arq[idx].MAX){
            PreencherBuffer(&arq[idx], k);
        } 
        return 1;
    }
    else{
        return 0;
    }
}

void PreencherBuffer(struct Arquivo* arq, int k){

    int i;
    if(arq->f == NULL){
        return;
    }

    arq->pos = 0;
    arq->MAX = 0;
    for(i = 0; i < k; i++){
       
        if(!feof(arq->f)){
            fscanf(arq->f, "%d", &arq->buffer[arq->MAX]);
            arq->MAX++;
        }
        else{
            fclose(arq->f);
            arq->f = NULL;
            break;
        }
    }
    
}