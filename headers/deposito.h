#ifndef DEPOSITO_H_INCLUDED
#define DEPOSITO_H_INCLUDED

/// Validar operacion depositos y retiros
int valida(cliente *cliente, float cantidad, char tipo) {
if (cantidad <= 0) {
printf("CANTIDAD NO VALIDA.\n");
return 101;
}
if (tipo == 'd' || tipo == 'D') {
cliente->saldo += cantidad;
printf("DEPOSITO REALIZADO CON EXITO. TU NUEVO SALDO ES: %.2f\n", cliente->saldo);
return 0;
} else if (tipo == 'r' || tipo == 'R') {
if (cantidad > cliente->saldo) {
printf("SALDO INSUFICIENTE.\n");
return 102;
}
cliente->saldo -= cantidad;
printf("RETIRO REALIZADO CON EXITO. TU NUEVO SALDO ES: %.2f\n", cliente->saldo);
return 0;
} else {
printf("TIPO DE OPERACION NO VALIDA.\n");
return 103;
}
}
///deposito   incluye funcion valida
void deposito(cliente clientes[],int totalClientes){
int ncuenta, resultado;
float cantidad;
int encontrado=0;
printf("INGRESA EL NUMERO DE LA CUENTA A LA QUE DESEA DEPOSITAR: \n");
scanf("%d",&ncuenta);
for(int i = 0; i < totalClientes; i++){
if(clientes[i].nCliente==ncuenta){
encontrado=1;
printf("INGRESA LA CANTIDAD A DEPOSITAR:\n");
scanf("%f",&cantidad);
resultado=valida(&clientes[i],cantidad,'d');
if(resultado==0){
printf("DEPOSITO EXITOSO PARA LA CUENTA %d.\n",ncuenta);
}
return;
}
}
if(!encontrado){
printf("ERROR! CUENTA NO ENCONTRADA \n");
}
}

#endif // DEPOSITO_H_INCLUDED
