#include <windows.h>
#include <stdio.h>




    void cadastroPedido (){


        typedef struct Pedido {
    int filial;
    char nome [51];
    char cpf [20];
    char telefone [11];
    char email [50];
    char endereco [50];
    char cep[10];
    char obs [120];

    int idade;

    struct Pedido *proximo;

    }Pedido;


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
                        printfOrdenado("Mesa: ",3,3);
                        printfOrdenado("Garcon: ",3,4);
                        printfOrdenado("Itens: ",3,6);
                        printfOrdenado("Total: R$ ",60,19);
                        printfOrdenado("1-Cancelar item",3,18);
                        printfOrdenado("2-Salvar pedido: ",20,18);
                        printfOrdenado("0-Retornar ao Menu: ",20,19);

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
    }
