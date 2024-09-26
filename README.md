# Recorrido por Niveles (Breadth-First Search - BFS) en un Árbol Binario

El recorrido por niveles, conocido también como **Breadth-First Search (BFS)**, es una técnica de exploración de un árbol en la que se visitan todos los nodos nivel por nivel, de izquierda a derecha. A diferencia del recorrido en profundidad (DFS), que explora cada rama completamente antes de pasar a la siguiente, el BFS explora todos los nodos en un nivel antes de pasar al siguiente nivel.

## Características del BFS:
- Es ideal para encontrar la solución más cercana a la raíz.
- Utiliza una **cola (queue)** para gestionar los nodos que necesitan ser procesados.
- En un árbol binario, el BFS explora todos los nodos a un nivel antes de explorar los nodos del nivel inferior.

### Ejemplo de BFS en un Árbol Binario:

Para el siguiente árbol binario:

      1
     / \
    2   3

El recorrido por niveles (BFS) sería: `1, 2, 3, 4, 5, 6`.

## Algoritmo para Recorrer el Árbol por Niveles (BFS)

El recorrido BFS utiliza una cola (queue) para visitar los nodos de manera ordenada, nivel por nivel. A continuación se muestra el algoritmo.

## Recorrido en Preorden (DFS Preorder)
El recorrido preorden es un tipo de recorrido en profundidad (DFS) en el que primero se visita el nodo raíz, luego el subárbol izquierdo y finalmente el subárbol derecho. Este recorrido se denomina preorden porque el nodo raíz se procesa antes que sus hijos.

Ejemplo de Preorden:
Para el mismo árbol binario:

      1
     / \
    2   3
   / \   \
  4   5   6
El recorrido en preorden sería: 1, 2, 4, 5, 3, 6.

## Conclusión:
El recorrido por niveles (BFS) visita los nodos nivel por nivel, de izquierda a derecha.
El recorrido en preorden (DFS Preorder) visita primero la raíz, luego el subárbol izquierdo y finalmente el subárbol derecho.
Ambos recorridos tienen aplicaciones distintas según el problema que se quiera resolver.