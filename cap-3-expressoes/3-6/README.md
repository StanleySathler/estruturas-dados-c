### Exercício

Considerando _expressões lógicas_ infixas completamente parentesiadas, representadas por cadeias compostas exclusivamente por:

- _Operandos_, representados pelas letras `V` (verdade) e `F` (falso).
- _Operadores_, representados pelos caracteres `~` (não), `&` (e) e `|` (ou).
- _Parênteses_, que muda as prioridades dos operadores (prioridade padrão: `~`, `&`, `|`).

a) Crie uma função que devolve a _posfixa_ de uma expressão lógica infixa.
b) Crie uma função que devolve o _valor_ de uma expressão lógica posfixa.
c) Crie um programa que lê uma expressão lógica infixa e exibie sua forma posfixa e seu valor.

### Solução

Converter para posfixa é tranquilo. Nós basicamente reutilizados a implementação para a expressão posfixa (`cap-3-expressoes/posfixa`). A diferença é que precisamos modificar nossas funções para que considerem:

- Operandos como `V` ou `F`
- Operadores como `~`, `&` ou `|`
- Prioridades na ordem `~, & e |`

Já para calcular o valor da expressão, que agora é uma expressão lógica, precisamos de algumas mudanças.

Algoritmo principal de cálculo:

- Declara pilha v_operandos
- Para cada i em [expressao]
  - Se i é operando
    - Empilha em v_operandos
  - Se i é operador
    - Se i é "~"
      - Desempilha a de v_operandos
      - Empilha inverte(a)
    - Senão
      - Desempilha b de v_operandos
      - Desempilha a de v_operandos
      - Empilha calculo(a, b)
- Desempilha x de v_operandos
- Transforma x em um booleano
