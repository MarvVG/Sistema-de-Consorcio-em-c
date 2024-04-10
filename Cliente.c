#include "Interface.h"
#include "Cliente.h"
void TelaCliente(){
        system("cls");
        textcoloreback(LIGHT_BLUE, BLACK);
        Caixa(20,2 , 80, 24, 1);
        textcoloreback(YELLOW, BLACK);
        Caixa(30, 3, 60, 1,1);
         textcoloreback(YELLOW, BLACK);
        Caixa(25 ,6, 70, 18, 1);
        textcoloreback(YELLOW, BLACK);
        gotoxy(49, 4);
        printf("Consorcio Tio Hevera's");
         gotoxy(26,8);
         for(int i=0;i<25;i++)printf("%c",205);
        gotoxy(50,8);printf("Cadastro de clientes");
        gotoxy(70,8);
         for(int i=0;i<26;i++)printf("%c",205);
    gotoxy(26,  11); printf("             Nome: ");
    gotoxy(26,  14); printf("              Cpf: ");
    gotoxy(26, 17); printf("          Telefone: ");
    gotoxy(26, 20); printf("Data de nascimento: ");
        Caixa(26,22,68,1,0);
        gotoxy(28,23);
        printf("Mensagem:");
}
Cliente DigitarCliente(){
Cliente Cadastro;
tipocursor(1);
char opcao;
do{
    gotoxy(44,  11); scanf(" %[^\n]", Cadastro.Nome);
    gotoxy(44,  14); scanf(" %[^\n]", Cadastro.Cpf);
    gotoxy(45, 17); scanf(" %[^\n]", Cadastro.Telefone);
    gotoxy(45, 20); scanf(" %[^\n]", Cadastro.DataNascimento);
    strcpy(Cadastro.status,"Criado");
    fseek(fp,0,SEEK_END);
    fwrite(&Cadastro,sizeof(Cliente),1,fp);
    gotoxy(38,23);
    printf("Deseja continuar?(S/N)");
    opcao=getche();
    if(opcao=='N' || opcao=='n') break;
    else if(opcao=='S' || opcao=='s') {LimparTelaClienteGrupo();continue;}
    else break;
}while(1);
fflush(fp);
return Cadastro;
}
void Listarclientes(){
system("cls");
Cliente x;
textcoloreback(YELLOW, BLACK);
Caixa(10, 3, 27, 1,1);
gotoxy(16,4);
printf("Lista de clientes:");
fseek(fp,0,SEEK_SET);
int a=6,b=7;
while(fread(&x,sizeof(Cliente),1,fp)==1){
Caixa(10, a, 93, 3,1);
gotoxy(11,b);printf("Nome");
gotoxy(11,b+1);
for(int i=0;i<40;i++)printf("%c",196);
gotoxy(21,b+2);printf("%s",x.Nome);
gotoxy(53,b);printf("CPF");
gotoxy(53,b+1);
for(int i=0;i<17;i++)printf("%c",196);
gotoxy(53,b+2);printf("%s\n",x.Cpf);
gotoxy(71,b);printf("Data nascimento");
gotoxy(71,b+1);
for(int i=0;i<15;i++)printf("%c",196);
gotoxy(71,b+2);printf("%s\n",x.DataNascimento);
gotoxy(87,b);printf("Telefone");
gotoxy(87,b+1);
for(int i=0;i<17;i++)printf("%c",196);
gotoxy(87,b+2);printf("%s",x.Telefone);
a+=5;b+=5;
}
gotoxy(10,1);system("pause");
}
void AlterarCliente(){
    fflush(stdin);
  system("cls");
 int opcao,verificador=2;
 opcao=MenuAlterarExcluir();
 char opcao1;
 Cliente receber,procurar,C;
 if(opcao==0){
    gotoxy(27,8);
    printf("Digite o nome:");
    gotoxy(42,8);scanf(" %[^\n]",receber.Nome);
    fseek(fp,0,SEEK_SET);
    while(!feof(fp)){
        fread(&procurar,sizeof(Cliente),1,fp);
        if(strcmp(procurar.Nome,receber.Nome)==0) {
                break;
        verificador=1;
        }
        if(verificador==2){
            strcpy(procurar.Nome,"Vazio");
            strcpy(procurar.Cpf,"Vazio");
            strcpy(procurar.Telefone,"Vazio");
            strcpy(procurar.DataNascimento,"Vazio");
        }
        }
    gotoxy(27,  11); printf("             Nome:%s ",procurar.Nome);
    gotoxy(27,  14); printf("              Cpf:%s ",procurar.Cpf);
    gotoxy(26, 17); printf("          Telefone:%s ",procurar.Telefone);
    gotoxy(26, 20); printf("Data de nascimento:%s ",procurar.DataNascimento);
    //gotoxy(28,  3); printf("%*s", 68, " ");
    //gotoxy(28,  4); printf("%*s", 68, " ");
    //gotoxy(28,  5); printf("%*s", 68, " ");
    gotoxy(27,  8); printf("%*s", 40, " ");
 }
 if(opcao==1){
 gotoxy(27,8);
    printf("Digite o CPF :");
    gotoxy(42,8);scanf(" %[^\n]",receber.Cpf);
    fseek(fp,0,SEEK_SET);
    while(!feof(fp)){
        fread(&procurar,sizeof(Cliente),1,fp);
        if(strcmp(procurar.Cpf,receber.Cpf)==0) {
                break;
        verificador=1;
        }
        if(verificador==2){
            strcpy(procurar.Nome,"Vazio");
            strcpy(procurar.Cpf,"Vazio");
            strcpy(procurar.Telefone,"Vazio");
            strcpy(procurar.DataNascimento,"Vazio");
        }
        }
    gotoxy(27,  11); printf("             Nome:%s ",procurar.Nome);
    gotoxy(27,  14); printf("              Cpf:%s ",procurar.Cpf);
    gotoxy(26, 17); printf("          Telefone:%s ",procurar.Telefone);
    gotoxy(26, 20); printf("Data de nascimento:%s ",procurar.DataNascimento);
    //gotoxy(28,  3); printf("%*s", 68, " ");
    //gotoxy(28,  4); printf("%*s", 68, " ");
    //gotoxy(28,  5); printf("%*s", 68, " ");
    gotoxy(27,  8); printf("%*s", 40, " ");
 }
    gotoxy(38,23);
    printf("Deseja Continuar(S/N)?");
    fflush(stdin);
    gotoxy(60,23);
    scanf("%c",&opcao1);
    if(opcao1=='S' || opcao1=='s'){
    gotoxy(45,  11); printf("%*s", 40, " ");
    gotoxy(45,  14); printf("%*s", 40, " ");
    gotoxy(45,  17); printf("%*s", 40, " ");
    gotoxy(45,  20); printf("%*s", 40, " ");
    gotoxy(45,  11); scanf(" %[^\n]", C.Nome);
    gotoxy(45,  14); scanf(" %[^\n]", C.Cpf);
    gotoxy(46, 17); scanf(" %[^\n]", C.Telefone);
    gotoxy(46, 20); scanf(" %[^\n]", C.DataNascimento);
    strcpy(C.status,"Criado");
    fseek(fp,-sizeof(Cliente),SEEK_CUR);
    fwrite(&C,sizeof(Cliente),1,fp);
    fflush(fp);
    } else;}
