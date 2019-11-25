#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include "cabeçalho.h"

void cadastroFuncionarios (){




 typedef struct Funcionarios {
    int filial;
    char nome [51];
    char cpf [20];
    char telefone [11];
    char email [50];
    char endereco [50];
    char cep[10];
    char cargo [30];
    char pis [30];
    char jornada [30];
    int id;



    struct Funcionarios *proximo;

    }Funcionarios;

    Funcionarios *inicio = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivo = "bancoFuncionarios.bin";

    Funcionarios *funcionario;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (!feof(arq))      /* repetindo até o final do arquivo*/
    {   funcionario  = (Funcionarios*) malloc(sizeof(Funcionarios));
        int qtd = fread(funcionario,sizeof(Funcionarios),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = funcionario;
                funcionario->proximo = NULL;
            }
            else{
                Funcionarios *aux = inicio;
                funcionario->proximo = aux;
                inicio = funcionario;
            }
        }
    }
    fclose(arq);   /* abriu e leu o arquivo armazenou na memoria e fechou */


    Funcionarios *aux;
    int ot=0;
    int opp;
    int x=0;



            int op; /* aqui começa */
            int ordenaMenu =8;
            do {
            contornoTelaComCabeca();
            contornoPizzaiolo();
            printfCenter("TELA DE CLIENTE",1);
            printfOrdenado("1. NOVO FUNCIONARIO",5,ordenaMenu);
            printfOrdenado("2. LISTAR FUNCIONARIOS",29,ordenaMenu);
            printfOrdenado("3. REMOVER FUNCIONARIO",55,ordenaMenu);
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

            Funcionarios *novo = (Funcionarios*) malloc(sizeof(Funcionarios));

            novo->proximo=NULL;


            aux = inicio;
            ordenaMenu =3;
            novo->id += 1;
            contornoTelaComCabeca();

            printfCenter("Novo Funcionarios",1);
            gotoxy(3,4);
            printf("ID: %d", novo->id);
            printfOrdenado("Filial: ",15,4);
            scanf("%d", &novo->filial);

            printfOrdenado("Nome: ",ordenaMenu,5);


            printfOrdenado("CPF: ",ordenaMenu,6);


            printfOrdenado("Cep: ", ordenaMenu,7);


            printfOrdenado("Telefone: ",ordenaMenu,8);


            printfOrdenado("Endereco: ",ordenaMenu,9);


            printfOrdenado("Cargo: ",ordenaMenu, 10);

            printfOrdenado("PIS:",ordenaMenu, 11);

            printfOrdenado("Jornada Trabalho: ",ordenaMenu, 12);


            /* Ordenando a leitura do que é escrito no teclado <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

            gotoxy(9,5);
             fflush(stdin);
            fgets(novo->nome ,sizeof(novo->nome),stdin);
            strtok(novo->nome, "\n");
            gotoxy(8,6);
            scanf("%20s", novo->cpf);
            gotoxy(8,7);
            scanf("%10s", novo->cep);
            gotoxy(13,8);
            scanf("%11s", novo->telefone);
            gotoxy(13,9);
            fflush(stdin);
            fgets(novo->endereco ,sizeof(novo->endereco),stdin);
            strtok(novo->endereco, "\n");
            gotoxy(10,10);
            fflush(stdin);
            fgets(novo->cargo ,sizeof(novo->cargo),stdin);
            strtok(novo->cargo, "\n");
            gotoxy(8,11);
            fgets(novo->pis ,sizeof(novo->pis),stdin);
            strtok(novo->pis, "\n");
            gotoxy(22,12);
            fgets(novo->jornada ,sizeof(novo->jornada),stdin);
            strtok(novo->jornada, "\n");







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
    Funcionarios *aux = inicio;
    FILE *arq = fopen(arquivo,"wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    while (aux != NULL){
        /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
       */ fwrite(aux,sizeof(Funcionarios),1,arq);
        aux = aux->proximo;

    }

    fclose(arq);
    }

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|      USUARIO CADASTRADO COM SUCESSO      |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoCADASTRO();
            printfOrdenado("1. CADASTRAR OUTRO USUARIO",9,11);
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



             if(ot==1){
                return cadastroFuncionarios();
            }else; break;



                case 2:
                    limparTela();
                    contornoTela();
                    gotoxy(2,3);
            printfCenter("LISTAR",3);
            aux = inicio;
            gotoxy(2,4);
            printf ("\n\tFilial\tNome\t\t\tEndereco");
            while (aux!=NULL){
                printf("\n\t%d\t%s\t\t\t%s", aux->filial, aux->nome,aux->endereco);
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




