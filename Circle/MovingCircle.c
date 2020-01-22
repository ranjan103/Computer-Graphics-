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



void myDisplay() {
    printf("Enter the co-ordinates of circle\n");
    
    // cin>>x1>>y1;
    scanf("%d%d",&x1,&y1);
    
    printf("Enter the value of radius\n");
    scanf("%d",&r);
    int up=1;
    int right=1;
    // glTranslatef(0.0f,0.0f,0);
    while(1){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);
        draw_line();
        if(up){
            if(y1+r<=450)
                y1+=10;
            else{
                up=0;
                y1-=10;
                if(right){
                    if(x1+10<=450){
                        x1+=10;
                    }
                    else{
                        right=0;
                        x1-=10;
                    }
                }
                else{
                    if(x1-10>=50){
                        x1-=10;
                    }
                    else{
                        right=1;
                        x1+=10;
                    }
                }
            }
        }
        else{
            if(y1-r>=50){
                y1-=10;
            }
            else{
                up=1;
                y1+=10;
                if(right){
                    if(x1+10<=450){
                        x1+=10;
                    }
                    else{
                        right=0;
                        x1-=10;
                    }
                }
                else{
                    if(x1-10>=50){
                        x1-=10;
                    }
                    else{
                        right=1;
                        x1+=10;
                    }
                }
            }
        }
        glFlush();
    }
    
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

