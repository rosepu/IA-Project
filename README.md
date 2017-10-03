# IA-Project

- Problema: Rotating Workforce Scheduling Problem
- Heurísticas usadas: Greedy, Tabu Search
- Autor: Rodrigo Sepúlveda Garrido

## Compilación y ejecución

Para compilar el código utilizar el archivo make incluido, es decir:

```
$ make
```

Para compilar y ejecutar el código, igualmente se utiliza el makefile incluido, al llamar este comando es posible especificar la semilla e instancia a utilizarán, si no se especifica se utilizaran los valores por defecto.

```
$ make run										// Utilizará los valores por defecto 
$ make run i=2                // Utilizará la instancia nº 2
$ make run seed=2131          // Utilizará la semilla igual a 2131
$ make run i=20 seed=1221     // Utilizará la instancia nº 20 y la semilla 1221
```

----------------------------------------------------------------------------------------------------------------------------

### Compilado en 

- gcc versión 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.2) 
- los pc del lds (CentOS)
