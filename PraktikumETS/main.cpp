#include "STROKE.h"
#include "SHAPE.h"
#include "UTILS.h"
#define BACKGROUND BLACK

void animateCircle(double x1, double y1, int radius){
    int i, rotasi = 0, iteration = 3;
    // ROTASI LINGKARAN.
    cartesianToScreen(&x1,&y1);
    i = 0;
    while(rotasi<iteration){
        drawCircle(x1,y1,i,1,RED,GREEN,BLUE,YELLOW);
        swapbuffers();
        cleardevice();
        i++;
        if(i==radius){
            rotasi++;
            i=0;
        }
    }

    int j = radius;
    while(j>=0){
        drawCircle(x1,y1,j,1,RED,GREEN,BLUE,YELLOW);
        swapbuffers();
        j--;
    }

    j = 0;
    while(j<=radius){
        drawCircle(x1,y1,j,1,LIGHTBLUE,LIGHTBLUE,LIGHTBLUE,LIGHTBLUE);
        swapbuffers();
        j++;
    }

    j = 0;
    while(j<=radius){
        drawCircle(x1,y1,j,1,BACKGROUND,BACKGROUND,BACKGROUND,BACKGROUND);
        swapbuffers();
        j++;
    }

    j = 0;
    while(j<=radius){
        drawCircle(x1,y1,j,1,BACKGROUND,BACKGROUND,BACKGROUND,BACKGROUND);
        swapbuffers();
        j++;
    }
}

void animateLine(double x1, double y1, double x2, double y2){
    // GARIS MEMUTAR.
    int i, rotasi, iteration = 3;
    cartesianToScreen(&x1,&y1);
    cartesianToScreen(&x2,&y2);
    rotasi = 0;
    i = 0;
    while(rotasi<iteration){
        screenToCartesian(&x1,&y1);
        screenToCartesian(&x2,&y2);
        rotation(&x1,&y1,0,0,1);
        rotation(&x2,&y2,0,0,1);
        cartesianToScreen(&x1,&y1);
        cartesianToScreen(&x2,&y2);
        drawLine(x1,y1,x2,y2,1,LIGHTBLUE,1);
        swapbuffers();
        cleardevice();
        i++;
        if(i == 360){
            rotasi++;
            i = 0;
        }
    }

    // GARIS MEMUTAR GANTI WARNA
    rotasi = 0;
    iteration = 3;
    while(rotasi<iteration){
        screenToCartesian(&x1,&y1);
        screenToCartesian(&x2,&y2);
        rotation(&x1,&y1,0,0,1);
        rotation(&x2,&y2,0,0,1);
        cartesianToScreen(&x1,&y1);
        cartesianToScreen(&x2,&y2);
        if(rotasi == iteration-1){
            drawLine(x1,y1,x2,y2,1,BLACK,1);
        } else {
            drawLine(x1,y1,x2,y2,1,rotasi+1,1);
        }
        swapbuffers();
        i++;
        if(i == 360){
            rotasi++;
            i = 0;
        }
    }
}

void animateStar(double x1, double y1, double length){
    double x2 = length+x1;
    double y2 = y1;
    drawCircle(x1,y1,10,10,LIGHTCYAN,LIGHTCYAN,LIGHTCYAN,LIGHTCYAN);

    int i = 0;
    while(i<360/60){
        screenToCartesian(&x1,&y1);
        screenToCartesian(&x2,&y2);
        rotation(&x1,&y1,x1,y1,60);
        rotation(&x2,&y2,x1,y1,60);
        cartesianToScreen(&x1,&y1);
        cartesianToScreen(&x2,&y2);
        drawLine(x1,y1,x2,y2,1,LIGHTBLUE,1);
        drawCircle(x2,y2,10,1,YELLOW,YELLOW,YELLOW,YELLOW);
        i++;
    }

}

void animatePersegi(int a, int b, int colors){
    int i = 0;
    while(i<550){
        persegiRotation(a,b,i,colors,0,0,i);
        i = i + 10;
    }
}

void animatePola(){
    double x1 = 200;
    double y1 = 0;
    double x2 = 200;
    double y2 = 0;
    double length = 50;
    cartesianToScreen(&x1,&y1);
    cartesianToScreen(&x2,&y2);
    int i = 0;
    int rotasi = 1;
    while(rotasi < 2){
        persegiRotation(375,375,500,LIGHTGREEN,0,0,45);
        screenToCartesian(&x1,&y1);
        rotation(&x1,&y1,0,0,1);
        cartesianToScreen(&x1,&y1);
        animateStar(x1,y1,length);
        swapbuffers();
        cleardevice();
        if(i>=360){
            i=0;
            rotasi++;
        } else if(i>90 && i<180){
            animateStar(100,100,50);
        } else if(i>180 && i<270){
            animateStar(100,650,50);
        } else if(i>270 && i<360){
            animateStar(650,650,50);
        } else if(i>0 && i<90){
            animateStar(650,100,50);
        }
        i++;
    }
    cleardevice();
    i = 0;
    while(i<50){
        persegiRotation(375,375,400 - 10,LIGHTGREEN,0,0,i);
        i++;
    }
    x1 = x2 = 375;
    drawCircle(375,375,50,5,LIGHTBLUE,LIGHTBLUE,LIGHTBLUE,LIGHTBLUE);
    animateStar(500,375,50);
    animateStar(250,375,50);
    animateStar(375,500,50);
    animateStar(375,250,50);

    animateStar(100,100,50);
    animateStar(100,650,50);
    animateStar(650,650,50);
    animateStar(650,100,50);
    swapbuffers();
}

int main(){
    initwindow(WIDTH,HEIGHT,"Tugas 5 Praktikum CG");
    setbkcolor(BACKGROUND);
    double x1 = 0;
    double y1 = 0;
    double x2 = 200;
    double y2 = 0;


    animatePersegi(375,375,LIGHTGREEN);
    animateLine(x1,y1,x2,y2);
    animateCircle(x1,y1,200);
    animatePola();



    getch();
    return 0;
}
