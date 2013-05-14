/* 
 * File:   modelos.c
 * Author: Luis Portela, 36170
 * Author: Rui Martins, 38282
 *
 * Created on November 24, 2011, 12:16 PM
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "estDados.h"
#include "globais.h"
#include "modelos.h"
#include "propsMateriais.h"
#include "consoleIO.h"

/* ----------------------------------------------------------------------- */

void shuffle() {
    printf("Vou comecar a baralhar...\n");

    int tipo[] = {TRANSLACAO, ROTACAO};
    int eixo[] = {XX, Xx, YY, Yy, ZZ, Zz};

    srand(time(NULL));
    pecaSelec = rand() % totalPecas;
    actualizaParametroModeloSelect(tipo[rand() % 2], eixo[rand() % 6]);
    ActualizaMaterial();
    printf("Já está baralhado...\n");
}

int verificaPuzzleCompleto() {
    int i, j;
    int completo = 0;

    /*
        for (i=0;i<totalPecas;i++){
            printf("Verificando a peca %d de %d.\n", i+1, totalPecas);
        
            printf("A coordenada do centro da peca é %d, %d, %d.\n", TodasPecas->listaPecas[i]->coordCuboPrinc[0],TodasPecas->listaPecas[i]->coordCuboPrinc[1],TodasPecas->listaPecas[i]->coordCuboPrinc[2]);
            for (j=0;j<TodasPecas->listaPecas[i]->numCubos-1;j++){
                printf("Verificando o cubo %d de %d.\n", j+2, TodasPecas->listaPecas[i]->numCubos);
                printf("Coordenada= %d, %d, %d.\n", TodasPecas->listaPecas[i]->coordOutrosCubos[j][0],TodasPecas->listaPecas[i]->coordOutrosCubos[j][1],TodasPecas->listaPecas[i]->coordOutrosCubos[j][2]);
            }
        }
     */

    for (i = 0; i < totalPecas; i++) {
        printf("%f =?= %f\n", PecasPuzzle[i]->translacao[0], PecasPuzzle[i]->translacaoOriginal[0]);
        if (PecasPuzzle[i]->translacao[0] == PecasPuzzle[i]->translacaoOriginal[0]
                &&
                PecasPuzzle[i]->translacao[1] == PecasPuzzle[i]->translacaoOriginal[1]
                &&
                PecasPuzzle[i]->translacao[2] == PecasPuzzle[i]->translacaoOriginal[2]) {
            completo = 1;
            printf("Peca %d está no local correcto.\n", i);
        } else {
            printf("Peca %d está no local ERRADO.\n", i);
            return 0;
        }
    }
    printf("Puzzle Completo!\n", i);

    return completo;
}

/* Calcula o maior e menor ponto */
void getMinAndMax(ponto3D* values, int size, char eixo, GLfloat *minimum, GLfloat *maximum) {

    int i;

    if (eixo == 'X') {
        (*minimum) = values[0][0];
        (*maximum) = values[0][0];
        for (i = 1; i < size; i++) {
            if (values[i][0] < (*minimum))
                (*minimum) = values[i][0];

            if (values[i][0] > (*maximum))
                (*maximum) = values[i][0];
        }
        return;
    }

    if (eixo == 'Y') {
        (*minimum) = values[0][1];
        (*maximum) = values[0][1];
        for (i = 1; i < size; i++) {
            if (values[i][1] < (*minimum))
                (*minimum) = values[i][1];

            if (values[i][1] > (*maximum))
                (*maximum) = values[i][1];
        }
        return;
    }

    if (eixo == 'Z') {
        (*minimum) = values[0][2];
        (*maximum) = values[0][2];
        for (i = 1; i < size; i++) {
            if (values[i][2] < (*minimum))
                (*minimum) = values[i][2];

            if (values[i][2] > (*maximum))
                (*maximum) = values[i][2];
        }
        return;
    }
}

/* Calcula o centro de uma gama de valores */
float calcMed(float root, float min, float max, GLfloat *tamanho) {

    int i, count = 0;
    float finalValue = 0.0;

    printf("\nValor Minimo: %f", min);
    printf("\nValor Maximo: %f", max);

    for (i = min; i <= max; i += 1.0) {

        finalValue = (float) (finalValue + (root + i));
        count++;
        printf("\nSomas: %d, valor: %f", i, finalValue);
    }
    printf("\nfinalValue: %f, media: %f", finalValue, finalValue / count);

    (*tamanho) = ((GLfloat) (count * CUBO_SIZE));

    return ((float) (finalValue / count));
}

