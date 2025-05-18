#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

void login(cliente *cliente){//Funcion login
    int option, numeroCliente, contrasena;
    int intento = 3;
    float quantity = 0;

    printf("Ingrese su numero de cuenta: \t\n");
    scanf("%d", &numeroCliente);

    printf("Ingrese su nip de 4 digitos: \t\n");
    scanf("%d", &contrasena);

    if(numeroCliente == cliente->nCliente && contrasena == cliente->nip){
    do{
        printf("Que accion desea realizar?: \t\n");
        printf("1. Consultar Saldo\n");
        printf("2. Consultar Historico\n");
        printf("3. Retiro\n");
        printf("4. Salir\n");
        printf("Elija una opcion: \t");
        scanf("%d", &option);
        switch(option){
        case 1:
            printf("Su saldo actual es: %.2f\t\n", cliente->saldo);
            break;
        case 2:
            for(int i = 0; i <= 10; i++){
                if(cliente->movimientos[i] < 0){
                    printf("retiro: %d$\n", cliente->movimientos[i]);
                }
                else{
                    printf("deposito: %d$\n", cliente->movimientos[i]);
                }
            }
        case 3:
            printf("Introduzca la cantidad que desea retirar: ");
            scanf("%f", &quantity);
            if(quantity > cliente->saldo){
                printf("cantidad no disponible para retirar, supera el limite de cuenta\n");
            }
            else{
                int ans = 0;
                printf("Esta seguro que desea continuar con la operacion?\n1. si\n2. no");
                scanf("%d", &ans);
                if(ans == 1){
                    cliente->saldo -= quantity;
                    printf("saldo actual: %.2f\n", cliente->saldo);
                    printf("accion realizada con exito\n");
                }
            }
            break;
        case 4:
            break;

        default:
            printf("\nEse numero no pertenece a las opciones ingresa un numero valido\n\n");
            break;
    }

}while(intento > 0 && option !=4);
}else{
     printf("\nEl PIN  o  el numero de cuenta ingresado es incorrecto, intentelo de nuevo\n");
     intento --;
}
}

#endif // LOGIN_H_INCLUDED
