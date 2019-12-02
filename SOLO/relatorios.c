#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include "cabeçalho.h"
#include <string.h>


void cadastroRelatorio (){

typedef struct relatorio {
    char filial [2];
    char dia [2];
    char mes [10];
    char ano [5];
    char sabor [10];
    int quantidadeVendida;
    int quantidadeCancelada;
    int despesas;
    int lucro;
    float precoVenda;
    char obs [120];



    struct Relatorio *proximo;

    }Relatorio;




    Relatorio *inicio = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivo = "Relatorio.bin";

    Relatorio *relatorio;
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
    {   relatorio  = (Relatorio*) malloc(sizeof(Relatorio));
        int qtd = fread(relatorio,sizeof(Relatorio),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = relatorio;
                relatorio->proximo = NULL;
            }
            else{
                Relatorio *aux = inicio;
                relatorio->proximo = aux;
                inicio = relatorio;
            }
        }
    }
    fclose(arq);   /* abriu e leu o arquivo armazenou na memoria e fechou */



    Relatorio *aux;
    int ott=0;
    int opp;
    int xx=0;



            int op;
            int ordenaMenu =8;
            do {
            contornoTelaComCabeca();
            contorno_BePeP();
            printfCenter("TELA DE RELATORIO",1);
            printfOrdenado("1-Novo",8,ordenaMenu);
            printfOrdenado("2-Listar",30,ordenaMenu);
            printfOrdenado(C_RED"0-Retornar ao Menu"NONE,61,19);pintar(15);
            printfOrdenado("Digite a opcao desejada: ",5,12);
            scanf("%d", &opp);
            limparTela();
        if(opp<0){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(opp>=4){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 3 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(opp==0){
            return menu();
        }else;


            switch (opp){
            case 1:


            limparTela();
            printf("\nAdicionar");

            Relatorio *novo = (Relatorio*) malloc(sizeof(Relatorio));

            novo->proximo=NULL;


            aux = inicio;
            ordenaMenu =3;
            contornoTelaComCabeca();
            printfCenter("Novo Lancamento",1);
            gotoxy(3,4);





            printfOrdenado("Filial: ",3,4);
            scanf("%d", &novo->filial);
            printfOrdenado("Dia: ",ordenaMenu,5);
            printfOrdenado("Mes: ",ordenaMenu,6);
            printfOrdenado("Ano: ",ordenaMenu,7);
            printfOrdenado("Sabor: ",ordenaMenu,8);
            printfOrdenado("Qtd Vendida: ", ordenaMenu,9);
            printfOrdenado("Qtd Cancelada %: ",ordenaMenu,10);
            printfOrdenado("Valor Uni.: ",ordenaMenu,11);



            gotoxy(8,5);
            fflush(stdin);
            fgets(novo->dia ,sizeof(novo->dia),stdin);
            strtok(novo->dia, "\n");
            gotoxy(8,6);

            fflush(stdin);
            fgets(novo->mes ,sizeof(novo->mes),stdin);
            strtok(novo->mes, "\n");
            gotoxy(8,7);
            fflush(stdin);
            fgets(novo->ano ,sizeof(novo->ano),stdin);
            strtok(novo->ano, "\n");
            gotoxy(10,8);
            fflush(stdin);
            fgets(novo->sabor ,sizeof(novo->sabor),stdin);
            strtok(novo->sabor, "\n");
            gotoxy(16,9);
            scanf("%d", &novo->quantidadeVendida);
            gotoxy(19,10);
            scanf("%d", &novo->quantidadeCancelada);
            gotoxy(15,11);
            gotoxy(10,12);
            scanf("%d", &novo->lucro);



             if (inicio == NULL){

            inicio = novo;


        }else{

            while(aux->proximo!=NULL){

                aux=aux->proximo;

            }

            aux ->proximo = novo;
        }


                                /* Abrindo arquivo  para gravar os dados*/
        if(inicio != NULL){
    Relatorio *aux = inicio;
    FILE *arq = fopen(arquivo,"wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    while (aux != NULL){
        fwrite(aux,sizeof(Relatorio),1,arq);
        aux = aux->proximo;

    }

    fclose(arq);
    }


        limparTela();
        contornoTela();

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|       REGISTRO SALVO COM SUCESSO         |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoCADASTRO();
            printfOrdenado("1. NOVO CADASTRO",9,11);
            printfOrdenado("0. RETORNAR AO MENU PRINCIPAL",43,11);
            printfOrdenado("Digite a opcao desejada: ",8,14);
            scanf("%d", &ott);
            limparTela();
            contornoTelaComCabeca();
        if(ott<0){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(ott>=2){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 1 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(ott==0){
            return menu();
        }else;


            if(ott==1){
                return cadastroRelatorio();
            }else; break;



                case 2:


               printf("\nPesquisar por sabor");
                char nome[41];
                printf("\n\n");
                printf("Digite o nome: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                strtok(nome, "\n");

                Relatorio *aux = inicio;
                printf("\nTodos os contatos");
                printf("\n\n\n%-40s|%-15s|%-5s|%-5s\n\n", "NOME", "FILIAL","DIA", "QTD VENDA");
                while(aux != NULL){

                if(strcmp(nome, aux->sabor) == 0){
                    printf("%-40s|%-15s|%-5s|%-5d\n", aux->sabor, aux->filial,aux->dia,aux->quantidadeVendida);
                }
                aux = aux->proximo;
                }


                system("pause");


                case 0: return main(); break;
        default:
            printf("Opcao Invalida");break;

        }
        free(relatorio);






       }while(ott == 1);

    return cadastroRelatorio();

}









