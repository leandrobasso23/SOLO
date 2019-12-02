 #include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include "cabeçalho.h"


void pedidos(){

    int Opcao;
    int resposta;
    int Op, Op02;


contornoTelaComCabecaPedidos();
system("cls");
contornoTelaComCabecaPedidos();

contornoPedido();
        printfOrdenado("\t\t\t\tTELA DE PEDIDOS ",2,1);
        printfOrdenado(" 1. NOVO PEDIDO ",3,10);
        printfOrdenado(" 2. PEDIDO EM ANDAMENTO ", 3,12);
        printfOrdenado(" 3. PEDIDO CONCLUIDO ",3,14);
        printfOrdenado(" 4. PESQUISAR POR NOME DO CLIENTE",3,16);
        printfOrdenado(" 5. LISTAR PEDIDOS DE MESA",44,10);
        printfOrdenado(" 6. LISTAR PEDIDOS DE RETIRADA",44,12);
        printfOrdenado(" 7. LISTAR PEDIDOS DE ENTREGA",44,14);
        printfOrdenado(" 8. ",44,16);
        printfOrdenado(C_RED" 0. RETORNAR AO MENU "NONE,59,19);pintar(15);
        printfOrdenado(" Digite a opcao desejada: ",1,19);
        scanf("%d", &Op);
                                             system("cls");
contornoTelaComCabecaPedidos();
        if(Op<0){
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
            return 0;
        }else if(Op>=9){
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 8 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
            return 0;
        }else if(Op==0){
            return menu();
        }else;

    switch(Op){contornoTelaComCabecaPedidos();

    case 1: contornoTelaComCabecaPedidos();
contorno_M_E_R();
            printfOrdenado(C_BLUE"|***************************** TIPO DE PEDIDO ****************************|"NONE,3,3);pintar(15);
contornoMenu02();
            printfOrdenado(" 1. MESA",14,8);
            printfOrdenado(" 2. RETIRAR",34,8);
            printfOrdenado(" 3. ENTREGA",55,8);
            printfOrdenado(C_RED" 0. RETORNAR AO MENU"NONE,59,19);pintar(15);
            printfOrdenado("  Digite a opcao desejada: ",11,13);
            scanf("%d", &Op02);
                                             system("cls");
contornoTelaComCabecaPedidos();
        if(Op02<0){
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
            return 0;
        }else if(Op02>=4){
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 3 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
            return 0;
        }else if(Op02==0){
            return menu();
        }else;
                                break;
    case 2: CasePedidoAndamento();
                                break;
    case 3: CasePedidoConcluido();
                                break;
    case 4: contornoMenu06();
            printfOrdenado("1. PESQUISAR POR CLIENTE DE RETIRADA",2,6);
            printfOrdenado("2. PESQUISAR POR CLIENTE DE ENTREGA",43,6);
            /*printfOrdenado("3. PESQUISAR POR NUMERO DE MESA",27,9);*/
            printfOrdenado(C_RED" 0. VOLTAR AO MENU "NONE,59,19);pintar(15);
            printfOrdenado("Digite a opcao desejada: ",2,10);
            scanf("%d", &Opcao);
        if(Opcao == 2){
             CasePesquisarPorNomeEnt();
contornoTelaComCabecaPedidos();
                gotoxy(12,12);
                system("pause");
                system("cls");
        }else if(Opcao == 1){
             CasePesquisarPorNomeRet();
contornoTelaComCabecaPedidos();
                gotoxy(12,12);
                system("pause");
                system("cls");
        }else if(Opcao<0){
             system("cls");
contornoTelaComCabecaPedidos();
             printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos."NONE,1,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
        }else if(Opcao>=3){
                system("cls");
contornoTelaComCabecaPedidos();
             printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
            return 0;
        }else if(Opcao==0){
            return menu();
        }else;
                                break;
    case 5: CaseListarMesa();
            system("pause");
            system("cls");
                                break;
    case 6: CaseListarRetirada();
            system("pause");
            system("cls");
                                break;
    case 7: CaseListarEntrega();
            system("pause");
            system("cls");
                                break;
    case 8: AsciiArtIMAGEM();
            AsciiArtPIZZA();
                                break;
    default: contornoTelaComCabecaPedidos();
                                break;
};
    switch(Op02){contornoTelaComCabecaPedidos();

    case 1: CaseNovoPedidoMesa();
                                break;
    case 2: CaseNovoPedidoRetirar();
                                break;
    case 3: CaseNovoPedidoEntrega();
                                break;
    default: contornoTelaComCabecaPedidos();
                                break;
};

};

/*Sub Funcões-->*/

