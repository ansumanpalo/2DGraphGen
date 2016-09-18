#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
#include<iostream>

extern int subnum;
extern int resNum;
extern int graphindx, graphindy;

class subplot{
    int xpos, ypos;
    float scalex, scaley;
    float xorig, yorig;

    static void init(){
        subnum++;
    }

    void vertex(float x, float y){
        x=x*scalex + xorig;
        y=y*scaley + yorig;
        glVertex2f(x, y);
    }

public:
    subplot(){
        init();
        xorig = xpos = subnum/graphindy;
        yorig = ypos = graphindy - subnum%graphindy -1;
        scalex = scaley = 1.0;
    }

    void drawAxis(){
        glColor3f(0, 0, 0);
        glLineWidth(2);
        glBegin(GL_LINES);
        glVertex2f(xpos, yorig);
        glVertex2f(xpos+1, yorig);
        glVertex2f(xorig, ypos);
        glVertex2f(xorig, ypos+1);
        glEnd();
        glLineWidth(1);
    }

    void setRange(float xmin, float xmax, float ymin, float ymax){
        scalex = 1.0f/(xmax - xmin);
        xorig = -1.0 * scalex * xmin + xpos;
        scaley = 1.0f/(ymax - ymin);
        yorig = -1.0 * scaley * ymin + ypos;
        drawAxis();
    }

    void drawPlot(float arr[][2], int num = resNum){
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<num; i++) vertex(arr[i][0], arr[i][1]);
        glEnd();
    }
};
