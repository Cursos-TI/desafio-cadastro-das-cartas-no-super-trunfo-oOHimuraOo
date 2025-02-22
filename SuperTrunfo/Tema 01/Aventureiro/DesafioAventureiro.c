//Importação de bibliotecas essenciais para o funcionamento do codigo.
//A biblioteca stdio.h é uma biblioteca essencial para permitir comandos de entrada e saida de informações.
//a biblioteca locale.h é uma biblioteca responsavel por permitir a opção de localização idiomatica.
//a biblioteca stdlib.h é uma biblioteca responsavel por permitir a utilização de comandos basicos de console.
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    //Uma chamada de função especifica da biblioteca locale.h que é responsavel por permitir caracteres especiais do idioma português.
    setlocale(LC_ALL,"Portuguese");
    
    //Declaração de variaveis que vão ser utilizadas durante a execução do programa para armazenar inputs do usuario.
    char Estado1, Estado2, CodigoCarta1[4], CodigoCarta2[4], NomeCidade1[20], NomeCidade2[20];
    int Populacao1, Populacao2, NumeroTuristico1, NumeroTuristico2, billion = 1000000000;
    float Area1, Area2, PIB1, PIB2, Densidade1, Densidade2, PIBPC1, PIBPC2;

    printf("** SUPER TRUNFO CIDADES DO MUNDO **\n\n");
    
    printf("Por favor digite as informações relacionadas a carta 1:\n \n");
    
    //coleta de informações:
    printf("Qual o estado da carta? ex: A \n");
    scanf(" %c", &Estado1);

    printf("\nQual o codigo da carta? ex: A01\n");
    scanf("%s", CodigoCarta1);

    printf("\nQual o nome da cidade? ex: Sao_Paulo\n");
    scanf("%s", NomeCidade1);

    printf("\nQual a população? Ex: 12325000\n");
    scanf("%d", &Populacao1);

    printf("\nQual a área em km quadrados? ex: 1521.11\n");
    printf("ATENÇÃO: NÃO UTILIZE ','(vírgula) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
    scanf("%f", &Area1);

    printf("\nQual o PIB em bilhões de reais? ex: 699.28\n");
    printf("ATENÇÃO: NÃO UTILIZE ','(vírgula) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
    scanf("%f", &PIB1);

    printf("\nQuantos pontos turísticos existem? ex: 50\n");
    scanf("%d", &NumeroTuristico1);

    //calculando desidade populacional e pib per capta da carta 1:
    Densidade1 = (float) Populacao1 / Area1;
    PIBPC1 =  (float) (PIB1 * billion) /  Populacao1;

    //limpando o feed do console, para deixar ele funcional. Em sistme linux o comando é clear, em windows cls
    system("clear");

    printf("** SUPER TRUNFO CIDADES DO MUNDO **\n\n");

    printf("Por favor digite as informações relacionadas a carta 2:\n \n");
        
    printf("Qual o estado da carta? ex: A \n");
    scanf(" %c", &Estado2);

    printf("\nQual o codigo da carta? ex: A01\n");
    scanf("%s", CodigoCarta2);

    printf("\nQual o nome da cidade? ex: Sao_Paulo\n");
    scanf("%s", NomeCidade2);

    printf("\nQual a população? Ex: 12325000\n");
    scanf("%d", &Populacao2);

    printf("\nQual a área em km quadrados? ex: 1521.11\n");
    printf("ATENÇÃO: NÃO UTILIZE ','(vírgula) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
    scanf("%f", &Area2);

    printf("\nQual o PIB em bilhões de reais? ex: 699.28\n");
    printf("ATENÇÃO: NÃO UTILIZE ','(vírgula) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
    scanf("%f", &PIB2);

    printf("\nQuantos pontos turísticos existem? ex: 50\n");
    scanf("%d", &NumeroTuristico2);

    //calculando a densidade populacional e o pib per capta da carta 2:
    Densidade2 = (float) Populacao2 / Area2;
    PIBPC2 = (float) (PIB2 * billion) / Populacao2;

    system("clear");

    printf("** SUPER TRUNFO CIDADES DO MUNDO **\n\n");

    //exibição de informações coletadas de maneira completa.
    printf("Informações da carta 1:\n\n");
    printf("1) Estado: %c \n", Estado1);
    printf("2) Código da carta: %s \n", CodigoCarta1);
    printf("3) Nome da cidade: %s \n", NomeCidade1);
    printf("4) População: %d \n", Populacao1);
    printf("5) Área: %.2f km²\n", Area1);
    printf("6) PIB: %.2f bilhões de reais\n", PIB1);
    printf("7) Número de pontos turísticos: %d \n", NumeroTuristico1);
    printf("8) Densidade populacional: %.2f hab/km²\n", Densidade1);
    printf("9) PIB per capita: %.2f reais\n\n", PIBPC1);

    printf("Informações da carta 2:\n\n");
    printf("1) Estado: %c \n", Estado2);
    printf("2) Código da carta: %s \n", CodigoCarta2);
    printf("3) Nome da cidade: %s \n", NomeCidade2);
    printf("4) População: %d \n", Populacao2);
    printf("5) Área: %.2f km²\n", Area2);
    printf("6) PIB: %.2f bilhões de reais\n", PIB2);
    printf("7) Número de pontos turísticos: %d \n", NumeroTuristico2);
    printf("8) Densidade populacional: %.2f hab/km²\n", Densidade2);
    printf("9) PIB per capita: %.2f reais\n\n", PIBPC2);

    return 0;
}