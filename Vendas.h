#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED
typedef struct{
char data[15];
int numerovenda;
}Vendas;
FILE*fv;
void Ativarvendas();
void ListarVendas();
#endif // VENDAS_H_INCLUDED
