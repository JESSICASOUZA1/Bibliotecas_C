/*
 * cliente.h
 *
 *  Created on: May 3, 2021
 *      Author: jessi
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "compra.h"

#define ARRAY_LEN_STRING 4096
#define ARRAY_LEN_INT 64
#define ARRAY_LEN_NOMBRE 30
#define ARRAY_LEN_APELLIDO 50
#define LEN_CHAR 2
#define ARRAY_LEN_DNI 11
#define ARRAY_LEN_CUIT 14
#define ARRAY_LEN_TEL 20
#define QTY_REINTENTOS 2
#define MAX_CLIENTES 5
#define MININO_ID 1
#define MAXIMO_ID 100
#define VACIO 0
#define OCUPADO 1


typedef struct
{
	int id;
	char nombre[ARRAY_LEN_NOMBRE];
	char apellido[ARRAY_LEN_APELLIDO];
	char cuit[ARRAY_LEN_CUIT];
	int isEmpty;

}Cliente;

/*
 * \brief Imprime un cliente por su numero de ID que se pasa como parametro
 * \param array Array de Cliente a ser actualizado
 * \param limite Limite del array de Cliente
 * \param id ID a ser buscado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 **/
int printClientePorID(Cliente* pArray,int limite,int id);

/**
 * \brief Actualiza los datos de un Cliente en una posicion del array
 * \param array Array de Cliente a ser actualizado
 * \param limite Limite del array de Cliente
 * \param indice es la posicion del ID a modificar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int modificarDatosCliente(Cliente* pArray,int limite);

/**
 * \brief Actualiza una posicion del array
 * \param array Array de Cliente a ser actualizado
 * \param limite Limite del array de Cliente
 * \param indice es la posicion del ID a borrar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int bajaCliente(Cliente* pArray, Compra* pArrayCompra,int limite);

/*
 * \brief Pide un numero al usuario dentro de un rango determinado
 * \param pResultado: puntero a int donde se guarda el valor del dato a mostrar enm el main, el numero.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeerror: puntero a mensaje de error que se le pasa en caso de error.
 * \param minimo y maximo: enteros donde se pasa el rango de numeros a tomar, el minimo aceptado y el maximo aceptado.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getNumeroCliente(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
/*
 * \brief Pide un numero decimal al usuario dentro de un rango determinado
 * \param pResultado: puntero a float donde se guarda el valor del dato a mostrar en el main, el numero.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param minimo y maximo: floats donde se pasa el rango de numeros a tomar, el minimo aceptado y el maximo aceptado.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getNumeroFlotanteCliente(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, float reintentos);
/*
 * \brief Pide un texto al usuario.
 * \param pResultado: puntero a char donde se guarda el dato a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getTextoCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
/*
 * \brief Pide un Nombre al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getNombreCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
/*
 * \brief Pide un Apellido al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getApellidoCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
/*
 * \brief Pide un Caracter al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getCaracterCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
/*
 * \brief Pide un DNI al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getDniCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
/*
 * \brief Pide un CUIT al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getCuitCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
/*
 * \brief Pide un Telefono al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getTelefonoCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);
/*
 * \brief Pide un Caracter solo S o N al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int getCaracterSNCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos);



int inicializarArrayCliente(Cliente* array,int limite);
int findEmpty(Cliente* pArray,int limite);
int findClientePorID(Cliente* pArray,int limite, int id);
int inicializarArrayFloat(float* pArray,int longitud,int valorInicial);
int imprimirArrayFloat(float* pArray,int longitud);
int altaArrayCliente(Cliente* array,int limite);

#endif /* CLIENTE_H_ */
