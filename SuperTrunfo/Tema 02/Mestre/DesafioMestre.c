//Importação de bibliotecas essenciais para o funcionamento do codigo.
//A biblioteca stdio.h é uma biblioteca essencial para permitir comandos de entrada e saida de informações.
//a biblioteca locale.h é uma biblioteca responsavel por permitir a opção de localização idiomatica.
//a biblioteca stdlib.h é uma biblioteca responsavel por permitir a utilização de comandos basicos de console.
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void message_alert_program() {
#if defined(_WIN32) || defined(_WIN64)
    printf("ATENÇÃO: NÃO UTILIZE '.'(PONTO) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
#else
    printf("ATENÇÃO: NÃO UTILIZE ','(VIRGULA) PARA REPRESENTAR NUMEROS DECIMAIS!\n");
#endif
}

//declaracao da função responsavel por verificar e controlar qual metodo utilizar para pausar o programa dependendo de em qual sistema operacional o programa foi compilado.
void pause_program() {
//#ifdef é um if que verifica uma condição boleana em tempo de compilação. 
#if defined(_WIN32) || defined(_WIN64)
    //função da biblioteca stdlib.h que é responsavel utilizar o comando pause no console. Exclusivo do windows.
    system("pause");
#else
    printf("Pressione Enter para continuar... \n");
    getchar();
#endif
}

//declaracao da função resposavel por verificar e controlar qual metodo utilizar para limpar o console dependendo de em qual sistema operacional o programa foi compilado.
void clear_console() {
#if defined(_WIN32) || defined(_WIN64)
    //função da biblioteca stdlib.h que é responsavel por utilizar o comando cls. Exclusivo do windows.
    system("cls");
#else
    //função da biblioteca stdlib.h que é responsavel por utilizar o comando clear. Funciona em MacOs e Linux.
    system("clear");
#endif
}

//função por fazer uma comparação simples e decidir qual foi o jogador vencedor.
//a função recebe três valores, o primeiro valor deve ser sempre referente a carta 1, o segundo valor deve sempre ser referente a carta 2 e o terceiro valor apenas deve ser 1 se estiver sendo comparada a densidade populacional.
int decidir_vencedor(double valor1, double valor2, int densidade) {
    if (densidade == 1) {
        if (valor1 > valor2) {
            return 2;
        } else if (valor1 < valor2) {
            return 1;
        } else {
            return 3;
        }
    } else {
        if (valor1 > valor2) {
            return 1;
        } else if (valor1 < valor2){
            return 2;
        } else {
            return 3;
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
        int numero_turisticos1;
        float area1, pib1;

        long long int populacao1;
        double super_poder1, densidade1, pibpc1;

        char estado2[15], codigo_carta2[4], nome_cidade2[15];
        char confirmar2;
        int numero_turisticos2;
        float area2, pib2;

        long long int populacao2;
        double super_poder2, densidade2, pibpc2;

        //variavel de referencia para calculo.
        long long int bilhao = 1000000000;
        
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
                scanf(" %lld", &populacao1);

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
                //função responsavel por escrever um alerta de comportamento para função baseado no sistema operacional em que o programa foi compilado.
                message_alert_program();
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
                //função responsavel por escrever um alerta de comportamento para função baseado no sistema operacional em que o programa foi compilado.
                message_alert_program();
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
                densidade1 = (double) populacao1 / area1;
                pibpc1 = (double) (pib1 * bilhao) / populacao1;
                super_poder1 = (double) populacao1 + area1 + (pib1 * bilhao) + pibpc1 + (-densidade1);
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
                printf("  4) população: %lld \n", populacao1);
                printf("  5) área: %.2f km² \n", area1);
                printf("  6) PIB: %.2f bilhões \n", pib1);
                printf("  7) pontos turisticos: %d \n", numero_turisticos1);
                printf("  8) densidade demográfica: %.2f hab/km² \n", densidade1);
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
                scanf(" %lld", &populacao2);

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
                //função responsavel por escrever um alerta de comportamento para função baseado no sistema operacional em que o programa foi compilado.
                message_alert_program();
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
                //função responsavel por escrever um alerta de comportamento para função baseado no sistema operacional em que o programa foi compilado.
                message_alert_program();
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
                densidade2 = (double) populacao2 / area2;
                pibpc2 = (double) (pib2 * bilhao) / populacao2;
                super_poder2 = (double) populacao2 + area2 + (pib2 * bilhao) + pibpc2 + (-densidade2);
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
                printf("  4) população: %lld \n", populacao2);
                printf("  5) área: %.2f km² \n", area2);
                printf("  6) PIB: %.2f bilhões \n", pib2);
                printf("  7) pontos turisticos: %d \n", numero_turisticos2);
                printf("  8) densidade demográfica: %.2f hab/km² \n", densidade2);
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
                printf("  4) Nome da cidade\n");
                printf("  5) populacao\n");
                printf("  6) Área\n");
                printf("  7) PIB\n");
                printf("  8) Pontos Turísticos\n");
                printf("  9) Densidade demográfica\n");
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
            } else if (aprovado == 1) {
                printf("Para corrigir alguma informação da segunda carta,\npor favor digite o numero que represente a opção desejada:\n\n");
                printf("  1) Todas\n");
                printf("  2) Estado\n");
                printf("  3) Codigo da carta\n");
                printf("  4) Nome da cidade\n");
                printf("  5) populacao\n");
                printf("  6) Área\n");
                printf("  7) PIB\n");
                printf("  8) Pontos Turísticos\n");
                printf("  9) Densidade demográfica\n");
                printf("  10) PIB per capta\n");
                printf("  11) Cancelar\n");
                scanf("%d", &verif);

                //direciona o usuario até a etapa adequada referentes a carta 1
                switch (verif)
                {
                case 1:
                    verif = 0;
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
            float valor_1a = 0, valor_2a = 0, valor_1b = 0, valor_2b = 0;
            
            //variaveis de verificação para seleção de novas opções
            int verificador_final1 = 0, verificador_final2 = 0;

            //tag que leva até a etapa de seleção final para efetuar a comparação e apresentar resultado.
            selecaoFinal: {
                //função responsavel por limpar o console.
                clear_console();
                
                printf("Selecione duas categorias para dar continuidade\n");
                printf("Por favor informe o numero que equivale a categoria que você deseja comparar:\n");
                printf("  1) População\n");
                printf("  2) Área\n");
                printf("  3) PIB\n");
                printf("  4) Pontos Turísticos\n");
                printf("  5) Densidade demográfica\n");
                printf("  6) PIB per Capta\n");
                printf("  7) Super Poder\n");
                scanf("%d", &verificador_final1);

                //verifica qual foi a primeira opção selecionada e direciona para a seleção da segunda opção.
                switch (verificador_final1)
                {
                case 1:
                    //função responsavel por limpar o console.
                    clear_console();

                    printf("Por favor informe o numero que equivale a categoria que você deseja comparar:\n");
                    printf("  2) Área\n");
                    printf("  3) PIB\n");
                    printf("  4) Pontos Turísticos\n");
                    printf("  5) Densidade demográfica\n");
                    printf("  6) PIB per Capta\n");
                    printf("  7) Super Poder\n");
                    scanf("%d", &verificador_final2);

                    valor_1a = populacao1;
                    valor_1b = populacao2;

                    switch (verificador_final2)
                    {
                    case 2:
                        valor_2a = area1;
                        valor_2b = area2;
                        break;
                    case 3:
                        valor_2a = pib1;
                        valor_2b = pib2;
                        break;
                    case 4:
                        valor_2a = numero_turisticos1;
                        valor_2b = numero_turisticos2;
                        break;
                    case 5:
                        valor_2a = -densidade1;
                        valor_2b = -densidade2;
                        break;
                    case 6:
                        valor_2a = pibpc1;
                        valor_2b = pibpc2;
                        break;
                    case 7:
                        valor_2a = super_poder1;
                        valor_2b = super_poder2;
                        break;
                    default:
                        clear_console();
                        printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                        pause_program();
                        goto selecaoFinal;
                    }
                    break;
                case 2:
                    //função responsavel por limpar o console.
                    clear_console();

                    printf("Por favor informe o numero que equivale a categoria que você deseja comparar:\n");
                    printf("  1) População\n");
                    printf("  3) PIB\n");
                    printf("  4) Pontos Turísticos\n");
                    printf("  5) Densidade demográfica\n");
                    printf("  6) PIB per Capta\n");
                    printf("  7) Super Poder\n");
                    scanf("%d", &verificador_final2);

                    valor_1a = area1;
                    valor_1b = area2;

                    switch (verificador_final2)
                    {
                    case 1:
                        valor_2a = populacao1;
                        valor_2b = populacao2;
                        break;
                    case 3:
                        valor_2a = pib1;
                        valor_2b = pib2;
                        break;
                    case 4:
                        valor_2a = numero_turisticos1;
                        valor_2b = numero_turisticos2;
                        break;
                    case 5:
                        valor_2a = -densidade1;
                        valor_2b = -densidade2;
                        break;
                    case 6:
                        valor_2a = pibpc1;
                        valor_2b = pibpc2;
                        break;
                    case 7:
                        valor_2a = super_poder1;
                        valor_2b = super_poder2;
                        break;
                    default:
                        clear_console();
                        printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                        pause_program();
                        goto selecaoFinal;
                    }
                    
                    break;
                case 3:
                    //função responsavel por limpar o console.
                    clear_console();

                    printf("Por favor informe o numero que equivale a categoria que você deseja comparar:\n");
                    printf("  1) População\n");
                    printf("  2) Área\n");
                    printf("  4) Pontos Turísticos\n");
                    printf("  5) Densidade demográfica\n");
                    printf("  6) PIB per Capta\n");
                    printf("  7) Super Poder\n");
                    scanf("%d", &verificador_final2);

                    valor_1a = pib1;
                    valor_1b = pib2;

                    switch (verificador_final2)
                    {
                    case 1:
                        valor_2a = populacao1;
                        valor_2b = populacao2;
                        break;
                    case 2:
                        valor_2a = area1;
                        valor_2b = area2;
                        break;
                    case 4:
                        valor_2a = numero_turisticos1;
                        valor_2b = numero_turisticos2;
                        break;
                    case 5:
                        valor_2a = -densidade1;
                        valor_2b = -densidade2;
                        break;
                    case 6:
                        valor_2a = pibpc1;
                        valor_2b = pibpc2;
                        break;
                    case 7:
                        valor_2a = super_poder1;
                        valor_2b = super_poder2;
                        break;
                    default:
                        clear_console();
                        printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                        pause_program();
                        goto selecaoFinal;
                    }

                    break;
                case 4:
                    //função responsavel por limpar o console.
                    clear_console();
                    
                    printf("Por favor informe o numero que equivale a categoria que você deseja comparar:\n");
                    printf("  1) População\n");
                    printf("  2) Área\n");
                    printf("  3) PIB\n");
                    printf("  5) Densidade demográfica\n");
                    printf("  6) PIB per Capta\n");
                    printf("  7) Super Poder\n");
                    scanf("%d", &verificador_final2);

                    valor_1a = numero_turisticos1;
                    valor_1b = numero_turisticos2;

                    switch (verificador_final2)
                    {
                    case 1:
                        valor_2a = populacao1;
                        valor_2b = populacao2;
                        break;
                    case 2:
                        valor_2a = area1;
                        valor_2b = area2;
                        break;
                    case 3:
                        valor_2a = pib1;
                        valor_2b = pib2;
                        break;
                    case 5:
                        valor_2a = -densidade1;
                        valor_2b = -densidade2;
                        break;
                    case 6:
                        valor_2a = pibpc1;
                        valor_2b = pibpc2;
                        break;
                    case 7:
                        valor_2a = super_poder1;
                        valor_2b = super_poder2;
                        break;
                    default:
                        clear_console();
                        printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                        pause_program();
                        goto selecaoFinal;
                    }
                    break;
                case 5:
                    //função responsavel por limpar o console.
                    clear_console();

                    printf("Por favor informe o numero que equivale a categoria que você deseja comparar:\n");
                    printf("  1) População\n");
                    printf("  2) Área\n");
                    printf("  3) PIB\n");
                    printf("  4) Pontos Turísticos\n");
                    printf("  6) PIB per Capta\n");
                    printf("  7) Super Poder\n");
                    scanf("%d", &verificador_final2);
                    
                    valor_1a = -densidade1;
                    valor_1b = -densidade2;

                    switch (verificador_final2)
                    {
                    case 1:
                        valor_2a = populacao1;
                        valor_2b = populacao2;
                        break;
                    case 2:
                        valor_2a = area1;
                        valor_2b = area2;
                        break;
                    case 3:
                        valor_2a = pib1;
                        valor_2b = pib2;
                        break;
                    case 4:
                        valor_2a = numero_turisticos1;
                        valor_2b = numero_turisticos2;
                        break;
                    case 6:
                        valor_2a = pibpc1;
                        valor_2b = pibpc2;
                        break;
                    case 7:
                        valor_2a = super_poder1;
                        valor_2b = super_poder2;
                        break;
                    default:
                        clear_console();
                        printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                        pause_program();
                        goto selecaoFinal;
                    }
                    break;
                case 6:
                    //função responsavel por limpar o console.
                    clear_console();

                    printf("Por favor informe o numero que equivale a categoria que você deseja comparar:\n");
                    printf("  1) População\n");
                    printf("  2) Área\n");
                    printf("  3) PIB\n");
                    printf("  4) Pontos Turísticos\n");
                    printf("  5) Densidade demográfica\n");
                    printf("  7) Super Poder\n");
                    scanf("%d", &verificador_final2);
                    
                    valor_1a = pibpc1;
                    valor_1b = pibpc2;

                    switch (verificador_final2)
                    {
                    case 1:
                        valor_2a = populacao1;
                        valor_2b = populacao2;
                        break;
                    case 2:
                        valor_2a = area1;
                        valor_2b = area2;
                        break;
                    case 3:
                        valor_2a = pib1;
                        valor_2b = pib2;
                        break;
                    case 4:
                        valor_2a = numero_turisticos1;
                        valor_2b = numero_turisticos2;
                        break;
                    case 5:
                        valor_2a = -densidade1;
                        valor_2b = -densidade2;
                        break;
                    case 7:
                        valor_2a = super_poder1;
                        valor_2b = super_poder2;
                        break;
                    default:
                        clear_console();
                        printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                        pause_program();
                        goto selecaoFinal;
                    }
                    break;
                case 7:
                    //função responsavel por limpar o console.
                    clear_console();

                    printf("Por favor informe o numero que equivale a categoria que você deseja comparar:\n");
                    printf("  1) População\n");
                    printf("  2) Área\n");
                    printf("  3) PIB\n");
                    printf("  4) Pontos Turísticos\n");
                    printf("  5) Densidade demográfica\n");
                    printf("  6) PIB per Capta\n");
                    scanf("%d", &verificador_final2);
                    
                    valor_1a = super_poder1;
                    valor_1b = super_poder2;
                    
                    switch (verificador_final2)
                    {
                    case 1:
                        valor_2a = populacao1;
                        valor_2b = populacao2;
                        break;
                    case 2:
                        valor_2a = area1;
                        valor_2b = area2;
                        break;
                    case 3:
                        valor_2a = pib1;
                        valor_2b = pib2;
                        break;
                    case 4:
                        valor_2a = numero_turisticos1;
                        valor_2b = numero_turisticos2;
                        break;
                    case 5:
                        valor_2a = densidade1;
                        valor_2b = densidade2;
                        break;
                    case 6:
                        valor_2a = super_poder1;
                        valor_2b = super_poder2;
                        break;
                    default:
                        clear_console();
                        printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                        pause_program();
                        goto selecaoFinal;
                    }
                    break;
                default:
                    clear_console();
                    printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                    pause_program();
                    goto selecaoFinal;
                }

                //variaveis contendo 1 ou 2 como valor simbolizando qual foi a carta que venceu.
                int vencedor_populacao = decidir_vencedor((double) populacao1, (double) populacao2, 0);
                int vencedor_area = decidir_vencedor((double) area1,(double) area2, 0);
                int vencedor_pib = decidir_vencedor((double) pib1,(double) pib2, 0);
                int vencedor_turistico = decidir_vencedor((double) numero_turisticos1, (double) numero_turisticos2, 0);
                int vencedor_densidade = decidir_vencedor((double) densidade1,(double) densidade2, 1);
                int vencedor_pibpc = decidir_vencedor((double) pibpc1,(double) pibpc2, 0);
                int vencedor_super = decidir_vencedor(super_poder1, super_poder2, 0);

                int contador_de_vitorias1 = 0, contador_de_vitorias2 = 0, contador_de_empates = 0;
                
                //função responsavel por limpar o console.
                clear_console();
                printf("*** Resultado Geral ***\n");
                printf("Comparaçao das cartas:\n\n");

                //com base na primeira opção selecionada revela o resultado da primeira rodada.
                switch (verificador_final1)
                {
                case 1:
                    if (vencedor_populacao == 1) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: POPULAÇÃO ***\n\n");
                        printf("Nessa categoria vence quem tem mais habitantes.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %lld habitantes.\n", nome_cidade1, populacao1);
                        printf("A carta 02 (%s) tem %lld habitantes.\n", nome_cidade2, populacao2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!\n", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_populacao == 2){
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: POPULAÇÃO ***\n\n");
                        printf("Nessa categoria vence quem tem mais habitantes.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %lld habitantes.\n", nome_cidade2, populacao2);
                        printf("A carta 01 (%s) tem %lld habitantes.\n", nome_cidade1, populacao1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    }else {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: POPULAÇÃO ***\n\n");
                        printf("Nessa categoria vence quem tem mais habitantes.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %lld habitantes.\n", nome_cidade1, populacao1);
                        printf("A carta 02 (%s) tem %lld habitantes.\n", nome_cidade2, populacao2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 2:
                    if (vencedor_area == 1) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: ÁREA ***\n\n");
                        printf("Nessa categoria vence quem tem mais km².\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2f km².\n", nome_cidade1, area1);
                        printf("A carta 02 (%s) tem %.2f km².\n", nome_cidade2, area2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_area == 2) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: ÁREA ***\n\n");
                        printf("Nessa categoria vence quem tem mais km².\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2f km².\n", nome_cidade2, area2);
                        printf("A carta 01 (%s) tem %.2f km².\n", nome_cidade1, area1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: ÁREA ***\n\n");
                        printf("Nessa categoria vence quem tem mais km².\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2f km².\n", nome_cidade1, area1);
                        printf("A carta 02 (%s) tem %.2f km².\n", nome_cidade2, area2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 3:
                    if (vencedor_pib == 1) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2f bilhões de reais.\n", nome_cidade1, pib1);
                        printf("A carta 02 (%s) tem %.2f bilhões de reais.\n", nome_cidade2, pib2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_pib == 2) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2f bilhões de reais.\n", nome_cidade2, pib2);
                        printf("A carta 01 (%s) tem %.2f bilhões de reais.\n", nome_cidade1, pib1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2f bilhões de reais.\n", nome_cidade1, pib1);
                        printf("A carta 02 (%s) tem %.2f bilhões de reais.\n", nome_cidade2, pib2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 4:
                    if (vencedor_turistico == 1) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PONTOS TURÍSTICOS ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos turísticos.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %d pontos turísticos.\n", nome_cidade1, numero_turisticos1);
                        printf("A carta 02 (%s) tem %d pontos turísticos.\n", nome_cidade2, numero_turisticos2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_turistico == 2) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PONTOS TURÍSTICOS ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos turísticos.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %d pontos turísticos.\n", nome_cidade2, numero_turisticos2);
                        printf("A carta 01 (%s) tem %d pontos turísticos.\n", nome_cidade1, numero_turisticos1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PONTOS TURÍSTICOS ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos turísticos.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %d pontos turísticos.\n", nome_cidade1, numero_turisticos1);
                        printf("A carta 02 (%s) tem %d pontos turísticos.\n", nome_cidade2, numero_turisticos2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 5:
                    if (vencedor_densidade == 1) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: DENSIDADE DEMOGRÁFICA ***\n\n");
                        printf("Nessa categoria vence quem tem menos habitantes por km².\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2f hab/km².\n", nome_cidade1, densidade1);
                        printf("A carta 02 (%s) tem %.2f hab/km².\n", nome_cidade2, densidade2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_densidade == 2){
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: DENSIDADE DEMOGRÁFICA ***\n\n");
                        printf("Nessa categoria vence quem tem menos habitantes por km².\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2f hab/km².\n", nome_cidade2, densidade2);
                        printf("A carta 01 (%s) tem %.2f hab/km².\n", nome_cidade1, densidade1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: DENSIDADE DEMOGRÁFICA ***\n\n");
                        printf("Nessa categoria vence quem tem menos habitantes por km².\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2f hab/km².\n", nome_cidade1, densidade1);
                        printf("A carta 02 (%s) tem %.2f hab/km².\n", nome_cidade2, densidade2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 6:
                    if (vencedor_pibpc == 1) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB PER CAPTA ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro por habitantes.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2f reais por habitante.\n", nome_cidade1, pibpc1);
                        printf("A carta 02 (%s) tem %.2f reais por habitante.\n", nome_cidade2, pibpc2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_pibpc == 2) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB PER CAPTA ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro por habitantes.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2f reais por habitante.\n", nome_cidade2, pibpc2);
                        printf("A carta 01 (%s) tem %.2f reais por habitante.\n", nome_cidade1, pibpc1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB PER CAPTA ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro por habitantes.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2f hab/km².\n", nome_cidade1, pibpc1);
                        printf("A carta 02 (%s) tem %.2f hab/km².\n", nome_cidade2, pibpc2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 7:
                    if (vencedor_super == 1) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: SUPER PODER ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2lf pontos.\n", nome_cidade1, super_poder1);
                        printf("A carta 02 (%s) tem %.2lf pontos.\n", nome_cidade2, super_poder2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_super == 2) {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: SUPER PODER ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2lf pontos.\n", nome_cidade2, super_poder2);
                        printf("A carta 01 (%s) tem %.2lf pontos.\n", nome_cidade1, super_poder1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA PRIMEIRA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: SUPER PODER ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2lf pontos.\n", nome_cidade1, super_poder1);
                        printf("A carta 02 (%s) tem %.2lf pontos.\n", nome_cidade2, super_poder2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                default:
                    clear_console();
                    printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                    pause_program();
                    goto selecaoFinal;
                }

                //função responsavel por pausar o programa.
                pause_program();
                //com base na segunda opção selecionada revela o resultado da segunda rodada.
                switch (verificador_final2)
                {
                case 1:
                    if (vencedor_populacao == 1) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: POPULAÇÃO ***\n\n");
                        printf("Nessa categoria vence quem tem mais habitantes.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %lld habitantes.\n", nome_cidade1, populacao1);
                        printf("A carta 02 (%s) tem %lld habitantes.\n", nome_cidade2, populacao2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!\n", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_populacao == 2){
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: POPULAÇÃO ***\n\n");
                        printf("Nessa categoria vence quem tem mais habitantes.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %lld habitantes.\n", nome_cidade2, populacao2);
                        printf("A carta 01 (%s) tem %lld habitantes.\n", nome_cidade1, populacao1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    }else {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: POPULAÇÃO ***\n\n");
                        printf("Nessa categoria vence quem tem mais habitantes.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %lld habitantes.\n", nome_cidade1, populacao1);
                        printf("A carta 02 (%s) tem %lld habitantes.\n", nome_cidade2, populacao2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 2:
                    if (vencedor_area == 1) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: ÁREA ***\n\n");
                        printf("Nessa categoria vence quem tem mais km².\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2f km².\n", nome_cidade1, area1);
                        printf("A carta 02 (%s) tem %.2f km².\n", nome_cidade2, area2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_area == 2) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: ÁREA ***\n\n");
                        printf("Nessa categoria vence quem tem mais km².\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2f km².\n", nome_cidade2, area2);
                        printf("A carta 01 (%s) tem %.2f km².\n", nome_cidade1, area1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: ÁREA ***\n\n");
                        printf("Nessa categoria vence quem tem mais km².\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2f km².\n", nome_cidade1, area1);
                        printf("A carta 02 (%s) tem %.2f km².\n", nome_cidade2, area2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 3:
                    if (vencedor_pib == 1) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2f bilhões de reais.\n", nome_cidade1, pib1);
                        printf("A carta 02 (%s) tem %.2f bilhões de reais.\n", nome_cidade2, pib2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_pib == 2) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2f bilhões de reais.\n", nome_cidade2, pib2);
                        printf("A carta 01 (%s) tem %.2f bilhões de reais.\n", nome_cidade1, pib1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2f bilhões de reais.\n", nome_cidade1, pib1);
                        printf("A carta 02 (%s) tem %.2f bilhões de reais.\n", nome_cidade2, pib2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 4:
                    if (vencedor_turistico == 1) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PONTOS TURÍSTICOS ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos turísticos.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %d pontos turísticos.\n", nome_cidade1, numero_turisticos1);
                        printf("A carta 02 (%s) tem %d pontos turísticos.\n", nome_cidade2, numero_turisticos2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_turistico == 2) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PONTOS TURÍSTICOS ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos turísticos.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %d pontos turísticos.\n", nome_cidade2, numero_turisticos2);
                        printf("A carta 01 (%s) tem %d pontos turísticos.\n", nome_cidade1, numero_turisticos1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PONTOS TURÍSTICOS ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos turísticos.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %d pontos turísticos.\n", nome_cidade1, numero_turisticos1);
                        printf("A carta 02 (%s) tem %d pontos turísticos.\n", nome_cidade2, numero_turisticos2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 5:
                    if (vencedor_densidade == 1) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: DENSIDADE DEMOGRÁFICA ***\n\n");
                        printf("Nessa categoria vence quem tem menos habitantes por km².\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2f hab/km².\n", nome_cidade1, densidade1);
                        printf("A carta 02 (%s) tem %.2f hab/km².\n", nome_cidade2, densidade2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_densidade == 2){
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: DENSIDADE DEMOGRÁFICA ***\n\n");
                        printf("Nessa categoria vence quem tem menos habitantes por km².\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2f hab/km².\n", nome_cidade2, densidade2);
                        printf("A carta 01 (%s) tem %.2f hab/km².\n", nome_cidade1, densidade1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: DENSIDADE DEMOGRÁFICA ***\n\n");
                        printf("Nessa categoria vence quem tem menos habitantes por km².\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2f hab/km².\n", nome_cidade1, densidade1);
                        printf("A carta 02 (%s) tem %.2f hab/km².\n", nome_cidade2, densidade2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 6:
                    if (vencedor_pibpc == 1) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB PER CAPTA ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro por habitantes.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2f reais por habitante.\n", nome_cidade1, pibpc1);
                        printf("A carta 02 (%s) tem %.2f reais por habitante.\n", nome_cidade2, pibpc2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_pibpc == 2) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB PER CAPTA ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro por habitantes.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2f reais por habitante.\n", nome_cidade2, pibpc2);
                        printf("A carta 01 (%s) tem %.2f reais por habitante.\n", nome_cidade1, pibpc1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: PIB PER CAPTA ***\n\n");
                        printf("Nessa categoria vence quem tem mais dinheiro por habitantes.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2f hab/km².\n", nome_cidade1, pibpc1);
                        printf("A carta 02 (%s) tem %.2f hab/km².\n", nome_cidade2, pibpc2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                case 7:
                    if (vencedor_super == 1) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: SUPER PODER ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos.\n");
                        printf("A carta 01: %s, venceu!\n", nome_cidade1);
                        printf("A carta 01 (%s) tem %.2lf pontos.\n", nome_cidade1, super_poder1);
                        printf("A carta 02 (%s) tem %.2lf pontos.\n", nome_cidade2, super_poder2);
                        printf("Com isso a carta vencedora desta rodada foi a carta 1 (%s)!", nome_cidade1);
                        contador_de_vitorias1++;
                    } else if (vencedor_super == 2) {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: SUPER PODER ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos.\n");
                        printf("A carta 02: %s, venceu!\n", nome_cidade2);
                        printf("A carta 02 (%s) tem %.2lf pontos.\n", nome_cidade2, super_poder2);
                        printf("A carta 01 (%s) tem %.2lf pontos.\n", nome_cidade1, super_poder1);
                        printf("Com isso a carta vencedora desta rodada foi a carta 2 (%s)!", nome_cidade2);
                        contador_de_vitorias2++;
                    } else {
                        printf("*** RESULTADO DA SEGUNDA RODADA *** \n");
                        printf("*** A CATEGORIA SELECIONADA FOI: SUPER PODER ***\n\n");
                        printf("Nessa categoria vence quem tem mais pontos.\n");
                        printf("Houve um empate!\n");
                        printf("A carta 01 (%s) tem %.2lf pontos.\n", nome_cidade1, super_poder1);
                        printf("A carta 02 (%s) tem %.2lf pontos.\n", nome_cidade2, super_poder2);
                        printf("Com isso houve um empate!\n");
                        contador_de_empates++;
                    }
                    break;
                default:
                    clear_console();
                    printf("Houve um erro ao computar os valores, por favor selecione os dois valores novamente.\n");
                    pause_program();
                    goto selecaoFinal;
                }

                //função responsavel por pausar o programa.
                pause_program();
                
                //variaveis de soma dos valores totais obtidos
                double soma1 = (double) valor_1a + valor_2a;
                double soma2 = (double) valor_1b + valor_2b;

                //variavel responsavel por decidir qual foi a carta vencedora. Se a função retornar 1, significa que foi a carta 1, se for 2 a carta 2 e se for 3 houve um empate
                int quem_venceu = decidir_vencedor(soma1, soma2, 0);

                if (quem_venceu == 1) {
                    printf("*** RESULTADO DA TERCEIRA RODADA ***\n");
                    printf("Nessa rodada vence quem tem mais pontos somando as duas categorias.\n");
                    printf("ATENÇÃO: Caso exista a densidade seja um dos valores a ser somado, ela será somada como o inverso do seu valor.\n\n");
                    printf("A carta que apresentou a melhor soma foi a carta 01 (%s) pois possui a soma de: %.2lf \n", nome_cidade1, soma1);
                    printf("A carta 02 (%s) alcançou uma soma de: %.2lf \n", nome_cidade2, soma2);
                    contador_de_vitorias1++;
                } else if (quem_venceu == 2) {
                    printf("*** RESULTADO DA TERCEIRA RODADA ***\n");
                    printf("Nessa rodada vence quem tem mais pontos somando as duas categorias.\n");
                    printf("ATENÇÃO: Caso exista a densidade seja um dos valores a ser somado, ela será somada como o inverso do seu valor.\n\n");
                    printf("A carta que apresentou a melhor soma foi a carta 02 (%s) pois possui a soma de: %.2lf \n", nome_cidade2, soma2);
                    printf("A carta 01 (%s) alcançou uma soma de: %.2lf \n", nome_cidade1, soma1);
                    contador_de_vitorias2++;
                } else {
                    printf("*** RESULTADO DA TERCEIRA RODADA ***\n");
                    printf("Nessa rodada vence quem tem mais pontos somando as duas categorias.\n");
                    printf("ATENÇÃO: Caso exista a densidade seja um dos valores a ser somado, ela será somada como o inverso do seu valor.\n\n");
                    printf("A carta 01 (%s) alcançou uma soma de: %.2lf \n", nome_cidade1, soma1);
                    printf("A carta 02 (%s) alcançou uma soma de: %.2lf \n", nome_cidade2, soma2);
                    printf("O que singnifica que houve um empate nesta rodada\n");
                    contador_de_empates++;
                }

                printf("A carta 01 (%s) ganhou %d vezes. \n", nome_cidade1, contador_de_vitorias1);
                printf("A carta 02 (%s) ganhou %d vezes. \n", nome_cidade2, contador_de_vitorias2);
                printf("houve %d empates. \n", contador_de_empates);
            }
            
            pause_program();
            clear_console();
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
