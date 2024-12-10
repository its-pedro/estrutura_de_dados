#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int tamanho;
    struct No *inicio;
    struct No *final;
};

struct No{
    int dado;
    struct No *prox;
};

typedef struct Queue queue;
typedef struct No no;

queue *cria_fila (){
    queue *fila = (queue*) malloc(sizeof(queue));
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->final = NULL;
    return fila;
}

void adiciona_elemento(queue *fila, int item){
    no *novo = (no*) malloc(sizeof(no));
    novo->dado = item;
    novo->prox = NULL;
    
    if(fila->inicio == NULL){
        fila->inicio = novo;
    }else{
        no *atual = fila->final;
        atual->prox = novo;
    }
    fila->final = novo;
    fila->tamanho++;
}

void retira_elemento(queue *fila){
    fila->inicio = fila->inicio->prox;
    fila->tamanho--;
}

int lista_vazia (queue *fila){
    if(fila->tamanho == 0){
        return 1; 
    }
    return 0; 
}

void sizeof_fila (queue *fila){
    printf("o tamnho da lista eh %d\n", fila->tamanho);
}

void first_print(queue *fila){
    printf("o primeiro elemento da fila eh %d\n", fila->inicio->dado);
}

int main(){
    queue *minha_fila = cria_fila();
    adiciona_elemento(minha_fila, 10);
    adiciona_elemento(minha_fila,8);
    sizeof_fila(minha_fila);
    first_print(minha_fila);
    retira_elemento(minha_fila);
    sizeof_fila(minha_fila);
    first_print(minha_fila);
    
    return 0;
}