/* Calcula o centro da peca */
ponto3D calcCentro(Peca pecaALer, ponto3D tamanho) {

    ponto3D centro;
    float centroX, centroY, centroZ;
    GLfloat min, max;

    getMinAndMax(pecaALer->coordOutrosCubos, pecaALer->numCubos - 1, 'X', &min, &max);
    centroX = calcMed(pecaALer->coordCuboPrinc[0], min, max, (&(tamanho[0])));
    printf("\n[calcCentro]: TAMANHO X: %f", tamanho[0]);
    getMinAndMax(pecaALer->coordOutrosCubos, pecaALer->numCubos - 1, 'Y', &min, &max);
    centroY = calcMed(pecaALer->coordCuboPrinc[1], min, max, (&(tamanho[1])));
    printf("\n[calcCentro]: TAMANHO Y: %f", tamanho[1]);
    getMinAndMax(pecaALer->coordOutrosCubos, pecaALer->numCubos - 1, 'Z', &min, &max);
    centroZ = calcMed(pecaALer->coordCuboPrinc[2], min, max, (&(tamanho[2])));
    printf("\n[calcCentro]: TAMANHO Z: %f", tamanho[2]);

    centro = criaVertice(centroX, centroY, centroZ);

    printf("Centro: ");
    imprimeVertice(centro);

    return centro;
}

/* Criacao dos modelos a usar na aplicacao */
pontCubo criaCubo(Peca pecaALer, ponto3D centro, int cubo) {

    pontCubo pCubo = (pontCubo) malloc(sizeof (Estructura_Cubo));
    ponto3D *vertices = (ponto3D*) calloc(8, (sizeof (ponto3D)));
    ponto3D cuboRelativo;
    ponto3D tmpPonto;
    ponto3D cuboPrinc = criaCopiaDeVertice(pecaALer->coordCuboPrinc);

    float tmpX, tmpY, tmpZ;

    cuboPrinc[0] = (float) (cuboPrinc[0] - centro[0]);
    cuboPrinc[1] = (float) (cuboPrinc[1] - centro[1]);
    cuboPrinc[2] = (float) (cuboPrinc[2] - centro[2]);

    printf("[CriaCubo]: cuboPrinc Nao CENTRADO: ");
    imprimeVertice(cuboPrinc);

    pCubo->faces = (face*) calloc(NUM_FACES_CUBO, (sizeof (face)));
    pCubo->normais = (vector3D*) calloc(6, sizeof (vector3D));

    if (cubo == 0) {

        tmpX = (float) (cuboPrinc[0] * CUBO_SIZE);
        tmpY = (float) (cuboPrinc[1] * CUBO_SIZE);
        tmpZ = (float) (cuboPrinc[2] * CUBO_SIZE);
        tmpPonto = criaVertice(tmpX, tmpY, tmpZ);

        printf("[criaCubo]: Vertice Principal Centrado: ");
        imprimeVertice(tmpPonto);

    } else {

        cuboRelativo = pecaALer->coordOutrosCubos[cubo - 1];

        printf("[criaCubo]: Vertice Relativo Não Centrado: ");
        imprimeVertice(pecaALer->coordOutrosCubos[cubo - 1]);

        tmpX = (float) ((cuboPrinc[0] + cuboRelativo[0]) * CUBO_SIZE);
        tmpY = (float) ((cuboPrinc[1] + cuboRelativo[1]) * CUBO_SIZE);
        tmpZ = (float) ((cuboPrinc[2] + cuboRelativo[2]) * CUBO_SIZE);

        tmpPonto = criaVertice(tmpX, tmpY, tmpZ);

        printf("[criaCubo]: Vertice Relativo Centrado: ");
        imprimeVertice(tmpPonto);
    }

    /* Vertices Frente */
    vertices[0] = criaVertice(tmpPonto[0] - HALF_CUBO_SIZE, tmpPonto[1] - HALF_CUBO_SIZE, tmpPonto[2] + HALF_CUBO_SIZE);
    vertices[1] = criaVertice(tmpPonto[0] + HALF_CUBO_SIZE, tmpPonto[1] - HALF_CUBO_SIZE, tmpPonto[2] + HALF_CUBO_SIZE);
    vertices[2] = criaVertice(tmpPonto[0] + HALF_CUBO_SIZE, tmpPonto[1] + HALF_CUBO_SIZE, tmpPonto[2] + HALF_CUBO_SIZE);
    vertices[3] = criaVertice(tmpPonto[0] - HALF_CUBO_SIZE, tmpPonto[1] + HALF_CUBO_SIZE, tmpPonto[2] + HALF_CUBO_SIZE);

    /* Vertices Tras */
    vertices[4] = criaVertice(tmpPonto[0] - HALF_CUBO_SIZE, tmpPonto[1] - HALF_CUBO_SIZE, tmpPonto[2] - HALF_CUBO_SIZE);
    vertices[5] = criaVertice(tmpPonto[0] + HALF_CUBO_SIZE, tmpPonto[1] - HALF_CUBO_SIZE, tmpPonto[2] - HALF_CUBO_SIZE);
    vertices[6] = criaVertice(tmpPonto[0] + HALF_CUBO_SIZE, tmpPonto[1] + HALF_CUBO_SIZE, tmpPonto[2] - HALF_CUBO_SIZE);
    vertices[7] = criaVertice(tmpPonto[0] - HALF_CUBO_SIZE, tmpPonto[1] + HALF_CUBO_SIZE, tmpPonto[2] - HALF_CUBO_SIZE);

    /* Face Frente */
    pCubo->faces[0] = criaFace(vertices[0], vertices[1], vertices[2], vertices[3]);

    /* Face Direita */
    pCubo->faces[1] = criaFace(vertices[1], vertices[5], vertices[6], vertices[2]);

    /* Face Traseira */
    pCubo->faces[2] = criaFace(vertices[4], vertices[7], vertices[6], vertices[5]);

    /* Face Esquerda */
    pCubo->faces[3] = criaFace(vertices[4], vertices[0], vertices[3], vertices[7]);

    /* Face Topo */
    pCubo->faces[4] = criaFace(vertices[3], vertices[2], vertices[6], vertices[7]);

    /* Face Base */
    pCubo->faces[5] = criaFace(vertices[4], vertices[5], vertices[1], vertices[0]);

    pCubo->normais[0] = criaVector(0.0, 0.0, 1.0);
    pCubo->normais[1] = criaVector(1.0, 0.0, 0.0);
    pCubo->normais[2] = criaVector(0.0, 0.0, -1.0);
    pCubo->normais[3] = criaVector(-1.0, 0.0, 0.0);
    pCubo->normais[4] = criaVector(0.0, 1.0, 0.0);
    pCubo->normais[5] = criaVector(0.0, -1.0, 0.0);

    free(vertices);
    free(tmpPonto);
    free(cuboPrinc);

    tmpPonto = NULL;
    vertices = NULL;

    return pCubo;
}

