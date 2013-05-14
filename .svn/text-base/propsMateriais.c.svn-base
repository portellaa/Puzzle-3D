/* 
 * File:   propsMateriais.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:17 PM
 */

#include <stdlib.h>

#include "globais.h"
#include "propsMateriais.h"
#include "inicializacoes.h"

/* ----------------------------------------------------------------------- */

/* Funcao que cria uma copia dum material fornecido */
pontPropsMaterial criarMaterialDeMaterial(pontPropsMaterial pontOrig) {
	
	pontPropsMaterial tmpMaterial = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));
	
	tmpMaterial->coefReflAmbiente[0] = pontOrig->coefReflAmbiente[0];
    tmpMaterial->coefReflAmbiente[1] = pontOrig->coefReflAmbiente[1];
    tmpMaterial->coefReflAmbiente[2] = pontOrig->coefReflAmbiente[2];
    tmpMaterial->coefReflAmbiente[3] = pontOrig->coefReflAmbiente[3];
	
	tmpMaterial->coefReflDifusa[0] = pontOrig->coefReflDifusa[0];
    tmpMaterial->coefReflDifusa[1] = pontOrig->coefReflDifusa[1];
    tmpMaterial->coefReflDifusa[2] = pontOrig->coefReflDifusa[2];
    tmpMaterial->coefReflDifusa[3] = pontOrig->coefReflDifusa[3];


    tmpMaterial->coefReflEspecular[0] = pontOrig->coefReflEspecular[0];
    tmpMaterial->coefReflEspecular[1] = pontOrig->coefReflEspecular[1];
    tmpMaterial->coefReflEspecular[2] = pontOrig->coefReflEspecular[2];
    tmpMaterial->coefReflEspecular[3] = pontOrig->coefReflEspecular[3];


    /* Coef. de Phong */
    tmpMaterial->coefDePhong[0] = pontOrig->coefDePhong[0];
	
	return tmpMaterial;
}

/* Funcao que dada uma instancia dum material e uma peca atribui ao material da peca as mesmas caracteristicas do material fornecido */
void associaMaterialModelo(pontPropsMaterial material, PecaPuzzle modelo) {

	modelo->material = material;
}


/* ----------------------------------------------------------------------- */
/*** Materiais Metalicos ***/

/*** Bronze  ***/
pontPropsMaterial criaMaterialBronze(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.21;
    p->coefReflAmbiente[1] = 0.13;
    p->coefReflAmbiente[2] = 0.05;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.71;
    p->coefReflDifusa[1] = 0.43;
    p->coefReflDifusa[2] = 0.18;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.39;
    p->coefReflEspecular[1] = 0.27;
    p->coefReflEspecular[2] = 0.17;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 25.6;

    return p;
}

/*** Bronze Polido --- Polished Bronze ***/
pontPropsMaterial criaMaterialBronzePolido(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.25;
    p->coefReflAmbiente[1] = 0.15;
    p->coefReflAmbiente[2] = 0.06;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.4;
    p->coefReflDifusa[1] = 0.24;
    p->coefReflDifusa[2] = 0.10;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.77;
    p->coefReflEspecular[1] = 0.46;
    p->coefReflEspecular[2] = 0.20;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 76.8;

    return p;
}

/*** Cobre --- Copper  ***/
pontPropsMaterial criaMaterialCobre(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.19;
    p->coefReflAmbiente[1] = 0.07;
    p->coefReflAmbiente[2] = 0.02;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.70;
    p->coefReflDifusa[1] = 0.27;
    p->coefReflDifusa[2] = 0.08;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.26;
    p->coefReflEspecular[1] = 0.14;
    p->coefReflEspecular[2] = 0.08;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 12.8;

    return p;
}

/*** Cobre Polido --- Polished Copper ***/
pontPropsMaterial criaMaterialCobrePolido(void) {
    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.23;
    p->coefReflAmbiente[1] = 0.08;
    p->coefReflAmbiente[2] = 0.03;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.55;
    p->coefReflDifusa[1] = 0.21;
    p->coefReflDifusa[2] = 0.07;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.58;
    p->coefReflEspecular[1] = 0.22;
    p->coefReflEspecular[2] = 0.07;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 51.2;

    return p;
}

/*** Cromio --- Chrome ***/
pontPropsMaterial criaMaterialCromio(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.25;
    p->coefReflAmbiente[1] = 0.25;
    p->coefReflAmbiente[2] = 0.25;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.4;
    p->coefReflDifusa[1] = 0.4;
    p->coefReflDifusa[2] = 0.4;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.77;
    p->coefReflEspecular[1] = 0.77;
    p->coefReflEspecular[2] = 0.77;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 76.8;

    return p;
}

