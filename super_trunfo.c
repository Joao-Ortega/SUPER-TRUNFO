#include <stdio.h>
#include <string.h>
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

int chooseAttribute(int *variable) {
	printf("1 - População\n");
	printf("2 - Área\n");
	printf("3 - PIB\n");
	printf("4 - Número de Pontos Turísticos\n");
	printf("5 - Densidade Populacional\n");
	printf("6 - PIB per Capita\n");
	scanf("%d", variable);
}

int checkIfIsValid(int value) {
	return value >= 1 && value <=6;
}

int main()
{
	char state1 = 'A', state2 = 'B';
	char code1[3] = "A01", code2[3] = "A02";
	char cityName1[50] = "São Paulo", cityName2[50] = "Rio de Janeiro";
	unsigned long int population1 = 12325000, population2 = 6748000;
	float area1 = 1521.11, area2 = 1200.25;
	float pib1 = 699.28, pib2 = 300.50;
	int turisticPoints1 = 50, turisticPoints2 = 30;
	float populationDensity1 = 8102.47, populationDensity2 = 5622.24;
	float pibPerCapita1 = 56724.32, pibPerCapita2 = 44532.91;

	printf("\n");
	int attributeOne;
	int attributeTwo;
	int invalidOption = 1;
	float sumOfAttributes1;
	float sumOfAttributes2;
	printf("Agora é com você! Você irá escolher 2 atributos para comparação!\n");
	printf("Escolha o primeiro atributo:\n");
	chooseAttribute(&attributeOne);

	printf("\n");
	printf("Escolha o segundo atributo:\n");
	chooseAttribute(&attributeTwo);

	invalidOption = !(checkIfIsValid(attributeOne) && checkIfIsValid(attributeTwo));

	while (attributeTwo == attributeOne || invalidOption)
	{
		if (invalidOption) {
			printf("OPÇÃO INVÁLIDA DIGITE UM NÚMERO REFERENTE AO ATRIBUTO EXISTENTE\n");
			printf("Escolha o primeiro atributo:\n");
			chooseAttribute(&attributeOne);
			printf("Escolha o segundo atributo:\n");
			chooseAttribute(&attributeTwo);
			invalidOption = !(checkIfIsValid(attributeOne) && checkIfIsValid(attributeTwo));
		} else {
			printf("ESTE ATRIBUTO JÁ FOI ESCOLHIDO, POR FAVOR DIGITE OUTRO!\n");
			chooseAttribute(&attributeTwo);
			invalidOption = !checkIfIsValid(attributeTwo);
		}
	}

	printf("\n");
	printf("Duelo - %s X %s\n", cityName1, cityName2);

	switch (attributeOne)
	{
	case 1:
		printf("Atributo 1: População\n");
		printf("%s - %lu habitantes X %s - %lu habitantes\n", cityName1, population1, cityName2, population2);
		if (compareUnsignedLongInts(population1, population2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareUnsignedLongInts(population2, population1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)population1;
		sumOfAttributes2 += (float)population2;
		break;
	case 2:
		printf("Atributo 1: Área\n");
		printf("%s - %.2f km² X %s - %.2f km²\n", cityName1, area1, cityName2, area2);
		if (compareFloats(area1, area2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareFloats(area2, area1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)area1;
		sumOfAttributes2 += (float)area2;
		break;
	case 3:
		printf("Atributo 1: PIB\n");
		printf("%s - %.2f bilhões de reais X %s - %.2f bilhões de reais\n", cityName1, pib1, cityName2, pib2);
		if (compareFloats(pib1, pib2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareFloats(pib2, pib1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)pib1;
		sumOfAttributes2 += (float)pib2;
		break;
	case 4:
		printf("Atributo 1: Pontos Turísticos\n");
		printf("%s - %d X %s - %d\n", cityName1, turisticPoints1, cityName2, turisticPoints2);
		if (compareFloats((float) turisticPoints1, (float) turisticPoints2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareFloats((float) turisticPoints2, (float) turisticPoints1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)turisticPoints1;
		sumOfAttributes2 += (float)turisticPoints2;
		break;
	case 5:
		printf("Atributo 1: Densidade Populacional\n");
		printf("%s - %.2f hab/km² X %s - %.2f hab/km²\n", cityName1, populationDensity1, cityName2, populationDensity2);
		if (!compareFloats(populationDensity1, populationDensity2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (!compareFloats(populationDensity2, populationDensity1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)populationDensity1;
		sumOfAttributes2 += (float)populationDensity2;
		break;
	case 6:
		printf("Atributo 1: PIB per Capita\n");
		printf("%s - %.2f reais X %s - %.2f reais\n", cityName1, pibPerCapita1, cityName2, pibPerCapita2);
		if (compareFloats(pibPerCapita1, pibPerCapita2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareFloats(pibPerCapita2, pibPerCapita1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)pibPerCapita1;
		sumOfAttributes2 += (float)pibPerCapita2;
		break;
	default:
		printf("Error!");
		break;
	}

	switch (attributeTwo)
	{
	case 1:
		printf("Atributo 2: População\n");
		printf("%s - %lu habitantes X %s - %lu habitantes\n", cityName1, population1, cityName2, population2);
		if (compareUnsignedLongInts(population1, population2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareUnsignedLongInts(population2, population1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)population1;
		sumOfAttributes2 += (float)population2;
		break;
	case 2:
		printf("Atributo 2: Área\n");
		printf("%s - %.2f km² X %s - %.2f km²\n", cityName1, area1, cityName2, area2);
		if (compareFloats(area1, area2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareFloats(area2, area1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)area1;
		sumOfAttributes2 += (float)area2;
		break;
	case 3:
		printf("Atributo 2: PIB\n");
		printf("%s - %.2f bilhões de reais X %s - %.2f bilhões de reais\n", cityName1, pib1, cityName2, pib2);
		if (compareFloats(pib1, pib2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareFloats(pib2, pib1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)pib1;
		sumOfAttributes2 += (float)pib2;
		break;
	case 4:
		printf("Atributo 2: Pontos Turísticos\n");
		printf("%s - %d X %s - %d\n", cityName1, turisticPoints1, cityName2, turisticPoints2);
		if (compareFloats((float) turisticPoints1, (float) turisticPoints2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareFloats((float) turisticPoints2, (float) turisticPoints1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)turisticPoints1;
		sumOfAttributes2 += (float)turisticPoints2;
		break;
	case 5:
		printf("Atributo 2: Densidade Populacional\n");
		printf("%s - %.2f hab/km² X %s - %.2f hab/km²\n", cityName1, populationDensity1, cityName2, populationDensity2);
		if (!compareFloats(populationDensity1, populationDensity2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (!compareFloats(populationDensity2, populationDensity1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)populationDensity1;
		sumOfAttributes2 += (float)populationDensity2;
		break;
	case 6:
		printf("Atributo 2: PIB per Capita\n");
		printf("%s - %.2f reais X %s - %.2f reais\n", cityName1, pibPerCapita1, cityName2, pibPerCapita2);
		if (compareFloats(pibPerCapita1, pibPerCapita2)) {
			printf("%s VENCEU!\n", cityName1);
		}
		else if (compareFloats(pibPerCapita2, pibPerCapita1)) {
			printf("%s VENCEU!\n", cityName2);
		}
		else {
			printf("Empate!");
		}
		sumOfAttributes1 += (float)pibPerCapita1;
		sumOfAttributes2 += (float)pibPerCapita2;
		break;
	default:
		printf("Error!");
		break;
	}

	printf("------------------------------------\n");
	printf("Resultado das somas dos atributos de cada carta\n");
	printf("%s TOTAL: %.2f\n", cityName1, sumOfAttributes1);
	printf("%s TOTAL: %.2f\n", cityName2, sumOfAttributes2);

	if (sumOfAttributes1 > sumOfAttributes2) {
		printf("%s VENCEU!\n", cityName1);
	} else if (sumOfAttributes2 > sumOfAttributes1) {
		printf("%s VENCEU!\n", cityName2);
	} else {
		printf("EMPATOU!\n");
		printf("%s TOTAL = %.2f ----- %s TOTAL: %.2f\n", cityName1, sumOfAttributes1, cityName2, sumOfAttributes2);
	}
}