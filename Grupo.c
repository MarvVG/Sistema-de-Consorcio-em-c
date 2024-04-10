#include "Grupo.h"
void  TelaGrupos()
{
    tipocursor(0);
    system("cls");
    textcoloreback(LIGHT_BLUE, BLACK);
    Caixa(20,2, 80, 24, 1);
    textcoloreback(YELLOW, BLACK);
    Caixa(30, 3, 60, 1,1);
    textcoloreback(YELLOW, BLACK);
    Caixa(25,6, 70, 18, 1);
    textcoloreback(YELLOW, BLACK);
    gotoxy(49, 4);
    printf("Consorcio Tio Hevera's");
    //gotoxy(10, 4);
    gotoxy(26,8);
    for(int i=0; i<26; i++)printf("%c",205);
    gotoxy(52,8);
    printf("Cadastro de grupos");
    gotoxy(70,8);
    for(int i=0; i<26; i++)printf("%c",205);
    gotoxy(26,  11);
    printf("    Numero do grupo: ");
    gotoxy(26,  13);
    printf("Quantidade de cotas: ");
    gotoxy(26, 15);
    printf("      Valor da cota:");
    gotoxy(26, 17);
    printf("        Tipo do bem: ");
    gotoxy(26, 19);
    printf("       Valor do bem:");
    Caixa(26,22,68,1,0);
    gotoxy(28,23);
    printf("Mensagem:");

}
Grupo CadastroGrupos()
{
    fflush(stdin);
    Grupo G;
    tipocursor(1);
    char opcao;
    int aux;
    do
    {
        fseek(f,-sizeof(Grupo),SEEK_END);
        fread(&G,sizeof(Grupo),1,f);
        G.numerogrupo+=1;
        gotoxy(47,  11);
        printf("%d",G.numerogrupo);
        gotoxy(47,  13);
        scanf("%d",&G.numerodecotas);
        gotoxy(47, 15);
        scanf("%lf",&G.valorcota);
        gotoxy(47, 17);
        scanf(" %[^\n]",G.tipobem);
        gotoxy(47, 19);
        scanf("%lf",&G.valorbem);
        strcpy(G.status,"Criado");
        G.quantidadeparc=G.valorbem/G.valorcota;
        for(int i=0; i<G.numerodecotas; i++)strcpy(G.clientes[i],"Vazio");
        aux=G.valorbem;
        for(int i=0; i<G.numerodecotas; i++){
            G.Cotas[i]=aux;
        }
        G.cont=0;
        fseek(f,0,SEEK_END);
        fwrite(&G,sizeof(Grupo),1,f);
        gotoxy(38,23);
        printf("Deseja continuar?(S/N)");
        opcao=getche();
        if(opcao=='N' || opcao=='n') break;
        else if(opcao=='S' || opcao=='s')
        {
    gotoxy(47,  11); printf("%*s", 40, " ");
    gotoxy(47,  13); printf("%*s", 40, " ");
    gotoxy(47, 15); printf("%*s", 40, " ");
    gotoxy(47, 17); printf("%*s", 40, " ");
    gotoxy(47, 19); printf("%*s", 40, " ");
    gotoxy(50, 23); printf("%*s", 10, " ");
            continue;
        }
        else break;
    }
    while(1);
    return G;
}
int   MenuAlterarExcluirG()
{
    int opcao;
    char OpcoesAlterar[][20]= {"Numero do grupo"};
    int xAlterar[]= {62};
    int yAlterar[]= {4};
    textcoloreback(LIGHT_BLUE, BLACK);
    Caixa(20,2, 80, 24, 1);
    textcoloreback(YELLOW, BLACK);
    Caixa(25,6, 70, 18, 1);
    Caixa(26,22,68,1,0);
    gotoxy(28,23);
    printf("Mensagem:");
    textcoloreback(LIGHT_BLUE, BLACK);
    Caixa(30, 3, 60, 1,1);
    textcoloreback(YELLOW, BLACK);
    gotoxy(31,4);
    printf("Por qual forma deseja alterar:");
    gotoxy(52,4);
    opcao=Menu(xAlterar, yAlterar, OpcoesAlterar,1);
    return opcao;
    system("pause");
}
void  ExcluirGrupo()
{
    system("cls");
    int opcao;
    char OpcoesAlterar[][20]= {"Numero do grupo",};
    int xAlterar[]= {62};
    textcoloreback(YELLOW, BLACK);
    int yAlterar[]= {4,4};
    textcoloreback(LIGHT_BLUE, BLACK);
    Caixa(20,2, 80, 24, 1);
    Caixa(25,6, 70, 18, 1);
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
    char opcao1;
    Grupo receber,procurar;
    if(opcao==0)
    {
        gotoxy(27,8);
        printf("Digite o numero do grupo:");
        gotoxy(52,8);
        scanf("%d",&receber.numerogrupo);
        fseek(f,0,SEEK_SET);
        while(fread(&procurar,sizeof(Grupo),1,f))
        {
            ;
            if(procurar.numerogrupo==receber.numerogrupo)
            {
                break;
            }
        }
        gotoxy(27,  11);
        printf("  Numero do grupo:%d ",procurar.numerogrupo);
        gotoxy(26, 14);
        printf("       Tipo de bem:%s ",procurar.tipobem);
        gotoxy(26, 17);
        printf("      Valor do bem:%.3lf ",procurar.valorbem);
        gotoxy(27,20  );
        printf("       Valor cota:%.3lf ",procurar.valorcota);
        gotoxy(70,14  );
        printf("   Quant. de cotas:%d ",procurar.numerodecotas);
        gotoxy(70,11  );
        printf("Quant. de parcelas:%d ",procurar.quantidadeparc);
        //gotoxy(28,  3); printf("%*s", 68, " ");
        //gotoxy(28,  4); printf("%*s", 68, " ");
        //gotoxy(28,  5); printf("%*s", 68, " ");
        gotoxy(27,  8);
        printf("%*s", 38, " ");
    }
    gotoxy(38,23);
    printf("Deseja Continuar(S/N)?");
    fflush(stdin);
    gotoxy(60,23);
    scanf("%c",&opcao1);
    FILE*fx;
    fx=fopen("Reserva.txt","wb");
    if(opcao1=='S' || opcao1=='s')
    {
        fseek(f,0,SEEK_SET);
        while(fread(&procurar,sizeof(Grupo),1,f))
        {
            if((procurar.numerogrupo!=receber.numerogrupo))
            {
                fwrite(&procurar,sizeof(Grupo),1,fx);
            }
        }
        fclose(f);
        fclose(fx);
        remove("ArquivoGrupo.txt");
        rename("Reserva.txt","ArquivoGrupo.txt");
    }
    f=fopen("ArquivoGrupo.txt","rb+");
}
void  Listargrupo()
{
    fflush(stdin);
    system("cls");
    Grupo x;
    textcoloreback(YELLOW, BLACK);
    Caixa(0, 0, 27, 1,1);
    gotoxy(6,1);
    printf("Lista de grupos:");
    Caixa(0, 3, 27, 1,1);
    gotoxy(6,4);
    printf("Quant. de grupos:");


    fseek(f,sizeof(Grupo),SEEK_SET);
    int a=6,b=7,c=11;
    while(fread(&x,sizeof(Grupo),1,f)==1)
    {
        Caixa(0, a, 100, 3,1);
        gotoxy(1,b);
        printf("N.Grupo");
        gotoxy(1,b+1);
        for(int i=0; i<7; i++)printf("%c",196);
        gotoxy(1,b+2);
        printf("%d",x.numerogrupo);
        gotoxy(11,b);
        printf("Tipo de bem");
        gotoxy(11,b+1);
        for(int i=0; i<13; i++)printf("%c",196);
        gotoxy(11,b+2);
        printf("%s",x.tipobem);
        gotoxy(26,b);
        printf("Valor do bem");
        gotoxy(26,b+1);
        for(int i=0; i<17; i++)printf("%c",196);
        gotoxy(26,b+2);
        printf("%.3lf",x.valorbem);
        gotoxy(45,b);
        printf("N.Cotas");
        gotoxy(45,b+1);
        for(int i=0; i<7; i++)printf("%c",196);
        gotoxy(45,b+2);
        printf("%d",x.numerodecotas);
        gotoxy(53,b);
        printf("Valor cota");
        gotoxy(53,b+1);
        for(int i=0; i<10; i++)printf("%c",196);
        gotoxy(53,b+2);
        printf("%.3lf",x.valorcota);
        gotoxy(65,b);
        printf("Quant. de parcelas");
        gotoxy(65,b+1);
        for(int i=0; i<18; i++)printf("%c",196);
        gotoxy(65,b+2);
        printf("%d",x.quantidadeparc);
        gotoxy(86,b);
        printf("Status");
        gotoxy(86,b+1);
        for(int i=0; i<6; i++)printf("%c",196);
        gotoxy(86,b+2);
        printf("%s",x.status);
        gotoxy(0,c);
        printf("Clientes:\n\n");
        for(int i=0; i<x.numerodecotas; i++)
        {
            printf("%d contemplado-->Nome:%s\n",i+1,x.clientes[i]);
        }
         for(int i=0; i<120; i++)printf("%c",196);

         printf("\n");
        if(x.numerodecotas>4)
        {
            a+=7+x.numerodecotas;
            b+=7+x.numerodecotas;
            c+=7+x.numerodecotas;
            }else
            {
                a+=12;
                b+=12;
                c+=12;
            }
        }
    gotoxy(46,1);
    system("pause");
    }
