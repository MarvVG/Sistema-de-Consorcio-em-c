#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#define TEC_ENTER 13
#define TEC_TAB 9
#define TEC_BACKSPACE 8
#define TEC_ESC 27
#define TEC_DIR 1077
#define TEC_ESQ 1075
#define TEC_BAIXO 1080
#define TEC_CIMA 1072
#define TEC_DEL 1083
#define TEC_END 1079
#define TEC_INSERT 1082
#define TEC_HOME 1071
#define TEC_PAGE_UP 1073
#define TEC_PAGE_DOWN 1081
#include <conio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
enum DOS_COLORS {
       BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
       LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
       LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };

void gotoxy(int x,int y);
void Caixa(int x, int y, int Largura, int Altura, int Tipo);
void MenuPrincipal();
int Menu(int x[], int y[], char Opcoes[][20], int n);
void tipocursor (int cursor);
void textcoloreback (int letras, int fundo);
void LimparTelaClienteGrupo();
int MenuAlterarExcluir();
int getTecla();


#endif // INTERFACE_H_INCLUDED
