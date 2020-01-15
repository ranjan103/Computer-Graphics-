#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1,x2,y1,y2;

void display(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); 
	
	float dy,dx,step,x,y,k,Xin,Yin;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);

	Xin=dx/step;
	Yin=dy/step;

	x=x1;
	y=y1;

	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();

	for(k=1;k<=step;k++){
		x+=Xin;
		y+=Yin;

		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	}

	glFlush();

}

void init(){
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc,char** argv){

	printf("Hey! please enter the value of x1\n");
	scanf("%f",&x1);
	printf("Hey! please enter the value of y1\n");
	scanf("%f",&y1);
	printf("Hey! please enter the value of x2\n");
	scanf("%f",&x2);
	printf("Hey! please enter the value of y2\n");
	scanf("%f",&y2);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("DDA Line Algo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}