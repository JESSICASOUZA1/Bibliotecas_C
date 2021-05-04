/*
 ============================================================================
 Name        : ExerciciosFaceis.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

int main(void)
{

	Persona Persona[MAX_PERSONAS];

	int opcion;
	//int resultadoInicializar = 0;

	initializeArrayPersonas(Persona,MAX_PERSONAS);


	if(utn_getNumero(&opcion,"Ingrese opcion\n1-Altas\n2-Bajas\n3-Modificaciones\n","Error,opcion invalida",1,3,5)==-1)
	{
		printf("Se acabo los reintentos");
	}

	switch (opcion){
	case 1:



		break;

	case 2:
		break;

	case 3:
		break;
	}





	return EXIT_SUCCESS;
}