void CasePedidoAndamento(){
contornoTelaComCabecaPedidos();

typedef struct Andamento{
    int QtdPedidoAnd;
    struct Andamento *proximo;
}Andamento;

Andamento *inicio = NULL;

    char *arquivo = "BancoAndamento.bin";

    Andamento *andamento;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };

    while (!feof(arq)){
        andamento  = (Andamento*) malloc(sizeof(Andamento));
        int qtd = fread(andamento,sizeof(Andamento),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = andamento;
                andamento->proximo = NULL;
            }else{
                Andamento *aux = inicio;
                andamento->proximo = aux;
                inicio = andamento;
            };
        };
    };
    fclose(arq);

    Andamento *aux;

    int Opp;
    int op;
    int ott;
    int opp;
    int ordenaMenu =3;
    int x;

    do {

contornoTelaComCabecaPedidos();
contornoMenu07();
            printfOrdenado("1. NOVO PEDIDO EM ANDAMENTO",10,8);
            printfOrdenado("2. LISTAR PEDIDO EM ANDAMENTO",45,8);
            printfOrdenado(C_RED" 0. VOLTAR AO MENU"NONE,59,19);pintar(15);
            printfOrdenado("  Digite a opcao desejada: ",6,13);
            scanf("%d", &Opp);
            system("cls");
        if(Opp <0){
contornoTelaComCabecaPedidos();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
        }else if(Opp >=3){
contornoTelaComCabecaPedidos();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
        }else if(Opp == 0){
            return menu();
        }else;

        if(Opp==1){
            system("cls");
contornoTelaComCabecaPedidos();

            Andamento *novo = (Andamento*) malloc(sizeof(Andamento));

            novo->proximo=NULL;

            aux = inicio;

            printfOrdenado(C_RED"*NUMERO MAXIMO DE CADASTRO POR EXECUCAO DO PROGRAMA: 11.",1,19);
            printfOrdenado(" 0. SAIR"NONE,70,19);pintar(15);
            printfOrdenado(C_BLUE"______________________________________________________________"NONE,3,6);pintar(15);
            printfOrdenado("Quantos Pedidos deseja cadastrar para o processo de Andamento?: ",3,5);
            scanf("%d", &novo->QtdPedidoAnd);
            if(novo->QtdPedidoAnd>=12){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"Ops...\n  \aNumero digitado excedeu o numero max de cadastros por executacao do programa."NONE,2,8);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else if(novo->QtdPedidoAnd<0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\aNumeros negativos ou letras nao sao permitidos."NONE,3,8);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else if(novo->QtdPedidoAnd==0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\t\aNumero 0 ou letras nao sao permitidos."NONE,3,8);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else;
                                    system("cls");

if (inicio == NULL){
            inicio = novo;
            }else{

            while(aux->proximo!=NULL){
                aux=aux->proximo;
            };
            aux ->proximo = novo;
};
        int y;
        int Pedido_And[novo->QtdPedidoAnd];
        char Pedido_Tipo[novo->QtdPedidoAnd];


        for(x=0;x<novo->QtdPedidoAnd;x++){
contornoTelaComCabecaPedidos();
            printfOrdenado(C_BLUE"************************** PEDIDO EM ANDAMENTO **************************"NONE,3,9);pintar(15);
            printfOrdenado("|_______________|_________________________________________________________",2,8);
contorno_AND_CONC();
            printfOrdenado(" _______________", 2,3);
            printfOrdenado("|     TIPO      |",2,4);
            printfOrdenado("| M p/ MESA     |",2,5);
            printfOrdenado("| E p/ ENTREGA  |",2,6);
            printfOrdenado("| R p/ RETIRADA |",2,7);
            printfOrdenado(C_RED"*NUMERO MAXIMO DE PEDIDO POR EXECUCAO DO PROGRAMA: 500."NONE,1,19);pintar(15);
            gotoxy(28,12);
            printf("PEDIDO LOTE N.(%d): ", x);
            scanf("%d", &Pedido_And[x]);
            gotoxy(28,13);
            printf("TIPO   LOTE N.(%d): ", x);
            scanf("%s", &Pedido_Tipo[x]);

            };
                                    system("CLS");

            if(Pedido_And <0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\aOps...\n   No campo PEDIDO e permitido apenas numeros positivos."NONE,3,5);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else if(Pedido_And >=500){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\aErro!Nao sao permitidos letras, simbolos ou numero maior que 500 no campo MESA."NONE,1,5);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else if(Pedido_And == 0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\a0 nao e um numero valido p/ cadastrar no campo PEDIDO."NONE,3,5);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else if(Pedido_Tipo != 'm' && Pedido_Tipo != 'M' &&
                      Pedido_Tipo != 'r' && Pedido_Tipo != 'R' &&
                       Pedido_Tipo != 'e' && Pedido_Tipo != 'E'){
                printfOrdenado(C_RED"Ops...\n   \aNo campo TIPO e permitido apenas letras:(M,E,R)."NONE,3,5);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else;

        for(x=0;x<novo->QtdPedidoAnd;x++){
            gotoxy(3,5);
            printf("TOTAL DE PEDIDOS EM ANDAMENTO: %d",x+1);
            gotoxy(3,7);
            printf("Segue abaixo as informacoes dos Pedidos cadastrados em Andamento:\n");
        };
        for(x=0;x<novo->QtdPedidoAnd;x++){
            printf("\t\tLOTE(%d) - PEDIDO: %d\tTIPO: %c\n", x, Pedido_And[x], Pedido_Tipo[x]);
        };

                                        /* Abrindo arquivo  para gravar os dados*/
        if(inicio != NULL){
         Andamento *aux = inicio;
         FILE *arq = fopen(arquivo,"wb");
       if (arq == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    };
    while (aux != NULL){
        /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
       */ fwrite(aux,sizeof(Andamento),1,arq);
        aux = aux->proximo;

    };

    fclose(arq);  /* apagou o arquivo antigo e salvou tudo que esta na memoria, normalmente os dados antigos esta na memoria ainda.*/
    };

    system("cls");
        contornoTelaComCabecaPedidos();

            printfOrdenado(C_GREEN"|**********************************************|",18,4);
                   printfOrdenado("|                                              |"NONE,18,5);pintar(15);
            printfOrdenado(C_BLACK"|  PEDIDO EM ANDAMENTO CADASTRADO COM SUCESSO  |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                              |",18,7);
                   printfOrdenado("|**********************************************|"NONE,18,8);pintar(15);
contornoMenu04();
            printfOrdenado("1. CADASTRAR OUTRO PEDIDO CONCLUIDO",2,11);
            printfOrdenado("2. LISTAR PEDIDOS CONCLUIDOS",47,11);
            printfOrdenado(C_RED" 0. RETORNAR AO MENU"NONE,59,19);pintar(15);
            printfOrdenado("Escolha a opcao desejada: ",3,14);
            scanf("%d", &opp);
            system("cls");
            if(opp==1){
                return CasePedidoAndamento();
            }else if(opp<0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"Ops...\n   \aNumeros negativos ou letras e simbolos nao sao permitidos."NONE,3,8);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else if(opp>=3){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else if(opp==0){
                return menu();
            }else;

            }else if(Opp==2){
            system("cls");
                    contornoTelaComCabecaPedidos();
                    printfOrdenado("LISTAR",2,3);
                    aux = inicio;
                    gotoxy(5,10);
                    printf("\t%-15s|%-15s\n", "NOME", "PRECO");
                    while (aux!=NULL){
                    printf("\t%-15d\n",aux->QtdPedidoAnd);
                    aux=aux->proximo;
                    };
                    gotoxy(12,17);
                    system("pause");
                    system("cls");
            }else if(opp<0){
contornoTelaComCabecaPedidos();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(5,12);
            system("pause");
            system("cls");
            return 0;
            }else if(opp>=3){
contornoTelaComCabecaPedidos();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(5,12);
            system("pause");
            system("cls");
            return 0;
            }else;

            switch (opp){
            case 2:
               system("cls");
                    contornoTelaComCabecaPedidos();
                    printfOrdenado("LISTAR",2,3);
                    aux = inicio;
                    gotoxy(2,4);
                    printf("\t%-15s|%-15s\n\n", "NOME", "PRECO");
                    while (aux!=NULL){
                    printf("\t%-15d\n",aux->QtdPedidoAnd);
                    aux=aux->proximo;
                    };
                    break;

 };
 }while(ott == 1);

return 0;

};

void CasePedidoConcluido(){



typedef struct Concluido{
    int QtdPedidoConc;
    float Soma;

    struct Concluido *proximo;
}Concluido;

Concluido *inicio = NULL;

    char *arquivo = "BancoConcluido.bin";

    Concluido *concluido;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };

    while (!feof(arq)){
        concluido  = (Concluido*) malloc(sizeof(Concluido));
        int qtd = fread(concluido,sizeof(Concluido),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = concluido;
                concluido->proximo = NULL;
            }else{
                Concluido *aux = inicio;
                concluido->proximo = aux;
                inicio = concluido;
            };
        };
    };
    fclose(arq);

    Concluido *aux;
    int ott=0;
    int opp;
    int xx=0;
    int Opp;

            int op;
            int ordenaMenu =3;
            do {
contornoTelaComCabecaPedidos();
contornoMenu03();
            printfOrdenado("1. NOVO PEDIDO CONCLUIDO",10,8);
            printfOrdenado("2. LISTAR PEDIDO CONCLUIDO",45,8);
            printfOrdenado(C_RED" 0. RETORNAR AO MENU"NONE,59,19);pintar(15);
            printfOrdenado("  Digite a opcao desejada: ",6,13);
            scanf("%d", &opp);
            system("cls");

            if(opp==1){
            system("cls");
contornoTelaComCabecaPedidos();
            Concluido *novo = (Concluido*) malloc(sizeof(Concluido));

            novo->proximo=NULL;

            aux = inicio;

            printfOrdenado(C_RED"*NUMERO MAXIMO DE CADASTRO POR EXECUCAO DO PROGRAMA EH 11."NONE,1,19);pintar(15);
            printfOrdenado("________________________________________________",3,6);
            printfOrdenado("Quantos Pedidos deseja cadastrar nos Concluidos?: ",3,5);
            scanf("%d", &novo->QtdPedidoConc);
            if(novo->QtdPedidoConc<0){
                printfOrdenado(C_RED"Ops...\n   \aNumeros negativos ou letras nao sao permitidos."NONE,3,8);
                gotoxy(5,12);
                system("pause");
                system("cls");
                return 0;
            }else if(novo->QtdPedidoConc>=12){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\aNumero digitado excedeu o numero max de cadastros por execucao do programa."NONE,3,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else if(novo->QtdPedidoConc==0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\t\aNumero 0 ou letras nao sao permitidos."NONE,3,8);
                gotoxy(7,12);
                system("pause");
                system("cls");
                return 0;
            }else;
                                    system("cls");

    int Pedido_Concluido[novo->QtdPedidoConc];
    float Valor[novo->QtdPedidoConc];
    int i;


    contornoTelaComCabecaPedidos();
        for(i=0;i<novo->QtdPedidoConc;i++){
            printfOrdenado(C_BLUE"*************************** PEDIDOS CONCLUIDOS **************************"NONE,3,7);pintar(15);
            printfOrdenado("_________________________________________________________________________",3,6);
            printfOrdenado(C_RED"*NUMERO MAXIMO DE PEDIDO POR EXECUCAO DO PROGRAMA: 500."NONE,1,19);pintar(15);
contornoTelaComCabecaPedidos();
contorno_AND_CONC();
            gotoxy(28,12);
            printf("PEDIDO LOTE N.(%d): ", i);
            scanf("%d", &Pedido_Concluido[i]);
            gotoxy(28,13);
            printf("VALOR  LOTE N.(%d): ", i);
            scanf("%f", &Valor[i]);
                                        system("cls");
            if(Pedido_Concluido[i]<0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"Ops...\n   \aNo campo PEDIDO e permitido apenas numeros positivos."NONE,3,5);
                gotoxy(12,17);
                system("pause");
                system("cls");
                return 0;
            }else if(Pedido_Concluido[i]>500){
contornoTelaComCabecaPedidos();
                 printfOrdenado(C_RED"\aErro!Nao sao permitidos letras, simbolos ou numero maior que 500 no campo PEDIDO."NONE,1,5);
                 gotoxy(12,17);
                 system("pause");
                 system("cls");
                 return 0;
            }else if(Pedido_Concluido[i] == 0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\a0 nao e um numero valido p/ cadastrar no campo PEDIDO."NONE,3,5);
                gotoxy(12,17);
                system("pause");
                system("cls");
                return 0;
            }else if(Valor[i]<0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\aValor invalido!"NONE,25,15);
                gotoxy(12,17);
                system("pause");
                system("cls");
                return 0;
            }else if(Valor[i]>500){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"Ops...\n   \aValor excedeu ao numero de valor definido pelo desenvolvedor."NONE,3,5);
                gotoxy(12,17);
                system("pause");
                system("cls");
                return 0;
            }else;
            };
            for(i=0;i<novo->QtdPedidoConc;i++){
                gotoxy(3,5);
                printf("TOTAL DE PEDIDOS CONCLUIDOS: %d", i+1);
            printfOrdenado("Segue abaixo o Valor Total dos Pedidos ja concluidos\n: ",3,7);
            };
            for(i=0;i<novo->QtdPedidoConc;i++){
                novo->Soma+=Valor[i];
                gotoxy(3,9);
                printf("VALOR TOTAL: R$%0.2f", novo->Soma);
            };


            if (inicio == NULL){
            inicio = novo;
            }else{

            while(aux->proximo!=NULL){
                aux=aux->proximo;
            };
            aux ->proximo = novo;
};


                                /* Abrindo arquivo  para gravar os dados*/
        if(inicio != NULL){
         Concluido *aux = inicio;
         FILE *arq = fopen(arquivo,"wb");
       if (arq == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    };
    while (aux != NULL){
        /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
       */ fwrite(aux,sizeof(Concluido),1,arq);
        aux = aux->proximo;

    };

    fclose(arq);  /* apagou o arquivo antigo e salvou tudo que esta na memoria, normalmente os dados antigos esta na memoria ainda.*/
    };

    system("cls");
        contornoTelaComCabecaPedidos();

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"| PEDIDO CONCLUIDO CADASTRADO COM SUCESSO  |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoMenu04();
            printfOrdenado("1. CADASTRAR OUTRO PEDIDO CONCLUIDO",2,11);
            printfOrdenado("2. LISTAR PEDIDOS CONCLUIDOS",47,11);
            printfOrdenado(C_RED" 0. RETORNAR AO MENU"NONE,59,19);pintar(15);
            printfOrdenado("Digite a opcao desejada: ",3,14);
            scanf("%d", &Opp);
            system("cls");
            if(Opp==1){
                return CasePedidoConcluido();
            }else if(Opp<0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\aOps...\n\tNumeros negativos ou letras e simbolos nao sao permitidos."NONE,3,8);
                gotoxy(12,17);
                system("pause");
                system("cls");
                return 0;
            }else if(Opp>=3){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
                gotoxy(12,17);
                system("pause");
                system("cls");
                return 0;
            }else if(Opp==0){
                return menu();
            }else;

            }else if(opp==2){
            system("cls");
                    contornoTelaComCabecaPedidos();
                    printfOrdenado("LISTAR",2,3);
                    aux = inicio;
                    gotoxy(5,10);
                    printf("\t%-d|%-f\n", "NOME", "PRECO");
                    while (aux!=NULL){
                    printf("\t%-d|%-0.2f|\n",aux->QtdPedidoConc,aux->Soma);
                    aux=aux->proximo;
                    };
                    gotoxy(12,17);
                    system("pause");
                    system("cls");
            }else if(opp<0){
contornoTelaComCabecaPedidos();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,17);
            system("pause");
            system("cls");
            return 0;
            }else if(opp>=3){
contornoTelaComCabecaPedidos();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,17);
            system("pause");
            system("cls");
            return 0;
            }else if(opp==0){
                return menu();
            }else;

            switch (Opp){
            case 2:
               system("cls");
                    contornoTelaComCabecaPedidos();
                    printfOrdenado("LISTAR",2,3);
                    aux = inicio;
                    gotoxy(2,4);
                    printf("\t%-d|%-f\n\n", "NOME", "PRECO");
                    while (aux!=NULL){
                    printf("\t%-d|%-0.2f\n",aux->QtdPedidoConc,aux->Soma);
                    aux=aux->proximo;
                    };
                    gotoxy(12,17);
                    system("pause");
                    system("cls");
                    break;

 };
 }while(ott == 1);

    return 0;
};

