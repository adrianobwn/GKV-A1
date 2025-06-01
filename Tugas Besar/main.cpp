#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// Game state variables
static float snowmanZ = 0.0f;
static float snowmanX = 0.0f;
static float snowmanY = 0.5f;
static float jumpVelocity = 0.0f;
static int slices = 16, stacks = 16;
static int gameOver = 0;
static int shadowEnabled = 1;
static int score = 0; // New: Score based on distance traveled

// Camera variables
static float cameraAngleX = 30.0f;
static float cameraDistance = 10.0f;

// Movement controls
static int moveForward = 0;
static int moveBackward = 0;
static int moveLeft = 0;
static int moveRight = 0;
static const float moveSpeed = 0.1f;

// Obstacle (trees) data
#define MAX_TREES 20
struct Tree {
    float x, z;
    int active;
} trees[MAX_TREES];

// Snow particles
#define MAX_SNOWFLAKES 200
struct Snowflake {
    float x, y, z;
    float vy;
} snowflakes[MAX_SNOWFLAKES];

// Lighting variables (unchanged)
const GLfloat light_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
const GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {0.0f, 5.0f, -5.0f, 1.0f};
const GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};

// Texture variables
GLuint snowTexture, pineTexture, trunkTexture;

// drawSolidCylinder function (unchanged)
void drawSolidCylinder(GLfloat radius, GLfloat height, GLint slices, GLint stacks) {
    const float PI = 3.14159265359f;
    float z, theta;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= stacks; i++) {
        z = height * i / stacks;
        for (int j = 0; j <= slices; j++) {
            theta = 2.0f * PI * j / slices;
            float s = (float)j / slices;
            float t = (float)i / stacks;
            glTexCoord2f(s, t);
            glNormal3f(cos(theta), sin(theta), 0.0f);
            glVertex3f(radius * cos(theta), radius * sin(theta), z);
            t = (float)(i + 1) / stacks;
            glTexCoord2f(s, t);
            glNormal3f(cos(theta), sin(theta), 0.0f);
            glVertex3f(radius * cos(theta), radius * sin(theta), z + height / stacks);
        }
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, height);
    for (int j = 0; j <= slices; j++) {
        theta = 2.0f * PI * j / slices;
        float s = 0.5f + 0.5f * cos(theta);
        float t = 0.5f + 0.5f * sin(theta);
        glTexCoord2f(s, t);
        glVertex3f(radius * cos(theta), radius * sin(theta), height);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    for (int j = slices; j >= 0; j--) {
        theta = 2.0f * PI * j / slices;
        float s = 0.5f + 0.5f * cos(theta);
        float t = 0.5f + 0.5f * sin(theta);
        glTexCoord2f(s, t);
        glVertex3f(radius * cos(theta), radius * sin(theta), 0.0f);
    }
    glEnd();
}

// Initialize snowflakes (unchanged)
void initSnowflakes() {
    for (int i = 0; i < MAX_SNOWFLAKES; i++) {
        snowflakes[i].x = (float)(rand() % 200 - 100) / 10.0f;
        snowflakes[i].y = (float)(rand() % 100) / 10.0f;
        snowflakes[i].z = (float)(rand() % 1000 - 500) / 10.0f;
        snowflakes[i].vy = -0.02f - (float)(rand() % 10) / 1000.0f;
    }
}

// Generate textures (unchanged)
void generateTextures() {
    GLubyte snowData[64][64][3];
    GLubyte pineData[64][64][3];
    GLubyte trunkData[64][64][3];
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            int noise = rand() % 20;
            snowData[i][j][0] = 235 + noise;
            snowData[i][j][1] = 235 + noise;
            snowData[i][j][2] = 235 + noise;
            int variation = (i % 4 < 2) ? 10 : 0;
            pineData[i][j][0] = 34 - variation;
            pineData[i][j][1] = 139 - variation;
            pineData[i][j][2] = 34 - variation;
            int grain = (i % 4 < 2) ? 10 : 0;
            trunkData[i][j][0] = 139 - grain;
            trunkData[i][j][1] = 69 - grain;
            trunkData[i][j][2] = 19 - grain;
        }
    }
    glGenTextures(1, &snowTexture);
    glBindTexture(GL_TEXTURE_2D, snowTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, snowData);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenTextures(1, &pineTexture);
    glBindTexture(GL_TEXTURE_2D, pineTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, pineData);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenTextures(1, &trunkTexture);
    glBindTexture(GL_TEXTURE_2D, trunkTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, trunkData);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

