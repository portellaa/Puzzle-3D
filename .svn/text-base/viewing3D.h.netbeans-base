/* 
 * File:   viewing3D.h
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 11:51 AM
 */

#ifndef _viewing3D_h
#define _viewing3D_h


/* ----------------------------------------------------------------------- */

/* Caracteristicas da JANELA de OUTPUT*/
int alturaJanela;	 
int compJanela;

int X_INICIAL_JANELA;
int Y_INICIAL_JANELA;

/* ----------------------------------------------------------------------- */

/* Caracteristicas do Volume de Visualizacao */
float xInf; 
float xSup;
float yInf;
float ySup;

float zPerto;
float zLonge;

/* O tipo de projeccao seleccionado */
char tipoProjeccao;


/* ----------------------------------------------------------------------- */

/* Inicializar modo de visualizacao em 3D */
void inicializarViewing3D( void );

/* Funcao que é invocada quando a janela / viewport sofre uma transformacao */
void transfJanelaViewport(void);

/* Actualiza a coordenada Z consoante o tipo de projecção */
void toogleZModelProjType(char tipoProjecao);

/* ----------------------------------------------------------------------- */


#endif