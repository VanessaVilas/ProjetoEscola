#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Escola.h"

int verifica_numero(char CARACTER);
int verifica_ano_bisexto(int iAno);
int valida_numeros(int iDia, int iMes, int iAno);
int validarCPF(char *cpf);

int validar_data(char *data, Data *d){
    int iDia;
    int iMes;
    int iAno;
    int retorno;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int iCont;
    int jCont;
    int verificacao;
    
    for (iCont = 0; data[iCont] != '/'; iCont++){
        sDia[iCont] = data[iCont];
        if(iCont >= 3)
            return FALSE;
    }

    sDia[iCont] = '\0';
    
    for (jCont = 0; sDia[jCont] != '\0'; jCont++){
        verificacao = verifica_numero(sDia[jCont]);
        if(verificacao == FALSE)
            return FALSE;
    }
    
    if (strlen(sDia) == 0)
        return FALSE;
 
    iDia = atoi(sDia); 
 
    for (iCont = iCont+1, jCont = 0; data[iCont] != '/'; iCont++, jCont++){
        sMes[jCont] = data[iCont];
        if(jCont >= 3)
            return FALSE;
    }
    
    sMes[jCont] = '\0';
    
    for (jCont = 0; sMes[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sMes[jCont]);
            if(verificacao == FALSE)
                return FALSE;
    }
    
    if (strlen(sMes) == 0)
        return FALSE;
    
    iMes = atoi(sMes); 
  
    for (iCont = iCont+1, jCont=0; data[iCont] != '\0' ; iCont++, jCont++){
        sAno[jCont] = data[iCont];
    }
    sAno[jCont] = '\0';
    
    for (jCont = 0; sAno[jCont] != '\0'; jCont++){
        verificacao= verifica_numero(sAno[jCont]);
        if(verificacao == FALSE)
            return FALSE;
    }
        
    if(strlen(sAno) == 0)
        return FALSE;
    
    iAno = atoi(sAno); 
 
    retorno= valida_numeros(iDia, iMes, iAno);
    
    d->dia = iDia;
    d->mes = iMes;
    d->ano = iAno;

    return retorno;
}

int valida_numeros(int iDia, int iMes, int iAno){
    int bissexto = verifica_ano_bisexto(iAno);
    
    if(iDia < 1 || iDia > 31)
        return FALSE;
    
    else if(iDia >= 31 && (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11 ))
        return FALSE;
    
    else if (iMes < 1 || iMes > 12)
        return FALSE;
    
    else if(iDia> 29 && iMes == 2 && bissexto == TRUE)
        return FALSE;
    
    else if(iDia> 28 && iMes == 2 && bissexto == FALSE)
        return FALSE;
    
    else if(iAno <= 0 )
        return FALSE;
      
    else if(iAno >= 10000)
        return FALSE;
    
  return TRUE;  
}

int verifica_ano_bisexto(int iAno){
    if(((iAno%4) == 0) && ((iAno%100) != 0) && ((iAno%400) != 0))
        return TRUE;
    return FALSE;
}

int verifica_numero(char CARACTER){
    if(CARACTER < '0' && CARACTER > '9' )
        return FALSE;
    
    return TRUE;
}

int validarCPF(char *cpf) {
    int i, j, primeiro_digito = 0, segundo_digito = 0;
    int numeros[11];
    int tamanho = 0;

    for (i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            if (tamanho < 11)
                numeros[tamanho++] = cpf[i] - '0';
        }
    }

    if (tamanho != 11)
        return 0;

    int iguais = 1;
    for (i = 1; i < 11; i++) {
        if (numeros[i] != numeros[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais)
        return 0;

    for (i = 0, j = 10; i < 9; i++, j--) 
    primeiro_digito += numeros[i] * j;
    primeiro_digito = (primeiro_digito * 10) % 11;
    if (primeiro_digito == 10) primeiro_digito = 0;

    for (i = 0, j = 11; i < 10; i++, j--)
    segundo_digito += numeros[i] * j;
    segundo_digito = (segundo_digito * 10) % 11;
    if (segundo_digito == 10) segundo_digito = 0;

    return (primeiro_digito == numeros[9] && segundo_digito == numeros[10]);
}
