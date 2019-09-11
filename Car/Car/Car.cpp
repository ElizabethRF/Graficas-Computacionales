//
//  Car.cpp
//  Car
//
//  Created by Intern on 9/10/19.
//  Copyright © 2019 Elizabeth.Tec. All rights reserved.
//

#include "Car.hpp"

//constructor and destructor dont have a return value
//:: mean belongs to - this function belongs to the class wheel

Car::Car(){ // like init
    position[0] = position[1]= position[2] = 0; // x y z
    color[0] = color[1] = color[2] = 0; // r g b
    size  = 0;
}

Car::~Car(){
    
}

void Car::draw(){ // display()
    glPushMatrix();
    {
        glTranslatef(position[0], position[1], position[2]);
        glColor3f(color[0],color[1],color[2]);
        glScalef(0.5f,0.5f,1);
        glutWireCube(size);
    }
    glPopMatrix();
}

void Car::update(){ // update
}



