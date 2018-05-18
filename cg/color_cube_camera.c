#include<GL/glut.h>
#include<stdio.h>
void drawcube(float *a, float *b, float *c, float *d);
void display();
void init();
void Keys(unsigned char K,int x,int y);
float copx=10,copy=20,copz=100;


void main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutCreateWindow("COLOR CUBE");
	init();
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutKeyboardFunc(Keys);
	glutMainLoop();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-100,100,-100,100,500,1000);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	
	glClearColor(0.5,0.25,0.5,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float v[8][3]={{-20,-20,20},{20,-20,20},{20,20,20},{-20,20,20},{-20,-20,-20},{20,-20,-20},{20,20,-20},{-20,20,-20}};
	glLoadIdentity();
	gluLookAt(copx,copy,copz,0,0,0,0,1,0);
	glColor3f(1,0,0);
	drawcube(v[0],v[1],v[2],v[3]);
	glColor3f(0.2,0.55,0.5);
	drawcube(v[1],v[2],v[6],v[5]);
	glColor3f(0,0,0.5);
	drawcube(v[3],v[2],v[6],v[7]);
	glColor3f(0.57,0.304,0.88);
	drawcube(v[0],v[3],v[7],v[4]);
	glColor3f(0.94,0.59,0.91);
	drawcube(v[5],v[6],v[7],v[4]);
	glColor3f(0.2,0.9,0.5);
	drawcube(v[0],v[1],v[5],v[4]);
	glFlush();
	
}
void drawcube(float *a,float *b,float *c, float *d)
{
	glBegin(GL_QUADS);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();
	
}

void Keys(unsigned char K,int x,int y)
{
	if(K=='X')
		copx=copx+10;
	if(K=='x')
		copx=copx-10;
	if(K=='Y')
		copy=copy+10;
	if(K=='y')
		copy=copy-10;
	if(K=='Z')
		copz=copz+10;
	if(K=='z')
		copz=copz-10;
	glutPostRedisplay();
}







