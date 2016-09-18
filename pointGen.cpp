#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#define pi 3.14159

using namespace std;
#include<iostream>

void pointGen(float out[][2], double (*fn)(double), float x1, float x2, int num, float tfact = 0.0, float xfact=1.0){
    float t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    double dx = (x2 - x1)/(num-1);
    double x0=x1;
    for(int i=0; i<num; i++){
        out[i][0] = x0;
        out[i][1] = fn(xfact*x0-tfact*t);
        x0+= dx;
    }
}

void add(float sum[][2], float ar1[][2], float ar2[][2], int num){
    for(int i=0; i<num; i++){
        sum[i][0]=ar1[i][0]+ar2[i][0];
        sum[i][1]=ar1[i][1]+ar2[i][1];
    }
}
