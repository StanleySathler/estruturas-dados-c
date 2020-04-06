# Capítulo 3 - Expressões

### Exercício 3.4

Na forma _prefixa_, os operadores são colocados _antes_ de seus operandos. Por exemplo, convertendo a expressão infixa `A*B+C/D` em prefixa, obtemos `+*AB/CD`. Para efetuar essa conversão, basta parentesiar completamente a expressão infixa e, depois, reescrevê-la, descartando os parênteses e movendo os operadores para a posição ocupada por seus parênteses esquerdos, como a seguir:

```
A * B + C / D => ((A * B) + (C / D)) => + * A B / C D
```

Supondo que os operandos em uma expressão infixa completamente parentesiada são letras, crie uma função para convertê-la em prefixa. _Dica:_ a função `strlen(s)` devolve o tamanho de uma cadeia `s` e a função `strrev(s)` inverte uma cadeia `s`. Ambas as funções são declaradas em `string.h`.

### Exercício 3.6

Considerando _expressões lógicas_ infixas completamente parentesiadas, representadas por cadeias compostas exclusivamente por:

- _Operandos_, representados pelas letras `V` (verdade) e `F` (falso).
- _Operadores_, representados pelos caracteres `~` (não), `&` (e) e `|` (ou).
- _Parênteses_, que muda as prioridades dos operadores (prioridade padrão: `~`, `&`, `|`).

a) Crie uma função que devolve a _posfixa_ de uma expressão lógica infixa.

b) Crie uma função que devolve o _valor_ de uma expressão lógica posfixa.

c) Crie um programa que lê uma expressão lógica infixa e exibe sua forma posfixa e seu valor.
