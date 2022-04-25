#include "string.h"

void strcrear (string &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strdestruir (string &s)
{
    delete [] s;
    strcrear(s);
}

int strlar (string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strprint (string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        printf("%c", s[i]);
        i++;
    }
}

void strcop (string &s1, string s2)
{
    int largo = strlar(s2);
    delete [] s1;
    s1 = new char[largo + 1];
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

// precondicion: indices entre 0 y strlar
void strcopiar_entre_indices (string &stringNuevo, string strOrigen, int inicio, int fin){
    int largo = fin-inicio;
    delete [] stringNuevo;
    stringNuevo = new char[largo + 1];
    int i = 0;
    while (i+inicio<=fin)
    {
        stringNuevo[i] = strOrigen[i+inicio];
        i++;
    }
    stringNuevo[i] = '\0';
}

void strscan (string &s)
{
    string aux=new char [MAX];
    int i=0;

    fflush(stdin);
    scanf("%c",&aux[i]);
    while((aux[i]!='\n')&&(i<MAX-1))
    {
        i++;
        scanf("%c",&aux[i]);
    }
    aux[i]='\0';
    strcop(s,aux);
    strdestruir(aux);
}

void strcon (string &s1, string s2)
{
    string aux = new char [strlar(s1)+ strlar(s2)+1];
    int i = 0,j=0;
    while (s1[i] != '\0')
    {
        aux[i] = s1[i];
        i++;
    }
    while(s2[j]!='\0')
    {
        aux[i]=s2[j];
        j++;
        i++;
    }
    aux[i]='\0';
    strdestruir(s1);
    s1=aux;
}

void strswp (string &s1, string &s2)
{
   string aux = s2;
   s2=s1;
   s1=aux;
}

boolean strmen (string s1, string s2)
{
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
            menor = TRUE;
    return menor;

}

boolean streq (string s1, string s2)
{
     boolean igual=TRUE;
    int i=0;
    while((s1[i]!='\0')&&(s2[i]!='\0')&& igual)
    {
        if(s1[i]!=s2[i])
            igual=FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        igual = FALSE;
    return igual;
}

boolean string_validar_alfabetico(string s1){
    boolean esAlfabetico = TRUE;
    int i = 0;
    while (esAlfabetico && s1[i] != '\0'){
        if( ! ( (s1[i] >= 65 && s1[i] <= 90) || (s1[i] >= 97 && s1[i] <= 122) ) ){
            esAlfabetico = FALSE;
        } else {
            i++;
        }
    }
    return esAlfabetico;
}

boolean string_validar_numero_natural(string s1){
    boolean esNatural = TRUE;
    int i = 0;
    while (esNatural && s1[i] != '\0'){
        if( ! (s1[i] >= 48 && s1[i] <= 57) ){
            esNatural = FALSE;
        } else {
            i++;
        }
    }
    return esNatural;
}

boolean string_validar_nombre_archivo_txt(string s1){
    boolean cortarEjecucion = FALSE;
    boolean nombreValido = FALSE;
    boolean encuentroPunto = FALSE;
    boolean resultadoFinal = FALSE;
    int i = 0;
    while (!encuentroPunto && s1[i] != '\0' && !cortarEjecucion){
        if(  (s1[i] >= 65 && s1[i] <= 90) || (s1[i] >= 97 && s1[i] <= 122) ){
            nombreValido = TRUE;
        } else if(s1[i] == 46){
            encuentroPunto = TRUE;
            if(!nombreValido){
                cortarEjecucion = TRUE;
            }
        } else {
            cortarEjecucion = TRUE;
        }
        i++;
    }
    if(encuentroPunto && nombreValido && !cortarEjecucion){
        if(     s1[i]  != '\0'  && s1[i]   == 't'
            && s1[i+1] != '\0'  && s1[i+1] == 'x'
            && s1[i+2] != '\0'  && s1[i+2] == 't'
            && s1[i+3] == '\0'){
                resultadoFinal = TRUE;
            }
    }
    return resultadoFinal;
}

int string_convert(string s){
    int multiplicador = 1, i, resultado = 0, nroCaracter;

    for(i=strlar(s)-1; i>=0; i--){
        nroCaracter = s[i] - 48;
        resultado = resultado + (nroCaracter * multiplicador);
        multiplicador = multiplicador * 10;
    }
    return resultado;
}

void string_a_minuscula(string &s1, string s2){
    int largo = strlar(s2);
    delete [] s1;
    s1 = new char[largo + 1];
    int i = 0;
    while (s2[i] != '\0')
    {
        // si es mayuscula
        if(s2[i] >= 65 && s2[i] <= 90){
            s1[i] = s2[i] + 32;
        } else {
            s1[i] = s2[i];
        }
        i++;
    }
    s1[i] = '\0';
}

