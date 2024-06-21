#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Função para preencher o arquivo com números em ordem crescente
void preencherOrdenado(FILE *arquivo, int tamanho) {
    for (int i = 1; i <= tamanho; i++) {
        fprintf(arquivo, "%d\n", i);
    }
}

// Função para preencher o arquivo com números em ordem decrescente
void preencherInvertido(FILE *arquivo, int tamanho) {
    for (int i = tamanho; i >= 1; i--) {
        fprintf(arquivo, "%d\n", i);
    }
}

// Função para preencher o arquivo com números aleatórios
void preencherRandomico(FILE *arquivo, int tamanho) {
    srand(time(NULL)); // Semente para números aleatórios
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d\n", rand() % tamanho + 1);
    }
}

int main() {
    int tamanho;

    printf("Escolha o tamanho dos arquivos:\n");
    printf("1 - 1000000 dados\n");
    printf("2 - 1500000 dados\n");
    printf("3 - 2000000 dados\n");
    printf("4 - 2500000 dados\n");
    printf("5 - 3000000 dados\n");
    printf("Tamanho Selecionado: ");
    scanf("%d", &tamanho); 

    switch (tamanho) {
        case 1:
            tamanho = 1000000;
        break;

        case 2:
            tamanho = 1500000;
        break;

        case 3:
            tamanho = 2000000;
        break;

        case 4:
            tamanho = 2500000;
        break;

        case 5:
            tamanho = 3000000;
        break;

        default:
            printf("Opcao invalida.\n");
        return 1;
    }

    FILE *ordenado = fopen("ordenado.txt", "w");
    FILE *invertido = fopen("invertido.txt", "w");
    FILE *randomico = fopen("randomico.txt", "w");

    if (ordenado == NULL || invertido == NULL || randomico == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    preencherOrdenado(ordenado, tamanho);
    preencherInvertido(invertido, tamanho);
    preencherRandomico(randomico, tamanho);

    fclose(ordenado);
    fclose(invertido);
    fclose(randomico);

    printf("Arquivos criados com sucesso!\n");

    return 0;
}
