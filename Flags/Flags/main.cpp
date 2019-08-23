/*
 * Elizabeth Rodríguez Fallas A01334353
 * Diego Plata
 * TC3022. Computer Graphics Course.
 * Drawing polygons.
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

int type; //global variable to select flag


void init() // FOR GLUT LOOP
{
    type = 0;
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0);    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius){
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    
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



void germany(){
    glColor3f(0, 0, 0);
    glRects(-10,5,10,1.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRects(-10,1.5f,10,-1.5f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glRects(-10,-1.5f,10,-4);
}

void japan(){
    glColor3f(1, 1, 1);
    glRects(-10,5,10,-4);
    glColor3f(1,0,.12f);
    drawFilledCircle(0,0,1,1);
}


void jamaica(){
    glColor3f(1, 1, 0);
    glRects(-10,5,10,-4);
    glColor3f(0.25f, 0.4f, 0.3f);
    glBegin(GL_TRIANGLES);{
        glVertex3f(-9.5f,5,1);
        glVertex3f(9.5f,5,1);
        glVertex3f(0,1,1);
    }
    glEnd();
    glBegin(GL_TRIANGLES);{
        glVertex3f(-9.5f,-5,1);
        glVertex3f(9.5f,-5,1);
        glVertex3f(0,-1,1);
    }
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);{
        glVertex3f(-10,4.5f,1);
        glVertex3f(-10,-4.5f,1);
        glVertex3f(-1,0,1);
    }
    glEnd();
    glBegin(GL_TRIANGLES);{
        glVertex3f(10,4.5f,1);
        glVertex3f(10,-4.5f,1);
        glVertex3f(1,0,1);
    }
    glEnd();
}


void greece(){
    
}

void finland(){
    
    //cross
    //horizontal
    glColor3f(0.0f, 0.207f, 0.501f); //RGB 0 53 128
    glBegin(GL_QUADS);
    {
        glVertex3f(-4.0, -0.7, 0.0);
        glVertex3f(4.0, -0.7, 0.0);
        glVertex3f(4.0, 0.7, 0.0);
        glVertex3f(-4.0, 0.7, 0.0);
    }
    glEnd();
    
    // vertical
    glColor3f(0.0f, 0.207f, 0.501f); //RGB 0 53 128
    glBegin(GL_QUADS);
    {
        glVertex3f(-2.0, -2.5, 0.0);
        glVertex3f(-0.5, -2.5, 0.0);
        glVertex3f(-0.5, 2.5, 0.0);
        glVertex3f(-2.0, 2.5, 0.0);
    }
    glEnd();
    
    //Back
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    {
        glVertex3f(-4.0, -2.5, 0.0);
        glVertex3f(4.0, -2.5, 0.0);
        glVertex3f(4.0, 2.5, 0.0);
        glVertex3f(-4.0, 2.5, 0.0);
    }
    glEnd();
    
    
}

void bahamas(){
    //Triangle
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);{
        glVertex3f(-5.0,-2.5,0);
        glVertex3f(-1,0,0);
        glVertex3f(-5.0,2.5,0);
    }
    glEnd();
    
    //line
    glColor3f(1.0f, 0.796f, 0.0); //RGB 249 200 71
    glBegin(GL_QUADS);
    {
        glVertex3f(-5.0, -0.7, 0.0);
        glVertex3f(5.0, -0.7, 0.0);
        glVertex3f(5.0, 0.7, 0.0);
        glVertex3f(-5.0, 0.7, 0.0);
    }
    glEnd();
    
    // back
    glColor3f(0, 0.474f, 0.564f);
    glBegin(GL_QUADS);
    {
        glVertex3f(-5.0, -2.5, 0.0);
        glVertex3f(5.0, -2.5, 0.0);
        glVertex3f(5.0, 2.5, 0.0);
        glVertex3f(-5.0, 2.5, 0.0);
    }
    glEnd();
}

void somalia(){
    
    // Star 5 triangulos
    // Triangle 1
     glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);{
        glVertex3f(-0.624,-0.416,0);
        glVertex3f(0.624,-0.416,0);
        glVertex3f(0,1.248,0);
    }
    glEnd();
    
    // Triangle 2
    
    
    // Triangle 3
    
    // Triangle 4
    
    // Triangle 5
    
    //Back
    glColor3f(0.2f, 0.513f, 0.894f); // RGB 51 131 228
    glBegin(GL_QUADS);
    {
        glVertex3f(-3.75, -2.5, 0.0);
        glVertex3f(3.75, -2.5, 0.0);
        glVertex3f(3.75, 2.5, 0.0);
        glVertex3f(-3.75, 2.5, 0.0);
    }
    glEnd();
}


void keyboard(unsigned char key, int x, int y){
    
    switch (key) {
        case '1':
            type = 1; // japan
            break;
        case '2':
            type = 2; // germany
            break;
        case '3':
            type = 3; //jamaica
            break;
        case '4':
            type = 4; // finland
            break;
        case '5':
            type = 5; // bahamas
            break;
        case '6':
            type = 6; // somalia
            break;
        case '7':
            type = 7; // greece
            break;
    }
    
}
    
    


void display()                            // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers.
    glLoadIdentity();                                                // Reset 3D view matrix.
    gluLookAt(0.0, 0.0, 20.0,                                        // Where the camera is.
              0.0, 0.0, 0.0,                                        // To where the camera points at.
              0.0, 1.0, 0.0);                                        // "UP" vector.
    
    //axes(5);
    
    switch (type) {
        case 1:
            japan();
            break;
        case 2:
            germany();
            break;
        case 3:
            jamaica();
            break;
        case 4:
            finland();
            break;
        case 5:
            bahamas();
            break;
        case 6:
            somalia();
            break;
        case 7:
            greece();
            break;
    }
    
    
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
    gluLookAt(0.0, 1.0, 10.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG first program");
    
    init();
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}
