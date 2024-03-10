#include <stdio.h>
#include <stdlib.h>

#define MAX_NOME_ALUNO 50

typedef struct {

    int num;
    char nome[MAX_NOME_ALUNO];

} Aluno;

int pesquisa_binaria ( Aluno vetor[], int tamanho, int busca ) {

    // Condicional de Segurança
    if ( vetor == NULL || busca > tamanho || busca < 0 ) {

        printf ( "CRITICAL ERROR" );
        return 0;

    }

    int inicio = 0;
    int fim = tamanho - 1;

    while ( inicio <= fim ) {

        int meio = (inicio + fim) / 2;

        if (vetor[meio].num == busca ) {

            printf ( "Aluno Encontrado!\nNumero: %d - Nome: %s", vetor[meio].num, vetor[meio].nome  );
            return 1;

        } else if ( vetor[meio].num < busca ) {

            inicio = meio + 1;

        } else {

            fim = meio - 1;

        }
    }

    printf ( "Numero nao encontrado.\n" );
    return 0; 

}



int main() {

    FILE *arquivo;
    char nome_arquivo[10] = "uga.txt";
    int num_busca;

    arquivo = fopen ( nome_arquivo, "r" );

    if ( arquivo == NULL ) {

        printf ( "Erro ao abrir o arquivo.\n" );
        return -1;

    }

    // Conta quantas linhas o arquivo tem para determinar o tamanho do vetor
    int tamanho_vetor = 0;
    char buffer[MAX_NOME_ALUNO];

    while ( fscanf ( arquivo, "%s", buffer ) != EOF ) {

        tamanho_vetor++;

    }

    // Volta ao início do arquivo para ler os dados
    rewind ( arquivo );

    // Aloca dinamicamente o vetor de alunos
    Aluno *vetor_alunos = ( Aluno* ) malloc ( tamanho_vetor * sizeof ( Aluno ) );

    // Lê os dados do arquivo e armazena no vetor
    for ( int i = 0; i < tamanho_vetor; i++ ) {

        fscanf ( arquivo, "%d %s", &vetor_alunos[i].num, vetor_alunos[i].nome );
    }

    // Fecha o arquivo
    fclose ( arquivo );

    // Solicita o número do aluno a ser buscado
    printf ( "Digite o numero do aluno a ser buscado: " );
    scanf ( "%d", &num_busca );

    // Realiza a busca binária
    pesquisa_binaria ( vetor_alunos, tamanho_vetor, num_busca );

    // Libera a memória
    free ( vetor_alunos );

    return 0;
}