/*** Latao --- Brass ***/
pontPropsMaterial criaMaterialLatao(void) {
    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.33;
    p->coefReflAmbiente[1] = 0.22;
    p->coefReflAmbiente[2] = 0.03;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.78;
    p->coefReflDifusa[1] = 0.57;
    p->coefReflDifusa[2] = 0.11;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.99;
    p->coefReflEspecular[1] = 0.94;
    p->coefReflEspecular[2] = 0.81;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 27.9;

    return p;
}

/*** Ouro --- Gold  ***/
pontPropsMaterial criaMaterialOuro(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.25;
    p->coefReflAmbiente[1] = 0.20;
    p->coefReflAmbiente[2] = 0.07;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.75;
    p->coefReflDifusa[1] = 0.60;
    p->coefReflDifusa[2] = 0.23;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.63;
    p->coefReflEspecular[1] = 0.56;
    p->coefReflEspecular[2] = 0.37;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 51.2;

    return p;
}

/*** Ouro Polido --- Polished Gold ***/
pontPropsMaterial criaMaterialOuroPolido(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.25;
    p->coefReflAmbiente[1] = 0.22;
    p->coefReflAmbiente[2] = 0.06;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.35;
    p->coefReflDifusa[1] = 0.31;
    p->coefReflDifusa[2] = 0.09;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.80;
    p->coefReflEspecular[1] = 0.73;
    p->coefReflEspecular[2] = 0.21;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 83.2;

    return p;
}

/*** Prata Polida ***/
pontPropsMaterial criaMaterialPrataPolida(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.23;
    p->coefReflAmbiente[1] = 0.23;
    p->coefReflAmbiente[2] = 0.23;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.28;
    p->coefReflDifusa[1] = 0.28;
    p->coefReflDifusa[2] = 0.28;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.77;
    p->coefReflEspecular[1] = 0.77;
    p->coefReflEspecular[2] = 0.77;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 89.6;

    return p;
}

/*** Materiais Nao-Metalicos ***/
pontPropsMaterial criaMaterialPlasticoVermelho(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.3;
    p->coefReflAmbiente[1] = 0.0;
    p->coefReflAmbiente[2] = 0.0;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.6;
    p->coefReflDifusa[1] = 0.0;
    p->coefReflDifusa[2] = 0.0;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.8;
    p->coefReflEspecular[1] = 0.6;
    p->coefReflEspecular[2] = 0.6;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 32.0;

    return p;
}

pontPropsMaterial criaMaterialEsmeralda(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.02;
    p->coefReflAmbiente[1] = 0.17;
    p->coefReflAmbiente[2] = 0.02;
    p->coefReflAmbiente[3] = 0.55;

    p->coefReflDifusa[0] = 0.08;
    p->coefReflDifusa[1] = 0.61;
    p->coefReflDifusa[2] = 0.08;
    p->coefReflDifusa[3] = 0.55;

    p->coefReflEspecular[0] = 0.63;
    p->coefReflEspecular[1] = 0.73;
    p->coefReflEspecular[2] = 0.63;
    p->coefReflEspecular[3] = 0.55;

    /* Coef. de Phong */
    p->coefDePhong[0] = 76.8;

    return p;
}

pontPropsMaterial criaMaterialJade(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.14;
    p->coefReflAmbiente[1] = 0.22;
    p->coefReflAmbiente[2] = 0.16;
    p->coefReflAmbiente[3] = 0.95;

    p->coefReflDifusa[0] = 0.54;
    p->coefReflDifusa[1] = 0.89;
    p->coefReflDifusa[2] = 0.63;
    p->coefReflDifusa[3] = 0.95;

    p->coefReflEspecular[0] = 0.32;
    p->coefReflEspecular[1] = 0.32;
    p->coefReflEspecular[2] = 0.32;
    p->coefReflEspecular[3] = 0.95;

    /* Coef. de Phong */
    p->coefDePhong[0] = 12.8;

    return p;
}

