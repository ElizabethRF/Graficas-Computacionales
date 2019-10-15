/*
 * Elizabeth Rodríguez Fallas
 *
 * TC3022. Computer Graphics Course.
 * Lightning assignment
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

GLfloat        rotation;
GLfloat*    mat0_ambient;        //<-------------------------------Material 0 - specular array
GLfloat*    mat0_diffuse;        //<-------------------------------Material 0 - diffuse array
GLfloat*    mat0_specular;        //<-------------------------------Material 0 - specular array
GLfloat*    mat0_shininess;        //<-------------------------------Material 0 - specular power array

GLfloat*    light0_position;    //<-------------------------------Light 0    - location array
GLfloat*    light0_ambient;        //<-------------------------------Light 0    - ambient array
GLfloat*    light0_specular;    //<-------------------------------Light 0    - diffuse array
GLfloat*    light0_diffuse;        //<-------------------------------Light 0    - specular array

GLfloat*    light1_position;    //<-------------------------------Light 1   - location array
GLfloat*    light1_ambient;        //<-------------------------------Light 1    - ambient array
GLfloat*    light1_specular;    //<-------------------------------Light 1    - diffuse array
GLfloat*    light1_diffuse;        //<-------------------------------Light 1    - specular array
void init()
{
    
    
    /*
     DATA
     kdr  0.871078 kdg  0.318621 kdb  0.929734
     kar  0.254415 kag  0.266047 kab  0.164320
     ksr  0.147271 ksg  0.950464 ksb  0.650074
     
     
     */
    rotation = 0;
//->MATERIAL 0 BEGINS
    mat0_ambient = new GLfloat[4]; //<----------------------------Reserve memory
    mat0_ambient[0] = 0.254415f; //<-----------------------------------ka0r
    mat0_ambient[1] = 0.266047f; //<-----------------------------------ka0g
    mat0_ambient[2] = 0.164320f; //<-----------------------------------ka0b
    mat0_ambient[3] = 1.0f; //<-----------------------------------ka0a

    mat0_diffuse = new GLfloat[4]; //<----------------------------Reserve memory
    mat0_diffuse[0] = 0.871078f; //<-----------------------------------kd0r
    mat0_diffuse[1] = 0.318621f; //<-----------------------------------kd0g
    mat0_diffuse[2] = 0.929734f; //<-----------------------------------kd0b
    mat0_diffuse[3] = 1.0f; //<-----------------------------------kd0a

    mat0_specular = new GLfloat[4]; //<---------------------------Reserve memory
    mat0_specular[0] = 0.147271f; //<----------------------------------ks0r
    mat0_specular[1] = 0.950464f; //<----------------------------------ks0g
    mat0_specular[2] = 0.650074f; //<----------------------------------ks0b
    mat0_specular[3] = 1.0f; //<----------------------------------ks0a

    mat0_shininess = new GLfloat[1]; //<--------------------------Reserve memory
    mat0_shininess[0] = 1.545f; //<--------------------------------Material 0 specular power (alpha)
//<-MATERIAL 0 ENDS

///-> LIGHT 0 BEGINS
    light0_position = new GLfloat[4]; //<-------------------------Reserve memory
    light0_position[0] = -4.924f; //<--------------------------------L0x
    light0_position[1] = 6.43f; //<--------------------------------L0y
    light0_position[2] = 10; //<--------------------------------L0z
    light0_position[3] = 0.0f; //<--------------------------------L0w

    /*
    Important: light position is L0(lx,ly,lz,lw).
    -If lw = 0, configures a directional light, and parameters lx, ly y lz define its direction.
    -If lw = 1, configures a point light, and parameters lx, ly y lz define its location.
    */

    light0_ambient = new GLfloat[4]; //<--------------------------Reserve memory
    light0_ambient[0] = 0.164295f; //<---------------------------------Ia0r
    light0_ambient[1] = 0.092044f; //<---------------------------------Ia0g
    light0_ambient[2] = 0.268798f; //<---------------------------------Ia0b
    light0_ambient[3] = 1.0f; //<---------------------------------Ia0a

    light0_diffuse = new GLfloat[4]; //<--------------------------Reserve memory
    light0_diffuse[0] = 0.446441f; //<---------------------------------Id0r
    light0_diffuse[1] = 0.003730f; //<---------------------------------Id0g
    light0_diffuse[2] = 0.471438f; //<---------------------------------Id0b
    light0_diffuse[3] = 1.0f; //<---------------------------------Id0a

    light0_specular = new GLfloat[4]; //<-------------------------Reserve memory
    light0_specular[0] = 0.902940f; //<--------------------------------Is0r
    light0_specular[1] = 0.926548f; //<--------------------------------Is0g
    light0_specular[2] = 0.718841f; //<--------------------------------Is0b
    light0_specular[3] = 1.0f; //<--------------------------------Is0a

