#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Body Mobil 1
    glPushMatrix();
        glTranslatef(0.0, -0.2, 0.0);  // Posisi
        glColor3f(1.0f, 0.0f, 0.0f);  // Warna Merah
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.6, 0.2, 0.0);  // Titik Kiri Atas
            glVertex3f(0.4, 0.2, 0.0);   // Titik Kanan Atas
            glVertex3f(0.4, -0.2, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.6, -0.2, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
	
	// Body Mobil 2
    glPushMatrix();
        glTranslatef(0.4, -0.2, 0.0);  // Posisi
        glColor3f(1.0f, 0.0f, 0.0f);  // Warna Merah
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(0.0, 0.2, 0.0);  // Titik Kiri Atas
            glVertex3f(0.3, 0.0, 0.0);   // Titik Kanan Atas
            glVertex3f(0.3, -0.2, 0.0);  // Titik Kanan Bawah
            glVertex3f(0.0, -0.2, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Body Mobil 3
    glPushMatrix();
        glTranslatef(0.0, 0.2, 0.0);  // Posisi
        glColor3f(1.0f, 0.0f, 0.0f);  // Warna Merah
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.45, 0.1, 0.0);  // Titik Kiri Atas
            glVertex3f(0.25, 0.1, 0.0);   // Titik Kanan Atas
            glVertex3f(0.4, -0.2, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.6, -0.2, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // jendela Belakang
    glPushMatrix();
        glTranslatef(-0.2, 0.12, 0.0);  // Posisi
        glColor3f(0.6f, 0.8f, 1.0f);  // Warna Biru Muda
        glBegin(GL_QUADS); // Gambar 4 titik
            glVertex3f(-0.2, 0.13, 0.0);  // Titik Kiri Atas
            glVertex3f(0.07, 0.13, 0.0);   // Titik Kanan Atas
            glVertex3f(0.07, -0.1, 0.0);  // Titik Kanan Bawan
            glVertex3f(-0.32, -0.1, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // jendela Depan
    glPushMatrix();
        glTranslatef(0.15, 0.12, 0.0);  // Posisi
        glColor3f(0.6f, 0.8f, 1.0f);  // Warna Biru Muda
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.2, 0.13, 0.0);  // Titik Kiri Atas
            glVertex3f(0.05, 0.13, 0.0);   // Titik Kanan Atas
            glVertex3f(0.16, -0.1, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.2, -0.1, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Gagang Pintu Depan
    glPushMatrix();
        glTranslatef(0.15, -0.04, 0.0);  // Posisi
        glColor3f(0.0f, 0.0f, 0.0f);  // Warna Hitam
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.2, 0.0, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.1, 0.0, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.1, -0.03, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.2, -0.03, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Gagang Pintu Belakang
    glPushMatrix();
        glTranslatef(-0.32, -0.04, 0.0);  // Posisi
        glColor3f(0.0f, 0.0f, 0.0f);  // Warna Hitam
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.2, 0.0, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.1, 0.0, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.1, -0.03, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.2, -0.03, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
	// Ban
    #define PI 3.1415926535898
    GLint circle_points = 100;  // Declare circle points
    float angle;  // Declare angle
    float rotasi_angular = 0.0f;
    
    // Ban Belakang
    glPushMatrix();
        glTranslatef(-0.32, -0.4, 0.0);  // Posisi
        glRotatef(rotasi_angular, 0.0, 0.0, 1.0); // Rotasi
        glColor3f(0.0f, 0.0f, 0.0f);  // Warna Hitam
        glBegin(GL_POLYGON);
            for (int i = 0; i < circle_points; i++) {
                angle = 2 * PI * i / circle_points;
                glVertex2f(0.13 * cos(angle), 0.13 * sin(angle)); // Ukuran Ban
            }
        glEnd();
    glPopMatrix();
    
    // Ban Belakang Dalam
    glPushMatrix();
        glTranslatef(-0.32, -0.4, 0.0);  // Posisi
        glColor3f(0.55f, 0.55f, 0.55f);  // Warna Abu-Abu
        glBegin(GL_POLYGON);
            for (int i = 0; i < circle_points; i++) {
                angle = 2 * PI * i / circle_points;
                glVertex2f(0.06 * cos(angle), 0.06 * sin(angle)); // Ukuran Ban
            }
        glEnd();
    glPopMatrix();

    // Ban Depan
    glPushMatrix();
        glTranslatef(0.4, -0.4, 0.0);  // Posisi
        glRotatef(rotasi_angular, 0.0, 0.0, 1.0); // Rotasi
        glColor3f(0.0f, 0.0f, 0.0f);  // Warna Hitam
        glBegin(GL_POLYGON);
            for (int i = 0; i < circle_points; i++) { 
                angle = 2 * PI * i / circle_points;
                glVertex2f(0.13 * cos(angle), 0.13 * sin(angle)); // Ukuran Ban
            }
        glEnd();
    glPopMatrix();
    
    // Ban Depan Dalam
    glPushMatrix();
        glTranslatef(0.4, -0.4, 0.0);  // Posisi
        glColor3f(0.55f, 0.55f, 0.55f);  // Warna Abu-Abu
        glBegin(GL_POLYGON);
            for (int i = 0; i < circle_points; i++) { 
                angle = 2 * PI * i / circle_points;
                glVertex2f(0.06 * cos(angle), 0.06 * sin(angle)); // Ukuran Ban
            }
        glEnd();
    glPopMatrix();
	
	// Bumper Belakang
    glPushMatrix();
        glTranslatef(0.0, -0.3, 0.0);  // Posisi
        glColor3f(0.0f, 0.0f, 0.0f);  // Warna Hitam
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.64, 0.05, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.5, 0.05, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.5, -0.1, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.64, -0.1, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Bumper Depan
    glPushMatrix();
        glTranslatef(1.2, -0.3, 0.0);  // Posisi
        glColor3f(0.0f, 0.0f, 0.0f);  // Warna Hitam
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.62, 0.02, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.47, 0.02, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.47, -0.1, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.62, -0.1, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Lampu Belakang
    // Tempat Lampu
    glPushMatrix();
        glTranslatef(0.0, -0.15, 0.0);  // Posisi
        glColor3f(0.75f, 0.75f, 0.75f);  // Warna Abu-Abu
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.63, 0.05, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.54, 0.05, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.54, -0.1, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.63, -0.1, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Lampu Rem
    glPushMatrix();
        glTranslatef(0.0, -0.145, 0.0);  // Posisi
        glColor3f(0.8f, 0.0f, 0.0f);  // Warna Merah
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.63, 0.02, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.56, 0.02, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.56, -0.04, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.63, -0.04, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Lampu Retting
    glPushMatrix();
        glTranslatef(0.0, -0.185, 0.0);  // Posisi
        glColor3f(1.0f, 0.9f, 0.0f);  // Warna Kuning
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.63, -0.01, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.56, -0.01, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.56, -0.05, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.63, -0.05, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Lampu Depan
    // Tempat Lampu
    glPushMatrix();
        glTranslatef(1.2, -0.17, 0.0);  // Posisi
        glColor3f(0.75f, 0.75f, 0.75f);  // Warna Abu-Abu
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.53, -0.01, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.47, -0.01, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.47, -0.1, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.62, -0.1, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    // Lampu
    glPushMatrix();
        glTranslatef(1.2, -0.17, 0.0);  // Posisi
        glColor3f(1.0f, 0.9f, 0.0f);  // Warna Kuning
        glBegin(GL_QUADS);  // Gambar 4 titik
            glVertex3f(-0.43, -0.01, 0.0);  // Titik Kiri Atas
            glVertex3f(-0.47, -0.01, 0.0);   // Titik Kanan Atas
            glVertex3f(-0.47, -0.1, 0.0);  // Titik Kanan Bawah
            glVertex3f(-0.43, -0.1, 0.0); // Titik Kiri Bawah
        glEnd();
    glPopMatrix();
    
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 540);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Car with Roof, Windows, and Background");
    glutDisplayFunc(RenderScene);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // Set background to blue
    glutMainLoop();
    return 0;
}

