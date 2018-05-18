#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
void display();
void init();
int a,i;
void draw_triangle(float *p,float *q,float *r);

void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	printf("enter the angle of rotation:");
	scanf("%d",&a);
	glutCreateWindow("ROTATE TRIANGLE");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
}

void draw_triangle(float *p,float *q,float *r)
{
	
	
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_TRIANGLES);
	glVertex2fv(p);
	glVertex2fv(q);
	glVertex2fv(r);
	glEnd();

	glColor3f(1,0,0);
	glPolygonMode(GL_FRONT,GL_LINE);
	glLineWidth(5);
	glBegin(GL_TRIANGLES);
	glVertex2fv(p);
	glVertex2fv(q);
	glVertex2fv(r);
	glEnd();

}


void display()
{
	glClearColor(0.94,0.59,0.91,0);
	glClear(GL_COLOR_BUFFER_BIT);
	float v[3][2] = {{30,30},{90,30},{60,60}};
	char s[50]="Rotating the triangle about the origin";
	glColor3f(0,0,0.2);
	glRasterPos2f(30,-30);
	for(i=0;i<strlen(s);i++)
	{

		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s[i]);
	}

	glColor3f(0.2,0,0.8);
	glLoadIdentity();
	draw_triangle(v[0],v[1],v[2]);
	glPushMatrix();
	glRotatef(a,0,0,1);
	glColor3f(0.2,0,0.8);
	draw_triangle(v[0],v[1],v[2]);
	glPopMatrix();
	

	float v1[3][2] = {{-20,-20},{-80,-20},{-50,-50}};
	char s1[50]="Fixed point rotation";
	glColor3f(0,0,0.2);
	glRasterPos2f(-50,-70);
	for(i=0;i<strlen(s1);i++)
	{

		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s1[i]);
	}
	glColor3f(0,0,0.4);
	draw_triangle(v1[0],v1[1],v1[2]);
	glTranslatef(-50,-50,0);
	glRotatef(a,0,0,1);
	glTranslatef(50,50,0);
	glColor3f(0,0,0.4);
	draw_triangle(v1[0],v1[1],v1[2]);
	glFlush();
}

















