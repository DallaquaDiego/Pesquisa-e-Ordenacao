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

void heapify(int *vetor, int tamanho, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < tamanho && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    if (direita < tamanho && vetor[direita] > vetor[maior])
        maior = direita;

    if (maior != i) {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;

        heapify(vetor, tamanho, maior);
    }
}

void heapSort(int *vetor, int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(vetor, tamanho, i);
        imprimirVetor(vetor, tamanho); 
    }

    for (int i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        heapify(vetor, i, 0);
        imprimirVetor(vetor, tamanho);  
    }
}

int getMax(int *vetor, int tamanho) {
    int max = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max)
            max = vetor[i];
    }
    return max;
}

void countSort(int *vetor, int tamanho, int exp) {
    int *output = malloc(tamanho * sizeof(int));
    if (output == NULL) {
        printf("Erro ao alocar memória para Output.\n");
        return;
    }

    int count[10] = {0};

    for (int i = 0; i < tamanho; i++) 
        count[(vetor[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = tamanho - 1; i >= 0; i--) {
        output[count[(vetor[i] / exp) % 10] - 1] = vetor[i];
        count[(vetor[i] / exp) % 10]--;
    }

    for (int i = 0; i < tamanho; i++)
        vetor[i] = output[i];

    free(output);
    imprimirVetor(vetor, tamanho);  
    printf("Finalizou countSort\n");
}

void radixSort(int *vetor, int tamanho) {
    int max = getMax(vetor, tamanho);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(vetor, tamanho, exp);
}

int main() {
    int opcao, tamanho = 0;
    clock_t inicio, fim;
    double tempo_execucao;

    printf("|----------MENU DE ORDENACAO----------|\n");
    printf("|1 - Ordenar Utilizando Heap Sort     |\n");
    printf("|2 - Ordenar Utilizando Radix Sort    |\n");
    printf("|-------------------------------------|\n");
    printf("Metodo Selecionado: ");
    scanf("%d", &opcao);
    printf("\n\n");

    
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo .txt.\n");
        return 1;
    }

    int i;
    while (fscanf(arquivo, "%d", &i) != EOF) {
        tamanho++;
    }

    fclose(arquivo); 

    arquivo = fopen("dados.txt", "r"); 

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo .txt.\n");
        return 1;
    }

    int *vetor = malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor.\n");
        fclose(arquivo);
        return 1;
    }

    
    for (i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &vetor[i]);
    }

    fclose(arquivo);

    inicio = clock();

    switch (opcao) {
        case 1:
            heapSort(vetor, tamanho);
            printf("\nOrdenacao utilizando Heap Sort finalizada!\n");
            printf("Primeiro Elemento: %d\nUltimo Elemento: %d\n", vetor[0], vetor[tamanho - 1]);
        break;

        case 2:
            radixSort(vetor, tamanho);
            printf("Ordenacao utilizando Radix Sort finalizada!\n");
            printf("Primeiro Elemento: %d\nUltimo Elemento: %d\n", vetor[0], vetor[tamanho - 1]);
        break;

        default:
            printf("Opcao invalida.\n");
        return 0;
    }

    fim = clock();
    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao: %.5f segundos.\n", tempo_execucao);

    free(vetor);

    return 1;
}
