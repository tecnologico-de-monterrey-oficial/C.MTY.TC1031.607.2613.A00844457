
//Allison Charlize Arriaza Chachagua
//A00844457

#Prompts 
- ¿Por qué findData recibe el dato y no el índice?
- ¿Para qué sirve sobrecargar el operador []?
- ¿Cuál es la diferencia entre usar getData y usar []?
- Mi programa se queda mostrando el menú sin parar, ayudame a solucionar.
- ¿Cómo funciona la sobrecarga del operador = en una lista enlazada?



#Reflexión
¿Qué parte del código te propuso la IA que aceptaste tal cual y por qué era correcta?
La parte que más me costó entender fue la sobrecarga del operador =.  Al principio no tenía claro cómo copiar una lista completa sin simplemente copiar los apuntadores. La propuesta fue borrar primero los elementos que ya tenía la lista, poner size en 0 y después recorrer la otra lista para ir agregando sus datos con push back. 

También agregó la validación if (this == &lista) para evitar que una lista intentara copiarse a sí misma. Esa parte la acepté porque después de revisarla entendí por qué era necesario copiar los datos y no solo los apuntadores

¿Qué parte modificaste y cómo verificaste que tu cambio era mejor?
Modifiqué algunas partes de los métodos conforme los fui probando. Corregí los tipos de retorno de getData y findData y revisé las validaciones de los índices en deleteAt, getData y updateAt.  
Para comprobar los cambios fui ejecutando cada función desde el main e imprimiendo la lista después de hacer las operaciones. Así podía ver si realmente se estaba borrando, obteniendo o actualizando el dato que quería


¿Dónde se equivocó la IA (si ocurrió) y cómo lo detectaste?
Cuando estaba haciendo findData hubo confusión con el tipo que debía regresar. Como la función busca un dato pero lo que necesita devolver es su posición, al revisar el código vi que no tenía sentido que fuera void y lo cambié a int.
También tuve un error con el menú porque se quedaba imprimiendo una y otra vez. Primero pensé que era por la condición del while, pero revisando el código vi que en esa versión no estaba leyendo otra vez opcion dentro del ciclo. Lo corregí y volví a correr el programa para comprobar que ya podía seleccionar las demás opciones.



¿Qué harías diferente si no tuvieras Copilot/ChatGPT?
Me apoyaría con el codigo visto en clases, también tendría que probar y profundixar temas de código como los apuntadores y sobrecarga de operadores, que fueron las partes que más me costaron. Seguiría probando cada método por separado para detecar los errores, soklo que me tomaría más tiempo econtrar la causa de algunos problemas. 
