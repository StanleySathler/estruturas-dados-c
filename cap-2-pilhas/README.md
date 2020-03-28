# Capítulo 2 - Pilhas

## Descrição dos exercícios

### Exercício 2.3
---

_Usando pilha, crie um programa para inverter a ordem das letras nas palavras de uma frase digitada pelo usuário. Por exemplo, se for digitada a frase "apenas um teste", o programa deverá exibir a frase "sanepa mu etset"._

Solução:

- Declara pilha A
- Para cada i em [entrada]
  - Se i é um caractere
    - Empilha i em A
  - Se i é um espaço ou quebra de linha
    - Enquanto A conter algo:
      - Desempilha A
      - Printa na tela

### Exercício 2.4
---

_Crie um programa que usa duas pilhas A e B para ordenar uma sequência de n números reais dados pelo usuário. A ideia é organizar a pilha A de modo que nenhum item seja empilhado sobre outro menor (use a pilha B apenas como espaço de manobra), depois, descarregue e exiba os itens da pilha A._

Solução:

- Para cada i em [entrada]
  - Se i < topo(A)
    - add(A, i)
  - Senão
    - Para cada j em [A]
      - Se i > j
        - add(B, j)
      - Senão
        - add(A, j)
        - Copia B para A
- Printa A na tela


### Exercício 2.5
---

_Usando pilha, crie uma função para verificar se uma expressão composta apenas por chaves, colchetes e parênteses, representada por uma cadeia, está ou não _balanceada_. Por exemplo, as expressões `[{()()}{}]` e `{[([{}])]}` estão balanceadas, mas as expressões `{[(}]}` e `{[)()(]}` não estão._

Solução:

- Declara pilha A
- Para cada i em [entrada]
  - Se i = ('{' | '(' | '[')
    - add(A, i)
  - Senao se i = ('}' | ')' | ']')
    - Se i corresponde à topo(A)
      - desempilha(A)
    - Senao
      - Retorna falso
  - Senao
    - Retorna falso
- Se pilha nao estiver vazia
  - Retorna false
- Retorna verdadeiro
