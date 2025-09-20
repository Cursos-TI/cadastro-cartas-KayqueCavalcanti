#include <stdio.h>

// Código — Nível Mestre

int main() {
    // --- Carta 1 ---
    char estado1;
    char codigo1[4];
    char cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos1;

    // --- Carta 2 ---
    char estado2;
    char codigo2[4];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // --- Cálculos da Carta 1 ---
    float densidade1 = populacao1 / area1;
    float pib_per_capita1 = (pib1 * 1000000000.0) / populacao1; 
    float super_poder1 = populacao1 + area1 + pib1 + pontos1 + pib_per_capita1;

    // --- Cálculos da Carta 2 ---
    float densidade2 = populacao2 / area2;
    float pib_per_capita2 = (pib2 * 1000000000.0) / populacao2;
    float super_poder2 = populacao2 + area2 + pib2 + pontos2 + pib_per_capita2;

    // Exibição das cartas
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Comparações
    printf("\n=== Comparacoes ===\n");

    // População
    if (populacao1 > populacao2)
        printf("Populacao: Carta 1 venceu!\n");
    else if (populacao2 > populacao1)
        printf("Populacao: Carta 2 venceu!\n");
    else
        printf("Populacao: Empate!\n");

    // Área
    if (area1 > area2)
        printf("Area: Carta 1 venceu!\n");
    else if (area2 > area1)
        printf("Area: Carta 2 venceu!\n");
    else
        printf("Area: Empate!\n");

    // PIB
    if (pib1 > pib2)
        printf("PIB: Carta 1 venceu!\n");
    else if (pib2 > pib1)
        printf("PIB: Carta 2 venceu!\n");
    else
        printf("PIB: Empate!\n");

    // Pontos turísticos
    if (pontos1 > pontos2)
        printf("Pontos Turisticos: Carta 1 venceu!\n");
    else if (pontos2 > pontos1)
        printf("Pontos Turisticos: Carta 2 venceu!\n");
    else
        printf("Pontos Turisticos: Empate!\n");

    // Densidade Populacional (menor vence)
    if (densidade1 < densidade2)
        printf("Densidade Populacional: Carta 1 venceu!\n");
    else if (densidade2 < densidade1)
        printf("Densidade Populacional: Carta 2 venceu!\n");
    else
        printf("Densidade Populacional: Empate!\n");

    // PIB per capita
    if (pib_per_capita1 > pib_per_capita2)
        printf("PIB per capita: Carta 1 venceu!\n");
    else if (pib_per_capita2 > pib_per_capita1)
        printf("PIB per capita: Carta 2 venceu!\n");
    else
        printf("PIB per capita: Empate!\n");

    // Super Poder
    if (super_poder1 > super_poder2)
        printf("Super Poder: Carta 1 venceu!\n");
    else if (super_poder2 > super_poder1)
        printf("Super Poder: Carta 2 venceu!\n");
    else
        printf("Super Poder: Empate!\n");

    return 0;
}
