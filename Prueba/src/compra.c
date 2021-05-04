/*
 * compra.c
 *
 *  Created on: May 4, 2021
 *      Author: jessi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compra.h"
#include "cliente.h"


static int newID(void);
static int getInt(int* pResultado);
static int getString(char* array, int len);
static int esNumerica(char* cadena, int limite);


static int newID(void)
{
	static int id = 0;
	id = id+1;
	return id;
}

static int getString(char* array, int len)
{
	int ret=-1;
	char bufferString[ARRAY_LEN_STRING];
	if(array!=NULL && len>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=len)
			{
				strncpy(array,bufferString,len);
				ret=0;
			}
		}
	}
	return ret;
}

static int esNumerica(char* cadena, int limite)
{
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0)
	{
		retorno = 1;
		for(i=0;i<limite&&cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno = 0;
				printf("ERROR, Ingrese solo numeros enteros.\n");
				break;
			}
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[ARRAY_LEN_INT];
    if( pResultado!=NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		*pResultado = atoi(bufferString);
		retorno=0;

	}
    return retorno;
}



int inicializarArrayCompra(Compra* pArray,int limite) //Inicializar
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0) {
		for(i = 0; i < limite; i++) {
			pArray[i].isEmpty = VACIO;
		}

		retorno = 0;
	}

	return retorno;

}

int findEmptyCompra(Compra* pArray,int limite) //BuscarLibre
{
	int retorno = -1;
    int i;

	if(pArray != NULL && limite > 0) {
		for(i = 0; i < limite; i++) {
			if(pArray[i].isEmpty == VACIO) {
				retorno = i;
				break;
			}
		}
	}

    return retorno;
}

int findIdClienteEnCompra(Compra* pArray,int limite, int id) //BuscarLibre
{
	int retorno = -1;
    int i;

    if(pArray != NULL && limite > 0) {
    		for(i = 0; i < limite; i++) {
    			if(pArray[i].idCliente == id) {
    				retorno = i;
    				break;
    			}
    		}
    	}

    return retorno;
}

int printComprasPorIdCliente(Compra* pArray,int limite, int id) //BuscarLibre
{
	int retorno = -1;
    int i;

    if(pArray != NULL && limite > 0) {
    		for(i = 0; i < limite; i++) {
    			if(pArray[i].idCliente == id) {
    				printf("\nID de Venta: %d\n", pArray[i].idVenta);


    				retorno = 0;
    			}
    		}
    	}

    return retorno;
}

int findEliminarIdClienteEnCompra(Compra* pArray,int limite, int id) //BuscarLibre
{
	int retorno = -1;
    int i;

    if(pArray != NULL && limite > 0) {
    		for(i = 0; i < limite; i++) {
    			if(pArray[i].idCliente == id) {

    				pArray[i].isEmpty = VACIO;
    				retorno = 0;
    			}
    		}
    	}

    return retorno;
}

int realizarCompra(Compra* pArray, Cliente* pArrayCliente,int limite)
{
	int retorno = -1;
	int auxIndiceVenta = -1;
	Compra BufferCompra;
	int auxCantBarbijos = 1;
	//auxCantBarbijos = BufferCompra.cantidadBarbijos;
	int id = -1;
	int indice = -1;
	printf("\nIngrese ID del Cliente\n");
		getInt(&id);
		indice = findClientePorID(pArrayCliente,limite,id);

		if (indice != -1)
		{

	if(pArray != NULL && limite>0)
	{
		if(getNumeroCliente(&auxCantBarbijos,"\nIngrese cantidad de barbijos: ","\nError,cantidad invalida.\n",1,100,QTY_REINTENTOS) == 0 &&
				getApellidoCliente(BufferCompra.direccionEntrega,LEN_ENTREGA,"\nIngrese direccion de entrega: ","\nError,direccion invalida.\n",QTY_REINTENTOS) == 0 &&
				getApellidoCliente(BufferCompra.color,LEN_COLOR,"\nIngrese color de barbijos: ","\nError,color invalido.\n",QTY_REINTENTOS) == 0)
		{
			auxIndiceVenta = findEmptyCompra(pArray,limite);
			if(auxIndiceVenta != -1)
			{
				BufferCompra.idCliente = id;
				BufferCompra.idVenta = newID();
				BufferCompra.isEmpty = OCUPADO;
				strcpy(BufferCompra.estado, "Pendiente de cobrar");
			pArray[auxIndiceVenta] = BufferCompra;
			pArray[auxIndiceVenta].cantidadBarbijos = auxCantBarbijos;

			retorno = 0;
			printf("\nVenta realizada con exito.\n"
					"ID de Venta es: %d\n\n",pArray[auxIndiceVenta].idVenta);
			}
			else
			{
				printf("\nNo hay lugar para mas ventas.\n");
			}


		}
		else
		{
			printf("\nError ingresando venta.\n");
		}

	}
		}
		else
		{
			printf("\nID de Cliente invalido.\n");
		}


	return retorno;
}
