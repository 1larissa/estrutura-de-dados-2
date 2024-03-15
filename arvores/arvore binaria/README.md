# Lista de exercícios (Árvore Binária)

Exercício 1 - Considerando a árvore a seguir, defina a saída para os percursos:
<br>
• pré-ordem
<br>
• in-ordem
<br>
• pós-ordem
<br>
<br>
![image](https://github.com/1larissa/fundamentos-de-programacao/assets/129631047/934e7fa3-72d4-44ad-bfdb-46fbd29f263a)
<br>
<br>
Exercício 2 -  Considerando a árvore do exercício 1, escreva funções para os percursos:
<br>
• pré-ordem
<br>
• in-ordem
<br>
• pós-ordem
<br>
<br>

```C
    Arvore *a = constroi_arv (‘a’,
    constroi_arv(‘b’,
    cria_arv_vazia(),
    constroi_arv(‘d’,cria_arv_vazia(),cria_arv_vazia())
    ),
    constroi_arv(‘c’,
    constroi_arv(‘e’,cria_arv_vazia(),cria_arv_vazia()),
    constroi_arv(‘f’,cria_arv_vazia(),cria_arv_vazia())
    )
    );
```
<br>
Exercício 3 - Escreva uma função que retorna um valor booleano (um ou zero) que indica a ocorrência ou não de um dado caractere na árvore. Considere o seguinte protótipo para a sua função:


