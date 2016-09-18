#include<math.h>
#include "plotDraw.cpp"
void pointGen(float out[][2], double (*fn)(double), float x1, float x2, int num, float tfact = 0.0, float xfact=1.0);
void add(float sum[][2], float ar1[][2], float ar2[][2], int);
int subnum = -1;
int graphindx = 2;
int graphindy = 1;
subplot s[2][1];

int resNum = 1000; //number of points in a plot(max 2000)
float arr[5][2000][2];

void preGLConsole(){
    ;
}

void staticDraw(){
    s[0][0].setRange(-2, 3, -1.2, 1.2);
    s[0][0].drawAxis();
    glColor3f(1, 0, 0);
    pointGen(arr[0], sin, -2, 3, resNum, 1);
    s[0][0].drawPlot(arr[0]);
    glColor3f(0, 1, 0);
    pointGen(arr[1], cos, -2, 3, resNum, -1);
    s[0][0].drawPlot(arr[1]);




    s[1][0].setRange(-0.1, 10, -5, 5);
    s[1][0].drawAxis();
    glColor3f(0, 1, 0);
    pointGen(arr[0], cos, 0, 10, resNum, 0, -1);
    s[1][0].drawPlot(arr[0]);
    glColor3f(0, 0, 1);
    pointGen(arr[1], cos, 0, 10, resNum, 2);
    s[1][0].drawPlot(arr[1]);
    glColor3f(0, 0, 1);
    add(arr[2], arr[1], arr[0], resNum);
    s[1][0].drawPlot(arr[2]);
}
