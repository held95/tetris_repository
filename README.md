🎮 Tetris Stack – Sistema de Fila de Peças Futuras
Projeto em C utilizando Fila Circular, Structs e Modularização

Este projeto implementa a mecânica principal da fila de peças do jogo Tetris Stack, desenvolvido pela ByteBros.
O objetivo é simular o sistema interno de organização de peças futuras, permitindo ao jogador visualizar, inserir e jogar peças, utilizando conceitos fundamentais de estruturas de dados.

📌 Descrição Geral

Neste jogo educativo, o sistema de peças futuras é representado por uma fila circular.
A cada jogada, o jogador pode:

Jogar uma peça → remove a peça da frente da fila (dequeue)

Inserir uma nova peça → adiciona ao final da fila (enqueue)

Visualizar a fila completa → mostra todas as peças na ordem correta

Cada peça contém:

nome da peça → 'I', 'O', 'T' ou 'L'

id único → número incremental que representa sua ordem de geração

As peças são criadas automaticamente por gerarPeca().

🧠 Conceitos Envolvidos
✔️ 1. Fila Circular

Permite inserção e remoção eficientes, reaproveitando espaço com aritmética modular.

✔️ 2. Structs

Peças e a estrutura da fila são representadas com struct.

✔️ 3. Modularização

Funções separadas deixam o código limpo e de fácil manutenção:

inicializarFila()

gerarPeca()

enqueue()

dequeue()

exibirFila()

filaCheia()

filaVazia()

lerInteiro() (versão compatível com OneCompiler)

✔️ 4. Entrada e Saída

Menu interativo para manipulação da fila.
