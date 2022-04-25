#include "secuencia.h"

void secuencia_crear(secuencia &sec, string nom){
    strcrear(sec.nombre);
    strcop(sec.nombre, nom);
    lista_naturales_crear(sec.lista);
}

void secuencia_mostrar(secuencia sec){
    printf("\n");
    strprint(sec.nombre);
    printf(" = [ ");
    lista_naturales_mostrar(sec.lista);
    printf("]");
}

void secuencia_dar_nombre(secuencia sec, string &nom){
    strcop(nom, sec.nombre);
}

listaNaturales secuencia_dar_lista(secuencia sec){
    return sec.lista;
}

void secuencia_ins_back(secuencia &sec, int nro){
    lista_naturales_insertar_al_final(sec.lista, nro);
}

void secuencia_concat(secuencia sec1, secuencia sec2, secuencia &secNueva){
    lista_naturales_concatenar(secNueva.lista, sec1.lista, sec2.lista);
}

void secuencia_reverse(secuencia secOriginal, secuencia &secNueva){
    lista_naturales_reverse(secNueva.lista, secOriginal.lista);
}

void secuencia_guardar(secuencia sec, string nombre_archivo){
    FILE * f = fopen(nombre_archivo, "wb");
    while (sec.lista != NULL){
        fwrite (&sec.lista->info, sizeof(int), 1, f);
        sec.lista = sec.lista -> sig;
    }
    fclose(f);
}

void secuencia_leer(secuencia &sec, string nombre_archivo){
    lista_naturales_crear(sec.lista);
    int aux;
    FILE * f = fopen(nombre_archivo, "rb");
    fread (&aux, sizeof(int), 1, f);
    while (!feof (f)){
        lista_naturales_insertar_al_final(sec.lista, aux);
        fread (&aux, sizeof(int), 1, f);
    }
    fclose(f);
}

void secuencia_liberar_memoria(secuencia &sec){
    lista_naturales_liberar_memoria(sec.lista);
    strdestruir(sec.nombre);
}