void Procurarclientes(){
fflush(stdin);
    char ch='s';
    do{
    system("cls");
    int opcao;
    int verificador=2;
    Cliente receber,procurar;
    char OpcoesAlterar[][20]={"Nome","Cpf"};
    int xAlterar[]={62,68};
    int yAlterar[]={4,4};
 textcoloreback(LIGHT_BLUE, BLACK);
 Caixa(20,2 , 80, 24, 1);
 textcoloreback(YELLOW, BLACK);
 Caixa(25 ,6, 70, 18, 1);
 Caixa(26,22,68,1,0);
 gotoxy(28,23);
 printf("Mensagem:");
 textcoloreback(LIGHT_BLUE, BLACK);
 Caixa(30, 3, 60, 1,1);
  textcoloreback(YELLOW, BLACK);
 gotoxy(31,4);
 printf("Por qual forma deseja procurar:");
 gotoxy(52,4);
 opcao=Menu(xAlterar, yAlterar, OpcoesAlterar,2);
if(opcao==0){

    gotoxy(27,8);
    printf("Digite o nome:");
    gotoxy(42,8);scanf(" %[^\n]",receber.Nome);
    fseek(fp,0,SEEK_SET);
    while(!feof(fp)){
    fread(&procurar,sizeof(Cliente),1,fp);
        if(strcmp(procurar.Nome,receber.Nome)==0) {

                break;
             verificador=1;
        }
        if(verificador==2){
            strcpy(procurar.Nome,"Vazio");
            strcpy(procurar.Cpf,"Vazio");
            strcpy(procurar.Telefone,"Vazio");
            strcpy(procurar.DataNascimento,"Vazio");
            strcpy(procurar.status,"Vazio");
        }
        }
    gotoxy(27,  8); printf("%*s", 38, " ");
    gotoxy(27,  11); printf("             Nome:%s ",procurar.Nome);
    gotoxy(27,  14); printf("              Cpf:%s ",procurar.Cpf);
    gotoxy(26, 17); printf("          Telefone:%s ",procurar.Telefone);
    gotoxy(26, 20); printf("Data de nascimento:%s ",procurar.DataNascimento);
    gotoxy(75, 14); printf("Status:%s ",procurar.status);
}
if(opcao==1){

    gotoxy(27,8);
    printf("Digite o CPF :");
    gotoxy(42,8);scanf(" %[^\n]",receber.Cpf);
    fseek(fp,0,SEEK_SET);
    while(!feof(fp)){
        fread(&procurar,sizeof(Cliente),1,fp);
        if(strcmp(procurar.Cpf,receber.Cpf)==0) {

                break;
             verificador=1;
        }
        if(verificador==2){
            strcpy(procurar.Nome,"Vazio");
            strcpy(procurar.Cpf,"Vazio");
            strcpy(procurar.Telefone,"Vazio");
            strcpy(procurar.DataNascimento,"Vazio");
            strcpy(procurar.status,"Vazio");
        }
        }
    gotoxy(27,  8); printf("%*s", 38, " ");
    gotoxy(27,  11); printf("             Nome:%s ",procurar.Nome);
    gotoxy(27,  14); printf("              Cpf:%s ",procurar.Cpf);
    gotoxy(26, 17); printf("          Telefone:%s ",procurar.Telefone);
    gotoxy(26, 20); printf("Data de nascimento:%s ",procurar.DataNascimento);
    gotoxy(75, 14); printf("Status:%s ",procurar.status);

}
fflush(stdin);
    gotoxy(38, 23);printf("Deseja fazer nova busca?(S/N)");
    gotoxy(68,23);
    ch=getchar();
    }while(ch=='s'||ch=='S');
}
void ExcluirCliente(){
    fflush(stdin);
 system("cls");
 int opcao;
 opcao=MenuAlterarExcluir();
 char opcao1;
 Cliente receber,procurar;
 if(opcao==0){
    gotoxy(27,8);
    printf("Digite o nome:");
    gotoxy(42,8);scanf(" %[^\n]",receber.Nome);
    fseek(fp,0,SEEK_SET);
   while(fread(&procurar,sizeof(Cliente),1,fp)){;
        if(strcmp(procurar.Nome,receber.Nome)==0) {
                break;
        }
        }
    gotoxy(27,  11); printf("             Nome:%s ",procurar.Nome);
    gotoxy(27,  14); printf("              Cpf:%s ",procurar.Cpf);
    gotoxy(26, 17); printf("          Telefone:%s ",procurar.Telefone);
    gotoxy(26, 20); printf("Data de nascimento:%s ",procurar.DataNascimento);
    gotoxy(60,  12); printf("           Status:%s ",procurar.status);
    //gotoxy(28,  3); printf("%*s", 68, " ");
    //gotoxy(28,  4); printf("%*s", 68, " ");
    //gotoxy(28,  5); printf("%*s", 68, " ");
    gotoxy(27,  8); printf("%*s", 70, " ");
 }
 if(opcao==1){
 gotoxy(27,8);
    printf("Digite o CPF :");
    gotoxy(42,8);scanf(" %[^\n]",receber.Cpf);
    fseek(fp,0,SEEK_SET);
    while(!feof(fp)){
        fread(&procurar,sizeof(Cliente),1,fp);
        if(strcmp(procurar.Cpf,receber.Cpf)==0) {
                break;

        }
        }
    gotoxy(27,  11); printf("             Nome:%s ",procurar.Nome);
    gotoxy(27,  14); printf("              Cpf:%s ",procurar.Cpf);
    gotoxy(26, 17); printf("          Telefone:%s ",procurar.Telefone);
    gotoxy(26, 20); printf("Data de nascimento:%s ",procurar.DataNascimento);
    gotoxy(60,  12); printf("           Status:%s ",procurar.status);
    //gotoxy(28,  3); printf("%*s", 68, " ");
    //gotoxy(28,  4); printf("%*s", 68, " ");
    //gotoxy(28,  5); printf("%*s", 68, " ");
    gotoxy(27,  8); printf("%*s", 70, " ");
 }
    gotoxy(38,23);
    printf("Deseja Continuar(S/N)?");
    fflush(stdin);
    gotoxy(60,23);
    scanf("%c",&opcao1);
            FILE*fx;
        fx=fopen("Reserva.txt","wb");
    if(opcao1=='S' || opcao1=='s'){
        fseek(fp,0,SEEK_SET);
        while(fread(&procurar,sizeof(Cliente),1,fp)){
        if(strcmp(procurar.Nome,receber.Nome)!=0) {
        fwrite(&procurar,sizeof(Cliente),1,fx);
 }
 }
fclose(fp);
 fclose(fx);
 remove("Arquivo.txt");
 rename("Reserva.txt","Arquivo.txt");
}
fp=fopen("Arquivo.txt","rb+");
}
