#ifndef STROKE_H
#define STROKE_H

#include<stdio.h>
#include<graphics.h>

int abs (int n);

void LineFromDDA(double X0, double Y0, double X1, double Y1, int color = 4, int typeLine = 1);

void drawLine(double X0, double Y0, double X1, double Y1, int width = 1, int color = 4, int typeLine = 1);


#endif // ADT_SLL_STR_H
