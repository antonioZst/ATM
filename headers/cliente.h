#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int nCliente;
    int nip;
    char nombre[50];
    char apellido[50];
    float saldo;
    int movimientos[10];
} cliente;

#endif // CLIENTE_H_INCLUDED
