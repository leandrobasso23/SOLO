#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "cabeçalho.h"

void cadastroReclamacoes(){


    int id_cliente=0;

 typedef struct Feedback {
    int filial;
    char nome [51];
    char data [20];
    char telefone [11];
    char endereco [50];
    char tipo [20];
    char obs [120];
    int id;



    struct Feedback *proximo;

    }Feedback;

    Feedback *inicio = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivo = "bancoFeedback.bin";

    Feedback *feedback;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (!feof(arq))      /* repetindo até o final do arquivo*/
    {   feedback  = (Feedback*) malloc(sizeof(Feedback));
        int qtd = fread(feedback,sizeof(Feedback),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = feedback;
                feedback->proximo = NULL;
            }
            else{
                Feedback *aux = inicio;
                feedback->proximo = aux;
                inicio = feedback;
            }
        }
    }
    fclose(arq);   /* abriu e leu o arquivo armazenou na memoria e fechou */


    Feedback *aux;
    int ot=0;
    int opp;
    int x=0;



            int op; /* aqui começa */
            int ordenaMenu =11;
            do {
            contornoTelaComCabeca();
            contornoRegistro();
            printfCenter("TELA DE REGISTRO",1);
            printfOrdenado("1. NOVO REGISTRO",5,ordenaMenu);
            printfOrdenado("2. LISTAR REGISTROS",30,ordenaMenu);
            printfOrdenado("3. PESQUISAR POR NOME",56,ordenaMenu);
            printfOrdenado(C_RED"0. RETORNAR AO MENU"NONE,60,19);pintar(15);
            printfOrdenado("Digite a opcao desejada: ",3,15);
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
            return 0;
        }else if(opp==0){
            return menu();
        }else;


            switch (opp){
            case 1:


            limparTela();
            printf("\nAdicionar");

            Feedback *novo = (Feedback*) malloc(sizeof(Feedback));

            novo->proximo=NULL;


            aux = inicio;
            ordenaMenu =3;
            novo->id += 1;
            contornoTelaComCabeca();

            limparTela();
                    contornoTela();
                    printfCenter("NOVO REGISTRO", 1);


                    printfOrdenado("TIPO:",ordenaMenu, 3);
                    printfOrdenado("Cliente:",ordenaMenu,4);
                    printfOrdenado("DATA:",30,3);
                    printfOrdenado("Telefone: ", ordenaMenu,5);
                    linha(1,7);
                    printfOrdenado("Descricao: ", ordenaMenu, 9);

                    gotoxy(9,3);
                    fflush(stdin);
                    fgets(novo->tipo,sizeof(novo->tipo),stdin);
                    strtok(novo->tipo, "\n");
                    gotoxy(36,3);
                    fflush(stdin);
                    fgets(novo->data,sizeof(novo->data),stdin);
                    strtok(novo->data, "\n");
                    gotoxy(12,4);
                    fflush(stdin);
                    fgets(novo->nome,sizeof(novo->nome),stdin);
                    strtok(novo->nome, "\n");
                    gotoxy(13,5);
                    fflush(stdin);
                    fgets(novo->telefone,sizeof(novo->telefone),stdin);
                    strtok(novo->telefone, "\n");
                    gotoxy(14,9);
                    fflush(stdin);
                    fgets(novo->obs,sizeof(novo->obs),stdin);
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
            Feedback *aux = inicio;
            FILE *arq = fopen(arquivo,"wb");
            if (arq == NULL)
            {
            printf("Erro ao abrir arquivo\n");
            exit(1);
            }
            while (aux != NULL){
            /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
        */ fwrite(aux,sizeof(Feedback),1,arq);
            aux = aux->proximo;

            }

            fclose(arq);
            }

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|     REGISTRO CADASTRADO COM SUCESSO      |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoCADASTRO();
            printfOrdenado("1. CADASTRAR OUTRO REGISTRO",9,11);
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
                return cadastroReclamacoes();
            }else; break;



                case 2:
                    limparTela();
                    contornoTela();
                    gotoxy(2,3);
                    printfCenter("LISTAR",2);
                    aux = inicio;
                    gotoxy(2,4);
                    printf ("\t%-35s|%-15s\n\n", "NOME", "TIPO");
                    while (aux!=NULL){
                    printf("\n\t%-35s|%-15s\n\t%-35s",aux->nome,aux->tipo,aux->obs);
                    printf("\n\t");
                    for(x=1;x<66;x++){

                        printf("-");
                    }


                    aux=aux->proximo;
                    }
                    system("pause");
                    return 0;

                    limparTela(); break;



                case 4:

                printf("\nPesquisar por nome");
                char nome[41];
                printf("\n\n");
                printf("Digite o nome: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                strtok(nome, "\n");

                Feedback *aux = inicio;
                printf("\nTodos os contatos");
                printf("\n\n\n%-40s|%-15s\n\n", "NOME", "TELEFONE");
                while(aux != NULL){

                if(strcmp(nome, aux->nome) == 0){
                    printf("%-40s|%-15s\n", aux->nome, aux->endereco);
                }
                aux = aux->proximo;
                }

                system("pause");

        break;

         case 0:
                   return main(); break;

        default:
            printf("Opcao Invalida");break;
        }





       }while(ot == 1);












    return 0;

}





