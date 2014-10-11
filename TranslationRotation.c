/*Code to show translation and rotation of a rectangle 
Copyright - Prateek Narendra, Gokul Shanth, Jashan Shetty (2014)
*/
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
      

float rectangle1[3][1];
float rectangle2[3][1];
float rectangle3[3][1];
float rectangle4[3][1];
float rectangle1_origin[3][1];
float rectangle2_origin[3][1];
float rectangle3_origin[3][1];
float rectangle4_origin[3][1];
float line1[3][1];
float line2[3][1];
float translation[3][3]={{0,0,0},{0,0,0},{0,0,1}};
float rotation[3][3]={{0,0,0},{0,0,0},{0,0,1}};
float rectangle1_translate[3][1]={{0},{0},{1}};
float rectangle2_translate[3][1]={{0},{0},{1}};
float rectangle3_translate[3][1]={{0},{0},{1}};
float rectangle4_translate[3][1]={{0},{0},{1}};
float rectangle1_rotate[3][1]={{0},{0},{1}};
float rectangle2_rotate[3][1]={{0},{0},{1}};
float rectangle3_rotate[3][1]={{0},{0},{1}};
float rectangle4_rotate[3][1]={{0},{0},{1}};
float rectangle1_translate_rotate[3][1]={{0},{0},{1}};
float rectangle2_translate_rotate[3][1]={{0},{0},{1}};
float rectangle3_translate_rotate[3][1]={{0},{0},{1}};
float rectangle4_translate_rotate[3][1]={{0},{0},{1}};

void matrix_multiply(float mmatrix[3][1],float matrix1[3][3],float matrix2[3][1])  //Matrix Multiplication
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

void init(void)
{
  width  = 1280.0;                 /* initial window width and height, */
  height = 800.0;                  /* within which we draw. */
}



void start()
{	int a,b;
	float centerx,centery,wid,hei,line1x,line1y,line2x,line2y,angle,translate_x,translate_y;
	printf("\nEnter the coordinates of the centre of the rectangle : ");
	scanf("%f%f",&centerx,&centery);
	printf("\nEnter the width and height : ");
	scanf("%f%f",&wid,&hei);//INPUT
	printf("\nEnter translation factor : ");
	scanf("%f%f",&translate_x,&translate_y);
	printf("Enter rotation angle : ");
	scanf("%F",&angle);
	rectangle1[0][0]=centerx-(wid/2);
	rectangle1[1][0]=centery-(hei/2);
	rectangle1[2][0]=1;
	rectangle2[0][0]=centerx-(wid/2);
	rectangle2[1][0]=centery+(hei/2);
	rectangle2[2][0]=1;//Calculation of rectangle vertices
	rectangle3[0][0]=centerx+(wid/2);
	rectangle3[1][0]=centery+(hei/2);
	rectangle3[2][0]=1;
	rectangle4[0][0]=centerx+(wid/2);
	rectangle4[1][0]=centery-(hei/2);
	rectangle4[2][0]=1;
	translation[0][2]=-(centerx);
	translation[1][2]=-(centery);
	translation[2][2]=1;					//For rotation - procedure id -> translate to origin -> rotate ->translate back
	translation[0][0]=1;					//Settting up translation matrix
	translation[1][1]=1;
	rotation[0][0]=cos(angle);
	rotation[0][1]=-sin(angle);//Settting up rotation matrix
	rotation[1][0]=sin(angle);
	rotation[1][1]=cos(angle);
	rotation[2][2]=1;	
	matrix_multiply(rectangle1_translate,translation,rectangle1);
	matrix_multiply(rectangle2_translate,translation,rectangle2);
	matrix_multiply(rectangle3_translate,translation,rectangle3);	//Translating to origin
	matrix_multiply(rectangle4_translate,translation,rectangle4);
	matrix_multiply(rectangle1_rotate,rotation,rectangle1_translate);
	matrix_multiply(rectangle2_rotate,rotation,rectangle2_translate);
	matrix_multiply(rectangle3_rotate,rotation,rectangle3_translate);//Rotating
	matrix_multiply(rectangle4_rotate,rotation,rectangle4_translate);
	translation[0][2]=(centerx);
	translation[1][2]=(centery);
	translation[2][2]=1;
	translation[0][0]=1;
	translation[1][1]=1;
	matrix_multiply(rectangle1_translate_rotate,translation,rectangle1_rotate);
	matrix_multiply(rectangle2_translate_rotate,translation,rectangle2_rotate);
	matrix_multiply(rectangle3_translate_rotate,translation,rectangle3_rotate);//Translating back
	matrix_multiply(rectangle4_translate_rotate,translation,rectangle4_rotate);
	translation[0][2]=translate_x;
	translation[1][2]=translate_y;
	translation[2][2]=1;
	translation[0][0]=1;//Normal translation function
	translation[1][1]=1;
	matrix_multiply(rectangle1_translate,translation,rectangle1);
	matrix_multiply(rectangle2_translate,translation,rectangle2);
	matrix_multiply(rectangle3_translate,translation,rectangle3);
	matrix_multiply(rectangle4_translate,translation,rectangle4);

}

