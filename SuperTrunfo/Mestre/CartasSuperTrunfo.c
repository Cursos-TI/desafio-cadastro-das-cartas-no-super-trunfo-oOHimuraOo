//Importação de bibliotecas essenciais para o funcionamento do codigo.
//A biblioteca stdio.h é uma biblioteca essencial para permitir comandos de entrada e saida de informações.
//a biblioteca locale.h é uma biblioteca responsavel por permitir a opção de localização idiomatica.
//a biblioteca stdlib.h é uma biblioteca responsavel por permitir a utilização de comandos basicos de console.
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//declaracao da função responsavel por verificar e controlar qual metodo utilizar para pausar o programa dependendo de em qual sistema operacional o programa foi compilado.
void pause_program() {
//#ifdef é um if que verifica uma condição boleana em tempo de compilação. 
#ifdef _WIN32
    //função da biblioteca stdlib.h que é responsavel utilizar o comando pause no console. Exclusivo do windows.
    system("pause");
#else
    printf("Pressione Enter para continuar... \n");
    getchar();
#endif
}

//declaracao da função resposavel por verificar e controlar qual metodo utilizar para limpar o console dependendo de em qual sistema operacional o programa foi compilado.
void clear_console() {
#ifdef _WIN32
    //função da biblioteca stdlib.h que é responsavel por utilizar o comando cls. Exclusivo do windows.
    system("cls");
#else
    //função da biblioteca stdlib.h que é responsavel por utilizar o comando clear. Funciona em MacOs e Linux.
    system("clear");
#endif
}

//função por fazer uma comparação simples e decidir qual foi o jogador vencedor.
//a função recebe três valores, o primeiro valor deve ser sempre referente a carta 1, o segundo valor deve sempre ser referente a carta 2 e o terceiro valor apenas deve ser 1 se estiver sendo comparada a densidade populacional.
int decidir_vencedor(float valor1, float valor2, int densidade) {
    if (densidade == 1) {
        if (valor1 >= valor2) {
            return 2;
        } else {
            return 1;
        }
    } else {
        if (valor1 >= valor2) {
            return 1;
        } else {
            return 2;
        }
    }
}

