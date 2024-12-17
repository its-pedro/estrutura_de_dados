#include<stdio.h>

typedef struct Item {
  int info;
  struct Item *prox;
}item;

typedef struct Stack{
  item *inicio;
  //dado *fim;
  int tamanho;
}stack;

stack* cria_pilha();

void push(stack *pilha, int dado);

void pop(stack *pilha);

void peek(stack *pilha);

int isEmpty (stack *pilha);

void tamanho (stack *pilha);

void divisões_sucessivas(stack *pilha, int num);

void imprime_pilha(stack *pilha);




