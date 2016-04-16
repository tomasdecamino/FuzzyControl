# FuzzyControl para Arduino

Esta es una librería de estructuras de datos y funciones para la construcción de conjuntos difusos, y la aplicacón de control difuso en placas de desarrollo como Arduino y Feather de Adafruit.

Algunas definiciones para entender las estructuras y funciones.

La librería está programada utilizando regitros y operaciones sobre esas estructuras de datos.  La librería perfectamente podría programarse utilizando objetos, pero fue construida de esta manera para enseñanza. Un registro es una colección de campos, y en C se construyen con struct.

##Estructuras de Datos


- FuzzyDef para definir conjuntos difusos con su respectiva función de membresía.
- fuzyDomain  para encapsular todo el dominio de conjuntos difusos para el dominio de discurso

##Funciones y Métodos

- setDomain:  permite construir un domino completo de conjuntos difusos usanfo dfunciones monotonicas de triángulo
- resetDomain: resetea los valores de mebresía a 0
- truthDegree: Calcula los valores de mebresia de todo el dominio, y lo almacena en el campo miu de cada conjunto

##Utilización

###declaracion de variables y definicióon de conjuntos difusos

###cálculo de grados de membresía

###construcción de reglas de inferencia

###Defusificación
