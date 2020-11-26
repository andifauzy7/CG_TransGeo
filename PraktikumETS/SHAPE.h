#ifndef SHAPE_H
#define SHAPE_H

#include<stdio.h>
#include<graphics.h>
#include <math.h>

void segitigaSamaSisi(double x, double y, double sisi);

void belahKetupat(double x, double y, double sisi);

void persegi(int X0, int Y0, int sisi, int color);

void persegiRotation(int X0, int Y0, int sisi, int color, int a, int b, int degree);

void persegiPanjang(int X0, int Y0, int panjang, int lebar);

void jajaranGenjang(int X0, int Y0, int sisi);

void trapesium(int X0, int Y0, int alasBawah, int alasAtas, int tinggi);

void segitigaSiku(int X0, int Y0, int alas, int tinggi);

void midPointCircleDraw(int x_centre, int y_centre, int r, int color1, int color2, int color3, int color4);

void drawCircle(int x_centre, int y_centre, int r, int width, int color1, int color2, int color3, int color4);

void midptellipse(int rx, int ry, int xc, int yc);
#endif
