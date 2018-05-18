#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
void display();
void plot(int,int);
int x1,x2,y11,y2,x,y;
void bresenham();
void init();


void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	printf("enter the values of x1,y11,x2,y2:");
	scanf("%d%d%d%d",&x1,&y11,&x2,&y2);
	glutCreateWindow("Bresenham's Line Drawing Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

void bresenham()
{
	int dx,dy,xinc,yinc,pk,i;
	dx = x2-x1;
	dy = y2-y11;
	x=x1;
	y=y11;
	plot(x,y);
	if(dx>0)
		xinc=1;
	else
		xinc=-1;
	if(dy>0)
		yinc=1;
	else
		yinc=-1;
	if(abs(dx)>abs(dy))
	{
		pk=(2*abs(dy))-abs(dx);
		for(i=1;i<=abs(dx)-1;i++)
		{
			if(pk>0)
			{
				pk=pk+(2*abs(dy))-(2*abs(dx));
				y=y+yinc;
			}
			else
			{
				pk=pk+(2*abs(dy));
				y=y;
			}
			x=x+xinc;
			plot(x,y);
		}
	}
	else
	{
		pk=(2*dx)-dy;
		for(i=1;i<=abs(dy)-1;i++)
		{
			if(pk>0)
			{
				pk=pk+(2*abs(dx))-(2*abs(dy));
				x=x+xinc;
			}
			else
			{
				pk=pk+(2*abs(dx));
				x=x;
			}
			y=y+yinc;
			plot(x,y);
		}
	}
}

void plot(int x,int y)
{
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(0.5,0.5,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	bresenham();
}












			




























	

