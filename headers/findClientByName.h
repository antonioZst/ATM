#ifndef FINDCLIENTBYNAME_H_INCLUDED
#define FINDCLIENTBYNAME_H_INCLUDED

int findClient(cliente clientes[], int sizeClientes){
    char name[50];
    char lastName[50];
    printf("Introduzca nombre: ");
    scanf("%s", name);
    printf("Introduzca apellido: ");
    scanf("%s", lastName);
    for(int i = 0; i < sizeClientes; i++){
        if(strcmp(name, clientes[i].nombre) == 0 && strcmp(lastName, clientes[i].apellido) == 0){
            return clientes[i].nCliente;
        }
    }
    return -1;
}


#endif // FINDCLIENTBYNAME_H_INCLUDED
