 #include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include "cabeçalho.h"

void cadastroPizzas(){




 typedef struct Pizzas {
    int filial;
    char sabor [51];
    char status [20];
    char tamanho [11];
    float custo ;
    int lucro;
    char composicao [120];
    int id;
    float precovenda;



    struct Pizzas *proximo;

    }Pizzas;

    Pizzas *inicio = NULL;

    char *arquivo = "bancoPizzas.bin";

    Pizzas *pizzas;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    while (!feof(arq))
    {   pizzas  = (Pizzas*) malloc(sizeof(Pizzas));
        int qtd = fread(pizzas,sizeof(Pizzas),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = pizzas;
                pizzas->proximo = NULL;
            }
            else{
                Pizzas *aux = inicio;
                pizzas->proximo = aux;
                inicio = pizzas;
            }
        }
    }
    fclose(arq);


    Pizzas *aux;
    int ot=0;
    int opp;
    int x=0;



            int op;
           int ordenaMenu =8;
            do {
            contornoTelaComCabeca();
            contorno_BePeP();
            printfCenter("CADASTRO DE PIZZAS",1);
            printfOrdenado("1. NOVO SABOR",8,ordenaMenu);
            printfOrdenado("2. LISTAR SABORES",31,ordenaMenu);
            printfOrdenado("3. REMOVER SABORES",57,ordenaMenu);
            printfOrdenado(C_RED"0. RETORNAR AO MENU"NONE,61,19);pintar(15);
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

            Pizzas *novo = (Pizzas*) malloc(sizeof(Pizzas));

            novo->proximo=NULL;


            aux = inicio;
            ordenaMenu =3;
            novo->id += 1;
            contornoTelaComCabeca();

            printfCenter("Novo Sabor",1);
            gotoxy(3,4);
            printf("ID: %d", novo->id);
            printfOrdenado("Filial: ",15,4);
            scanf("%d", &novo->filial);

            gotoxy(0,2);
            regua();

            printfOrdenado("Sabor: ",ordenaMenu,5);


            printfOrdenado("Status (ativa\\inativa): ",ordenaMenu,6);

            printfOrdenado("Tamanho: ",ordenaMenu,8);


            printfOrdenado("Custo estimado: ",ordenaMenu,9);

            printfOrdenado("lucro estimado % : ",ordenaMenu,10);








            gotoxy(10,5);
            fflush(stdin);
            fgets(novo->sabor ,sizeof(novo->sabor),stdin);
            strtok(novo->sabor, "\n");
            gotoxy(27,6);
            scanf("%20s", novo->status);
            gotoxy(13,8);
            scanf("%11s", novo->tamanho);
            gotoxy(20,9);
            scanf("%f", &novo->custo);
            gotoxy(22,10);
            scanf("%d", &novo->lucro);



            gotoxy(3,11);
            printf("LUCRO estipulado em R$ %.2f",novo->custo/100*(novo->lucro));
            gotoxy(3,12);
            printf("Preco estipulado em R$%.2f repita o preco se estiver de acordo: ", (novo->custo/100*(novo->lucro))+novo->custo );
            scanf("%f", &novo->precovenda);









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




        if(inicio != NULL){
    Pizzas *aux = inicio;
    FILE *arq = fopen(arquivo,"wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    while (aux != NULL){

        fwrite(aux,sizeof(Pizzas),1,arq);
        aux = aux->proximo;

    }

    fclose(arq);
    }

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|     NOVA PIZZA CADASTRADA COM SUCESSO    |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoCADASTRO();
            printfOrdenado("1. CADASTRAR OUTRO SABOR",9,11);
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
                return cadastroPizzas();
            }else;
            break;



                case 2:
                    limparTela();
                    contornoTela();
                    gotoxy(2,3);
            printfCenter("LISTAR",3);
            aux = inicio;
            gotoxy(2,4);
            printf ("\n\tFilial\tPizza\t\t\tValor");
            while (aux!=NULL){
                printf("\n\t%d\t%s\t\t\tR$%.2f", aux->filial, aux->sabor,aux->precovenda);
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




