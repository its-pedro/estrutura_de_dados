#include <stdio.h>
#include <stdlib.h>
#include "pilha-num_binarios.h"

stack* cria_pilha() {
    stack *novo = (stack*) malloc(sizeof(stack));
    novo->inicio = NULL;
    novo->tamanho = 0;
    return novo;
}

void push(stack *pilha, int dado) {
    item *new = (item*) malloc(sizeof(item));
    new->info = dado;
    new->prox = NULL;

    if(pilha->inicio == NULL) {
        pilha->inicio = new;
        pilha->tamanho++;

    }else {
        item* ex = pilha->inicio;
        new->prox = ex;
        pilha->inicio = new;
        pilha->tamanho++;

    }
}

void pop(stack *pilha) {
    item *unpilled = pilha->inicio;
    pilha->inicio = unpilled->prox;
    pilha->tamanho--;
    free(unpilled);
}

void peek(stack *pilha) {
    printf("O comeco da pilha eh %d\n", pilha->inicio->info);
}

int isEmpty (stack *pilha) {
    if(pilha->inicio == NULL) {
        printf("pilha vazia\n");
        return 1;
    }
    printf("pilha com elementos\n");
    return 0;
}

void tamanho (stack *pilha) {
    printf("O tamanho da pilha eh %d\n", pilha->tamanho);
}

void divisões_sucessivas(stack *pilha, int num) {
    int resto;

    while(num > 1) {
        resto = num%2;
        push(pilha, resto);
        num = num/2;
    }
    resto = num%2;
    push(pilha, resto);
}

void imprime_pilha(stack *pilha) {
    item *atual = pilha->inicio;

    while(atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    stack *resto = cria_pilha();
    int num;

    scanf("%d", &num);
    divisões_sucessivas(resto, num);
    imprime_pilha(resto);

    free(resto);
    return 0;
}