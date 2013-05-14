/* 
 * File:   inicializacoes.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "estDados.h"
#include "focos.h"
#include "globais.h"
#include "inicializacoes.h"
#include "modelos.h"
#include "propsMateriais.h"
#include "rendering.h"
#include "viewing3D.h"

/* ----------------------------------------------------------------------- */

/* Inicializa o OpenGL*/
void inicializarEstado(void) {

	/* Permitir remover faces ocultas */
	/* BACK-FACE CULLING + DEPTH TEST */
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	/* Definir a cor do fundo */
	glClearColor(0.0, 0.0, 0.0, 1.0); /* Preto */

	/* Inicializacao da matriz de transformacao / modelacao */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* O intervalo de tempo entre frames para as animacoes */
	intervaloDeTempo = 40; /* 40 mseg -> 25 fps */
}

/* Inicializa o OpenGL*/
void inicializarEstado2(void) {

	/* Permitir remover faces ocultas */
	/* BACK-FACE CULLING + DEPTH TEST */
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	/* Definir a cor do fundo */
	glClearColor(1.0, 1.0, 1.0, 1.0); /* branco */

	/* Inicializacao da matriz de transformacao / modelacao */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Cria a janela de saida */
void inicializarJanela(void) {

	/* Double-buffering + Depth-buffer */
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	/* Caracteristicas da janela de saida */
	inicializarViewing3D();

	/* Criar Janela */
	glutInitWindowSize(compJanela, alturaJanela);
	glutInitWindowPosition(X_INICIAL_JANELA, Y_INICIAL_JANELA);
	glutCreateWindow("Puzzle 3D");
}

/* Cria a janela de saida */
void inicializarJanela2(void) {

	/* Double-buffering + Depth-buffer */
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	/* Caracteristicas da janela de saida */
	//inicializarViewing3D();

	/* Criar Janela */
	glutInitWindowSize(650, 100);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Informacoes");
}

/* Inicializa o foco */
void inicializarFocos(void) {

	/* Permitir a utilizacao de iluminacao */
	glEnable(GL_LIGHTING);

	/* Criar todos os focos necess?rios */
	pFoco = criaFocoZERO();

	/* Associar a representacao simplificada como "lista de desenho" */
	criaListaDeDesenhoParaFoco(pFoco);
}

/* Desenha o conteudo da janela 2 */
void inicializarConteudo2() {


}

/* Inicializa as pecas do puzzle (le do ficheiro e cria-as em openGL compilando-as em listas) */
void inicializarModelos(void) {
	tmpShuffle = 0;

	/* Estabelece os materiais qu3e se podem usar --- Fazer aqui ?? */
	criaMateriais();
	inicializarListaMateriais();

	if (lePecasDoNivel(NivelActual) == 0) {

		printf("Pecas Lidas Ficheiro\n");

		if ((totalPecas = TodasPecas->numPecas) > 0) {

			pecaSelec = 0;

			Visualizador = criaPessoa();

			/* Cria todas as pecas do puzzle atraves das configura??es lidas do ficheiro */
			constroiPecasPuzzle();

			/* Liberta todo o espa?o das pe?as lidas do ficheiro */
			free(TodasPecas);
			TodasPecas = NULL;

			/* Controi Listas de Desenho para cada peca do puzzle */
			controiListaDeDesenhoPecasPuzzle();
		} else exit(0);

	} else {
		exit(1);
	}
}