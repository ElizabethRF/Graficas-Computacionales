// Elizabeth Rodríguez Fallas


#include "cCube.hpp"

Cube::Cube(float side, bool use_mipmaps)
{
   
    for (int t = 0;t <6 ; t++)
    {
        glGenTextures(1, &targas[t].texID);
        glBindTexture(GL_TEXTURE_2D, targas[t].texID);
        glTexEnvi( GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
        if (use_mipmaps)
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        }
        else
        {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        }
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        
        switch (t) {
            case 0: LoadTGA(&targas[t],"/Users/Intern/Desktop/assets/cube_front.tga");  break;
            case 1: LoadTGA(&targas[t],"/Users/Intern/Desktop/assets/cube_back.tga");  break;
            case 2: LoadTGA(&targas[t],"/Users/Intern/Desktop/assets/cube_left.tga");  break;
            case 3: LoadTGA(&targas[t],"/Users/Intern/Desktop/assets/cube_right.tga");  break;
            case 4: LoadTGA(&targas[t],"/Users/Intern/Desktop/assets/cube_top.tga");  break;
            case 5: LoadTGA(&targas[t],"/Users/Intern/Desktop/assets/cube_bottom.tga");  break;

        }
        
        
        if(use_mipmaps){
            gluBuild2DMipmaps(GL_TEXTURE_2D,
                              3,
                              targas[t].width,
                              targas[t].height,
                              GL_RGB,
                              GL_UNSIGNED_BYTE,
                              targas[t].imageData);
            
        }
        else{
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, targas[t].width, targas[t].height, 0, GL_RGB, GL_UNSIGNED_BYTE, targas[t].imageData);
        }
        glBindTexture(GL_TEXTURE_2D, 0); // unbind
    }
        
    
   


    }

Cube::~Cube(void)
{
    glDeleteTextures( 1, &targas[0].texID );
    glDeleteTextures( 1, &targas[1].texID );
    glDeleteTextures( 1, &targas[2].texID );
    glDeleteTextures( 1, &targas[3].texID );
    glDeleteTextures( 1, &targas[4].texID );
    glDeleteTextures( 1, &targas[5].texID );
}

void Cube::draw(void)
{
    
        
    glBindTexture(GL_TEXTURE_2D, targas[0].texID);

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
       glBindTexture(GL_TEXTURE_2D, NULL); // unbind
    
       glBindTexture(GL_TEXTURE_2D, targas[1].texID);
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
       glBindTexture(GL_TEXTURE_2D, NULL); // unbind
    
        glBindTexture(GL_TEXTURE_2D, targas[2].texID);
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
       glBindTexture(GL_TEXTURE_2D, NULL); // unbind
        
        glBindTexture(GL_TEXTURE_2D, targas[3].texID);
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
       
        
       glBindTexture(GL_TEXTURE_2D, NULL); // unbind
        glBindTexture(GL_TEXTURE_2D, targas[4].texID);
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
       glBindTexture(GL_TEXTURE_2D, NULL); // unbind
    
    
    glBindTexture(GL_TEXTURE_2D, targas[5].texID);
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
//  The mipmaps create a blurry effect as the pixels are not calculated specifically at each point
//
