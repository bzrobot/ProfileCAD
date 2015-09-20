#include <Scene.h>

using namespace std;
float ax, ay, az;       /* angles for orbit */
float tx, ty, tz;       /* factors for paning */
float scale = 0.1;          /* factor for scaling */
D int s = 0;

color_t BackgroundColor = BACKGROUND;
void sceneInit()
{
  tx, ty, tz = 0;
  glutDisplayFunc(sceneDraw);
  //sceneSetViewAngle(10, -10, 0);
}
void sceneIncViewAngle(float x, float y, float z)
{
  ax = ax + x;
  ay = ay + y;
  az = az + z;
  glutPostRedisplay();
}
void sceneSetViewAngle(float x, float y, float z)
{
  ax = x;
  ay = y;
  az = z;
  glutPostRedisplay();
}
point_t sceneGetViewAngle()
{
  return point_t{ax, ay, az};
}
void sceneIncZoom(float inc)
{
  if (inc > 0.01)
  {
    //inc = inc + 1;
    scale = scale + 0.01;
  }
  else
  {
    //inc = 1 + inc;
    scale = scale - 0.01;
    if (scale < 0)
    {
      scale = 0.01;
    }
  }
  //scale = scale + inc;
  glutPostRedisplay();
}
void sceneIncPan(float x, float y, float z)
{
  tx = tx + x;
  ty = ty + y;
  tz = tz + z;
  glutPostRedisplay();
}
void sceneColor(color_t c)
{
  glColor3f(c.r, c.g, c.b);
}
float sceneGetScale()
{
  return scale;
}
point_t sceneGetPanOffset()
{
  return point_t{tx, ty, tz};
}
void sceneDraw(void)
{
  //D printf("(sceneDraw) %d\r", s++);
  //D fflush(stdout);

  glClearColor(BackgroundColor.r, BackgroundColor.g, BackgroundColor.b, BackgroundColor.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //glEnable(GL_LIGHTING);
  //glDisable(GL_BLEND);
  //glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
  //glEnable ( GL_COLOR_MATERIAL );
  //Render 3D
  glPushMatrix();
  glRotatef(ax, 1.0, 0.0, 0.0);
  glRotatef(-ay, 0.0, 1.0, 0.0);
  glTranslatef(tx, ty, tz);
  //D printf("\nscale = %f\n", scale);
  glScalef(scale, scale, scale);
  //gluLookAt( 10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 10.0, 10.0, 10.0 );
  cadRender();
  glPopMatrix();

  //Render 2D overlay
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, 1, 0, 1);
  uiRender();
  glPopMatrix();
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);

  //glDisable(GL_STENCIL_TEST);
  glutSwapBuffers();

}
