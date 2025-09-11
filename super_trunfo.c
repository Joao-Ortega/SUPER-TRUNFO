#include <stdio.h>
#include <string.h>
// Função para registro de carta
int registerCard(
		char *state,
		char code[3],
		char cityName[50],
		unsigned long int *population,
		float *area,
		float *pib,
		int *turisticPoints)
{
	printf("Digite seu estado, escolhendo UMA letra de A até H:\n");
	scanf(" %c", state);

	printf("Digite código de sua carta, número de 01 à 04:\n");
	scanf("%s", code);
	// O código acima, após o enter deixa um espaço vazio em Buffer
	// Com isso utilizei o getchar() para 'pegar' esse espaço vazio, sendo possível assim colocar o nome da cidade na próxima linha
	getchar();

	printf("Digite o nome da Cidade:\n");
	fgets(cityName, 50, stdin);
	// Removendo a quebra de linha no final da string
	cityName[strcspn(cityName, "\n")] = 0;

	printf("Digite sua população:\n");
	scanf("%lu", population);

	printf("Digite sua Área (em km²):\n");
	scanf("%f", area);

	printf("Digite seu PIB:\n");
	scanf("%f", pib);

	printf("Quantos pontos turísticos ela possui?:\n");
	scanf("%d", turisticPoints);

	return 0;
}
// Função para cálculo de densidade populacional fazendo casting de unsigned long int para float.
float populationDensityCalculation(unsigned long int *population, float *area)
{
	return (float)*population / *area;
}
// Função para cálculo de PIB per Capita transformando bilhões em unidades de reais par ter o valor em reais por pessoa
float pibPerCapitaCalculation(float *pib, unsigned long int *population)
{
	return (*pib * 1000000000) / (float)*population;
}
// Função para cálculo do super poder
float calculateSuperPower(
		unsigned long int *population,
		float *area,
		float *pib,
		int *turisticPoints,
		float *pibPerCapita,
		float reverseDensity)
{
	return (float)*population + *area + *pib + (float)*turisticPoints + *pibPerCapita + reverseDensity;
}
// Funções de comparação para tipo de dados específicos
int compareUnsignedLongInts(unsigned long int value1, unsigned long int value2)
{
	return value1 > value2;
}

int compareFloats(float value1, float value2)
{
	return value1 > value2;
}

int compareDensities(float value1, float value2)
{
	return value1 < value2;
}
// Funções de comparação para tipo de dados específicos

// Função de retorna o ganhador levando em conta resultado da comparação (sempre carta 1 sobre carta 2)
const char *getResult(int compareResult)
{
	if (compareResult == 1)
	{
		return "Carta 1 venceu";
	}
	return "Carta 2 venceu";
}

