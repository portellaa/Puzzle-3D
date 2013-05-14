/* 
 * File:   callbacks.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>

#include "callbacks.h"
#include "consoleIO.h"
#include "globais.h"
#include "modelos.h"
#include "rendering.h"
#include "viewing3D.h"

static int font_index;

/* ----------------------------------------------------------------------- */

/* Fun??o para alterar o material da pe?a quando esta ? selecionada*/
void ActualizaMaterial() {
    //TODO: Falha se passarmos o limite do vector de materiais,
    int i;
    for (i = 0; i < totalPecas; i++) {
        if (i == pecaSelec) {
            associaMaterialModelo(pMaterialPlasticoVermelho, PecasPuzzle[i]);
        } else {
            associaMaterialModelo(listaMateriais[i], PecasPuzzle[i]);
        }
    }
}

/* Funcao que responsavel por chamar as funcoes para contruir o puzzle */
void myDisplay(void) {

    /* Atencao: agora tb. se "limpa" o DEPTH-BUFFER */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Construir a cena */
    constroiCenaUsandoListasDeDesenho();

    /* Forcar o rendering: agora usa-se DOUBLE_BUFFERING */
    glutSwapBuffers();
}

void print_bitmap_string(void* font, char* s) {
    if (s && strlen(s)) {
        while (*s) {
            glutBitmapCharacter(font, *s);
            s++;
        }
    }
}

void
draw_stuff() {
    char string[4][100];
    unsigned int i, j;
    unsigned int count;
    void* bitmap_fonts[7] = {
        GLUT_BITMAP_9_BY_15,
        GLUT_BITMAP_8_BY_13,
        GLUT_BITMAP_TIMES_ROMAN_10,
        GLUT_BITMAP_TIMES_ROMAN_24,
        GLUT_BITMAP_HELVETICA_10,
        GLUT_BITMAP_HELVETICA_12,
        GLUT_BITMAP_HELVETICA_18
    };

    char* bitmap_font_names[7] = {
        "GLUT_BITMAP_9_BY_15",
        "GLUT_BITMAP_8_BY_13",
        "GLUT_BITMAP_TIMES_ROMAN_10",
        "GLUT_BITMAP_TIMES_ROMAN_24",
        "GLUT_BITMAP_HELVETICA_10",
        "GLUT_BITMAP_HELVETICA_12",
        "GLUT_BITMAP_HELVETICA_18"
    };

    void* stroke_fonts[2] = {
        GLUT_STROKE_ROMAN,
        GLUT_STROKE_MONO_ROMAN
    };

    void* stroke_font_names[2] = {
        "GLUT_STROKE_ROMAN",
        "GLUT_STROKE_MONO_ROMAN"
    };

    GLfloat x, y, ystep, yild, stroke_scale;

    /* Set up some strings with the characters to draw. */
    count = 0;
    char txt1[100] = "Trabalho de: Rui Martins e Luis Portela.";
    for (i = 0; i < 100; i++) { /* Skip zero - it's the null terminator! */
        string[0][count] = txt1[i];
        count++;
    }
    string[0][count] = '\0';

    count = 0;
    char txt2[100] = "[W] [S] [D] [A] [Q] [E] - Rotacoes X, Y, Z";
    for (i = 0; i < 100; i++) {
        string[1][count] = txt2[i];
        count++;
    }
    string[1][count] = '\0';

    count = 0;
    char txt3[100] = "[CIMA] [BAIXO] [ESQUERDA] [DIREITA] [HOME] [END] - Translacoes X, Y, Z";
    for (i = 0; i < 100; i++) {
        string[2][count] = txt3[i];
        count++;
    }
    string[2][count] = '\0';

    count = 0;
    char txt4[100] = "[N] [M]  - Selecciona a Peca";
    for (i = 0; i < 100; i++) {
        string[3][count] = txt4[i];
        count++;
    }
    string[3][count] = '\0';




    /* Draw the strings, according to the current mode and font. */
    glColor4f(0.0, 1.0, 0.0, 0.0);
    x = -320.0;
    y = 30.0; //70
    ystep = 100.0;
    yild = 20.0;

    glRasterPos2f(-150, y + 1.25 * yild); //-150
    //print_bitmap_string(
    //   bitmap_fonts[font_index], bitmap_font_names[font_index]);
    for (j = 0; j < 4; j++) {
        glRasterPos2f(x, y);
        print_bitmap_string(bitmap_fonts[font_index], string[j]);
        y -= yild;
    }


}

