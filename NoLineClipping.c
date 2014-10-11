//Code to draw a line and rectangle without line clipping
//Copyright-Prateek Narendra , Gokul Shanth, Jashan Shetty
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


GLdouble width, height;   /* window width and height */
int wd;                   /* GLUT window handle */
float a,b,c,d,e,f,g,h;       
void takevalues()
{
printf("Enter center coordinates of rectangle : ");
scanf("%f%f",&a,&b);
printf("Enter length and breadth of rectangle : ");
scanf("%f%f",&c,&d);
printf("Enter the coordinates of point 1 : ");
scanf("%f%f",&e,&f);
printf("Enter the coordinates of point 2 : ");
scanf("%f%f",&g,&h);

}
void
init(void)
{
  width  = 1280.0;                 /* initial window width andheight,*/
  height = 800.0;                  /* within which we draw. */
  
}


void
display(void)
{
  float centre[2]={a,b},lb[2]={c,d},rect1[2]={(centre[0]-(lb[0]/2)),(centre[1]-(lb[1]/2))},rect2[2]={(centre[0]-(lb[0]/2)),(centre[1]+(lb[1]/2))},rect3[2]={(centre[0]+(lb[0]/2)),(centre[1]+(lb[1]/2))},rect4[2]={(centre[0]+(lb[0]/2)),(centre[1]-(lb[1]/2))},line1[2]={e,f},line2[2]={g,h};




glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  /* draw a black line */
  glColor3f(0.0, 0.0, 0.0);
  glLineWidth(3.0);
  glBegin(GL_LINES);
	glVertex2f(rect1[0],rect1[1]);
	glVertex2f(rect2[0],rect2[1]);
	glVertex2f(rect2[0],rect2[1]);//Just draws recangle and line without clipping
	glVertex2f(rect3[0],rect3[1]);
	glVertex2f(rect3[0],rect3[1]);
	glVertex2f(rect4[0],rect4[1]);
	glVertex2f(rect4[0],rect4[1]);
	glVertex2f(rect1[0],rect1[1]);
	glVertex2f(line1[0],line1[1]);
	glVertex2f(line2[0],line2[1]);
	glEnd();

   //clear the screen to white


  
glFlush();
}

/* Called when window is resized,
   also when window is first created,
   before the first call to display(). */
void
reshape(int w, int h)
{

  width = (GLdouble) w;
  height = (GLdouble) h;

  
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);

  
     glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, width, 0.0, height);
}

int
main(int argc, char *argv[])
{
  
	takevalues();
  init();

  
  glutInit(&argc, argv);

  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

  
  glutInitWindowSize((int) width, (int) height);

  wd = glutCreateWindow("Non Liang Barsky");


  glutReshapeFunc(reshape);

  glutDisplayFunc(display);

 
  glutMainLoop();

  return 0;
}

