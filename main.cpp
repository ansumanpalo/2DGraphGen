#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void preGLConsole();
extern int graphindx, graphindy;
void render();

int main(int argc, char *argv[])
{

    preGLConsole();

    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(700, 650);  // Initial window width and height
    glutInitWindowPosition(650, 0); // Initial window top-left corner (x, y)
    glutCreateWindow("Graph Generator");      // Create window with given title
    glClearColor(1.0, 1.0, 1.0, 1.0);

    gluOrtho2D(0, (GLfloat)graphindx, 0, (GLfloat)graphindy);
    glutIdleFunc(render);
    glutDisplayFunc(render);     // Register callback handler for window re-paint
    glutMainLoop();               // Enter event-processing loop
    return 0;
}
