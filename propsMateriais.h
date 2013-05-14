/* 
 * File:   propsMateriais.h
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 11:50 AM
 */

#ifndef _props_materiais_h
#define _props_materiais_h


#include "globais.h"


/* ----------------------------------------------------------------------- */

/* Funcao que cria uma copia dum material fornecido */
pontPropsMaterial criarMaterialDeMaterial(pontPropsMaterial pontOrig);

/* Funcao que dada uma instancia dum material e uma peca atribui ao material da peca as mesmas caracteristicas do material fornecido */
void associaMaterialModelo(pontPropsMaterial material, PecaPuzzle modelo);

/* Funcao para instanciar todos os tipos de materiais */
void criaMateriais(void);

/* Inicializa a lista de Materiais */
void inicializarListaMateriais (void);

/* ----------------------------------------------------------------------- */


#endif