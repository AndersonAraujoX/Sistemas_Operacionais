# Trabalhos Práticos de Sistemas Operacionais

Este repositório contém os trabalhos práticos desenvolvidos para a disciplina de Sistemas Operacionais.

## Trabalho 1: Desenferrujando C

* **Descrição**: Implementação de um programa em C que busca uma determinada cadeia de caracteres em um arquivo de texto.
* **Funcionalidades**:
    * Recebe como argumentos de linha de comando a cadeia de busca e o nome do arquivo.
    * Imprime o número da linha e o conteúdo da linha onde a cadeia é encontrada.
    * Opcional: Implementação de opções para busca *case-insensitive* e busca em múltiplos arquivos.
* **Instruções de uso**:
    * Compile o código fonte: `gcc procura.c -o procura`
    * Execute o programa: `./procura abacate receitas.txt`

## Trabalho 2: Shell Script

* **Descrição**: Desenvolvimento de dois scripts shell para manipulação de arquivos executáveis.
* **Funcionalidades**:
    * O primeiro script verifica se um arquivo shell é executável e se possui uma linha *shebang*. Caso contrário, torna o arquivo executável e adiciona a linha `#!/bin/bash`.
    * O segundo script executa o primeiro script em todos os arquivos com extensão `.sh` no diretório corrente e subdiretórios.
* **Instruções de uso**:
    * Torne os scripts executáveis: `chmod +x script1.sh script2.sh`
    * Execute o segundo script: `./script2.sh`

## Trabalho 3: Processos, Threads e Criptografia

* **Descrição**: Implementação de exercícios relacionados a processos, threads e criptografia.
* **Exercícios**:
    1.  Mapa logístico:
        * Cálculo e desenho do diagrama de bifurcação do mapa logístico usando processos e comunicação IPC (arquivos e pipes).
        * Implementação da visualização em tempo real do diagrama usando pipes.
    2.  Implementação do diagrama de bifurcação usando pthreads, com comparação de desempenho entre processos e threads.
    3.  Estudo de funções OWF e hashcodes baseados em geradores de congruência linear.
    4.  Implementação de um codificador e decodificador usando um algoritmo de criptografia, com a senha gerada pelo hashcode do exercício anterior.

## Observações

* Todos os trabalhos foram desenvolvidos em ambiente Unix/Linux.
* Os códigos fonte estão comentados para facilitar a compreensão.
* Para o terceiro trabalho, o uso de alguma ferramenta de plotagem será necessário, como por exemplo, gnuplot, ou bibliotecas de plotagem de alguma linguagem como python.
