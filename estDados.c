/* 
 * File:   estDados.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:11 PM
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "globais.h"
#include "estDados.h"
#include "propsMateriais.h"


/* ----------------------------------------------------------------------- */

/* Funcao para criar um vertice com os pontos dados */
ponto3D criaVertice(GLfloat x, GLfloat y, GLfloat z) {
	
	ponto3D vertice = (ponto3D) calloc(3, sizeof ( GLfloat));

	vertice[0] = x;
	vertice[1] = y;
	vertice[2] = z;

	return vertice;
}

/* Cria copia de um vertice com base noutro vertice */
ponto3D criaCopiaDeVertice(ponto3D vert) {
	
	ponto3D vertice = (ponto3D) calloc(3, sizeof ( GLfloat));

	vertice[0] = vert[0];
	vertice[1] = vert[1];
	vertice[2] = vert[2];

	return vertice;
}

/* Imprime o vertice na consola*/
void imprimeVertice(ponto3D vert) {

	printf("Vertice : %f %f %f\n", vert[0], vert[1], vert[2]);
}

/* Funcao para criar vector para normal */
vector3D criaVector(GLfloat x, GLfloat y, GLfloat z) {

	vector3D vector = (vector3D) calloc(3, sizeof ( GLfloat));

	vector[0] = x;
	vector[1] = y;
	vector[2] = z;

	return vector;
}

/* Funcao para criar uma face de um cubo com base em pontos de vertices */
face criaFace(ponto3D p1, ponto3D p2, ponto3D p3, ponto3D p4) {

	face q = (face) calloc(4, sizeof ( ponto3D));

	q[0] = p1;
	q[1] = p2;
	q[2] = p3;
	q[3] = p4;

	return q;
}

/* Devolve o vertice i da face q de um cubo */
ponto3D verticeFace(GLint i, GLint q, pontCubo p) {
	return p->faces[q][i];
}

/* Aloca memoria para o array pecas  */
ArrayPecas criarArrayPecas(int numPecas) {

	ArrayPecas tmpArray = (ArrayPecas) malloc(sizeof (Estructura_ArrayPecas));

	tmpArray->numPecas = numPecas;
	tmpArray->listaPecas = (Peca*) calloc(numPecas, sizeof (Peca));

	return tmpArray;
}

/* Alocar Memoria para a peca bem como para os cubos */
Peca criarPeca(int numCubos) {

	Peca tmpPeca = (Peca) malloc(sizeof (Estructura_Peca));

	tmpPeca->numCubos = numCubos;
	tmpPeca->coordOutrosCubos = (ponto3D*) calloc(numCubos - 1, sizeof (ponto3D));

	return tmpPeca;
}

/* Cria a peca do puzzle alocando memoria para esta com base na informacao de uma peca lida do ficheiro */
PecaPuzzle criarPecaPuzzle(Peca pecaOrig) {

	PecaPuzzle tmpPeca = (PecaPuzzle) malloc(sizeof (Estructura_PecaPuzzle));

	tmpPeca->numCubos = pecaOrig->numCubos;
	tmpPeca->listaCubos = (pontCubo*) calloc(tmpPeca->numCubos, sizeof (pontCubo));
	tmpPeca->tamanho = (ponto3D) calloc(3, sizeof ( GLfloat));

	associaMaterialModelo(materialSelec, tmpPeca);

	/* Parametros globais de transformacao */
	/* Transla??o da peca */
	tmpPeca->translacao = (double*) calloc(3, sizeof (double));
	tmpPeca->translacaoOriginal = (double*) calloc(3, sizeof (double));
	tmpPeca->translacao[0] = 0.0;
	tmpPeca->translacao[1] = 0.0;
	tmpPeca->translacao[2] = 0.0;
	tmpPeca->translacaoOriginal[0] = 0.0;
	tmpPeca->translacaoOriginal[1] = 0.0;
	tmpPeca->translacaoOriginal[2] = 0.0;

	/* Angulos de rotacao */
	tmpPeca->angulo = (double*) calloc(3, sizeof (double));
	tmpPeca->angulo[0] = 0;
	tmpPeca->angulo[1] = 0;
	tmpPeca->angulo[2] = 0;

	/* Tamanho da perpectiva da peca (n?o sei se ? bem assim :s) */
	tmpPeca->factor = (double*) calloc(3, sizeof (double));
	tmpPeca->factor[0] = 2.0;
	tmpPeca->factor[1] = 2.0;
	tmpPeca->factor[2] = 2.0;

	/* Controlos da animacao */
	tmpPeca->rotacaoOnXX = 0;
	tmpPeca->rotacaoOnYY = 0;
	tmpPeca->rotacaoOnZZ = 0;

	return tmpPeca;
}

/* Aloca memoria para todas as pecas do puzzle que vao ser criadas a partir da informacao lida do ficheiro */
PecaPuzzle *criarArrayPecasPuzzle(int numPecas) {

	PecaPuzzle* tmpArray = (PecaPuzzle*) calloc(numPecas, sizeof (PecaPuzzle));

	return tmpArray;
}

/* Funcao para alocar memoria para estrutura do tipo Pessoa */
Pessoa criaPessoa() {
	
	Pessoa tmpPessoa = (Pessoa) calloc(1, sizeof(Estructura_Visualizador));
	
	tmpPessoa->rotacaoEmX = 1;
	tmpPessoa->rotacaoEmY = 1;
	tmpPessoa->valorX = 0.0;
	tmpPessoa->valorY = 0.0;
	
	return tmpPessoa;
}