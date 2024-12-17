# Manual de Usuario

## Renta de Activos
### Juan Rodas | 202200389 | EDD Sección "A"

## Introducción
El programa es un sistema de gestión de renta de activos que permite realizar las siguientes 
acciones:

### Iniciar sesión como usuario.
```
>> [1]. Login [ADMIN]/[USUARIO]
>> [2]. Salir del Programa
>> Ingresar Opción:
>> |
```

Posteriormente de elegir la opción 1, qué inicia el programa, ingresará el usuario y contraseña
para poder acceder al menú de opciones, si el usuario y contraseña son correctas se mostrará el 
menú ya sea de usuario o de administrador. Además de ingresar el usuario y contraseña, se debe de
ingresar el departamento y empresa a la que pertenece para iniciar sesión como usuario.

## Menú de Opciones del Usuario

El menú de opciones del usuario permite realizar las siguientes acciones:
```
====================== Menu Usuario =====================
>> ### [1]. Agregar Activo
>> ### [2]. Eliminar Activo
>> ### [3]. Modificar Activo
>> ### [4]. Rentar Activo
>> ### [5]. Activos Rentados
>> ### [6]. Mis Activos Rentados
>> ### [7]. Cerrar Sesion
=========================================================
```

1. **Agregar Activo:** Permite al usuario añadir un nuevo activo al sistema.  
2. **Eliminar Activo:** Permite al usuario eliminar uno de sus activos mientras este no este rentado.
3. **Modificar Activo:** Permite al usuario modificar la descripción de un activo existente.
4. **Rentar Activo:** Permite al usuario rentar un activo disponible mientras este no sea suyo.
5. **Activos Rentados:** Muestra todos los activos que han sido rentados a nombre del usuario.
6. **Mis Activos Rentados:** Muestra los activos propios del usuario que están rentados. 
7. **Cerrar Sesión:** Permite al usuario cerrar su sesión actual en el sistema.

## Menú de Opciones del Administrador

El menú de opciones del administrador permite realizar las siguientes acciones:
```
====================== Menu Administrador =====================
>> %%% [1]. Registrar Usuario
>> %%% [2]. Reporte (Graphviz) Matriz Dispersa
>> %%% [3]. Reporte (Graphviz) Activos Disponibles de un Departamento
>> %%% [4]. Reporte (Graphviz) Activos Disponibles de una Company
>> %%% [5]. Reporte (Graphviz) Transacciones
>> %%% [6]. Reporte Activos de un Usuario
>> %%% [7]. Activos Rentados por un Usuario
>> %%% [8]. Ordenar Transacciones
>> %%% [9]. Cerrar Sesion
===============================================================
```

1. **Registrar Usuario:** Permite al administrador registrar un nuevo usuario en el sistema. 
2. **Reporte (Graphviz) Matriz Dispersa:** Genera un reporte visual de la matriz dispersa utilizando Graphviz. 
3. **Reporte (Graphviz) Activos Disponibles de un Departamento:** Genera un reporte visual de los activos disponibles en un departamento específico utilizando Graphviz. 
4. **Reporte (Graphviz) Activos Disponibles de una Compañía:** Genera un reporte visual de los activos disponibles en una compañía específica utilizando Graphviz. 
5. **Reporte (Graphviz) Transacciones:** Genera un reporte visual de todas las transacciones realizadas utilizando Graphviz. 
6. **Reporte Activos de un Usuario:** Genera un reporte de todos los activos asociados a un usuario específico. 
7. **Activos Rentados por un Usuario:** Genera un reporte de todos los activos que un usuario ha rentado. 
8. **Ordenar Transacciones:** Permite ordenar las transacciones de forma ascendente o descendente. 
9. **Cerrar Sesión:** Permite al administrador cerrar su sesión actual en el sistema.

## Estructuras del Sistema
Las estructuras de datos utilizadas en el sistema son las siguientes:
#### Lista doblemente enlazada:
Una lista doblemente enlazada es una estructura de datos lineal que consiste en una secuencia de nodos, donde 
cada nodo contiene un valor y dos punteros: uno que apunta al siguiente nodo en la secuencia y otro que apunta al 
nodo anterior. Esto permite una navegación bidireccional a través de la lista, facilitando operaciones como inserción 
y eliminación de nodos en cualquier posición de manera eficiente.
#### Matriz dispersa: 
Una matriz dispersa es una estructura de datos que almacena elementos no nulos en una matriz de gran tamaño, 
donde la mayoría de los elementos son nulos. Esta estructura es eficiente en términos de memoria y permite 
realizar operaciones de manera rápida al enfocarse solo en los elementos significativos.
#### Árbol binario de búsqueda:
Un árbol binario de búsqueda es una estructura de datos en forma de árbol en la que cada nodo tiene como máximo dos 
hijos, denominados hijo izquierdo e hijo derecho. En un árbol binario de búsqueda, para cada nodo, todos los 
valores en el subárbol izquierdo son menores que el valor del nodo, y todos los valores en el subárbol derecho 
son mayores. Esta propiedad permite realizar operaciones de búsqueda, inserción y eliminación de manera eficiente.