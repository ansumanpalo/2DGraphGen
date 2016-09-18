#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

extern int graphindx, graphindy;
void staticDraw();

void drawBorders(){
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int i=1; i<graphindx; i++){ //Vertical
        glVertex2f(i, 0);
        glVertex2f(i, graphindy);
    }
    for(int i=1; i<graphindy; i++){ //Horizontal
        glVertex2f(0, i);
        glVertex2f(graphindx, i);
    }
    glEnd();
    glLineWidth(1);
}

void mainDraw(){
    drawBorders();
    staticDraw();
}

void render(){
   glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
   mainDraw();
   glutSwapBuffers();
}
