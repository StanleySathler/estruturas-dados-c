# Capítulo 3 - Pilhas

## Descrição da implementação

Expressões infixas e posfixas são maneiras diferentes de escrever uma expressão matemática. A posfixa é uma maneira de escrevê-las jogando todos os operadores para DEPOIS dos operandos.

```sh
# Infixa
2 + 3 * 4

# Posfixa
3 4 * 2 +
```

[Mais informações (em inglês)](https://github.com/ss-c-cpp/infix2postfix).

Implementação:

- Declara string v_posfixa
- Declara pilha v_operadores

- Para cada i em [expressao]
  - Se i é espaço em branco,
    - Ignore e vá para a próx. iteração
  - Senão, se i == "("
    - Empilha i em v_operadores
  - Senão, se i é operando,
    - Adiciona i em v_posfixa
  - Senão, se i é operador,
    - Adiciona espaço em v_posfixa
    - Enquanto prioridade(topo(v_operadores)) >= prioridade(i)
      - Desempilha j de v_operadores
      - Adiciona j em v_posfixa
      - Adiciona espaço em v_posfixa
    - Empilha i em v_operadores
  - Senão, se i == ')'
    - Enquanto topo(v_operadores) != '('
      - Adiciona espaço em v_posfixa
      - Desempilha j de v_operadores
      - Adiciona j em v_posfixa
    - Desempilha '(' de v_operadores
- Se v_operadores nao estiver vazia
  - Enquanto houver items em v_operadores
    - Adiciona espaço em v_posfixa
    - Desempilha j de v_operadores
    - Adiciona j em v_posfixa