pontPropsMaterial criaMaterialRubi(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.17;
    p->coefReflAmbiente[1] = 0.01;
    p->coefReflAmbiente[2] = 0.01;
    p->coefReflAmbiente[3] = 0.55;

    p->coefReflDifusa[0] = 0.61;
    p->coefReflDifusa[1] = 0.04;
    p->coefReflDifusa[2] = 0.04;
    p->coefReflDifusa[3] = 0.55;

    p->coefReflEspecular[0] = 0.73;
    p->coefReflEspecular[1] = 0.63;
    p->coefReflEspecular[2] = 0.63;
    p->coefReflEspecular[3] = 0.55;

    /* Coef. de Phong */
    p->coefDePhong[0] = 76.8;

    return p;
}

pontPropsMaterial criaMaterialPerola(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.25;
    p->coefReflAmbiente[1] = 0.21;
    p->coefReflAmbiente[2] = 0.21;
    p->coefReflAmbiente[3] = 0.922;

    p->coefReflDifusa[0] = 1.0;
    p->coefReflDifusa[1] = 0.83;
    p->coefReflDifusa[2] = 0.83;
    p->coefReflDifusa[3] = 0.922;

    p->coefReflEspecular[0] = 0.30;
    p->coefReflEspecular[1] = 0.30;
    p->coefReflEspecular[2] = 0.30;
    p->coefReflEspecular[3] = 0.922;

    /* Coef. de Phong */
    p->coefDePhong[0] = 11.264;

    return p;
}

pontPropsMaterial criaMaterialAzulMtoBrilhante(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.0;
    p->coefReflAmbiente[1] = 0.0;
    p->coefReflAmbiente[2] = 0.5;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.0;
    p->coefReflDifusa[1] = 0.0;
    p->coefReflDifusa[2] = 1.0;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 1.0;
    p->coefReflEspecular[1] = 1.0;
    p->coefReflEspecular[2] = 1.0;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 125.0;

    return p;
}

pontPropsMaterial criaMaterialCinzento(void) {

    pontPropsMaterial p = (pontPropsMaterial) malloc(sizeof ( Registo_Props_Material));

    p->coefReflAmbiente[0] = 0.1;
    p->coefReflAmbiente[1] = 0.1;
    p->coefReflAmbiente[2] = 0.1;
    p->coefReflAmbiente[3] = 1.0;

    p->coefReflDifusa[0] = 0.5;
    p->coefReflDifusa[1] = 0.5;
    p->coefReflDifusa[2] = 0.5;
    p->coefReflDifusa[3] = 1.0;

    p->coefReflEspecular[0] = 0.7;
    p->coefReflEspecular[1] = 0.7;
    p->coefReflEspecular[2] = 0.7;
    p->coefReflEspecular[3] = 1.0;

    /* Coef. de Phong */
    p->coefDePhong[0] = 1.0;

    return p;
}


/* ----------------------------------------------------------------------- */

/* Funcao para instanciar todos os tipos de materiais */
void criaMateriais(void) {
	
    pMaterialBronze = criaMaterialBronze();
    pMaterialBronzePolido = criaMaterialBronzePolido();
    pMaterialCobre = criaMaterialCobre();
    pMaterialCobrePolido = criaMaterialCobrePolido();
    pMaterialCromio = criaMaterialCromio();
    pMaterialLatao = criaMaterialLatao();
    pMaterialOuro = criaMaterialOuro();
    pMaterialOuroPolido = criaMaterialOuroPolido();
    pMaterialPlasticoVermelho = criaMaterialPlasticoVermelho();
    pMaterialEsmeralda = criaMaterialEsmeralda();
    pMaterialJade = criaMaterialJade();
    pMaterialRubi = criaMaterialRubi();
    pMaterialPerola = criaMaterialPerola();
    pMaterialAzulMtoBrilhante = criaMaterialAzulMtoBrilhante();
}

/* Inicializa a lista de Materiais */
void inicializarListaMateriais (void) {
	
	materialSelec = pMaterialPlasticoVermelho;
	listaMateriais = (pontPropsMaterial*) calloc (13, sizeof(pontPropsMaterial));
	
	listaMateriais[0] = pMaterialBronze;
	listaMateriais[1] = pMaterialBronzePolido;
	listaMateriais[2] = pMaterialCobre;
	listaMateriais[3] = pMaterialCobrePolido;
	listaMateriais[4] = pMaterialCromio;
	listaMateriais[5] = pMaterialLatao;
	listaMateriais[6] = pMaterialOuro;
	listaMateriais[7] = pMaterialOuroPolido;
	listaMateriais[8] = pMaterialEsmeralda;
	listaMateriais[9] = pMaterialJade;
	listaMateriais[10] = pMaterialRubi;
	listaMateriais[11] = pMaterialPerola;
	listaMateriais[12] = pMaterialAzulMtoBrilhante;
}
