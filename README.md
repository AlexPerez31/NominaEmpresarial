# NominaEmpresarial
Proyecto en C++ que simula la administración de la nomina de una empresa. Diseño orientado a objetos (POO) y usando archivos.

Alex Jordan Pérez Rojas 

Programa "Nomina":

El siguiente programa emula las funciones de una nómina (no exacta, pero si lo mas
cercana posible), está constituido con las librearías necesarias, con algunas 
funciones con y sin parámetros, sin variables globales y usando struct.
La forma más eficiente que halle para hacerlo sin variables globales y sin tener
que ponerles muchos parámetros a las funciones es usando los archivos como escritura
y lectura, ya que al guardar información por palabra en un archivo esta se puede
volver a llamar sin necesidad de usar exactamente las mimas variables con las
que se guardó la información, lo importante aquí es saber el orden en el que 
se guardó la información y en ese mismo orden se vuelve a invocar.
El programa, aunque imprime en pantalla no fue exclusivamente diseñado para
guardar la información en 3 archivos los cuales son:
empleados: este archivo guarda toda la información de la nómina, como
nombres, valores, etc. y fue la base para generar los demás archivos.
gasto: solo guarda el valor que se gastó la empresa por cada empleado.
recibo: Contiene el recibo de Nomina de solo los empleados que hayan sido seleccionados.
