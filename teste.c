#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista encadeada
typedef struct Node {
    int x;
    int y;
    struct Node *next;
} Node;

int total_passos = 0;

// Função para adicionar um nó à 
void adicionar_no(Node **head, int x, int y) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->x = x;
    novo->y = y;
    novo->next = *head;
    *head = novo;
}

// Função para imprimir a lista 
void imprimir_lista(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("(%d, %d) -> ", temp->x, temp->y);
        temp = temp->next;
    }
    printf("Fim\n");
}

// Função para liberar a lista encadeada
void liberar_lista(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Função que calcula os passos com base no ciclo atual
int calculaPassos(int ciclo) {
    int passos = 1;
    if (ciclo == 1) return 1;

    int diferenca = 1; 

    for (int i = 2; i <= ciclo; i++) {
        passos += diferenca;

        if (i % 2 == 0) {
            diferenca++;
        }
    }

    total_passos += passos;  // Atualiza o total de passos
    return passos;
}

// Função que movimenta o robô e atualiza a lista de posições
void movimentar_robo(int ciclos) {
    int x = 0, y = 0, direcao = 0;
    Node *lista = NULL;

    // Adiciona o ponto de origem (0, 0)
    adicionar_no(&lista, x, y);
    
    for (int i = 1; i <= ciclos; i++) {
        int passos = calculaPassos(i);  // Calcula o número de passos para o ciclo atual

        // Movimentação do robô conforme a direção
        switch (direcao) {
            case 0: // Direita
                x += passos;
                break;
            case 1: // Cima
                y += passos;
                break;
            case 2: // Esquerda
                x -= passos;
                break;
            case 3: // Baixo
                y -= passos;
                break;
        }

        // Adiciona o novo ponto à lista
        adicionar_no(&lista, x, y);

        // Gira 90° à esquerda (anti-horário)
        direcao = (direcao + 1) % 4;
    }

    // Imprime a lista de pontos percorridos
    imprimir_lista(lista);

    // Libera a lista encadeada
    liberar_lista(lista);
}

int main() {
    int ciclos;
    int temp = 0, i;

    do {
        printf("Qual opcao desejas realizar?\n");
        printf("(1) Movimentar o Robo.\n");
        printf("(2) Descobrir a quantidade de passos realizados ate o momento.\n");
        printf("(3) Onde o robo esta localizado.\n");
        printf("(4) Quantos ciclos foram realizados ate agora.\n");
        printf("(0) Sair do programa.\n");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("Digite a quantidade de ciclos: ");
                scanf("%d", &ciclos);
                temp += ciclos;
                movimentar_robo(ciclos);  // Move o robô e atualiza a contagem de passos
                break;

            case 2:
                printf("Foram realizados %d passos ate o momento\n", total_passos);
                break;

            case 3:
                printf("Robo esta na origem, pois nao mantemos a coordenada atual fora do escopo de movimentacao.\n");
                break;

            case 4:
                printf("Total de ciclos realizados: %d\n", temp);
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (i != 0);

    return 0;
}
