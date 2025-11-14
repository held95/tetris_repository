#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM_FILA 5

typedef struct {
    char nome;
    int id;
} Peca;

typedef struct {
    Peca vetor[TAM_FILA];
    int front;
    int rear;
    int quantidade;
} Fila;

// ----------------------
// Leitura segura de inteiro
// ----------------------
int lerInteiro() {
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    return atoi(buffer);
}

// ----------------------
void inicializarFila(Fila *f) {
    f->front = 0;
    f->rear = -1;
    f->quantidade = 0;
}

int filaCheia(Fila *f) {
    return f->quantidade == TAM_FILA;
}

int filaVazia(Fila *f) {
    return f->quantidade == 0;
}

Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca nova;
    nova.nome = tipos[rand() % 4];
    nova.id = id;
    return nova;
}

void enqueue(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Nao e possivel inserir.\n");
        return;
    }

    f->rear = (f->rear + 1) % TAM_FILA;
    f->vetor[f->rear] = p;
    f->quantidade++;

    printf("Peca [%c %d] inserida.\n", p.nome, p.id);
}

Peca dequeue(Fila *f) {
    Peca vazio;
    vazio.nome = '-';
    vazio.id = -1;

    if (filaVazia(f)) {
        printf("Fila vazia! Nao ha peca para jogar.\n");
        return vazio;
    }

    Peca removida = f->vetor[f->front];
    f->front = (f->front + 1) % TAM_FILA;
    f->quantidade--;

    printf("Peca jogada: [%c %d]\n", removida.nome, removida.id);
    return removida;
}

void exibirFila(Fila *f) {
    printf("\n=== Fila de Pecas ===\n");

    if (filaVazia(f)) {
        printf("[vazia]\n");
        return;
    }

    for (int i = 0; i < f->quantidade; i++) {
        int idx = (f->front + i) % TAM_FILA;
        printf("[%c %d] ", f->vetor[idx].nome, f->vetor[idx].id);
    }
    printf("\n=====================\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    srand(time(NULL));

    int opcao;
    int contadorID = 0;

    printf("Inicializando fila...\n");
    for (int i = 0; i < TAM_FILA; i++) {
        enqueue(&fila, gerarPeca(contadorID++));
    }

    do {
        exibirFila(&fila);

        printf("\n1 - Jogar peca\n");
        printf("2 - Inserir nova peca\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        opcao = lerInteiro();

        switch (opcao) {
            case 1:
                dequeue(&fila);
                break;
            case 2:
                enqueue(&fila, gerarPeca(contadorID++));
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
