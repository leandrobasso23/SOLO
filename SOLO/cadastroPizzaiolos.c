#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include "cabeçalho.h"

void cadastroPizzaiolo (){


    int id_cliente=0;

 typedef struct Pizzaiolo {
    int filial;
    char nome [51];
    char obs [120];
    int id;



    struct Pizzaiolo *proximo;

    }Pizzaiolo;

    Pizzaiolo *inicio = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivo = "bancoPizzaiolo.bin";

    Pizzaiolo *pizzaiolo;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (!feof(arq))      /* repetindo até o final do arquivo*/
    {   pizzaiolo  = (Pizzaiolo*) malloc(sizeof(Pizzaiolo));
        int qtd = fread(pizzaiolo,sizeof(Pizzaiolo),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = pizzaiolo;
                pizzaiolo->proximo = NULL;
            }
            else{
                Pizzaiolo *aux = inicio;
                pizzaiolo->proximo = aux;
                inicio = pizzaiolo;
            }
        }
    }
    fclose(arq);   /* abriu e leo o arquivo armazenou na memoria e fechou */


    Pizzaiolo *aux;
    int ot=0;
    int opp;
    int x=0;



            int op; /* aqui começa */
            int ordenaMenu =8;
            do {
            contornoTelaComCabeca();
            contornoPizzaiolo();
            printfCenter("TELA DE PIZZAIOLOS",1);
            printfOrdenado("1. Novo Pizzaiolo",6,ordenaMenu);
            printfOrdenado("2. Listar ja cadastrados",28,ordenaMenu);
            printfOrdenado(C_RED"0. Retornar ao Menu"NONE,60,19);pintar(15);
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

            Pizzaiolo *novo = (Pizzaiolo*) malloc(sizeof(Pizzaiolo));

            novo->proximo=NULL;


            aux = inicio;
            ordenaMenu =3;

            contornoTelaComCabeca();

            printfCenter("Novo Pizzaiolo",1);
            gotoxy(3,4);

            printfOrdenado("Filial: ",15,4);
            scanf("%d", &novo->filial);

            printfOrdenado("Nome: ",ordenaMenu,5);


            printfOrdenado("Jornada: ",ordenaMenu, 6);


            /* Ordenando a leitura do que é escrito no teclado <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

            gotoxy(9,5);
             fflush(stdin);
            fgets(novo->nome ,sizeof(novo->nome),stdin);
            strtok(novo->nome, "\n");
             gotoxy(16,6);
            fflush(stdin);
            fgets(novo->obs ,sizeof(novo->obs),stdin);
            strtok(novo->obs, "\n");







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
    Pizzaiolo *aux = inicio;
    FILE *arq = fopen(arquivo,"wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    while (aux != NULL){
        /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
       */ fwrite(aux,sizeof(Pizzaiolo),1,arq);
        aux = aux->proximo;

    }

    fclose(arq);
    }

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|     PIZZAIOLO CADASTRADO COM SUCESSO     |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoCADASTRO();
            printfOrdenado("1. CADASTRAR OUTRO PIZZAIOLO",8,11);
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
            }else if (ot==1){
                return cadastroPizzaiolo();
            }else;
            break;



                case 2:
                    limparTela();
                    contornoTela();
                    gotoxy(2,3);
            printfCenter("LISTAR",3);
            aux = inicio;
            gotoxy(2,4);
            printf ("\n\tFilial\tNome\t\t\tObservacao");
            while (aux!=NULL){
                printf("\n\t%d\t%s\t\t\t%s", aux->filial, aux->nome,aux->obs);
                aux=aux->proximo;

            } printfOrdenado("Aperte 0 para sair: ",35,19);
                scanf("%d",&opp);

                if (opp== 0){
                    return cadastroPizzaiolo();
                }
                limparTela(); break;

                case 0:
                    return main(); break;

        default:
            printf("Opcao Invalida");break;
        }





       }while(ot == 1);


        free(pizzaiolo);









    return 0;

}




