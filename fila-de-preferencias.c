#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila-de-preferências.h"

queue* cria_fila() {
    queue *fila = (queue *) malloc(sizeof(queue));
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

void adiciona_fila(queue* fila, int idade, char nome[20]) {
    pessoa* novo = malloc(sizeof(pessoa));
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(fila->inicio == NULL) {
        fila->inicio = novo;

    }else {
        pessoa *last = fila->fim;
        last->prox = novo;
    }
    fila->fim = novo;
    fila->tamanho++;
}

void atende_pessoa(queue *fila_80, queue *fila_60, queue *fila_jovem) {
    if(fila_80->tamanho != 0) {
        pessoa *atendido = fila_80->inicio;
        fila_80->inicio = atendido->prox;
        free(atendido);
        fila_80->tamanho--;

    }else if(fila_60 != 0) {
        pessoa *atendido = fila_60->inicio;
        fila_60->inicio = atendido->prox;
        free(atendido);
        fila_60->tamanho--;

    }else {
        pessoa *atendido = fila_jovem->inicio;
        fila_jovem->inicio = atendido->prox;
        free(atendido);
        fila_jovem->tamanho--;

    }
}

void imprime_filas(queue *fila_80, queue *fila_60, queue *fila_jovem) {
    int i, j = 1;

    printf("FILA DE PREFERENCIA\n");
    i = fila_80->tamanho;
    pessoa *atual = fila_80->inicio;
    while(i > 0) {
        printf("A %d pessoa da fila eh %s - %d anos\n",j,atual->nome, atual->idade);
        atual = atual->prox;
        j++;
        i--;
    }

    i = fila_60->tamanho;
    atual = fila_60->inicio;
    while (i > 0) {
        printf("A %d pessoa da fila eh %s - %d anos\n",j,atual->nome, atual->idade);
        atual = atual->prox;
        j++;
        i--;
    }

    i = fila_jovem->tamanho;
    atual = fila_jovem->inicio;
    while (i > 0) {
        printf("A %d pessoa da fila eh %s - %d anos\n",j,atual->nome, atual->idade);
        atual = atual->prox;
        j++;
        i--;
    }
    printf("\n");
}

int main() {
    queue *mais_80 = cria_fila();
    queue *mais_60 = cria_fila();
    queue *jovens = cria_fila();
    int pessoas, idade, i;
    char nome[20];

    scanf("%d", &pessoas);
    for(i = 0; i < pessoas; i++) {
        scanf("%s %d", nome, &idade);
        getchar();
        if(idade >= 80)
            adiciona_fila(mais_80, idade, nome);
        else if(idade >= 60)
            adiciona_fila(mais_60, idade, nome);
        else
            adiciona_fila(jovens, idade, nome);
    }
    imprime_filas(mais_80, mais_60, jovens);
    atende_pessoa(mais_80, mais_60, jovens);
    atende_pessoa(mais_80, mais_60, jovens);
    imprime_filas(mais_80, mais_60, jovens);

    free(jovens);
    free(mais_60);
    free(mais_80);
    return 0;
}