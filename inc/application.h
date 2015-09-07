#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <iostream>

#include <CAD.h>
#include <Keyboard.h>
#include <Menu.h>
#include <Mouse.h>
#include <Scene.h>
#include <Window.h>

#ifndef APPLICATION_
#define  APPLICATION_

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1100
#define WINDOW_TITLE "ProfileCAD"

#define DEBUG

#ifdef DEBUG
 #define D
#else
 #define D for(;0;)
#endif

struct point_t{
  float x,y,z;
};

#endif
