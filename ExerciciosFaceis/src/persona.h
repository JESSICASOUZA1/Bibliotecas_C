/*
 * persona.h
 *
 *  Created on: Apr 29, 2021
 *      Author: jessi
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#define ARRAY_LEN_STRING 4096
#define ARRAY_LEN_INT 64
#define ARRAY_LEN_NOMBRE 30
#define ARRAY_LEN_APELLIDO 50
#define LEN_CHAR 2
#define ARRAY_LEN_DNI 11
#define ARRAY_LEN_CUIT 14
#define ARRAY_LEN_TEL 20
#define QTY_REINTENTOS 2

#define MAX_PERSONAS 200



int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, float reintentos);
int utn_getTexto(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getApellido(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCaracter(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCuit(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getTelefono(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
int utn_getCaracterSN(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);

typedef struct
{
	char nombre[ARRAY_LEN_NOMBRE];
	char apellido[ARRAY_LEN_APELLIDO];
	char dni[ARRAY_LEN_DNI];
	int isEmpty;

}Persona;

typedef struct
{
	char nombre[50];
	char apellido[50];
    float peso;
    float altura;
}Personaa;

int inicializarArrayPersonas(Persona* array,int limite);
int findEmpty(Persona* pArray,int limite);
int inicializarArrayFloat(float* pArray,int longitud,int valorInicial);
int imprimirArrayFloat(float* pArray,int longitud);

int altaPersona(Persona* array,int limite);

#endif /* PERSONA_H_ */
