/* 
 * File:   inicializacoes.h
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 11:48 AM
 */

#ifndef _inicializacoes_h
#define _inicializacoes_h


/* ----------------------------------------------------------------------- */

/* Inicializa o OpenGL*/
void inicializarEstado(void);

/* Cria a janela de saida */
void inicializarJanela(void);

/* Inicializa o foco */
void inicializarFocos(void);

/* Inicializa as pecas do puzzle (le do ficheiro e cria-as em openGL compilando-as em listas) */
void inicializarModelos(void);

/* ----------------------------------------------------------------------- */


#endif
