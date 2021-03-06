/* 
 * File:   viewing3D.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:19 PM
 */

#include <GL/glut.h>

#include "consoleIO.h"
#include "viewing3D.h"
#include "globais.h"

/* ----------------------------------------------------------------------- */

/* Inicializacao das variaveis globais */
void inicializarViewing3D(void) {

	/* Caracteristicas da JANELA de OUTPUT*/
	alturaJanela = 500;
	compJanela = 500;

	X_INICIAL_JANELA = 100;
	Y_INICIAL_JANELA = 100;

	/* Caracteristicas do Volume de Visualizacao */
	xInf = -3.0;
	xSup = 3.0;
	yInf = -3.0;
	ySup = 3.0;

	/* No inicio: projeccao paralela ortogonal */
	tipoProjeccao = 'O';

	/* E estabelce-se um volume de visualizacao alongado... */
	zPerto = ZNEARORTH;
	zLonge = ZFARORTH;

	/* Mostar as caracteristicas do Volume de Visualizacao */
	infosProjeccao();
}

/* Funcao que ? invocada quando a janela / viewport sofre uma transformacao */
void transfJanelaViewport(void) {

	float razaoDeAspecto;
	float centroX, centroY;
	float novaAlturaJanelaXOY, novoCompJanelaXOY;

	/* Nao fazer nada se a janela tiver sido minimizada */
	if ((alturaJanela < 1) || (compJanela < 1)) {
		return;
	}

	/* Estabelecer a janela */
	/* Usar as dimensoes da janela para determinar a RAZAO de ASPECTO */
	/* Ocupar a maior area possivel sem originar distorcoes */
	if (compJanela <= alturaJanela) {

		/* Ajustar a altura da janela no plano XOY */
		/* A razao de aspecto da janela de output */
		razaoDeAspecto = (float) alturaJanela / (float) compJanela;

		/* Para a janela no plano XOY */
		centroY = (float) (yInf + ySup) / 2.0;
		novaAlturaJanelaXOY = razaoDeAspecto * (xSup - xInf);

		/* Manter o centro da janela no plano */
		yInf = centroY - novaAlturaJanelaXOY / 2;
		ySup = centroY + novaAlturaJanelaXOY / 2;

	} else {

		/* Ajustar o comprimento da janela no plano XOY */
		/* A razao de aspecto da janela de output */
		razaoDeAspecto = (float) compJanela / (float) alturaJanela;

		/* Para a janela no plano XOY */
		centroX = (float) (xInf + xSup) / 2.0;
		novoCompJanelaXOY = razaoDeAspecto * (ySup - yInf);

		/* Manter o centro da janela no plano */
		xInf = centroX - novoCompJanelaXOY / 2;
		xSup = centroX + novoCompJanelaXOY / 2;
	}

	/* Estabelecer o Volume de Visualizacao */
	glMatrixMode(GL_PROJECTION);

	/* Carregar matriz identidade */
	glLoadIdentity();

	/* Alterar coordenada Z consoante o tipo de projeccao */
	toogleZModelProjType(tipoProjeccao);

	switch (tipoProjeccao) {

		case 'O':

			glOrtho(xInf, xSup, yInf, ySup, zPerto, zLonge);
			break;

		case 'P':

			gluPerspective(90.0, compJanela / alturaJanela, zPerto, zLonge);
			break;

	}
	/* Utilizada toda a janela de output */
	glViewport(0, 0, compJanela, alturaJanela);

	/* Voltar ao modo de transf. de modelacao */
	glMatrixMode(GL_MODELVIEW);
}

/* Actualiza a coordenada Z consoante o tipo de projec??o */
void toogleZModelProjType(char tipoProjecao) {

	int j;

	switch (tipoProjecao) {

		case 'P':
			for (j = 0; j < totalPecas; j++) {
				PecasPuzzle[j]->translacao[2] = (PecasPuzzle[j]->translacaoOriginal[2] - MINPERSPZ);
			}
			break;

		case 'O':
			for (j = 0; j < totalPecas; j++) {
				PecasPuzzle[j]->translacao[2] = 0;
			}
			break;
	}
}