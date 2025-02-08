#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    inicio: {
        setlocale(LC_ALL, "Portuguese");
        char estado1[15], codigo_carta1[4], nome_cidade1[15];
        char confirmar1;
        int populacao1, numero_turisticos1;
        float area1, pib1;

        char estado2[15], codigo_carta2[4], nome_cidade2[15];
        char confirmar2;
        int populacao2, numero_turisticos2;
        float area2, pib2;
    
        printf("Seja bem vindo ao comparador de cartas de supertrunfo! \n");
        printf("Primeiramente iremos coletar as informações da primeira carta: \n");

        carta1: {
            system("cls");

            printf("insira o codigo da carta. \n");
            scanf(" %s", codigo_carta1);

            printf("insira o estado da carta. \n");
            scanf(" %s", estado1);

            printf("Por favor insira o nome da cidade.\n");
            scanf(" %s", nome_cidade1);

            printf("Por favor insira a população da carta. \n");
            scanf(" %d", &populacao1);

            printf("Por favor insira a area da carta em Km quadrados. \n");
            scanf(" %f", &area1);

            printf("Por favor insira o PIB da carta. \n");
            scanf(" %f", &pib1);

            printf("Por favor insira a quantidade de numeros turisticos da carta.");
            scanf(" %d", &numero_turisticos1);
        }

        system("cls");

        printf("As informações da primeira carta são:\n \n");
        printf("  O codigo da carta é: %s \n", codigo_carta1);
        printf("  O estado da carta é: %s \n", estado1);
        printf("  O nome da cidade na carta é: %s \n", nome_cidade1);
        printf("  A população registrada na carta é: %d \n", populacao1);
        printf("  A area registrada na carta é: %.2f \n", area1);
        printf("  O PIB registrado na carta é: %.2f \n", pib1);
        printf("  A quantidade de pontos turisticos escritos na carta são: %d \n\n", numero_turisticos1);
        printf("As informações estão corretas? \n");
        printf("Se sim digit S ou s, caso contrario digite n \n");
        scanf(" %c", &confirmar1);

        if (confirmar1 == 's' || confirmar1 == 'S') {
            goto carta2;
        } else {
            goto carta1;
        }

        carta2: {
            system("cls");

            printf("insira o codigo da carta. \n");
            scanf(" %s", codigo_carta1);

            printf("insira o estado da carta. \n");
            scanf(" %s", estado2);

            printf("Por favor insira o nome da cidade.\n");
            scanf(" %s", nome_cidade2);

            printf("Por favor insira a população da carta. \n");
            scanf(" %d", &populacao2);

            printf("Por favor insira a area da carta em Km quadrados. \n");
            scanf(" %f", &area2);

            printf("Por favor insira o PIB da carta. \n");
            scanf(" %f", &pib2);

            printf("Por favor insira a quantidade de numeros turisticos da carta.");
            scanf(" %d", &numero_turisticos2);
        }

        system("cls");

        printf("As informações da primeira carta são:\n \n");
        printf("  O codigo da carta é: %s \n", codigo_carta2);
        printf("  O estado da carta é: %s \n", estado2);
        printf("  O nome da cidade na carta é: %s \n", nome_cidade2);
        printf("  A população registrada na carta é: %d \n", populacao2);
        printf("  A area registrada na carta é: %.2f \n", area2);
        printf("  O PIB registrado na carta é: %.2f \n", pib2);
        printf("  A quantidade de pontos turisticos escritos na carta são: %d \n\n", numero_turisticos2);
        printf("As informações estão corretas? \n");
        printf("Se sim digit S ou s, caso contrario digite n \n");
        scanf(" %c", &confirmar2);

        if (confirmar2 == 's' || confirmar2 == 'S') {
            return 0;
        } else {
            goto carta2;
        }
    }
}
