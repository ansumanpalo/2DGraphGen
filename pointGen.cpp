#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#define pi 3.14159

using namespace std;
#include<iostream>

extern float arr[4][2000][2];
extern int num;

double sinc(double x){
    return sin(x)/x;
}

void pointGen(float out[][2], double (*fn)(double), float x1, float x2, int num){
    float t=glutGet(GLUT_ELAPSED_TIME)/1000.0;
    double dx = (x2 - x1)/(num-1);
    double x0=x1;
    for(int i=0; i<num; i++){
        out[i][0] = x0;
        out[i][1] = fn(x0 + 5*t)*9;
        x0+= dx;
    }
}

void populate(){
    pointGen(arr[0], cos, -4*pi, 4*pi, num);
    pointGen(arr[1], sin, -4*pi, 4*pi, num);

}