void CaseListarMesa();

void CaseNovoPedidoMesa(){
   typedef struct CadNovo{
    char Nome_Garcom[50];
    int Mesa;
    char Item[100];
    float Total;

    struct CadNovo *proximo;

}CadNovo;

CadNovo *inicio = NULL;
    char *arquivo = "BancoNovoMesa.bin";
CadNovo *cadnovo;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        cadnovo  = (CadNovo*) malloc(sizeof(CadNovo));
    int qtd = fread(cadnovo,sizeof(CadNovo),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = cadnovo;
        cadnovo->proximo = NULL;
    }else{
        CadNovo *aux = inicio;
        cadnovo->proximo = aux;
        inicio = cadnovo;
        };
        };
        };
    fclose(arq);

    CadNovo *aux;
    int mesa;
    CadNovo *novo = (CadNovo*) malloc(sizeof(CadNovo));
        novo->proximo=NULL;
        aux = inicio;

contornoTelaComCabecaPedidos();
contorno_M_E_R();
            printfOrdenado(C_BLUE"|*************************** NOVO PEDIDO - MESA **************************"NONE,3,3);pintar(15);
            printfOrdenado("Garcom: ",6,5);
            fflush(stdin);
            fgets(novo->Nome_Garcom, sizeof(novo->Nome_Garcom),stdin);
            strtok(novo->Nome_Garcom, "\n");

            printfOrdenado("Mesa: ",6,7);
            printfOrdenado("Item: ",6,9);
            printfOrdenado("Total: ",6,11);
            gotoxy(12,7);
            scanf("%d", &novo->Mesa);
            if(novo->Mesa<0){
                system("cls");
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\aErro! Valido apenas numeros poitivos no campo MESA."NONE,3,5);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else if(novo->Mesa>500){
                system("cls");
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\aErro!Nao sao permitidos letras, simbolos ou numero maior que 500 no campo MESA."NONE,1,5);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else;
            gotoxy(12,9);
            fflush(stdin);
            fgets(novo->Item,sizeof (novo->Item),stdin);
            strtok(novo->Item, "\n");

            gotoxy(13,11);
            scanf("%f", &novo->Total);
            if(novo->Total<0){
                printfOrdenado(C_RED"\aValor invalido!"NONE,12,13);
                gotoxy(6,15);
                system("pause");
                system("cls");
                return 0;
            }else if(novo->Total>500){
                printfOrdenado(C_RED"\aOps... Valor excedeu ao numero de valor definido pelo desenvolvedor."NONE,5,13);
                gotoxy(12,15);
                system("pause");
                system("cls");
                return 0;
            }else;

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
               CadNovo *aux = inicio;
            FILE *arq = fopen(arquivo,"wb");
            if (arq == NULL)
            {
                printf("Erro ao abrir arquivo\n");
                exit(1);
            }
            while (aux != NULL){
        /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
       */   fwrite(aux,sizeof(CadNovo),1,arq);
            aux = aux->proximo;
            };
            fclose(arq);  /* apagou o arquivo antigo e salvou tudo que esta na memoria, normalmente os dados antigos esta na memoria ainda.*/
            };

            system("cls");
