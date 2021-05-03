#include <GL/glut.h>
#include <iostream>

float angle = -45;
float xScale = 1, yScale = 1, zAngle = 0;

void rotateFunc(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_RIGHT:
        angle += 1;
        if (angle > 360)
            angle = 0.0;
        break;
    case GLUT_KEY_LEFT:
        angle -= 1;
        if (angle < -360)
            angle = 0.0;
        break;
    case GLUT_KEY_DOWN:
        if (xScale > 0.7)
        {
            xScale -= 0.01;
            yScale -= 0.01;
        }
        break;
    case GLUT_KEY_UP:
        if (xScale < 1.5)
        {
            xScale += 0.01;
            yScale += 0.01;
        }
        break;
    }
    glutPostRedisplay();
}

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// sekillere rotate ve scale transformu uygulamayı saglar.
// her cizimden once tekrar cagrilmali.
void registerTransform()
{
    glRotatef(angle, 0, 1, 0);
    glScalef(xScale, yScale, 1);
}

void surface()
{
    glLoadIdentity();

    // simulasyon yuzeyi, acik yesil.
    glTranslatef(0, 0, -6);
    glColor3f(0.56, .93, 0.56);
    registerTransform();
    glBegin(GL_QUADS);
    glVertex3f(-40, -1, 50);
    glVertex3f(-40, -1, -50);
    glVertex3f(40, -1, -50);
    glVertex3f(40, -1, 50);
    glEnd();
}

void homeBody()
{
    glLoadIdentity();

    // evin iskeleti, dikdortgenler prizması
    glColor3f(0.2f, 0.1f, 0.03); // kahverengi
    glTranslatef(0, 0.0f, -6.0f);
    registerTransform();
    glBegin(GL_QUADS);

    // prizma icin 6 farkli yuzey
    glVertex3f(1.0f, 1.0f, -2.0f);
    glVertex3f(-1.0f, 1.0f, -2.0f);
    glVertex3f(-1.0f, 1.0f, 2.0f);
    glVertex3f(1.0f, 1.0f, 2.0f);

    glVertex3f(1.0f, -1.0f, 2.0f);
    glVertex3f(-1.0f, -1.0f, 2.0f);
    glVertex3f(-1.0f, -1.0f, -2.0f);
    glVertex3f(1.0f, -1.0f, -2.0f);

    glVertex3f(1.0f, 1.0f, 2.0f);
    glVertex3f(-1.0f, 1.0f, 2.0f);
    glVertex3f(-1.0f, -1.0f, 2.0f);
    glVertex3f(1.0f, -1.0f, 2.0f);

    glVertex3f(1.0f, -1.0f, -2.0f);
    glVertex3f(-1.0f, -1.0f, -2.0f);
    glVertex3f(-1.0f, 1.0f, -2.0f);
    glVertex3f(1.0f, 1.0f, -2.0f);

    glVertex3f(-1.0f, 1.0f, 2.0f);
    glVertex3f(-1.0f, 1.0f, -2.0f);
    glVertex3f(-1.0f, -1.0f, -2.0f);
    glVertex3f(-1.0f, -1.0f, 2.0f);

    glVertex3f(1.0f, 1.0f, -2.0f);
    glVertex3f(1.0f, 1.0f, 2.0f);
    glVertex3f(1.0f, -1.0f, 2.0f);
    glVertex3f(1.0f, -1.0f, -2.0f);
    glEnd();

    glTranslatef(0, 0, -6);
    glColor3f(0.9f, 0.2f, 0.5); // kahverengi
    registerTransform();
    glBegin(GL_TRIANGLES);
    glVertex3f(2, 0, 1.1);
    glVertex3f(1.9, .8, 0);

    glVertex3f(2, 0, -1.1);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // kamerayi evi ortalayacak konuma getir
    glTranslatef(-4.0f, 0, 4.0f);

    surface();
    homeBody();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(2000, 100);
    glutInitWindowSize(1600, 900);
    glutCreateWindow("3B EV");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(rotateFunc);
    glutMainLoop();
    return 0;
}