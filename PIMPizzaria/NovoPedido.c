#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cadastrodePedido(){


    char temp1 [50];
    int tempQ;
    float tempV =0;
    float tempT[4];
    char tempCli [50];
    char tempEnd [50];

    /* Pedidos struct responsavel por amarzernar em Fila os pedidos */



    typedef struct Pedido {
    int id;
    char Cliente [51];
    char endereco [100];
    char Mesa [10];
    char categoria [10];
    char item00 [20];
    char item01 [20];
    char item02 [20];
    char item03 [20];
    char item04 [20];
    float valorItem [4];
    float valorTotal;
    char hora [5];


    struct Pedido *seguinte

    }PedidosGerados;


        PedidosGerados *comeco = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivoped = "ArqPedidos.bin";

    PedidosGerados *pedger;
    FILE *arqped = fopen(arquivoped,"w+b");
    if (arqped == NULL)
    {
        limparTela();
        contornoTela();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    }

    while (!feof(arqped))      /* repetindo até o final do arquivo*/
    {   pedger  = (PedidosGerados*) malloc(sizeof(PedidosGerados));
        int qtdped = fread(pedger,sizeof(PedidosGerados),1,arqped);
        if(qtdped > 0){
            if(comeco == NULL){
                comeco = pedger;
                pedger->seguinte = NULL;
            }
            else{
                PedidosGerados *auxped = comeco;
                pedger->seguinte = auxped;
                comeco = pedger;
            }
        }
    }
    fclose(arqped);   /* abriu e leu o arquivo armazenou na memoria e fechou */



   PedidosGerados *auxped;


        PedidosGerados *novoped = (PedidosGerados*) malloc(sizeof(PedidosGerados));

            novoped->seguinte=NULL;



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
        system("\npause");
        return;
    }

    while (!feof(arq))      /* repetindo até o final do arquivo */
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
    fclose(arq);