/* Funcao para criar peca puzzle completa */
PecaPuzzle criaPecaPuzzle(Peca pecaALer, int pecaID) {

    PecaPuzzle pecaCompleta = criarPecaPuzzle(pecaALer);
    int i;

    ponto3D centro = calcCentro(pecaALer, pecaCompleta->tamanho);
    imprimeVertice(centro);

    pecaCompleta->listaCubos[0] = criaCubo(pecaALer, centro, 0);

    for (i = 1; i < pecaALer->numCubos; i++) {
        pecaCompleta->listaCubos[i] = criaCubo(pecaALer, centro, i);
    }

    /* Propriedades do material do modelo */
    associaMaterialModelo(listaMateriais[pecaID], pecaCompleta);

    printf("[criaPecaPuzzle]:Peca->%d CUBO PRINC: X: %f, Y: %f, Z: %f\n", pecaID, pecaALer->coordCuboPrinc[0], pecaALer->coordCuboPrinc[1], pecaALer->coordCuboPrinc[2]);
    printf("[criaPecaPuzzle]:Peca->%d CENTRO: X: %f, Y: %f, Z: %f\n", pecaID, centro[0], centro[1], centro[2]);

    pecaCompleta->translacao[0] = pecaCompleta->translacaoOriginal[0] = (float) ((centro[0]) * (CUBO_SIZE * 2));
    pecaCompleta->translacao[1] = pecaCompleta->translacaoOriginal[1] = (float) ((centro[1]) * (CUBO_SIZE * 2));
    pecaCompleta->translacao[2] = pecaCompleta->translacaoOriginal[2] = (float) ((centro[2]) * (CUBO_SIZE * 2));

    printf("\n[criaPecaPuzzle]: TAMANHO PECA: ");
    imprimeVertice(pecaCompleta->tamanho);

    printf("[criaPecaPuzzle]:Peca->%d TRANSLACAO: X: %f, Y: %f, Z: %f\n", pecaID, pecaCompleta->translacao[0], pecaCompleta->translacao[1], pecaCompleta->translacao[2]);

    return pecaCompleta;
}

/* Funcao para percorrer todas as pecas lidas do ficheiro e criar a PecaPuzzle */
void constroiPecasPuzzle(void) {

    PecasPuzzle = criarArrayPecasPuzzle(TodasPecas->numPecas);
    int i;

    for (i = 0; i < totalPecas; i++) {
        PecasPuzzle[i] = criaPecaPuzzle(TodasPecas->listaPecas[i], i);
    }

    PecasPuzzle[pecaSelec]->material = materialSelec;
}

