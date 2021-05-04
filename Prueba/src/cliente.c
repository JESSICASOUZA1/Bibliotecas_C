/*
 * cliente.c
 *
 *  Created on: May 3, 2021
 *      Author: jessi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compra.h"
#include "cliente.h"

/*********Prototipos*********/
static int newID(void);
static int getString(char* array, int len);
static int getInt(int* pResultado);
static int esNumerica(char* cadena, int limite);
static int getFloat(float* pResultado);
static int esNumericaFloat(char* cadena, int limite);
static int getTexto(char* pResultado, int longitud);
static int esTexto(char* cadena,int longitud);
static int esNombre(char* cadena,int longitud);
static int getNombre(char* pResultado, int longitud);
static int getApellido(char* pResultado, int longitud);
static int esApellido(char* cadena,int longitud);
static int getCaracter(char* pResultado, int longitud);
static int esCaracter(char* cadena, int longitud);
static int getDni(char* pResultado, int longitud);
static int getCuit(char* pResultado, int longitud);
static int esDNI(char* cadena, int longitud);
static int esCUIT(char* cadena, int longitud);
static int getTelefono(char* pResultado, int longitud);
static int esTelefono(char* cadena,int longitud);
static int getCaracterSN(char* pResultado, int longitud);
static int esCaracterSN(char* cadena, int longitud);

/////////Funciones Estaticas////////

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

static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[ARRAY_LEN_INT];
    if( pResultado!=NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
		esNumericaFloat(bufferString,sizeof(bufferString)))
	{
		*pResultado = atof(bufferString);
		retorno=0;
	}
    return retorno;
}

static int getTexto(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_STRING];
	if(pResultado!=NULL && longitud>0)
	{
		if( !getString(bufferString,sizeof(bufferString)) &&
		    esTexto(bufferString, sizeof(bufferString)))
		{
			strncpy(pResultado,bufferString,longitud);
			res = 0;
		}
	}
	return res;
}

static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[ARRAY_LEN_NOMBRE];
    if(pResultado!=NULL && longitud>0)
    {
    	if(	!getString(buffer,sizeof(buffer)) &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

static int getApellido(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[ARRAY_LEN_APELLIDO];
    if(pResultado!=NULL && longitud>0)
    {
    	if(	!getString(buffer,sizeof(buffer)) &&
    		esApellido(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
    }
    return retorno;
}

static int getCaracter(char* pResultado, int longitud)
{
	int retorno=-1;
    char buffer[LEN_CHAR];
	if(pResultado!=NULL && longitud>0)
	{
		if(	!getString(buffer,sizeof(buffer)) &&
			esCaracter(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
	}
	return retorno;
}

static int getDni(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_DNI];
	if( pResultado != NULL && longitud > 0 &&
	    !getString(bufferString, sizeof(bufferString)) &&
	    esDNI(bufferString, sizeof(bufferString)))
	{
		strncpy(pResultado, bufferString, longitud);
		res = 0;
	}
	return res;
}

static int getCuit(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_CUIT];
	if( pResultado != NULL && longitud > 0 &&
	    !getString(bufferString, sizeof(bufferString)) &&
	    esCUIT(bufferString, sizeof(bufferString)))
	{
		strncpy(pResultado, bufferString, longitud);
		res = 0;
	}
	return res;
}

static int getTelefono(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_TEL];
	if( pResultado != NULL && longitud > 0 &&
	    !getString(bufferString, sizeof(bufferString)) &&
	    esTelefono(bufferString,sizeof(bufferString)))
	{
		res = 0;
		strncpy(pResultado,bufferString,longitud);
	}
	return res;
}

static int getCaracterSN(char* pResultado, int longitud)
{
	int retorno=-1;
    char buffer[LEN_CHAR];
	if(pResultado!=NULL && longitud>0)
	{
		if(	!getString(buffer,sizeof(buffer)) &&
			esCaracterSN(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
	}
	return retorno;
}

/////////Estaticas Validaciones//////////

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

static int esNumericaFloat(char* cadena, int limite)
{
	int i=0;
	int retorno = -1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		retorno = 1;
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					if(contadorPuntos>0)
					{
						retorno=0;
						printf("El numero no puede contener mas de una coma.\n");
						break;
					}
					retorno = 0;
					printf("ERROR, Ingrese solo numeros.\n");
					break;
				}
			}
		}
	}
	return retorno;
}

static int esTexto(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud;i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) &&
			   (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != ' ') &&
			   (cadena[i] != ',') && (cadena[i] != '.') &&
			   (cadena[i] != '+') && (cadena[i] != '-') &&
			   (cadena[i] != '?'))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}

static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z'))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}

