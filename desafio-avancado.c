#include <stdio.h>
#include <string.h>

// Definindo a estrutura do tipo Territorio
typedef struct {
    char nome[30];
    char cor[20];
    int tropas;
} Territorio;

int main() {
    Territorio territorio[5];

    // Preenchendo os dados dos territórios
    for (int i = 0; i < 5; i++) {
        printf ("=== Digite os dados do território %d ===\n", i + 1);
        
        // Lendo o nome do território
        printf ("Nome: ");
        fgets (territorio[i].nome, sizeof(territorio[i].nome), stdin);
        territorio[i].nome[strcspn(territorio[i].nome, "\n")] = '\0'; // Remover a nova linha do final
        
        // Lendo a cor do território
        printf ("Cor: ");
        fgets (territorio[i].cor, sizeof(territorio[i].cor), stdin);
        territorio[i].cor[strcspn(territorio[i].cor, "\n")] = '\0'; // Remover a nova linha do final

        // Lendo o número de tropas
        printf ("Número de tropas: ");
        scanf ("%d", &territorio[i].tropas);
        getchar(); // Limpar o buffer do teclado

        printf ("\n");
    }
    
    // Exibindo os dados dos territórios
    printf ("=== Dados dos Territórios ===\n");
    for (int i = 0; i < 5; i++) {
        printf ("%d. %s (%s) - %d Tropas\n",
        i + 1,
        territorio[i].nome,
        territorio[i].cor,
        territorio[i].tropas);

    }

    return 0;
}