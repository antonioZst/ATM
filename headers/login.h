#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include"GuardarCliente.h"

int login(cliente *clientes, int sizeClientes) {
    int option, numeroCliente, contrasena;
    float quantity = 0;
    cliente *seleccionado = NULL;

    printf("Ingrese su numero de cuenta: \t\n");
    scanf("%d", &numeroCliente);

    printf("Ingrese su nip de 4 digitos: \t\n");
    scanf("%d", &contrasena);

    // Buscar al cliente
    for(int i = 0; i < sizeClientes; i++) {
        if(numeroCliente == clientes[i].nCliente && contrasena == clientes[i].nip) {
            seleccionado = &clientes[i];
            break;
        }
    }

    if(seleccionado == NULL) {
        printf("Datos incorrectos. Acceso denegado.\n");
        return 0;
    }

    do {
        printf("\nQue accion desea realizar?: \t\n");
        printf("1. Consultar Saldo\n");
        printf("2. Consultar Historico\n");
        printf("3. Retiro\n");
        printf("4. Salir\n");
        printf("Elija una opcion: \t");
        scanf("%d", &option);

        switch(option){
        case 1:
            printf("Su saldo actual es: %.2f\n", seleccionado->saldo);
            break;

        case 2:
            printf("Historial de movimientos:\n");
            for(int i = 0; i < 10; i++){
                if(seleccionado->movimientos[i] == 0) continue;
                if(seleccionado->movimientos[i] < 0)
                    printf("Retiro: %.2f$\n", seleccionado->movimientos[i] * -1);
                else
                    printf("Deposito: %.2f$\n", seleccionado->movimientos[i]);
            }
            break;

        case 3:
            printf("Introduzca la cantidad que desea retirar: ");
            scanf("%f", &quantity);
            if(quantity > seleccionado->saldo){
                printf("Cantidad no disponible, excede el saldo.\n");
            } else {
                int ans = 0;
                printf("Esta seguro que desea continuar con la operacion?\n1. Si\n2. No\n");
                scanf("%d", &ans);
                if(ans == 1){
                    seleccionado->saldo -= quantity;

                    // Agregar a movimientos
                    for (int i = 0; i < 10; i++) {
                        if (seleccionado->movimientos[i] == 0) {
                            seleccionado->movimientos[i] = -quantity;
                            break;
                        }
                    }

                    printf("Saldo actual: %.2f\n", seleccionado->saldo);
                    printf("Accion realizada con exito\n");
                }
            }
            guardarClientes(clientes, 3);
            break;

        case 4:
            printf("Saliendo del menú de cuenta...\n");
            break;

        default:
            printf("Opcion invalida, intente de nuevo.\n");
        }

    } while(option != 4);

    return 1;
}

#endif // LOGIN_H_INCLUDED
