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
    

    printf("==== OLÁ, SEJA BEM VINDO AO JOGO SUPER TRUNFO====\n");

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

    printf("Digite o PIB: \n");
    scanf("%lf", &PIB);

    printf("Digite a quantidade de pontos turísticos: \n");
    scanf("%d", &pontos);

    //Processamento de dados

    densidade = (populacao / area);
    capita = (PIB / populacao);
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

    printf("Digite o PIB (use ponto para decimais): \n");
    scanf("%lf", &PIB2);

    printf("Digite a quantidade de pontos turísticos: \n");
    scanf("%d", &pontos2);

    //Processamento de dados

    densidade2 = (populacao2 / area2);
    capita2 = (PIB2 / populacao2);
    super2 = (float) populacao2 + area2 + PIB2 + pontos2 + capita2 + (1 / densidade2);

//Isso será apresentado.

    printf("\n===CARTA 1===\n");
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
    
    printf("\n===CARTA 2===\n");
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


    //Aqui as cartas serão comparadas sem a necessidade de interação dos usuarios.

    printf("\n===COMPARAÇÃO DE CARTAS===\n");

        if(populacao > populacao2){
            printf("\n**POPULAÇÃO**\nCarta 1 - %s (%s):%lu\n", cidade, estado, populacao);
            printf("Carta 2 - %s (%s):%lu\n", cidade2, estado2, populacao2);
            printf("\nCarta 1 (%s) Venceu!\n", cidade);
        } else {
            printf("\n**POPULAÇÃO**\nCarta 1 - %s (%s):%lu\n", cidade, estado, populacao);
            printf("Carta 2 - %s (%s):%lu\n", cidade2, estado2, populacao2);
            printf("\nCarta 2 (%s) Venceu!\n", cidade2);
        }

        
    return 0;
}