// Initialize trees with more x positions
void initTrees() {
    float xPositions[] = {-4.0f, -2.0f, 0.0f, 2.0f, 4.0f}; // New: More lanes
    for (int i = 0; i < MAX_TREES; i++) {
        trees[i].z = -10.0f - (rand() % 100);
        trees[i].x = xPositions[rand() % 5]; // Randomly select from xPositions
        trees[i].active = 1;
    }
}

// Resize callback (unchanged)
static void resize(int width, int height) {
    const float ar = (float)width / (float)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Check collision with tighter radius
int checkCollision() {
    for (int i = 0; i < MAX_TREES; i++) {
        if (trees[i].active) {
            float dx = snowmanX - trees[i].x;
            float dz = snowmanZ - trees[i].z;
            float distance = sqrt(dx * dx + dz * dz);
            if (distance < 0.7f) return 1; // New: Tighter collision radius
        }
    }
    return 0;
}

// Draw shadow (unchanged)
void drawShadow() {
    glDisable(GL_LIGHTING);
    glColor3f(0.2f, 0.2f, 0.2f);
    glPushMatrix();
    glTranslatef(snowmanX, 0.01f, snowmanZ);
    glScalef(1.0f, 0.0f, 1.0f);
    glutSolidSphere(0.5f, slices, stacks);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glutSolidSphere(0.3f, slices, stacks);
    glPopMatrix();
    for (int i = 0; i < MAX_TREES; i++) {
        if (trees[i].active) {
            glPushMatrix();
            glTranslatef(trees[i].x, 0.01f, trees[i].z);
            glScalef(1.0f, 0.0f, 1.0f);
            glutSolidCone(0.5f, 1.0f, slices, stacks);
            glPopMatrix();
        }
    }
    glEnable(GL_LIGHTING);
}

// Display callback with score display
static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    gluLookAt(
        snowmanX, snowmanY + 2.0f, snowmanZ + cameraDistance,
        snowmanX, snowmanY, snowmanZ,
        0.0f, 1.0f, 0.0f
    );
    
    // Draw ground
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, snowTexture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 0.0f, 0.0f);
    glTexCoord2f(10.0f, 0.0f); glVertex3f(10.0f, 0.0f, 0.0f);
    glTexCoord2f(10.0f, 10.0f); glVertex3f(10.0f, 0.0f, -100.0f);
    glTexCoord2f(0.0f, 10.0f); glVertex3f(-10.0f, 0.0f, -100.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    // Draw snowflakes
    glDisable(GL_LIGHTING);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < MAX_SNOWFLAKES; i++) {
        glPushMatrix();
        glTranslatef(snowflakes[i].x, snowflakes[i].y, snowflakes[i].z);
        glutSolidSphere(0.05f, 8, 8);
        glPopMatrix();
    }
    glEnable(GL_LIGHTING);
    
    // Draw snowman
    glPushMatrix();
    glTranslatef(snowmanX, snowmanY, snowmanZ);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.5f, slices, stacks);
    glTranslatef(0.0f, 0.8f, 0.0f);
    glutSolidSphere(0.3f, slices, stacks);
    glPopMatrix();
    
    // Draw trees
    for (int i = 0; i < MAX_TREES; i++) {
        if (trees[i].active) {
            glPushMatrix();
            glTranslatef(trees[i].x, 0.0f, trees[i].z);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, trunkTexture);
            glPushMatrix();
            glRotatef(-90, 1.0f, 0.0f, 0.0f);
            drawSolidCylinder(0.1f, 1.2f, slices, stacks);
            glPopMatrix();
            glBindTexture(GL_TEXTURE_2D, pineTexture);
            glPushMatrix();
            glTranslatef(0.0f, 1.2f, 0.0f);
            glRotatef(-90, 1.0f, 0.0f, 0.0f);
            glutSolidCone(0.4f, 3.0f, slices, stacks);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
            glPopMatrix();
        }
    }
    
    // Draw shadows
    if (shadowEnabled) drawShadow();
    
    // Display score and game over message
    glDisable(GL_LIGHTING);
    // Score display
    char scoreText[32];
    snprintf(scoreText, sizeof(scoreText), "Score: %d", score);
    glColor3f(0.0f, 1.0f, 0.0f);
    glRasterPos3f(snowmanX - 1.0f, snowmanY + 1.5f, snowmanZ - 5.0f);
    for (char *c = scoreText; *c; c++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    
    if (gameOver) {
        glColor3f(1.0f, 0.0f, 0.0f);
        glRasterPos3f(snowmanX - 1.0f, snowmanY + 1.0f, snowmanZ - 5.0f);
        const char *msg = "Game Over! Press 'r' to restart.";
        while (*msg) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *msg++);
    }
    glEnable(GL_LIGHTING);
    
    glutSwapBuffers();
}

