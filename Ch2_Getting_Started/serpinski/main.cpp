
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void displayFunc();

void drawDot(GLint, GLint);

void sierpinski();

typedef struct GLintPoint {
    GLint x;
    GLint y;
} GLintPoint;


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("OpenGL UT Template");

    glutDisplayFunc(displayFunc);

    init();

    glutMainLoop();

    return 0;
}


void displayFunc() {
    glClear(GL_COLOR_BUFFER_BIT);

    sierpinski();

    glFlush();
}



void drawDot(GLint x, GLint y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}


void sierpinski() {
    GLintPoint T[3] = {{100, 100}, {300, 400}, {500, 100}};

    int index = rand() % 3;
    GLintPoint point = T[index];
    drawDot(point.x, point.y);

    for(int i = 0; i < 5000; i++) {
        index = rand() % 3;
        point.x = (point.x + T[index].x) / 2;
        point.y = (point.y + T[index].y) / 2;

        drawDot(point.x, point.y);
    }
}

