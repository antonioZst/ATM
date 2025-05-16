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
  
##**Explicación/Descripcion de las cuentas**

**Características**

Las características principales de la estructura cliente que es donde se encuentra almacenada toda la información de las cuentas, es que están definidos tres datos de tipo int los cuales son nCliente, nip y movimientos.

El tipo de dato entero definido como nCliente contendrá el número de la cuenta de cada cliente, el cual será fundamental para el funcionamiento de la función login la cual se describe más adelante.

El tipo de dato entero definido como nip contendrá la contraseña del usuario la cual será de 4 dígitos.

El último dato de tipo entero está definido como movimientos el comienza en cero termina en 10 (ya que guardará los últimos 10 movimientos que haga el usuario) y almacenará la cantidad de movimientos que hace el usuario y también informará con números negativos (si se trata de un retiro) o con números positivos (si se trata de un depósito) los movimientos del usuario.

También se encuentran definidos dos datos de tipo char (cadenas) los cuales son Nombre y Apellido los cuales son arreglos de 50 elementos cada uno. 

Ambos arreglos de carácter almacenarán el nombre del usuario y sus apellidos (respectivamente), los cuales serán fundamentales para el correcto funcionamiento de la función crear cuenta y búsqueda.

Por último tiene un tipo de dato de tipo float el cual almacena el saldo que contiene cada cuenta.

**Acciones**

Las acciones que se pueden realizar con las cuentas son consultar saldo, depositar, retirar, buscar, crear cuentas.

En la función de consultar el saldo de la cuenta, lo que regresa es el saldo que contiene esa cuenta después de retirar o depositar el saldo. Lo que requiere esta función para que funcione es que la cuenta en cuestión se encuentre registrada en el sistema con sus respectivos datos (esto se hace mediante la función crear cuenta), además de eso recibe un tipo de dato flotante denominada como saldo para que pueda funcionar, también recibe una función constante denominada como consultar saldo.

En la función de depositar saldo, lo que regresa es es un printf o imprimir en pantalla dependiendo de los datos ingresados por el usuario al momento de ingresar una cantidad para depositar, si la cantidad es menor o igual a cero el programa regresa el mensaje “CANTIDAD NO VÁLIDA” esto mediante un int llamado valida, el cual contiene una estructura llamada cliente con un paso de parámetros * cliente, un tipo de dato flotante definido como cantidad y un tipo de dato carácter definido como tipo, Si tipo es igual a d o D (refiriendose al deposito) el programa escribe “DEPÓSITO REALIZADO CON ÉXITO. TU NUEVO SALDO ES:” Mostrando al usuario el nuevo saldo registrado en el sistema.

En la función de retirar, lo que regresa es un printf también dependiendo de los datos ingresados por el usuario al momento de ingresar una cantidad para retirar, mediante un condicional if se verifica si la cantidad ingresada es mayor al saldo que tiene el cliente, si esto ocurre el programa devolverá el mensaje “SALDO INSUFICIENTE”, en caso contrario mediante un paso de parámetros se verifica si el saldo del cliente es mayor a la cantidad a retirar si esto ocurre el programa generará el mensaje RETIRO REALIZADO CON ÉXITO. TU NUEVO SALDO ES:”. Mostrando el nuevo saldo del usuario después del retiro

En la función de buscar, lo que regresa es el número de la cuenta es el número de la cuenta del usuario, esto debido a un tipo de dato int, el cual tiene como parámetros un arreglo de carácteres denominado name, un arreglo denominado clientes y otro int denominado sizeClientes, también debido a un bucle for con un entero definido como i que está igualado a 0, hasta que i sea menor que sizeClientes, i ++.

En la función de crear cuenta, lo que regresa es una cuenta nueva, esto debido a una función void denominada como crear, la cual tiene como parámetros una estructura  denominada cliente y paso de parámetros llamado cliente, y un tipo de dato entero definido como numClientes el cual también es un paso de parámetros, luego otra estructura cliente con varios pasos de parametros, se le pide al usuario que ingrese varios datos como su nombre, sus apellidos, un nip o contraseña la cual será de 4 dígitos y un saldo inicial, todo esto a base varios pasos de parametros, despues de esto mediante un bucle for se incrementa en uno el número de usuarios que contiene el programa. 


