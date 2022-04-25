#include "abbSecuencia.h"

void abb_secuencia_crear(abbSecuencia &a){
    a = NULL;
}

boolean abb_secuencia_vacio(abbSecuencia a){
    boolean vacio = FALSE;
    if (a == NULL)
        vacio = TRUE;
    return vacio;
}

void abb_secuencia_insertar(abbSecuencia &a, secuencia sec){
    string nom;
    if (a == NULL){
        a = new nodoArbol;
        a -> info = sec;
        a -> hizq = NULL;
        a -> hder = NULL;
    } else {
        strcrear(nom);
        secuencia_dar_nombre(a->info, nom);
        if (strmen(sec.nombre, nom)){
            strdestruir(nom);
            abb_secuencia_insertar (a -> hizq, sec);
        } else {
            strdestruir(nom);
            abb_secuencia_insertar (a -> hder, sec);
        }
    }
}

secuencia abb_secuencia_dar_raiz(abbSecuencia a){
    return a->info;
}

abbSecuencia abb_secuencia_dar_h_izq(abbSecuencia a){
    return a->hizq;
}

abbSecuencia abb_secuencia_dar_h_der(abbSecuencia a){
    return a->hder;
}

boolean abb_secuencia_existe_nombre(abbSecuencia abb, string ident){
    string nom;
    if (abb == NULL){
        return FALSE;
    } else {
        strcrear(nom);
        secuencia_dar_nombre(abb->info, nom);
        if(streq(nom, ident)){
            return TRUE;
        } else {
            if(strmen(ident, nom)){
                return abb_secuencia_existe_nombre(abb->hizq, ident);
            } else {
                return abb_secuencia_existe_nombre(abb->hder, ident);
            }
        }
    }
}

/// devuelve secuencia de abb por nombre
secuencia abb_secuencia_obtener_por_nombre(abbSecuencia abb, string ident){
    string nom;
    strcrear(nom);
    secuencia_dar_nombre(abb->info, nom);
    if(streq(nom, ident)){
        return abb->info;
    } else {
        if(strmen(ident, nom)){
            return abb_secuencia_obtener_por_nombre(abb->hizq, ident);
        } else {
            return abb_secuencia_obtener_por_nombre(abb->hder, ident);
        }
    }
}

/// Lista todas las secuencias registrados en el sistema, ordenados por identificador alfabeticamente y lista de entero ( nombre = [ valores ] )
void abb_secuencia_mostrar_en_orden(abbSecuencia abb){
    if(abb != NULL){
        abb_secuencia_mostrar_en_orden(abb->hizq);
        secuencia_mostrar(abb->info);
        abb_secuencia_mostrar_en_orden(abb->hder);
    }
}

void abb_secuencia_ins_back(abbSecuencia &abb, string ident, int valor){
    string nom;
    strcrear(nom);
    secuencia_dar_nombre(abb->info, nom);
    if(streq(nom, ident)){
        // modifica abb->info (secuencia)
        secuencia_ins_back(abb->info, valor);
    } else {
        if(strmen(ident, nom)){
            abb_secuencia_ins_back(abb->hizq, ident, valor);
        } else {
            abb_secuencia_ins_back(abb->hder, ident, valor);
        }
    }
}

void abb_secuencia_liberar_memoria(abbSecuencia &abb){
    if(abb != NULL){
        abb_secuencia_liberar_memoria(abb->hizq);
        abb_secuencia_liberar_memoria(abb->hder);
        secuencia_liberar_memoria(abb->info);
        delete abb;
    }
}