/* Funcao para actualizar os parametros do cubo utilizada pelo Timer */
GLint actualizaParametrosModelos(void) {

    int i, flagRedisplay = 0;
    float angRotModelo = 1.0;

    /*
            if (Visualizador->rotacaoEmY) {
                    Visualizador->valorY += angRotModelo;
                    flagRedisplay = 1;
            }
     */

    /* Usar os controlos de animacao para saber que angulo incrementar ou decrementar */
    for (i = 0; i < totalPecas; i++) {
        if (PecasPuzzle[i]->rotacaoOnXX) {
            flagRedisplay = 1;

            PecasPuzzle[i]->angulo[0] += angRotModelo;

            if (PecasPuzzle[i]->angulo[0] >= 360) {
                PecasPuzzle[i]->angulo[0] -= 360;
            }
        }

        if (PecasPuzzle[i]->rotacaoOnYY) {
            flagRedisplay = 1;

            PecasPuzzle[i]->angulo[1] += angRotModelo;

            if (PecasPuzzle[i]->angulo[1] >= 360) {
                PecasPuzzle[i]->angulo[1] -= 360;
            }
        }

        if (PecasPuzzle[i]->rotacaoOnZZ) {
            flagRedisplay = 1;

            PecasPuzzle[i]->angulo[2] += angRotModelo;

            if (PecasPuzzle[i]->angulo[2] >= 360) {
                PecasPuzzle[i]->angulo[2] -= 360;
            }
        }
    }

    return flagRedisplay;
}

