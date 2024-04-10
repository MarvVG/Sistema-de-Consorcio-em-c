#include "Pagamentos.h"
#include <time.h>
void Realizarpagamento(){
    fflush(stdin);
    srand(time(NULL));
    Vendas gravarv;
    Grupo procurarg,receberg,gravarg;
    Cliente receberc,gravarc,procurarc;
    int aux;
    double valor;
    textcoloreback(LIGHT_BLUE, BLACK);
    Caixa(20,2 , 80, 24, 1);
    textcoloreback(YELLOW, BLACK);
    Caixa(25 ,6, 70, 18, 1);
    Caixa(26,22,68,1,0);
    gotoxy(28,23);
    printf("Mensagem:");
    textcoloreback(LIGHT_BLUE, BLACK);
    Caixa(30, 3, 60, 1,1);
    gotoxy(50,4);
    textcoloreback(YELLOW, BLACK);
    printf("Registar pagamento");
    gotoxy(26, 11); printf("     Numero do grupo: ");
    gotoxy(26, 13); printf("      Numero da cota: ");
    gotoxy(26, 15); printf("          Valor pago: ");
    gotoxy(26, 17); printf("        Nome cliente: ");

    gotoxy(48, 11); scanf(" %d",&receberg.numerogrupo);
    fseek(f,0,SEEK_SET);
    while(fread(&procurarg,sizeof(Grupo),1,f)){
        if(receberg.numerogrupo==procurarg.numerogrupo) break;}
    gotoxy(48, 13); scanf("%d",&aux);
    gotoxy(48, 15); scanf(" %lf",&valor);
    gotoxy(48, 17); scanf(" %[^\n]",receberc.Nome);
    if(procurarg.Cotas[aux-1]>0)procurarg.Cotas[aux-1]-=valor;
    if(procurarg.Cotas[aux-1]==0){
    strcpy(gravarc.status,"Quitado");
    }
    fseek(fp,0,SEEK_SET);
    while(fread(&procurarc,sizeof(Cliente),1,fp)){
    if(strcmp(procurarc.Nome,receberc.Nome)==0) break;}
       strcpy(gravarc.Cpf,procurarc.Cpf);
       strcpy(gravarc.DataNascimento,procurarc.DataNascimento);
       strcpy(gravarc.Nome,procurarc.Nome);
       strcpy(gravarc.Telefone,procurarc.Telefone);
    fseek(fp,-sizeof(Cliente),SEEK_CUR);
    fwrite(&gravarc,sizeof(Cliente),1,fp);
    for(int i=0;i<procurarg.numerodecotas;i++)strcpy(gravarg.clientes[i],procurarg.clientes[i]);
    gravarg.cont=procurarg.cont+1;
    for(int i=0;i<procurarg.numerodecotas;i++)gravarg.Cotas[i]=procurarg.Cotas[i];
    gravarg.numerodecotas=procurarg.numerodecotas;
    gravarg.quantidadeparc=procurarg.quantidadeparc;
    gravarg.numerogrupo=procurarg.numerogrupo;
    strcpy(gravarg.status,procurarg.status);
    strcpy(gravarg.tipobem,procurarg.tipobem);
    gravarg.valorbem=procurarg.valorbem;
    gravarg.valorcota=procurarg.valorcota;
    strcpy(gravarg.statuscliente,receberg.statuscliente);
fseek(f,-sizeof(Grupo),SEEK_CUR);
    fwrite(&gravarg,sizeof(Grupo),1,f);
    fseek(fv,0,SEEK_END);
    fwrite(&gravarv,sizeof(Vendas),1,fv);
    fflush(f);
    fflush(fv);
    fflush(fp);
system("pause");
}
