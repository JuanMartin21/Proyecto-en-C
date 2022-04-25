#include "listaString.h"

void lista_string_crear(listaString &lista){
    lista = NULL;
}

boolean lista_string_vacia(listaString lista){
    boolean vacio = FALSE;
    if (lista == NULL)
        vacio = TRUE;
    return vacio;
}

void lista_string_insertar_al_final(listaString &L, string texto){
    listaString auxdos = L;
    listaString aux = new NodoLista;
    strcrear(aux->info);
    strcop(aux->info, texto);
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

void lista_string_mostrar(listaString lista){
    if(lista != NULL){
        strprint(lista->info);
        printf(" - ");
        lista_string_mostrar(lista->sig);
    }
}

void lista_string_separar_palabras(string texto, listaString &lista){
    int i=0, inicioPalabra = 0, finPalabra = 0;
    boolean leyendoPalabra = FALSE;
    while (texto[i] !='\0'){
        if(texto[i] != ' ' && !leyendoPalabra){
            inicioPalabra = i;
            leyendoPalabra = TRUE;
        }
        if(leyendoPalabra && (texto[i] == ' ' || texto[i+1] =='\0')){
            string aux;
            strcrear(aux);
            if(texto[i] == ' '){
                finPalabra = i-1;
            } else {
                finPalabra = i;
            }
            strcopiar_entre_indices(aux, texto, inicioPalabra, finPalabra);
            lista_string_insertar_al_final(lista, aux);
            leyendoPalabra = FALSE;
        }
        i++;
    }
}

int lista_string_contar_nodos(listaString lista){
    if(lista != NULL){
        return 1 + lista_string_contar_nodos(lista->sig);
    } else {
        return 0;
    }
}

void lista_string_obtener_por_indice(listaString lista, int pos, string &s){
    if(pos != 0){
        lista_string_obtener_por_indice(lista->sig, pos-1, s);
    } else {
        strcop(s, lista->info);
    }
}

void lista_string_liberar_memoria(listaString &lista){
    if (lista != NULL){
        listaString aux = lista;
        lista = lista -> sig;
        delete aux;
        lista_string_liberar_memoria(lista);
    }
}
