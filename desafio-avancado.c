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

// Função para mover as tropas
void mov_Tropas(Territorio *territorios, int qtd) {
    int origem, destino, quant;

    printf("=== Movimentação das Tropas ===\n\n");

    // 1. Mostra os territórios existentes
    exib_Territorios(territorios, qtd);

    // 2. Escolha do território de origem
    printf ("\nMover tropas DE qual território? (1 a %d): ", qtd);
    scanf ("%d", &origem);
    getchar ();

    // Ajusta origem para índice (0 a qtd-1)
    origem--;

    // Validação
    if (origem < 0 || origem >= qtd) {
        printf ("Território de origem inválido\n");
        return;

    }

    // 3. Escolha do territótio destino
    printf ("Mover tropas PARA qual território? (1 a %d): ", qtd);
    scanf ("%d", &destino);
    getchar ();

    destino--;

    if (destino < 0 || destino >= qtd) {
        printf ("Território de destino inválido!\n");
        return;

    }

    // Não pode mover para o mesmo território
    if (origem == destino) {
        printf("Origem e destino não podem ser iguais!\n");
        return;

    }

    // 4. Pergunta quantas tropas mover
    printf ("Quantas tropas deseja mover? ");
    scanf ("%d", &quant);
    getchar();

    // Validações
    if (quant <= 0) {
        printf ("Quantidade inválida!\n");
        return;

    }

    if (quant > territorios[origem].tropas) {
        printf ("Tropas insuficientes no território de orgiem!\n");
        return;

    }

    // 5. Atualiza os valores
    territorios[origem].tropas -= quant;
    territorios[origem].tropas += quant;

    // 6. Mensagem final
    printf ("Movimentação concluída com sucesso!\n");

}

// Função principal
int main() {
    int qtd_territorios = 5; // Definindo a quantidade de territorios
    int opcao; // Variável de opção do menu interativo

    Territorio *territorios = (Territorio*) calloc(qtd_territorios, sizeof(Territorio)); // Alocação dinâmica de memória para os territórios

    if (territorios == NULL) { // Programa encerra por erro de alocação
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    do {
        printf ("\n=== MENU PRINCIPAL ===\n");
        printf ("Digite os números para acessar as opções\n");
        printf ("1. Cadastrar Territórios\n");
        printf ("2. Exibir Territórios\n");
        printf ("0. Sair\n");
        scanf ("%d", &opcao);
        getchar (); // Limpa o buffer após ler a opção

        switch (opcao) {
            case 1:
                cdt_Territorios(territorios, qtd_territorios);
                break;
            case 2:
                exib_Territorios(territorios, qtd_territorios);
                break;
            case 3:
                mov_Tropas(territorios, qtd_territorios);
                break;
            case 0:
                printf("\nPrograma encerrado...\n");
                break;
            default:
                printf ("\nOpção inválida! Tente novamente.\n");

        }
    
    } while (opcao != 0);

    // Liberando memória
    free(territorios);

    return 0;
}