/* Funcao que responsavel por chamar as funcoes para contruir o puzzle */
void myDisplay2(void) {

    /* Atencao: agora tb. se "limpa" o DEPTH-BUFFER */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ////////////////

    /* Clear the window. */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    draw_stuff();

    glutSwapBuffers();

    /* Forcar o rendering: agora usa-se DOUBLE_BUFFERING */
    glutSwapBuffers();


}

/* Funcao que ? chamada quando uma tecla ? premida */
void myKeyboard(unsigned char key, int x, int y) {
    //printf("Premida Tecla %d\n", key);

	switch (key) {
		case 'j':
		case 'J':
		{
			// Movimento negativo em Y
			glLoadIdentity();
			Visualizador->valorX += 0.1;
			gluLookAt(Visualizador->valorX * Visualizador->rotacaoEmX, Visualizador->valorY * Visualizador->rotacaoEmY, Visualizador->rotacaoEmX, 0, 0, 0, 0, 1.0, 0);
			glutPostRedisplay();
			break;
		}
		case 'l':
		case 'L':
		{
			// Movimento positivo em Y
			glLoadIdentity();
			Visualizador->valorX -= 0.1;
			gluLookAt(Visualizador->valorX * Visualizador->rotacaoEmX, Visualizador->valorY * Visualizador->rotacaoEmY, Visualizador->rotacaoEmX, 0, 0, 0, 0, 1.0, 0);
			glutPostRedisplay();
			break;
		}
		case 'i':
		case 'I':
		{
			// Movimento positivo em X
			glLoadIdentity();
			Visualizador->valorY -= 0.1;
			gluLookAt(Visualizador->valorX * Visualizador->rotacaoEmX, Visualizador->valorY * Visualizador->rotacaoEmY, Visualizador->rotacaoEmX, 0, 0, 0, 0, 1.0, 0);
			glutPostRedisplay();
			break;
		}
		case 'k':
		case 'K':
		{
			// Movimento negativo em X
			glLoadIdentity();
			Visualizador->valorY += 0.1;
			gluLookAt(Visualizador->valorX * Visualizador->rotacaoEmY, Visualizador->valorY * Visualizador->rotacaoEmY, Visualizador->rotacaoEmX, 0, 0, 0, 0, 1.0, 0);
			glutPostRedisplay();
			break;
		}
	}




    printf("\n[myKeyboard]: VALOR X: %f, VALOR Y: %f", Visualizador->valorX, Visualizador->valorY);

    //TODO: Trocar isto tudo para um Select Case

    /* Usar as teclas X ou ESC para terminar o programa */
    if ((key == 'X') || (key == 'x') || (key == 27)) {
        exit(0);
    }

    if ((key == 'n') || (key == 'n')) {
        printf("Peca Seleccionada muda de %d ", pecaSelec);
        pecaSelec = pecaSelec > 0 ? --pecaSelec : totalPecas - 1;
        printf("para %d\n", pecaSelec);
        ActualizaMaterial();
        //pecaSelec>0 ? --pecaSelec : pecasSelec = totalPecas-1
    }

    if ((key == 'm') || (key == 'M')) {
        printf("Peca Seleccionada muda de %d ", pecaSelec);
        pecaSelec = pecaSelec >= totalPecas - 1 ? 0 : ++pecaSelec;
        printf("para %d\n", pecaSelec);
        ActualizaMaterial();
    }

    ////////////////////////////////////////////////////////////////////////////////
    /////////////////// ROTA??O
    ////////////////////////////////////////////////////////////////////////////////

    if (((key == 'w') || (key == 'W')) && tmpRedisplayRXX == 0) {
        printf("XX");
        tmpRedisplayRXX = 90;
        actualizaParametroModeloSelect(ROTACAO, XX);
    }

    if (((key == 's') || (key == 'S')) && tmpRedisplayRXX == 0) {
        printf("Xx");
        tmpRedisplayRXX = -90;
        actualizaParametroModeloSelect(ROTACAO, Xx);
    }

    if (((key == 'a') || (key == 'A')) && tmpRedisplayRYY == 0) {
        printf("YY");
        tmpRedisplayRYY = 90;
        actualizaParametroModeloSelect(ROTACAO, YY);
    }

    if (((key == 'd') || (key == 'D')) && tmpRedisplayRYY == 0) {
        printf("Yy");
        tmpRedisplayRYY = -90;
        actualizaParametroModeloSelect(ROTACAO, Yy);
    }

    if (((key == 'q') || (key == 'Q')) && tmpRedisplayRZZ == 0) {
        printf("ZZ");
        tmpRedisplayRZZ = 90;
        actualizaParametroModeloSelect(ROTACAO, ZZ);
    }

    if (((key == 'e') || (key == 'E')) && tmpRedisplayRZZ == 0) {
        printf("Zz");
        tmpRedisplayRZZ = -90;
        actualizaParametroModeloSelect(ROTACAO, Zz);
    }

    if (((key == 'r') || (key == 'R')) && tmpRedisplayRZZ == 0) {
        tmpShuffle = 200; /* Numero de movimentos aleat?rios */
    }

    glutPostRedisplay();
}

