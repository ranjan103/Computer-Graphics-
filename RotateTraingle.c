#include<GL/glut.h>

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);        // Clear the color buffer (background)

    // glRotatef(90.0f,0,0,0);
   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_TRIANGLES);           // Each set of 4 vertices form a quad
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(0.5, 0); // x, y
        glVertex2f( -0.5, 0);
        glVertex2f( 0, 1);

   glEnd();

    glFlush();  // Render now
   
}


void DrawTraingle(){
    float theta=0.005f;
    int cnt=0;
    while(1){
        glClear(GL_COLOR_BUFFER_BIT);

        glRotatef(theta,1,1,1);
        // theta=theta+0.000001;
        // if(theta>360)theta-=360;
        display();
    }
}


int main(int argc,char **argv){

    // INITIALISATION

        glutInit(&argc,argv); // Initialize GLUT
        glutCreateWindow("OpenGL Setup Test"); // Create a window with the title
        glutInitWindowSize(320,320); // Set the window's initial width and height
        glutInitWindowPosition(50,50); // Position the window's initial top-left corner
        glutDisplayFunc(DrawTraingle); // Register display callback handler for window re-paint
        glutMainLoop();  // Enter the event-processing loop


    return 0;

}
