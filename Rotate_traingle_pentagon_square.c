#include <GL/glut.h>

GLfloat angle = 0.0f;  
int refreshMills = 10;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
}

void Timer(int value) {
   glutPostRedisplay();      
   glutTimerFunc(refreshMills, Timer, 0); 
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);   
   glMatrixMode(GL_MODELVIEW);     
   glLoadIdentity();               
   glPushMatrix();                    
   glTranslatef(0.5f, 0.5f, 0.0f);   
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glBegin(GL_QUADS);                 
      glColor3f(1.0f, 0.0f, 0.0f);    
      glVertex2f(-0.3f, -0.3f);
      glVertex2f( 0.3f, -0.3f);
      glVertex2f( 0.3f,  0.3f);
      glVertex2f(-0.3f,  0.3f);
   glEnd();
   glPopMatrix();


   glPushMatrix();                    
   glTranslatef(-0.5f, 0.5f, 0.0f);   
   glRotatef(angle, 0.0f, 1.0f, 0.0f);
   glBegin(GL_TRIANGLES);                 
      glColor3f(1.0f, 0.0f, 0.0f);    
      glVertex2f(0.0f, 0.0f);
      glVertex2f( 0.3f, -0.3f);
      glVertex2f( 0.3f,  0.3f); 
   glEnd();
   glPopMatrix();


   glPushMatrix();                    
   glTranslatef(0.0f, -0.5f, 0.0f);   
   glRotatef(angle, 1.0f, 0.0f, 0.0f);
   glBegin(GL_POLYGON);                 
      glColor3f(1.0f, 0.0f, 0.0f);    
      glVertex2f(0.0f, 0.2f);
      glVertex2f( -0.2f, 0.0f);
      glVertex2f( -0.1f,  -0.2f);
      glVertex2f( 0.1f,  -0.2f); 
      glVertex2f( 0.2f,  0.0f); 
   glEnd();
   glPopMatrix();



   glutSwapBuffers();
     angle += 0.66f;
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);          
   glutInitDisplayMode(GLUT_DOUBLE);  
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow("Animation via Idle Function");  
   glutDisplayFunc(display);       
   glutTimerFunc(0, Timer, 0);     
   initGL();                       
   glutMainLoop();                 
   return 0;
}