typedef struct Bebidas {
    int filial;
    char nome [51];
    char categoria [10];
    float precoCusto;
    int imposto;
    int despesas;
    int lucro;
    float precoVenda;
    float precoEst;
    int estoqueAtual;
    int novoEstoque;
    char fornecedor [50];
    char obs [120];



    struct Bebidas *proximoBebida;

    }Bebidas;




    Bebidas *inicioBebida = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivoBebida = "teste.bin";

    Bebidas *bebidas;
    FILE *arqBebida = fopen(arquivoBebida,"r+b");
    if (arqBebida == NULL)
    {
        limparTela();
        contornoTela();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    }

    while (!feof(arqBebida))      /* repetindo até o final do arquivo*/
    {   bebidas  = (Bebidas*) malloc(sizeof(Bebidas));
        int qtd1 = fread(bebidas,sizeof(Bebidas),1,arqBebida);
        if(qtd1 > 0){
            if(inicioBebida == NULL){
                inicioBebida = bebidas;
                bebidas->proximoBebida = NULL;
            }
            else{
                Bebidas *aux1 = inicioBebida;
                bebidas->proximoBebida = aux1;
                inicioBebida = bebidas;
            }
        }
    }
    fclose(arqBebida);   /* abriu e leu o arquivo armazenou na memoria e fechou */



            int x;
            int opii;
            int ordenaMenu =3;
            do {
            contornoTelaComCabeca();
            printfCenter("TELA DE PEDIDO",1);
            printfOrdenado("1-Novo pedido",ordenaMenu,3);
            printfOrdenado("2-Listar pedidos em aberto",ordenaMenu,4);
            printfOrdenado("3-Listar pedidos ja concluidos",ordenaMenu,5);
            printfOrdenado("0-Retornar ao Menu",ordenaMenu,19);
            printfOrdenado("Executar: ",ordenaMenu,8);
            scanf("%d", &opii);
            limparTela();

            switch(opii){
            case 0:
                ;break;
            case 1:
                        contornoTelaComCabeca();
                        printfCenter("NOVO PEDIDO - MESA",1);
                        printfOrdenado("Cliente: ",3,3);
                        printfOrdenado("Endereço: ",3,4);
                        linha(1,5);
                        gotoxy(3,6);
                        printf ("\t%-30s|%-15s|%-5s|%-5s\n\n", "ITEM", "QUANTIDADE", "V. UNI", "VALOR TOTAL");
                        gotoxy(3,7);
                        for(x=0;x<9;x++){
                            printf ("\t%-30s%-16s%-7s%-5s\n", "", "|", "|", "|");
                        }

                        /* PESQUISA CLIENTE*/
                                gotoxy(12,3);
                                fflush(stdin);
                                scanf("%s", &tempCli);
                                strtok(temp1, "\n");

                                Cliente *aux = inicio;
                                while(aux != NULL){

                                if(strcmp(tempCli, aux->nome) == 0){

                                    gotoxy(14,4);
                                    printf("%s", aux->endereco);
                                }
                                aux = aux->proximo;
                                }
                                   /* strcpy(auxped->Cliente,aux->nome);
                                    strcpy(auxped->endereco,aux->endereco);*/


                        /* ITEM 1*/



                                printfOrdenado("1|",2,7);
                                fflush(stdin);
                                scanf("%s", &temp1);
                                strtok(temp1, "\n");

                                Bebidas *aux1 = inicioBebida;
                                while(aux1 != NULL){

                                if(strcmp(temp1, aux1->nome) == 0){

                                tempV = aux1->precoVenda;
                                gotoxy(55,7);
                                printf("%.2f", tempV);
                                gotoxy(40,7);
                                scanf("%d", &tempQ);
                                tempT[0] = tempQ*tempV;
                                gotoxy(63,7);
                                printf("%.2f", tempT[0]);


                                }
                                aux1 = aux1->proximoBebida;
                                                }
                                strcpy(novoped->item00,temp1);




                        /* ITEM 2*/
                                printfOrdenado("2|",2,8);
                                fflush(stdin);
                                scanf("%s", &temp1);
                                strtok(temp1, "\n");
                                aux1=inicioBebida;
                                while(aux1 != NULL){

                                if(strcmp(temp1, aux1->nome) == 0){

                                tempV = aux1->precoVenda;
                                gotoxy(55,8);
                                printf("%.2f", tempV);
                                gotoxy(40,8);
                                scanf("%d", &tempQ);
                                tempT[1] = tempQ*tempV;
                                gotoxy(63,8);
                                printf("%.2f", tempT[1]);

                                }
                                aux1 = aux1->proximoBebida;
                                                }
                                strcpy(novoped->item01,temp1);

                        /* ITEM 3*/
                                printfOrdenado("3|",2,9);
                                fflush(stdin);
                                scanf("%s", &temp1);
                                strtok(temp1, "\n");
                                aux1=inicioBebida;
                                while(aux1 != NULL){

                                if(strcmp(temp1, aux1->nome) == 0){

                                tempV = aux1->precoVenda;
                                gotoxy(55,9);
                                printf("%.2f", tempV);
                                gotoxy(40,9);
                                scanf("%d", &tempQ);
                                tempT[2] = tempQ*tempV;
                                gotoxy(63,9);
                                printf("%.2f", tempT[2]);

                                }
                                aux1 = aux1->proximoBebida;
                                                }
                                strcpy(novoped->item02,temp1);

                        /* ITEM 4*/
                                printfOrdenado("4|",2,10);
                                fflush(stdin);
                                scanf("%s", &temp1);
                                strtok(temp1, "\n");
                                aux1=inicioBebida;
                                while(aux1 != NULL){

                                if(strcmp(temp1, aux1->nome) == 0){

                                tempV = aux1->precoVenda;
                                gotoxy(55,10);
                                printf("%.2f", tempV);
                                gotoxy(40,10);
                                scanf("%d", &tempQ);
                                tempT[3] = tempQ*tempV;
                                gotoxy(63,10);
                                printf("%.2f", tempT[3]);

                                }
                                aux1 = aux1->proximoBebida;
                                                }
                                strcpy(novoped->item03,temp1);

                        /* ITEM 5*/
                                printfOrdenado("5|",2,11);
                                fflush(stdin);
                                scanf("%s", &temp1);
                                strtok(temp1, "\n");
                                aux1=inicioBebida;
                                while(aux1 != NULL){

                                if(strcmp(temp1, aux1->nome) == 0){

                                tempV = aux1->precoVenda;
                                gotoxy(55,11);
                                printf("%.2f", tempV);
                                gotoxy(40,11);
                                scanf("%d", &tempQ);
                                tempT[4] = tempQ*tempV;
                                gotoxy(63,11);
                                printf("%.2f", tempT[4]);

                                }
                                aux1 = aux1->proximoBebida;
                                                }
                                strcpy(novoped->item04,temp1);

                                strcpy(novoped->Cliente,aux->nome);



                            int x;
                            float valorFinal=0;
                            for(x=0;x<=4;x++){
                                valorFinal += tempT[x];
                            }






                        gotoxy(60,19);
                        printf("Total R$ %.2f ",valorFinal);
                        printfOrdenado("1-Cancelar item",3,18);
                        printfOrdenado("2-Salvar pedido: ",20,18);
                        printfOrdenado("0-Retornar ao Menu: ",20,19);

                        /*gotoxy(10,3);
                        scanf("%d", &ped->mesa);
                        gotoxy(12,4);
                        fflush(stdin);
                        fgets(ped->garcon,sizeof(ped->garcon),stdin);



                        fflush(stdin);
                        fgets(novo->endereco ,sizeof(novo->endereco),stdin);
                        strtok(novo->endereco, "\n");*/

                        scanf("%d", &opii);
                        limparTela();

                        contornoTela();
                        printfCenter("PEDIDO SALVO COM SUCESSO!",10);
                        printfOrdenado("Aperte 0 para continuar: ",3,12);
                        scanf("%d", &opii);

                         break;
            case 2: break;

            case 3: break;
             }

            }while (opii==2);
            free(bebidas);
            free(cliente);
            free(pedger);
    }
