# Proyecto 1 | Renta de Activos

## Objetivos

### Objetivo General
- Aplicar los conocimientos del curso de Estructuras de Datos en la creación de soluciones de software.

### Objetivos Específicos
- Aplicar los conocimientos adquiridos sobre estructuras de datos lineales, matrices dinámicas y arboles avl.

- Aplicar los conocimientos adquiridos sobre memoria dinámica y apuntadores en el lenguaje de programación C++.

- Utilizar la herramienta graphviz para la generación de reportes gráficos.

## Descripción General
Se le solicita a los estudiantes realizar un sistema de renta de activos entre usuarios. Dentro del sistema, se manejarán rentas, usuarios, un historial de transacciones y reportes. Todo el sistema deberá de poder ser controlado mediante una aplicación en consola, trabajada con el lenguaje c++.

### Implementación

Se deberá de implementar una aplicación en consola utilizando c++ para la parte que maneje usuarios y catálogos de activos disponibles para la renta. Los encabezados horizontales de la matriz dispersa serán nombres de los distintos departamentos en el país de Guatemala, los encabezados verticales serán las diferentes empresas pertenecientes a Guatemala y el nodo de la matriz contendrá nombres de personas que serán los encargados de realizar la renta de los activos. Cada nodo de la matriz dispersa deberá de contener al usuario, con su nombre de usuario (para realizar su login), contraseña y nombre completo, así como un árbol binario de búsqueda equilibrado (AVL) donde se almacenarán los activos que el usuario ponga a la renta. Los activos van a tener un nombre, una descripción y un ID único para cada activo que será un código alfanumérico de 15 caracteres, por ejemplo “tb86vw4rh194hpk”.

NOTA: El nombre de usuario se podrá repetir siempre y cuando no se repita en un solo departamento y empresa.
Adicionalmente a esto, se deberá manejar la parte de los historiales de transacciones. Para esto se tendrá una lista circular doblemente enlazada, donde cada nodo contendrá toda la información de las transacciones que se han realizado en el sistema. Cada vez que se rente un activo, se deberá de crear una nueva transacción, esta tendrá la siguiente información:

- Un ID único para la transacción (un código alfanumérico de 15 caracteres)
- El ID del activo que se rento
- El usuario que realizó la renta
- El departamento y empresa pertenecientes al usuario que realizó la renta
- La fecha en que se realizó la renta
- Por cuánto tiempo se rentó

La lista circular deberá estar ordenado mediante el ID único de cada transacción y se contará con un usuario administrador que establecerá el tipo de ordenamiento que tendrá la lista, así como el manejo de creación, eliminación, y modificación de usuarios y la creación de reportes.

### Registro de Usuarios
Se deberá contar con usuario “Administrador” que maneje la creación de usuario. Los usuarios que se creen mediante este usuario deberán de ser guardados en la matriz dispersa y los activos que esté agregue al sistema deben de guardarse en su AVL.
Debe de existir una opción de modificar la descripción de un activo que esté a la renta, así como la opción de eliminar un activo de su AVL.

#### Inicio de Sesión
#### Menú principal de un usuario ya ingresado
#### Creación de activos
Al ingresar la opción “Agregar activo” el ID del nuevo activo se crea automática y aleatoriamente.
#### Eliminación de activos
 Los campos de nombre y descripción se tienen que llenar automáticamente con la información correspondiente al ID seleccionado por el usuario. Se deben mostrar, en forma de lista, el id y el nombre de los activos pertenecientes al usuario antes de la eliminación.
#### Modificación de activos
Los campos de nombre y descripción se tienen que llenar automáticamente con la información correspondiente al ID seleccionado por el usuario. Se deben mostrar, en forma de lista, el id y el nombre de los activos pertenecientes al usuario.
El atributo de descripción es el que puede ser modificado y cuando la modificación se haya llevado a cabo se debe mostrar el producto con su descripción modificada.
#### Renta de Activos
Se deberá de escoger en un catálogo de activos, el activo que se desea alquilar y el tiempo de alquiler. Un activo debe ser eliminado del catálogo una vez se realiza una renta sobre él.
También deberá de existir un módulo donde se registre la devolución del activo. Esto regresará el activo al catálogo de activos disponibles.
#### Activos Rentados
El usuario podrá ver un listado de los activos que ha rentado, teniendo la opción de realizar una devolución de los activos.
#### Mis Activos Rentados
El usuario podrá ver un listado de sus activos que se encuentran rentados.

### Usuario Administrador
El usuario administrador tendrá la opción de crear usuarios, y de generar distintos tipos de reportes, los cuales se generarán con la herramienta graphviz.
El usuario administrador tendrá la opción de ordenar las transacciones, basándose en los ID de estas, de manera ascendente o descendente.
#### Creación de un Usuario

## Flujo de la aplicación
Básicamente el sistema tendrá el siguiente flujo:
- Se crearán usuarios dentro del sistema con contraseña para poder realizar su login.
- Este usuario va a pertenecer a un departamento y una empresa de Guatemala.
- El usuario podrá poner activos para rentar.
- Otros usuarios podrán rentar esos activos.

## Reportes
Los reportes que el usuario administrador podrá generar son:
- El estado actual de la matriz dispersa
- Todos los activos pertenecientes a una empresa que estén disponibles para rentarse.
- Todos los activos pertenecientes a un departamento en específico que estén disponibles para rentarse.
- La circular doblemente enlazada.
- El AVL de cierto usuario
- Todos los activos que un usuario tenga en su posesión actualmente (activos que el haya rentado)

**Nota**: Los reportes son esenciales para verificar si se trabajó correctamente la estructura, por lo que **sin reportes, no se calificará el proyecto.**

## Entregables
- Ejecutable
- Código Fuente
- Manual de Usuario
- Manual Técnico
**Todo en un archivo .rar con el nombre [EDD]Proyecto1_<carnet>.rar**

## Observaciones
- Lenguaje de Programación: C++
- Sistema Operativo: Elección del estudiante
- La aplicación será compilada y ejecutada al momento de la calificación
- Las estructuras de datos deben ser realizadas por el estudiante.
- Para la creación de las estructuras, se debe hacer uso de clases y apuntadores.
- La aplicación que no genere gráficas no podrá ser calificada.
- No se permite el uso de las siguientes librerías: QString, QFile, QList, QStack, std::list, std::stack, etc.
- Fecha de Entrega y Calificación: Jueves 16 de diciembre antes de medianoche.
- Entrega en plataforma UEDI.
- Copias tendrán nota de 0 puntos y serán reportadas al catedrático y a la escuela de sistemas.
