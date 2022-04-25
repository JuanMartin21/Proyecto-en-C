#ifndef LISTANATURALES_H_INCLUDED
#define LISTANATURALES_H_INCLUDED

#include "boolean.h"

typedef struct nodoN {
    int info;
	nodoN * sig;
} nodoNatural;

typedef nodoNatural * listaNaturales;

/// crea lista vacía
void lista_naturales_crear(listaNaturales &lista);

/// devuelve true si la lista está vacía
boolean lista_naturales_vacia(listaNaturales lista);

/// inserta al principio de la lista un nuevo valor
void lista_naturales_insertar_al_inicio(listaNaturales &lista, int num);

/// inserta al final de la lista un nuevo valor
void lista_naturales_insertar_al_final(listaNaturales &lista, int num);

/// muestra los datos de la lista de numeros
void lista_naturales_mostrar(listaNaturales lista);

/// cuenta la cantidad de nodos de la lista
int lista_naturales_contar_nodos(listaNaturales lista);

/// sumar los elementos de la secuencia
int lista_naturales_sumar(listaNaturales lista);

/// liberar memoria de lista de numeros
void lista_naturales_liberar_memoria(listaNaturales &lista);

/// concatenar lista 2 despues de lista uno en orden
void lista_naturales_concatenar(listaNaturales &listaNueva, listaNaturales lista1, listaNaturales lista2);

/// invertir lista de numeros
void lista_naturales_reverse(listaNaturales &listaNueva, listaNaturales lista1);

#endif // LISTANATURALES_H_INCLUDED
