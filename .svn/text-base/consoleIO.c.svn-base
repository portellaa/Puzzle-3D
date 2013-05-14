/* 
 * File:   consoleIO.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:11 PM
 */

#include <stdio.h>

#include "consoleIO.h"
#include "inicializacoes.h"
#include "viewing3D.h"


/* ----------------------------------------------------------------------- */

/* Escreve informações adicionais na consola */
void infosIniciais(void) {
	
	printf("\t\t _______________________________________________________________________\n");
	printf("\t\t|\t\t\t\t\t\t\t\t\t|\n");
	printf("\t\t|\t\t\t\tPuzzle 3D\t\t\t\t|\n");
	printf("\t\t|_______________________________________________________________________|\n");
	printf("\t\t|\tDesenvolvido por:\t\t\t\t\t\t|\n");
	printf("\t\t|\t\tLuis Carlos Portela Afonso - 36160\t\t\t|\n");
	printf("\t\t|\t\tRui Filipe Sousa Martins - 38282\t\t\t|\n");
	printf("\t\t|-----------------------------------------------------------------------|\n");
	printf("\t\t|Utilizacao das teclas:\t\t\t\t\t\t\t|\n");
	printf("\t\t|\tN ou M : Alternar entre a peca selecionada\t\t\t|\n");
	printf("\t\t|\tTeclas de deslocamento : Mexem a peca no plaxo XOY\t\t|\n");
	printf("\t\t|\tW ou S : Rodam a peca selecionada no plano X\t\t\t|\n");
	printf("\t\t|\tA ou D : Rodam a peca selecionada no plano Y\t\t\t|\n");
	printf("\t\t|\tQ ou E : Rodam a peca selecionada no plano Z\t\t\t|\n");
        printf("\t\t|\tCIMA ou BAIXO : Deslocam a peca selecionada no plano Y\t\t\t|\n");
        printf("\t\t|\tESQUERDA ou DIREITA : Deslocam a peca selecionada no plano X\t\t\t|\n");
        printf("\t\t|\tHOME ou END : Deslocam a peca selecionada no plano Z\t\t\t|\n");
	printf("\t\t|-----------------------------------------------------------------------|\n");
	printf("\t\t|\t\t Para Terminar:\tusar as teclas X ou ESC\t\t\t|\n");
	printf("\t\t|_______________________________________________________________________|\n");
}

/* Imprime informações sobre a projecção na consola */
void infosProjeccao(void) {
	switch (tipoProjeccao) {

		case 'O':

			printf("\n Projeccao Paralela Ortogonal\n\n");

			break;

		case 'P':

			printf("\n Projeccao Perspectiva\n\n");

			break;

	}

	printf("\n Volume de Visualizacao definido por:\n\n");
	printf("\t\txInf = %f xSup = %f\n\n", xInf, xSup);
	printf("\t\tyInf = %f ySup = %f\n\n", yInf, ySup);
	printf("\t\tzPerto = %f zLonge = %f\n\n", zPerto, zLonge);
}