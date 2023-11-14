# Codigo Agente Inteligente 8 puzzle
### //author: Christopher Xavier Sanchez Duran
### //UAMC

## main.cpp

El código proporcionado es un ejemplo de implementación de un algoritmo de búsqueda en amplitud (BFS) para resolver el rompecabezas del 8-puzzle en un entorno de inteligencia artificial.
Genera un estado inicial aleatorio y encuentra una secuencia de movimientos para resolver el rompecabezas, mostrando cada paso en el camino hacia la solución. 

### Explicacion:
#### Inclusión de bibliotecas: 
El código comienza incluyendo varias bibliotecas de C++ que serán utilizadas. Estas bibliotecas incluyen entrada/salida (iostream), algoritmos (algorithm), generación de números aleatorios (random), manejo de vectores (vector), y estructuras de datos para la búsqueda (stack y queue). Estas bibliotecas proporcionan las herramientas necesarias para implementar el algoritmo BFS y resolver el 8-puzzle.

#### Clase Node: 
La clase Node representa un nodo en el árbol de búsqueda. Cada nodo contiene la siguiente información:

Una cuadrícula (x) que almacena el estado del rompecabezas como una matriz 2D.
El tamaño n de la cuadrícula (generalmente 3 para el 8-puzzle).
Una ubicación de la casilla vacía (vacio) representada como un par de coordenadas.
Un puntero al nodo padre (padre) que se utiliza para rastrear el camino de la solución.
Una lista de punteros a nodos hijos (hijos) que representan los posibles estados que se pueden alcanzar desde el nodo actual.
Clase Tree: La clase Tree representa el árbol de búsqueda. Se inicializa con un nodo raíz que contiene el estado inicial del rompecabezas. Además, proporciona métodos para verificar si un estado se ha resuelto, agregar un nuevo nodo al árbol con su respectivo nodo padre y ubicación de la casilla vacía, copiar cuadrículas, y agregar nuevos estados al nivel actual.


#### Función main: 
En esta función se realiza la ejecución principal del programa. Aquí se crea una cuadrícula aleatoria inicial para el 8-puzzle. Se barajan los números del 0 al 8 y se distribuyen en la cuadrícula. Luego, se crea un objeto de la clase Tree con la cuadrícula inicial y se invoca la función BFS para encontrar una solución.

#### Función BFS: 
La función BFS es la implementación del algoritmo de búsqueda en amplitud. Utiliza una cola para explorar los nodos del árbol en un orden específico. Comienza con el nodo raíz y explora todos los nodos de manera iterativa. Cuando encuentra un nodo que representa el estado objetivo (cuando se cumple la función isSolved), devuelve ese nodo como la solución.

#### Recorrido del camino de solución: 
Después de encontrar la solución, el código rastrea el camino de solución desde el nodo objetivo hacia el nodo raíz utilizando una pila. Luego, imprime cada paso del camino de solución, mostrando cómo se llega desde el estado inicial al estado objetivo.

Finalmente, la función main devuelve un valor entero 23 al final del programa.
##### // author: Christopher Xavier Sanchez Duran
##### // Github: https://github.com/cxavier23
##### // Portafolio: https://cxavier23.github.io/