void  ProcurarGrupo()
{

    char ch='s';
    do
    {
        system("cls");
        int opcao;
        int verificador=2;
        Grupo receber,procurar;
        char OpcoesAlterar[][20]= {"Numero do grupo"};
        int xAlterar[]= {62};
        int yAlterar[]= {4};
        textcoloreback(LIGHT_BLUE, BLACK);
        Caixa(20,2, 80, 24, 1);
        textcoloreback(YELLOW, BLACK);
        Caixa(25,6, 70, 18, 1);
        Caixa(26,22,68,1,0);
        gotoxy(28,23);
        printf("Mensagem:");
        textcoloreback(LIGHT_BLUE, BLACK);
        Caixa(30, 3, 60, 1,1);
        textcoloreback(YELLOW, BLACK);
        gotoxy(31,4);
        printf("Por qual forma deseja procurar:");
        gotoxy(52,4);
        opcao=Menu(xAlterar, yAlterar, OpcoesAlterar,1);
        if(opcao==0)
        {

            gotoxy(27,8);
            printf("Digite o num.grupo:");
            gotoxy(46,8);
            scanf(" %d",&receber.numerogrupo);
            fseek(f,0,SEEK_SET);
            while(fread(&procurar,sizeof(Grupo),1,f))
            {
                if(procurar.numerogrupo==receber.numerogrupo)
                {

                    break;
                    verificador=1;
                }
                if(verificador==2)
                {
                    procurar.numerogrupo=0;
                    strcpy(procurar.tipobem,"Vazio");
                    procurar.valorbem=0;
                    procurar.numerodecotas=0;
                    procurar.valorcota=0;
                    procurar.quantidadeparc=0;

                }
            }
            gotoxy(26,  11);
            printf("  Numero do grupo:%d ",procurar.numerogrupo);
            gotoxy(26, 14);
            printf("       Tipo de bem:%s ",procurar.tipobem);
            gotoxy(26, 17);
            printf("      Valor do bem:%.2lf ",procurar.valorbem);
            gotoxy(27,20  );
            printf("       Valor cota:%.2lf ",procurar.valorcota);
            gotoxy(70,14  );
            printf("   Quant. de cotas:%d ",procurar.numerodecotas);
            gotoxy(70,11  );
            printf("Quant. de parcelas:%d ",procurar.quantidadeparc);
            gotoxy(27,8);
            printf("%*s", 68, " ");
        }
        fflush(stdin);
        gotoxy(38, 23);
        printf("Deseja fazer nova busca?(S/N)");
        gotoxy(68,23);
        ch=getchar();
    }
    while(ch=='s'||ch=='S');
}
