#include <stdio.h>
#include <stdlib.h>
#include "cabeçalho.h"
#include <locale.h>


void menu(){
    int resposta;
    int ordenaMenu =3;
    int op;



    do {
    contornoTelaComCabeca();
    contornoMenu();
    DataHoraMENU();
    printfCenter("TELA DE MENUS", 1);
    printfOrdenado("1. CADASTRO",3,12);
    printfOrdenado("2. PEDIDOS",3,14);
    printfOrdenado("3. ESTOQUE",3,16);
    printfOrdenado("4. RELATORIOS",44,12);
    printfOrdenado("5. CONTROLE FINANCEIRO",44,14);
    printfOrdenado("6. RECLAMACOES E ELOGIOS",44,16);
    printfOrdenado(C_RED"0. ENCERRAR SESSAO"NONE,61,19);pintar(15);
    printfOrdenado(" Digite a opcao desejada: ",1,19);
    scanf("%d", &op);
    limparTela();
        if(op<0){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(op>=7){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 6 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(op==0){
            system("exit");
        }else;

    switch(op){
        case 1:

                contornoTelaComCabeca();
                printfCenter("TELA DE CADASTROS E CONSULTAS", 1);
                contornoCadastro();
                printfOrdenado("1. CLIENTES",3,10);
                printfOrdenado("2. BEBIDAS",3,12);
                printfOrdenado("3. PIZZAS",3,14);
                printfOrdenado("4. PIZZAIOLOS",3,16);
                printfOrdenado("5. PRODUTOS",3,18);
                printfOrdenado("6. PROMOCOES",44,10);
                printfOrdenado("7. FORNECEDORES",44,12);
                printfOrdenado("8. FUNCIONARIOS",44,14);
                printfOrdenado("9. MATERIA PRIMA",44,16);
                printfOrdenado("10. PROMOCOES",44,18);
                printfOrdenado(C_RED"0- RETORNAR AO MENU"NONE,60,21);pintar(15);
                printfOrdenado("Digite a opcao desejada: ",1,21);
                scanf("%d", &op);
            if(op<0){
                contornoTelaComCabeca();
                printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
            }else if(op>=11){
                contornoTelaComCabeca();
                printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 10 ou letras e simbolos nao sao permitidos."NONE,1,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
            }else if(op==0){
                return menu();
            }else;

                switch (op){
                case 0: return main();break;
                case 1: return cadastroCliente();break;
                case 2: cadastroBebidas();break;
                case 3: cadastroPizzas ();break;
                case 4: cadastroPizzaiolo();break;
                case 5: cadastroProdutos();break;
                case 6: break;
                case 7: cadastroFornecedores();break;
                case 8: cadastroFuncionarios();break;
                case 9: break;
                case 10:break;
                default:contornoTelaComCabeca();

                        break;
                };
                 break;

        case 2:
            printf("TELA PEDIDO");
            system("pause");
             cadastrodePedido();
              break;

        case 3:
            estoque();
            break;

        case 6:
            cadastroReclamacoes();
             break;

        default:contornoTelaComCabeca();
                break;
    };
    contornoTelaComCabeca();
    AsciiArtIMAGEM();
    AsciiArtPIZZA();
    printfOrdenado(C_RED "Deseja continuar logado no programa? Digite 0 p/ SIM ou outro numero p/ NAO: "NONE,2,22);pintar(15);
    gotoxy(79,22);
    scanf(" %d", &resposta);

        if(resposta == 0){
         system("cls");
         return menu();

        }else if(resposta != 0){
            printfOrdenado("\n\t\t\tOk.. Volte Sempre:)\n",3,23);
         gotoxy(12,26);
         system("pause");
         return 0;
        }else;

}while(resposta == '0');
            gotoxy(30,22);
            return 0;
};