//função principal do programa, responsavel por coletar todos os inputs e retornar os devidos resultados.
int main() {
    //tag de marcação para indicar um ponto crucial do codigo, que será acessado posteriormente atravez do comando goto.
    inicio: {
        //função da biblioteca locale.h que é responsavel por permitir localização de idioma.
        setlocale(LC_ALL, "Portuguese");

        //declaração das variaveis que serão utilizadas para armazenar as inforamções das cartas.
        char estado1[15], codigo_carta1[4], nome_cidade1[15];
        char confirmar1;
        int populacao1, numero_turisticos1;
        float area1, pib1, densidade1, pibpc1, super_poder1;

        char estado2[15], codigo_carta2[4], nome_cidade2[15];
        char confirmar2;
        int populacao2, numero_turisticos2;
        float area2, pib2, densidade2, pibpc2, super_poder2;

        //variavel de referencia para calculo.
        int bilhao = 1000000000;
        
        //Variaveis de controle
        int aprovado = 0, verif = 0;
        char final;
        
        //primeira chamada de inicialização do programa.
        printf("*** SUPER TRUNFO CIDADES DO MUNDO! ***\n\n");
        printf("Seja bem vindo ao comparador de cartas de supertrunfo! \n");
        pause_program();

        //tag para ser utilizada com o goto que é referente a capitação de informações da carta 1
        carta1: {
            //função responsavel por limpar o console.
            clear_console();

            printf("Insira as informações da carta 1:\n\n");

            //coleta de informaçao do estado:
            es1: {
                printf("Qual o estado da carta? ex: A \n");
                scanf(" %s", estado1);
                
                //verifica qual o proximo ponto de destino, se verif for 0 vai para a proxima etapa, ou pode ir para etapa de confirmarção de informações.
                if (verif == 0) {
                    goto co1;
                } else if (verif == 2) {
                    goto confirmador1;
                }
            }
            
            //coleta de informaçao do codigo:
            co1: {
                printf("\nQual o codigo da carta? ex: A01\n");
                scanf(" %s", codigo_carta1);
                
                //verifica qual o proximo ponto de destino, se verif for 0 vai para a proxima etapa, ou pode ir para etapa de confirmarção de informações.
                if (verif == 0) {
                    goto ci1;
                } else if (verif == 3) {
                    goto confirmador1;
                }
            }

            //coleta de informaçao da cidade:
            ci1:{
                printf("\nQual o nome da cidade? ex: Sao_Paulo\n");
                printf("ATENÇÃO: NÃO UTILIZE caracteres especiais como cê cedilha, assentos, crases e apostrofos. SUBSTITUA os espaços por : '_' \n");
                scanf(" %s", nome_cidade1);

                //verifica qual o proximo ponto de destino, se verif for 0 vai para a proxima etapa, ou pode ir para etapa de confirmarção de informações.
                if (verif == 0) {
                    goto po1;
                } else if (verif == 4) {
                    goto confirmador1;
                }
            }

            //coleta de informaçao da populacao:
            po1:{
                printf("\nQual a população? Ex: 12325000\n");
                scanf(" %d", &populacao1);

                //verifica qual o proximo ponto de destino, se verif for 0 vai para a proxima etapa, ou pode ir para etapa de confirmarção de informações.
                if (verif == 0) {
                    goto ar1;
                } else if (verif == 5) {
                    goto calculo1;
                } else if (verif == 9) {
                    goto ar1;
                } else {
                    goto calculo1;
                }
            }

            //coleta de informaçao da area:
            ar1: {
                printf("\nQual a área em km²? ex: 1521.11\n");
                printf("ATENÇÃO: NÃO UTILIZE ','(vírgula) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
                scanf(" %f", &area1);

                //verifica qual o proximo ponto de destino, se verif for 0 vai para a proxima etapa, ou pode ir para etapa de confirmarção de informações.
                if (verif == 0) {
                    goto pb1;
                } else if (verif == 6) {
                    goto calculo1;
                } else if (verif == 9) {
                    goto calculo1;
                }
            }

            //coleta de informaçao do pib:
            pb1: {
                printf("\nQual o PIB em bilhões de reais? ex: 699.28\n");
                printf("ATENÇÃO: NÃO UTILIZE ','(vírgula) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
                scanf(" %f", &pib1);

                //verifica qual o proximo ponto de destino, se verif for 0 vai para a proxima etapa, ou pode ir para etapa de confirmarção de informações.
                if (verif == 0) {
                    goto nu1;
                } else if (verif == 7) {
                    goto calculo1;
                } else if (verif == 10) {
                    goto po1;
                }
            }

            //coleta de informaçao de pontos turisticos:
            nu1: {
                printf("\nQuantos pontos turísticos existem? ex: 50\n");
                scanf(" %d", &numero_turisticos1);

                //verifica qual o proximo ponto de destino, se verif for 0 vai para a proxima etapa, ou pode ir para etapa de confirmarção de informações.
                if (verif == 0) {
                    goto calculo1;
                } else if (verif == 8) {
                    goto confirmador1;
                }
            }
            
            //Calculo dos valores de densidade populacional, pib per capta, super poder
            calculo1: {
                densidade1 = (float) populacao1 / area1;
                pibpc1 = (float) (pib1 * bilhao) / populacao1;
                super_poder1 = (float) populacao1 + area1 + (pib1 * bilhao) + pibpc1 + (-densidade1);
                goto confirmador1;
            }
            
            //confirma se as informações foram inseridas adequadamente.
            confirmador1:{
                //função responsavel por limpar o console.
                clear_console();

                printf("As informações da primeira carta são:\n \n");
                printf("  1) estado: %s \n", estado1);
                printf("  2) codigo da carta: %s \n", codigo_carta1);
                printf("  3) nome da cidade: %s \n", nome_cidade1);
                printf("  4) população: %d \n", populacao1);
                printf("  5) área: %.2f km² \n", area1);
                printf("  6) PIB: %.2f bilhões \n", pib1);
                printf("  7) pontos turisticos: %d \n", numero_turisticos1);
                printf("  8) densidade populacional: %.2f hab/km² \n", densidade1);
                printf("  9) PIB per capta: %.2f reais \n", pibpc1);
                printf("  10) Super Poder: %.2f \n\n", super_poder1);
                printf("As informações estão corretas? \n");
                printf("Se sim digit S ou s, caso contrario digite n \n");
                scanf(" %c", &confirmar1);
        
                if (confirmar1 == 's' || confirmar1 == 'S') {
                    aprovado++;
                    goto carta2;
                } else {
                    goto verificador;
                }
            }
        }

        carta2: {
            //função responsavel por limpar o console
            clear_console();

            printf("Insira as informações da carta 2:\n\n");
            
            //coleta de informaçao do estado:
            es2: {
                printf("Qual o estado da carta? ex: A \n");
                scanf(" %s", estado2);

                if (verif == 0) {
                    goto co2;
                } else if (verif == 2) {
                    goto confirmador2;
                }
            }

            //coleta de informaçao do codigo da carta:
            co2:{
                printf("\nQual o codigo da carta? ex: A01\n");
                scanf(" %s", codigo_carta2);

                if (verif == 0) {
                    goto ci2;
                } else if (verif == 3) {
                    goto confirmador2;
                }
            }

            //coleta de informaçao do nome da cidade:
            ci2: {
                printf("\nQual o nome da cidade? ex: Sao_Paulo\n");
                printf("ATENÇÃO: NÃO UTILIZE caracteres especiais como cê cedilha, assentos, crases e apostrofos. SUBSTITUA os espaços por : '_' \n");
                scanf(" %s", nome_cidade2);

                if (verif == 0) {
                    goto po2;
                } else if (verif == 4) {
                    goto confirmador2;
                }
            }

            //coleta de informaçao da população:
            po2: {
                printf("\nQual a população? Ex: 12325000\n");
                scanf(" %d", &populacao2);

                if (verif == 0) {
                    goto ar2;
                } else if (verif == 5) {
                    goto calculo2;
                } else if (verif == 9) {
                    goto ar2;
                } else {
                    goto calculo2;
                }
            }

            //coleta de informaçao da area:
            ar2: {
                printf("\nQual a área em km²? ex: 1521.11\n");
                printf("ATENÇÃO: NÃO UTILIZE ','(vírgula) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
                scanf(" %f", &area2);

                if (verif == 0) {
                    goto pb2;
                } else if (verif == 6) {
                    goto calculo2;
                } else if (verif == 9) {
                    goto calculo2;
                }
            }

            //coleta de informaçao do pib:
            pb2: {
                printf("\nQual o PIB em bilhões de reais? ex: 699.28\n");
                printf("ATENÇÃO: NÃO UTILIZE ','(vírgula) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
                scanf(" %f", &pib2);

                if (verif == 0) {
                    goto nu2;
                } else if (verif == 7) {
                    goto calculo2;
                } else if (verif == 10) {
                    goto po2;
                }
            }

            //coleta de informaçao dos pontos turisticos:
            nu2: {
                printf("\nQuantos pontos turísticos existem? ex: 50\n");
                scanf(" %d", &numero_turisticos2);

                if (verif == 0) {
                    goto calculo2;
                } else if (verif == 2) {
                    goto confirmador2;
                }
            }

            //Calculo dos valores de densidade populacional, pib per capta, super poder
            calculo2: {
                densidade2 = (float) populacao2 / area2;
                pibpc2 = (float) (pib2 * bilhao) / populacao2;
                super_poder2 = (float) populacao2 + area2 + (pib2 * bilhao) + pibpc2 + (-densidade2);
                goto confirmador2;
            }

            //confirma se as informações foram inseridas adequadamente
            confirmador2: {
                //função responsavel por limpar o console.
                clear_console();

                printf("As informações da segunda carta são:\n \n");
                printf("  1) estado: %s \n", estado2);
                printf("  2) codigo da carta: %s \n", codigo_carta2);
                printf("  3) nome da cidade: %s \n", nome_cidade2);
                printf("  4) população: %d \n", populacao2);
                printf("  5) área: %.2f km² \n", area2);
                printf("  6) PIB: %.2f bilhões \n", pib2);
                printf("  7) pontos turisticos: %d \n", numero_turisticos2);
                printf("  8) densidade populacional: %.2f hab/km² \n", densidade2);
                printf("  9) PIB per capta: %.2f reais\n", pibpc2);
                printf("  10) Super Poder: %.2f \n\n", super_poder2);
                printf("As informações estão corretas? \n");
                printf("Se sim digit S ou s, caso contrario digite n \n");
                scanf(" %c", &confirmar2);
        
                if (confirmar2 == 's' || confirmar2 == 'S') {
                    aprovado++;
                    goto finalizacao;
                } else {
                    goto verificador;
                }
            }
        }

        //se tiver tido algum erro na confirmação de informação o usuario poderá escolher qual input modificar e refazer apenas ele.
        verificador: {
            //função responsavel por limpar o console.
            clear_console();

            //zera o verif para garantir o resultado esperado.
            verif = 0;

            //verifica se está lidando com os inputs da carta 1 ou da carta 2
            if (aprovado == 0) {
                printf("Para corrigir alguma informação da primeira carta,\npor favor digite o numero que represente a opção desejada:\n\n");
                printf("  1) Todas\n");
                printf("  2) Estado\n");
                printf("  3) Codigo da carta\n");
                printf("  4) Nome da cidade");
                printf("  5) populacao\n");
                printf("  6) Área\n");
                printf("  7) PIB\n");
                printf("  8) Pontos Turísticos\n");
                printf("  9) Densidade populacional\n");
                printf("  10) PIB per capta\n");
                printf("  11) Cancelar;");
                scanf("%d", &verif);

                //direciona o usuario até a etapa adequada referentes a carta 1
                switch (verif)
                {
                case 1:
                    verif = 0;
                    goto carta1;
                case 2:
                    goto es1;
                case 3:
                    goto co1;
                case 4:
                    goto ci1;
                case 5:
                    goto po1;
                case 6:
                    goto ar1;
                case 7:
                    goto pb1;
                case 8:
                    goto nu1;
                case 9:
                    goto po1;
                case 10:
                    goto pb1;
                default:
                    goto confirmador1;
                }
            } else if (verif == 1) {
                printf("Para corrigir alguma informação da segunda carta,\npor favor digite o numero que represente a opção desejada:\n\n");
                printf("  1) Todas\n");
                printf("  2) Estado\n");
                printf("  3) Codigo da carta\n");
                printf("  4) Nome da cidade");
                printf("  5) populacao\n");
                printf("  6) Área\n");
                printf("  7) PIB\n");
                printf("  8) Pontos Turísticos\n");
                printf("  9) Densidade populacional\n");
                printf("  10) PIB per capta\n");
                printf("  11) Cancelar;");
                scanf("%d", &verif);

                //direciona o usuario até a etapa adequada referentes a carta 1
                switch (verif)
                {
                case 1:
                    goto carta2;
                case 2:
                    goto es2;
                case 3:
                    goto co2;
                case 4:
                    goto ci2;
                case 5:
                    goto po2;
                case 6:
                    goto ar2;
                case 7:
                    goto pb2;
                case 8:
                    goto nu2;
                case 9:
                    goto po2;
                case 10:
                    goto pb2;
                default:
                    goto confirmador2;
                }
            } else {
                goto finalizacao;
            }
        }

        //Responsavel por executar as etapas finais do programa, tais como comparação, entrega de resultados e reinicialização ou finalização.
        finalizacao: {
            //função responsavel por limpar o console.
            clear_console();

            //variaveis contendo 1 ou 2 como valor simbolizando qual foi a carta que venceu.
            int vencedor_populacao = decidir_vencedor((float) populacao1, (float) populacao2, 0);
            int vencedor_area = decidir_vencedor(area1, area2, 0);
            int vencedor_pib = decidir_vencedor(pib1, pib2, 0);
            int vencedor_turistico = decidir_vencedor((float) numero_turisticos1, (float) numero_turisticos2, 0);
            int vencedor_densidade = decidir_vencedor(densidade1, densidade2, 1);
            int vencedor_pibpc = decidir_vencedor(pibpc1, pibpc2, 0);
            int vencedor_super = decidir_vencedor(super_poder1, super_poder2, 0);

            printf("*** Resultado Geral ***\n\n");
            printf("Comparaçao das cartas:\n");

            printf("População: A carta %d venceu!\n", vencedor_populacao);
            printf("Área: A carta %d venceu!\n", vencedor_area);
            printf("PIB: A carta %d venceu!\n", vencedor_pib);
            printf("Pontos turísticos: A carta %d venceu!\n", vencedor_turistico);
            printf("Densidade populacional: A carta %d venceu!\n", vencedor_densidade);
            printf("Super poder: A carta %d venceu!\n\n", vencedor_super);

            //verificação final para finalização do programa.
            printf("Deseja comparar outra carta?\n");
            printf("Digite S para confirmar, ou qualquer outra letra para finalizar o programa.\n");
            scanf(" %c", &final);

            if (final == 's' || final == 'S') {
                goto inicio;
            } else {
                return 0;
            }
        }
    }
}