contornoTelaComCabecaPedidos();
                   printfOrdenado(C_GREEN"|******************************************|",18,4);
                          printfOrdenado("|                                          |"NONE,18,5);pintar(15);
                   printfOrdenado(C_WHITE"|  PEDIDO DE MESA CADASTRADO COM SUCESSO   |"NONE,18,6);pintar(15);
                   printfOrdenado(C_GREEN"|                                          |",18,7);
                          printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoMenu04();
            printfOrdenado("1. CADASTRAR OUTRO PEDIDO DE MESA",3,11);
            printfOrdenado("2. LISTAR PEDIDOS DE MESA",48,11);
            printfOrdenado(C_RED" 0. RETORNAR AO MENU"NONE,59,19);pintar(15);
            printfOrdenado("Digite a opcao desejada: ",3,14);
            scanf("%d", &mesa);
            system("cls");
contornoTelaComCabecaPedidos();
            switch(mesa){
            case 1: return CaseNovoPedidoMesa();
                                                break;
            case 2: CaseListarMesa();
                    system("pause");
                    system("cls");
                                                break;
            default:if(mesa<0){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"Ops...\n   \aNumeros negativos ou letras e simbolos nao sao permitidos."NONE,3,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else if(mesa>=3){
contornoTelaComCabecaPedidos();
                printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else if(mesa==0){
                return menu();
            }else;
                                                break;
 };
 return 0;
};

void CaseListarMesa(){


typedef struct CadNovo{
    char Nome_Garcom[50];
    int Mesa;
    char Item[100];
    float Total;

    struct CadNovo *proximo;

}CadNovo;

CadNovo *inicio = NULL;
    char *arquivo = "BancoNovoMesa.bin";
CadNovo *cadnovo;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        cadnovo  = (CadNovo*) malloc(sizeof(CadNovo));
    int qtd = fread(cadnovo,sizeof(CadNovo),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = cadnovo;
        cadnovo->proximo = NULL;
    }else{
        CadNovo *aux = inicio;
        cadnovo->proximo = aux;
        inicio = cadnovo;
        };
        };
        };
    fclose(arq);

    CadNovo *aux;
    CadNovo *novo = (CadNovo*) malloc(sizeof(CadNovo));
        novo->proximo=NULL;
        aux = inicio;

                    system("cls");
                    printfOrdenado("LISTAR",2,3);
                    aux = inicio;
                    gotoxy(2,4);
                    printf("\t|%-10s|%-10s|%-10s|%-10s\n\n", "GARCOM", "MESA", "ITEM", "TOTAL");
                    while (aux!=NULL){
                    printf("\t|%-10s|%-10d|%-10s|%-10.2f\n",aux->Nome_Garcom,aux->Mesa,aux->Item,aux->Total);
                    aux=aux->proximo;
                    };
};
/*void CasePesquisarPorNomeMesa(){
   typedef struct CadNovo{
    char Nome_Garcom[50];
    int Mesa;
    char Item[100];
    float Total;

    struct CadNovo *proximo;

}CadNovo;

CadNovo *inicio = NULL;
    char *arquivo = "BancoNovoMesa.bin";
CadNovo *cadnovo;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabeca();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        cadnovo  = (CadNovo*) malloc(sizeof(CadNovo));
    int qtd = fread(cadnovo,sizeof(CadNovo),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = cadnovo;
        cadnovo->proximo = NULL;
    }else{
        CadNovo *aux = inicio;
        cadnovo->proximo = aux;
        inicio = cadnovo;
        };
        };
        };
    fclose(arq);

    CadNovo *aux;
    CadNovo *novo = (CadNovo*) malloc(sizeof(CadNovo));
        novo->proximo=NULL;
        aux = inicio;

        int Mesa;
                printf("\n\n");
                printfOrdenado("Digite o numero da mesa: ",2,15);
                getchar();
                scanf("%d", &Mesa);
                system("cls");
                printf("\nInformacoes do pedido de Mesa:");
                printf("\n\n\n%-40s|%-15s|%-15s|%-15s\n\n", "GARCOM", "Mesa", "ITEM", "TOTAL");
            while(aux != NULL){
            if(strcmp(Mesa, aux->Mesa) == 0){
                printf("%-40s|%-15d|%-15s|%-15.2f\n", aux->Nome_Garcom,aux->Mesa,aux->Item,aux->Total);
        }
                    aux = aux->proximo;
    };

};*/

