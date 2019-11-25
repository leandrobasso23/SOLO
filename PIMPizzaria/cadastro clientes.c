#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "cabeçalho.h"

 void cadastroCliente (){


    int id_cliente=0;

 typedef struct Cliente {
    int filial;
    char nome [51];
    char cpf [20];
    char telefone [11];
    char email [50];
    char endereco [50];
    char cep[10];
    char obs [120];
    int id;



    struct Cliente *proximo;

    }Cliente;

    Cliente *inicio = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivo = "bancoCliente.bin";

    Cliente *cliente;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (!feof(arq))      /* repetindo até o final do arquivo*/
    {   cliente  = (Cliente*) malloc(sizeof(Cliente));
        int qtd = fread(cliente,sizeof(Cliente),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = cliente;
                cliente->proximo = NULL;
            }
            else{
                Cliente *aux = inicio;
                cliente->proximo = aux;
                inicio = cliente;
            }
        }
    }
    fclose(arq);   /* abriu e leu o arquivo armazenou na memoria e fechou */


    Cliente *aux;
    int ot=0;
    int opp;
    int x=0;



            int op; /* aqui começa */
            int ordenaMenu =3;
            do {
            contornoTelaComCabeca();
            contornoCliente();
            printfCenter("TELA DE CLIENTE",1);
            printfOrdenado("1. Novo cliente",18,8);
            printfOrdenado("2. Listar clientes",16,11);
            printfOrdenado("3. Pesquisar por nome",45,8);
            printfOrdenado(C_RED"0-Retornar ao Menu"NONE,61,19);pintar(15);
            printfOrdenado("Digite a opcao desejada: ",15,15);
            scanf("%d", &opp);
            limparTela();
            if(opp<0){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
            return 0;
        }else if(opp>=5){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 4 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
            return 0;
        }else if(opp==0){
            return menu();
        };


            switch (opp){
            case 1:


            limparTela();
            printf("\nAdicionar");

            Cliente *novo = (Cliente*) malloc(sizeof(Cliente));

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

            printfOrdenado("Nome: ",ordenaMenu,5);


            printfOrdenado("CPF: ",ordenaMenu,6);


            printfOrdenado("Cep: ", ordenaMenu,7);


            printfOrdenado("Telefone: ",ordenaMenu,8);


            printfOrdenado("Endereco: ",ordenaMenu,9);


            printfOrdenado("Observacao: ",ordenaMenu, 12);


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
            gotoxy(16,12);
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
            Cliente *aux = inicio;
            FILE *arq = fopen(arquivo,"wb");
            if (arq == NULL)
            {
            printf("Erro ao abrir arquivo\n");
            exit(1);
            }
            while (aux != NULL){
            /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
        */ fwrite(aux,sizeof(Cliente),1,arq);
            aux = aux->proximo;

            }

            fclose(arq);
            }

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|      CLIENTE CADASTRADO COM SUCESSO      |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoCADASTRO();
            printfOrdenado("1. CADASTRAR OUTRO CLIENTE",9,11);
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
        }else;


            if (ot==0){
                return menu();
            } break;



                case 2:
                    limparTela();
                    contornoTela();
                    gotoxy(2,3);
                    printfCenter("LISTAR",2);
                    aux = inicio;
                    gotoxy(2,4);
                    printf ("\t%-35s|%-15s\n\n", "NOME", "ENDERECO");
                    while (aux!=NULL){
                    printf("\t%-35s|%-15s\n",aux->nome,aux->endereco);
                    aux=aux->proximo;

                    } printfOrdenado("Aperte 0 para sair: ",35,19);
                    scanf("%d",&opp);

                    if (opp== 0){
                    return cadastroCliente();
                    }
                    limparTela(); break;



                case 3:

                printf("\nPesquisar por nome");
                char nome[41];
                printf("\n\n");
                printf("Digite o nome: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                strtok(nome, "\n");

                Cliente *aux = inicio;
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

        default:contornoTelaComCabeca();
                AsciiArtIMAGEM();
                AsciiArtPIZZA();
                                   break;
        }


       }while(ot == 1);
        free(cliente);

    return 0;

};



