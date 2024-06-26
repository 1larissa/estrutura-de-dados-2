#include "abbLista.h"
#include <stdio.h>

Arvore *cria_arvore_vazia(void) { return NULL; }

void arvore_libera(Arvore *a) {
  if (a != NULL) {
    arvore_libera(a->esq);
    arvore_libera(a->dir);
    free(a);
  }
}

void pre_order(Arvore *a) {
  if (a != NULL) {
    printf("%d ", a->info);
    pre_order(a->esq);
    pre_order(a->dir);
  }
}

//========= Q1 - inserir
Arvore *inserir(Arvore *a, int v) {
  if (a == NULL) {
    a = (Arvore *)malloc(sizeof(Arvore));
    a->info = v;
    a->esq = NULL;
    a->dir = NULL;
  } else if (v < a->info)
    a->esq = inserir(a->esq, v);
  else
    a->dir = inserir(a->dir, v);

  return a;
}
//========= Q1 - remover
Arvore *remover(Arvore *a, int v) {
  if (a == NULL)
    return 0;
  if (v < a->info)
    a->esq = remover(a->esq, v);
  else if (a->info < v)
    a->dir = remover(a->dir, v);
  else { // encontrei
         //é folha
    if (a->dir == NULL && a->esq == NULL) {
      free(a);
      return NULL;
    } else if (a->dir == NULL) {
      // tem 1 filho a esquerda
      Arvore *tmp = a;
      a = a->esq;
      free(tmp);
    } else if (a->esq == NULL) {
      // tem 1 filho a direita
      Arvore *tmp = a;
      a = a->dir;
      free(tmp);
    } else {// tem 2 filhos
			Arvore *tmp = a->esq;
      // procuro o max da arv esq
      while (tmp->dir != NULL) {
        tmp = tmp->dir;
      }
			// faz a troca
			a->info = tmp->info;
			tmp->info = v;
			a->esq = remover(a->esq, v);
    }
  }
  return a;
}
//========= Q1 - busca
int buscar(Arvore *a, int v) {
  if (a == NULL)
    return 0;
  else if (v < a->info)
    return buscar(a->esq, v);
  else if (v > a->info)
    return buscar(a->dir, v);
  else // (a->info == v)
    return 1;
}
//========= Q2 - min =====
int min(Arvore *a) {
  if (a == NULL)
    return -1;
  else if (a->esq == NULL)
    return a->info;
  else
    return min(a->esq);
}
//========= Q2 - max =====
int max(Arvore *a) {
  if (a == NULL)
    return -1;
  else if (a->dir == NULL)
    return a->info;
  else
    return max(a->dir);
}
//========= Q3 - imprime_decrescente =====
void imprime_decrescente(Arvore *a) {
  if (a == NULL)
    return;
  imprime_decrescente(a->dir);
  printf("%d ", a->info);
  imprime_decrescente(a->esq);
}
//========= Q4 - maior ramo =====
int maior_ramo(Arvore *a) {
  if (a == NULL) {
    return 0;
  } else {
    // Calcula a soma do ramo atual e
    // das somas dos ramos da subárvore esquerda e direita
    int soma_esq = maior_ramo(a->esq);
    int soma_dir = maior_ramo(a->dir);
    return a->info + (soma_esq > soma_dir ? soma_esq : soma_dir);
    // Retorna a soma do ramo atual mais o maior valor
    // entre as somas das subárvores esquerda e direita
  }
}

int main() {
  // inserir
  Arvore *a;
  a = cria_arvore_vazia();
  a = inserir(a, 50);
  a = inserir(a, 30);
  a = inserir(a, 90);
  a = inserir(a, 20);
  a = inserir(a, 40);
  a = inserir(a, 95);
  a = inserir(a, 10);
  a = inserir(a, 35);
  a = inserir(a, 45);

  pre_order(a);
  printf("\n");

  // buscar
  printf("Buscar 11: %d \n", buscar(a, 0));
  printf("Buscar 30: %d \n", buscar(a, 30));
  printf("Buscar 45: %d \n", buscar(a, 45));

  // remoção

  // min e max
  printf("Min: %d \n", min(a));
  printf("Max: %d \n", max(a));

  // decrescente
  imprime_decrescente(a);
  printf("\n");

  // maior ramo
  printf("Maior ramo: %d \n", maior_ramo(a));

  // ====== Q5 ====

  return 0;
}
