#include "utilitario.h"

/// verifica si existe archivo con un nombre dado.
boolean utilitario_existe_archivo(string nombre_archivo){
    boolean existe = TRUE;
    FILE * f = fopen(nombre_archivo, "rb");
    if(f == NULL){
        existe = FALSE;
    } else {
        fclose(f);
    }
    return existe;
}
