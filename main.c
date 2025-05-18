#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "login.h"
#include "crearCuenta.h"
#include "deposito.h"
#include "findClientByName.h"
#include "GuardarCliente.h"
#include<ctype.h>

int accountsMenu(){
    int position;
    printf("Cuenta: 1, 2 o 3?\n");
    scanf("%d", &position);
    return position;
}

cliente menu(int nCliente, cliente clientes[], int sizeClientes){
    for(int i = 0; i < sizeClientes; i++){
        if(clientes[i].nCliente == nCliente){
            return clientes[i];
        }
    }
    cliente vacio = {-1, 12, "juan", 1200};
    return vacio;
}

int main()
{
    cliente clientes[100] = {
        {1, 1234, "Christian", "Cruz", 1000, {10, -20}},
        {2, 1234, "Jose", "Rodriguez", 2000},
        {3, 1234, "Manuel", "Campos", 3000},
    };
    int ans,contasena=1234,resp;
    int numeroClientes = 100;
    do{
    printf("\n---------------Menu principal---------------\n");
    printf("1) Login/iniciar sesion\n");
    printf("2) Busqueda\n");
    printf("3) Deposito\n");
    printf("4) Crear cuenta\n");
    printf("5) Salir\n");
    printf("6) Guardar o exportar\n");
    printf("7) Encriptar\n");
    printf("8) Desencriptar\n");
    scanf("%d", &ans);
    switch(ans){
    case 1:
        login(clientes, numeroClientes);
        break;
    case 2:
        printf("numero de cuenta: %d",findClient(clientes, 3));
        break;
    case 3:
        deposito(clientes, 3);
        guardarClientes(clientes, 3);
        break;
    case 4:
        crear(clientes, &numeroClientes);
        break;
    case 5:
        return 0;
    case 6:
        guardarClientes(clientes, 3);
        printf("Datos guardados exitosamente!!\n");
        break;
    case 7:
        printf("\nIngrese la contasena: ");
        scanf("%d",&resp);
        if(resp == contasena){
            EncriptacionArchivo();
            printf("Encriptacion exitosa!!\n");
        }
        else{
            printf("\nContrasena incorrecta, intentalo de nuevo\n");
        }

        break;
    case 8:

        printf("\nIngrese la contasena: ");
        scanf("%d",&resp);
        if(resp == contasena){
            DescifradoArchivo();
            printf("Descencriptacion exitosa!!\n");
        }
        else{
            printf("\nContrasena incorrecta, intentalo de nuevo\n");
        }
        break;
    }
    }while(ans != 5);
}
