#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
// #include <windows.h>
#include <unistd.h>

float s=1;
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

int x1,y1;
int r;
void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void displayBresenamOctants(int x,int y){
    draw_pixel(x1+x,y1+y);
    draw_pixel(x1-x,y1+y);
    draw_pixel(x1+x,y1-y);
    draw_pixel(x1-x,y1-y);
    draw_pixel(x1+y,y1+x);
    draw_pixel(x1-y,y1+x);
    draw_pixel(x1+y,y1-x);
    draw_pixel(x1-y,y1-x);
}
void displayBresenamOctants1(int x,int y){
    // draw_pixel(x1+x,y1+y);
    // draw_pixel(x1-x,y1+y);
    draw_pixel(x1+x,y1-y);
    draw_pixel(x1-x,y1-y);
    // draw_pixel(x1+y,y1+x);
    // draw_pixel(x1-y,y1+x);
    draw_pixel(x1+y,y1-x);
    draw_pixel(x1-y,y1-x);
}
void draw_line() {

    int x=0,y=r;
    int deicsionParameter = 3-2*r;
    displayBresenamOctants(x,y);
    while(y>=x){
        x++;
        if(deicsionParameter>0){
            y--;
            deicsionParameter=deicsionParameter+4*(x-y)+10;
        }
        else{
            deicsionParameter=deicsionParameter+4*x+6;
        }
        displayBresenamOctants(x,y);
    }

}

void draw_line1() {

    int x=0,y=r;
    int deicsionParameter = 3-2*r;
    displayBresenamOctants(x,y);
    while(y>=x){
        x++;
        if(deicsionParameter>0){
            y--;
            deicsionParameter=deicsionParameter+4*(x-y)+10;
        }
        else{
            deicsionParameter=deicsionParameter+4*x+6;
        }
        displayBresenamOctants1(x,y);
    }

}

void myDisplay() {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f( 1, 1, 1 );
    
    int up=1;
    int right=1;
    // glTranslatef(0.0f,0.0f,0);
    r=50*s;
    draw_line();
    
    
}


void keyboard( unsigned char key, int x, int y )
{
    if(key=='A'){
        flag1=1;
    }
    if(key=='B'){
        flag2=1;
    }
    if(key=='C'){
        s*=2;
    }
    if(key=='D'){
        if(s>1)
            s/=2;
    }
    if(key=='E'){
        scanf("%d%d",&x1,&y1);
    }
    if(key=='F'){
        d-=50;
    }   
    if(key=='R'){
        d=0;
    }
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