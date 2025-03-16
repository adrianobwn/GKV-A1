#include <GL/glut.h>

static int shoulder = 0, elbow = 0, palm = 0, kelingking = 0, manis = 0, tengah = 0, telunjuk = 0, jempol = 0;


void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Set background color to black
    glShadeModel(GL_FLAT);              // Use flat shading
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Bagian pertama: Lengan atas
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Bagian kedua: Lengan bawah
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Bagian ketiga: Telapak Tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) palm, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.4, 1.3);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Jari Pertama (Kelingking)
    glPushMatrix();
    glTranslatef(0.4, 0.0, -0.55);
    glRotatef((GLfloat) kelingking, 0.0, 0.0, 1.0);
	glTranslatef(0.45, 0.0, 0.0);
    glScalef(0.7, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Jari Kedua (Manis)
    glPushMatrix();
    glTranslatef(0.4, 0.0, -0.2);
    glRotatef((GLfloat) manis, 0.0, 0.0, 1.0);
    glTranslatef(0.55, 0.0, 0.0);
    glScalef(0.9, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari Ketiga (Tengah)
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat) tengah, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.15);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari Keempat (Telunjuk)
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.1);
    glRotatef((GLfloat) telunjuk, 0.0, 0.0, 1.0);
    glTranslatef(0.4, 0.0, 0.45);
	glScalef(0.8, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Jari Kelima (Jempol)
    glPushMatrix();
    glTranslatef(-0.3, 0.0, 0.3);
    glRotatef((GLfloat) jempol, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.45);
	glScalef(0.8, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}



void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, (GLfloat) w / (GLfloat) h, 2.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, -5.0, -8.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': // Bagian Pertama : Lengan Atas
            shoulder = (shoulder + 5);
			if (shoulder > 180) shoulder = 180; 
            glutPostRedisplay();
            break;
        case 'S': // Bagian Pertama : Lengan Atas (kembali)
            shoulder = (shoulder - 5);
			if (shoulder < 0) shoulder = 0; 
            glutPostRedisplay();
            break;
        case 'e': // Bagian Kedua : Lengan Bawah
            elbow = (elbow + 5); 
            if (elbow > 135) elbow = 135;
            glutPostRedisplay();
            break;
        case 'E': // Bagian Kedua : Lengan Bawah (kembali)
            elbow = (elbow - 5);
			if (elbow < 0) elbow = 0; 
            glutPostRedisplay();
            break;
        case 'f': // Bagian Ketiga : Telapak Tangan
            palm = (palm + 5);
			if (palm > 90) palm = 90; 
            glutPostRedisplay();
            break;
        case 'F': // Bagian Ketiga : Telapak Tangan (kembali)
            palm = (palm - 5); 
            if (palm < -90) palm = -90;
            glutPostRedisplay();
            break;
        case '1':  // Jari pertama (kelingking)
            kelingking += 5;
            if (kelingking > 90) kelingking = 90;
            glutPostRedisplay();
            break;
        case '!':  // Jari pertama (kelingking) kembali
            kelingking -= 5;
            if (kelingking < 0) kelingking = 0;
            glutPostRedisplay();
            break;
        case '2':  // Jari kedua (manis)
            manis += 5;  
            if (manis > 90) manis = 90;  
            glutPostRedisplay();
            break;
        case '@':  // Jari kedua (manis) kembali
            manis -= 5;  
            if (manis < 0) manis = 0;  
            glutPostRedisplay();
            break;
        case '3':  // Jari ketiga (tengah)
            tengah += 5;  
            if (tengah > 90) tengah = 90;  
            glutPostRedisplay();
            break;
        case '#':  // Jari ketiga (tengah) kembali
            tengah -= 5;  
            if (tengah < 0) tengah = 0;  
            glutPostRedisplay();
            break;
        case '4':  // Jari keempat (telunjuk)
            telunjuk += 5;  
            if (telunjuk > 90) telunjuk = 90;  
            glutPostRedisplay();
            break;
        case '$':  // Jari keempat (telunjuk) kembali
            telunjuk -= 5;  
            if (telunjuk < 0) telunjuk = 0;  
            glutPostRedisplay();
            break;
        case '5':  // Jari keempat (jempol)
            jempol += 5;  
            if (jempol > 90) jempol = 90;  
            glutPostRedisplay();
            break;
        case '%':  // Jari keempat (jempol) kembali
            jempol -= 5;  
            if (jempol < 0) jempol = 0;  
            glutPostRedisplay();
            break;
        case 27:  // Tombol ESC untuk keluar
            exit(0); 
            break;
        default: 
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