void CaseListarRetirada();

void CaseNovoPedidoRetirar(){
   typedef struct NovoCad {
    char Nome_Cliente[50];
    char Telefone[16];
    char Item[100];
    float Total;

    struct NovoCad *proximo;
}NovoCad;

    NovoCad *inicio = NULL;
    char *arquivo = "BancoNovoRetirar.bin";
NovoCad *novocad;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        novocad  = (NovoCad*) malloc(sizeof(NovoCad));
    int qtd = fread(novocad,sizeof(NovoCad),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = novocad;
        novocad->proximo = NULL;
    }else{
        NovoCad *aux = inicio;
        novocad->proximo = aux;
        inicio = novocad;
        };
        };
        };
    fclose(arq);

    NovoCad *aux;
    int ret;
    NovoCad *novo = (NovoCad*) malloc(sizeof(NovoCad));
        novo->proximo=NULL;
        aux = inicio;

contornoTelaComCabecaPedidos();
contorno_M_E_R();
            printfOrdenado(C_BLUE"|************************* NOVO PEDIDO - RETIRAR *************************"NONE,3,3);pintar(15);
            printfOrdenado("Cliente: ",6,5);
            fflush(stdin);
            fgets(novo->Nome_Cliente, sizeof(novo->Nome_Cliente),stdin);
            strtok(novo->Nome_Cliente, "\n");

            printfOrdenado("Telefone: ",6,7);
            printfOrdenado("Item: ",6,9);
            printfOrdenado("Total: ",6,11);
            gotoxy(16,7);
            fflush(stdin);
            fgets(novo->Telefone, sizeof(novo->Telefone),stdin);
            strtok(novo->Telefone, "\n");

            gotoxy(12,9);
            fflush(stdin);
            fgets(novo->Item, sizeof(novo->Item),stdin);
            strtok(novo->Item, "\n");

            gotoxy(13,11);
            scanf("%f", &novo->Total);
            if(novo->Total<0){
                printfOrdenado(C_RED"\aValor invalido!"NONE,25,15);
                gotoxy(12,17);
                system("pause");
                system("cls");
                return 0;
            }else if(novo->Total>500){
                printfOrdenado(C_RED"\aOps... Valor excedeu ao numero de valor definido pelo desenvolvedor."NONE,5,15);
                gotoxy(12,17);
                system("pause");
                system("cls");
                return 0;
            }else;


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
               NovoCad *aux = inicio;
            FILE *arq = fopen(arquivo,"wb");
            if (arq == NULL)
            {
                printf("Erro ao abrir arquivo\n");
                exit(1);
            }
            while (aux != NULL){
            fwrite(aux,sizeof(NovoCad),1,arq);
            aux = aux->proximo;
            };
            fclose(arq);  /* apagou o arquivo antigo e salvou tudo que esta na memoria, normalmente os dados antigos esta na memoria ainda.*/
            };

            system("cls");
