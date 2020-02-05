#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
// #include <windows.h>

void myInit() {
   
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
int x1,y1;
int r;
int X,Y;
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

void draw_circle() {
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

void draw_line(int x1, int x2, int y1, int y2) {
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x,y;

    dx = x2-x1;
    dy = y2-y1;

    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    incx = 1;
    if (x2 < x1) incx = -1;
    incy = 1;
    if (y2 < y1) incy = -1;
    x = x1; y = y1;
    if (dx > dy) {
        draw_pixel(x, y);
        e = 2 * dy-dx;
        inc1 = 2*(dy-dx);
        inc2 = 2*dy;
        for (i=0; i<dx; i++) {
            if (e >= 0) {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            draw_pixel(x, y);
        }

    } else {
        draw_pixel(x, y);
        e = 2*dx-dy;
        inc1 = 2*(dx-dy);
        inc2 = 2*dx;
        for (i=0; i<dy; i++) {
            if (e >= 0) {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            draw_pixel(x, y);
        }
    }
}

void myDisplay() {
    printf("Enter the co-ordinates of circle\n");
    
    // cin>>x1>>y1;
    x1=300,y1=200;
    r=100;
    X=300,Y=480;

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    draw_circle();
    draw_line(X,x1,Y,y1+r);
    draw_line(X-100,X+100,Y,Y);
    glFlush();
}

int main(int argc, char **argv) {

    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Cricle Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}

