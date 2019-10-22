// Elizabeth Rodríguez Fallas
// What’s the effect for the cube that uses mipmaps when compared to the one that does not?
// The cube that uses mipmas has a blurry effect due that it is not calculating each pixel at each moment.
//

#include "cCube.hpp"

Cube::Cube(float side, bool use_mipmaps)
{
    this->side = side;
    hside = side / 2.0f;

    texture_id = 0;
    // Generate my texture ID (just 1):
    glGenTextures(1, &texture_id);

    glBindTexture(GL_TEXTURE_2D, texture_id);

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    GLfloat texture_data[TEX_SIDE][TEX_SIDE][3];
    for (int u = 0; u < TEX_SIDE; u++)
    {
        for (int v = 0; v < TEX_SIDE; v++)
        {
            texture_data[u][v][0] = (GLfloat)rand() / RAND_MAX; // RED
            texture_data[u][v][1] = (GLfloat)rand() / RAND_MAX;//GREEN
            texture_data[u][v][2] = (GLfloat)rand() / RAND_MAX;//BLUE


        }
    }
        
    if (use_mipmaps)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        gluBuild2DMipmaps(GL_TEXTURE_2D,
            3,
            TEX_SIDE,
            TEX_SIDE,
            GL_RGB,
            GL_FLOAT,
            texture_data);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D,
            0,
            GL_RGB,
            TEX_SIDE,
            TEX_SIDE,
            0,
            GL_RGB,
            GL_FLOAT,
            texture_data);
    }

    glBindTexture(GL_TEXTURE_2D, NULL); // unbind
   


    }

Cube::~Cube(void)
{
    glDeleteTextures(1, &texture_id);
}

void Cube::draw(void)
{
    glBindTexture(GL_TEXTURE_2D, texture_id);

       glBegin(GL_QUADS); // FRONT
       {
           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 0.0f);
           glVertex3f(-hside, -hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 0.0f);
           glVertex3f(hside, -hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 1.0f);
           glVertex3f(hside, hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 1.0f);
           glVertex3f(-hside, hside, hside);



       }
       glEnd();
       
       glBegin(GL_QUADS); // RIGHT
       {
           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 0.0f);
           glVertex3f(hside, -hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 0.0f);
           glVertex3f(hside, -hside, -hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 1.0f);
           glVertex3f(hside, hside, -hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 1.0f);
           glVertex3f(hside, hside, hside);



       }
       glEnd();
       
       glBegin(GL_QUADS); // BACK
       {
           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 0.0f);
           glVertex3f(hside, -hside, -hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 0.0f);
           glVertex3f(-hside, -hside, -hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 1.0f);
           glVertex3f(-hside, hside, -hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 1.0f);
           glVertex3f(hside, hside, -hside);



       }
       glEnd();
       
       
       glBegin(GL_QUADS); // LEFT
       {
           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 0.0f);
           glVertex3f(-hside, -hside, -hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 0.0f);
           glVertex3f(-hside, -hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 1.0f);
           glVertex3f(-hside, hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 1.0f);
           glVertex3f(-hside, hside, -hside);



       }
       glEnd();
       
       glBegin(GL_QUADS); // TOP
       {
           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 0.0f);
           glVertex3f(-hside, hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 0.0f);
           glVertex3f(hside, hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 1.0f);
           glVertex3f(hside, hside, -hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 1.0f);
           glVertex3f(-hside, hside, hside);



       }
       glEnd();
       
       glBegin(GL_QUADS); // BOTTOM
       {
           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 0.0f);
           glVertex3f(-hside, -hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 0.0f);
           glVertex3f(hside, -hside, hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(1.0f, 1.0f);
           glVertex3f(hside, -hside, -hside);

           glNormal3f(0.0f, 0.0f, 1.0f);
           glTexCoord2f(0.0f, 1.0f);
           glVertex3f(-hside, -hside, -hside);



       }
       glEnd();

       
       glBindTexture(GL_TEXTURE_2D, NULL); // unbind
}


// What’s the effect for the cube that uses mipmaps when compared to the one that does not?
// The cube that uses mipmas has a blurry effect due that it is not calculating each pixel at each moment.
//
