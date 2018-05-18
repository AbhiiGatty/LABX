#include<GL/glut.h>
#include<stdio.h>
void display();
int n;
void divide_tetra(float *a,float *b,float *c,float *d,int n);
void draw_triangle(float *a,float *b,float *c);
void init();

void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	printf("enter the number of times the tetrahedron should be divided:");
	scanf("%d",&n);
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutCreateWindow("SIERPENSKI GASKET USING RECURSIVE SUBDIVISION OF TETRAHEDRON");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10,10,-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(0.574,0.304,0.886,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float v[4][3] = {{-8.9,-8.9,-8.9},{8.9,-8.9,-8.9},{0,8.9,-8.9},{0,0,8.9}};
	divide_tetra(v[0],v[1],v[2],v[3],n);
	glFlush();
}


void divide_tetra(float *a,float *b,float *c,float *d,int n)
{
	int i;
	float mid[6][3];
	if(n>0)
	{
		for(i=0;i<3;i++)
		{
			mid[0][i] = (a[i]+b[i])/2;
			mid[1][i] = (b[i]+c[i])/2;
			mid[2][i] = (c[i]+a[i])/2;
			mid[3][i] = (a[i]+d[i])/2;
			mid[4][i] = (b[i]+d[i])/2;
			mid[5][i] = (c[i]+d[i])/2;
		}
		divide_tetra(a,mid[0],mid[2],mid[3],n-1);
		divide_tetra(mid[0],b,mid[1],mid[4],n-1);
		divide_tetra(mid[2],mid[1],c,mid[5],n-1);
		divide_tetra(mid[3],mid[4],mid[5],d,n-1);
	}
	else
	{
		glColor3f(0.94,0.59,0.91);
		draw_triangle(a,b,c);
		glColor3f(0.925,0.589,0.363);
		draw_triangle(a,d,c);
		glColor3f(1,1,0);
		draw_triangle(b,d,c);
		glColor3f(0.9,0.2,0.4);
		draw_triangle(a,b,d);
	}
}

void draw_triangle(float *a,float *b,float *c)
{
	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}







