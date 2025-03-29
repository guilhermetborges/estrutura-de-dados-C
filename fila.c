#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

bool filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

void enfileirar(Fila* fila, Cliente cliente) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->cliente = cliente;
    novo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

Cliente desenfileirar(Fila* fila) {
    Cliente vazio = {"", 0, {NULL, NULL}};
    if (filaVazia(fila)) {
        return vazio;
    }

    NoFila* temp = fila->inicio;
    Cliente cliente = temp->cliente;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    return cliente;
}

void imprimirFila(Fila* fila) {
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        printf("Cliente: %s, Codigo: %d\n", 
               atual->cliente.nome, atual->cliente.codigo);
        printf("Lista de Mercado:\n");
        imprimirLista(&atual->cliente.lista_mercado);
        printf("\n");
        atual = atual->proximo;
    }
}

void liberarFila(Fila* fila) {
    while (!filaVazia(fila)) {
        Cliente cliente = desenfileirar(fila);
        liberarLista(&cliente.lista_mercado);
    }
}
