#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED
#include "Interface.h"
FILE*f;
typedef struct{
int numerogrupo;
double valorcota;
double valorbem;
char tipobem[31];
int numerodecotas;
char status[21];
char statuscliente[21];
int quantidadeparc;
int cont;
char clientes[1000][61];
double Cotas[1000];
}Grupo;
void TelaGrupos();
Grupo CadastroGrupos();
void AtivarCota();
void ExcluirGrupo();
void Listargrupo();
void ProcurarGrupo();
int MenuAlterarExcluirG();


#endif // GRUPO_H_INCLUDED
