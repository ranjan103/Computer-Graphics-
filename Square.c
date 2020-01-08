#include<GL/glut.h>


void display(){
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Now, draw a red 1X1 Square centered at origin
    glBegin(GL_QUADS);
        glColor3f(1.0f,0.0f,0.0f);//RED
        glVertex2f(-0.5f,-0.5f); //x,y - co-ordinates
        glColor3f(0.75f,0.0f,0.25f);
        glVertex2f(0.5f,-0.5f);
        glColor3f(1.0f,-0.5f,0.35f);
        glVertex2f(0.5f,0.5f);
        glColor3f(0.7f,0.0f,-0.1f);
        glVertex2f(-0.5f,0.5f);
    glEnd();

    glFlush(); //Render now
}


int main(int argc,char **argv){

    // INITIALISATION

        glutInit(&argc,argv); // Initialize GLUT
        glutCreateWindow("OpenGL Setup Test"); // Create a window with the title
        glutInitWindowSize(320,320); // Set the window's initial width and height
        glutInitWindowPosition(50,50); // Position the window's initial top-left corner
        glutDisplayFunc(display); // Register display callback handler for window re-paint
        glutMainLoop();  // Enter the event-processing loop

    return 0;

}
