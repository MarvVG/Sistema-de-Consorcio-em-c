#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"
#include "Vendas.h"
#include "Grupo.h"
#include "Cliente.h"
#include "Pagamentos.h"
int main()
{
    fp=fopen("Arquivo.txt","rb+");
    if(fp==NULL){
            fp=fopen("Arquivo.txt","wb+");
}
    f=fopen("ArquivoGrupo.txt","rb+");
    if(f==NULL){
            f=fopen("ArquivoGrupo.txt","wb+");
            Grupo c;
            c.numerogrupo=0;
     fseek(f,0,SEEK_END);
     fwrite(&c,sizeof(Grupo),1,f);
}
     fv=fopen("Vendas.txt","rb+");
     if(fv==NULL){
     fv=fopen("Vendas.txt","wb+");
     Vendas v;
     v.numerovenda=0;
     fseek(fv,0,SEEK_END);
     fwrite(&v,sizeof(Vendas),1,fv);
     }
    int Opcao, Opcao1,Opcao2;
    do{
 system("cls");
        textcoloreback(WHITE, BLACK);
        Caixa(20,2 , 80, 24, 1);
        textcoloreback(YELLOW, BLACK);
        Caixa(30, 3, 60, 1,1);
         textcoloreback(YELLOW, BLACK);
        Caixa(25 ,6, 70, 18, 1);
        textcoloreback(YELLOW, BLACK);
        gotoxy(49, 4);
        printf("Consorcio Tio Heveras");
        //gotoxy(10, 4);
        textcoloreback(WHITE, BLACK);
        gotoxy(3,2);
        textcoloreback(LIGHT_BLUE,BLACK);
        gotoxy(43,15); printf("   CCCCCC  TTTTTTTTTTTT   HH     HH");
        gotoxy(43,16); printf("  CC       TTT  TT  TTT   HH     HH");
        gotoxy(43,17); printf(" CC             TT        HH     HH");
        gotoxy(43,18); printf("CCC             TT        HHHHHHHHH");
        gotoxy(43,19); printf(" CC             TT        HH     HH");
        gotoxy(43,20); printf("  CC            TT        HH     HH");
        gotoxy(43,21); printf("   CCCCCC       TT        HH     HH");
         textcoloreback(BLUE,BLACK);
        gotoxy(51,26); printf("Sistema Versao 1.0");
        textcoloreback(BROWN,BLACK);
        char OpcoesMenuteste[][20] = {"Cadastros", "Rotinas", "Consultas", "Sair"};
        int xMenuteste[] = {37, 52, 66, 81};
        int yMenuteste[] = {9, 9, 9, 9};
        char OpcoesCadastro[][20] = {"Clientes", "Grupo"};
        int xCadastro[] = {37, 37};
        int yCadastro[] = {11,12 };
        char OpcoesRotina[][20] = {"Vendas", "Pagamento","Alterar","Excluir"};
        int xRotina[] = {52,52,52,52};
        int yRotina[] = {11,12,13,14};
        char RotinaAlterar[][20] = {"Cliente"};
        int  xRotinaAlterar[]= {64};
        int  yRotinaAlterar[]= {13};

        char RotinaExcluir[][20] = {"Cliente","Grupo"};
        int  xRotinaExcluir[]= {64,64};
        int  yRotinaExcluir[]= {13,14};



        char OpcoesConsulta[][20] = {"Clientes","Grupos"};
        int xConsulta[] = {66,66};
        int yConsulta[] = {11,12};
        char Consultar[][20]={"Procurar","Listar"};
        int xConsultar[]={78,78};
        int yConsultar[]={13,14};
        Opcao = Menu(xMenuteste, yMenuteste, OpcoesMenuteste, 4);
        if(Opcao == 0){
             Caixa(36, 10, 10, 2, 0);
             Opcao1 = Menu(xCadastro, yCadastro, OpcoesCadastro, 2);
             if(Opcao1 == 0) {TelaCliente(); DigitarCliente();}
             if(Opcao1 == 1) {TelaGrupos(); CadastroGrupos();}
        }
        if(Opcao == 1) {
             Caixa(51, 10, 10, 4, 0);
             Opcao1 = Menu(xRotina, yRotina, OpcoesRotina, 4);
             if(Opcao1 == 0) Ativarvendas();
             if(Opcao1 == 1) Realizarpagamento();
             if(Opcao1 == 2) {
             Caixa(63, 12, 10, 2, 0);
             Opcao2=Menu(xRotinaAlterar, yRotinaAlterar, RotinaAlterar,1);
             if(Opcao2==0)AlterarCliente();
             }
             if(Opcao1 == 3){
             Caixa(63, 12, 10, 2, 0);
             Opcao2=Menu(xRotinaExcluir, yRotinaExcluir, RotinaExcluir,2);
             if(Opcao2==0)ExcluirCliente();
             if(Opcao2==1)ExcluirGrupo();

        }
        }
        if(Opcao == 2){
             Caixa(65, 10, 10, 2, 0);
             Opcao1 = Menu(xConsulta, yConsulta, OpcoesConsulta,2);
             if(Opcao1 == 0){
             Caixa(77, 12, 10, 2, 0);
             Opcao2 = Menu(xConsultar, yConsultar, Consultar, 2);
             if(Opcao2==0)Procurarclientes();
             if(Opcao2==1)Listarclientes();
             }
             if(Opcao1 == 1){
             Caixa(77, 12, 10, 3, 0);
             Opcao2 = Menu(xConsultar, yConsultar, Consultar, 2);
             if(Opcao2==0)ProcurarGrupo();
             if(Opcao2==1)Listargrupo();
             }



             if(Opcao1 == 2){
             Caixa(77, 12, 10, 3, 0);
             Opcao2 = Menu(xConsultar, yConsultar, Consultar, 2);}
        }
    }while (Opcao != 3);
    if(Opcao ==3)printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    return 0;
}
