#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

Arvore *cria_arv_vazia(void) { return NULL; }

Arvore *constroi_arv(char c, Arvore *e, Arvore *d) {
  Arvore *no = (Arvore *)malloc(sizeof(Arvore));
  no->info = c;
  no->esq = e;
  no->dir = d;
  return no;
}

int verifica_arv_vazia(Arvore *a)
{ return (a == NULL); }

void arv_libera(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
	// verifica recursivamente a todas as sub-arvores
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }
}

//========= Exercício 2 - pré-ordem ====
void acessa_arv_pre_ordem(Arvore *a) {
  // R, E, D
  if (!verifica_arv_vazia(a)) {
    printf("%c", a->info);
    acessa_arv_pre_ordem(a->esq);
    acessa_arv_pre_ordem(a->dir);
  }
}
//========= Exercício 2 - in-ordem ====
void acessa_arv_in_ordem(Arvore *a) {
  // E, R, D
  if (!verifica_arv_vazia(a)) {
    acessa_arv_in_ordem(a->esq);
    printf("%c", a->info);
    acessa_arv_in_ordem(a->dir);
  }
}
//========= Exercício 2 - pós-ordem ====
void acessa_arv_pos_ordem(Arvore *a) {
  // E, D, R
  if (!verifica_arv_vazia(a)) {
    acessa_arv_pos_ordem(a->esq);
    acessa_arv_pos_ordem(a->dir);
    printf("%c", a->info);
  }
}

//========= Exercício 3 - pertence ====
int pertence_arv(Arvore *a, char c) {
  if (!verifica_arv_vazia(a)) {
    if (a->info == c)
      return 1;
    else if (pertence_arv(a->esq, c) || pertence_arv(a->dir, c))
			return 1;
  }
  return 0;
}

//========= Exercício 4 - conta nós ====
int conta_nos(Arvore *a) {
	if (verifica_arv_vazia(a))
		return 0;

	return (1 + conta_nos(a->esq) + conta_nos(a->dir));
}

//========= Exercício 5 - calcula altura ====
int calcula_altura_arv(Arvore *a) {
	if (verifica_arv_vazia(a))
		return -1;
	else{
		int esq = 1 + calcula_altura_arv(a->esq);
		int dir = 1 + calcula_altura_arv(a->dir);
		if (esq > dir)
			return esq;
		else
			return dir;
	}
}

//========= Exercício 6 - conta folhas ====
int conta_nos_folhas(Arvore *a) {
	if (!verifica_arv_vazia(a)){
		if((a->esq == NULL) && (a->dir == NULL))
			return 1;
		else
			return (conta_nos_folhas(a->esq) + conta_nos_folhas(a->dir));
	}
	return 0 ;
}

int main(int argc, char *argv[]) {

  Arvore *a = constroi_arv(
      'a',
      constroi_arv('b', cria_arv_vazia(),
                   constroi_arv('d', cria_arv_vazia(), cria_arv_vazia())),
      constroi_arv('c', constroi_arv('e', cria_arv_vazia(), cria_arv_vazia()),
                   constroi_arv('f', cria_arv_vazia(), cria_arv_vazia())));
	/*
	  Arvore *a, *a1, *a2, *a3, *a4, *a5;
	a1 = constroi_arv('d', cria_arv_vazia(), cria_arv_vazia());
	a2 = constroi_arv('b', cria_arv_vazia(), a1);
	a3 = constroi_arv('e', cria_arv_vazia(), cria_arv_vazia());
	a4 = constroi_arv('f', cria_arv_vazia(), cria_arv_vazia());
	a5 = constroi_arv('c', a3, a4);
	a = constroi_arv('a', a2, a5);
	*/

	// Inserção em b
	/*
	a->esq->esq = constroi_arv ('x',
	constroi_arv('y',cria_arv_vazia(),cria_arv_vazia()),
	constroi_arv('z',cria_arv_vazia(),cria_arv_vazia())
	);
	*/

	printf("Pertence : %i \n", pertence_arv(a, 'k'));
	printf("Conta nós: %i \n", conta_nos(a));
	printf("Calcula altura: %i \n", calcula_altura_arv(a));
	printf("Conta folhas: %i \n", conta_nos_folhas(a));

  arv_libera(a);

  return 0;
}