static int esApellido(char* cadena,int longitud)
{
	int i=0;
	int retorno=1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud;i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') &&
			   (cadena[i]!=' '))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}

static int esCaracter(char* cadena, int longitud)
{
	int i=0;
	int retorno=1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud; i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z' ) && (cadena[i]<'a' || cadena[i]>'z'))
			{
				retorno=0;
				printf("Error de validacion, solo puede ingresar un caracter.\n");
				break;
			}
		}
	}
	return retorno;
}

static int esCaracterSN(char* cadena, int longitud)
{
	int i=0;
	int retorno=1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud; i++)
		{
			if(cadena[i]!='S' && cadena[i]!='N' && cadena[i]!='s' && cadena[i]!='n')
			{
				retorno=0;
				printf("Error de validacion, solo puede ingresar S o N.\n");
				break;
			}
		}
	}
	return retorno;
}

static int esDNI(char* cadena, int longitud)
{
	int i=0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	int contadorPuntos = 0;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0;cadena[i]!='\0'; i++)
		{
			//Menos de 6 numeros->ERROR
			if(lengthCadena < 6)
			{
				retorno = 0;
				if((cadena[i] < '0' || cadena[i] > '9'))
				{
					printf("El DNI no puede contener letras\n");
					break;
				}
				else
				{
					printf("El DNI no puede tener menos de 6 numeros\n");
					break;
				}
			}
			//Contador de puntos
			if(cadena[i]=='.')
			{
				contadorPuntos++;
			}
			//Si comienza con un punto ERROR
			if(i==0 && cadena[i]=='.')
			{
				retorno = 0;
				printf("El DNI no puede empezar con un punto\n");
				break;
			}
			//Si contiene letras->ERROR
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.'))
			{
				retorno = 0;
				printf("El DNI no puede contener letras\n");
				break;
			}
		}
	}
	if(contadorPuntos == 0)
	{
		retorno = 0;
		printf("El DNI debe contener puntos\n");
	}
	else if(contadorPuntos == 1)
	{
		retorno = 0;
		printf("El DNI debe contener mas de un punto\n");
	}
	else if(contadorPuntos > 2)
	{
		retorno = 0;
		printf("El DNI no puede contener mas de dos puntos\n");
	}
	return retorno;
}

static int esCUIT(char* cadena, int longitud)
{
	int i=0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	int contadorGuiones = 0;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			//Contador de guiones
			if(cadena[i]=='-')
			{
				contadorGuiones++;
			}
			//Menos de 13 numeros->ERROR
			if(lengthCadena < 13)
			{
				retorno = 0;
				if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '-'))
				{
					printf("El CUIT no puede contener letras\n");
					break;
				}
				else
				{
					printf("El CUIT debe contener 11 numeros y dos guiones\n");
					break;
				}
			}
			//Si comienza con un guion ERROR
			if(i==0 && cadena[i]=='-')
			{
				retorno = 0;
				printf("El CUIT no puede empezar con un guion\n");
				break;
			}
			//Si contiene letras->ERROR
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '-'))
			{
				retorno = 0;
				printf("El CUIT no puede contener letras, espacios ni caracteres especiales\n");
				break;
			}
		}
	}
	if(contadorGuiones == 0)
	{
		retorno = 0;
		printf("Respete el formato [xx-xxxxxxxx-x]\n");
	}
	else if(contadorGuiones == 1)
	{
		retorno = 0;
		printf("Respete el formato [xx-xxxxxxxx-x]\n");
	}
	else if(contadorGuiones > 2)
	{
		retorno = 0;
		printf("El CUIT no puede contener mas de dos guiones\n");
	}
	return retorno;
}

static int esTelefono(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud; i++)
		{
			if(lengthCadena<=7)
			{
				retorno = 0;
				printf("El telefono no puede contener menos de 8 numeros\n");
				break;
			}
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != ' ') &&
			   (cadena[i] != '-'))
			{
				retorno = 0;
				printf("Error de validacion, los telefonos solo contienen numeros, espacios y guiones medios.\n");
				break;
			}
		}
	}
	return retorno;
}


//////////////GET////////////////

int getNumeroCliente(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
	int ret = -1;
	int bufferInt;
	int i;
	for(i=0;i<=reintentos;i++){
		if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && minimo<=maximo && reintentos>0)
		{
			printf("%s", pMensaje);
			if(!getInt(&bufferInt))
			{
				if(bufferInt>=minimo && bufferInt<=maximo)
				{
					*pResultado = bufferInt;
					ret = 0;
					break;
				}
				else
				{
					printf("%s - Fuera de rango\n", pMensajeError);
				}
			}
		}
	}
	return ret;
}

