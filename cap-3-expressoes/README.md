# Capítulo 3 - Pilhas

## Descrição da implementação

Expressões infixas e posfixas são maneiras diferentes de escrever uma expressão matemática. A posfixa é uma maneira de escrevê-las jogando todos os operadores pra DEPOIS dos operandos.

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
  - Se i == "(" ou espaço em branco, nao faz nada
  - Senão, se i é operando,
    - Adiciona i em v_posfixa
  - Senão, se i é operador,
    - Se prioridade(i) < prioridade(topo(v_operadores))
      - Desempilha j de v_operadores
      - Adiciona j em v_posfixa
    - Empilha i em v_operadores
  - Senão, se i == ")"
    - Desempilha j de v_operadores
    - Adiciona j em v_posfixa
- Se v_operadores nao estiver vazia
  - Enquanto houver items em v_operadores
    - Desempilha j de v_operadores
    - Adiciona j em v_posfixa
