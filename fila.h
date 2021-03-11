#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct nos{
    TIPOCHAVE chave;
    nodo proximo;
    nodo anterior;
}no,*nodo;

nodo novo(TIPOCHAVE chave){
    nodo temp = (nodo) malloc(sizeof(no));
    temp->chave = chave;
    temp->proximo = NULL;
    temp->anterior = NULL;
    return temp;
}

nodo push(nodo base,TIPOCHAVE e){
    if (!base) return novo(e);
    nodo temp = base;
    while(temp->proximo)temp = temp->proximo;
    temp->proximo = novo(e);
    temp->proximo->anterior = temp;
    return base;
}

nodo pop(nodo base){
    nodo temp = base;
    while (temp->anterior) temp = temp->anterior;
    temp->proximo->anterior=NULL;
    free(temp);
}