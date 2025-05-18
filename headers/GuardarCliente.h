#ifndef GUARDARCLIENTE_H_INCLUDED
#define GUARDARCLIENTE_H_INCLUDED
#include<ctype.h>

void guardarClientes(cliente Persona[], int cantidad);
void EncriptacionArchivo();
void DescifradoArchivo();

//Funcion para guardar el contenido de la estructuras en un archivo
void guardarClientes(cliente Persona[], int cantidad){

    //En esta funcion creamos el archivo y agregamos los datos, uno siguiente de otro
    FILE *f;
    if(fopen("clientes.txt","r") == NULL){
        f = fopen("clientes.txt","a");
        for(int i = 0; i<cantidad; i++){
            if(f != NULL){
            fprintf(f, "nCliente: %d\n",Persona[i].nCliente);
            fprintf(f, "NIP: %d\n",Persona[i].nip);
            fprintf(f, "Nombre: %s\n",Persona[i].nombre);
            fprintf(f, "Saldo: %.2f\n",Persona[i].saldo);

            }
        }
        fclose(f);
        f = NULL;

    }

    /*
    Una vez creado el archivo con los datos iniciales, en esta funcion sobreescribimos los datos dependiendo de los movimientos
    Es decir, si el cliente deposita, se sobreescribe el saldo anterior por el nuevo saldo
    */
    if(fopen("clientes.txt","r") != NULL){
        f = fopen("clientes.txt","w");
        for(int i = 0; i<cantidad; i++){
            if(f != NULL){
            fprintf(f, "nCliente: %d\n",Persona[i].nCliente);
            fprintf(f, "NIP: %d\n",Persona[i].nip);
            fprintf(f, "Nombre: %s\n",Persona[i].nombre);
            fprintf(f, "Saldo: %.2f\n",Persona[i].saldo);

            }
        }
        fclose(f);
        f=NULL;
    }

}

//Funcion para Encriptar el contenido del archivo (Lo pasa a un nuevo archivo llamado encriptacion.txt)
void EncriptacionArchivo(){
    //Cifrado Cesar
    char caracter;
    FILE *f;
    FILE *Salida;
    f = fopen("clientes.txt","r");
    Salida = fopen("encriptacion.txt","w");
    if(f==NULL){
        printf("\nEl archivo no se a creado\n\n");
    }
    else{
        while((caracter = fgetc(f)) != EOF){
            if(isupper(caracter)){
                caracter = ((caracter - 'A' + 3)% 26 + 26) % 26 + 'A';
            }
            else if(islower(caracter)){
                caracter = ((caracter - 'a' + 3)% 26 + 26) % 26 + 'a';
            }
            fputc(caracter,Salida);
        }

        fclose(f);
        f=NULL;
        f = fopen("clientes.txt","w");//Borramos la informacion del archivo
        fclose(f);
        f=NULL;
        fclose(Salida);
        Salida=NULL;
    }

}

//Funcion para Decencriptar el contenido del archivo(Lo pasa al anterior archivo clientes.txt)
void DescifradoArchivo(){
    char caracter;
    FILE *f;
    FILE *Salida;

    Salida = fopen("encriptacion.txt","r");
    f = fopen("clientes.txt","w");
    if(Salida==NULL){
        printf("\nEl archivo no se a creado\n\n");
    }
    else{
        while((caracter = fgetc(Salida)) != EOF){
            if(isupper(caracter)){
                caracter = ((caracter - 'A' - 3+26)% 26 + 26) % 26 + 'A';
            }
            else if(islower(caracter)){
                caracter = ((caracter - 'a' - 3+26)% 26 + 26) % 26 + 'a';
            }
            fputc(caracter,f);

        }
        fclose(f);
        f=NULL;
        fclose(Salida);
        Salida=NULL;
        Salida = fopen("encriptacion.txt","w"); //Borramos la informacion del archivo
        fclose(Salida);
        Salida=NULL;
    }
}

#endif // GUARDARCLIENTE_H_INCLUDED
