#include "UTILS.h"
#include "STROKE.h"
#include "SHAPE.h"

void screenToCartesian(double *x, double *y){
    *x = *x - (WIDTH / 2);
    *y = -1*(*y) + (HEIGHT/2);
}

void cartesianToScreen(double *x, double *y){
    *x = *x + (WIDTH / 2);
    *y = -1*(*y) + (HEIGHT/2);
}

void matricsMultiplication(double oriMatrix[1][3], double transMatrix[3][3], double result[1][3]){

    int i = 0;
    for(int j = 0; j < 3; j++){
        result[i][j] = 0;
        for(int k = 0; k < 3; k++){
            result[i][j] += oriMatrix[i][k] * transMatrix[k][j];
        }
    }
}

void translation(double *x1, double *y1, double transX, double transY){

    double oriMatrix1[1][3] = { {*x1, *y1, 1} };
    double result1[1][3];
    double transMatrix[3][3] = { {1, 0, 0}, {0, 1, 0}, {transX, transY, 1} };
    matricsMultiplication(oriMatrix1, transMatrix, result1);
    *x1 = result1[0][0];
    *y1 = result1[0][1];
}

void scaling(double *x1, double *y1, double scaleX, double scaleY){

    double oriMatrix1[1][3] = { {*x1, *y1, 1} };
    double result1[1][3];
    double transMatrix[3][3] = { {scaleX, 0, 0}, {0, scaleY, 0}, {0, 0, 1} };
    matricsMultiplication(oriMatrix1, transMatrix, result1);
    *x1 = result1[0][0];
    *y1 = result1[0][1];
}

void rotation(double *x1, double *y1, int a, int b, int degree){

    double oriMatrix1[1][3] = { {*x1 - a, *y1 - b, 1} };
    double result1[1][3];
    double transMatrix[3][3] = { {COS(degree), SIN(degree), 0}, {-1*SIN(degree), COS(degree), 0}, {0, 0, 1} };
    matricsMultiplication(oriMatrix1, transMatrix, result1);
    *x1 = result1[0][0] + a;
    *y1 = result1[0][1] + b;
}