/* Função para rodar apenas a peca seleccionada */
void actualizaParametroModeloSelect(int tipo, int direccao) {

    if (tipo == ROTACAO) {
        float angRotModelo = 1.0;
        float anguloFinal;

        printf("actualizaParametroModeloSelect - ROTAÇÃO\n");

        if (direccao == XX) {
            printf("XX\n");
            anguloFinal = PecasPuzzle[pecaSelec]->angulo[0] + 90;
            printf("%f = %f - (%f % 90)   => %f\n", anguloFinal, anguloFinal, anguloFinal, ((int) anguloFinal % (int) 90));
            anguloFinal = anguloFinal - ((int) anguloFinal % (int) 90);
            printf("%f = %f - (%f % 90)   => %f\n", anguloFinal, anguloFinal, anguloFinal, ((int) anguloFinal % (int) 90));
            if (tmpRedisplayRXX > 0) {

                PecasPuzzle[pecaSelec]->angulo[0] += VEL_ROTACAO * angRotModelo;

                if (PecasPuzzle[pecaSelec]->angulo[0] >= 360) {
                    PecasPuzzle[pecaSelec]->angulo[0] -= 360;
                }
                if (PecasPuzzle[pecaSelec]->angulo[0] >= anguloFinal) {
                    tmpRedisplayRXX = 0;
                    PecasPuzzle[pecaSelec]->angulo[0] = anguloFinal;

                } else {
                    tmpRedisplayRXX -= VEL_ROTACAO * (int) angRotModelo;
                    if (tmpRedisplayRXX <= 0) tmpRedisplayRXX = 0;
                }
            }
        } else {

            if (direccao == Xx) {
                printf("Xx\n");
                anguloFinal = PecasPuzzle[pecaSelec]->angulo[0] - 90;
                anguloFinal -= ((int) anguloFinal % (int) 90);
                if (tmpRedisplayRXX < 0) {

                    PecasPuzzle[pecaSelec]->angulo[0] -= VEL_ROTACAO * angRotModelo;

                    if (PecasPuzzle[pecaSelec]->angulo[0] < 0) {
                        PecasPuzzle[pecaSelec]->angulo[0] += 360;
                    }
                    if (PecasPuzzle[pecaSelec]->angulo[0] <= anguloFinal) {
                        tmpRedisplayRXX = 0;
                        PecasPuzzle[pecaSelec]->angulo[0] = anguloFinal;

                    } else {
                        tmpRedisplayRXX += VEL_ROTACAO * (int) angRotModelo;
                        if (tmpRedisplayRXX >= 0) tmpRedisplayRXX = 0;
                    }
                }
            }
        }

        if (direccao == YY) {
            printf("YY\n");
            anguloFinal = PecasPuzzle[pecaSelec]->angulo[1] + 90;
            anguloFinal -= ((int) anguloFinal % (int) 90);
            if (tmpRedisplayRYY > 0) {

                PecasPuzzle[pecaSelec]->angulo[1] += VEL_ROTACAO * angRotModelo;

                if (PecasPuzzle[pecaSelec]->angulo[1] >= 360) {
                    PecasPuzzle[pecaSelec]->angulo[1] -= 360;
                }
                if (PecasPuzzle[pecaSelec]->angulo[1] >= anguloFinal) {
                    tmpRedisplayRYY = 0;
                    PecasPuzzle[pecaSelec]->angulo[1] = anguloFinal;

                } else {
                    tmpRedisplayRYY -= VEL_ROTACAO * (int) angRotModelo;
                    if (tmpRedisplayRYY <= 0) tmpRedisplayRYY = 0;
                }
            }
        } else {

            if (direccao == Yy) {
                printf("Yy\n");
                anguloFinal = PecasPuzzle[pecaSelec]->angulo[1] - 90;
                anguloFinal -= ((int) anguloFinal % (int) 90);
                if (tmpRedisplayRYY < 0) {

                    PecasPuzzle[pecaSelec]->angulo[1] -= VEL_ROTACAO * angRotModelo;

                    if (PecasPuzzle[pecaSelec]->angulo[1] < 0) {
                        PecasPuzzle[pecaSelec]->angulo[1] += 360;
                    }
                    if (PecasPuzzle[pecaSelec]->angulo[1] <= anguloFinal) {
                        tmpRedisplayRYY = 0;
                        PecasPuzzle[pecaSelec]->angulo[1] = anguloFinal;

                    } else {
                        tmpRedisplayRYY += VEL_ROTACAO * (int) angRotModelo;
                        if (tmpRedisplayRYY >= 0) tmpRedisplayRYY = 0;
                    }
                }
            }
        }


        if (direccao == ZZ) {
            printf("ZZ\n");
            anguloFinal = PecasPuzzle[pecaSelec]->angulo[2] + 90;
            if (tmpRedisplayRZZ > 0) {

                PecasPuzzle[pecaSelec]->angulo[2] += VEL_ROTACAO * angRotModelo;

                if (PecasPuzzle[pecaSelec]->angulo[2] >= 360) {
                    PecasPuzzle[pecaSelec]->angulo[2] -= 360;
                }
                if (PecasPuzzle[pecaSelec]->angulo[2] >= anguloFinal) {
                    tmpRedisplayRZZ = 0;
                    PecasPuzzle[pecaSelec]->angulo[2] = anguloFinal;

                } else {
                    tmpRedisplayRZZ -= VEL_ROTACAO * (int) angRotModelo;
                    if (tmpRedisplayRZZ <= 0) tmpRedisplayRZZ = 0;
                }
            }
        } else {

            if (direccao == Zz) {
                printf("Zz\n");
                anguloFinal = PecasPuzzle[pecaSelec]->angulo[2] - 90;
                if (tmpRedisplayRZZ < 0) {

                    PecasPuzzle[pecaSelec]->angulo[2] -= VEL_ROTACAO * angRotModelo;

                    if (PecasPuzzle[pecaSelec]->angulo[2] < 0) {
                        PecasPuzzle[pecaSelec]->angulo[2] += 360;
                    }
                    if (PecasPuzzle[pecaSelec]->angulo[2] <= anguloFinal) {
                        tmpRedisplayRZZ = 0;
                        PecasPuzzle[pecaSelec]->angulo[2] = anguloFinal;

                    } else {
                        tmpRedisplayRZZ += VEL_ROTACAO * (int) angRotModelo;
                        if (tmpRedisplayRZZ >= 0) tmpRedisplayRZZ = 0;
                    }
                }
            }
        }
    } else {
        if (tipo = TRANSLACAO) {

            float posTraModelo = 0.01; /* Numero de posições que o modelo se desloca */
            float posicaoFinal;

            printf("actualizaParametroModeloSelect - TRANSLACÇÃO\n");

            if (direccao == XX) {
                printf("XX tmpRedisplayTXX = %f\n", tmpRedisplayTXX);
                posicaoFinal = PecasPuzzle[pecaSelec]->translacao[0] + CUBO_SIZE;
                if (posicaoFinal >= LIM_MAX_X) posicaoFinal = LIM_MAX_X;
                if (tmpRedisplayTXX > 0) {
                    printf("tmpRedisplayTXX>0 - %d\n", tmpRedisplayTXX);

                    PecasPuzzle[pecaSelec]->translacao[0] += VEL_TRANSLACAO * posTraModelo;

                    if (PecasPuzzle[pecaSelec]->translacao[0] >= LIM_MAX_X) {
                        printf("PecasPuzzle[pecaSelec]->translacao[0] >= LIM_MAX_X - %f >= %f\n", PecasPuzzle[pecaSelec]->translacao[0], LIM_MAX_X);
                        PecasPuzzle[pecaSelec]->translacao[0] = LIM_MAX_X;
                    }
                    if (PecasPuzzle[pecaSelec]->translacao[0] >= posicaoFinal) {
                        printf("PecasPuzzle[pecaSelec]->translacao[0] >= posicaoFinal - %f> = %f\n", PecasPuzzle[pecaSelec]->translacao[0], posicaoFinal);
                        tmpRedisplayTXX = 0;
                        PecasPuzzle[pecaSelec]->translacao[0] = posicaoFinal;


                    } else {

                        printf("tmpRedisplayTXX -= VEL_TRANSLACAO * posTraModelo;\n");
                        tmpRedisplayTXX -= (VEL_TRANSLACAO * posTraModelo) / 2;
                        if (tmpRedisplayTXX <= 0) {
                            tmpRedisplayTXX = 0;
                            printf("tmpRedisplayTXX <= 0\n");
                        }


                    }

                }
            } else {
                if (direccao == Xx) {
                    printf("Xx tmpRedisplayTXX = %f\n", tmpRedisplayTXX);
                    posicaoFinal = PecasPuzzle[pecaSelec]->translacao[0] - CUBO_SIZE;
                    if (posicaoFinal <= LIM_MIN_X) posicaoFinal = LIM_MIN_X;
                    if (tmpRedisplayTXX < 0) {
                        printf("tmpRedisplayTXX<0 - %d\n", tmpRedisplayTXX);

                        PecasPuzzle[pecaSelec]->translacao[0] -= VEL_TRANSLACAO * posTraModelo;

                        if (PecasPuzzle[pecaSelec]->translacao[0] < LIM_MIN_X) {
                            printf("PecasPuzzle[pecaSelec]->translacao[0] >= LIM_MAX_X - %f >= %f\n", PecasPuzzle[pecaSelec]->translacao[0], LIM_MAX_X);
                            PecasPuzzle[pecaSelec]->translacao[0] = LIM_MIN_X;
                        }
                        if (PecasPuzzle[pecaSelec]->translacao[0] <= posicaoFinal) {
                            printf("PecasPuzzle[pecaSelec]->translacao[0] >= posicaoFinal - %f> = %f\n", PecasPuzzle[pecaSelec]->translacao[0], posicaoFinal);
                            tmpRedisplayTXX = 0;
                            PecasPuzzle[pecaSelec]->translacao[0] = posicaoFinal;


                        } else {

                            printf("tmpRedisplayTXX += VEL_TRANSLACAO * posTraModelo;\n");
                            tmpRedisplayTXX += (VEL_TRANSLACAO * posTraModelo) / 2;
                            if (tmpRedisplayTXX >= 0) {
                                tmpRedisplayTXX = 0;
                                printf("tmpRedisplayTXX >= 0\n");
                            }
                        }
                    }
                }
            }

            if (direccao == YY) {
                printf("YY tmpRedisplayTYY = %f\n", tmpRedisplayTYY);
                posicaoFinal = PecasPuzzle[pecaSelec]->translacao[1] + CUBO_SIZE;
                if (posicaoFinal >= LIM_MAX_Y) posicaoFinal = LIM_MAX_Y;
                if (tmpRedisplayTYY > 0) {
                    printf("tmpRedisplayTYY>0 - %d\n", tmpRedisplayTYY);

                    PecasPuzzle[pecaSelec]->translacao[1] += VEL_TRANSLACAO * posTraModelo;

                    if (PecasPuzzle[pecaSelec]->translacao[1] >= LIM_MAX_Y) {
                        PecasPuzzle[pecaSelec]->translacao[1] = LIM_MAX_Y;
                    }
                    if (PecasPuzzle[pecaSelec]->translacao[1] >= posicaoFinal) {
                        tmpRedisplayTYY = 0;
                        PecasPuzzle[pecaSelec]->translacao[1] = posicaoFinal;


                    } else {

                        printf("tmpRedisplayTYY -= VEL_TRANSLACAO * posTraModelo;\n");
                        tmpRedisplayTYY -= (VEL_TRANSLACAO * posTraModelo) / 2;
                        if (tmpRedisplayTYY <= 0) {
                            tmpRedisplayTYY = 0;
                            printf("tmpRedisplayTYY <= 0\n");
                        }


                    }

                }
            } else {
                if (direccao == Yy) {
                    printf("Yy tmpRedisplayTYY = %f\n", tmpRedisplayTYY);
                    posicaoFinal = PecasPuzzle[pecaSelec]->translacao[1] - CUBO_SIZE;
                    if (posicaoFinal <= LIM_MIN_Y) posicaoFinal = LIM_MIN_Y;
                    if (tmpRedisplayTYY < 0) {
                        printf("tmpRedisplayTYY<0 - %d\n", tmpRedisplayTYY);

                        PecasPuzzle[pecaSelec]->translacao[1] -= VEL_TRANSLACAO * posTraModelo;

                        if (PecasPuzzle[pecaSelec]->translacao[1] < LIM_MIN_Y) {

                            PecasPuzzle[pecaSelec]->translacao[1] = LIM_MIN_Y;
                        }
                        if (PecasPuzzle[pecaSelec]->translacao[1] <= posicaoFinal) {

                            tmpRedisplayTYY = 0;
                            PecasPuzzle[pecaSelec]->translacao[1] = posicaoFinal;


                        } else {

                            printf("tmpRedisplayTXX += VEL_TRANSLACAO * posTraModelo;\n");
                            tmpRedisplayTYY += (VEL_TRANSLACAO * posTraModelo) / 2;
                            if (tmpRedisplayTYY >= 0) {
                                tmpRedisplayTYY = 0;
                                printf("tmpRedisplayTYY >= 0\n");
                            }


                        }

                    }
                }


            }


            if (direccao == ZZ) {
                printf("ZZ tmpRedisplayTZZ = %f\n", tmpRedisplayTZZ);
                posicaoFinal = PecasPuzzle[pecaSelec]->translacao[2] + CUBO_SIZE;
                if (posicaoFinal >= LIM_MAX_Z) posicaoFinal = LIM_MAX_Z;
                if (tmpRedisplayTZZ > 0) {
                    printf("tmpRedisplayTZZ>0 - %d\n", tmpRedisplayTZZ);

                    PecasPuzzle[pecaSelec]->translacao[2] += VEL_TRANSLACAO * posTraModelo;

                    if (PecasPuzzle[pecaSelec]->translacao[2] >= LIM_MAX_Z) {
                        PecasPuzzle[pecaSelec]->translacao[2] = LIM_MAX_Z;
                    }
                    if (PecasPuzzle[pecaSelec]->translacao[2] >= posicaoFinal) {
                        tmpRedisplayTZZ = 0;
                        PecasPuzzle[pecaSelec]->translacao[2] = posicaoFinal;


                    } else {

                        printf("tmpRedisplayTZZ -= VEL_TRANSLACAO * posTraModelo;\n");
                        tmpRedisplayTZZ -= (VEL_TRANSLACAO * posTraModelo) / 2;
                        if (tmpRedisplayTZZ <= 0) {
                            tmpRedisplayTZZ = 0;
                            printf("tmpRedisplayTYY <= 0\n");
                        }


                    }

                }
            } else {
                if (direccao == Zz) {
                    printf("Zz tmpRedisplayTZZ = %f\n", tmpRedisplayTZZ);
                    posicaoFinal = PecasPuzzle[pecaSelec]->translacao[2] - CUBO_SIZE;
                    if (posicaoFinal <= LIM_MIN_Z) posicaoFinal = LIM_MIN_Z;
                    if (tmpRedisplayTZZ < 0) {
                        printf("tmpRedisplayTZZ<0 - %d\n", tmpRedisplayTZZ);

                        PecasPuzzle[pecaSelec]->translacao[2] -= VEL_TRANSLACAO * posTraModelo;

                        if (PecasPuzzle[pecaSelec]->translacao[2] < LIM_MIN_Z) {

                            PecasPuzzle[pecaSelec]->translacao[2] = LIM_MIN_Z;
                        }
                        if (PecasPuzzle[pecaSelec]->translacao[2] <= posicaoFinal) {

                            tmpRedisplayTZZ = 0;
                            PecasPuzzle[pecaSelec]->translacao[2] = posicaoFinal;


                        } else {

                            printf("tmpRedisplayTZZ += VEL_TRANSLACAO * posTraModelo;\n");
                            tmpRedisplayTZZ += (VEL_TRANSLACAO * posTraModelo) / 2;
                            if (tmpRedisplayTZZ >= 0) {
                                tmpRedisplayTZZ = 0;
                                printf("tmpRedisplayTZZ >= 0\n");
                            }


                        }

                    }
                }
            }



            if (tmpRedisplayRXX == 0 && tmpRedisplayRYY == 0 && tmpRedisplayRZZ == 0
                    && tmpRedisplayTXX == 0 && tmpRedisplayTYY == 0 && tmpRedisplayTZZ == 0) {
                if (verificaPuzzleCompleto() == 0) {
                    printf(">Cubo incompleto, continue a tentar :P\n");
                } else {
                    printf(">Parabens!!! Vamos la ver se isto muda de nivel!\n");
                }
            }


        } else {
            printf("Tipo Errado\nNem é Rotaçao, nem Translação!!\n");
        }

    }


    //tmpRedisplay=flagRedisplay;

    //    return flagRedisplay;
}

