#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h>
#define maxWD 640 
#define maxHT 480 
  
// rotation speed 
#define thetaSpeed 0.05 
  
// this creates delay between two actions 
void delay(unsigned int mseconds) 
{ 
    clock_t goal = mseconds + clock(); 
    while (goal > clock()) 
        ; 
} 
  
// this is a basic init for the glut window 
void myInit(void) 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0.0, maxWD, 0.0, maxHT); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glFlush(); 
} 
  
// this function just draws a point 
void drawPoint(int x, int y) 
{ 
    glPointSize(7.0); 
    glColor3f(0.0f, 0.0f, 1.0f); 
    glBegin(GL_POINTS); 
    glVertex2i(x, y); 
    glEnd(); 
} 
  
void rotateAroundPt(int px, int py, int cx, int cy) 
{ 
    float theta = 0.0; 
    while (1) { 
        glClear(GL_COLOR_BUFFER_BIT); 
        int xf, yf; 
  
        // update theta anticlockwise rotation 
        theta = theta + thetaSpeed; 
  
        // check overflow 
        if (theta >= (2.0 * 3.14159)) 
            theta = theta - (2.0 * 3.14159); 
  
        // actual calculations.. 
        xf = cx + (int)((float)(px - cx) * cos(theta)) 
             - ((float)(py - cy) * sin(theta)); 
        yf = cy + (int)((float)(px - cx) * sin(theta)) 
             + ((float)(py - cy) * cos(theta)); 
  
        // drawing the centre point 
        drawPoint(cx, cy); 
  
        // drawing the rotating point 
        drawPoint(xf, yf); 
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
        delay(10); 
    } 
} 
  
// this function will translate the point 
void translatePoint(float x1, float y1, float x2, float y2,float tx) 
{ 
   // int fx = x1, fy = y1; 
        glClear(GL_COLOR_BUFFER_BIT); 
  
        // update 
       float px = x1*cos(tx) - y1*sin(tx); 
        float py = y1*cos(tx) + x1*sin(tx); 

   float px1 = x2*cos(tx) - y2*sin(tx); 
        float py1 = y2*cos(tx) + x2*sin(tx); 


      glColor3f( 1, 1, 1 );
glBegin(GL_LINES);
    glVertex2f(px, py);
    glVertex2f(px1, py1);
glEnd();

glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
glEnd();
  
//        drawPoint(px, py); // drawing the point 
  
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
      
} 
  
// this function draws 
void scalePoint(int px, int py, int sx, int sy) 
{ 
    int fx, fy; 
    while (1) { 
        glClear(GL_COLOR_BUFFER_BIT); 
  
        // update 
        fx = px * sx; 
        fy = py * sy; 
  
        drawPoint(fx, fy); // drawing the point 
  
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
        delay(500); 
  
        glClear(GL_COLOR_BUFFER_BIT); 
  
        // update 
        fx = px; 
        fy = py; 
  
        // drawing the point 
        drawPoint(fx, fy); 
        glFlush(); 
        // creating a delay 
        // so that the point can be noticed 
    //    delay(500); 
    } 
} 
  
// Actual display function 
void myDisplay(void) 
{ 
    int opt; 
    
float x1,y1,x2,y2;
printf("Enter x1,y1,x2,y2\n");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    float tx,ty;
    printf("Enter rotation degree\n");
    scanf("%f",&tx);
tx = (tx*3.14)/180;
        translatePoint(x1, y1, x2, y2,tx); 
    
} 
  
int main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(maxWD, maxHT); 
    glutInitWindowPosition(100, 150); 
    glutCreateWindow("Transforming point"); 
    glutDisplayFunc(myDisplay); 
    myInit(); 
    glutMainLoop(); 
} 