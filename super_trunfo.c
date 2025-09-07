#include <stdio.h>
#include <string.h>

int main()
{
    char state1, state2;
    char code1[3], code2[3];
    char cityName1[50], cityName2[50];
    int population1, population2;
    float area1, area2;
    float pib1, pib2;
    int turisticPoints1, turisticPoints2;

    printf("CADASTRO DA CARTA 1...\n");
    printf("Digite seu estado, escolhendo UMA letra de A até H:\n");
    scanf("%c", &state1);

    printf("Digite código de sua carta, número de 01 à 04:\n");
    scanf("%s", code1);
    // O código acima, após o enter deixa um espaço vazio em Buffer
    // Com isso utilizei o getchar() para 'pegar' esse espaço vazio, sendo possível assim colocar o nome da cidade na próxima linha
    getchar();

    printf("Digite o nome da Cidade:\n");
    fgets(cityName1, 50, stdin);

    cityName1[strcspn(cityName1, "\n")] = 0;

    printf("Digite sua população:\n");
    scanf("%d", &population1);

    printf("Digite sua Área (em km²):\n");
    scanf("%f", &area1);

    printf("Digite seu PIB:\n");
    scanf("%f", &pib1);

    printf("Quantos pontos turísticos ela possui?:\n");
    scanf("%d", &turisticPoints1);

    printf("\n");

    printf("CADASTRO DA CARTA 2...\n");
    printf("Digite seu estado, escolhendo UMA letra de A até H:\n");
    scanf(" %c", &state2);

    printf("Digite código de sua carta, número de 01 à 04:\n");
    scanf("%s", code2);
    getchar();

    printf("Digite o nome da Cidade:\n");
    fgets(cityName2, 50, stdin);

    cityName2[strcspn(cityName2, "\n")] = 0;

    printf("Digite sua população:\n");
    scanf("%d", &population2);

    printf("Digite sua Área (em km²):\n");
    scanf("%f", &area2);

    printf("Digite seu PIB:\n");
    scanf("%f", &pib2);

    printf("Quantos pontos turísticos ela possui?:\n");
    scanf("%d", &turisticPoints2);

    printf("\n");

    printf("Carta 1:\n");
    printf("Estado: %c\n", state1);
    printf("Código: %c%s\n", state1, code1);
    printf("Nome da Cidade: %s\n",cityName1);
    printf("População: %d\n", population1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", turisticPoints1);
    
    printf("\n");

    printf("Carta 2:\n");
    printf("Estado: %c\n", state2);
    printf("Código: %c%s\n", state2, code2);
    printf("Nome da Cidade: %s\n",cityName2);
    printf("População: %d\n", population2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", turisticPoints2);
}