contornoTelaComCabecaPedidos();
            printfOrdenado(C_GREEN"|********************************************|",18,4);
                   printfOrdenado("|                                            |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|  PEDIDO DE RETIRADA CADASTRADO COM SUCESSO |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                            |",18,7);
                   printfOrdenado("|********************************************|"NONE,18,8);pintar(15);
contornoMenu05();
            printfOrdenado("1. CADASTRAR OUTRO PEDIDO DE RETIRADA",2,11);
            printfOrdenado("2. LISTAR PEDIDOS DE RETIRADA",47,11);
            printfOrdenado(C_RED" 0. RETORNAR AO MENU"NONE,59,19);pintar(15);
            printfOrdenado(C_WHITE"Digite a opcao desejada: "NONE,3,14);pintar(15);
            scanf("%d", &ret);
            system("cls");
contornoTelaComCabecaPedidos();
            switch(ret){
            case 1: return CaseNovoPedidoRetirar();
                                                break;
            case 2: CaseListarRetirada();
                    system("pause");
                    system("cls");
                                                break;
            default:if(ret<0){
                printfOrdenado(C_RED"\aOps...\n   Numeros negativos ou letras e simbolos nao sao permitidos."NONE,3,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else if(ret>=3){
                printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else if(ret==0){
                return menu();
            }else;
                                                break;
 };
return 0;

};

void CaseListarRetirada(){
typedef struct NovoCad {
    char Nome_Cliente[50];
    char Telefone[16];
    char Item[100];
    float Total;

    struct NovoCad *proximo;
}NovoCad;

    NovoCad *inicio = NULL;
    char *arquivo = "BancoNovoRetirar.bin";
NovoCad *novocad;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        novocad  = (NovoCad*) malloc(sizeof(NovoCad));
    int qtd = fread(novocad,sizeof(NovoCad),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = novocad;
        novocad->proximo = NULL;
    }else{
        NovoCad *aux = inicio;
        novocad->proximo = aux;
        inicio = novocad;
        };
        };
        };
    fclose(arq);

    NovoCad *aux;
    NovoCad *novo = (NovoCad*) malloc(sizeof(NovoCad));
        novo->proximo=NULL;
        aux = inicio;

        system("cls");
                    contornoTelaComCabeca();
                    printfOrdenado("LISTAR",2,3);
                    aux = inicio;
                    gotoxy(5,10);
                    printf("\t%-10s|%-10s|%-10s|%-10s|\n\n", "CLIENTE", "TEL", "ITEM", "TOTAL");
                    while (aux!=NULL){
                    printf("\t%-10s|%-10s|%-10s|%-10.2f|\n",aux->Nome_Cliente,aux->Telefone,aux->Item,aux->Total);
                    aux=aux->proximo;
                    };

};

