/* 
 * File:   focos.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:13 PM
 */

#include <stdlib.h>

#include "focos.h"
#include "globais.h"

/* ----------------------------------------------------------------------- */

/* Funcao para inicializar o Foco */
pontFoco criaFocoZERO(void) {

	/* Ponteiro para o registo do foco criado */
	pontFoco pFoco = (Registo_Foco*) malloc(sizeof ( Registo_Foco));

	/* Foco Pontual e Ligado */
	pFoco->focoPontual = 1;
	pFoco->focoIsOn = 1;

	/* Propriedades da luz emitida --- RGBA */
	/* Ambiente --- White */
	pFoco->compAmbiente[0] = 1.0;
	pFoco->compAmbiente[1] = 1.0;
	pFoco->compAmbiente[2] = 1.0;
	pFoco->compAmbiente[3] = 1.0;

	/* Difusa --- White */
	pFoco->compDifusa[0] = 1.0;
	pFoco->compDifusa[1] = 1.0;
	pFoco->compDifusa[2] = 1.0;
	pFoco->compDifusa[3] = 1.0;

	/* Especular --- White */
	pFoco->compEspecular[0] = 1.0;
	pFoco->compEspecular[1] = 1.0;
	pFoco->compEspecular[2] = 1.0;
	pFoco->compEspecular[3] = 1.0;

	/* A posicao do Foco na ORIGEM --- Coord. Homogeneas */
	pFoco->posicao[0] = 0.0;
	pFoco->posicao[1] = 0.0;
	pFoco->posicao[2] = 0.0;
	pFoco->posicao[3] = 1.0; /* Distancia finita */

	/* Parametros globais de transformacao */
	pFoco->translX = 0.0;
	pFoco->translY = 0.0;
	pFoco->translZ = 20.0;
	
	pFoco->angRotXX = 0;
	pFoco->angRotYY = 0;
	pFoco->angRotZZ = 0;

	/* Controlos da animacao */
	pFoco->rotacaoOnXX = 0;
	pFoco->rotacaoOnYY = 0;
	pFoco->rotacaoOnZZ = 0;

	/* Devolver o ponteiro para o registo criado */
	return pFoco;
}