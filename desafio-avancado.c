#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão para funções utilitárias
#include <string.h> // Biblioteca para manipulação de strings

// Definindo a estrutura do tipo Territorio
typedef struct {
    char nome[20];
    char cor[20];
    int tropas;
} Territorio;

// Função para entrada de territórios OBS(cdt = cadastro)
void cdt_Territorios(Territorio *territorios, int qtd) {
    for (int i = 0; i < qtd; i++) {

        // Limpa a tela a cada novo território
        system("clear"); // use "cls" se estiver no Windows

        printf ("=== Digite os dados do territorio %d ===\n\n", i + 1);

        printf ("Nome: ");
        fgets (territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // Limpa o \n(espaço, enter) do fgets

        printf ("Cor: ");
        fgets (territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; // Limpa o \n(espaço, enter) do fgets

        printf ("Número de tropas: ");
        scanf ("%d", &territorios[i].tropas);
        getchar (); // Limpar o buffer

        printf ("\n"); // Da um espaço para organização

    }
}

// Função para saída de dados dos territórios OBS(exib = exibir)
void exib_Territorios(Territorio *territorios, int qtd) {
    printf ("=== Dados dos Territórios ===\n\n");
    for (int i = 0; i < qtd; i++) {
        printf ("%d. %s (%s, Tropas: %d)\n",
        i + 1,
        territorios[i].nome,
        territorios[i].cor,
        territorios[i].tropas);

    }
}

int main() {
    int qtd_territorios = 5; // Definindo a quantidade de territorios

    Territorio *territorios = (Territorio*) calloc(qtd_territorios, sizeof(Territorio)); // Alocação dinâmica de memória para os territórios

    if (territorios == NULL) { // Programa encerra por erro de alocação
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Chamada das funções
    cdt_Territorios(territorios, qtd_territorios);
    exib_Territorios(territorios, qtd_territorios);

    // Liberando memória
    free(territorios);

    return 0;
}