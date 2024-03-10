#include <stdio.h>
#include <stdlib.h>

struct livro{

    int ordem;
    char nome[30];
    char autor[60];

}; typedef struct livro Livro;


int pesquisa_binaria ( Livro vetor[], int tamanho, int n ) {

    // Condicional de Segurança
    if ( vetor == NULL || n > tamanho || n < 0 ) {

        printf ( "CRITICAL ERROR" );
        return 0;

    }

    int inicio = 0;
    int fim = tamanho - 1;

    // Enquanto não acha o valor, o  programa repete o loop e divide a área de busca pela metade
    while ( inicio <= fim ) {

        // Define aonde será o meio do vetor
        int meio = ( inicio + fim ) / 2;

        // Quando acha o valor, o programa imprime os dados
        if ( vetor[meio].ordem == n ) {

            printf ( "Livro encontrado! %s eh o %d livro da biblia, o seu autor eh %s.\n", vetor[meio].nome, vetor[meio].ordem, vetor[meio].autor  );
            return 1;

        // Caso o valor esteja a direita do meio, o novo inicio é o elemento depois do meio do vetor
        } else if ( vetor[meio].ordem < n ) {

            inicio = meio + 1;

        // Caso o valor esteja a esquerda do meio, o novo inicio é o elemento anterior do meio do vetor
        } else {

            fim = meio - 1;

        }
    }

    // Caso não achar o valor, imprime a mensagem de erro e retorna 0
    printf ( "Livro nao encontrado.\n" );
    return 0; 

}


int main() {
    
    Livro biblia[] = { { 1, "Genesis", "Moises" }, { 2, "Exodo", "Moises" },
                       { 3, "Levitico", "Moises" }, { 4, "Numeros", "Moises" },
                       { 5, "Deuteronomio", "Moises" }, { 6, "Josue", "Desconhecido" },
                       { 7, "Juizes", "Samuel" }, { 8, "Rute", "Desconhecido" },
                       { 9, "1 Samuel", "Samuel, Gade e Nata" }, { 10, "2 Samuel", "Samuel, Gade e Nata" },
                       { 11, "1 Reis", "Jeremias" }, { 12, "2 Reis", "Jeremias" },
                       { 13, "1 Cronicas", "Esdras" }, { 14, "2 Cronicasl", "Esdras" },
                       { 15, "Esdras", "Esdras" }, { 16, "Neemias", "Neemias" },
                       { 17, "Ester", "Desconhecido" }, { 18, "Jo", "Moises" },
                       { 19, "Salmos", "Davi, Moises, Asafe e Hema" }, { 20, "Proverbios", "Salomao" },
                       { 21, "Eclesiastes", "Salomao" }, { 22, "Canticos", "Salomao" },
                       { 23, "Isaias", "Isaias" }, { 24, "Jeremias", "Jeremias" },
                       { 25, "Lamentacoes", "Jeremias" }, { 26, "Ezequiel", "Ezequiel" },
                       { 27, "Daniel", "Daniel" }, { 28, "Oseias", "Oseias" },
                       { 29, "Joel", "Joel" }, { 30, "Amos", "Amos" },
                       { 31, "Obadias", "Obadias" }, { 32, "Jonas", "Desconhecido" },
                       { 33, "Miqueias", "Desconhecido" }, { 34, "Naum", "Naum" },
                       { 35, "Habacuque", "Habacuque" }, { 36, "Sofonias", "Sofonias" },
                       { 37, "Ageu", "Ageu" }, { 38, "Zacarias", "Zacarias" },
                       { 39, "Malaquias", "Desconhecido" }, { 40, "Mateus", "Mateus" },
                       { 41, "Marcos", "Marcos" }, { 42, "Lucas", "Lucas" },
                       { 43, "Joao", "Joao" }, { 44, "Atos dos Apostolos", "Lucas" },
                       { 45, "Romanos", "Paulo" }, { 46, "1 Corintios", "Paulo" },
                       { 47, "2 Corintios", "Paulo" }, { 48, "Galatas", "Paulo" },
                       { 49, "Efesios", "Paulo" }, { 50, "Filipenses", "Paulo" },
                       { 51, "Colossenses", "Paulo" }, { 52, "1 Tessalonicenses", "Paulo" },
                       { 53, "2 Tessalonicenses", "Paulo" }, { 54, "1 Timóteo", "Paulo" },
                       { 55, "2 Timóteo", "Paulo" }, { 56, "Tito", "Paulo" },
                       { 57, "Filemom", "Paulo" }, { 58, "Hebreus", "Paulo" },
                       { 59, "Tiago", "Tiago" }, { 60, "1 Pedro", "Pedro" },
                       { 61, "2 Pedro", "Pedro" }, { 62, "1 Joao", "Joao" },
                       { 63, "2 Joao", "Joao" }, { 64, "3 Joao", "Joao" },
                       { 65, "Judas", "Judas" }, { 66, "Apocalipse", "Joao" }};


    int tamanho = sizeof( biblia ) / sizeof ( biblia[0] );
    int busca;

    printf("Digite o numero do livro a ser procurado: ");
    scanf("%d", &busca);

    pesquisa_binaria ( biblia, tamanho, busca );

    return 0;

}