int getNumeroFlotanteCliente(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, float reintentos)
{
	int ret = -1;
	float bufferFloat;
	int i;
	for(i=0;i<=reintentos;i++){
		if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && minimo<=maximo && reintentos>0)
		{
			printf("%s", pMensaje);
			if(!getFloat(&bufferFloat))
			{
				if(bufferFloat>=minimo && bufferFloat<=maximo)
				{
					*pResultado = bufferFloat;
					ret = 0;
					break;
				}
				else
				{
					printf("%s - Fuera de rango\n", pMensajeError);
				}
			}
		}
	}
	return ret;
}

int getTextoCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[ARRAY_LEN_STRING];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if( !getTexto(bufferString,sizeof(bufferString)) &&
			strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno=0;
			break;
		}
		else
		{
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}

int getNombreCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[ARRAY_LEN_NOMBRE];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && longitud>0 && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s",pMensaje);
			if(	!getNombre(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud)
			{
				strncpy(pResultado,bufferString,longitud);
				retorno=0;
				break;
			}
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}

int getApellidoCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[ARRAY_LEN_APELLIDO];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s", pMensaje);
			if( !getApellido(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud)
			{
				strncpy(pResultado,bufferString,longitud);
				retorno=0;
				break;
			}
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}

int getCaracterCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[LEN_CHAR];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s",pMensaje);
			if( !getCaracter(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud )
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}

int getDniCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[ARRAY_LEN_DNI];
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if(!getDni( bufferString,sizeof(bufferString)) &&
				    strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}
	return retorno;
}

int getCuitCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[ARRAY_LEN_CUIT];
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if(!getCuit( bufferString,sizeof(bufferString)) &&
				     strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}
	return retorno;
}

int getTelefonoCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[ARRAY_LEN_TEL];
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if(!getTelefono( bufferString,sizeof(bufferString)) &&
				         strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}
	return retorno;
}

int getCaracterSNCliente(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[LEN_CHAR];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s",pMensaje);
			if( !getCaracterSN(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud )
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}

/////////////////////////////////////Arrays//////////////////////////////////////////


void hardCode(Cliente* pArray,int limite)
{





}


/**\brief Setea flag (isEmpty) en 1 para todos para inicializar array
 * \param pArray Array de personas a ser inicializado
 * \param limite Limite del array de personas
 * \return Retorna -1 (ERROR) y 0 (EXITO)
 */
int inicializarArrayCliente(Cliente* pArray,int limite) //Inicializar
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

/**
 * \brief Busca la primer ocurrencia de un espacio vacio en un array de Personas
 * \param Array es el array en el cual buscar
 * \param Limites indica la logitud del array
 * \param posicion es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */
int findEmpty(Cliente* pArray,int limite) //BuscarLibre
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

/**
 * \brief Busca la primer ocurrencia de un valor en un array de Personas
 * \param Array es el array en el cual buscar
 * \param Limites indica la logitud del array
 * \param posicion es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */
int findClientePorID(Cliente* pArray,int limite, int id) //BuscarLibre
{
	int retorno = -1;
    int i;

	if(pArray != NULL && limite > 0) {
		for(i = 0; i < limite; i++) {
			if(pArray[i].id == id) {
				retorno = i;
				break;
			}
		}
	}

    return retorno;
}

int printClientePorID(Cliente* pArray,int limite,int id)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && limite > 0 && id > 0) {

		for(i = 0; i < limite; i++) {
			if(pArray[i].id == id) {
				printf("ID: %d - Nombre: %s - Apellido: %s - Cuit: %s",
						pArray[i].id, pArray[i].nombre, pArray[i].apellido,
						pArray[i].cuit);
			}
		}

		retorno = 0;
	}
    return retorno;
}

int altaArrayCliente(Cliente* pArray,int limite)
{
	int retorno = -1;
	int auxIndiceCliente = -1;
	Cliente BufferCliente;

	if(pArray != NULL && limite>0)
	{
		if(getNombreCliente(BufferCliente.nombre,ARRAY_LEN_NOMBRE,"\nIngrese nombre: ","\nError,nombre invalido.\n",QTY_REINTENTOS) == 0 &&
				getApellidoCliente(BufferCliente.apellido,ARRAY_LEN_APELLIDO,"\nIngrese apellido: ","\nError,apellido invalido.\n",QTY_REINTENTOS) == 0 &&
				getCuitCliente(BufferCliente.cuit,ARRAY_LEN_CUIT,"\nIngrese CUIT: ","\nError,CUIT invalido",QTY_REINTENTOS) == 0)
		{
			auxIndiceCliente = findEmpty(pArray,limite);
			if(auxIndiceCliente != -1)
			{
			BufferCliente.id = newID();
			BufferCliente.isEmpty = OCUPADO;
			pArray[auxIndiceCliente] = BufferCliente;
			retorno = 0;
			}
			printf("\nAlta con exito.\n"
					"ID de Cliente es: %d\n\n",pArray[auxIndiceCliente].id);

		}
		else
		{
			printf("\nNo hay lugar para mas clientes.\n");
		}

	}


	return retorno;
}