/* Fun??o que ? chamada quando as teclas de deslocamento s?o premidas */
void mySpecialKeys(int key, int x, int y) {

    ////////////////////////////////////////////////////////////////////////////////
    /////////////////// TRANSLA??O
    ////////////////////////////////////////////////////////////////////////////////
    switch (key) {
        case GLUT_KEY_RIGHT:
            if (tmpRedisplayTXX == 0) {
                printf("XX Transla??o\n");
                tmpRedisplayTXX = CUBO_SIZE;
                actualizaParametroModeloSelect(TRANSLACAO, XX);
            }
            break;
        case GLUT_KEY_LEFT:

            if (tmpRedisplayTXX == 0) {
                printf("Xx Transla??o\n");
                tmpRedisplayTXX = -CUBO_SIZE;
                actualizaParametroModeloSelect(TRANSLACAO, Xx);
            }
            break;
        case GLUT_KEY_UP:

            if (tmpRedisplayTYY == 0) {
                printf("YY Transla??o\n");
                tmpRedisplayTYY = CUBO_SIZE;
                actualizaParametroModeloSelect(TRANSLACAO, YY);
            }

            break;
        case GLUT_KEY_DOWN:

            if (tmpRedisplayTYY == 0) {
                printf("Yy Transla??o\n");
                tmpRedisplayTYY = -CUBO_SIZE;
                actualizaParametroModeloSelect(TRANSLACAO, Yy);
            }

            break;


        case GLUT_KEY_END:
            if (tmpRedisplayTZZ == 0) {
                printf("ZZ Transla??o\n");
                tmpRedisplayTZZ = CUBO_SIZE;
                actualizaParametroModeloSelect(TRANSLACAO, ZZ);
            }
            break;
        case GLUT_KEY_HOME:
            if (tmpRedisplayTZZ == 0) {
                printf("Yz Transla??o\n");
                tmpRedisplayTZZ = -CUBO_SIZE;
                actualizaParametroModeloSelect(TRANSLACAO, Zz);
            }
            break;
    }

    glutPostRedisplay();
}

/* Fun??o que ? chamada quando a janela ? redimensionada */
void myReshape(int comp, int altura) {

    /* Actualizar as variaveis globais com novas as dimensoes da janela */
    compJanela = comp;
    alturaJanela = altura;

    /* Definir a nova transformacao janela / viewport,
       actualizando as dimensoes da janela */
    transfJanelaViewport();
}