// Keyboard callback (unchanged)
static void key(unsigned char key, int x, int y) {
    if (gameOver && key != 'r') return;
    
    switch (key) {
        case 27:
        case 'q':
            exit(0);
            break;
        case 'w':
            moveForward = 1;
            break;
        case 's':
            moveBackward = 1;
            break;
        case 'a':
            moveLeft = 1;
            break;
        case 'd':
            moveRight = 1;
            break;
        case ' ':
            if (snowmanY <= 0.5f) jumpVelocity = 0.1f;
            break;
        case 't':
            shadowEnabled = !shadowEnabled;
            break;
        case 'r':
            if (gameOver) {
                snowmanX = 0.0f;
                snowmanZ = 0.0f;
                snowmanY = 0.5f;
                jumpVelocity = 0.0f;
                gameOver = 0;
                score = 0; // Reset score
                initTrees();
                initSnowflakes();
            }
            break;
        case '+':
            slices++;
            stacks++;
            break;
        case '-':
            if (slices > 3 && stacks > 3) {
                slices--;
                stacks--;
            }
            break;
    }
    glutPostRedisplay();
}

// Keyboard release (unchanged)
static void keyUp(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            moveForward = 0;
            break;
        case 's':
            moveBackward = 0;
            break;
        case 'a':
            moveLeft = 0;
            break;
        case 'd':
            moveRight = 0;
            break;
    }
    glutPostRedisplay();
}

// Special key callback (unchanged)
static void special(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            cameraAngleX -= 5.0f;
            if (cameraAngleX < 10.0f) cameraAngleX = 10.0f;
            break;
        case GLUT_KEY_DOWN:
            cameraAngleX += 5.0f;
            if (cameraAngleX > 80.0f) cameraAngleX = 80.0f;
            break;
    }
    glutPostRedisplay();
}

// Idle callback with score update and movement constraints
static void idle(void) {
    if (!gameOver) {
        // Update snowman position with constraints
        if (moveForward) snowmanZ -= moveSpeed;
        if (moveBackward) snowmanZ += moveSpeed;
        if (moveLeft) snowmanX -= moveSpeed;
        if (moveRight) snowmanX += moveSpeed;
        
        // Constrain snowmanX to ±4.0f
        if (snowmanX < -4.0f) snowmanX = -4.0f;
        if (snowmanX > 4.0f) snowmanX = 4.0f;
        
        // Update jumping
        snowmanY += jumpVelocity;
        jumpVelocity -= 0.005f;
        if (snowmanY < 0.5f) {
            snowmanY = 0.5f;
            jumpVelocity = 0.0f;
        }
        
        // Update snowflakes
        for (int i = 0; i < MAX_SNOWFLAKES; i++) {
            snowflakes[i].y += snowflakes[i].vy;
            if (snowflakes[i].y < 0.0f) {
                snowflakes[i].y = 10.0f;
                snowflakes[i].x = (float)(rand() % 200 - 100) / 10.0f;
                snowflakes[i].z = (float)(rand() % 1000 - 500) / 10.0f;
            }
        }
        
        // Update trees
        for (int i = 0; i < MAX_TREES; i++) {
            if (trees[i].active) {
                trees[i].z += moveSpeed;
                if (trees[i].z > 5.0f) {
                    trees[i].z = -100.0f;
                    float xPositions[] = {-4.0f, -2.0f, 0.0f, 2.0f, 4.0f};
                    trees[i].x = xPositions[rand() % 5];
                }
            }
        }
        
        // Update score (increment every frame)
        score++;
        
        // Check collision
        if (checkCollision()) gameOver = 1;
    }
    glutPostRedisplay();
}

// Main function (unchanged)
int main(int argc, char *argv[]) {
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutCreateWindow("Icydoom");
    
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutKeyboardUpFunc(keyUp);
    glutSpecialFunc(special);
    glutIdleFunc(idle);
    
    glClearColor(0.8f, 0.9f, 1.0f, 1.0f);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    
    generateTextures();
    initTrees();
    initSnowflakes();
    
    glutMainLoop();
    return EXIT_SUCCESS;
}
