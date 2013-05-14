/* 
 * File:   modelos.h
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 11:49 AM
 */

#ifndef _modelos_h
#define _modelos_h

#include "globais.h"

/* ----------------------------------------------------------------------- */

/* Actualizacao dos parametros de transformacao de cada modelo */
GLint actualizaParametrosModelos( void );

/* Função para rodar apenas a peca seleccionada */
void actualizaParametroModeloSelect(int tipo, int direccao);

/* Função que vai ler um ficheiro e retornar as peças existentes no puzzle */
int lePecasDoNivel(int nivel);

/* Funcao para percorrer todas as pecas lidas do ficheiro e criar a PecaPuzzle */
void constroiPecasPuzzle( void );

/* ----------------------------------------------------------------------- */

#endif