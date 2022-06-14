# NominaEmpresarial
Este programa emula las funciones de una nómina (no exacta, pero si lo más cercana posible), está constituido con las librearías necesarias, con funciones que poseen parámetros y otras que no, sin variables globales y usando struct. Reemplace el uso de variables globales optando por el uso de archivos como escritura y lectura: al guardar información por palabra en un archivo esta se puede volver a llamar sin necesidad de usar las mimas variables con las que se guardó la información, ya que cada elemento se llama en el mismo orden en el que se guardó. El programa, aunque imprime en consola, fue exclusivamente diseñado para guardar la información en 3 archivos:
- Empleados: este archivo guarda toda la información de la nómina, como nombres, valores, etc. y es la base para generar los demás archivos.
- Gasto: solo guarda el valor que se gastó la empresa por cada empleado.
- Recibo: Contiene el recibo de Nomina de solo los empleados que hayan sido seleccionados.