void CasePesquisarPorNomeRet(){
typedef struct NovoCad {
    char Nome_Cliente[50];
    char Telefone[16];
    char Item[100];
    float Total;

    struct NovoCad *proximo;
}NovoCad;

    NovoCad *inicio = NULL;
    char *arquivo = "BancoNovoRetirar.bin";
NovoCad *novocad;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        novocad  = (NovoCad*) malloc(sizeof(NovoCad));
    int qtd = fread(novocad,sizeof(NovoCad),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = novocad;
        novocad->proximo = NULL;
    }else{
        NovoCad *aux = inicio;
        novocad->proximo = aux;
        inicio = novocad;
        };
        };
        };
    fclose(arq);

    NovoCad *aux;
    NovoCad *novo = (NovoCad*) malloc(sizeof(NovoCad));
        novo->proximo=NULL;
        aux = inicio;

        char Nome_Cliente[50];
                printf("\n\n");
                printfOrdenado("Digite o nome: ",2,14);
                getchar();
                fgets(Nome_Cliente, sizeof(Nome_Cliente), stdin);
                strtok(Nome_Cliente, "\n");
                system("cls");
                printf("\nTodos os contatos");
                printf("\n\n\n%-40s|%-15s\n\n", "NOME", "TELEFONE");
            while(aux != NULL){
            if(strcmp(Nome_Cliente, aux->Nome_Cliente) == 0){
                printf("%-40s|%-15s\n", aux->Nome_Cliente);
        }
                    aux = aux->proximo;
    };
};

void CaseNovoPedidoEntrega(){

  typedef struct Cad_Novo{
    char Nome_Cliente[50];
    char Telefone[12];
    char Endereco[50];
    char Item[100];
    float Total;
    char Forma_Pagamento[25];
    float Troco;

    struct Cad_Novo *proximo;

}Cad_Novo;

Cad_Novo *inicio = NULL;
    char *arquivo = "BancoNovoEntrega.bin";
Cad_Novo *cad_novo;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        cad_novo  = (Cad_Novo*) malloc(sizeof(Cad_Novo));
    int qtd = fread(cad_novo,sizeof(Cad_Novo),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = cad_novo;
        cad_novo->proximo = NULL;
    }else{
        Cad_Novo *aux = inicio;
        cad_novo->proximo = aux;
        inicio = cad_novo;
        };
        };
        };
    fclose(arq);

    Cad_Novo *aux;
    int ent;
    Cad_Novo *novo = (Cad_Novo*) malloc(sizeof(Cad_Novo));
        novo->proximo=NULL;
        aux = inicio;


contornoTelaComCabecaPedidos();
contorno_M_E_R();
            printfOrdenado(C_BLUE"|************************* NOVO PEDIDO - ENTREGA *************************"NONE,3,3);pintar(15);
            printfOrdenado("Cliente: ",6,5);
            fflush(stdin);
            fgets(novo->Nome_Cliente, sizeof(novo->Nome_Cliente),stdin);
            strtok(novo->Nome_Cliente, "\n");

            printfOrdenado("Telefone: ",6,7);
            printfOrdenado("Endereco: ",6,9);
            printfOrdenado("Item: ",6,11);
            printfOrdenado("Total: ",6,13);
            printfOrdenado("Pagamento: ",6,15);
            printfOrdenado("Troco: ",6,17);


            gotoxy(16,7);
            fflush(stdin);
            scanf("%11s", &novo->Telefone);
            strtok(novo->Telefone, "\n");

            gotoxy(16,9);
            fflush(stdin);
            fgets(novo->Endereco, sizeof(novo->Endereco),stdin);
            strtok(novo->Endereco, "\n");

            gotoxy(12,11);
            fflush(stdin);
            fgets(novo->Item, sizeof(novo->Item),stdin);
            strtok(novo->Item, "\n");

            gotoxy(13,13);
            scanf("%f", &novo->Total);
            if(novo->Total<0){
                printfOrdenado(C_RED"\aValor negativo invalido!"NONE,25,19);
                gotoxy(12,21);
                system("pause");
                system("cls");
                return 0;
            }else if(novo->Total>500){
                printfOrdenado(C_RED"\aOps... Valor excedeu ao numero de valor definido pelo desenvolvedor."NONE,5,19);
                gotoxy(12,21);
                system("pause");
                system("cls");
                return 0;
            }else;
            gotoxy(17,15);
            fflush(stdin);
            fgets(novo->Forma_Pagamento, sizeof(novo->Forma_Pagamento),stdin);
            strtok(novo->Forma_Pagamento, "\n");

            gotoxy(13,17);
            scanf("%f", &novo->Troco);
            if(novo->Troco<0){
                printfOrdenado(C_RED"\aValor negativo invalido!"NONE,25,19);
                gotoxy(12,21);
                system("pause");
                system("cls");

                return 0;
            }else if(novo->Troco>500){
                printfOrdenado(C_RED"\aOps... Valor excedeu ao numero de valor definido pelo desenvolvedor."NONE,5,19);
                gotoxy(12,21);
                system("pause");
                system("cls");

                return 0;
            }else;

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
               Cad_Novo *aux = inicio;
            FILE *arq = fopen(arquivo,"wb");
            if (arq == NULL)
            {
                printf("Erro ao abrir arquivo\n");
                exit(1);
            }
            while (aux != NULL){
        /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
       */   fwrite(aux,sizeof(Cad_Novo),1,arq);
            aux = aux->proximo;
            };
            fclose(arq);  /* apagou o arquivo antigo e salvou tudo que esta na memoria, normalmente os dados antigos esta na memoria ainda.*/
            };

            system("cls");
