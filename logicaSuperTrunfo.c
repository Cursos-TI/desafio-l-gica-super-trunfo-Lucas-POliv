#include <stdio.h>
#include <locale.h>
#include <string.h> //para usar strcspn

int main () {
    setlocale(LC_NUMERIC, "C"); // permite usar ponto como separador decimal.

    char estado [3], estado2 [3];
    char carta [10], carta2[10];
    char cidade [50], cidade2 [50];
    unsigned long int populacao, populacao2;
    float area, area2, densidade, densidade2, super, super2, capita, capita2;
    double PIB, PIB2;
    int pontos, pontos2;
    int escolha, escolha2, escolha3, opcao;
    int vitoria1 = 0, vitoria2 = 0;

    //Início do jogo

    printf("\n==== OLÁ, SEJA BEM VINDO AO JOGO SUPER TRUNFO ====\n");

    do { //Isso inicia um loop para o jogo ser finalizado apenas quando for escolhido a opção "3. Sair".

        printf("\nMenu Principal:\n"); // Menu interativo.
        printf("\n1. Iniciar o jogo.\n");
        printf("2. Regras\n");
        printf("3. Sair\n");
        printf("O que deseja fazer? ");
        scanf("%d", &opcao);

    
        switch (opcao){
            case 1:

                printf("\n#### INICIANDO O JOGO ####\n");

            // ENTRADA CARTA 1
                printf("\nDIGITE OS DADOS DA CARTA 1.\n");

                printf("\nDigite o código da carta: \n");
                scanf("%9s", carta);

                printf("Digite o estado (sigla): \n");
                scanf("%2s", estado);
                
                getchar(); //limpa o \n deixado pelo scanf anterior.
                printf("Digite o nome da cidade: \n");
                fgets(cidade, sizeof(cidade), stdin);
                cidade[strcspn(cidade, "\n")] = '\0'; //remove o \n que o fgets pode guardar no final.

                printf("Digite a populacao: \n");
                scanf("%lu", &populacao);

                printf("Digite a área (use ponto para decimais): \n");
                scanf("%f", &area);

                printf("Digite o PIB (Em bilhões): \n");
                scanf("%lf", &PIB);

                printf("Digite a quantidade de pontos turísticos: \n");
                scanf("%d", &pontos);

                //Processamento de dados

                densidade = (populacao / area);
                capita = (PIB * 1000000000.0 / populacao);
                super = (float) populacao + area + PIB + pontos + capita + (1 / densidade);
                

            // ENTRADA CARTA 2
                printf("\nDIGITE OS DADOS DA CARTA 2.\n");

                printf("\nDigite o código da carta: \n");
                scanf("%9s", carta2);

                printf("Digite o estado (sigla): \n");
                scanf("%2s", estado2);

                getchar(); //limpa o \n deixado pelo scanf anterior.
                printf("Digite o nome da cidade: \n");
                fgets(cidade2, sizeof(cidade2), stdin);
                cidade2[strcspn(cidade2, "\n")] = '\0'; //remove o \n que o fgets pode guardar no final.

                printf("Digite a populacao: \n");
                scanf("%lu", &populacao2);

                printf("Digite a área (use ponto para decimais): \n");
                scanf("%f", &area2);

                printf("Digite o PIB (Em bilhões): \n");
                scanf("%lf", &PIB2);

                printf("Digite a quantidade de pontos turísticos: \n");
                scanf("%d", &pontos2);

                //Processamento de dados
                densidade2 = (populacao2 / area2);
                capita = (PIB * 1000000000.0 / populacao);
                super2 = (float) populacao2 + area2 + PIB2 + pontos2 + capita2 + (1 / densidade2);

                /*Aqui será feito a comparação de cartas de acordo com a escolha do usuario.
                Primeiro o usuario vai escolher qual atributo ele deseja comparar.
                */
                printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
                printf("\n1. População\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Pontos Turisticos\n");
                printf("5. Densidade populacional\n");
                printf("6. PIB per Capita\n");
                printf("7. Super Poder\n");
                printf("\nQual atributo você deseja comparar? ");
                scanf("%d", &escolha);

                //Aqui seleciona a escolha feita pelo usuario.
                switch (escolha){
                    case 1:
                        printf("\nSua escolha foi: %d - População\n", escolha);
                        printf("Carta 1 - %s (%s):%lu\n", cidade, estado, populacao);
                        printf("Carta 2 - %s (%s):%lu\n", cidade2, estado2, populacao2);

                        if (populacao > populacao2) {
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (populacao < populacao2) {
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else {
                        printf("Houve um empate\n");
                        }
                        break;

                    case 2:
                        printf("\nSua escolha foi: %d - Área\n", escolha);
                        printf("Carta 1 - %s (%s):%.2f km²\n", cidade, estado, area);
                        printf("Carta 2 - %s (%s):%.2f km²\n", cidade2, estado2, area2);

                        if(area > area2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if(area < area2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else {
                            printf("Houve um empate\n");
                        }
                        break;
                        
                    case 3:
                        printf("\nSua escolha foi: %d - PIB\n", escolha);
                        printf("Carta 1 - %s (%s):R$ %.2lf\n", cidade, estado, PIB);
                        printf("Carta 2 - %s (%s):R$ %.2lf\n", cidade2, estado2, PIB2);
                         
                        if(PIB > PIB2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (PIB < PIB2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++; 
                        } else{
                            printf("Houve um empate\n");
                        }
                        break;

                    case 4:
                        printf("\nSua escolha foi: %d - Pontos Turisticos\n", escolha);
                        printf("Carta 1 - %s (%s):%d\n", cidade, estado, pontos);
                        printf("Carta 2 - %s (%s):%d\n", cidade2, estado2, pontos2);

                        if(pontos > pontos2){
                            printf("\nCarta 1 (%s) Venceu\n!", cidade);
                            vitoria1++;
                        } else if (pontos < pontos2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else {
                            printf("Houve um empate\n");
                        }
                        break;
                        
                    case 5:
                        printf("\nSua escolha foi: %d - Densidade Populacional\n", escolha);
                        printf("Carta 1 - %s (%s):%.2f hab/km²\n", cidade, estado, densidade);
                        printf("Carta 2 - %s (%s):%.2f hab/km²\n", cidade2, estado2, densidade2);

                    //No super trunfo, a menor densidade vence!
                        
                        if(densidade < densidade2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (densidade2 < densidade) {
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else {
                            printf("Houve um empate\n");
                        }
                        break;

                    case 6:
                        printf("\nSua escolha foi: %d - PIB per Capita\n", escolha);
                        printf("Carta 1 - %s (%s):R$ %.2f\n", cidade, estado, capita);
                        printf("Carta 2 - %s (%s):R$ %.2f\n", cidade2, estado2, capita2);

                        if(capita > capita2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (capita < capita2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2); 
                            vitoria2++;
                        } else {
                            printf("Houve um empate\n");
                        }
                        break;

                    case 7:
                        printf("\nSua escolha foi: %d - Super Poder\n", escolha);
                        printf("Carta 1 - %s (%s):%.2f\n", cidade, estado, super);
                        printf("Carta 2 - %s (%s):%.2f\n", cidade2, estado2, super2);
                        
                        if(super > super2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (super < super2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else{
                            printf("Houve um empate\n");
                        }
                        break;

                    default:
                        printf("Opção Invalida!\n");
                        break;
                    }
                            
                // Aqui será feito a comparação do segundo atributo.

                printf("\nESCOLHA MAIS UM ATRIBUTO PARA SER COMPARADO\n");

                printf("\n1. Populção\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Pontos Turisticos\n");
                printf("5. Densidade populacional\n");
                printf("6. PIB per Capita\n");
                printf("7. Super Poder\n");
                printf("\nQual atributo você deseja comparar? ");
                scanf("%d", &escolha2);

                //Condição para comparação
                if (escolha2 == escolha){
                    printf("Você escolheu o mesmo atributo que o anterior!\n");
                    printf("Por favor, escolha outro!\n");
                    printf("\nQual atributo você deseja comparar? ");
                    scanf("%d", &escolha3);

                        switch (escolha3){
                        case 1:
                            printf("\nSua escolha foi: %d - População\n", escolha3);
                            printf("Carta 1 - %s (%s):%lu\n", cidade, estado, populacao);
                            printf("Carta 2 - %s (%s):%lu\n", cidade2, estado2, populacao2);

                            if (populacao > populacao2) {
                                printf("\nCarta 1 (%s) Venceu!\n", cidade);
                                vitoria1++;
                            } else if (populacao < populacao2) {
                                printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                                vitoria2++;
                            } else {
                                printf("Houve um empate\n");
                            }
                            break;

                        case 2:
                            printf("\nSua escolha foi: %d - Área\n", escolha3);
                            printf("Carta 1 - %s (%s):%.2f km²\n", cidade, estado, area);
                            printf("Carta 2 - %s (%s):%.2f km²\n", cidade2, estado2, area2);

                            if(area > area2){
                                printf("\nCarta 1 (%s) Venceu!\n", cidade);
                                vitoria1++;
                            } else if(area < area2){
                                printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                                vitoria2++;
                            } else {
                                printf("Houve um empate\n");
                            }
                            break;
                            
                        case 3:
                            printf("\nSua escolha foi: %d - PIB\n", escolha3);
                            printf("Carta 1 - %s (%s): R$ %.2lf\n", cidade, estado, PIB);
                            printf("Carta 2 - %s (%s): R$ %.2lf\n", cidade2, estado2, PIB2);
                            
                            if(PIB > PIB2){
                                printf("\nCarta 1 (%s) Venceu!\n", cidade);
                                vitoria1++;
                            } else if (PIB < PIB2){
                                printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                                vitoria2++; 
                            } else{
                                printf("Houve um empate\n");
                            }
                            break;

                        case 4:
                            printf("\nSua escolha foi: %d - Pontos Turisticos\n", escolha3);
                            printf("Carta 1 - %s (%s):%d\n", cidade, estado, pontos);
                            printf("Carta 2 - %s (%s):%d\n", cidade2, estado2, pontos2);

                            if(pontos > pontos2){
                                printf("\nCarta 1 (%s) Venceu\n!", cidade);
                                vitoria1++;
                            } else if (pontos < pontos2){
                                printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                                vitoria2++;
                            } else {
                                printf("Houve um empate\n");
                            }
                            break;
                            
                        case 5:
                            printf("\nSua escolha foi: %d - Densidade Populacional\n", escolha3);
                            printf("Carta 1 - %s (%s):%.2f hab/km²\n", cidade, estado, densidade);
                            printf("Carta 2 - %s (%s):%.2f hab/km²\n", cidade2, estado2, densidade2);

                        //No super trunfo, a menor densidade vence!
                            
                            if(densidade < densidade2){
                                printf("\nCarta 1 (%s) Venceu!\n", cidade);
                                vitoria1++;
                            } else if (densidade2 < densidade) {
                                printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                                vitoria2++;
                            } else {
                                printf("Houve um empate\n");
                            }
                            break;

                        case 6:
                            printf("\nSua escolha foi: %d - PIB per Capita\n", escolha3);
                            printf("Carta 1 - %s (%s):R$ %.2f\n", cidade, estado, capita);
                            printf("Carta 2 - %s (%s):R$ %.2f\n", cidade2, estado2, capita2);

                            if(capita > capita2){
                                printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            } else if (capita < capita2){
                                printf("\nCarta 2 (%s) Venceu!\n", cidade2); 
                            } else {
                                printf("Houve um empate\n");
                            }
                            break;

                        case 7:
                            printf("\nSua escolha foi: %d - Super Poder\n", escolha3);
                            printf("Carta 1 - %s (%s):%.2f\n", cidade, estado, super);
                            printf("Carta 2 - %s (%s):%.2f\n", cidade2, estado2, super2);
                            
                            if(super > super2){
                                printf("\nCarta 1 (%s) Venceu!\n", cidade);
                                vitoria1++;
                            } else if (super < super2){
                                printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                                vitoria2++;
                            } else{
                                printf("Houve um empate\n");
                            }
                            break;

                        default:
                            printf("Opção Invalida!\n");
                            break;
                        }
                }
                else {
                    switch (escolha2){
                    case 1:
                        printf("\nSua escolha foi: %d - População\n", escolha2);
                        printf("Carta 1 - %s (%s):%lu\n", cidade, estado, populacao);
                        printf("Carta 2 - %s (%s):%lu\n", cidade2, estado2, populacao2);

                        if (populacao > populacao2) {
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (populacao < populacao2) {
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else {
                        printf("Houve um empate\n");
                        }
                        break;

                    case 2:
                        printf("\nSua escolha foi: %d - Área\n", escolha2);
                        printf("Carta 1 - %s (%s):%.2f km²\n", cidade, estado, area);
                        printf("Carta 2 - %s (%s):%.2f km²\n", cidade2, estado2, area2);

                        if(area > area2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if(area < area2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else {
                            printf("Houve um empate\n");
                        }
                        break;
                        
                    case 3:
                        printf("\nSua escolha foi: %d - PIB\n", escolha2);
                        printf("Carta 1 - %s (%s):R$ %.2lf\n", cidade, estado, PIB);
                        printf("Carta 2 - %s (%s):R$ %.2lf\n", cidade2, estado2, PIB2);
                         
                        if(PIB > PIB2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (PIB < PIB2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++; 
                        } else{
                            printf("Houve um empate\n");
                        }
                        break;

                    case 4:
                        printf("\nSua escolha foi: %d - Pontos Turisticos\n", escolha2);
                        printf("Carta 1 - %s (%s):%d\n", cidade, estado, pontos);
                        printf("Carta 2 - %s (%s):%d\n", cidade2, estado2, pontos2);

                        if(pontos > pontos2){
                            printf("\nCarta 1 (%s) Venceu\n!", cidade);
                            vitoria1++;
                        } else if (pontos < pontos2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else {
                            printf("Houve um empate\n");
                        }
                        break;
                        
                    case 5:
                        printf("\nSua escolha foi: %d - Densidade Populacional\n", escolha2);
                        printf("Carta 1 - %s (%s):%.2f hab/km²\n", cidade, estado, densidade);
                        printf("Carta 2 - %s (%s):%.2f hab/km²\n", cidade2, estado2, densidade2);
                    //No super trunfo, a menor densidade vence!
                        
                        if(densidade < densidade2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (densidade2 < densidade) {
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else {
                            printf("Houve um empate\n");
                        }
                        break;

                    case 6:
                        printf("\nSua escolha foi: %d - PIB per Capita\n", escolha2);
                        printf("Carta 1 - %s (%s):R$ %.2f\n", cidade, estado, capita);
                        printf("Carta 2 - %s (%s):R$ %.2f\n", cidade2, estado2, capita2);

                        if(capita > capita2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (capita < capita2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2); 
                            vitoria2++;
                        } else {
                            printf("Houve um empate\n");
                        }
                        break;

                    case 7:
                        printf("\nSua escolha foi: %d - Super Poder\n", escolha2);
                        printf("Carta 1 - %s (%s):%lu\n", cidade, estado, super);
                        printf("Carta 2 - %s (%s):%lu\n", cidade2, estado2, super2);
                        
                        if(super > super2){
                            printf("\nCarta 1 (%s) Venceu!\n", cidade);
                            vitoria1++;
                        } else if (super < super2){
                            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
                            vitoria2++;
                        } else{
                            printf("Houve um empate\n");
                        }
                        break;

                    default:
                        printf("Opção Invalida!\n");
                        break;
                    }
                }

         /*Isso será apresentado.

            CARTA 1:
         */
            printf("\n=== CARTA 1 ===\n");
            printf("\nCarta: %s\n", carta);
            printf("Estado: %s\n", estado);
            printf("Cidade: %s\n", cidade);
            printf("População: %lu\n", populacao);
            printf("Area: %.2fkm²\n", area);
            printf("PIB: R$%.2lf\n", PIB);
            printf("Pontos turísticos: %d\n", pontos); 
            printf("Densidade Populacional: %.2fhab/km²\n", densidade);
            printf("PIB per Capita: R$%.2f\n", capita);
            printf("Super poder: %.2f\n", super);
            
         // CARTA 2:

            printf("\n=== CARTA 2 ===\n");
            printf("\nCarta: %s\n", carta2);
            printf("Estado: %s\n", estado2);
            printf("Cidade: %s\n", cidade2);
            printf("População: %lu\n", populacao2);
            printf("Area: %.2fkm²\n", area2);
            printf("PIB: R$%.2lf\n", PIB2);
            printf("Pontos turísticos: %d\n", pontos2);
            printf("Densidade Populacional: %.2fhab/km²\n", densidade2);
            printf("PIB per Capita: R$%.2f\n", capita2);
            printf("Super poder: %.2f\n", super2);

            if(vitoria1 == 2){
                printf("\nA carta 1 venceu nas duas comparações!\n");
            } else if(vitoria2 == 2){
                printf("\nA carta 2 venceu nas duas comparações!\n");
            } else if(vitoria1 == vitoria2){
                printf("\nCada carta venceu em uma comparação diferente!\n");
                printf("As comparações empatou\n");
            }
        
            if(super > super2){
                printf("\n#### Parabéns, o dono da carta 1 venceu a partida por ter a carta mais forte! ####\n");
            } else if (super < super2){
                printf("\n#### Parabéns, o dono da carta 2 venceu a partida por ter a carta mais forte! ####\n");
            } else {
                printf("\n#### Houve um empate! ####\n");
            }
             
            break;

         case 2: 
            printf("\nREGRAS\n"); //As regras estão em fase de desenvolvimento.
            printf("1. O JOGO DEVE SER EXECUTADO POR DOIS USUARIOS\n");
            printf("2. ....\n");
            printf("3. ....\n");
            break;
        
         case 3:
            printf("Saindo do jogo....\n");
            break;

         default:
            printf("Opção Inavalida!\n");
            break;
        }

     } while (opcao != 3);  // while finaliza loop e o jogo é encerrado.
        printf("Obrigado por jogar!\n");
    
    
    return 0;
 } 