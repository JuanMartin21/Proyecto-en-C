#ifndef SECUENCIA_H_INCLUDED
#define SECUENCIA_H_INCLUDED

#include "listaNaturales.h"
#include "string.h"

typedef struct  {
    string nombre;
	listaNaturales lista;
} secuencia;

/// crea una secuencia vacía
void secuencia_crear(secuencia &sec, string nom);

/// muestra la data de la secuencia
void secuencia_mostrar(secuencia sec);

/// devuelve el nombre de la secuencia
void secuencia_dar_nombre(secuencia sec, string &nom);

/// devuelve la lista de enteros de la secuencia
listaNaturales secuencia_dar_lista(secuencia sec);

/// insertar valor al final de la secuencia
void secuencia_ins_back(secuencia &sec, int nro);

/// crea nueva secuencia usando primero los valores de la sec1 y luego los valores de la sec2 en orden
void secuencia_concat(secuencia sec1, secuencia sec2, secuencia &secNueva);

/// crea nueva secuencia invirtiendo los valores de una secuencia dada
void secuencia_reverse(secuencia secOriginal, secuencia &secNueva);

/// Lee desde el archivo los datos de la secuencia.
/// precondicion: secuencia_existe_archivo(nombre_archivo)
void secuencia_leer(secuencia &sec, string nombre_archivo);

/// Escribe en el archivo los datos de la secuencia.
void secuencia_guardar(secuencia sec, string nombre_archivo);

/// liberar memoria de la secuencia
void secuencia_liberar_memoria(secuencia &sec);


#endif // SECUENCIA_H_INCLUDED