/* Fun??o que ? chamada quando a janela ? redimensionada */
void myReshape2(int w, int h) {
    GLdouble size;
    GLdouble aspect;

    /* Use the whole window. */
    glViewport(0, 0, w, h);

    /* We are going to do some 2-D orthographic drawing. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    size = (GLdouble) ((w >= h) ? w : h) / 2.0;
    if (w <= h) {
        aspect = (GLdouble) h / (GLdouble) w;
        glOrtho(-size, size, -size*aspect, size*aspect, -100000.0, 100000.0);
    } else {
        aspect = (GLdouble) w / (GLdouble) h;
        glOrtho(-size*aspect, size*aspect, -size, size, -100000.0, 100000.0);
    }

    /* Make the world and window coordinates coincide so that 1.0 in */
    /* model space equals one pixel in window space.                 */
    glScaled(aspect, aspect, 1.0);

    /* Now determine where to draw things. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

/* Fun??o que ? chamada pelo timer */

void myTimer(int flag) {

    if (actualizaParametrosModelos()) {
        /*
                        if (Visualizador->rotacaoEmY) {
                                glLoadIdentity();
                                gluLookAt(-(Visualizador->valorY),0,1, 0,0,0, 0,1,0);
                        }
         */
        glutPostRedisplay();
    }

    if (tmpRedisplayRXX > 0) {
        actualizaParametroModeloSelect(ROTACAO, XX);
        glutPostRedisplay();
    }
    if (tmpRedisplayRXX < 0) {
        actualizaParametroModeloSelect(ROTACAO, Xx);
        glutPostRedisplay();
    }

    if (tmpRedisplayRYY > 0) {
        actualizaParametroModeloSelect(ROTACAO, YY);
        glutPostRedisplay();
    }
    if (tmpRedisplayRYY < 0) {
        actualizaParametroModeloSelect(ROTACAO, Yy);
        glutPostRedisplay();
    }

    if (tmpRedisplayRZZ > 0) {
        actualizaParametroModeloSelect(ROTACAO, ZZ);
        glutPostRedisplay();
    }
    if (tmpRedisplayRZZ < 0) {
        actualizaParametroModeloSelect(ROTACAO, Zz);
        glutPostRedisplay();
    }

    if (tmpRedisplayTXX > 0) {
        actualizaParametroModeloSelect(TRANSLACAO, XX);
        glutPostRedisplay();
    }
    if (tmpRedisplayTXX < 0) {
        actualizaParametroModeloSelect(TRANSLACAO, Xx);
        glutPostRedisplay();
    }
    if (tmpRedisplayTYY > 0) {
        actualizaParametroModeloSelect(TRANSLACAO, YY);
        glutPostRedisplay();
    }
    if (tmpRedisplayTYY < 0) {
        actualizaParametroModeloSelect(TRANSLACAO, Yy);
        glutPostRedisplay();
    }
    if (tmpRedisplayTZZ > 0) {
        actualizaParametroModeloSelect(TRANSLACAO, ZZ);
        glutPostRedisplay();
    }
    if (tmpRedisplayTZZ < 0) {
        actualizaParametroModeloSelect(TRANSLACAO, Zz);
        glutPostRedisplay();
    }

    if (tmpShuffle > 0 && tmpRedisplayRXX == 0 && tmpRedisplayRYY == 0 && tmpRedisplayRZZ == 0 &&
            tmpRedisplayTXX == 0 && tmpRedisplayTYY == 0 && tmpRedisplayTZZ == 0) {
        shuffle();
        tmpShuffle--;
    }

    glutTimerFunc(intervaloDeTempo, myTimer, 0);
}

/* Fun??o para testar a visibilidade da janela */
void myVisibility(int state) {

    if (state == GLUT_VISIBLE) {
        /* Actualizar ... */
        glutTimerFunc(intervaloDeTempo, myTimer, 0);
    }
}

void myVisibility2(int state) {

    if (state == GLUT_VISIBLE) {
        /* Actualizar ... */
        glutTimerFunc(intervaloDeTempo, myTimer, 0);
    }
}

/* Fun??o para inicializar todos os elementos necess?rios para o openGL */
void registarCallbackFunctions(void) {

    glutDisplayFunc(myDisplay);

    glutKeyboardFunc(myKeyboard);

    glutReshapeFunc(myReshape);

    /* Usar teclas "especiais", p.ex., do cursor */
    glutSpecialFunc(mySpecialKeys);

    /* Teste de visibilidade da janela */
    glutVisibilityFunc(myVisibility);

    /* Utilizacao do temporizador */
    glutTimerFunc(intervaloDeTempo, myTimer, 0);
}

/* Fun??o para inicializar todos os elementos necess?rios para o openGL */
void registarCallbackFunctions2(void) {

    glutDisplayFunc(myDisplay2);

    //glutKeyboardFunc(myKeyboard);

    glutReshapeFunc(myReshape2);

    /* Usar teclas "especiais", p.ex., do cursor */
    //glutSpecialFunc(mySpecialKeys);

    /* Teste de visibilidade da janela */
    glutVisibilityFunc(myVisibility2);

    /* Utilizacao do temporizador */
    //    glutTimerFunc(intervaloDeTempo, myTimer, 0);
}