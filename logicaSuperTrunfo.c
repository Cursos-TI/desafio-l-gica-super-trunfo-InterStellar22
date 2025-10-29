#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>
#include <string.h>

int main() {
    // ===== Declaração das variáveis =====
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    float densidadePopulacional1, densidadePopulacional2;

    // ===== Entrada de dados =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf(" %s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a Populacao: ");
    scanf("%lu", &populacao1);

    printf("Digite a Area em km²: ");
    scanf("%f", &area1);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf(" %s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a Populacao: ");
    scanf("%lu", &populacao2);

    printf("Digite a Area em km²: ");
    scanf("%f", &area2);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // ===== Cálculos =====
    densidadePopulacional1 = populacao1 / area1;
    densidadePopulacional2 = populacao2 / area2;

    // ===== Menu interativo - Escolha de 2 atributos =====
    int atributo1, atributo2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    float soma1 = 0, soma2 = 0;

    printf("\n=== Escolha o PRIMEIRO atributo para comparar ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    printf("\n=== Escolha o SEGUNDO atributo (diferente do primeiro) ===\n");
    // Menu dinâmico - oculta o atributo já escolhido
    for (int i = 1; i <= 5; i++) {
        if (i == atributo1) continue;
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    if (atributo1 == atributo2) {
        printf("\nErro: os atributos devem ser diferentes!\n");
        return 0;
    }

    printf("\n===== Comparando %s e %s =====\n\n", cidade1, cidade2);

    // ===== Função auxiliar (switch para comparar atributos) =====
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? atributo1 : atributo2;
        float valorCarta1 = 0, valorCarta2 = 0;

        switch (atributo) {
            case 1:
                valorCarta1 = populacao1;
                valorCarta2 = populacao2;
                printf("Atributo %d: População\n", i);
                break;
            case 2:
                valorCarta1 = area1;
                valorCarta2 = area2;
                printf("Atributo %d: Área\n", i);
                break;
            case 3:
                valorCarta1 = pib1;
                valorCarta2 = pib2;
                printf("Atributo %d: PIB\n", i);
                break;
            case 4:
                valorCarta1 = pontosTuristicos1;
                valorCarta2 = pontosTuristicos2;
                printf("Atributo %d: Pontos Turísticos\n", i);
                break;
            case 5:
                valorCarta1 = densidadePopulacional1;
                valorCarta2 = densidadePopulacional2;
                printf("Atributo %d: Densidade Demográfica\n", i);
                break;
            default:
                printf("Opção inválida.\n");
                return 0;
        }

        printf("%s: %.2f\n", cidade1, valorCarta1);
        printf("%s: %.2f\n", cidade2, valorCarta2);

        // ===== Comparação (usando operador ternário e regra especial para densidade) =====
        if (atributo == 5) {
            printf("Menor valor vence!\n");
            (valorCarta1 < valorCarta2)
                ? printf("Vencedor: %s\n\n", cidade1)
                : (valorCarta2 < valorCarta1)
                    ? printf("Vencedor: %s\n\n", cidade2)
                    : printf("Empate!\n\n");
        } else {
            (valorCarta1 > valorCarta2)
                ? printf("Vencedor: %s\n\n", cidade1)
                : (valorCarta2 > valorCarta1)
                    ? printf("Vencedor: %s\n\n", cidade2)
                    : printf("Empate!\n\n");
        }

        // ===== Soma dos valores =====
        soma1 += valorCarta1;
        soma2 += valorCarta2;
    }

    // ===== Resultado final =====
    printf("===== RESULTADO FINAL =====\n");
    printf("%s - Soma dos atributos: %.2f\n", cidade1, soma1);
    printf("%s - Soma dos atributos: %.2f\n", cidade2, soma2);

    if (soma1 > soma2)
        printf("🏆 Vencedor final: %s\n", cidade1);
    else if (soma2 > soma1)
        printf("🏆 Vencedor final: %s\n", cidade2);
    else
        printf("⚖️ Empate!\n");

    printf("\n=== Fim da comparação ===\n");
    return 0;
}
