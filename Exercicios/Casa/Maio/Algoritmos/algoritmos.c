#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

void lerArquivo(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    fclose(arquivo);
}

void bubbleSort(int *vetor, int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}


void insertionSort(int *vetor, int tamanho) {
    int i, j, chave;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}


void selectionSort(int *vetor, int tamanho) {
    int i, j, minIdx, temp;
    for (i = 0; i < tamanho - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            temp = vetor[i];
            vetor[i] = vetor[minIdx];
            vetor[minIdx] = temp;
        }
    }
}


void troca(int vet[], int i, int j){
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}


int particiona(int vet[], int inicio, int fim){
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; 
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++){
		if(vet[i] <= pivo){
			troca(vet, i, pivo_indice);
			pivo_indice++;
		}
	}
	
	troca(vet, pivo_indice, fim);
	
	return pivo_indice;
}


// Escolhe um pivô aleatório para evitar o pior caso do quicksort
int particionaRandom(int vet[], int inicio, int fim){
	
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	troca(vet, pivo_indice, fim);
	
	return particiona(vet, inicio, fim);
}


void quickSort(int vet[], int inicio, int fim){
	if(inicio < fim){
		int pivo_indice = particionaRandom(vet, inicio, fim);
		
		quickSort(vet, inicio, pivo_indice - 1);
		quickSort(vet, pivo_indice + 1, fim);
	}
}

void shellSort(int *vetor, int tamanho) {

    int atual = 0, proximo = 0, valor = 0, salto = 1;

    while(salto < tamanho) {
        salto = 3*salto+1;
    }

    while (salto > 0) {
        for(atual = salto; atual < tamanho; atual++) {
            valor = vetor[atual];
            proximo = atual;
            while (proximo > salto-1 && valor <= vetor[proximo-salto]) {
                vetor[proximo] = vetor[proximo-salto];
                proximo = proximo - salto;
            }
            vetor[proximo] = valor;
        }
        salto = salto/3;
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
    }
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
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(vetor, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        heapify(vetor, i, 0);
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
}

void radixSort(int *vetor, int tamanho) {
    int max = getMax(vetor, tamanho);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(vetor, tamanho, exp);
}