int modificarDatosCliente(Cliente* pArray,int limite)
{
	int retorno = -1;
	Cliente bufferCliente;
	int id = -1;
	int indice = -1;


	printf("\nIngrese ID del Cliente\n");
	getInt(&id);
	indice = findClientePorID(pArray,limite,id);

	if (indice != -1)
	{
	if(pArray != NULL && limite > 0 && id >= 0)
	{
		if(getNombreCliente(bufferCliente.nombre,ARRAY_LEN_NOMBRE,"\nIngrese nuevo Nombre: ", "\nError, nombre invalido.\n",
				QTY_REINTENTOS) == 0 && getApellidoCliente(bufferCliente.apellido,ARRAY_LEN_APELLIDO, "\nIngrese nuevo Apellido: ","\nError, apellido invalido.\n",QTY_REINTENTOS) == 0
				&& getCuitCliente(bufferCliente.cuit, ARRAY_LEN_CUIT,"\nIngrese nuevo Cuit: ", "\nError, cuit invalido.\n",QTY_REINTENTOS)==0)
		{
			pArray[indice] = bufferCliente;
			retorno = 0;
			printf("\nSe modifico con exito.\n");
		} else {
			printf("No se encontro el ID ingresado.\n");
		}
	}
	}else {
		printf("No se encontro el ID ingresado.\n");
	}

	return retorno;
}

int bajaCliente(Cliente* pArray, Compra* pArrayCompra,int limite)
{

	int retorno = -1;
		Cliente bufferCliente;
		char bufferChar;
		int id = -1;
		int indice = -1;
		int indiceConIdEnCompra = -1;


		printf("\nIngrese ID del Cliente\n");
		getInt(&id);
		indice = findClientePorID(pArray,limite,id);

		if (indice != -1)
		{
			printf("\nCompras del Cliente:\n");

			if(pArray != NULL && limite > 0 && indice >= 0) {
				if(getCaracterSNCliente(&bufferChar,LEN_CHAR,
						"Estas seguro que desea borrar este cliente y todas sus compras?[S/N]:","\nError,solo puedes ingresar S o N \n",QTY_REINTENTOS) == 0)
				{
					switch(bufferChar) {
					case 'S':
					case 's':
						pArray[indice].isEmpty = VACIO;

						if (findEliminarIdClienteEnCompra(pArray,limite,id) == -1)
						{
							printf("Error eliminando compras con ID de usuario.\n");
							break;
						}

						retorno = 0;
						break;
					case 'N':
					case 'n':
						break;
					}
				}
			}
		}else {
			printf("No se encontro el ID ingresado.\n");
		}




	if(pArray != NULL && limite > 0 && indice >= 0) {
		if(getCaracterSNCliente(&bufferChar,LEN_CHAR,
				"Estas seguro que desea borrar este cliente y todas sus compras?[S/N]:","\nError,solo puedes ingresar S o N \n",QTY_REINTENTOS) == 0)
		{
			switch(bufferChar) {
			case 'S':
			case 's':
				pArray[indice].isEmpty = VACIO;
				retorno = 0;
				break;
			case 'N':
			case 'n':
				break;
			}
		}
	}
	return retorno;
}















/**
 * \brief Imprime um array de flotantes
 * \param pArray puntero del array
 * \param logitud define el tamano del array
 * \param valorInicial es el valor a ser cargado en todas las posiciones del array
 * \return return retorna 0(exito) y -1(Error)
*/

int inicializarArrayFloat(float* pArray,int longitud,int valorInicial)
{
	int i;
    int respuesta = -1;
    if(pArray != NULL && longitud > 0)
    {
    	respuesta = 0;
    	for(i=0;i<longitud;i++)
    	{
    		pArray[i] = valorInicial;
    	}
    }
    return respuesta;
}

/**
 * \brief Imprime um array de flotantes
 * \param pArray puntero del array
 * \param logitud define el tamano del array
 * \return return retorna 0(exito) y -1(Error)
*/
int imprimirArrayFloat(float* pArray,int longitud)
{
	int i;
    int respuesta = -1;
    if(pArray != NULL && longitud > 0)
    {
    	respuesta = 0;
    	for(i=0;i<longitud;i++)
    	{
    		printf("\nIndice: [%d] - Valor: %.2f",i,pArray[i]);
    	}
    }
    return respuesta;
}


/*
int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
*/
