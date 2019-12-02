#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED
#include <conio.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define NONE        "\033[0m"
#define BOLD        "\033[1m"
#define HALFBRIGHT  "\033[2m"
#define UNDERSCORE  "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m"

/*****************************COLORS***************************************/
#define C_BLACK     "\033[30m"
#define C_RED       "\033[31m"
#define C_GREEN     "\033[32m"
#define C_YELLOW    "\033[33m"
#define C_BLUE      "\033[34m"
#define C_MAGENTA   "\033[35m"
#define C_CYAN      "\033[36m"
#define C_GRAY      "\033[37m"
#define C_WHITE     "\033[1;37m"

/***************************BACKGROUNDS************************************/
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_GRAY     "\033[47m"


void linha(int inicio, int fim);
void coluna(int posicao);
void colunaOrdenada(int posicao,int ateAlinha);
void gotoxy(int x, int y);
void pintar(int cor);
void limparTela();
void contornoTela();
void contornoTelaComCabeca();
void printfCenter(char *texto, int linha);
void printfOrdenado(char *texto, int coluna, int linha);
void cadastroCliente ();
void cadastroPedido ();
void cadastroBebidas ();
void cadastroProdutos ();
void regua ();
void cadastroPizzaiolo ();
void cadastroFornecedores ();
void cadastroPizzas();
void cadastroFuncionarios();
void cadastroReclamacoes ();
void estoque ();
void menu();
void DataHora();
void tempo();
void RiscosLogin();
void cadastrodePedido();
void LerCliente ();
void troca_valores(float *ptrx, float *ptry);
void cadastroMateria ();
void cadastroRelatorio ();


void contornoTelaComCabecaPedidos();
void clrscr();
void contorno_M_E_R();
void contorno_AND_CONC();
void CaseNovoPedidoMesa();
void CaseNovoPedidoRetirar();
void CaseNovoPedidoEntrega();
void CasePedidoAndamento();
void CasePedidoConcluido();
void contornoMenu();
void contornoMenu02();
void limparTela();
void Listar();
void ListarConcluido();
void contornoMenu03();
void CaseListarPedidoConcluido();
void CaseListarEntrega();
void CaseListarRetirada();
void CaseListarMesa();
void CasePesquisarPorNomeEnt();
void CasePesquisarPorNomeRet();
void TelaLogin();
void LOGIN();












#endif // COMANDOS_H_INCLUDED
