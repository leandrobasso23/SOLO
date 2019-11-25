#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include "cabeçalho.h"


void estoque (){

    typedef struct Bebidas {
    int filial;
    char nome [51];
    char Ml [10];
    float precoCusto;
    int imposto;
    int despesas;
    float precoVenda;
    int estoqueAtual;
    int novoEstoque;
    char fornecedor [50];
    char obs [120];



    struct Bebidas *proximo;

    }Bebidas;




    Bebidas *inicio = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivo = "bancoBebidas.bin";

    Bebidas *bebidas;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        limparTela();
        contornoTela();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    }

    while (!feof(arq))      /* repetindo até o final do arquivo*/
    {   bebidas  = (Bebidas*) malloc(sizeof(Bebidas));
        int qtd = fread(bebidas,sizeof(Bebidas),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = bebidas;
                bebidas->proximo = NULL;
            }
            else{
                Bebidas *aux = inicio;
                bebidas->proximo = aux;
                inicio = bebidas;
            }
        }
    }
    fclose(arq);   /* abriu e leu o arquivo armazenou na memoria e fechou */



    Bebidas *aux;



 /* Lendo o banco de dados de Produtos */

 typedef struct Produtos {
    int filial;
    char nome [51];
    float Peso;
    float precoCusto;
    int imposto;
    int despesas [20];
    float precoVenda;
    int estoqueAtual;
    int novoEstoque;
    char fornecedor [50];
    char obs [120];



    struct Produtos *proximo;

    }Produtos;




    Produtos *inicio2 = NULL;

    Produtos *auxx;
    int ott=0;
    int opp;
    int xx=0;


    char *arquivo2 = "bancoProdutos.bin";

    Produtos *produtos;
    FILE *arq2 = fopen(arquivo2,"r+b");
    if (arq == NULL)
    {
        limparTela();
        contornoTela();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    }

    while (!feof(arq2))      /* repetindo até o final do arquivo*/
    {   produtos  = (Produtos*) malloc(sizeof(Produtos));
        int qtd = fread(produtos,sizeof(Produtos),1,arq2);
        if(qtd > 0){
            if(inicio2 == NULL){
                inicio2 = produtos;
                produtos->proximo = NULL;
            }
            else{
                Produtos *auxx = inicio2;
                produtos->proximo = auxx;
                inicio2 = produtos;
            }
        }
    }
    fclose(arq);








    limparTela();
    contornoTelaComCabeca();
    contornoEstoque();
    printfCenter("ESTOQUE",1);

    int ordenaMenu = 12;
    int op;


    printfOrdenado("1. BEBIDAS", 10,ordenaMenu);
    printfOrdenado("2. PRODUTOS",34,ordenaMenu);
    printfOrdenado("3. MATERIA PRIMA",57,ordenaMenu);
    printfOrdenado(C_RED"0- RETORNAR AO MENU"NONE,60,19);pintar(15);
    printfOrdenado("Digite a opcao desejada: ",7,16);
    scanf("%d", &op);
    if(op<0){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
    }else if(op>=4){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 3 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
    }else if(op==0){
        return menu();
    }else;


    switch (op){

        case 1:






    limparTela();
                    contornoTela();
                    gotoxy(2,3);
                    printfCenter("LISTAR",2);
                    aux = inicio;
                    gotoxy(2,4);
                    printf ("\t%-35s|%-15s|%10s\n\n", "NOME", "PRECO","ESTOQUE");
                    while (aux!=NULL){
                    printf("\t%-35s|%-15.2f|%10d\n",aux->nome,aux->precoVenda,aux->estoqueAtual);
                    aux=aux->proximo;}

                    printfOrdenado("Aperte 0 para sair: ",35,19);
                    scanf("%d",&opp);
                    limparTela(); break;


        case 2:

            limparTela();
                    contornoTela();
                    gotoxy(2,3);
            printfOrdenado("Listar",1,2);
            auxx = inicio2;

            printf ("\t%-35s|%-15s|%10s\n\n", "NOME", "PRECO","ESTOQUE");
                    while (auxx!=NULL){
                    printf("\t%-35s|%-15.2f|%10d\n",auxx->nome,auxx->precoVenda,auxx->estoqueAtual);
                    auxx=auxx->proximo;}


            } printfOrdenado("Aperte 0 para sair: ",35,19);
                scanf("%d",&opp);



    }







