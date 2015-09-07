#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <iostream>
#include <Window.h>

using namespace std;

void windowInit()
{
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow(WINDOW_TITLE);
  glutReshapeFunc(windowResize);
}
void windowResize(int w, int h)
{
  glViewport(0, 0, w, h);
}