#include "SHAPE.h"
#include "STROKE.h"
#include "UTILS.h"

void segitigaSamaSisi(double x, double y, double sisi){
    double tinggi = sisi*1/2*sqrt(3);
    drawLine(x,y,x+sisi,y,1,LIGHTRED,1);
    drawLine(x,y,x+(sisi/2),y-tinggi,1,LIGHTRED,1);
    drawLine(x+(sisi/2),y-tinggi,x+sisi,y,1,LIGHTRED,1);
}

void belahKetupat(double x, double y, double sisi){
    double tinggi = sisi*1/2*sqrt(3);
    drawLine(x,y,x+(sisi/2),y-tinggi,1,LIGHTRED,1);
    drawLine(x+(sisi/2),y-tinggi,x+sisi,y,1,LIGHTRED,1);
    drawLine(x,y,x+(sisi/2),y+tinggi,1,LIGHTRED,1);
    drawLine(x+(sisi/2),y+tinggi,x+sisi,y,1,LIGHTRED,1);
}

void persegi(int X0, int Y0, int sisi, int color){
    double bagianSisi = sisi/2;
    double x1 = X0-bagianSisi;          double y1 = Y0-bagianSisi;
    double x2 = X0+bagianSisi;          double y2 = Y0-bagianSisi;
    double x3 = X0-bagianSisi;          double y3 = Y0+bagianSisi;
    double x4 = X0+bagianSisi;          double y4 = Y0+bagianSisi;
    drawLine(x1, y1, x2, y2, 1, color, 1);
    drawLine(x1, y1, x3, y3, 1, color, 1);
    drawLine(x2, y2, x4, y4, 1, color, 1);
    drawLine(x3, y3, x4, y4, 1, color, 1);
}

void persegiRotation(int X0, int Y0, int sisi, int color, int a, int b, int degree){
    double bagianSisi = sisi/2;
    double x1 = X0-bagianSisi;          double y1 = Y0-bagianSisi;
    double x2 = X0+bagianSisi;          double y2 = Y0-bagianSisi;
    double x3 = X0-bagianSisi;          double y3 = Y0+bagianSisi;
    double x4 = X0+bagianSisi;          double y4 = Y0+bagianSisi;
    screenToCartesian(&x1,&y1);
    screenToCartesian(&x2,&y2);
    screenToCartesian(&x3,&y3);
    screenToCartesian(&x4,&y4);
    rotation(&x1,&y1,a,b,degree);
    rotation(&x2,&y2,a,b,degree);
    rotation(&x3,&y3,a,b,degree);
    rotation(&x4,&y4,a,b,degree);
    cartesianToScreen(&x1,&y1);
    cartesianToScreen(&x2,&y2);
    cartesianToScreen(&x3,&y3);
    cartesianToScreen(&x4,&y4);
    drawLine(x1, y1, x2, y2, 1, color, 1);
    drawLine(x1, y1, x3, y3, 1, color, 1);
    drawLine(x2, y2, x4, y4, 1, color, 1);
    drawLine(x3, y3, x4, y4, 1, color, 1);
}

void persegiPanjang(int X0, int Y0, int panjang, int lebar){
    drawLine(X0,Y0,X0+panjang,Y0);
    drawLine(X0,Y0,X0,Y0+lebar);
    drawLine(X0+panjang,Y0,X0+panjang,Y0+lebar);
    drawLine(X0,Y0+lebar,X0+panjang,Y0+lebar);
}

void jajaranGenjang(int X0, int Y0, int sisi){
    drawLine(X0+100,Y0,X0+sisi+100,Y0);
    drawLine(X0,Y0+150,X0+sisi,Y0+150);
    drawLine(X0+100,Y0,X0,Y0+150);
    drawLine(X0+sisi+100,Y0,X0+sisi,Y0+150);
}

void trapesium(int X0, int Y0, int alasBawah, int alasAtas, int tinggi){
    // Persegi
    drawLine(X0+(alasBawah-alasAtas)/2,Y0,X0+(alasBawah-alasAtas)/2 + alasAtas,Y0);
    drawLine(X0,Y0+tinggi,X0+alasBawah,Y0+tinggi);

    // Segitiga
    drawLine(X0,Y0+tinggi,X0+(alasBawah-alasAtas)/2,Y0);
    drawLine(X0+(alasBawah-alasAtas)/2 + alasAtas,Y0,X0+alasBawah,Y0+tinggi);
}

void segitigaSiku(int X0, int Y0, int alas, int tinggi){
    drawLine(X0,Y0,X0,Y0+tinggi);
    drawLine(X0,Y0+tinggi,X0+alas,Y0+tinggi);
    drawLine(X0,Y0,X0+alas,Y0+tinggi);
}

void midPointCircleDraw(int x_centre, int y_centre, int r, int color1, int color2, int color3, int color4){
    int x = r, y = 0;
    putpixel(x_centre + r, y_centre, color1);
    putpixel(x_centre - r, y_centre, color1);
    putpixel(x_centre, y_centre + r, color1);
    putpixel(x_centre, y_centre - r, color1);

    // Initialising the value of P
    int P = 1 - r;

    while (x > y){
        y++;

        // Mid-point is inside or on the perimeter
        if (P <= 0)
            P = P + 2*y + 1;

        // Mid-point is outside the perimeter
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }

        // All the perimeter points have already been printed
        if (x < y)
            break;

        // Printing the generated point and its reflection
        // in the other octants after translation
        putpixel(x + x_centre, y + y_centre, color1);
        putpixel(-x + x_centre, y + y_centre, color2);
        putpixel(x + x_centre, -y + y_centre, color2);
        putpixel(-x + x_centre, -y + y_centre, color1);

        // If the generated point is on the line x = y then
        // the perimeter points have already been printed
        if (x != y)
        {
            putpixel(-y + x_centre, x + y_centre, color3);
            putpixel(y + x_centre, x + y_centre, color4);
            putpixel(y + x_centre, -x + y_centre, color3);
            putpixel(-y + x_centre, -x + y_centre, color4);
        }
    }
}

void drawCircle(int x_centre, int y_centre, int r, int width, int color1, int color2, int color3, int color4){
    int i = 0;
    while(i<width){
        midPointCircleDraw(x_centre, y_centre, r-i, color1, color2, color3, color4);
        i++;
    }
}

void midptellipse(int rx, int ry, int xc, int yc) {

    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry)
         - (rx * rx * ry)
         + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy) {

        // Print points based on 4-way symmetry
        putpixel(x + xc, y + yc, LIGHTBLUE);
        putpixel(-x + xc, y + yc, LIGHTBLUE);
        putpixel(x + xc, -y + yc, LIGHTBLUE);
        putpixel(-x + xc, -y + yc, LIGHTBLUE);

        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
         + ((rx * rx) * ((y - 1) * (y - 1)))
         - (rx * rx * ry * ry);

    // Plotting points of region 2
    while (y >= 0) {

        // printing points based on 4-way symmetry
        putpixel(x + xc, y + yc, LIGHTBLUE);
        putpixel(-x + xc, y + yc, LIGHTBLUE);
        putpixel(x + xc, -y + yc, LIGHTBLUE);
        putpixel(-x + xc, -y + yc, LIGHTBLUE);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}
