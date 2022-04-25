#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"


const int MAX = 80;
typedef char * string;

/// crea un string vacío (solo con el carácter \\0)
void strcrear (string &s);

/// libera la memoria ocupada por el string y lo deja nulo.
void strdestruir (string &s);

/// devuelve el largo de un string.
int strlar (string s);

/// recibe dos strings y copia el segundo en el primero.
void strcop (string &s1, string s2);

/// recibe dos strings y copia desde el strOrigen comenzando en el indice inicio y termina en el indice fin
/// precondicion: indices entre 0 y strlar
void strcopiar_entre_indices (string &stringNuevo, string strOrigen, int inicio, int fin);

/// lee un string desde el teclado.
void strscan (string &s);

/// recibe dos strings y concatena el segundo al final del primero
void strcon (string &s1, string s2);

/// recibe dos strings y devuelve el primero en el segundo y viceversa.
void strswp (string &s1, string &s2);

/// despliega un string por pantalla.
void strprint (string s);

/// recibe dos strings y devuelve TRUE si el primero de ellos es menor
/// (en orden alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen (string s1, string s2);

/// recibe dos strings y devuelve TRUE si ambos strings son iguales
/// o FALSE en caso contrario.
boolean streq (string s1, string s2);

/// verifica que string sea solo letras mayusculas o minusculas
boolean string_validar_alfabetico(string s1);

/// verifica que string sea numero natural ( >= 0 )
boolean string_validar_numero_natural(string s1);

/// verifica que string sea solo letras mayusculas o minusculas y que termine con “.txt”
boolean string_validar_nombre_archivo_txt(string s1);

/// convierte un string a numero
/// PRECONDICION: string_validar_numero_natural(s)
int string_convert(string s);

/// pasa el string s2 a minúsculas en s1
void string_a_minuscula(string &s1, string s2);

#endif // STRING_H_INCLUDED