int main()
{
	char state1, state2;
	char code1[3], code2[3];
	char cityName1[50], cityName2[50];
	unsigned long int population1, population2;
	float area1, area2;
	float pib1, pib2;
	int turisticPoints1, turisticPoints2;
	float populationDensity1, populationDensity2;
	float pibPerCapita1, pibPerCapita2;
	float superPower1, superPower2;

	printf("CADASTRO DA CARTA 1...\n");

	registerCard(&state1, code1, cityName1, &population1, &area1, &pib1, &turisticPoints1);
	// Cálculo para Densidade populacional e PIB per capita Carta 1
	populationDensity1 = populationDensityCalculation(&population1, &area1);
	pibPerCapita1 = pibPerCapitaCalculation(&pib1, &population1);
	superPower1 = calculateSuperPower(&population1, &area1, &pib1, &turisticPoints1, &pibPerCapita1, (1 / populationDensity1));

	printf("------------CADASTRO DA CARTA 2------------\n");

	registerCard(&state2, code2, cityName2, &population2, &area2, &pib2, &turisticPoints2);
	// Cálculo para Densidade populacional e PIB per capita Carta 2
	populationDensity2 = populationDensityCalculation(&population2, &area2);
	pibPerCapita2 = pibPerCapitaCalculation(&pib2, &population2);
	superPower2 = calculateSuperPower(&population2, &area2, &pib2, &turisticPoints2, &pibPerCapita2, (1 / population2));

	// printf("-----EXIBIÇÃO DAS CARTAS-----\n");

	// printf("Carta 1:\n");
	// printf("Estado: %c\n", state1);
	// printf("Código: %c%s\n", state1, code1);
	// printf("Nome da Cidade: %s\n", cityName1);
	// printf("População: %lu\n", population1);
	// printf("Área: %.2f km²\n", area1);
	// printf("PIB: %.2f bilhões de reais\n", pib1);
	// printf("Número de Pontos Turísticos: %d\n", turisticPoints1);
	// printf("Densidade Populacional: %.2f hab/km²\n", populationDensity1);
	// printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

	// printf("\n");

	// printf("Carta 2:\n");
	// printf("Estado: %c\n", state2);
	// printf("Código: %c%s\n", state2, code2);
	// printf("Nome da Cidade: %s\n", cityName2);
	// printf("População: %lu\n", population2);
	// printf("Área: %.2f km²\n", area2);
	// printf("PIB: %.2f bilhões de reais\n", pib2);
	// printf("Número de Pontos Turísticos: %d\n", turisticPoints2);
	// printf("Densidade Populacional: %.2f hab/km²\n", populationDensity2);
	// printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

	printf("\n");
	printf("-----Resultado do duelo entre as cartas-----\n");
	printf("\n");
	// Declaração de variáveis para serem alteradas mais na frente
	const char *populationResult;
	const char *areaResult;
	const char *pibResult;
	const char *turisticPointsResult;
	const char *densityResult;
	const char *pibPerCapitaResult;
	const char *superPowerResult;

	populationResult = getResult(compareUnsignedLongInts(population1, population2));
	areaResult = getResult(compareFloats(area1, area2));
	pibResult = getResult(compareFloats(pib1, pib2));
	turisticPointsResult = getResult(compareFloats((float)turisticPoints1, (float)turisticPoints2));
	densityResult = getResult(compareDensities(populationDensity1, populationDensity2));
	pibPerCapitaResult = getResult(compareFloats(pibPerCapita1, pibPerCapita2));
	superPowerResult = getResult(compareFloats(superPower1, superPower2));

	printf("População: %s (%d)\n", populationResult, compareUnsignedLongInts(population1, population2));
	printf("Área: %s (%d)\n", areaResult, compareFloats(area1, area2));
	printf("PIB: %s (%d)\n", pibResult, compareFloats(pib1, pib2));
	printf("Pontos Turísticos: %s (%d)\n", turisticPointsResult, compareFloats((float)turisticPoints1, (float)turisticPoints2));
	printf("Densidade Populacional: %s (%d)\n", densityResult, compareDensities(populationDensity1, populationDensity2));
	printf("PIB per Capita: %s (%d)\n", pibPerCapitaResult, compareFloats(pibPerCapita1, pibPerCapita2));
	printf("Super Poder: %s (%d)\n", superPowerResult, compareFloats(superPower1, superPower2));

	printf("\n");
	int option;
	printf("Agora é com você! Qual atributo deseja comparar?\n");
	printf("1 - População\n");
	printf("2 - Área\n");
	printf("3 - PIB\n");
	printf("4 - Número de Pontos Turísticos\n");
	printf("5 - Densidade Populacional\n");
	printf("6 - PIB per Capita\n");
	printf("Escolha um número do menu acima\n");
	scanf("%d", &option);

	printf("\n");

	switch (option)
	{
	case 1:
		printf("Carta 1 %s X Carta 2 %s\n", cityName1, cityName2);
		printf("Comparação de População\n");
		printf("%s - %lu habitantes X %s - %lu habitantes\n", cityName1, population1, cityName2, population2);
		if (compareUnsignedLongInts(population1, population2)) {
			printf("Carta 1 VENCEU!");
		}
		else if (compareUnsignedLongInts(population2, population1)) {
			printf("Carta 2 VENCEU!");
		}
		else {
			printf("Empate!");
		}
		break;
	case 2:
		printf("Carta 1 %s X Carta 2 %s\n", cityName1, cityName2);
		printf("Comparação de Área\n");
		printf("%s - %.2f km² X %s - %.2f km²\n", cityName1, area1, cityName2, area2);
		if (compareFloats(area1, area2)) {
			printf("Carta 1 VENCEU!");
		}
		else if (compareFloats(area2, area1)) {
			printf("Carta 2 VENCEU!");
		}
		else {
			printf("Empate!");
		}
		break;
	case 3:
		printf("Carta 1 %s X Carta 2 %s\n", cityName1, cityName2);
		printf("Comparação de PIB\n");
		printf("%s - %.2f bilhões de reais X %s - %.2f bilhões de reais\n", cityName1, pib1, cityName2, pib2);
		if (compareFloats(pib1, pib2)) {
			printf("Carta 1 VENCEU!");
		}
		else if (compareFloats(pib2, pib1)) {
			printf("Carta 2 VENCEU!");
		}
		else {
			printf("Empate!");
		}
		break;
	case 4:
		printf("Carta 1 %s X Carta 2 %s\n", cityName1, cityName2);
		printf("Comparação de Pontos Turísticos\n");
		printf("%s - %d X %s - %d\n", cityName1, turisticPoints1, cityName2, turisticPoints2);
		if (compareFloats((float) turisticPoints1, (float) turisticPoints2)) {
			printf("Carta 1 VENCEU!");
		}
		else if (compareFloats((float) turisticPoints2, (float) turisticPoints1)) {
			printf("Carta 2 VENCEU!");
		}
		else {
			printf("Empate!");
		}
		break;
	case 5:
		printf("Carta 1 %s X Carta 2 %s\n", cityName1, cityName2);
		printf("Comparação de Densidade Populacional\n");
		printf("%s - %.2f hab/km² X %s - %.2f hab/km²\n", cityName1, populationDensity1, cityName2, populationDensity2);
		if (!compareFloats(populationDensity1, populationDensity2)) {
			printf("Carta 1 VENCEU!");
		}
		else if (!compareFloats(populationDensity2, populationDensity1)) {
			printf("Carta 2 VENCEU!");
		}
		else {
			printf("Empate!");
		}
		break;
	case 6:
		printf("Carta 1 %s X Carta 2 %s\n", cityName1, cityName2);
		printf("Comparação de PIB per Capita\n");
		printf("%s - %.2f reais X %s - %.2f reais\n", cityName1, pibPerCapita1, cityName2, pibPerCapita2);
		if (compareFloats(pibPerCapita1, pibPerCapita2)) {
			printf("Carta 1 VENCEU!");
		}
		else if (compareFloats(pibPerCapita2, pibPerCapita1)) {
			printf("Carta 2 VENCEU!");
		}
		else {
			printf("Empate!");
		}
		break;
	default:
		printf("Opção inválida, por favor digite um dos números existentes no menu!");
		break;
	}
}