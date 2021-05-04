/*
 ============================================================================
 Name        : Prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "compra.h"



int main(void)
{
	setbuf(stdout, NULL); //windows

	int opcion;
	//int contadorID = 0;
	Cliente arrayCliente[MAX_CLIENTES];
	Compra arrayCompras[MAX_COMPRAS];


	inicializarArrayCliente(arrayCliente,MAX_CLIENTES);
	inicializarArrayCompra(arrayCompras,MAX_COMPRAS);

	do
	{

	if(getNumeroCliente(&opcion,"Ingrese numero de opcion\n"
			"\n1-Alta de cliente\n"
			"2-Modificar datos de clientes\n"
			"3-Baja de cliente\n"
			"4-realizar compra\n"
			"5-Pagar compra\n"
			"6-Cancelar compra\n"
			"7-Imprimir clientes\n"
			"8-Informar\n"
			"9-Salir\n","Error,opcion invalida\n",1,9,5) == -1)
	{
		printf("\nError, se te acabaron los intentos\n");
		system("pause");

	}

	switch(opcion)
	{
	case 1:

		if(altaArrayCliente(arrayCliente,MAX_CLIENTES) == -1)
		{
			printf("\nError dando de alta a cliente\n");
		}
		system("pause");


	    break;

	case 2:

		if(modificarDatosCliente(arrayCliente,MAX_CLIENTES) == -1)
				{
					printf("\nError modificando al cliente\n");
				}
				system("pause");
		break;

	case 3:


		break;

	case 4:

		if(realizarCompra(arrayCompras,arrayCliente,MAX_COMPRAS) == -1)
				{
					printf("\nError realizando compra\n");
				}
				system("pause");
		break;

	case 5:
		break;

	case 6:
		break;

	case 7:
		break;

	case 8:
		break;

	}

	}while(opcion != 9);


	return EXIT_SUCCESS;
}
