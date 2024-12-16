#include<stdio.h>

typedef struct Pessoa {
  int idade;
  char nome[20];
  struct Pessoa *prox;
}pessoa;

typedef struct Queue{
  pessoa *inicio;
  pessoa *fim;
  int tamanho;
}queue;

queue* cria_fila();

void adiciona_fila(queue* fila, int idade, char nome[20]);

void atende_pessoa(queue *fila_80, queue *fila_60, queue *fila_jovem);

void imprime_filas(queue *fila_80, queue *fila_60, queue *fila_jovem);