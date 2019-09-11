//
//  Car.hpp
//  Car
//
//  Created by Intern on 9/10/19.
//  Copyright © 2019 Elizabeth.Tec. All rights reserved.
//

#pragma once

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


#ifndef __CAR
#define __CAR

class Car{
public:
    Car();
    ~Car(); // this free the memory when im done with the class
    
    void draw(); // to be called from main's display()
    void update(); // to be called from main's idle()
    
    // not the place to set the variable
    float position[3];
    float color[3];
    float size; 
};

#endif /* Wheel_hpp */
