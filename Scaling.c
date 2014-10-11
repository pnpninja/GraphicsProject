/*Code to show scaling of a rectangle
Copyright - Prateek Narendra, Gokul Shanth, Jashan Shetty (2014)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

        

GLdouble width, height;   /* window width and height */
int wd;                   /* GLUT window handle */
      

float rectangle1[3][1];
float rectangle2[3][1];
float rectangle3[3][1];
float rectangle4[3][1];
float rectangle1_final[3][1];
float rectangle2_final[3][1];
float rectangle3_final[3][1];
float rectangle4_final[3][1];
float line1[3][1];
float line2[3][1];
float translation[3][3]={{0,0,0},{0,0,0},{0,0,1}};
float scaling[3][3]={{0,0,0},{0,0,0},{0,0,1}};
float rectangle1_translate[3][1]={{0},{0},{1}};
float rectangle2_translate[3][1]={{0},{0},{1}};
float rectangle3_translate[3][1]={{0},{0},{1}};
float rectangle4_translate[3][1]={{0},{0},{1}};
float rectangle1_scaling[3][1]={{0},{0},{1}};
float rectangle2_scaling[3][1]={{0},{0},{1}};
float rectangle3_scaling[3][1]={{0},{0},{1}};
float rectangle4_scaling[3][1]={{0},{0},{1}};

void matrix_multiply(float mmatrix[3][1],float matrix1[3][3],float matrix2[3][1])  //Multiplication of 2 matrices - matrix1 and matrix2 to give output to mmatrix
{
	int i,j,k;
	for (i=0;i<3;i++)
       for(j=0;j<1;j++)
       {
 		mmatrix[i][j]=0;
 		for(k=0;k<3;k++)
     			mmatrix[i][j]+= matrix1[i][k]*matrix2[k][j];
       }

}

void
init(void)
{
  width  = 1280.0;                 /* initial window width and height, */
  height = 800.0;                  /* within which we draw. */
}


void start()
{	int a,b;
	float centerx,centery,wid,hei,line1x,line1y,line2x,line2y,angle,scaling_x,scaling_y;
	printf("\nEnter the coordinates of the centre of the rectangle : ");
	scanf("%f%f",&centerx,&centery);
	printf("\nEnter the width and height : ");
	scanf("%f%f",&wid,&hei);
	printf("\nEnter scaling factor : ");
	scanf("%f%f",&scaling_x,&scaling_y);
	rectangle1[0][0]=centerx-(wid/2);
	rectangle1[1][0]=centery-(hei/2);
	rectangle1[2][0]=1;
	rectangle2[0][0]=centerx-(wid/2);
	rectangle2[1][0]=centery+(hei/2);
	rectangle2[2][0]=1;
	rectangle3[0][0]=centerx+(wid/2);			//Setting up all vertices in a matrix mormat
	rectangle3[1][0]=centery+(hei/2);
	rectangle3[2][0]=1;
	rectangle4[0][0]=centerx+(wid/2);
	rectangle4[1][0]=centery-(hei/2);
	rectangle4[2][0]=1;
	translation[0][2]=-(centerx);				//Translation matrix to translate all points where centre of rectangle is at origin
	translation[1][2]=-(centery);
	translation[2][2]=1;
	translation[0][0]=1;
	translation[1][1]=1;
	scaling[0][0]=scaling_x;
	scaling[1][1]=scaling_y;
	scaling[2][2]=1;
	matrix_multiply(rectangle1_translate,translation,rectangle1);//Translation of all points such that centre at origin
	matrix_multiply(rectangle2_translate,translation,rectangle2);
	matrix_multiply(rectangle3_translate,translation,rectangle3);
	matrix_multiply(rectangle4_translate,translation,rectangle4);
	matrix_multiply(rectangle1_scaling,scaling,rectangle1_translate);//Scaling operation
	matrix_multiply(rectangle2_scaling,scaling,rectangle2_translate);
	matrix_multiply(rectangle3_scaling,scaling,rectangle3_translate);
	matrix_multiply(rectangle4_scaling,scaling,rectangle4_translate);
	translation[0][2]=(centerx);
	translation[1][2]=(centery);
	translation[2][2]=1;
	translation[0][0]=1;//Seting up to translate back to original position
	translation[1][1]=1;
	matrix_multiply(rectangle1_final,translation,rectangle1_scaling);//Calculation of translated scaled lines
	matrix_multiply(rectangle2_final,translation,rectangle2_scaling);
	matrix_multiply(rectangle3_final,translation,rectangle3_scaling);
	matrix_multiply(rectangle4_final,translation,rectangle4_scaling);



}

void display(void)
{

  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  /* draw a black line */
  glColor3f(0.0, 0.0, 0.0);
  glLineWidth(3.0);
  glBegin(GL_LINES);
	glVertex2f(rectangle1[0][0],rectangle1[1][0]);
	glVertex2f(rectangle2[0][0],rectangle2[1][0]);
	glVertex2f(rectangle2[0][0],rectangle2[1][0]);
	glVertex2f(rectangle3[0][0],rectangle3[1][0]);
	glVertex2f(rectangle3[0][0],rectangle3[1][0]);//Unscaled rectangle in black color
	glVertex2f(rectangle4[0][0],rectangle4[1][0]);
	glVertex2f(rectangle4[0][0],rectangle4[1][0]);
	glVertex2f(rectangle1[0][0],rectangle1[1][0]);
	glEnd();
glColor3f(1.0, 0.0, 0.0);
  glLineWidth(3.0);
glBegin(GL_LINES);
	glVertex2f(rectangle1_final[0][0],rectangle1_final[1][0]);
	glVertex2f(rectangle2_final[0][0],rectangle2_final[1][0]);
	glVertex2f(rectangle2_final[0][0],rectangle2_final[1][0]);
	glVertex2f(rectangle3_final[0][0],rectangle3_final[1][0]);//Scaled rectangle in red color
	glVertex2f(rectangle3_final[0][0],rectangle3_final[1][0]);
	glVertex2f(rectangle4_final[0][0],rectangle4_final[1][0]);
	glVertex2f(rectangle4_final[0][0],rectangle4_final[1][0]);
	glVertex2f(rectangle1_final[0][0],rectangle1_final[1][0]);
	glEnd();
  glFlush();
}

void reshape(int w, int h)
{
  
  width = (GLdouble) w;
  height = (GLdouble) h;

  
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, width, 0.0, height);
}

int main(int argc, char *argv[])
{
 
	start();
  init();

  
  glutInit(&argc, argv);

 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);


  glutInitWindowSize((int) width, (int) height);

  
  wd = glutCreateWindow("Scaling");

  glutReshapeFunc(reshape);
  
  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}

