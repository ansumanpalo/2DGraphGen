#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void drawGraph();

void render(){
   glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
   drawGraph();
   glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(700, 650);  // Initial window width and height
    glutInitWindowPosition(650, 0); // Initial window top-left corner (x, y)
    glutCreateWindow("Graph");      // Create window with given title
    glutDisplayFunc(render);     // Register callback handler for window re-paint
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
    glutIdleFunc(render);
//   glutReshapeFunc(reshape);     // Register callback handler for window re-shape
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();               // Enter event-processing loop
    return 0;
}
