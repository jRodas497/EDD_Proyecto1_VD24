# Manual Técnico

## Renta de Activos
### Juan Rodas | 202200389 | EDD Sección "A"

## Introducción
Este documento técnico proporciona una descripción detallada del sistema de gestión de activos y 
transacciones desarrollado en C++. El sistema está diseñado para permitir a los usuarios gestionar 
activos, registrar transacciones de renta y devolución, y generar reportes detallados sobre las 
actividades realizadas. A lo largo de este manual, se explicarán los componentes principales del 
sistema, su lógica de funcionamiento y cómo interactúan entre sí.  El sistema se compone de varias 
clases y estructuras de datos que trabajan en conjunto para proporcionar una funcionalidad robusta 
y eficiente. Entre las clases principales se encuentran Activo, Usuario, Transacción, NodoAVL, NodoMatriz, 
ListaTransaccion, y Matriz. Cada una de estas clases tiene un propósito específico y contribuye al 
funcionamiento general del sistema.

## Estructura del Sistema
La clase Activo representa los activos que pueden ser rentados por los usuarios. Cada activo tiene 
atributos como id, nombre, descripción, diasMax, rentado, usuario, y diasRenta. Estos atributos 
permiten identificar y gestionar los activos de manera efectiva.

### Gestión de Usuarios
La clase Usuario representa a los usuarios del sistema. Cada usuario puede agregar activos y 
realizar transacciones de renta y devolución. Los usuarios están organizados en una estructura 
matricial dividida entre departamentos y empresas para facilitar la gestión y búsqueda 
de los mismos además para en manejo de activos de forma individual, teniendo cada usuario su 
propia estructura de Árbol AVL.

### Transacciones
La clase Transacción se utiliza para registrar las operaciones de renta y devolución de activos. Cada 
transacción contiene información sobre el activo, el usuario, y los detalles de la operación.

### Estructuras de Datos

- Lista Doblemente Enlazada:
La clase ListaTransaccion representa una lista doblemente enlazada utilizada para gestionar las transacciones 
de renta y devolución de activos. Esta lista permite insertar transacciones al inicio, al final o en una posición 
intermedia, y recorrer la lista para generar reportes de las transacciones realizadas por los usuarios.


- Árbol AVL: El Árbol AVL se utiliza para almacenar y gestionar los activos de manera eficiente. Este árbol 
balanceado permite realizar operaciones de inserción, búsqueda y eliminación en tiempo logarítmico.


- Matriz Dispersa: La Matriz es una estructura que organiza a los usuarios y sus activos en una 
disposición matricial. Esta estructura facilita la búsqueda y gestión de activos rentados por diferentes usuarios.

## Funcionalidades Principales
El sistema de gestión de activos y transacciones proporciona las siguientes funcionalidades principales:

### ListaTransaccion.cpp
`reporteTransacciones();` Genera un reporte de las transacciones en orden ascendente. Verifica si la lista está 
vacía antes de generar el contenido del archivo dot.

`reporteTransaccionesAscendente/Descendente();`Genera un reporte de las transacciones en orden ascendente/descendente. 
Verifica si la lista está vacía antes de generar el contenido del archivo dot.

### Matriz Dispersa
`listadoActivos();` tiene dos versiones: una que toma un Usuario, un bool y un string como parámetros, y otra que 
además toma un NodoMatriz como punto de inicio. La función recorre la matriz de usuarios y lista los activos de 
un usuario específico. Si el parámetro bandera es true, lista todos los activos del usuario; si es false, busca 
un activo específico por su id. La función es recursiva y llama a sí misma para recorrer la matriz verticalmente. 

### ArbolAVL
El Árbol AVL es una estructura de datos balanceada que permite realizar operaciones de inserción, búsqueda y eliminación 
en tiempo logarítmico. En el programa, el Árbol AVL se utiliza para gestionar los activos de los usuarios de manera 
eficiente. Cada usuario tiene su propio Árbol AVL, lo que permite organizar y acceder rápidamente a los activos que posee.

### Lógica del Árbol AVL
1. **Balanceo**: Después de cada operación de inserción o eliminación, el árbol se balancea para asegurar que la diferencia 
de altura entre los subárboles izquierdo y derecho de cualquier nodo no sea mayor que uno.
2. **Rotaciones**: Para mantener el balance, se realizan rotaciones simples o dobles (rotación izquierda, rotación derecha, 
rotación izquierda-derecha, rotación derecha-izquierda).
3. **Operaciones**:
    - **Inserción**: Se inserta un nuevo nodo en la posición correcta y luego se balancea el árbol.
    - **Búsqueda**: Se recorre el árbol desde la raíz hasta encontrar el nodo con el valor buscado.
    - **Eliminación**: Se elimina el nodo y luego se balancea el árbol.

#### Uso en el Programa
- **Gestión de Activos**: Cada usuario tiene un Árbol AVL que almacena sus activos. Esto permite realizar operaciones rápidas 
de inserción, búsqueda y eliminación de activos.
- **Listar Activos**: La función `listadoActivos` recorre la matriz de usuarios y utiliza el Árbol AVL de cada usuario 
para listar o buscar activos específicos.
- **Reportes**: Los activos rentados por los usuarios se gestionan y reportan utilizando el Árbol AVL, lo que facilita la 
generación de reportes detallados y eficientes.

El Árbol AVL es necesario para la gestión eficiente de los activos en el sistema, dando una estructura balanceada que optimiza 
operaciones de acceso y edición de datos.

## Ejecución del Programa
Ejecución del Programa
Para ejecutar el archivo main.cpp en la consola, sigue estos pasos:  
1. Compila el archivo `main.cpp`  
```
g++ -o miPrograma main.cpp`
```
2. Ejecuta el archivo compilado `./miPrograma`

El proyecto tiene múltiples archivos fuente, incluye todos los archivos necesarios en el comando de compilación:
```
g++ -o miPrograma main.cpp archivo1.cpp archivo2.cpp
```
Luego, ejecuta el archivo compilado de la misma manera:
```
./miPrograma
```