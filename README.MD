# Projeto de Estrutura de Dados

### Sistema de correção de algoritmos

Este sistema foi construído na linguagem C e tem por objetivo executar códigos em C para validar seu funcionamento.

### Como funciona?

É necessário cadastrar um caso de teste com **input** e **output**. (Essas serão as entradas que o código receberá e as saídas que deve retornar)

1 - Crie uma pasta para guardar os casos de teste do problema. Por exemplo A, B...
2 - Crie dentro da pasta do problema 3 pastas, **input**, **output** e **temp**.
3 - Dentro da pasta **input** crie um arquivo _.txt_ para cada entrada do problema, numerado em sequência (1.txt, 2.txt...), dentro deste arquivo adicione as entradas esperadas pelo programa. Por exemplo
```c
1 #include<stdio>
2
3 int main(){
4	int a, b;
5	scanf("%d %d", &a, &b);
6	printf("%d\n", a+b);
7	return 0;
8 }
```
A linha 7 recebe os valores para o cálculo da soma, ou seja essa entrada deve ser os valores que o arquivo **input** deve conter.

4 - Dentro da pasta **output** crie um arquivo _.txt_ para cada entrada criada anteriormente, ou seja, se existem 4 entradas, adicione 4 saídas, também numerados em sequência. Dentro do arquivo _.txt_ coloque o resultado esperado conforme a entrada do programa. Por exemplo

```bash
#### input\1.txt
2
2
```

```bash
#### output\1.txt
4
```
> Atente-se: Adicionar uma linha vazia no final ('\n'), pode interferir no resultado esperado na execução do código. Caso o arquivo _.txt_ possua uma linha em branco no final, o código deve adicionar uma quebra de linha ('\n') ao mostrar o resultado da soma

Realizando esta inserção de casos de teste, compile e execute o _**main.c**_. Será mostrado na tela a quantidade de problemas encontrados e quantos casos de teste cada um possui.

O programa solicitará para digitar o problema que será corrigido, insira o nome da pasta criada. Após isso o programa solicitará o código fonte a ser corrigido, insira o nome do arquivo com a extensão (_.c_), após isso o programa irá compilar e executar o código para validar os casos de teste.

### Respostas possíveis

As respostas possíveis de se obter ao corrigir um código são:
- Erro de compilação: existe um problema de sintaxe no código que não permite o código compilar.
- ERRO: o código produziu uma saída inesperada ou problemas de acesso a endereços de memória.
- OK: O código produziu a saída esperada corretamente,

### Alunos
Daniel Lucas
Mateus dos Santos
Luiz Felipe