/* Função que vai ler um ficheiro e retornar as peças existentes no puzzle */
int lePecasDoNivel(int nivel) {
    //Total de peças no Nivel | i | Estado Actual da Leitura do ficheiro (Ler cabeçalho, Ler bloco de referencia, Ler restantes blocos) | Contador de linhas lidas em cada estado/bloco
    int totalPecas = 0, i = 0, estado = 0, lnCnt = 0;
    FILE * ficheiroNivel;
    char linha[MAX_LINE_SIZE];
    char * linhaDividida; //Usada no split de cada uma das linhas
    char *palavra[MAX_PALAVRAS_LINHA]; //Usado no split para apanhar cada uma das palavras
    char ficheiro[200] = ""; //Nome do ficheiro ==> PATCH_FILES + "Nivel" + nivel + ".niv"

    printf("lePecasDoNivel()\n");
    if (nivel < MIN_LEVELS || nivel > MAX_LEVELS) {
        printf("\n\nO nivel seleccionado está fora dos valores validos!\nNIVEL = %d\nLimites permitidos=[%d,%d]\n\n", nivel, MIN_LEVELS, MAX_LEVELS);
    } else {
        strcat(ficheiro, PATH_FILES);
        strcat(ficheiro, "Nivel0");
        strcat(ficheiro, ".niv");

        ficheiro[strlen(PATH_FILES) + strlen("Nivel")] = ('0' + nivel);

        printf("Abrindo ficheiro '");
        printf("%s", ficheiro);
        printf("'.\n");

        if ((ficheiroNivel = fopen(ficheiro, "r")) == NULL) {
            printf("Deu cócó ao tentar abrir o ficheiro '%s'!\n", (char*) ficheiro);
            return 1;
        } else {
            printf("Ficheiro 'Abrido' :)\n");
        }

        while (fgets(linha, MAX_LINE_SIZE, ficheiroNivel)) {
            //printf("len(linha)=%d\n", strlen(linha));
            if (linha[0] == '#') {
                printf("Ignorado Comentário: %s\n", linha);
            } else {

                if (strlen(linha) == 1) { //Linha vazia
                    printf("+Velho estado %d\n", estado);
                    estado++;
                    lnCnt = 0;
                    printf("+Novo estado %d\n", estado);
                } else {
                    printf("%s", linha);

                    i = 0;
                    if (estado == 0) {
                        printf(">ESTADO %d: Estou a ler os parametros iniciais\n", estado);
                        printf(" Lendo Linha %d\n", lnCnt);

                        linhaDividida = strtok(linha, " ");
                        while (linhaDividida != NULL) {
                            palavra[i] = linhaDividida;
                            linhaDividida = strtok(NULL, " ");
                            i++;
                        }

                        //Se estiver a lr a primeira linha (Numero de peças)
                        if (lnCnt == 0) {
                            totalPecas = atoi(palavra[0]);
                            printf("Numero de Peças:%d - '%s'\n", totalPecas, palavra[0]);
                            printf("ArrayPecas pecas = criarArrayPecas(%d); OK.\n", totalPecas);
                            TodasPecas = criarArrayPecas(totalPecas);
                        } else { //Se estiver a ler as restantes linhas do promeiro bloco de linhas,
                            //Significa que está a ler o numero de cubos que cada uma das peças tem.
                            printf("A peca %d tem %d=atoid(%s) cubos\n", lnCnt, atoi(palavra[0]), palavra[0]);
                            ///////////&&&&&&&&&&&
                            TodasPecas->listaPecas[lnCnt - 1] = criarPeca(atoi(palavra[0]));
                            //int pp=-99;
                            //pp=(int)pecas->listaPecas[0]->numCubos;
                        }

                    }
                    if (estado >= 1) {
                        //printf(">ESTADO %d: Estou a ler o xyz do primeiro bloco\n", estado);

                        linhaDividida = strtok(linha, " ");
                        while (linhaDividida != NULL) {
                            palavra[i] = linhaDividida;
                            linhaDividida = strtok(NULL, " ");
                            i++;
                        }
                        if (lnCnt == 0) {
                            printf("Estou a definir a peça %d centrada em %d, %d, %d\n", estado - 1, atoi(palavra[0]), atoi(palavra[1]), atoi(palavra[2]));
                            TodasPecas->listaPecas[estado - 1]->coordCuboPrinc = criaVertice(atoi(palavra[0]), atoi(palavra[1]), atoi(palavra[2]));
                        } else {
                            printf("CR %d: X:%s, Y:%s, Z:%s\n", estado, palavra[0], palavra[1], palavra[2]);
                            printf("Coordenada Relativa com indice %d\n", lnCnt - 1);
                            TodasPecas->listaPecas[estado - 1]->coordOutrosCubos[lnCnt - 1] = criaVertice(atoi(palavra[0]), atoi(palavra[1]), atoi(palavra[2]));
                        }

                    }
                    if (estado >= 9999 || lnCnt >= 9999) {
                        printf("> Uiii, ui... Estado ou lnCnt >=9999, isto ja deve ter estourado.... Vou-me desligar...\n\nCom licença...\n\n");
                        exit(1);
                    }
                    lnCnt++;
                }
            }
        }
        fclose(ficheiroNivel);
        ficheiroNivel = NULL;
        free(ficheiroNivel);
        return 0;
    }
}




