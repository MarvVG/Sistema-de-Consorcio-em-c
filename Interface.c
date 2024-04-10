#include "Interface.h"
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void textcoloreback (int letras, int fundo)
{
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             letras + (fundo << 4));
}

void Caixa(int x, int y, int Largura, int Altura, int Tipo)
{
    int i, j;
    unsigned char C[][6] = {{218, 196, 191, 179, 192, 217},
        {201, 205, 187, 186, 200, 188}
    };
    gotoxy(x, y);
    printf("%c", C[Tipo][0]);
    for(i = 0; i < Largura; i++)
        printf("%c", C[Tipo][1]);
    printf("%c", C[Tipo][2]);
    for(j = 0; j < Altura; j++)
    {
        gotoxy(x, y + j + 1);
        printf("%c", C[Tipo][3]);
        for(i = 0; i < Largura; i++) printf(" ");
        printf("%c", C[Tipo][3]);
    }
    gotoxy(x, y + j + 1);
    printf("%c", C[Tipo][4]);
    for(i = 0; i < Largura; i++)
        printf("%c", C[Tipo][1]);
    printf("%c", C[Tipo][5]);
}
int getTecla()
{
    int ch;
    ch = getch();
    if(ch == 224)
    {
        ch = getch() + 1000;
    }
    return ch;
}
void tipocursor (int cursor)
{
    HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CURSOR;
    BOOL result;
    CURSOR.dwSize = 1;
    if(cursor == 0)
        CURSOR.bVisible = FALSE;
    else
        CURSOR.bVisible = TRUE;
    result=SetConsoleCursorInfo(myconsole, &CURSOR);
}
int Menu(int x[], int y[], char Opcoes[][20], int n){
    int i, Opcao = 0, Tecla;
    tipocursor(0);
    textcoloreback(YELLOW, BLACK);
    for (i = 0; i < n; i++){
        gotoxy(x[i], y[i]); printf("%s", Opcoes[i]);
    }
    tipocursor(0);
    do{
        textcoloreback(YELLOW, BLUE);
        gotoxy(x[Opcao], y[Opcao]); printf("%s", Opcoes[Opcao]);
        Tecla = getTecla();
        textcoloreback(YELLOW, BLACK);
        gotoxy(x[Opcao], y[Opcao]); printf("%s", Opcoes[Opcao]);
        if(Tecla == TEC_ESQ) Opcao--;
        if(Tecla == TEC_DIR) Opcao++;
        if(Tecla == TEC_CIMA) Opcao--;
        if(Tecla == TEC_BAIXO) Opcao++;
        if(Tecla == TEC_ENTER) {
                tipocursor(1);
                return Opcao;
        }
        if(Opcao < 0) Opcao = n - 1;
        if(Opcao >= n) Opcao = 0;
    } while(Tecla != TEC_ESC);
    tipocursor(1);
    return -1;

}
void LimparTelaClienteGrupo(){
    gotoxy(44,  11); printf("%*s", 40, " ");
    gotoxy(44,  14); printf("%*s", 40, " ");
    gotoxy(45, 17); printf("%*s", 40, " ");
    gotoxy(45, 20); printf("%*s", 40, " ");
    gotoxy(38, 23); printf("%*s", 25, " ");
}
int MenuAlterarExcluir(){
    int opcao;
    char OpcoesAlterar[][20]={"Nome","Cpf"};
    int xAlterar[]={62,68};
 textcoloreback(YELLOW, BLACK);
    int yAlterar[]={4,4};
 textcoloreback(LIGHT_BLUE, BLACK);
 Caixa(20,2 , 80, 24, 1);
 Caixa(25 ,6, 70, 18, 1);
 Caixa(26,22,68,1,0);
 gotoxy(28,23);
 printf("Mensagem:");
 textcoloreback(LIGHT_BLUE, BLACK);
 Caixa(30, 3, 60, 1,1);
  textcoloreback(YELLOW, BLACK);
 gotoxy(31,4);
 printf("Por qual forma deseja excluir:");
 gotoxy(52,4);
 opcao=Menu(xAlterar, yAlterar, OpcoesAlterar,2);
return opcao;
system("pause");
}
