/*
 * Elizabeth Rodríguez Fallas A0133435
 * Diego Gonzalez Plata A01333129
 * TC3022. Computer Graphics Course.
 * Solar System
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

/*
 Program a solar system:
 
 - Planets, moons and rings rotate on their own axes.
 + Draw the planets in wireframe to see their rotation.
 + The sun at the center, yellow.
 + Mercury first (dark red), around the sun.
 + Venus after mercury (dark green).
 + Earth around the sun (blue).
 + The moon around earth.
 + A space station around the moon (clear gray).
 + Mars around the sun (red).
 + Jupiter around the sun (clear brown).
 + Saturn around the sun (dark yellow).
    - Draw the rings.
 */


int rotate = 0;


void init() // FOR GLUT LOOP
{
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0);    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}

void planet(float r, float g, float b, float rotVar, float radius, float translate){
    glColor3f(r,g,b);
    glPushMatrix();
    {
        
        glRotatef(rotVar,0,1,0);
        glTranslatef(translate,0,0);
        glRotatef(rotVar,0,1,0);
        glutWireSphere(radius,20,20);
    }
    glPopMatrix();
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
    gluLookAt(0.0, 25.0, 35.0,                                        // Where the camera is.
              0.0, 0.0, 0.0,                                        // To where the camera points at.
              0.0, 1.0, 0.0);                                        // "UP" vector.
    
    //axes(5);
    // sun - The sun at the center, yellow.
    planet(1,1,0,rotate,2,0); // RGB
    
    // Mercury - Mercury first (dark red), around the sun.
    planet(0.69, 0.21, 0.12,rotate* 1.7,0.4,4); // R 176 G 56 B 31
    
    
    // Venus - Venus after mercury (dark green).
    planet(0.27, 0.49, 0.05,rotate * 1.6 ,0.6,7);  // R 70 G 126 B 13
    
    // Earth - Earth around the sun (blue).
    glPushMatrix();
    {
        glColor3f(0, 0, 1); // blue
        glRotatef(rotate * 1.5 , 0, 1, 0);
        glTranslatef(11,0,0);
        glRotatef(rotate , 0, 1, 0);
        glutWireSphere(0.8, 36, 36);
        
        // Moon
        glColor3f(0.55, 0.55, 0.55); // grey R 142 G 142 B 142
        glRotatef(rotate , 0, 1, 0);
        glTranslatef(2,0,0);
        glutWireSphere(0.2, 36, 36);
        
        // Space station - A space station around the moon (clear gray).
        glColor3f(0.83, 0.87, 0.89); // clear gray R 214 G 223 B 228
        glRotatef(rotate , 0, 1, 0);
        glTranslatef(1,0,0);
        glutWireSphere(0.1, 36, 36);
        
        
    }
    glPopMatrix();
    
    // Mars - Mars around the sun (red).
    planet(1, 0, 0,rotate * 1.4 ,0.7,15);
    
    //Jupiter - Jupiter around the sun (clear brown).
    planet(0.81, 0.55, 0.11,rotate * 1.2 ,1,18); // R  209 G 141 B 29
    
    // Saturn - Saturn around the sun (dark yellow).
    //planet(0.76, 0.71, 0.02,rotate ,1,21); // R 194 G 183 B 7
   
    glColor3f(0.76, 0.71, 0.02); // clear gray R 214 G 223 B 228
    glRotatef(rotate , 0, 1, 0);
    glTranslatef(21,0,0);
    glutWireSphere(1, 36, 36);
    
    // Saturn rings
    glColor3f(0.92, 0.48, 0.09); // R 235 G 123  B 23
    glRotatef(90,1,0,0);
    glRotatef(rotate*2.5,0,0,1);
    glutWireTorus(0.5,2.5,10,50);
    // glutWireSphere(0.5, 36, 36);
    
    glutSwapBuffers();                                                // Swap the hidden and visible buffers.
}

void idle()                                                            // Called when drawing is finished.
{
    glutPostRedisplay();// Display again.
    rotate += 1;
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 1.0, 4.0,
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
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}

