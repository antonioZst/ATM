#ifndef FINDCLIENTBYNAME_H_INCLUDED
#define FINDCLIENTBYNAME_H_INCLUDED

int findClient(char name[], cliente clientes[], int sizeClientes){
    for(int i = 0; i < sizeClientes; i++){
        if(strcmp(name, clientes[i].nombre) == 0){
            return clientes[i].nCliente;
        }
    }
    return -1;
}


#endif // FINDCLIENTBYNAME_H_INCLUDED
