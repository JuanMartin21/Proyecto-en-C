#include "listaString.h"
#include "listaNaturales.h"
#include "secuencia.h"
#include "abbSecuencia.h"
#include "utilitario.h"

int main()
{
    string texto, comando, param1, param2, param3, comando_en_minuscula, opcion;
    listaString comandos;
    abbSecuencia arbol;
    secuencia sec1;
    int nro;
    boolean salir;
    abb_secuencia_crear(arbol);


    do{
        salir = FALSE;
        strcrear(texto);
        lista_string_crear(comandos);
        printf("\n>> Ingrese comando: ");
        strscan(texto);
        strcrear(comando);
        strcrear(comando_en_minuscula);
        strcrear(param1);
        strcrear(param2);
        strcrear(param3);
        strcrear(opcion);

        lista_string_separar_palabras(texto, comandos);
        if (lista_string_contar_nodos(comandos) < 1){
            printf("\n\nERROR: El comando ingresado NO es reconocido por el sistema!");
        }else{
            lista_string_obtener_por_indice(comandos, 0, comando);

            string_a_minuscula(comando_en_minuscula, comando);
            /// CASO CREATE
            if(streq(comando_en_minuscula, "create")){
                if ( lista_string_contar_nodos(comandos) != 2 ){
                    printf("\n\nERROR: Cantidad de parametros incorrecta para el comando create! \nEjemplo: 'create identificador'");
                } else {
                    lista_string_obtener_por_indice(comandos, 1, param1);
                    if( !string_validar_alfabetico(param1) ){
                        printf("\n\nERROR: El identificador de la secuencia debe ser puramente alfabetico! \nEjemplo: 'create identificador'");
                    } else {
                        if( abb_secuencia_existe_nombre(arbol, param1) ){
                            printf("\n\nERROR: El identificador de la secuencia ya existe en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!");
                        } else {
                            secuencia_crear(sec1, param1);
                            abb_secuencia_insertar(arbol, sec1);
                            printf("\n\nSecuencia creada exitosamente!");
                        }
                    }
                }
            /// CASO INSBACK
            } else if(streq(comando_en_minuscula, "insback")){
                if ( lista_string_contar_nodos(comandos) != 3 ){
                    printf("\n\nERROR: Cantidad de parametros incorrecta para el comando insback! \nEjemplo: 'insback identificadorSec 12'");
                } else {
                    lista_string_obtener_por_indice(comandos, 1, param1);
                    if( !string_validar_alfabetico(param1) ){
                        printf("\n\nERROR: El identificador de la secuencia debe ser puramente alfabetico! \nEjemplo: 'insback identificadorSec 12'");
                    } else {
                        lista_string_obtener_por_indice(comandos, 2, param2);
                        if( !string_validar_numero_natural(param2) ){
                            printf("\n\nERROR: El segundo parametro debe ser un numero natural! \nEjemplo: 'insback identificadorSec 12'");
                        } else {
                            if( ! abb_secuencia_existe_nombre(arbol, param1) ){
                                printf("\n\nERROR: El identificador de la secuencia NO existe en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!");
                            } else {
                                nro = string_convert(param2);
                                abb_secuencia_ins_back(arbol, param1, nro);
                                printf("\n\nValor agregado a la secuencia exitosamente!");
                            }
                        }
                    }
                }
            /// CASO SHOW
            } else if(streq(comando_en_minuscula, "show")){
                if ( lista_string_contar_nodos(comandos) != 1 ){
                    printf("\n\nERROR: El comando show no requiere parametros para su invocacion!");
                } else {
                    if ( abb_secuencia_vacio(arbol) ){
                        printf("\n\nNo existen secuencias cargadas en el sistema!");
                    } else {
                        abb_secuencia_mostrar_en_orden(arbol);
                    }
                }
            /// CASO SUM
            } else if(streq(comando_en_minuscula,  "sum")){
                if ( lista_string_contar_nodos(comandos) != 2 ){
                    printf("\n\nERROR: Cantidad de parametros incorrecta para el comando sum! \nEjemplo: 'sum identificadorSec'" );
                } else {
                    lista_string_obtener_por_indice(comandos, 1, param1);
                    if( !string_validar_alfabetico(param1) ){
                        printf("\n\nERROR: El identificador de la secuencia debe ser puramente alfabetico! \nEjemplo: 'sum identificadorSec'");
                    } else {
                        if( ! abb_secuencia_existe_nombre(arbol, param1) ){
                            printf("\n\nERROR: El identificador de la secuencia NO existe en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!");
                        } else {
                            printf("\n\nLa suma de los valores de la secuencia da como resultado: %d", lista_naturales_sumar(secuencia_dar_lista(abb_secuencia_obtener_por_nombre(arbol, param1))));
                        }
                    }
                }
            /// CASO CONCAT
            } else if(streq(comando_en_minuscula, "concat")){
                if ( lista_string_contar_nodos(comandos) != 4 ){
                    printf("\n\nERROR: Cantidad de parametros incorrecta para el comando concat! \nEjemplo: 'concat identificadorSecA identificadorSecB identificadorSecNueva'");
                } else {
                    lista_string_obtener_por_indice(comandos, 1, param1);
                    lista_string_obtener_por_indice(comandos, 2, param2);
                    lista_string_obtener_por_indice(comandos, 3, param3);
                    if( !string_validar_alfabetico(param1) || !string_validar_alfabetico(param2) || !string_validar_alfabetico(param3) ){
                        printf( "\n\nERROR: Los identificadores de las secuencias deben ser puramente alfabeticos! \nEjemplo: 'concat identificadorSecA identificadorSecB identificadorSecNueva'" );
                    } else {
                        if( ! abb_secuencia_existe_nombre(arbol, param1) || ! abb_secuencia_existe_nombre(arbol, param2)){
                            printf("\n\nERROR: Los identificadores de las secuencias a concatenar deben existir en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!");
                        } else {
                            if( abb_secuencia_existe_nombre(arbol, param3) ){
                                printf( "\n\nERROR: El identificador de la secuencia nueva ya existe en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!" );
                            } else {
                                secuencia_crear(sec1, param3);
                                secuencia_concat(abb_secuencia_obtener_por_nombre(arbol, param1), abb_secuencia_obtener_por_nombre(arbol, param2), sec1);
                                abb_secuencia_insertar(arbol, sec1);
                                printf("\n\nSecuencia creada exitosamente!");
                            }
                        }
                    }
                }
            /// CASO REVERSE
            } else if(streq(comando_en_minuscula, "reverse")){
                if ( lista_string_contar_nodos(comandos) != 3 ){
                    printf("\n\nERROR: Cantidad de parametros incorrecta para el comando reverse! \nEjemplo: 'reverse identificadorSec identificadorSecNueva'" );
                } else {
                    lista_string_obtener_por_indice(comandos, 1, param1);
                    lista_string_obtener_por_indice(comandos, 2, param2);
                    if( !string_validar_alfabetico(param1) || !string_validar_alfabetico(param2) ){
                        printf("\n\nERROR: Los identificadores de las secuencias deben ser puramente alfabeticos! \nEjemplo: 'reverse identificadorSec identificadorSecNueva'" );
                    } else {
                        if( ! abb_secuencia_existe_nombre(arbol, param1) ){
                            printf("\n\nERROR: El identificador de la secuencia a invertir deben existir en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!");
                        } else {
                            if( abb_secuencia_existe_nombre(arbol, param2) ){
                                printf( "\n\nERROR: El identificador de la secuencia nueva ya existe en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!" );
                            } else {
                                secuencia_crear(sec1, param2);
                                secuencia_reverse(abb_secuencia_obtener_por_nombre(arbol, param1), sec1);
                                abb_secuencia_insertar(arbol, sec1);
                                printf("\n\nSecuencia creada exitosamente!");
                            }
                        }
                    }
                }
            /// CASO SAVE
            } else if(streq(comando_en_minuscula, "save")){
                if ( lista_string_contar_nodos(comandos) != 3 ){
                    printf("\n\nERROR: Cantidad de parametros incorrecta para el comando save! \nEjemplo: 'save identificadorSec nombreArchivo.txt'" );
                } else {
                    lista_string_obtener_por_indice(comandos, 1, param1);
                    if( !string_validar_alfabetico(param1) ){
                        printf("\n\nERROR: El identificador de la secuencia debe ser puramente alfabetico! \nEjemplo: 'save identificadorSec nombreArchivo.txt'" );
                    } else {
                        lista_string_obtener_por_indice(comandos, 2, param2);
                        if( ! string_validar_nombre_archivo_txt(param2) ){
                            printf("\n\nERROR: El nombre del archivo debe ser puramente alfabetico y finalizar en extension '.txt'! \nEjemplo: 'save identificadorSec nombreArchivo.txt'");
                        } else {
                            if( ! abb_secuencia_existe_nombre(arbol, param1) ){
                                printf("\n\nERROR: El identificador de la secuencia a guardar deben existir en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!" );
                            } else {
                                if ( utilitario_existe_archivo(param2) ){
                                    printf("\n\nEl archivo con el nombre: ");
                                    strprint(param2);
                                    printf(" ya existe! Desea sobreescribirlo (S / N)? ");

                                    strscan(opcion);
                                    if( streq(opcion, "s") || streq(opcion, "S") ) {
                                        secuencia_guardar(abb_secuencia_obtener_por_nombre(arbol, param1), param2);
                                        printf("\n\nSecuencia ");
                                        strprint(param1);
                                        printf(" almacenada correctamente en archivo");
                                        strprint(param2);
                                    } else {
                                        printf("\n\nOperacion cancelada!");
                                    }
                                } else {
                                    secuencia_guardar(abb_secuencia_obtener_por_nombre(arbol, param1), param2);
                                    printf("\n\nSecuencia ");
                                    strprint(param1);
                                    printf(" almacenada correctamente en archivo ");
                                    strprint(param2);
                                }
                            }
                        }
                    }
                }
            /// CASO LOAD
            } else if(streq(comando_en_minuscula, "load")){
                if ( lista_string_contar_nodos(comandos) != 3 ){
                    printf("\n\nERROR: Cantidad de parametros incorrecta para el comando load! \nEjemplo: 'load nombreArchivo.txt identificadorSecNueva'" );
                } else {
                    lista_string_obtener_por_indice(comandos, 2, param2);
                    if( !string_validar_alfabetico(param2) ){
                        printf("\n\nERROR: El identificador de la secuencia debe contener solo letras (mayusculas o minusculas)! \nEjemplo: 'load nombreArchivo.txt identificadorSecNueva'" );
                    } else {
                        lista_string_obtener_por_indice(comandos, 1, param1);
                        if( ! string_validar_nombre_archivo_txt(param1) ){
                            printf("\n\nERROR: El nombre del archivo debe ser puramente alfabetico y finalizar en extension '.txt'! \nEjemplo: 'load nombreArchivo.txt identificadorSecNueva'" );
                        } else {
                            if ( ! utilitario_existe_archivo(param1) ){
                                printf("\n\nERROR: El archivo no existe en disco!" );
                            } else {
                                if( abb_secuencia_existe_nombre(arbol, param2) ){
                                    printf("\n\nERROR: El identificador de la secuencia nueva ya existe en el sistema! \nUtilice comando 'show' para listar las secuencias existentes!" );
                                } else {
                                    secuencia_crear(sec1, param2);
                                    secuencia_leer(sec1, param1);
                                    abb_secuencia_insertar(arbol, sec1);
                                    printf("\n\nSecuencia cargada exitosamente!");
                                }
                            }
                        }
                    }
                }
            /// CASO EXIT
            } else if(streq(comando_en_minuscula, "exit")){
                if ( lista_string_contar_nodos(comandos) != 1 ){
                    printf("\n\nERROR: El comando exit no requiere parametros para su invocacion!" );
                } else {
                    abb_secuencia_liberar_memoria(arbol);
                    strdestruir(texto);
                    strdestruir(comando);
                    strdestruir(param1);
                    strdestruir(param2);
                    strdestruir(param3);
                    strdestruir(comando_en_minuscula);
                    strdestruir(opcion);
                    lista_string_liberar_memoria(comandos);
                    salir = TRUE;
                    printf("\n\nChau, chau! Adios!");
                }
            } else {
                printf("\n\nERROR: El comando ingresado NO es reconocido por el sistema!");
            }
        }
        printf("\n");
    } while( ! salir );


//  MOSTRAR A BEATRIZ
//    listaString lista;
//    lista_string_crear(lista);
//    string var, var2;
//    secuencia sec, sec2, secN, secR, secF;
//    strcrear(var);
//    strcrear(var2);
//
//    printf("\nIngrese string: ");
//    strscan(var);
//
//    secuencia_crear(sec, var);
//
//
//    secuencia_ins_back(sec, 13);
//    secuencia_mostrar(sec);
//    secuencia_ins_back(sec, 28);
//    secuencia_mostrar(sec);
//    secuencia_ins_back(sec, 1);
//    secuencia_mostrar(sec);
//    secuencia_ins_back(sec, 39);
//    secuencia_mostrar(sec);
//
//
//    printf("\nIngrese string: ");
//    strscan(var);
//
//    secuencia_crear(sec2, var);
//
//    secuencia_ins_back(sec2, 55);
//    secuencia_mostrar(sec2);
//    secuencia_ins_back(sec2, 66);
//    secuencia_mostrar(sec2);
//    secuencia_ins_back(sec2, 77);
//    secuencia_mostrar(sec2);
//    secuencia_ins_back(sec2, 88);
//    secuencia_mostrar(sec2);
//
//    printf("\nIngrese string: ");
//    strscan(var);
//
//    secuencia_crear(secN, var);
//
//    secuencia_concat(sec, sec2, secN);
//    secuencia_mostrar(secN);
//    printf("\nIngrese string: ");
//    strscan(var);
//
//    secuencia_crear(secR, var);
//    secuencia_reverse(secN, secR);
//    secuencia_mostrar(secR);
//
//    printf("\nIngrese nombre archivo: ");
//    strscan(var);
//    if(secuencia_existe_archivo(var)){
//        printf("\nExiste archivo!!");
//        printf("\nIngrese nombre de secuencia levantada de archivo: ");
//        strscan(var2);
//        secuencia_crear(secF, var2);
//        secuencia_leer(secF, var);
//        secuencia_mostrar(secF);
//    } else {
//        printf("\nNOOOOOO Existe archivo!! Pero lo vamos a crear!");
//        secuencia_guardar(secR, var);
//        printf("\nArchivo guardado exitosamente!");
//    }



//    listaNaturales listaN, lista2, listaContat;
//    lista_naturales_crear(listaN);
//    lista_naturales_crear(lista2);
//    lista_naturales_crear(listaContat);
//    lista_naturales_insertar_al_inicio(listaN, 25);
//    lista_naturales_insertar_al_final(listaN, 1);
//    lista_naturales_insertar_al_inicio(listaN, 33);
//    lista_naturales_insertar_al_final(listaN, 77);
//    lista_naturales_insertar_al_final(lista2, 44);
//    lista_naturales_insertar_al_final(lista2, 45);
//    lista_naturales_insertar_al_final(lista2, 46);
//    lista_naturales_mostrar(listaN);
//    printf("\nLa suma da: %d", lista_naturales_sumar(listaN));
//    printf("\nLa lista tiene: %d nodos", lista_naturales_contar_nodos(listaN));
//    //lista_naturales_liberar_memoria(listaN);
//    printf("\nLa lista tiene: %d nodos", lista_naturales_contar_nodos(listaN));
//    printf("\nLista 2 -> ");
//    lista_naturales_mostrar(lista2);
//    lista_naturales_concatenar(listaContat, listaN, lista2);
//    printf("\nLista concat -> ");
//    lista_naturales_mostrar(listaContat);
//    lista_naturales_crear(listaN);
//    lista_naturales_reverse(listaN, listaContat);
//    printf("\nLista concat invertida -> ");
//    lista_naturales_mostrar(listaN);
  //  33 25 1 77

//    listaString lista;
//    string var, var2;
//    strcrear(var);
//    strcrear(var2);
//    int nroConvertido;
//    lista_string_crear(lista);
//
//    printf("\nIngrese string: ");
//    strscan(var);
//
//    printf("\nEl string es: ");
//    strprint(var);
//
//    lista_string_separar_palabras(var, lista);
//    printf("\nLa lista de string contiene: ");
//    lista_string_mostrar(lista);
//    printf("\nLa lista contienen: %d nodos", lista_string_contar_nodos(lista));
//    lista_string_obtener_por_indice(lista, 3, var2);
//    printf("\nEl elemento elegido es: ");
//    strprint(var2);
//    lista_string_liberar_memoria(lista);
//    strdestruir(var);
//    strdestruir(var2);
//    printf("\nPost liberado de memoria lalista contienen: %d nodos", lista_string_contar_nodos(lista));




    return 0;
}
