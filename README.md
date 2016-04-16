# FuzzyControl

Librería para control difuso.  Está hecha en C, y define los conjuntos difusos utilizando objetos struct àra simplificar el código, y no estrictamente C++.  Funciona bien en Arduino UNO, y corre bastante rápido.

##Estructuras de Datos

```
fuzzyDef
```
Estructura para la definici'on de un conjunto difuso. Contiene:

```
  float mina
  float minb
  float maxa
  float maxb
  float centroid
  float (*membership)(fuzzyDef, float)
  float miu
```
