#include<GL/glut.h>
#include<stdio.h>
void display();
void init();
void main(int argc , char** argv)
{
	glutInit(&argc,argv);
	glutCreateWindow("Tea Pot");
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_FLAT);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
void init()
{
	
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20,20,-20,20,-20,20);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	float amb[3]={1,0.5,0.3};
	float dif[3]={0.7,1,0.2};
	float spec[3]={0.4,0.1,1};
	float pos[4]={20.0,15.0,12.0,0.7};
	
	glClearColor(0,0.35,0.3,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
	glLightfv(GL_LIGHT0,GL_SPECULAR,spec);
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	float col[3]={0.4,0.35,0.2};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,col);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,col);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,col);
	glPushMatrix();
	glTranslatef(0,5,0);
	glRotatef(-30,-1,1,0);
	glutSolidTeapot(5);
	glPopMatrix();

	float col1[3]={0.4,0.1,0.2};
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,col1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,col1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,col1);
	glRotatef(-30,-1,1,0);
	glPushMatrix();
	glScalef(15.0,1,15.0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.0,-5,7.0);
	glScalef(0.5,10,0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.0,-5,7.0);
	glScalef(0.5,10,0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.0,-5,-7.0);
	glScalef(0.5,10,0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.0,-5,-7.0);
	glScalef(0.5,10,0.5);
	glutSolidCube(1);
	glPopMatrix();

	glFlush();
}

	
