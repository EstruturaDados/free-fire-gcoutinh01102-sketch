#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[10];
int total = 0;

void adicionar() {
    if (total >= 10) {
        printf("\nA mochila está cheia!\n");
        return;
    }

    Item novo;

    printf("\nNome do item: ");
    scanf("%s", novo.nome);

    printf("Tipo do item: ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[total] = novo;
    total++;

    printf("\nItem adicionado!\n");
}

void remover() {
    if (total == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item a remover: ");
    scanf("%s", nomeRemover);

    int pos = -1;

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nItem não encontrado!\n");
        return;
    }

    for (int i = pos; i < total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    total--;

    printf("\nItem removido!\n");
}

void listar() {
    if (total == 0) {
        printf("\nNenhum item na mochila.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("        ITENS NA MOCHILA\n");
    printf("=====================================\n");
    printf("%-15s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
    printf("-------------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%-15s %-15s %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
}

int main() {
    int opcao;

    do {
        printf("\n==============================\n");
        printf("     MENU DO INVENTÁRIO\n");
        printf("==============================\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionar(); break;
            case 2: remover(); break;
            case 3: listar(); break;
            case 0: printf("\nSaindo...\n"); break;
            default: printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
