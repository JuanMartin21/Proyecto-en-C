#ifndef ABBSECUENCIA_H_INCLUDED
#define ABBSECUENCIA_H_INCLUDED

#include "secuencia.h"

typedef struct nodoABB {
    secuencia info;
	nodoABB * hizq;
	nodoABB * hder;
} nodoArbol;

typedef nodoArbol * abbSecuencia;

/// valida si el árbol está vacío o no
boolean abb_secuencia_vacio(abbSecuencia a);

/// crear arbol vacio
void abb_secuencia_crear(abbSecuencia &a);

/// insertar nueva secuencia en abb
/// PRECONDICION: no existe secuencia en el arbol con el nombre de la nueva secuencia
void abb_secuencia_insertar(abbSecuencia &a, secuencia sec);

/// devuelve la raíz del abb
secuencia abb_secuencia_dar_raiz(abbSecuencia a);

/// devuelve el hijo izquierdo del abb
abbSecuencia abb_secuencia_dar_h_izq(abbSecuencia a);

/// devuelve el hijo derecho del abb
abbSecuencia abb_secuencia_dar_h_der(abbSecuencia a);

/// chequea si existe secuencia en abb por nombre
boolean abb_secuencia_existe_nombre(abbSecuencia a, string ident);

/// devuelve secuencia de abb por nombre
/// PRECONDICION: existe secuencia en el arbol con  ese nombre
secuencia abb_secuencia_obtener_por_nombre(abbSecuencia a, string ident);

/// Lista todas las secuencias registrados en el sistema, ordenados por identificador alfabeticamente y lista de entero ( nombre = [ valores ] )
void abb_secuencia_mostrar_en_orden(abbSecuencia a);

/// insertar en secuencia nuevo valor al final
/// PRECONDICION: existe secuencia en el arbol con  ese nombre
void abb_secuencia_ins_back(abbSecuencia &a, string ident, int valor);

/// liberar memoria del árbol
void abb_secuencia_liberar_memoria(abbSecuencia &a);


#endif // ABBSECUENCIA_H_INCLUDED
