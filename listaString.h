#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED

#include "string.h"

typedef struct NodoL {
    string info;
	NodoL * sig;
} NodoLista;

typedef NodoLista * listaString;

/// crea lista vacia
void lista_string_crear(listaString &lista);

/// devuelve true si la lista esta vacia
boolean lista_string_vacia(listaString lista);

/// inserta al final de la lista un nuevo string
void lista_string_insertar_al_final(listaString &lista, string texto);

/// muestra los datos de la lista de strings
void lista_string_mostrar(listaString lista);

/// separar “palabras” por espacios e insertar en lista
void lista_string_separar_palabras(string texto, listaString &lista);

/// cuenta la cantidad de nodos de la lista
int lista_string_contar_nodos(listaString lista);

/// dada una posición, obtener el string de esa posición
/// precondición: dicha posición existe en la lista
void lista_string_obtener_por_indice(listaString lista, int pos, string &s);

/// liberar memoria de lista de strings
void lista_string_liberar_memoria(listaString &lista);


#endif // LISTASTRING_H_INCLUDED
