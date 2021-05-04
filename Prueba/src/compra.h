/*
 * compra.h
 *
 *  Created on: May 4, 2021
 *      Author: jessi
 */

#ifndef COMPRA_H_
#define COMPRA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compra.h"
#include "cliente.h"

#define LEN_ENTREGA 64
#define LEN_COLOR 32
#define MAX_COMPRAS 10 //1000


typedef struct
{
	int idCliente;
	int idVenta;
	int cantidadBarbijos;
	char direccionEntrega[LEN_ENTREGA];
	char color[LEN_COLOR];
	char estado[LEN_COLOR];
	int isEmpty;
}Compra;


int inicializarArrayCompra(Compra* pArray,int limite);

int realizarCompra(Compra* pArray, Cliente* pArrayCliente,int limite);

int findIdClienteEnCompra(Compra* pArray,int limite, int id);

int findEliminarIdClienteEnCompra(Compra* pArray,int limite, int id);

#endif /* COMPRA_H_ */
