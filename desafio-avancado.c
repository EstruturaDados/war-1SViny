#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão para funções utilitárias
#include <string.h> // Biblioteca para manipulação de strings

// Definindo a estrutura do tipo Territorio
typedef struct {
    char nome[20];
    char cor[20];
    int tropas;
} Territorio;

// Função para entrada de territórios
void cdt_Territorios(Territorio *territorios, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf ("=== Digite os dados do territorio %d ===\n\n", i + 1);

        printf ("Nome: ");
        fgets (territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf ("Cor: ");
        fgets (territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf ("Número de tropas: ");
        scanf ("%d", &territorios[i].tropas);
        getchar (); // Limpar o buffer

        printf ("\n");

    }
}

void exib_Territorios(Territorio *territorios, int qtd) {
    printf ("=== Dados dos Territórios ===\n\n");
    for (int i = 0; i < qtd; i++) {
    }
}

int main() {
    int qtd_territorios = 5; // Definindo a quantidade de territorios

    Territorio *territorios = (Territorio*) calloc(qtd_territorios, sizeof(Territorio)); // Alocando dinâmica de memória para os territórios

    if (territorios == NULL) { // Programa encerra por erro de alocação
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Preenchendo os dados dos territórios
    for (int i = 0; i < qtd_territorios; i++) {
        printf ("=== Digite os dados do território %d ===\n\n", i + 1);
        
        // Lendo o nome do território
        printf ("Nome: ");
        fgets (territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // Remover a nova linha do final
        
        // Lendo a cor do território
        printf ("Cor: ");
        fgets (territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; // Remover a nova linha do final

        // Lendo o número de tropas
        printf ("Número de tropas: ");
        scanf ("%d", &territorios[i].tropas);
        getchar(); // Limpar o buffer do teclado

        printf ("\n"); // Da um espaço para organização
    }
    
    // Exibindo os dados dos territorios
    printf ("=== Dados dos Territórios ===\n\n");
    for (int i = 0; i < qtd_territorios; i++) {
        printf ("%d. %s (%s) - %d Tropas\n",
        i + 1,
        territorios[i].nome,
        territorios[i].cor,
        territorios[i].tropas);

    }

    free(territorios);

    return 0;
}