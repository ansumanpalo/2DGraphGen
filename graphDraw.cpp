#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float arr[4][2000][2];
int num=1000;
void populate();

float scalex=10/15;
float scaley=10/1;

void axisMarker(){
    int ht12 = 0.4;
    glRasterPos2f(0.1,-ht12);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, '0');
//GLUT_BITMAP_8_BY_13
//GLUT_BITMAP_9_BY_15
//GLUT_BITMAP_TIMES_ROMAN_10
//GLUT_BITMAP_TIMES_ROMAN_24
//GLUT_BITMAP_HELVETICA_10
//GLUT_BITMAP_HELVETICA_12
//GLUT_BITMAP_HELVETICA_18
}

void drawAxis(){

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-10, 0);
    glVertex2f(10, 0);
    glVertex2f(0, -10);
    glVertex2f(0, 10);
    glEnd();
}

void plot(float inp[][2]){
    populate();
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<num; i++) glVertex2f(inp[i][0], inp[i][1]);
    glEnd();
}

void drawGraph(){
    drawAxis();
    axisMarker();
//    drawGrid();
    glColor3f(1.0, 0.0, 0.0);
    plot(arr[0]);
    glColor3f(0.0, 1.0, 0.0);
    plot(arr[1]);
}
