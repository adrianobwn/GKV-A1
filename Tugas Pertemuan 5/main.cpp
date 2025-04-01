#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

GLfloat xRotation = 0.0f;
GLfloat yRotation = 0.0f;

int lastX = 0;
int lastY = 0;
bool mouseDown = false;

void drawSphere(GLfloat radius, GLint slices, GLint stacks) {
    GLUquadricObj *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    gluSphere(quadric, radius, slices, stacks);
    gluDeleteQuadric(quadric);
}

void drawCylinder(GLfloat baseRadius, GLfloat topRadius, GLfloat height, GLint slices, GLint stacks) {
    GLUquadricObj *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    gluCylinder(quadric, baseRadius, topRadius, height, slices, stacks);
    gluDeleteQuadric(quadric);
}

void drawSnowman() {
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    drawSphere(0.6f, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.8f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawSphere(0.4f, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.35f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawSphere(0.25f, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.35f, 0.25f);
    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
    drawCylinder(0.05f, 0.0f, 0.3f, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.1f, 1.42f, 0.2f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawSphere(0.03f, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1f, 1.42f, 0.2f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawSphere(0.03f, 10, 10);
    glPopMatrix();
    
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(0.0f, 0.6f + i * 0.15f, 0.4f);
        glColor3f(0.0f, 0.0f, 0.0f); drawSphere(0.03f, 10, 10);
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(0.4f, 0.9f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.5f, 0.25f, 0.0f);
    drawCylinder(0.03f, 0.02f, 0.4f, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4f, 0.9f, 0.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.5f, 0.25f, 0.0f);
    drawCylinder(0.03f, 0.02f, 0.4f, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.55f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCylinder(0.25f, 0.25f, 0.05f, 20, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.55f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCylinder(0.15f, 0.15f, 0.2f, 20, 2);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(0.0f, 0.5f, 7.0f,
              0.0f, 0.5f, 0.0f,
              0.0f, 1.0f, 0.0f);
    
    glRotatef(xRotation, 1.0f, 0.0f, 0.0f);
    glRotatef(yRotation, 0.0f, 1.0f, 0.0f);
    
    drawSnowman();
    
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouseDown = true;
            lastX = x;
            lastY = y;
        } else if (state == GLUT_UP) {
            mouseDown = false;
        }
    }
}

void motion(int x, int y) {
    if (mouseDown) {
        yRotation += (x - lastX) * 0.5f;
        xRotation += (y - lastY) * 0.5f;
        
        lastX = x;
        lastY = y;
        
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

void init() {
    glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightPosition[] = {1.0f, 1.0f, 1.0f, 0.0f};
    GLfloat lightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat lightDiffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Objek Utama - Snowman");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    
    return 0;
}
