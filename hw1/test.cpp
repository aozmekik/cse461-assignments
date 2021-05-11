#include <GL/glut.h>
#include <iostream>

float angle = -45;
float xScale = 1, yScale = 1;
float rotate = 0;

float xTranslate = 0, yTranslate = 0, zTranslate = -6;

void specialKeyHandler(int key, int x, int y)
{
    switch (key)
    {
    // rotating
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

    // scaling
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

void normalKeyHandler(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        zTranslate += 0.1;
        break;
    case 's':
        zTranslate -= 0.1;
        break;
    case 'a':
        xTranslate += 0.1;
        break;
    case 'd':
        xTranslate -= 0.1;
        break;
    case 'q':
        yTranslate += 0.1;
        break;
    case 'e':
        yTranslate -= 0.1;
    }
    glutPostRedisplay();
}

// sekillere rotate ve scale transformu uygulamayı saglar.
// her cizimden once tekrar cagrilmali.
void registerTransform()
{
    glTranslatef(xTranslate, yTranslate, zTranslate);
    glRotatef(angle, 0, 1, rotate);
    glScalef(xScale, yScale, 1);
}

void surface()
{
    // simulasyon yuzeyi, acik yesil.
    glLoadIdentity();
    glColor3f(0.56, .93, 0.56);
    registerTransform();
    glBegin(GL_QUADS);
    glVertex3f(-50, -1, 50);
    glVertex3f(-50, -1, -50);
    glVertex3f(50, -1, -50);
    glVertex3f(50, -1, 50);
    glEnd();
}

void windows()
{
    glColor3f(0.2, 0.5, 0.9);
    glPushMatrix();
    registerTransform();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.4, 0.2);

    glVertex3f(2.01, 0.2, -0.3);
    glVertex3f(2.01, 0.2, 0.4);
    glVertex3f(2.01, -1, 0.4);
    glVertex3f(2.01, -1, -0.3);
    glEnd();
    glPopMatrix();

    glColor3f(0.2, 0.5, 0.9);
    glPushMatrix();
    registerTransform();
    glBegin(GL_QUADS);
    glVertex3f(2.01, 0.2, -1);
    glVertex3f(2.01, 0.2, -1.7);
    glVertex3f(2.01, -0.3, -1.7);
    glVertex3f(2.01, -0.3, -1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    registerTransform();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(2.01, -0.1, -1);
    glVertex3f(2.01, -0.1, -1.7);
    glVertex3f(2.01, -0.2, -1.7);
    glVertex3f(2.01, -0.2, -1);
    glEnd();
    glPopMatrix();

    glColor3f(0.2, 0.5, 0.9);
    glPushMatrix();
    registerTransform();
    glBegin(GL_QUADS);
    glVertex3f(2.01, 0.2, 1.8);
    glVertex3f(2.01, 0.2, 1.1);
    glVertex3f(2.01, -0.3, 1.1);
    glVertex3f(2.01, -0.3, 1.8);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    registerTransform();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(2.01, -0.1, 1.8);
    glVertex3f(2.01, -0.1, 1.1);
    glVertex3f(2.01, -0.2, 1.1);
    glVertex3f(2.01, -0.2, 1.8);
    glEnd();
    glPopMatrix();
}

void chimney()
{
    // baca, dikdörtgenler prizması
    glPushMatrix();
    registerTransform();
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.8);

    glVertex3f(1.5, 1.0, 0);
    glVertex3f(1.5, 1.8, 0);
    glVertex3f(1.5, 1.8, -0.5);
    glVertex3f(1.5, 1.0, -0.5);

    glVertex3f(1, 1.5, -0.5);
    glVertex3f(1, 1.8, -0.5);
    glVertex3f(1, 1.8, 0);
    glVertex3f(1, 1.5, 0);

    glVertex3f(1, 1.0, 0);
    glVertex3f(1.5, 1.0, 0);
    glVertex3f(1.5, 1.8, 0);
    glVertex3f(1, 1.8, 0);

    glVertex3f(1, 1.8, -0.5);
    glVertex3f(1.5, 1.8, -0.5);
    glVertex3f(1.5, 1.0, -0.5);
    glVertex3f(1, 1.0, -0.5);
    glEnd();
    glPopMatrix();
}

void roof()
{
    // evin catisi, icin ucgen prizma
    glColor3f(0.6f, 0.02f, 0.02f); // kahverengi
    glPushMatrix();
    registerTransform();
    glBegin(GL_QUADS);
    glVertex3f(2.0, 1.0, -2.0);
    glVertex3f(1, 1.5, -2.0);
    glColor3f(0.65f, 0.1f, 0.1f);

    glVertex3f(1, 1.5, 2.0);
    glVertex3f(2.0, 1.0, 2.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    registerTransform();
    glBegin(GL_QUADS);
    glVertex3f(0, 1.0, -2.0);
    glVertex3f(1, 1.5, -2.0);
    glColor3f(0.65f, 0.1f, 0.1f);
    glVertex3f(1, 1.5, 2.0);
    glVertex3f(0, 1.0, 2.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    registerTransform();
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 1.0, -2.0);
    glVertex3f(2, 1.0, -2.0);
    glVertex3f(1, 1.5, -2.0);

    glEnd();
    glPopMatrix();
}

void front()
{
    glLoadIdentity();

    // evin iskeleti, dikdortgenler prizması
    glPushMatrix();
    glColor3f(0.2f, 0.1f, 0.03); // kahverengi
    registerTransform();
    glTranslatef(1, 0, 0);
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
    glPopMatrix();
}

void homeBody()
{
    front();
    roof();
    chimney();
    windows();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    surface();
    homeBody();
    // // kamerayi evi ortalayacak konuma getir
    // glTranslatef(0.0f, 0, 10.0f);

    glutSwapBuffers();
}

static void reshape(GLsizei width, GLsizei height)
{
    if (height == 0)
        height = 1;
    const GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-aspect, aspect, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(2000, 100);
    glutInitWindowSize(1600, 900);
    glutCreateWindow("3B EV");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeyHandler);
    glutKeyboardFunc(normalKeyHandler);
    glutMainLoop();
    return 0;
}