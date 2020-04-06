### Exercício

Na forma _prefixa_, os operadores são colocados _antes_ de seus operandos. Por exemplo, convertendo a expressão infixa `A*B+C/D` em prefixa, obtemos `+*AB/CD`. Para efetuar essa conversão, basta parentesiar completamente a expressão infixa e, depois, reescrevê-la, descartando os parênteses e movendo os operadores para a posição ocupada por seus parênteses esquerdos, como a seguir:

```
A * B + C / D => ((A * B) + (C / D)) => + * A B / C D
```

Supondo que os operandos em uma expressão infixa completamente parentesiada são letras, crie uma função para convertê-la em prefixa. _Dica:_ a função `strlen(s)` devolve o tamanho de uma cadeia `s` e a função `strrev(s)` inverte uma cadeia `s`. Ambas as funções são declaradas em `string.h`.

### Solução

- Declara string v_prefixa
- Declara pilha v_operadores

- Para cada i em [expressao], na ordem inversa
  - Se i é espaço em branco,
    - Ignore e vá para a próx. iteração
  - Senão, se i == ")"
    - Empilha i em v_operadores
  - Senão, se i é letra,
    - Adiciona i em v_prefixa
  - Senão, se i é operador,
    - Adiciona espaço em v_prefixa
    - Enquanto prioridade(topo(v_operadores)) >= prioridade(i)
      - Desempilha j de v_operadores
      - Adiciona j em v_prefixa
      - Adiciona espaço em v_prefixa
    - Empilha i em v_operadores
  - Senão, se i == "("
    - Enquanto topo(v_operadores) != ')'
      - Adiciona espaço em v_prefixa
      - Desempilha j de v_operadores
      - Adiciona j em v_prefixa
    - Desempilha ')' de v_operadores
- Se v_operadores nao estiver vazia
  - Enquanto houver items em v_operadores
    - Adiciona espaço em v_prefixa
    - Desempilha j de v_operadores
    - Adiciona j em v_prefixa
- Inverte v_prefixa
