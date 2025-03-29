#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void inicializarLista(Lista* lista) {
    lista->cabeca = NULL;
    lista->ultimo = NULL;
}

bool listaVazia(Lista* lista) {
    return (lista->cabeca == NULL);
}

void inserirProduto(Lista* lista, Dado dado, int posicao) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha ao alocar memória para novo produto.\n");
        return;
    }
    
    novoNo->dado = dado;
    novoNo->proximo = NULL;

    if (listaVazia(lista)) {
        lista->cabeca = novoNo;
        lista->ultimo = novoNo;
        return;
    }

    if (posicao == 0) {
        novoNo->proximo = lista->cabeca;
        lista->cabeca = novoNo;
        return;
    }

    if (posicao == -1) {
        lista->ultimo->proximo = novoNo;
        lista->ultimo = novoNo;
        return;
    }

    No* atual = lista->cabeca;
    int i = 1;
    while (i < posicao && atual->proximo != NULL) {
        atual = atual->proximo;
        i++;
    }
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
    if (novoNo->proximo == NULL) {
        lista->ultimo = novoNo;
    }
}

Dado removerProduto(Lista* lista, int codigo) {
    Dado dadoVazio = {"", 0.0, 0, 0};

    if (listaVazia(lista)) {
        return dadoVazio;
    }

    No* atual = lista->cabeca;
    No* anterior = NULL;

    while (atual != NULL && atual->dado.codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return dadoVazio;
    }

    Dado dadoRemovido = atual->dado;

    if (anterior == NULL) { 
        lista->cabeca = atual->proximo;
    } else { 
        anterior->proximo = atual->proximo;
    }

    if (atual == lista->ultimo) {
        lista->ultimo = anterior;
    }

    free(atual);
    return dadoRemovido;
}

void imprimirLista(Lista* lista) {
    No* atual = lista->cabeca;
    if (listaVazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    while (atual != NULL) {
        printf("Produto: %s, Preco: %.2f, Codigo: %d, Quantidade: %d\n",
               atual->dado.nome_produto,
               atual->dado.preco,
               atual->dado.codigo,
               atual->dado.quantidade);
        atual = atual->proximo;
    }
}

void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->cabeca = NULL;
    lista->ultimo = NULL;
}
