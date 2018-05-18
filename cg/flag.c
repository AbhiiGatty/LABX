#include <GL/glut.h>
void init();
void display();
void spin();
float a; 
void menu(int id);  
float cp[4][4][3]={{{0,-4,0},{3,-3,0},{6,-3,0},{9,-4,0}},
				{{0,-1,0},{3,-1,0},{6,-1,0},{9,-1,0}},
				{{0,2,0},{3,2,0},{6,2,0},{9,2,0}},
				{{0,5,0},{3,5.5,0},{6,5.5,0},{9,5,0}}};


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("FLAG");
	glutCreateMenu(menu);
	glutAddMenuEntry("yellow",1);
	glutAddMenuEntry("purple",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutIdleFunc(spin);
	glutMainLoop();
}

void spin()
{
	if(a>=60)
	{	
		a=0;
	}
	else
	{
		a=a+0.2;
	}
	glutPostRedisplay();
}
	

void init()
{
	glClearColor(1,1,0.8,0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10,10,-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMap2f(GL_MAP2_VERTEX_3,0,1,3,4,0,1,12,4,&cp[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
}

void menu(int id)
{
	if(id==1)
		glClearColor(1,1,0,0);
	if(id==2)
		glClearColor(0.5,0.5,1,0);
	glutPostRedisplay();
}

void display()
{  
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);                
	float i;
	glColor3f(0,0,0);
	/*glBegin(GL_LINE_STRIP);
	for(i=0;i<100;i++)
	{
		glEvalCoord1f(i/100);
	}
	glEnd();*/
	glRectf(0,5,-1,-8);
	glColor3f(0.2,0.2,0.5);
	
	glPushMatrix();
	glLoadIdentity();
	glRotatef(a,0,1,0);
	glMapGrid2f(50,0,1,20,0,1);
	glEvalMesh2(GL_FILL,0,50,0,20);
	glPopMatrix();
	
	glFlush();
}
