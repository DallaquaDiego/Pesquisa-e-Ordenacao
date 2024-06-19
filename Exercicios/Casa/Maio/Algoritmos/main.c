#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.c"
#include <time.h>

int main() {
    int arquivo, opcao;
    clock_t inicio, fim;
    double tempo_execucao;


    printf("|-------MENU DE ARQUIVOS------|\n");
    printf("|1 - Ler o Arquivo Ordenado   |\n");
    printf("|2 - Ler o Arquivo Invertido  |\n");
    printf("|3 - Ler o Arquivo Desordenado|\n");
    printf("|-----------------------------|\n");
    printf("Arquivo Selecionado: ");
    scanf("%d", &arquivo);
    

    printf("\n\n\n|----------MENU DE ORDENACAO----------|\n");
    printf("|1 - Ordenar Utilizando Bubble Sort   |\n");
    printf("|2 - Ordenar Utilizando Insertion Sort|\n");
    printf("|3 - Ordenar Utilizando Selection Sort|\n");
    printf("|4 - Ordenar Utilizando Shell Sort    |\n");
    printf("|5 - Ordenar Utilizando Quick Sort    |\n");
    printf("|6 - Ordenar Utilizando Merge Sort    |\n");
    printf("|7 - Ordenar Utilizando Heap Sort     |\n");
    printf("|8 - Ordenar Utilizando Radix Sort    |\n");
    printf("|-------------------------------------|\n");
    printf("Metodo Selecionado: ");
    scanf("%d", &opcao);

    int tamanho;

    int *vetor = malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        return 1;
    }
    

    switch (arquivo) {
        case 1: {
            FILE *ordenado = fopen("ordenado.txt", "r");
            if (ordenado == NULL) {
                printf("Erro ao abrir o arquivo ordenado.txt.\n");
                return 1;
            }
            int i = 0;
            while (fscanf(ordenado, "%d", &vetor[i]) != EOF) {
                i++;
            }
            tamanho = i;
            fclose(ordenado);
            break;
        }
        case 2: {
            FILE *invertido = fopen("invertido.txt", "r");
            if (invertido == NULL) {
                printf("Erro ao abrir o arquivo invertido.txt.\n");
                return 1;
            }
            int i = 0;
            while (fscanf(invertido, "%d", &vetor[i]) != EOF) {
                i++;
            }
            tamanho = i;
            fclose(invertido);
            break;
        }
        case 3: {
            FILE *randomico = fopen("randomico.txt", "r");
            if (randomico == NULL) {
                printf("Erro ao abrir o arquivo randomico.txt.\n");
                return 1;
            }
            int i = 0;
            while (fscanf(randomico, "%d", &vetor[i]) != EOF) {
                i++;
            }
            tamanho = i;
            fclose(randomico);
            break;
        }
        default:
            printf("Opcao invalida.\n");
            return 1;
    }

    inicio = clock();

    switch (opcao) {
        case 1: 
            bubbleSort(vetor, tamanho);
            printf("Vetor ordenado por Bubble Sort:\n");
            printf("FIRST: %d \nLAST: %d\nFILE SIZE: %d\n", vetor[0], vetor[tamanho - 1], tamanho);
        break;
        
        case 2: 
            insertionSort(vetor, tamanho);
            printf("Vetor ordenado por Insertion Sort:\n");
            printf("FIRST: %d \nLAST: %d\nFILE SIZE: %d\n", vetor[0], vetor[tamanho - 1], tamanho);
        break;
        
        case 3: 
            selectionSort(vetor, tamanho);
            printf("Vetor ordenado por Selection Sort:\n");
            printf("FIRST: %d \nLAST: %d\nFILE SIZE: %d\n", vetor[0], vetor[tamanho - 1], tamanho);
        break;
        
        case 4: 
            shellSort(vetor, tamanho);
            printf("Vetor ordenado por Shell Sort:\n");
            printf("FIRST: %d \nLAST: %d\nFILE SIZE: %d\n", vetor[0], vetor[tamanho - 1], tamanho);
        break;

        case 5: 
            quickSort(vetor, 0, tamanho - 1);
            printf("Vetor ordenado por Quick Sort:\n");
            printf("FIRST: %d \nLAST: %d\nFILE SIZE: %d\n", vetor[0], vetor[tamanho - 1], tamanho);
        break;

        case 6:
            mergeSort(vetor, 0, tamanho - 1);
            printf("\nVetor ordenado por Merge Sort\n");
            printf("FIRST: %d \nLAST: %d\nFILE SIZE: %d\n", vetor[0], vetor[tamanho - 1], tamanho);
        break;

        case 7:
            heapSort(vetor, tamanho);
            printf("Vetor ordenado por Heap Sort:\n");
            printf("FIRST: %d \nLAST: %d\nFILE SIZE: %d\n", vetor[0], vetor[tamanho - 1], tamanho);
        break;

        case 8:
            radixSort(vetor, tamanho);
            printf("Vetor ordenado por Radix Sort:\n");
            printf("FIRST: %d \nLAST: %d\nFILE SIZE: %d\n", vetor[0], vetor[tamanho - 1], tamanho);
        break;

        default:
            printf("Opcao invalida.\n");
        return 0;
    }

    fim = clock();
    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao: %.3f segundos.\n", tempo_execucao);

    free(vetor);

    return 1;
}