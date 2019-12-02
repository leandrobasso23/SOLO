#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "cabeçalho.h"



const int COLUNA=79;
const int LINHA=19;

/* Funções de designar do Programa ; COORD ; Contornos... */

void pintar(int cor){

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hStdOut, cor);

}

void gotoxy(int x, int y) {

  COORD coord;

  coord.X = x;

  coord.Y = y;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void linha(int inicio, int fim){

int x=0;
gotoxy(inicio,fim);
for(x=0;x<COLUNA;x++){

     printf("%c",205);

}

}

void coluna(int posicao){

int x;

for(x=1;x<=LINHA;x++){

     gotoxy(posicao,x);

     printf("%c",186);

}

}

void colunaOrdenada(int posicao,int ateAlinha){

int x;

for(x=3;x<=ateAlinha;x++){

     gotoxy(posicao,x);

     printf("%c",186);

}

}

void limparTela(){

system("cls");

}

void contornoTela(){
    limparTela();
    printf("%c", 201);
    gotoxy(80,0);
    printf("%c", 187);
    gotoxy(80,20);
    printf("%c", 188);
    linha(1,0);
    printf("%c",187);
    gotoxy(0,20);
    printf("%c", 200);
    linha(1,20);
    coluna(0);
    coluna(80);

    printf("\n");
    }

void contornoTelaComCabeca(){
pintar(15);
    limparTela();
    printf("%c", 201);
    gotoxy(80,0);
    printf("%c", 187);
    gotoxy(80,20);
    printf("%c", 188);
    linha(1,0);
    printf("%c",187);
    gotoxy(0,20);
    printf("%c", 200);
    linha(1,20);
    coluna(0);
    coluna(80);
    linha(1,2);

    }

void printfCenter(char *texto, int linha){

int coluna = (COLUNA / 2) - (strlen(texto)/2);

gotoxy(coluna, linha);

printf("%s", texto);

}

void printfOrdenado(char *texto, int coluna, int linha){

gotoxy(coluna, linha);

printf("%s", texto);

}

void contorno_M_E_R(){
            gotoxy(3,4);
                printf(C_BLUE"|");
            gotoxy(3,5);
                printf("|");
            gotoxy(3,6);
                printf("|");
            gotoxy(3,7);
                printf("|");
            gotoxy(3,8);
                printf("|");
            gotoxy(3,9);
                printf("|");
            gotoxy(3,10);
                printf("|");
            gotoxy(3,11);
                printf("|");
            gotoxy(3,12);
                printf("|");
            gotoxy(3,13);
                printf("|");
            gotoxy(3,14);
                printf("|");
            gotoxy(3,15);
                printf("|");
            gotoxy(3,16);
                printf("|");
            gotoxy(3,17);
                printf("|");
            gotoxy(3,18);
                printf("|");
            gotoxy(3,19);
                printf("|");
            gotoxy(77,4);
                printf("|");
            gotoxy(77,5);
                printf("|");
            gotoxy(77,6);
                printf("|");
            gotoxy(77,7);
                printf("|");
            gotoxy(77,8);
                printf("|");
            gotoxy(77,9);
                printf("|");
            gotoxy(77,10);
                printf("|");
            gotoxy(77,11);
                printf("|");
            gotoxy(77,12);
                printf("|");
            gotoxy(77,13);
                printf("|");
            gotoxy(77,14);
                printf("|");
            gotoxy(77,15);
                printf("|");
            gotoxy(77,16);
                printf("|");
            gotoxy(77,17);
                printf("|");
            gotoxy(77,18);
                printf("|");
            gotoxy(77,19);
                printf("|"NONE);pintar(15);
}

void regua (){
printfOrdenado("01234567890123456789012345678901234567890123456789012345678901234567890",0,2);}

void contornoTelaComCabecaPedidos(){
    pintar(15);
    gotoxy(1,1);
    printf("\t\t\t\t TELA DE PEDIDOS                                ");
    printf("%c", 201);
    gotoxy(80,0);
    printf("%c", 187);
    gotoxy(80,20);
    printf("%c", 188);
    linha(1,0);
    printf("%c",187);
    gotoxy(0,20);
    printf("%c", 200);
    linha(1,20);
    coluna(0);
    coluna(80);
    linha(1,2);
}

void contornoMenu(){

printfOrdenado(C_BLUE"88b           d88  88888888888  888b      88  88        88",11,3);
printfOrdenado("888b         d888  88           8888b     88  88        88",11,4);
printfOrdenado("88`8b       d8'88  88           88 `8b    88  88        88",11,5);
printfOrdenado("88 `8b     d8' 88  88aaaaa      88  `8b   88  88        88",11,6);
printfOrdenado("88  `8b   d8'  88  88'''''      88   `8b  88  88        88",11,7);
printfOrdenado("88   `8b d8'   88  88           88    `8b 88  88        88",11,8);
printfOrdenado("88    `888'    88  88           88     `8888  Y8a.    .a8P",11,9);
printfOrdenado("88     `8'     88  88888888888  88      `888   `'Y8888Y'  ",11,10);
printfOrdenado(" _____________________________________________________________________________ ",1,11);
printfOrdenado("|                                    |                                        |",1,12);
printfOrdenado("|____________________________________|________________________________________|",1,13);
printfOrdenado("|                                    |                                        |",1,14);
printfOrdenado("|____________________________________|________________________________________|",1,15);
printfOrdenado("|                                    |                                        |",1,16);
printfOrdenado("|____________________________________|________________________________________|"NONE,1,17);pintar(15);

};

void contornoCadastro(){
printfOrdenado(C_BLUE" a88888b.  .d888888 888888ba   .d888888  .d88888b  d888888P 888888ba   .88888. ",1,3);
printfOrdenado("d8'   `88 d8'    88  88    `8b d8'    88 88.    '     88    88    `8b d8'   `8b",1,4);
printfOrdenado("88        88aaaaa88  88     88 88aaaaa88 `Y88888b.    88    88aaaa8P' 88     88",1,5);
printfOrdenado("88        88     88  88     88 88     88       `8b    88    88   `8b. 88     88",1,6);
printfOrdenado("Y8.   .88 88     88  88    .8P 88     88 d8'   .8P    88    88     88 Y8.   .8P",1,7);
printfOrdenado(" Y88888P' 88     88 8888888P   88     88  Y88888P     dP    dP     dP  `8888P' ",1,8);
printfOrdenado(" _____________________________________________________________________________ ",1,9);
printfOrdenado("|                                    |                                        |",1,10);
printfOrdenado("|____________________________________|________________________________________|",1,11);
printfOrdenado("|                                    |                                        |",1,12);
printfOrdenado("|____________________________________|________________________________________|",1,13);
printfOrdenado("|                                    |                                        |",1,14);
printfOrdenado("|____________________________________|________________________________________|",1,15);
printfOrdenado("|                                    |                                        |",1,16);
printfOrdenado("|____________________________________|________________________________________|",1,17);
printfOrdenado("|                                    |                                        |",1,18);
printfOrdenado("|____________________________________|________________________________________|"NONE,1,19);pintar(15);
};

void contornoEstoque(){

printfOrdenado(C_BLUE" 88888888b .d88888b  d888888P  .88888.   .88888.   dP     dP  88888888b",4,3);
printfOrdenado(" 88        88.     '    88    d8'   `8b d8'   `8b  88     88  88       ",4,4);
printfOrdenado("a88aaaa    `Y88888b.    88    88     88 88     88  88     88 a88aaaa   ",4,5);
printfOrdenado(" 88              `8b    88    88     88 88  db 88  88     88  88       ",4,6);
printfOrdenado(" 88        d8'   .8P    88    Y8.   .8P Y8.  Y88P  Y8.   .8P  88       ",4,7);
printfOrdenado(" 88888888P  Y88888P     dP     `8888P'   `8888PY8b `Y88888P'  88888888P",4,8);
printfOrdenado(" ________________         ________________         ",6,11);
printfOrdenado("|                |       |                |       ",6,12);
printfOrdenado("|________________|       |________________|       "NONE,6,13);pintar(15);
};

void contornoCliente(){

printfOrdenado(C_BLUE" _____________________        ______________________ ",14,7);
printfOrdenado("|                     |      |                      |",14,8);
printfOrdenado("|_____________________|      |______________________|",14,9);
printfOrdenado(" _____________________         ",14,10);
printfOrdenado("|                     |      ",14,11);
printfOrdenado("|_____________________|      "NONE,14,12);pintar(15);

};

void contornoCADASTRO(){
printfOrdenado(C_BLUE" _____________________________      _____________________________ ",7,10);
      printfOrdenado("|                             |    |                             |",7,11);
      printfOrdenado("|_____________________________|    |_____________________________|"NONE,7,12);pintar(15);
};

void contorno_BePeP(){

printfOrdenado(C_BLUE" __________________       ___________________  ",4,7);
printfOrdenado("|                  |     |                   |     ",4,8);
printfOrdenado("|__________________|     |___________________|     "NONE,4,9);pintar(15);

};

void contornoPizzaiolo(){

printfOrdenado(C_BLUE" _______________________  ________________________  ",2,7);
printfOrdenado("|                       ||                        |",2,8);
printfOrdenado("|_______________________||________________________|"NONE,2,9);pintar(15);


};

void contornoFornecedor(){

printfOrdenado(C_BLUE" _____________________     ______________________     ______________________ ",2,7);
printfOrdenado("|                     |   |                      |   |                      |",2,8);
printfOrdenado("|_____________________|   |______________________|   |______________________|"NONE,2,9);pintar(15);

};

void contornoRegistro(){

printfOrdenado(C_BLUE" 888888ba   88888888b  .88888.  dP .d88888b  d888888P  888888ba   .88888. ",4,3);
printfOrdenado(" 88    `8b  88        d8'   `88 88 88.    '     88     88    `8b d8'   `8b",4,4);
printfOrdenado("a88aaaa8P' a88aaaa    88        88 `Y88888b.    88    a88aaaa8P' 88     88",4,5);
printfOrdenado(" 88   `8b.  88        88   YP88 88       `8b    88     88   `8b. 88     88",4,6);
printfOrdenado(" 88     88  88        Y8.   .88 88 d8'   .8P    88     88     88 Y8.   .8P",4,7);
printfOrdenado(" dP     dP  88888888P  `88888'  dP  Y88888P     dP     dP     dP  `8888P' ",4,8);
printfOrdenado(" _____________________     ______________________     ______________________ ",2,10);
printfOrdenado("|                     |   |                      |   |                      |",2,11);
printfOrdenado("|_____________________|   |______________________|   |______________________|"NONE,2,12);pintar(15);
};

void AsciiArtIMAGEM(){
printfOrdenado(C_YELLOW"                              ,(  `-.       ",36,3);
printfOrdenado("                             ,': `.   `.    ",36,4);
printfOrdenado("                           ,` *   `-.   '   ",36,5);
printfOrdenado("                         ,'  ` :+  = `.  `. ",36,6);
printfOrdenado("                       ,~  (o):  .,   `.  `.",36,7);
printfOrdenado("                     ,'  ; :   ,(__) x;`.  ;",36,8);
printfOrdenado("                   ,'  :'  itz  ;  ; ; _,-' ",36,9);
printfOrdenado("                 .'O ; = _' C ; ;'_,_ ;     ",36,10);
printfOrdenado("               ,;  _;   ` : ;'_,-'   i'     ",36,11);
printfOrdenado("             ,` `;(_)  0 ; ','       :      ",36,12);
printfOrdenado("           .';6     ; ' ,-'~                ",36,13);
printfOrdenado("         ,' Q  ,& ;',-.'                    ",36,14);
printfOrdenado("       ,( :` ; _,-'~  ;                     ",36,15);
printfOrdenado("     ,~.`c _','                             ",36,16);
printfOrdenado("   .';^_,-' ~                               ",36,17);
printfOrdenado(" ,'_;-''                                    ",36,18);
printfOrdenado(",,~                                         "NONE,36,19);pintar(15);

};

void AsciiArtPIZZA(){

printfOrdenado(C_BLUE"              88                                  ",1,3);
printfOrdenado(      "              ''                                  ",1,4);
printfOrdenado(      " 8b,dPPYba,   88  888888888  888888888  ,adPPYYba,",1,5);
printfOrdenado(      " 88P'    '8a  88       a8P'       a8P'  ''     `Y8",1,6);
printfOrdenado(      " 88       d8  88    ,d8P'      ,d8P'    ,adPPPPP88",1,7);
printfOrdenado(      " 88b,   ,a8'  88  ,d8'       ,d8'       88,    ,88",1,8);
printfOrdenado(      " 88`YbbdP''   88  888888888  888888888  `'8bbdP'Y8",1,9);
printfOrdenado(      " 88                                               ",1,10);
printfOrdenado(      " 88                                            "NONE,1,11);pintar(15);
printfOrdenado("HOT",6,3);
printfOrdenado("GOURMET", 37,11);
};

void DataHoraLOGIN(){
gotoxy(69,19);
  system ( "date /t" );
gotoxy(71,18);
   system ("time /t");

};

void DataHoraMENU(){
gotoxy(61,18);
  system ( "date /t" );
gotoxy(74,18);
   system ("time /t");

};

void contornoPedido(){

printfOrdenado(C_BLUE" 888888ba   88888888b  888888ba    dP 888888ba     .88888.   .d88888b ",6,3);
printfOrdenado(" 88    `8b  88          88    `8b  88  88    `8b  d8'   `8b  88.    ' ",6,4);
printfOrdenado("a88aaaa8P' a88aaaa      88     88  88  88     88  88     88  `Y88888b.",6,5);
printfOrdenado(" 88         88          88     88  88  88     88  88     88        `8b",6,6);
printfOrdenado(" 88         88          88    .8P  88  88    .8P  Y8.   .8P  d8'   .8P",6,7);
printfOrdenado(" dP         88888888   8888888P    dP 8888888P     `8888P'    Y88888P ",6,8);
printfOrdenado(" _____________________________________________________________________________ ",1,9);
printfOrdenado("|                                    |                                        |",1,10);
printfOrdenado("|____________________________________|________________________________________|",1,11);
printfOrdenado("|                                    |                                        |",1,12);
printfOrdenado("|____________________________________|________________________________________|",1,13);
printfOrdenado("|                                    |                                        |",1,14);
printfOrdenado("|____________________________________|________________________________________|",1,15);
printfOrdenado("|                                    |                                        |",1,16);
printfOrdenado("|____________________________________|________________________________________|"NONE,1,17);pintar(15);
};

void contornoMenu02(){

printfOrdenado(C_BLUE" ____________         ____________         ____________ ",12,7);
      printfOrdenado("|            |       |            |       |            |",12,8);
      printfOrdenado("|____________|       |____________|       |____________|"NONE,12,9);pintar(15);
};

void contornoMenu03(){

printfOrdenado(C_BLUE"        ___________________________         ___________________________   ",1,7);
      printfOrdenado("       |                           |       |                           |  ",1,8);
      printfOrdenado("       |___________________________|       |___________________________|  "NONE,1,9);pintar(15);
};

void contornoMenu04(){
printfOrdenado(C_BLUE" ____________________________________     ____________________________________ ",1,10);
      printfOrdenado("|                                    |   |                                    |",1,11);
      printfOrdenado("|____________________________________|   |____________________________________|"NONE,1,12);pintar(15);
};

void contornoMenu05(){
printfOrdenado(C_BLUE" _____________________________________    ____________________________________ ",1,10);
      printfOrdenado("|                                     |  |                                    |",1,11);
      printfOrdenado("|_____________________________________|  |____________________________________|"NONE,1,12);pintar(15);
};

void contornoMenu06(){
printfOrdenado(C_BLUE" _____________________________________    ____________________________________ ",1,5);
      printfOrdenado("|                                     |  |                                    |",1,6);
      printfOrdenado("|_____________________________________|  |____________________________________|"NONE,1,7);pintar(15);
/*      printfOrdenado("                       _____________________________________ ",1,8);
      printfOrdenado("                      |                                     |",1,9);
      printfOrdenado("                      |_____________________________________|"NONE,1,10);pintar(15);*/
};

void contornoMenu07(){

printfOrdenado(C_BLUE"        ______________________________      ______________________________   ",1,7);
      printfOrdenado("       |                              |    |                              |  ",1,8);
      printfOrdenado("       |______________________________|    |______________________________|  "NONE,1,9);pintar(15);


};

void contorno_AND_CONC(){








            gotoxy(28,10);
                printf(C_BLUE"________________________________________________");
            gotoxy(27,11);
                    printf("|                                                |");
            gotoxy(27,12);
                    printf("|                                                |");
             gotoxy(27,13);
                    printf("|                                                |");
            gotoxy(27,14);
                    printf("|________________________________________________|"NONE);pintar(15);
};

void TelaMenu(){
            gotoxy(14,13);
                printf(C_BLUE" ________________________________________________");
            gotoxy(14,14);
                printf("|                                                |");
            gotoxy(14,15);
                printf("|                                                |");
             gotoxy(14,16);
                printf("|                                                |");
            gotoxy(14,17);
                printf("|________________________________________________|"NONE);pintar(15);
};

void AsciiArtSOLO(){

printfOrdenado(C_RED"__________________________|____"NONE,48,3);
printfOrdenado(C_BLUE" .d8888b.        .d88888b.       888            .d88888b. ",10,5);
printfOrdenado("d88P  Y88b      d88P' 'Y88b      888           d88P' 'Y88b",10,6);
printfOrdenado("Y88b.           888     888      888           888     888"NONE,10,7);
printfOrdenado(" 'Y888b.        888     888      888           888     888",10,8);
printfOrdenado("    'Y88b.      888     888      888           888     888",10,9);
printfOrdenado(C_RED"      '888      888     888      888           888     888",10,10);
printfOrdenado("Y88b  d88P      Y88b. .d88P      888           Y88b. .d88P",10,11);
printfOrdenado(" 'Y8888P'        'Y88888P'       88888888       'Y88888P' "NONE,10,12);
printfOrdenado(C_RED"|",74,4);
printfOrdenado("|",74,5);
printfOrdenado("|",74,6);
printfOrdenado("|",74,7);
printfOrdenado("|",74,8);
printfOrdenado("____|__________________________",2,18);
printfOrdenado("|",6,19);
printfOrdenado("|",6,17);
printfOrdenado("|",6,16);
printfOrdenado("|",6,15);
printfOrdenado("|"NONE,6,14);
};








void RiscosLogin(){
printfOrdenado("                                          |    ",50,1);
printfOrdenado("__________________________________________|____",50,2);
printfOrdenado("                                          |    ",50,3);
printfOrdenado("                                          |    ",50,4);
printfOrdenado("                                          |    ",50,5);
printfOrdenado("                                          |    ",50,6);

};







