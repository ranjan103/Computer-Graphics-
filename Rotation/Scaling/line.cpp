#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
// #include <windows.h>
#include <unistd.h>
using namespace std;

float s=0;
int d=0;
int flag1=0,flag2=0;
char spin = 0;
//A - rotate the ball in clockwise 
// B in anticlockwise
// C- scale the face
//D- descaling the face 
// E move the face to right
// F to left
// R reset to original

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
int x1,y1,x2,y2;
void draw_line(){
    
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


int a=0,b=0;
void myDisplay() {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f( 1, 1, 1 );
    
    int up=1;
    int right=1;
    // glTranslatef(0.0f,0.0f,0);
    x1+=a;
    y1+=b;
    x2+=a;
    y2+=b;
    draw_line();
    
}
int X1,X2,Y2,Y1;
int inc1=0,dec1=0;
void keyboard( unsigned char key, int x, int y )
{
    if(key=='A'){
        flag1=1;
    }
    if(key=='B'){
        flag2=1;
    }
    if(key=='C' ){
        inc1++;
    }
    if(key=='D'){       
        dec1++;
    }
    if(key=='U'){
        cin>>a>>b;
    }
    if(key=='F'){
        d-=50;
    }   
    if(key=='R'){
        d=0;
    }
    if(key=='I'){
        cout<<"Enter the initial coordinates\n";
        cin>>x1>>y1>>x2>>y2;
        X1=x1,Y1=y1,X2=x1,Y2=y2;
    }
    if(inc1>0){
        x1-=20*inc1;
        y1-=20*inc1;
        x2+=20*inc1;
        y2+=20*inc1;
    }
    else if(dec1>0){
        x1+=20*dec1;
        y1+=20*dec1;
        x2-=20*dec1;
        y2-=20*dec1;
    }
    inc1=0,dec1=0;
    myDisplay();
}


float angle = 0;
void timer( int value )
{
    if( spin==1 )
    {
        angle += 3;
    }

    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}
//A - rotate the ball in clockwise 
// B in anticlockwise
// C- scale the face
//D- descaling the face 
// E move the face to right
// F to left
// R reset to original

void display()

{
//draw(100,100);
 //glClear (GL_COLOR_BUFFER_BIT);
//glClearColor (0.0, 0.0, 0.0, 0.0);
 glutSwapBuffers();
}
 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-1000.0, 1000.0, -1000.0, 1000.0, -1.0, 1.0);
 }
int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 1000, 1000 );
glutInitWindowPosition (1000, 1000);
    glutCreateWindow( "GLUT" );
init();
    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );   
glutIdleFunc(display);
   // glutTimerFunc( 0, timer, 0 );
    glutMainLoop();
    return 0;
}