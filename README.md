--------------------------------------------------------------------- ATM ---------------------------------------------------------------------
*** GUIA DE USUARIO***
El proposito de esta guia de usuario es facilitar el uso de la aplicacion ATM y entender su funcionamiento.
Menu principal.
En el menu principal tenemos 6 opciones disponibles:
1. Login/ iniciar sesión 
2. Búsqueda
3. Depósito
4. Crear Cuenta
5. Salir
6. Guardar o exportar.

-- Login --
Se pide introducir el numero de cuenta que se desea manejar en ese momento (en caso de ya exista la cuenta)
ademas del nip. Si los datos introducidos son correctos
al usuario se le muestra otro menu, en el que puede realizar las siguientes acciones:
1. consultar saldo
2. retirar efectivo
3. depositar efectivo
4. salir de la cuenta y regresar al menu principal

Consultar saldo
Esta opcion permite visualizar el saldo disponible actual en la cuenta y luego se vuelve a mostrar el menu principal.

Retirar efectivo
Pide introducir la cantidad a retirar, la cual puede ser escrita como numero entero, es decir, sin decimales o como numero decimal. Si la cantidad introducida es mayor al saldo disponible se le muestra al usuario un mensaje de aviso y se le regresa al menu de acciones, pero si la cantidad no supera al saldo y ademas esta es mayor a cero, se pide la confirmacion de la accion y solo si la respuesta es afirmativa se realiza el retiro, se le descuenta el dinero y se le regresa al menu de acciones.

Depositar efectivo
De igual manera que para retirar se pide la cantidad deseada para depositar, en este caso la unica condicion sera que la misma no sea menor a 0 si lo es, se le mostrara un aviso y se le enviara al menu de acciones. 
En caso de que la cantidad sea correcta, se pide confirmacion y si se confima la cantidad es depositada en la cuenta y pasa a ser saldo disponible.

**Cuando se retira o deposita una cantidad, al final se le muestra al usuario el saldo ya actualizado**

Salir de la cuenta
Esta opcion nos regresa al menu principal, de manera que se cierra la sesion.

-- Busqueda --
Esta opcion permite localizar el numero de una cuenta por medio del nombre. Se pide introducir el nombre y si este es encontrado se le regresa su numero de cuenta.

-- Crear cuenta --
Si el usuario no tiene una cuenta, se le da la opcion de crear una, requiriendo los siguientes datos para crearla:

nombre(no mayor a cincuenta caracteres)
apellido(no mayor a cincuenta caracteres) 
nip(el cual sera un numero entero de cuatro digitos)
saldo
Si los datos ingresados son correctos, la cuenta es creada con exito y se le regresa su numero de cliente.

-- Guardar o exportar --
**Esta opcion solo esta disponible para administradores** 
La cual al ser seleccionada se pide un usuario y contraseña, si los datos son correctos, es decir, se trata de un administrador, se le muestra un menu simple donde puede guardar la informacion actual de todos los clientes o exportarla en formato json, al finalizar la accion se le regresa al menu principal.
#instalacion y ejecucion del programa cajero_automatico.c 
-- Salir --
Termina la ejecucion del programa completamente.
*** FIN DE GUIA DE USUARIO ***

## A continuacion se describiran los pasos necesarios para instalar, compilar y ejecutar el programa de cajero automatico desarrollado en lenguaje c:

## archivos necesarios: 

**main.c** 
Contiene la funcion principal del programa.
**cajero.h** 
Contiene las funciones necesarias para el funcionamiento del programa.
**archivo.txt** 
Archivo de texto donde se guardara la informacion de los clientes, si este no existe sera creado automaticamente por el programa. 

## requisitos del sistema:

Antes de descargar los archivos del programa asegurese de contar con: 
*un sistema operativo que funcione con c. 
*un entorno de desarrollo integrado (IDE) o herramientas de compilación.
*un compilador de C como **gcc**
*un editor de texto. 
*acceso a la linea de comandos o terminal.
(este programa fue creado originalmente en windows utilizando como IDE codeblocks).

## Estructura del Proyecto

Coloca los siguientes archivos en un mismo directorio:
cajero/
main.c
cajero.h
saldo.txt

# instrucciones para la instalacion y compilacion del programa:

### Paso 1: Crear los archivos fuente

Descarga los dos archivos ejecutables desde github: `main.c` y `cajero.h`.
y colocalos en el directorio cajero/

### Paso 2: Compilar el programa

Abre una terminal y navega al directorio donde están los archivos (cajero/). 
para compilar el programa es necesaerio convertir el archivo.c en un ejecutable .exe
El proceso de compilación en C consta de cuatro pasos: preprocesamiento, compilación, ensamblaje y enlace.

### Paso 3: Ejecutar el programa

Después de compilar, ejecuta el programa con:

cajero.exe # 
  **fin de la guia de instalacion y compilacion**


