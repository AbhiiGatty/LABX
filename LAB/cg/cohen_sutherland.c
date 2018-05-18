#include<glut.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void display();
void init();
float xmin,xmax,ymin,ymax,x,y,xvmin,xvmax,yvmin,yvmax;
float x1,y11,x2,y2,x3,y3,x4,y4,sx,sy;
void cohen(float x1,float y11,float x2,float y2);
int top=8,bottom=4,left=1,right=2,i;
int outcode(float x,float y);


void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	printf("Enter the coordinates of clipping rectangle:xmin,ymin,xmax,ymax:");
	scanf_s("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);
	printf("Enter the two end points of line:");
	scanf_s("%f%f%f%f",&x1,&y11,&x2,&y2);
	printf("Enter the coordinates of new clipping rectangle:xvmin,yvmin,xvmax,yvmax:");
	scanf_s("%f%f%f%f",&xvmin,&yvmin,&xvmax,&yvmax);
	glutCreateWindow("COHEN SUTHERLAND LINE CLIPPING ALGORITHM");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
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
	glClearColor(1,1,0.8,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8,0.6,0.8);
	glRectf(xmin,ymin,xmax,ymax);
	glColor3f(0,0,0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(x1,y11);
	glVertex2f(x2,y2);
	glEnd();

	glColor3f(1,0,0);
	char s[] = "Line before clipping";
	glRasterPos2f(-400,450);
	for(i=0;i< strlen(s);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s[i]);
	}
	
	glColor3f(1,0,0);
	char s1[] = "Line after clipping";
	glRasterPos2f(100,450);
	for(i=0;i< strlen(s1);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s1[i]);
	}

	cohen(x1,y11,x2,y2);
	glFlush();
}	

void cohen(float x1,float y11,float x2,float y2)
{
	int o1,o2,o3;
	bool accept,stop=false;
	while(!stop)
	{
		o1=outcode(x1,y11);
		o2=outcode(x2,y2);
		if((o1==0)&&(o2==0))
		{
			accept = true;
			stop = true;
		}
		else if(o1&o2)
		{
			accept = false;
			stop = true;
		}
		else
		{
			o3=(o1==0)?o2:o1;
			if(o3&top)
			{
				y=ymax;
				x=x1+((x2-x1)/(y2-y11))*(ymax-y11);
			}
			else if(o3&bottom)
			{
				y=ymin;
				x=x1+((x2-x1)/(y2-y11))*(ymin-y11);
			}
			else if(o3&right)
			{
				x=xmax;
				y=y11+((y2-y11)/(x2-x1))*(xmax-x1);
			}
			else
			{
				x=xmin;
				y=y11+((y2-y11)/(x2-x1))*(xmin-x1);
			}
			if(o3==o1)
			{
				x1=x;
				y11=y;
			}
			else if(o3==o2)
			{
				x2=x;
				y2=y;
			}
		}
	}
	if(accept)
	{
		glColor3f(0.8,0.6,0.8);
		glRectf(xvmin,yvmin,xvmax,yvmax);
		sx=(xvmax-xvmin)/(xmax-xmin);
		sy=(yvmax-yvmin)/(ymax-ymin);
		x3=xvmin+(x1-xmin)*sx;
		y3=yvmin+(y11-ymin)*sy;
		x4=xvmin+(x2-xmin)*sx;
		y4=yvmin+(y2-ymin)*sy;

		glColor3f(0,0,0);
		glLineWidth(5);
		glBegin(GL_LINES);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		glEnd();
	}				
		
}

int outcode(float x,float y)
{
	int r=0;
	if(y>ymax)
		r=r|top;
	if(y<ymin)
		r=r|bottom;
	if(x>xmax)
		r=r|right;
	if(x<xmin)
		r=r|left;
	return r;
}
















		
























