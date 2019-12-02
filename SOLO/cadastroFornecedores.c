#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include "cabeçalho.h"

void cadastroFornecedores (){


    int id_cliente=0;

 typedef struct Fornecedores {
    int filial;
    char nome [51];
    char cnpj [20];
    char telefone [11];
    char email [50];
    char endereco [50];
    char cep[10];
    char representante [120];
    int id;



    struct Fornecedores *proximo;

    }Fornecedores;

    Fornecedores *inicio = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivo = "bancoFornecedores.bin";

    Fornecedores *fornecedor;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (!feof(arq))      /* repetindo até o final do arquivo*/
    {   fornecedor  = (Fornecedores*) malloc(sizeof(Fornecedores));
        int qtd = fread(fornecedor,sizeof(Fornecedores),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = fornecedor;
                fornecedor->proximo = NULL;
            }
            else{
                Fornecedores *aux = inicio;
                fornecedor->proximo = aux;
                inicio = fornecedor;
            }
        }
    }
    fclose(arq);   /* abriu e leo o arquivo armazenou na memoria e fechou */


    Fornecedores *aux;
    int ot=0;
    int opp;
    int x=0;



            int op; /* aqui começa */
            int ordenaMenu =8;
            do {
            contornoTelaComCabeca();
            contornoFornecedor();
            printfCenter("TELA DE FORNECEDORES",1);
            printfOrdenado("1. NOVO FORNECEDOR",4,ordenaMenu);
            printfOrdenado("2. LISTAR FORNECEDORES",29,ordenaMenu);
            printfOrdenado("3. REMOVER FORNECEDOR",56,ordenaMenu);
            printfOrdenado(C_RED"0. RETORNAR AO MENU"NONE,61,19);pintar(15);
            printfOrdenado("Digite a opcao desejada: ",3,12);
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

            Fornecedores *novo = (Fornecedores*) malloc(sizeof(Fornecedores));

            novo->proximo=NULL;


            aux = inicio;
            ordenaMenu =3;
            novo->id += 1;
            contornoTelaComCabeca();

            printfCenter("Novo Cliente",1);
            gotoxy(3,4);
            printf("ID: %d", novo->id);
            printfOrdenado("Filial: ",15,4);
            scanf("%d", &novo->filial);

            printfOrdenado("Empresa: ",ordenaMenu,5);


            printfOrdenado("Cnpj: ",ordenaMenu,6);


            printfOrdenado("Cep: ", ordenaMenu,7);


            printfOrdenado("Telefone: ",ordenaMenu,8);


            printfOrdenado("Endereco: ",ordenaMenu,9);


            printfOrdenado("Representante: ",ordenaMenu, 12);


            /* Ordenando a leitura do que é escrito no teclado <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

            gotoxy(12,5);
             fflush(stdin);
            fgets(novo->nome ,sizeof(novo->nome),stdin);
            strtok(novo->nome, "\n");
            gotoxy(8,6);
            scanf("%20s", novo->cnpj);
            gotoxy(8,7);
            scanf("%10s", novo->cep);
            gotoxy(13,8);
            scanf("%11s", novo->telefone);
            gotoxy(13,9);
            fflush(stdin);
            fgets(novo->endereco ,sizeof(novo->endereco),stdin);
            strtok(novo->endereco, "\n");
            gotoxy(18,12);
            fflush(stdin);
            fgets(novo->representante ,sizeof(novo->representante),stdin);
            strtok(novo->representante, "\n");







            limparTela();
            contornoTela();
            gotoxy(3,4);

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
    Fornecedores *aux = inicio;
    FILE *arq = fopen(arquivo,"wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    while (aux != NULL){
        /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
       */ fwrite(aux,sizeof(Fornecedores),1,arq);
        aux = aux->proximo;

    }

    fclose(arq);
    }

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|    FORNECEDOR CADASTRADO COM SUCESSO     |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoCADASTRO();
            printfOrdenado("1. CADASTRAR OUTRO FORNECEDOR",8,11);
            printfOrdenado("0. RETORNAR AO MENU PRINCIPAL",43,11);
            printfOrdenado("Digite a opcao desejada: ",8,14);
            scanf("%d", &ot);
            limparTela();
            contornoTelaComCabeca();
        if(ot<0){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(ot>=2){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 1 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(ot==0){
            return menu();
        }else;


            if (ot==0){
                return main();
            }else if(ot==1){
                return cadastroFornecedores();
            }else; break;



                case 2:
                    limparTela();
                    contornoTela();
                    gotoxy(2,3);
            printfCenter("LISTAR",3);
            aux = inicio;
            gotoxy(2,4);
            printf ("\n\tFilial\tEmpresa\t\t\tRepresentante");
            while (aux!=NULL){
                printf("\n\t%d\t%s\t\t\t%s", aux->filial, aux->nome,aux->representante);
                aux=aux->proximo;

            } printfOrdenado("Aperte 0 para sair: ",35,19);
                scanf("%d",&opp);

                if (opp== 0){
                    return main();
                }
                limparTela(); break;

                case 0:
                    return main(); break;

        default:
            printf("Opcao Invalida");break;
        }





       }while(ot == 1);












    return 0;

}




