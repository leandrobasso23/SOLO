#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include "cabeçalho.h"
#include <string.h>


void cadastroProdutos (){

typedef struct Produtos {
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



    struct Produtos *proximo;

    }Produtos;




    Produtos *inicio = NULL;
                                /* Aqui abrimos o arquivo gerado em binario para leitura dos dados já inseridos */

    char *arquivo = "teste.bin";

    Produtos *produtos;
    FILE *arq = fopen(arquivo,"r+b");
    if (arq == NULL)
    {
        limparTela();
        contornoTela();
        printfOrdenado("Erro ao abrir arquivo, verifique se o mesmo existe no diretorio\n",3,10);
        getch();
        return;
    }

    while (!feof(arq))      /* repetindo até o final do arquivo*/
    {   produtos  = (Produtos*) malloc(sizeof(Produtos));
        int qtd = fread(produtos,sizeof(Produtos),1,arq);
        if(qtd > 0){
            if(inicio == NULL){
                inicio = produtos;
                produtos->proximo = NULL;
            }
            else{
                Produtos *aux = inicio;
                produtos->proximo = aux;
                inicio = produtos;
            }
        }
    }
    fclose(arq);   /* abriu e leu o arquivo armazenou na memoria e fechou */



    Produtos *aux;
    int ott=0;
    int opp;
    int xx=0;



            int op;
            int ordenaMenu =8;
            do {
            contornoTelaComCabeca();
            contorno_BePeP();
            printfCenter("TELA DE PRODUTOS",1);
            printfOrdenado("1-Nova Produto",8,ordenaMenu);
            printfOrdenado("2-Lista de Produtos",30,ordenaMenu);
            printfOrdenado("3-Remover Produtos",57,ordenaMenu);
            printfOrdenado(C_RED"0-Retornar ao Menu"NONE,61,19);pintar(15);
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

            Produtos *novo = (Produtos*) malloc(sizeof(Produtos));

            novo->proximo=NULL;

            strcpy(novo->categoria,"Produtos");

            aux = inicio;
            ordenaMenu =3;
            contornoTelaComCabeca();
            printfCenter("Nova Produto",1);
            gotoxy(3,4);
            printf("ID:");
            printfOrdenado("Filial: ",15,4);
            scanf("%d", &novo->filial);

            printfOrdenado("Nome: ",ordenaMenu,5);
            gotoxy(3,6);
            printf("Categoria: %s", novo->categoria);
            printfOrdenado("Preco de Custo: ", ordenaMenu,7);
            printfOrdenado("Imposto %: ",ordenaMenu,8);
            printfOrdenado("Despesas %: ",ordenaMenu,9);
            printfOrdenado("Lucro %: ",ordenaMenu,10);
            printfOrdenado("Estoque Atual: ",ordenaMenu,11);
            printfOrdenado("Fornecedor: ",ordenaMenu,12);




            gotoxy(9,5);
            fflush(stdin);
            fgets(novo->nome ,sizeof(novo->nome),stdin);
            strtok(novo->nome, "\n");
            gotoxy(20,7);
            scanf("%f", &novo->precoCusto);
            gotoxy(15,8);
            scanf("%d", &novo->imposto);
            gotoxy(17,9);
            scanf("%d", &novo->despesas);
            gotoxy(13,10);
            scanf("%d", &novo->lucro);
            gotoxy(19,11);
            scanf("%d", &novo->estoqueAtual);
            gotoxy(16,12);
            fflush(stdin);
            scanf("%50s", novo->fornecedor);


             novo->precoEst = (novo->precoCusto/100*(novo->despesas+novo->imposto+novo->lucro))+novo->precoCusto;

            gotoxy(3,13);
            printf("Preco de venda estimado em R$ %.2f", novo->precoEst);
            printfOrdenado("Entre com o valor que deseja vender: R$ ",3,14);
            scanf("%f", &novo->precoVenda);



            printfOrdenado("Observacao: ",3,15);
            fflush(stdin);
            fgets(novo->obs ,sizeof(novo->obs),stdin);
            strtok(novo->obs, "\n");
                        system("\t\npause");



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
    Produtos *aux = inicio;
    FILE *arq = fopen(arquivo,"wb");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    while (aux != NULL){
        /*("\n->%d, %d, %s, %s, %s, \n%s, %s, %s, %s",novo->id,novo->filial, novo->nome, novo->cpf,novo->telefone,novo->email,novo->endereco,novo->cep,novo->obs);
       */ fwrite(aux,sizeof(Produtos),1,arq);
        aux = aux->proximo;

    }

    fclose(arq);
    }


        limparTela();
        contornoTela();

            printfOrdenado(C_GREEN"|******************************************|",18,4);
                   printfOrdenado("|                                          |"NONE,18,5);pintar(15);
            printfOrdenado(C_WHITE"|       PRODUTO CADASTRADO COM SUCESSO     |"NONE,18,6);pintar(15);
            printfOrdenado(C_GREEN"|                                          |",18,7);
                   printfOrdenado("|******************************************|"NONE,18,8);pintar(15);
contornoCADASTRO();
            printfOrdenado("1. CADASTRAR OUTRO PRODUTO",9,11);
            printfOrdenado("0. RETORNAR AO MENU PRINCIPAL",43,11);
            printfOrdenado("Digite a opcao desejada: ",8,14);
            scanf("%d", &ott);
            limparTela();
            contornoTelaComCabeca();
        if(ott<0){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumeros negativos ou letras e simbolos nao sao permitidos. "NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(ott>=2){
            contornoTelaComCabeca();
            printfOrdenado(C_RED"\t\aOpcao invalida!\n\tNumero maior que 1 ou letras e simbolos nao sao permitidos."NONE,1,8);
            gotoxy(12,12);
            system("pause");
            system("cls");
        }else if(ott==0){
            return menu();
        }else;


            if(ott==1){
                return cadastroProdutos();
            }else; break;



                case 2:
                    limparTela();
                    contornoTela();
                    gotoxy(2,3);
                    printfCenter("LISTAR",2);

                Produtos *aux = inicio;
                gotoxy(3,4);
                printf("\n\tTodos os Produtos");
                gotoxy(3,6);
                printf("\t%-40s|%-15s\n\n", "NOME", "PRECO");
                while(aux != NULL){


                if(strcmp("Produtos", aux->categoria) == 0){
                    printf("\t%-40s|%-15.2f", aux->nome, aux->precoVenda);
                    printf("\n");
                }
                aux = aux->proximo;
                }

                    gotoxy(35,19);
                    system("pause");
                    limparTela(); break;


                case 0: return cadastroProdutos(); break;
        default:
            printf("Opcao Invalida");break;
        }



       cadastroProdutos();

       }while(ott == 1);












    return 0;

}
