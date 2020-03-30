## Non-Portuguese speakers

The book is written in Portuguese and, due that, any content here, except the code itself, is in Portuguese as well.

## Sobre o repositório

Esse repositório foi criado para guardar todas os exercícios feitos ao ler o livro [Estruturas de Dados em C, de Silvio do Lago Pereira](https://www.saraiva.com.br/estruturas-de-dados-em-c-uma-abordagem-didatica-9269528/p).

## Onde estão as implementações das estruturas?

O livro sempre implementa uma estrutura de dados e, em seguida, fornece alguns exercícios para que possamos praticar.

Como as estruturas são "genéricas" e sempre reutilizadas por vários exercícios, elas foram separadas em [outros repositórios](https://github.com/ss-c-cpp). Este aqui só contêm os exercícios.

[Clique aqui para ver as estruturas de dados implementadas](https://github.com/ss-c-cpp). Nem todos os repositórios nessa organização são estruturas de dados, mas as estruturas estão todas aí, espalhadas.

## Estrutura do projeto

Cada capítulo possui sua própria pasta nomeada `cap-[X]-[assunto]`. Os exercícios são nomeados como `[cap]-[numero]`, de acordo com o livro (ex. exercícios do capítulo 2 são numerados como 2.1, 2.2, 2.3 e por aí vai).

## Compilando os exercícios

Os exercícios foram feitos em um Ubuntu Linux 18.04 x64, e algumas instruções foram escritas em C99.

Cada exercício possui seu próprio arquivo de implementação e um arquivo de testes, que servem como testes unitários. São os arquivos de testes quem possuem a função `main()`, logo, para rodar cada exercício, é necessário compilar e executar o arquivo de teste, e não o arquivo principal.

Para compilar e executar um exercício, use:

```sh
$ make run exercise=[caminho/pasta/exercicio] # Nao inclua um `.test.c` no final

# Exemplo:
# make run exercise=cap-2-pilhas/2-5/2-5
```

## Debugging dos exercícios

### VS Code

Até então, além do próprio GDB via linha de comando, o único debuggin suportado é o do [VS Code](https://code.visualstudio.com/download).

Para fazer debugging de qualquer um dos exercícios usando o VS Code você precisa garantir que o arquivo com a **implementação** do exercício (e não o arquivo de teste) esteja aberto no VS Code e que este seja a "aba atual" quando você clicar na opção de debugging.

Essas "regras" precisam ser seguidas devido à maneira como o debugging do VS Code funciona. Nos arquivos de configuração (dentro do diretório `.vscode`), nós nos baseamos no nome do arquivo selecionado para fazer a configuração do debugging.

Por enquanto somente as implementações podem passar por debugging - os testes em si, não. Logo, breakpoints só funcionam dentro dos arquivos de implementação.

Se você quiser debugar o arquivo `cap-3-expressoes/conversor/conversor.c`, por exemplo, você precisa garantir que este arquivo esteja aberto na **aba atual** do seu VS Code quando clicar em `gcc - Build and debug active file`.
