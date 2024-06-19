#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void imprimirVetor(int *vetor, int tamanho) {
    printf("Vetor: { ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("}\n");
}

void troca(int vet[], int i, int j){
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
    imprimirVetor(vet, 15); 
}

int particiona(int vet[], int inicio, int fim){
    int pivo, pivo_indice, i;

    pivo = vet[fim]; 
    pivo_indice = inicio;

    for (i = inicio; i < fim; i++) {
        if (vet[i] <= pivo) {
            troca(vet, i, pivo_indice);
            pivo_indice++;
        }
    }

    troca(vet, pivo_indice, fim);

    return pivo_indice;
}


int particionaRandom(int vet[], int inicio, int fim){
    int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
    troca(vet, pivo_indice, fim);
    return particiona(vet, inicio, fim);
}

void quickSort(int vet[], int inicio, int fim){
    if (inicio < fim) {
        int pivo_indice = particionaRandom(vet, inicio, fim);
        quickSort(vet, inicio, pivo_indice - 1);
        quickSort(vet, pivo_indice + 1, fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda = malloc(n1 * sizeof(int));
    int *direita = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        esquerda[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}

void mergeSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
        imprimirVetor(vetor, fim + 1);
    }
}

int main() {
    int opcao, vetor[] = {235, 24, 34, 54, 67, 109, 14, 6, 0, 23, 11, 1, 45, 65, 18};
    clock_t inicio, fim;
    double tempo_execucao;

    printf("\n\n\n|----------MENU DE ORDENACAO----------|\n");
    printf("|1 - Ordenar Utilizando Quick Sort    |\n");
    printf("|2 - Ordenar Utilizando Merge Sort    |\n");
    printf("|-------------------------------------|\n");
    printf("Metodo Selecionado: ");
    scanf("%d", &opcao);

    printf("Vetor Inicial:\n");
    imprimirVetor(vetor, 15);

    inicio = clock();

    switch (opcao) {
        case 1: 
            quickSort(vetor, 0, 14);
            printf("Vetor ordenado por Quick Sort:\n");
            printf("Primerio Elemento: %d \nUltimo Elemento:: %d\n", vetor[0], vetor[14]);
        break;

        case 2:
            mergeSort(vetor, 0, 14);
            printf("\nVetor ordenado por Merge Sort\n");
            printf("Primerio Elemento: %d \nUltimo Elemento: %d\n", vetor[0], vetor[14]);
        break;

        default:
            printf("Opcao invalida.\n");
            return 0;
    }

    fim = clock();
    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao: %.5f segundos.\n", tempo_execucao);

    return 1;
}