contornoTelaComCabecaPedidos();
            printfOrdenado(C_GREEN"|********************************************|",18,4);
                   printfOrdenado("|                                            |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|  PEDIDO DE ENTREGA CADASTRADO COM SUCESSO  |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                            |",18,7);
                   printfOrdenado("|********************************************|"NONE,18,8);pintar(15);
contornoMenu05();
            printfOrdenado("1. CADASTRAR OUTRO PEDIDO DE ENTREGA",2,11);
            printfOrdenado("2. LISTAR PEDIDOS DE ENTREGA",47,11);
            printfOrdenado(C_RED" 0. RETORNAR AO MENU"NONE,59,19);pintar(15);
            printfOrdenado(C_WHITE"Digite a opcao desejada: "NONE,3,14);pintar(15);
            scanf("%d", &ent);
            system("cls");
contornoTelaComCabecaPedidos();
            switch(ent){
            case 1: return CaseNovoPedidoEntrega();
                                                break;
            case 2: CaseListarEntrega();
                    system("pause");
                    system("cls");
                                                break;
            default:if(ent<0){
                printfOrdenado(C_RED"\aOps...\n   Numeros negativos ou letras e simbolos nao sao permitidos."NONE,3,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else if(ent>=3){
                printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 2 ou letras e simbolos nao sao permitidos."NONE,1,8);
                gotoxy(12,12);
                system("pause");
                system("cls");
                return 0;
            }else if(ent==0){
                return menu();
            }else;
                                                break;
            };
};

void CaseListarEntrega(){

  typedef struct Cad_Novo{
    char Nome_Cliente[50];
    char Telefone[12];
    char Endereco[50];
    char Item[100];
    float Total;
    char Forma_Pagamento[25];
    float Troco;

    struct Cad_Novo *proximo;

}Cad_Novo;

Cad_Novo *inicio = NULL;
    char *arquivo = "BancoNovoEntrega.bin";
Cad_Novo *cad_novo;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        cad_novo  = (Cad_Novo*) malloc(sizeof(Cad_Novo));
    int qtd = fread(cad_novo,sizeof(Cad_Novo),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = cad_novo;
        cad_novo->proximo = NULL;
    }else{
        Cad_Novo *aux = inicio;
        cad_novo->proximo = aux;
        inicio = cad_novo;
        };
        };
        };
    fclose(arq);

    Cad_Novo *aux;
    Cad_Novo *novo = (Cad_Novo*) malloc(sizeof(Cad_Novo));
        novo->proximo=NULL;
        aux = inicio;


system("cls");
    printfOrdenado("LISTAR",2,3);
    aux = inicio;
gotoxy(5,10);
    printf("\t%-10s|%-10s|%-10s|%-10s|%-10s|%-10s|%-10s|\n\n", "CLIENTE", "TEL", "ENDERECO", "ITEM", "TOTAL", "PAGAMENTO", "TROCO");
while (aux!=NULL){
    printf("\t%-10s|%-10s|%-10s|%-10s|%-10.2f|%-10s|%-10.2f|\n",aux->Nome_Cliente,aux->Telefone,aux->Endereco,aux->Item,aux->Total,aux->Forma_Pagamento,aux->Troco);
    aux=aux->proximo;
};
};

void CasePesquisarPorNomeEnt(){
typedef struct Cad_Novo{
    char Nome_Cliente[50];
    char Telefone[12];
    char Endereco[50];
    char Item[100];
    float Total;
    char Forma_Pagamento[25];
    float Troco;

    struct Cad_Novo *proximo;

}Cad_Novo;

Cad_Novo *inicio = NULL;
    char *arquivo = "BancoNovoEntrega.bin";
Cad_Novo *cad_novo;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        system("cls");
        contornoTelaComCabecaPedidos();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    };
    while (!feof(arq)){
        cad_novo  = (Cad_Novo*) malloc(sizeof(Cad_Novo));
    int qtd = fread(cad_novo,sizeof(Cad_Novo),1,arq);
    if(qtd > 0){
    if(inicio == NULL){
        inicio = cad_novo;
        cad_novo->proximo = NULL;
    }else{
        Cad_Novo *aux = inicio;
        cad_novo->proximo = aux;
        inicio = cad_novo;
        };
        };
        };
    fclose(arq);

    Cad_Novo *aux;
    Cad_Novo *novo = (Cad_Novo*) malloc(sizeof(Cad_Novo));
        novo->proximo=NULL;
        aux = inicio;

        char Nome_Cliente[50];
                printf("\n\n");
                printfOrdenado("Digite o nome: ",2,14);
                getchar();
                fgets(Nome_Cliente, sizeof(Nome_Cliente), stdin);
                strtok(Nome_Cliente, "\n");
                system("cls");
                printf("\nTodos os contatos");
                printf("\n\n\n%-40s|%-15s\n\n", "NOME", "TELEFONE");
            while(aux != NULL){
            if(strcmp(Nome_Cliente, aux->Nome_Cliente) == 0){
                printf("%-40s|%-15s\n", aux->Nome_Cliente);
        }
                    aux = aux->proximo;
    };

};
