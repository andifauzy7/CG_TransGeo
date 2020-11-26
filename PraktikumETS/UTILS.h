#ifndef UTILS_H
#define UTILS_H
#include <math.h>
#define PI 3.14159265
#define SIN(x) sin(x * (PI / 180))
#define COS(x) cos(x * (PI / 180))
#include<stdio.h>
#define WIDTH 750
#define HEIGHT 750

void screenToCartesian(double *x, double *y);

void cartesianToScreen(double *x, double *y);

void matricsMultiplication(double oriMatrix[1][3], double transMatrix[3][3], double result[1][3]);

void translation(double *x1, double *y1, double transX, double transY);

void scaling(double *x1, double *y1, double scaleX, double scaleY);

void rotation(double *x1, double *y1, int a, int b, int degree);

#endif
