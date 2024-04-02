# Lista de exercícios (Árvore Binária de Busca)

Exercício 1 - Baseado nas notas de aula e usando o código disponibilizado no Moodle, implemente as funções para realizar inserção, busca e remoção em uma arvore binária de busca (ABB).
Como exemplo, para construir a árvore:

```C
int main () {
Arvore *a;
a = inserir (a, 50);
a = inserir (a, 30);
a = inserir (a, 90);
a = inserir (a, 20);
a = inserir (a, 40);
a = inserir (a, 95);
a = inserir (a, 10);
a = inserir (a, 35);
a = inserir (a, 45);
return 0;
}
```

<br>
<br>
Exercício 2 - Escreva uma fun ̧cao “min” que encontre (e imprima)uma chave mınima em uma  ́arvore binaria de busca. Escreva uma função “max” que encontre (e imprima) uma chave máxima. Utilize os seguintes protótipos para a sua função:

```C
int min (Arvore *a);
int max (Arvore *a);
```

<br>
<br>
Exercício 3 - Escreva uma funçao recursiva que imprime uma ́arvore binaria de busca em ordem decrescente. Utilize o seguinte prototipo para a sua função:

```C
void imprime_decrescente (Arvore *a);
```

![image](https://github.com/1larissa/estrutura-de-dados-2/assets/129631047/3be750e8-4f25-450c-ab0d-e3b9f9531348)
<br>
<br>

Exercício 4 - Escreva uma funçao que retorna o valor do maior caminho (soma dos valores dos nós) da raiz at e algum no folha da ́arvore. Utilize o seguinte prototipo para a sua função:

```C
int maior_ramo (Arvore *a);
```

<br>
![image](https://github.com/1larissa/estrutura-de-dados-2/assets/129631047/260b60d2-4adb-42ea-8e03-2f647872823a)