#include<GL/glut.h>
void display();
void init();
void draw_cube(float *a,float *b,float *c,float *d);
float a=0;
void Spin();


void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutCreateWindow("CUBE");
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	init();
	glutDisplayFunc(display);
	glutIdleFunc(Spin);
	glutMainLoop();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,100,-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(0.5,0.25,0.5,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float v[8][3] = {{-20,-20,20},{20,-20,20},{20,20,20},{-20,20,20},{-20,-20,-20},{20,-20,-20},{20,20,-20},{-20,20,-20}};
	glColor3f(1,0,0);
	glLoadIdentity();
	glRotatef(a,1,1,1);
	draw_cube(v[0],v[1],v[2],v[3]);
	glColor3f(0.2,0.55,0.5);
	draw_cube(v[1],v[2],v[6],v[5]);
	glColor3f(0,0,0.5);
	draw_cube(v[3],v[2],v[6],v[7]);
	glColor3f(0.57,0.304,0.88);
	draw_cube(v[0],v[4],v[7],v[3]);
	glColor3f(0.94,0.59,0.91);
	draw_cube(v[0],v[1],v[5],v[4]);
	glColor3f(0.2,0.9,0.5);
	draw_cube(v[4],v[5],v[6],v[7]);
	glFlush();
}

void draw_cube(float *a,float *b,float *c,float *d)
{
	glBegin(GL_QUADS);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();
}

void Spin()
{
	if(a>=360)
		a=0;
	else
		a=a+0.5;
	glutPostRedisplay();
}	
	




