/* super_trunfo.c  - Nível Mestre (corrigido para nomes com espaços)
   - Corrige bug de leitura quando o nome da cidade contém espaços
   - Usa fgets() para nomes e clear_input_buffer() para limpar '\n'
*/

#include <stdio.h>
#include <string.h>

#define MAX_CIDADE 100

/* Limpa o buffer de entrada até o fim da linha */
void clear_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { /* nada */ }
}

/* Remove '\n' final deixado por fgets, se existir */
void strip_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';
}

int main(void) {
    /* Carta 1 */
    char estado1;
    char codigo1[4];
    char cidade1[MAX_CIDADE];
    unsigned long populacao1;
    float area1;
    float pib1;              /* em bilhões */
    int pontos1;

    /* Carta 2 */
    char estado2;
    char codigo2[4];
    char cidade2[MAX_CIDADE];
    unsigned long populacao2;
    float area2;
    float pib2;              /* em bilhões */
    int pontos2;

    /* --- Cadastro Carta 1 --- */
    printf("Cadastro da Carta 1:\n");

    printf("Estado:");
    scanf(" %c", &estado1);           /* ' %c' pula espaços em branco anteriores */

    printf("Codigo da Carta: ");
    scanf("%3s", codigo1);            /* lê código sem espaços */

    /* limpar resto da linha antes de usar fgets */
    clear_input_buffer();

    printf("Nome da Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);  /* lê linha inteira, com espaços */
    strip_newline(cidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    /* --- Cadastro Carta 2 --- */
    printf("\nCadastro da Carta 2:\n");

    printf("Estado: ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta: ");
    scanf("%3s", codigo2);

    /* limpar resto da linha antes de usar fgets */
    clear_input_buffer();

    printf("Nome da Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    strip_newline(cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB (bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    /* --- Cálculos --- */
    float densidade1 = 0.0f;
    float densidade2 = 0.0f;
    float pib_per_capita1 = 0.0f;
    float pib_per_capita2 = 0.0f;
    float inv_densidade1 = 0.0f;
    float inv_densidade2 = 0.0f;

    if (area1 > 0.0f) {
        densidade1 = (float)populacao1 / area1;
        inv_densidade1 = 1.0f / densidade1;
    }
    if (area2 > 0.0f) {
        densidade2 = (float)populacao2 / area2;
        inv_densidade2 = 1.0f / densidade2;
    }
    if (populacao1 > 0UL) {
        pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1; /* PIB (bilhões -> reais) */
    }
    if (populacao2 > 0UL) {
        pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    }

    /* Super Poder: soma de tudo (faz cast para float para somar tipos diferentes) */
    float super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontos1 + pib_per_capita1 + inv_densidade1;
    float super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos2 + pib_per_capita2 + inv_densidade2;

    /* --- Exibição das cartas --- */
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    /* --- Comparações (imprime 1 se Carta 1 vence, 0 se Carta 2 vence; Empate indicado) --- */
    printf("\n=== Comparacao de Cartas ===\n");

    /* População (maior vence) */
    if (populacao1 > populacao2) printf("Populacao: Carta 1 venceu (1)\n");
    else if (populacao2 > populacao1) printf("Populacao: Carta 2 venceu (0)\n");
    else printf("Populacao: Empate\n");

    /* Area (maior vence) */
    if (area1 > area2) printf("Area: Carta 1 venceu (1)\n");
    else if (area2 > area1) printf("Area: Carta 2 venceu (0)\n");
    else printf("Area: Empate\n");

    /* PIB (maior vence) */
    if (pib1 > pib2) printf("PIB: Carta 1 venceu (1)\n");
    else if (pib2 > pib1) printf("PIB: Carta 2 venceu (0)\n");
    else printf("PIB: Empate\n");

    /* Pontos Turísticos (maior vence) */
    if (pontos1 > pontos2) printf("Pontos Turisticos: Carta 1 venceu (1)\n");
    else if (pontos2 > pontos1) printf("Pontos Turisticos: Carta 2 venceu (0)\n");
    else printf("Pontos Turisticos: Empate\n");

    /* Densidade (menor vence) */
    if (densidade1 < densidade2) printf("Densidade Populacional: Carta 1 venceu (1)\n");
    else if (densidade2 < densidade1) printf("Densidade Populacional: Carta 2 venceu (0)\n");
    else printf("Densidade Populacional: Empate\n");

    /* PIB per capita (maior vence) */
    if (pib_per_capita1 > pib_per_capita2) printf("PIB per Capita: Carta 1 venceu (1)\n");
    else if (pib_per_capita2 > pib_per_capita1) printf("PIB per Capita: Carta 2 venceu (0)\n");
    else printf("PIB per Capita: Empate\n");

    /* Super Poder (maior vence) */
    if (super_poder1 > super_poder2) printf("Super Poder: Carta 1 venceu (1)\n");
    else if (super_poder2 > super_poder1) printf("Super Poder: Carta 2 venceu (0)\n");
    else printf("Super Poder: Empate\n");

    return 0;
}
