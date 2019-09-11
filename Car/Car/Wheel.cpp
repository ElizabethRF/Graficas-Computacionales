//
//  Wheel.cpp
//  Car
//
//  Created by Intern on 9/10/19.
//  Copyright © 2019 Elizabeth.Tec. All rights reserved.
//

#include "Wheel.hpp"

//constructor and destructor dont have a return value
//:: mean belongs to - this function belongs to the class wheel

Wheel::Wheel(){ // like init
    position[0] = position[1]= position[2] = 0; // x y z
    color[0] = color[1] = color[2] = 0; // r g b 
}

Wheel::~Wheel(){
    
}

void Wheel::draw(){ // display()
    glPushMatrix();
    {
        glTranslatef(position[0], position[1], position[2]);
        glColor3f(color[0],color[1],color[2]);
        glRotatef(angle, 1, 0, 0);
        glScalef(0.1f,1,1);
        glutWireSphere(1, 20, 20);
    }
    glPopMatrix();
}

void Wheel::update(){ // update
    angle += 0.1f; 
}


