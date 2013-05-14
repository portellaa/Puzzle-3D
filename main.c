

/* ----------------------------------------------------------------------- */

#include <stdio.h>
#include <GL/glut.h>

#include "modelos.h"

/* ----------------------------------------------------------------------- */


int main(int argc, char** argv) {
	
        NivelActual=4;
    
	/* Inicializacao do GLUT */
	glutInit(&argc, argv);

	/* Infos para o utilizador */
	infosIniciais();

	/* Inicializacoes */
	inicializarJanela();
	inicializarEstado();
	criarMenus();

	inicializarFocos();

	inicializarModelos();

	/* Registando "callback functions" */
	registarCallbackFunctions();

        /* Inicializar Segunda janela */
        //inicializarJanela2();
        //inicializarEstado2();
        //registarCallbackFunctions2();
        
	/* Esperando eventos */
	glutMainLoop();

	return 0;
}
