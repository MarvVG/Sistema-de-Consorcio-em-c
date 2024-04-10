#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
FILE*fp;
typedef struct{
char Nome[81];
char Telefone[30];
char Cpf[25];
char DataNascimento[11];
char status[31];
}Cliente;
void TelaCliente();
Cliente DigitarCliente();
void Ativarcliente(int n);
int getTecla();
void Listarclientes();
void AlterarCliente();
void Procurarclientes();
void ExcluirCliente();
#endif // CLIENTE_H_INCLUDED