//<-LIGHT 0 ENDS
    
//->LIGHT 1 BEGINS
    light1_position = new GLfloat[4]; //<-------------------------Reserve memory
    light1_position[0] = 4.432f; //<--------------------------------L0x
    light1_position[1] = 12.77f; //<--------------------------------L0y
    light1_position[2] = 1.0f; //<--------------------------------L0z
    light1_position[3] = 12.7f; //<--------------------------------L0w

    /*
    Important: light position is L0(lx,ly,lz,lw).
    -If lw = 0, configures a directional light, and parameters lx, ly y lz define its direction.
    -If lw = 1, configures a point light, and parameters lx, ly y lz define its location.
     
     LIGHT1 -4.924 6.43 10
     LIGHT2 4.432 12.77 12.7
     
     Idr1 0.446441 Idg1 0.003730 Idb1 0.471438
     Iar1 0.164295 Iag1 0.092044 Iab1 0.268798
     Isr1 0.902940 Isg1 0.926548 Isb1 0.718841
     Idr2 0.656028 Idg2 0.450156 Idb2 0.615143
     Iar2 0.253022 Iag2 0.157105 Iab2 0.230167
     Isr2 0.899988 Isg2 0.860035 Isb2 0.974324
    */
    
    
    light1_ambient = new GLfloat[4]; //<--------------------------Reserve memory
    light1_ambient[0] = 0.253022f; //<---------------------------------Ia0r
    light1_ambient[1] = 0.157105f; //<---------------------------------Ia0g
    light1_ambient[2] = 0.230167f; //<---------------------------------Ia0b
    light1_ambient[3] = 1.0f; //<---------------------------------Ia0a

    light1_diffuse = new GLfloat[4]; //<--------------------------Reserve memory
    light1_diffuse[0] = 0.656028f; //<---------------------------------Id0r
    light1_diffuse[1] = 0.450156f; //<---------------------------------Id0g
    light1_diffuse[2] = 0.615143f; //<---------------------------------Id0b
    light1_diffuse[3] = 1.0f; //<---------------------------------Id0a

    light1_specular = new GLfloat[4]; //<-------------------------Reserve memory
    light1_specular[0] = 0.899988f; //<--------------------------------Is0r
    light1_specular[1] = 0.860035f; //<--------------------------------Is0g
    light1_specular[2] = 0.974324f; //<--------------------------------Is0b
    light1_specular[3] = 1.0f; //<--------------------------------Is0a

//<-LIGHT 1 ENDS

// Locate LIGHT 0:
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
// Enable lighting:
    glEnable(GL_LIGHTING);
// Enable LIGHT 0:
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);                                        // Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0);                                    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glLoadIdentity();                                            // Reset 3D view matrix.
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

void display()                                                    // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                            // Clear color and depth buffers.
    glLoadIdentity();                                            // Reset 3D view matrix.
    // CAM -0.619 5.096 4.144
    // PoI  -0.3851333333 3.994666667 -0.2536666667
    gluLookAt(-0.619, 5.096, 4.144,                                        // Where the camera is.
              -0.3851333333, 3.994666667, -0.2536666667,                                        // To where the camera points at.
              0.0, 1.0, 0.0);                                        // "UP" vector.
    

    axes(1);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat0_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat0_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat0_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat0_shininess);

    glRotatef(rotation, 0, 1, 0);
    //glutSolidSphere(1, 30, 30);
    glBegin(GL_TRIANGLES);
    {
        // n -5.556752 5.876396 0.3243798
        // A -1.827 2.713 -1.735
        glNormal3f(-5.556752, 5.876396, 0.3243798);
        glVertex3f(-1.827, 2.713, -1.735); // A
        
        // n -5.556752 5.876396 0.3243798
        // B 0.6896 4.875 2.209
        glNormal3f(-5.556752, 5.876396, 0.3243798);
        glVertex3f(0.6896, 4.875, 2.209); // A
        
        // n -5.556752 5.876396 0.3243798
        // C -0.018 4.396 -1.235
        glNormal3f(-5.556752, 5.876396, 0.3243798);
        glVertex3f(-0.018, 4.396, -1.235); // A
    }
    glEnd();
    
    glutSwapBuffers();                                            // Swap the hidden and visible buffers.
}

void idle()                                                    // Called when drawing is finished.
{
    rotation += 0.1f;
    glutPostRedisplay();                                            // Display again.
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                        // Go to 2D mode.
    glLoadIdentity();                                            // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);                        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 1.0, 4.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    display();
}

void keyboard(unsigned char key, int x, int y)
{
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);                        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG Lighting");
    
    init();
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                            // Idle CALLBACK function.
    glutMainLoop();                                                // Begin graphics program.
    return 0;                                                // ANSI C requires a return value.
}
