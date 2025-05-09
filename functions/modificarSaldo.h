#ifndef MODIFICARSALDO_H_INCLUDED
#define MODIFICARSALDO_H_INCLUDED

void modificarSaldo(float *saldo, int cantidad, int op){
    switch(op){
        case 1:
            if(*saldo < cantidad){
                printf("cantidad no disponible para retirar, supera el limite de cuenta\n");
            }
            else{
                *saldo -= cantidad;
                printf("%.2f\n", *saldo);
                printf("accion realizada con exito\n");
            }
            break;
        case 2:
            *saldo += cantidad;
            printf("%.2f\n", *saldo);
            printf("accion realizada con exito\n");
            break;
    }
}

#endif // MODIFICARSALDO_H_INCLUDED
