//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <iostream>
#include <cstdlib>
#include <GL/glut.h>

#include "polygon.h"
#include "initOpengl.h"
#include "rectangle.h"

#define DRAWPOL 1
#define DRAWREC 2


using namespace std;
/************************************************************************************************************************
		global variables
************************************************************************************************************************/


int screenWidth = 640;
int screenHeight = 480;
int sel=DRAWPOL; 

int startXY=0;

polygon myPoly; //to polygwno tou xrhsth
rectangle myRec; //to tetragwno apokophs

int timesMoved=0;


struct tempVert
{
	int x,y;
	struct tempVert *nxt;
};
struct tempVert *L=NULL, *R=NULL, *B=NULL, *T=NULL, *final=NULL,*l1=NULL;

void S_H(polygon& Poly, rectangle& Rec); //Sutherland_Hodgman

/************************************************************************************************************************
		keyboard, mouse, menu functions
*************************************************************************************************************************/

void keyEvent(unsigned char key, int x, int y)
{

  switch (key)
  {
	//Quit
	  
	case 'Q':
	case 'q':
		exit(-1);
	break;
	case 'c':
	case 'C':
		S_H(myPoly,myRec);
		glColor3f(0.7,0.2,0.4);
		glBegin(GL_POLYGON);
		for (l1=final; l1!=NULL; l1=l1->nxt)
		{
			glVertex2i(l1->x, l1->y);
		}
		glEnd();
		glFlush();
	default:
	break;	
  }
}



void myMouse(int button, int state, GLint x, GLint y)
{
	static int timesPushed=0;
 
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN&&sel==DRAWPOL)
	{
		myPoly.addVertex(x,y);

	}

	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN &&sel==DRAWREC)
	{
		if (L!=NULL)
		{
			delete[] L;
			delete[] R;
			delete[] T;
			delete[] B;
			delete[] final;
			delete[] l1;


		}
		if (timesPushed){
			glutPostRedisplay();
			glColor3f(0.0, 0.0, 1.0);
			L=R=B=T=final=NULL;
			myPoly.drawPol();
			timesPushed=0;
		}
		
	}
	if (button==GLUT_LEFT_BUTTON && state==GLUT_UP &&sel==DRAWREC)
	{
		timesPushed=1;
		timesMoved=0;
		myRec.setStop(x, screenHeight-y);
		
	}


}



void motionMouse (int x, int y)
{
	 

	if (sel==DRAWREC)
	{
		if (!timesMoved)
		{
			myRec.setStart(x,screenHeight-y);
			timesMoved=1;
		}	
		myRec.drawFromStartTo(x,screenHeight-y);
	}
}




void specialButton(int key, int x, int y)
{
	static int timesPushedF1=0;
	switch (key)
  {
	//Quit
	  
	case GLUT_KEY_F1:
		timesPushedF1++;
		if (timesPushedF1%2)
		{
			sel=DRAWREC;
		}
		else 
		{
			sel=DRAWPOL;
		}
	default:
	break;	
  }
}



/************************************************************************************************************************
** LAB4
*************************************************************************************************************************/

int main (int argc, char *argv[]){



  glutInit(&argc, argv);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(640, 480);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutCreateWindow("lab3");
  init();

  glutDisplayFunc(mainDisplay);
  glutKeyboardFunc(keyEvent);
  glutMouseFunc(myMouse);
  
  //void glutMotionFunc((*func)(int x, int y))
  glutMotionFunc(motionMouse);

  //void glutSpecialFunc(void (*func)(int key, int x, int y));
  glutSpecialFunc(specialButton);
  // menu creation


  glutMainLoop();
  
	exit(-1);

}