/*
 * Elizabeth Rodríguez Fallas
 *
 * TC3022. Computer Graphics Course.
 * Class Assignment
 */

// Please don't change lines 9-31 (It helps me to grade)
#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

#include <stdio.h>
#include <math.h>
#include <random>
#include <cstdlib>

int sideNum;
char option;
void init() // FOR GLUT LOOP
{
    sideNum = 3;
    option = 'f';
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0);    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}



void keyboard(unsigned char key, int x, int y){
    
    switch(key){
        case 'f':
            option = 'f';
            break;
        case 'w':
            option = 'w';
            break;
            
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            sideNum = (int)key -48;
            break;
        
    }
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, int sidesAmount){
    int i;
    int triangleAmount = sidesAmount; //# of triangles used to draw circle
    
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, z); // center of circle
    for(i = 0; i <= triangleAmount;i++) {
        glVertex3f(
                   x + (radius * cos(i *  twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)),
                   z
                   );
    }
    glEnd();
}


void circle(float radius, float xc, float yc, int sides){
    float prevX = xc + radius;
    float prevY = yc;
    int count = 0;
    
    for(int i = 0; i<= 360; i+=(360/sides)){
            float rad = 0.0174533f * i;
            float x = xc +radius * cos(rad);
            float y = yc +radius * sin(rad);
            int r = (rand() % 100 + 1)/100;
            int g = (rand() % 100 + 1)/100;
            int b = (rand() % 100 + 1)/100;
        
            glColor3f(r,g,b);
            glBegin(GL_TRIANGLES);
            {
                glVertex3f(prevX,prevY,0);
                glVertex3f(x,y,0);
                // center
                glVertex3f(xc,yc,0);
                
            }
            glEnd();
            prevX= x;
            prevY  = y;
        
        
    }
}


void axes(float scale)
{
    glLineWidth(3);
    glBegin(GL_LINES);
    {
        glColor3f(1, 0, 0); // red
        glVertex3f(0, 0, 0);
        glVertex3f(scale, 0, 0);
        
        glColor3f(0, 1, 0); // green
        glVertex3f(0, 0, 0);
        glVertex3f(0, scale, 0);
        
        glColor3f(0, 0, 1); // blue
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, scale);
    }
    glEnd();
}



void display()                            // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers.
    glLoadIdentity();                                                // Reset 3D view matrix.
    gluLookAt(0.0, 0.0, 10.0,                                        // Where the camera is.
              0.0, 0.0, 0.0,                                        // To where the camera points at.
              0.0, 1.0, 0.0);                                        // "UP" vector.
    
    //shape
    
    //drawFilledCircle(0,0,1,3,sideNum);
    if(option == 'f'){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    
    
    circle(2, 0,0,sideNum);
    
    //drawFilledCircle(0,0,1,3,60);
    circle(2, 0,0,360);
    glutSwapBuffers();                                                // Swap the hidden and visible buffers.
}

void idle()                                                            // Called when drawing is finished.
{
    glutPostRedisplay();                                            // Display again.
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 0.0, 10.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("circle and shape");
    
    init();
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}
