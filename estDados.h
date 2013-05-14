/* 
 * File:   estDados.h
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 11:46 AM
 */


#ifndef _estDados_h
#define _estDados_h

#include <GL/glut.h>

#include "globais.h"


/* ----------------------------------------------------------------------- */

/* Funcao para criar um vertice com os pontos dados */
ponto3D criaVertice(GLfloat x, GLfloat y, GLfloat z);

/* Cria copia de um vertice com base noutro vertice */
ponto3D criaCopiaDeVertice(ponto3D vert);

/* Imprime o vertice na consola*/
void imprimeVertice(ponto3D vert);

/* Funcao para criar vector para normal */
vector3D criaVector(GLfloat x, GLfloat y, GLfloat z);

face criaFace( ponto3D p1, ponto3D p2, ponto3D p3, ponto3D p4 );

/* Devolve o vertice i da face q de um cubo */
ponto3D verticeFace(GLint i, GLint q, pontCubo p);

/* Aloca memoria para o array pecas  */
ArrayPecas criarArrayPecas(int numPecas);

/* Alocar Memoria para a peca bem como para os cubos */
Peca criarPeca(int numCubos);

/* Cria a peca do puzzle alocando memoria para esta com base na informacao de uma peca lida do ficheiro */
PecaPuzzle criarPecaPuzzle(Peca pecaOrig);

/* Aloca memoria para todas as pecas do puzzle que vao ser criadas a partir da informacao lida do ficheiro */
PecaPuzzle *criarArrayPecasPuzzle( int numPecas );

/* Funcao para alocar memoria para estrutura do tipo Pessoa */
Pessoa criaPessoa();
/* ----------------------------------------------------------------------- */

#endif