void display(void)
{
  	
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);


  glColor3f(0.0, 0.0, 0.0);
  glLineWidth(3.0);
  glBegin(GL_LINES);
	glVertex2f(rectangle1[0][0],rectangle1[1][0]);
	glVertex2f(rectangle2[0][0],rectangle2[1][0]);
	glVertex2f(rectangle2[0][0],rectangle2[1][0]);
	glVertex2f(rectangle3[0][0],rectangle3[1][0]);
	glVertex2f(rectangle3[0][0],rectangle3[1][0]);
	glVertex2f(rectangle4[0][0],rectangle4[1][0]);
	glVertex2f(rectangle4[0][0],rectangle4[1][0]);
	glVertex2f(rectangle1[0][0],rectangle1[1][0]);
	glEnd();
	glColor3f(1.0, 0.0, 0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
	glVertex2f(rectangle1_translate[0][0],rectangle1_translate[1][0]);
	glVertex2f(rectangle2_translate[0][0],rectangle2_translate[1][0]);
	glVertex2f(rectangle2_translate[0][0],rectangle2_translate[1][0]);
	glVertex2f(rectangle3_translate[0][0],rectangle3_translate[1][0]);			//Display of translated rectangle
	glVertex2f(rectangle3_translate[0][0],rectangle3_translate[1][0]);
	glVertex2f(rectangle4_translate[0][0],rectangle4_translate[1][0]);
	glVertex2f(rectangle4_translate[0][0],rectangle4_translate[1][0]);
	glVertex2f(rectangle1_translate[0][0],rectangle1_translate[1][0]);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
   glLineWidth(3.0);
   glBegin(GL_LINES);
	glVertex2f(rectangle1_translate_rotate[0][0],rectangle1_translate_rotate[1][0]);
	glVertex2f(rectangle2_translate_rotate[0][0],rectangle2_translate_rotate[1][0]);
	glVertex2f(rectangle2_translate_rotate[0][0],rectangle2_translate_rotate[1][0]);
	glVertex2f(rectangle3_translate_rotate[0][0],rectangle3_translate_rotate[1][0]);		//Display of rotated rectangle with center as point of rotation
	glVertex2f(rectangle3_translate_rotate[0][0],rectangle3_translate_rotate[1][0]);
	glVertex2f(rectangle4_translate_rotate[0][0],rectangle4_translate_rotate[1][0]);
	glVertex2f(rectangle4_translate_rotate[0][0],rectangle4_translate_rotate[1][0]);
	glVertex2f(rectangle1_translate_rotate[0][0],rectangle1_translate_rotate[1][0]);
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

int
main(int argc, char *argv[])
{
 
	start();
  init();

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

  glutInitWindowSize((int) width, (int) height);

  wd = glutCreateWindow("Translation and Rotation");

  glutReshapeFunc(reshape);

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}

