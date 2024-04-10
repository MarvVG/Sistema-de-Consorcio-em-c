#include "interface.h"
#include "Vendas.h"
#include "Grupo.h"
#include "Cliente.h"
void Ativarvendas(){
    fflush(stdin);
    int i=0;
    char suporte[51];
    Vendas gravarv,procurarv;
    Grupo procurarg,receberg,gravarg;
    Cliente receberc,procurarc,gravarc;
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
    printf("Registar nova venda");
    gotoxy(26, 11); printf("     Numero da venda: ");
    gotoxy(26, 13); printf("       Data da venda: ");
    gotoxy(26, 15); printf("     Numero do Grupo: ");
    gotoxy(26, 17); printf("      Numero da cota:");
    gotoxy(26, 19); printf("     Nome do cliente:");
    fseek(fv,-sizeof(Vendas),SEEK_END);
    fread(&procurarv,sizeof(Vendas),1,fv);
    gravarv.numerovenda=procurarv.numerovenda+1;
    gotoxy(48, 11); printf("%d",gravarv.numerovenda);
    gotoxy(48, 13); scanf(" %[^\n]",gravarv.data);
    gotoxy(48, 15); scanf(" %d",&receberg.numerogrupo);
    fseek(f,0,SEEK_SET);
    while(fread(&procurarg,sizeof(Grupo),1,f)){
        if(receberg.numerogrupo==procurarg.numerogrupo) break;}
    gotoxy(48, 17); printf("%d",procurarg.cont);
    gotoxy(48, 19); scanf(" %[^\n]",receberc.Nome);
    strcpy(suporte,"Vazio");
    while(1){

            if(strcmp(procurarg.clientes[i],suporte)==0)break;
    else i++;}
          strcpy(procurarg.clientes[i],receberc.Nome);
    strcpy(procurarg.status,"Ativo");
    for(int i=0;i<procurarg.numerodecotas;i++)strcpy(gravarg.clientes[i],procurarg.clientes[i]);
    gravarg.cont=procurarg.cont+1;
    for(int i=0;i<procurarg.numerodecotas;i++)gravarg.Cotas[i]=procurarg.Cotas[i];
    gravarg.numerodecotas=procurarg.numerodecotas;
    gravarg.quantidadeparc=procurarg.quantidadeparc;
    gravarg.numerogrupo=procurarg.numerogrupo;
    strcpy(gravarg.status,procurarg.status);
    strcpy(gravarg.tipobem,procurarg.tipobem);
    strcpy(gravarg.statuscliente,"Em debito");
    gravarg.valorbem=procurarg.valorbem;
    gravarg.valorcota=procurarg.valorcota;
fseek(f,-sizeof(Grupo),SEEK_CUR);
    fwrite(&gravarg,sizeof(Grupo),1,f);
    fseek(fv,0,SEEK_END);
    fwrite(&gravarv,sizeof(Vendas),1,fv);
    fseek(fp,0,SEEK_SET);
    while(fread(&procurarc,sizeof(Cliente),1,fp)){
        if(strcmp(procurarc.Nome,receberc.Nome)==0) break;}
        strcpy(gravarc.status,"Em debito");
       strcpy(gravarc.Cpf,procurarc.Cpf);
       strcpy(gravarc.DataNascimento,procurarc.DataNascimento);
       strcpy(gravarc.Nome,procurarc.Nome);
       strcpy(gravarc.Telefone,procurarc.Telefone);
    fseek(fp,-sizeof(Cliente),SEEK_CUR);
    fwrite(&gravarc,sizeof(Cliente),1,fp);
    fflush(f);
    fflush(fv);
    fflush(fp);
 gotoxy(38,23); system("pause");
}
