#include "listaNaturales.h"

void lista_naturales_crear(listaNaturales &lista){
    lista = NULL;
}

boolean lista_naturales_vacia(listaNaturales lista){
    boolean vacio = FALSE;
    if (lista == NULL)
        vacio = TRUE;
    return vacio;
}

void lista_naturales_insertar_al_inicio(listaNaturales &lista, int num){
    listaNaturales aux = new nodoNatural;
    aux -> info = num;
    aux -> sig = lista;
    lista = aux;
}

void lista_naturales_insertar_al_final(listaNaturales &L, int num){
    listaNaturales auxdos = L;
    listaNaturales aux = new nodoNatural;
    aux->info = num;
    if (auxdos != NULL){
        while(auxdos->sig != NULL){
            auxdos = auxdos->sig;
        }
        auxdos->sig = aux;
    }else{
      L = aux;
    }
    aux->sig = NULL;
}

void lista_naturales_mostrar(listaNaturales lista){
    if(lista != NULL){
        printf("%d", lista->info);
        printf(" ");
        lista_naturales_mostrar(lista->sig);
    }
}

int lista_naturales_contar_nodos(listaNaturales lista){
    if(lista != NULL){
        return 1 + lista_naturales_contar_nodos(lista->sig);
    } else {
        return 0;
    }
}

int lista_naturales_sumar(listaNaturales lista){
    if(lista != NULL){
        return lista->info + lista_naturales_sumar(lista->sig);
    } else {
        return 0;
    }
}

void lista_naturales_liberar_memoria(listaNaturales &lista){
    if (lista != NULL){
        listaNaturales aux = lista;
        lista = lista -> sig;
        delete aux;
        lista_naturales_liberar_memoria(lista);
    }
}

void lista_naturales_concatenar(listaNaturales &listaNueva, listaNaturales lista1, listaNaturales lista2){
    lista_naturales_crear(listaNueva);
    while(lista1 != NULL){
        lista_naturales_insertar_al_final(listaNueva, lista1->info);
        lista1 = lista1->sig;
    }
    while(lista2 != NULL){
        lista_naturales_insertar_al_final(listaNueva, lista2->info);
        lista2 = lista2->sig;
    }
}

void lista_naturales_reverse(listaNaturales &listaNueva, listaNaturales lista1){
    lista_naturales_crear(listaNueva);
    while(lista1 != NULL){
        lista_naturales_insertar_al_inicio(listaNueva, lista1->info);
        lista1 = lista1->sig;
    }
}
