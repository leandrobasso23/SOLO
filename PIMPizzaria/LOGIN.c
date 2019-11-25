#include <windows.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <string.h>

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

/***************************BACKGROUNDS************************************/
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_GRAY     "\033[47m"

int login();
int OpMenu;
int resp;
typedef struct Usuario{
    char Nome_Completo[50];
    char Email[50];
    char login[20];
    char senha[16];
}Usuario;
Usuario usuarios[10];


int main(int argc, char const *argv[])
{
    do{
    strcpy(usuarios[0].Nome_Completo,"Vinicio Mavel Dos Santos");
    strcpy(usuarios[0].Email,"viniciomavel@gmail.com");
    strcpy(usuarios[0].login,"Mavel");
    strcpy(usuarios[0].senha,"123");

    strcpy(usuarios[1].Nome_Completo,"Leandro Basso Ribeiro Da Silva");
    strcpy(usuarios[1].Email,"leandroadsrp@gmail.com");
    strcpy(usuarios[1].login,"Leandro");
    strcpy(usuarios[1].senha,"1234");

    strcpy(usuarios[2].Nome_Completo,"ADMINISTRADOR/DESENVOLVEDOR");
    strcpy(usuarios[2].login,"admin");
    strcpy(usuarios[2].senha,"12345");

    strcpy(usuarios[3].Nome_Completo,"Marcelo Gomes De Paula");
    strcpy(usuarios[3].Email,"marcelo.paula1@docente.unip.br");
    strcpy(usuarios[3].login,"Marcelo");
    strcpy(usuarios[3].senha,"marcelounipads");
    while(login()==1){
    printfOrdenado(C_GREEN":ACESSO LIBERADO:\ "NONE,29,18);pintar(15);
    Beep(1200,200);
    gotoxy(15,19);
    system("pause");
    system("cls");
contornoTelaComCabeca();
    menu();
};

        printfOrdenado(C_RED":ACESSO NEGADO\a:\n"NONE,29,18);pintar(15);
        gotoxy(15,19);
        system("pause");
        printfOrdenado(C_RED"Deseja tentar logar novamente? (S/N): "NONE,18,22);pintar(15);
        scanf(" %c", &resp);
        }while(resp == 's');

};
int login(){
    char login[20], senha[16];
    int i;
    int esc;
contornoTelaComCabeca();
system("cls");
contornoTelaComCabeca();
AsciiArtSOLO();
TelaMenu();
DataHoraLOGIN();
    while(esc != 27){
    printfOrdenado("Digite o Login: ", 20,15);
    fflush(stdin);
    gets(login);
    printfOrdenado("Digite a Senha: ",20,16);
    fflush(stdin);
    gets(senha);

    for(i=0;i<10;i++){
        if(strcmp(usuarios[i].login, login)==0 && strcmp(usuarios[i].senha, senha)==0){
            return 1;
        }else if(strcmp(usuarios[i].login, login)==1 && strcmp(usuarios[i].senha, senha)==1){
            return 0;
        }else;
    };
    switch (esc){
    case 'esc': esc = getch(); break;
    };

};
};

