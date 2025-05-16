#ifndef CREAR_CUENTA_H_INCLUDED
#define CREAR_CUENTA_H_INCLUDED

/// Crear nueva cuenta
void crear(struct cliente *clientes, int *numClientes) {
struct cliente *clienteNuevo = &clientes[*numClientes];
printf("INGRESA TU NOMBRE: ");
getchar();
fgets(clienteNuevo->nombre, sizeof(clienteNuevo->nombre), stdin);
strtok(clienteNuevo->nombre, "\n");
printf("INGRESA TU APELLIDO: ");
fgets(clienteNuevo->apellido, sizeof(clienteNuevo->apellido), stdin);
strtok(clienteNuevo->apellido, "\n");
printf("INGRESA UN NIP (4 DIGITOS): \n");
scanf("%d", &clienteNuevo->nip);
printf("INGRESA UN SALDO INICIAL: \n");
scanf("%f", &clienteNuevo->saldo);

for (int i = 0; i < 10; i++) {
clienteNuevo->movimientos[i] = 0;
}
clienteNuevo->nCliente = *numClientes + 1;
(*numClientes)++;
printf("\nCUENTA CREADA CON EXITO. TU NUMERO DE CUENTA ES: %d\n", clienteNuevo->nCliente);
}

#endif // CREAR_CUENTA_H_INCLUDED
