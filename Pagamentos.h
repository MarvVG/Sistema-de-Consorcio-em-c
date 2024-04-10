#ifndef PAGAMENTOS_H_INCLUDED
#define PAGAMENTOS_H_INCLUDED
#include "Interface.h"
#include "Vendas.h"
#include "Grupo.h"
#include "Cliente.h"
FILE*fpag;
typedef struct{
double parecelas;
char contemplados[1000][51];
int contem[1000];
}Pagamento;
void Realizarpagamento();
#endif // PAGAMENTOS_H_INCLUDED
