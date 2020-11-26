#include "STROKE.h"

int abs (int n){
    return ( (n>0) ? n : ( n * (-1)));
}

void LineFromDDA(double X0, double Y0, double X1, double Y1, int color, int typeLine){
    int dx = X1 - X0;
    int dy = Y1 - Y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    float X = X0;
    float Y = Y0;

    for (int i = 0; i <= steps; i++){
        if(typeLine == 1){
            // Garis.
            putpixel(X,Y, color);
        } else if(typeLine == 2){
            // Titik titik.
            if(i%5==0){
              putpixel (X,Y, color);
            }
        } else if(typeLine == 3){
            // Dashed
            if(i%5!=0){
              putpixel (X,Y, color);
            }
        } else if(typeLine == 4){
            // Dot Dashed.
            if(i%10==0 || i%10==6){
              // Passed
            } else if(i%10==1 || i%10==7){
                putpixel (X,Y, color);
            } else if(i%10==2 || i%10==8){
                putpixel (X,Y, color);
            } else if(i%10==3 || i%10==9){
                putpixel (X,Y, color);
            } else if(i%10==4){
                // Passed
            } else if(i%10==5){
                putpixel (X,Y, color);
            }
        } else {
            // Salah input Tipe.
        }
        X += Xinc;
        Y += Yinc;
    }
}

void drawLine(double X0, double Y0, double X1, double Y1, int width, int color, int typeLine){
    int i = 0;
    while(i<width){
        LineFromDDA(X0,Y0+i,X1,Y1+i, color, typeLine);
        i++;
    }
}
