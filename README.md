# Graph-Problem-Solved
Graph problem solved with C++.
Implementar la clase Grafo Dirigido que provea, como mínimo, los métodos definidos en la interfaz propuesta por la cátedra.

En cada método implementado incluir la complejidad temporal de dicho método. Una buena forma de hacerlo sería agregando un comentario previo a la declaración del método.

Se debe entregar un proyecto/carpeta que contenga:

Todas las clases necesarias para compilar el grafo dirigido solicitado.
Las clases y funciones necesarias para utilizar el grafo en el siguiente contexto y resolver el algoritmo solicitado.
Contexto
Se dispone de un conjunto de procesos, donde cada proceso tiene un nombre, una descripción, un tipo (crítico/opcional) y una duración (medida en horas). Se sabe también que hay una dependencia en el orden posible en el cual se pueden ejecutar estos procesos y un tiempo de espera entre dos procesos consecutivos (también medido en horas). Por ejemplo, si el proceso B depende del proceso A y tiene un tiempo de espera de 5 horas; significa que:

B no puede ejecutarse antes que A y, 
B debe ejecutarse 5 horas después de haber finalizado la ejecución de A.
Objetivo
Implementar un algoritmo que obtenga la secuencia de ejecución crítica de estos procesos, es decir, la secuencia de procesos que resulta en el máximo tiempo empleado para su ejecución; considerando, además, que como parte de esta secuencia se debe incluir, por lo menos, un proceso crítico.

La aplicación implementada debe presentar al usuario la secuencia de ejecución crítica junto con el tiempo total de la misma.

Aclaración: por el contexto del problema se asume que la configuración de procesos disponibles resulta en un grafo sin ciclos.

Por ejemplo: Para el siguiente esquema de procesos, donde los procesos críticos se marcan con un relleno de color (P3, P5, P6 y P9), se puede establecer que la secuencia de ejecución crítica está definida por los procesos <P0, P2, P6, P10>, resultando en un tiempo total de 33 hs.

![Ejemplo_procesos](https://user-images.githubusercontent.com/80551958/196959910-ec588f75-21a9-4670-88ff-6c471b86d905.png)
