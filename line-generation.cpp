#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <cmath>
#include <iostream>
#include <GL/freeglut.h>
using namespace std;
  int first=0;  
  float xi,yi,xf,yf;  

int algo=0;
void ddd(float x, float y){
glBegin(GL_POINTS);
glColor3f(1.0,1.0,1.0);
glVertex2d(x,y);
glEnd();
glFlush();
}


void dda(int a, int b, int c, int d){
        

	float dx = c - a;
	float dy = d - b;
	float x=a,y=b;
	int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	float xIncrement = dx / (float)steps;
	float yIncrement = dy / (float)steps;
	ddd(x,y);

	for (int i = 0; i < steps; i++) {
		x += xIncrement;
		y += yIncrement;

		ddd(x, y);
	}

  }

void bre()  //Bresenham's Algorithm
{
glColor3f (1.0, 0.0, 0.0);
   glBegin (GL_POINTS);
  int dx = abs (xf - xi);
  int dy = abs (yf - yi);
  int x, y;
  if (dx >= dy)
  {
   int d = 2*dy-dx;
   int ds = 2*dy;
   int dt = 2*(dy-dx);
       if (xi < xf)
       {
            x = xi;
            y = yi;
       }
        else
        {
             x = xf;
             y = yf;
             xf = xi;
             yf = yi;
        }
       glVertex2f (x, y);
   while (x < xf)
   {
        if (d < 0)
        d += ds;
        else {
             if (y < yf) {
              y++;
              d += dt;
             }
             else {
              y--;
              d += dt;
             }
            }
   x++;
        glVertex2f (x, y);
       }
       }
       else {
             int d = 2*dx-dy;
             int ds = 2*dx;
             int dt = 2*(dx-dy);
             if (yi < yf) {
             x = xi;
             y = yi;
             }
             else {
             x = xf;
            y = yf;
             yf = yi;
             xf = xi;
             }
            glVertex2f (x, y);
        while (y < yf)
        {
              if (d < 0)
                 d += ds;
              else {
                      if (x > xf){
                      x--;
                      d += dt;
                   } else {
                      x++;
                      d += dt;
                   }
              }
              y++;
              glVertex2f(x, y);
        }

       }
       glEnd();

       glFlush();
}



void mouse(int button, int state, int x, int y) {	
	  
	  int xx=x*2-500;
	  int yy=y*2-500;
	  yy=-yy;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

    	if(algo==1){

           switch(first)  
            {  
            case 0:  
                 xi=xx;  
                 yi=yy;  
                 first=1;  
                 break;  
            case 1:  
                 xf=xx;  
                 yf=yy;  
                 dda(xi,yi,xf,yf);  
                 first=0;
                 break;  
            }  

        } 
        

            if(algo==2){

           switch(first)  
            {  
            case 0:  
                 xi=xx;  
                 yi=yy;  
                 first=1;  
                 break;  
            case 1:  
                 xf=xx;  
                 yf=yy;  
                 bre();  
                 first=0;
                 break;  
            }  

        }    
}

}


void display()
{
	   glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(1,1,1);
     glRasterPos2f(-450,450);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Author : Meeta Chaudhary");

     glRasterPos2f(-450,-400);	
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Press 'd' for DDA,'b' For Bresenham's and 'ESC' to exit");
     glRasterPos2f(-450,-450);	
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Press 'spacebar' to clear the screen");
    glFlush();

}


void keyboard (unsigned char key, int x, int y) {

	if (key == 32) {

		glClear(GL_COLOR_BUFFER_BIT);
		glutSwapBuffers();
	}
    
    else if(key==100){
    	glClear(GL_COLOR_BUFFER_BIT);
    	
     algo=1;  
     glColor3f(1,1,1);
     glRasterPos2f(-450,450);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Meeta Chaudhary 500040803");
     glColor3f(1,1,1);
     glRasterPos2f(-450,-400);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"DDA Algorithm");
     glFlush();
    }

    else if(key==98){
    	glClear(GL_COLOR_BUFFER_BIT);
    	
     algo=2;  
     glColor3f(1,1,1);
     glRasterPos2f(-450,450);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Meeta Chaudhary 500040803");
     glColor3f(1,1,1);
     glRasterPos2f(-450,-400);
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Bresenham's Algorithm");
     glFlush();
    }
    else if(key==27){
    	glutDestroyWindow(1);
    }
    else{
     glColor3f(1,1,1);	
     glRasterPos2f(-450,-300);	
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Wrong Key! Press 'd' for DDA,'b' For Bresenham's and 'ESC' to exit");
     glRasterPos2f(-450,-350);	
     glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)"Press spacebar to clear the screen");
     glFlush();	
    }
}

int main (int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Line generation algorithm");
	glMatrixMode(GL_PROJECTION);  
       glLoadIdentity();  
       gluOrtho2D(-500,500,-500,500);  
         
	glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}