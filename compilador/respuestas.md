#Titulo
 
##Respuesta 1

###Pre-procesador: gcc -E calculator.c -o calculator.pp_c 
En esta parte de la compilacion el compilador se encarga de encontrar las librerias que necesita el programa principal. Crea un archivo con calculator.pp_c el cual contiene los "#include" ademas del programa principal. 

### Compilacion I: Assembler: gcc -masm=intel -S calculator.c -o calculator.asm
A partir de ahora el compilador es "agnostico del lenguaje". El compilador crea un archivo calculator.asm el cual no sabe en que lenguaje escribiste el codigo pero te da informacion del nombre del codigo y te lo escribe en algun tipo de lenguaje .asm.

### Compilacion II: Object: gcc -c calculator.c -o calculator.o
En esta etapa se genera un archivo calculator.o a partir del .asm.
El archivo .0 esta ahora escrito en un codigo (lenguaje) de maquina.
Es decir, genera objetos en binario.

### Linkeo: gcc calculator.o -o calculator.e
Una vez que tengo el codigo escrito en binarios puedo generar un archivo ejecutable, "calculator.e", que me permitira ejecutar el programa calculator.c.

##Respuesta 2:
El pre-procesador genero el archivo calculator.pp_c. Ademas del programa calculator.c incluye calculator.h y stdio.h.

##Respuesta 3:
El archivo calculator.asm reconoce como funciones a main y a add_numbers.
.type	main, @function
.type	add_numbers, @function

Observacion: Dentro de la funcion main se lama (call) a la funcion printf pero en principio el .asm no sabe que es una funcion.

##Respuesta 4: "nm calculator.o"
Mayusculas: Global
Minusculas: Local
T/t : texto/funcion (code)
R/r : read only
D/d : data
U/u : indefinido (esta declarado pero no definido)

T add_numbers --> funcion global
T main        --> funcion global
U printf      --> indefinido global

(https://www.mkssoftware.com/docs/man1/nm.1.asp)

##Respuesta 5: "nm calculator.e"
Los simbolos que aparecen en el objeto tambien aparecen en el ejecutable. 
Para T add_numbers y T main solo cambia la direccion de memoria.
En cambio, en el .e, U printf aparece modificado: U printf@@GLIBC\_2.2.5 . Esto indica que a la funcion printf  la va a buscar en la libreria "GLIBC_2.2.5". Esta informacion se la da el gcc (stdio es intrinseco de C).

Dato extra: en el ejecutable aprecen mas simbolos.


