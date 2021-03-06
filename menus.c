/* 
 * File:   menus.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:14 PM
 */

#include <stdlib.h>
#include <GL/glut.h>

#include "callbacks.h"
#include "consoleIO.h"
#include "globais.h"
#include "menus.h"
#include "propsMateriais.h"
#include "viewing3D.h"


/* ----------------------------------------------------------------------- */

/* Definicao dos menus e sub-menus usando um tipo auxiliar e arrays */
typedef struct menuItemStruct {
	char* item; /* O texto do item */
	char val; /* O valor retornado */
} menuItemStruct;

/* Menu 1 - Botao Esquerdo */
/*
static menuItemStruct menu1[] = {

};
*/

/* Numero de itens no menu */
//int numItensMenu1 = sizeof ( menu1) / sizeof ( menuItemStruct);

/* Menu 2 - Botao Direito */
static menuItemStruct menu2[] = {
	
	"Proj. Perspectiva", 'P',
	"Proj. Ortogonal",	 'O',
	"-----------------", '-',
	"Recomecar", 'R',
	"Sair", 'S'
};

int numItensMenu2 = sizeof ( menu2) / sizeof ( menuItemStruct);

/* ----------------------------------------------------------------------- */
/* Callback function para o MENU 2 - Botao Direito */
/*
static void myMenuEsq(int i) {

	switch (menu1[i].val) {
	}

	glutPostRedisplay();
}
*/

/* Callback function para o MENU 2 - Botao Direito */
static void myMenuDir(int i) {
	int j;
	switch (menu2[i].val) {

		case 'O':

			tipoProjeccao = 'O';
			zPerto = ZNEARORTH;
			zLonge = ZFARORTH;
			
			toogleZModelProjType(tipoProjeccao);
        
			/* Estabelecer a projeccao */
			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
			glOrtho( xInf, xSup, yInf, ySup, zPerto, zLonge ); 
			glViewport( 0, 0, compJanela, alturaJanela );
			glutPostRedisplay();
			glMatrixMode( GL_MODELVIEW );

			/* Mostrar as caracteristicas do Volume de Visualizacao */
			infosProjeccao();

			break;

		case 'P':

			tipoProjeccao = 'P';

			/* Nova posicao para os planos, anterior e posterior, de clipping */
			zPerto = ZNEARPERS;
			zLonge = ZFARPERS;

			toogleZModelProjType(tipoProjeccao);

			/* Estabelecer a projeccao */
			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
			gluPerspective(90.0, compJanela/alturaJanela, zPerto, zLonge);
			glViewport( 0, 0, compJanela, alturaJanela );
			glutPostRedisplay();
			glMatrixMode( GL_MODELVIEW );

			/* Mostrar as caracteristicas do Volume de Visualizacao */
			infosProjeccao();

			break;

		case 'R':

			for (j = 0; j < totalPecas; j++) {
				
				PecasPuzzle[j]->material = listaMateriais[j];
				
				PecasPuzzle[j]->translacao[0] = PecasPuzzle[j]->translacaoOriginal[0];
				PecasPuzzle[j]->translacao[1] = PecasPuzzle[j]->translacaoOriginal[1];
				PecasPuzzle[j]->translacao[2] = PecasPuzzle[j]->translacaoOriginal[2];
				
				PecasPuzzle[j]->rotacaoOnXX = 0;
				PecasPuzzle[j]->rotacaoOnYY = 0;
				PecasPuzzle[j]->rotacaoOnZZ = 0;

				PecasPuzzle[j]->angulo[0] = 0;
				PecasPuzzle[j]->angulo[1] = 0;
				PecasPuzzle[j]->angulo[2] = 0;
			}
			
			toogleZModelProjType(tipoProjeccao);
			
			Visualizador->valorX = 0;
			Visualizador->valorY = 0;
			
			PecasPuzzle[0]->material = pMaterialPlasticoVermelho;
                        pecaSelec=0;
                        ActualizaMaterial();
			
			tipoProjeccao = 'O';
			zPerto = ZNEARORTH;
			zLonge = ZFARORTH;
        
			/* Estabelecer a projeccao */
			glMatrixMode( GL_PROJECTION );
			glLoadIdentity();
			glOrtho( xInf, xSup, yInf, ySup, zPerto, zLonge );
			gluLookAt(Visualizador->valorX * Visualizador->rotacaoEmX, Visualizador->valorY * Visualizador->rotacaoEmY, Visualizador->rotacaoEmX, 0, 0, 0, 0, 1.0, 0);
			glViewport( 0, 0, compJanela, alturaJanela );
			glutPostRedisplay();
			glMatrixMode( GL_MODELVIEW );
			gluLookAt(Visualizador->valorX * Visualizador->rotacaoEmX, Visualizador->valorY * Visualizador->rotacaoEmY, Visualizador->rotacaoEmX, 0, 0, 0, 0, 1.0, 0);
			glutPostRedisplay();
			break;

		case 'S':
			exit(0);
			break;
	}
}

/* Funcao que cria as listas dos menus, associa-as ao clique e associa as fun??es que tratam os cliques */
void criarMenus(void) {

	int i;
	
	// Como este menu nao esta a ser utilizador nao e criado por enquanto

	/* Associa a funcao que trata das opcoes do menu esquerdo ao clique */
/*
	glutCreateMenu(myMenuEsq);

	for (i = 0; i < numItensMenu1; i++) {
		glutAddMenuEntry(menu1[i].item, i);
	}
*/
	/* Associa o menu criado em cima ao botao esquerdo do rato */
	//glutAttachMenu(GLUT_LEFT_BUTTON);


	/* Associa a funcao que trata das opcoes do menu esquerdo ao clique */
	glutCreateMenu(myMenuDir);

	for (i = 0; i < numItensMenu2; i++) {
		glutAddMenuEntry(menu2[i].item, i);
	}

	/* Associa o menu criado em cima ao botao direito do rato */
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}