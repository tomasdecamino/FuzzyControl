# FuzzyControl para Arduino

Esta es una librería de estructuras de datos y funciones para la construcción de conjuntos difusos, y la aplicacón de control difuso en placas de desarrollo como Arduino y Feather de Adafruit.

Algunas definiciones para entender las estructuras y funciones.

La librería está programada utilizando regitros y operaciones sobre esas estructuras de datos.  La librería perfectamente podría programarse utilizando objetos, pero fue construida de esta manera para enseñanza. Un registro es una colección de campos, y en C se construyen con struct. Se utilizó struct pues la estrucutra de conjuntos no pretende implementar métodos y herencia como tal, es decir, struct es útil para objectos pequeños públicos pasivos que no tienen herencia, como un contenedor de datos.  Se utiliza un puntero a función para asociar una función de membresía a cada estructura de conjunto difuso.

##Estructuras de Datos


- **FuzzyDef** para definir conjuntos difusos con su respectiva función de membresía.
- **fuzyDomain**  para encapsular todo el dominio de conjuntos difusos para el dominio de discurso

##Funciones (importantes)

- **setDomain**:  permite construir un domino completo de conjuntos difusos usanfo dfunciones monotonicas de triángulo
- **resetDomain**: resetea los valores de mebresía a 0
- **truthDegree**: Calcula los valores de mebresia de todo el dominio, y lo almacena en el campo miu de cada conjunto
- **isMember**: verdadero o falso y sin dado un valor el elemento es miembro de un conjunto difuso
- **isMemberOr**:  Igual que el anterior pero aplicando operaciones lógica AND entre varios conjuntos
- **isMemberAnd**:  Igual que el anterior pero aplicando operaciones lógica OR entre varios conjuntos
- **weightedAverage**:  Defusifica utilizando el método de weighted average

##Utilización

###Declaracion de variables y definición de conjuntos difusos
Para declara un conjunto difuso, digmos miConjunto:

```C
fuzzyDef miConjunto;
```
Luego en el setup:

```C
void setup(){
  miConjunto.membership = &increasing;
  miConjunto.mina = 0.5;
  miConjunto.maxa = 1.5;
}
```
miConjunt.membership define funci'on de membres'ia del conjunto. Noten que hay que enviar la referencia con "&". Luego se defininen los intervalos donde la funci'on de mebres'i contruye, en este caso, la funci'on monot'onica creciente.  Del mismo modo se puede definir triangle, decreasing y trapezoid, est'a 'ultima requiere definir mina, maxa, minb y maxb.

Para contruir un dominio con varios conjuntos más rápidamente, se utiliza setDomain. Por ejemplo para crear miDominio,

```C
fuzzyDef miDominio;

void setup(){
  miDominio.nset=3; //define el numero de conjuntos
  miDominio.fser = new fuzzyDef[miDominio.nset]; //prepara 3 conjuntos
  setDomain(&miDominio, -10,10); //crea tres conjuntos ya con sus funciones de membresia (monotónicas y trianguares)
}
```
Al final cada conjunto difuso se puede accesar con,

```C
  miDominio.fset[i]; // con 0 <= i < miDominio.nset
```

###Creación de más funciones de membresía

Las funciones de membresía se puede construir con el enunciado de función,
```C
  float miFuncion(fuzzyDef fset, float x){}
```
En la función se utilizan fset.mina, fset.maxa,fset.minb y fset.minb, para definir los intervalos de validez de la función. Vean por ejemplo la función increasing,

```C
float increasing(fuzzyDef fset, float x) {
  if (x < fset.mina)return 0;
  if (x > fset.maxa)return 1;
  return (x - fset.mina) / (fset.maxa - fset.mina);
}
```

Luego se asocia a un conjunto difuso, 

```C
  miConjunto.membersdip = &miFuncion; 
```

###Cálculo de grados de membresía

Para determinar la membresía en un conjunto dado un valos **x**, utilizamos,

```C
  truthDegree(&miConjunto,x); 
```
Esta función retorna el grado de membresía de un elemento con valor **x** en **miConjunto**. Esta función además almacena en miConjunto.miu el grado de membresía.  Se puede utilizar la misma función para la membresía en todo el dominio de discurso,
```C
  truthDegree(&miDominio,x); 
```
La función almacena en **miu** de cada conjunto del dominio el grado de verdad de pertenencia

###Construcción de reglas de inferencia

La reglas de inferencia se construyen de la siguiente manera

```C
  if(isMember($miConjunto)){
    setMiu(&outConjunto, miConjunto.miu);
  }
```
De esa manera se construyen las reglas de inferencia.  Hay más funciones para facilitar la escritura como **isMemberAnd** y **isMemberOr**, pero esa es la estructura básica.


###Defusificación

##Instalación

##Disclaimer

Estamos en el proceso de contruir un buen ejemplo, así que la librería está parcialmente probada, es decir, nada más se ha verificado que las funciones hacen lo que se suponen deben hacer.
