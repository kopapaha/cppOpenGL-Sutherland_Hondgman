#include <GL/glut.h>
#include "global.h"
#include "rectangle.h"

extern polygon myPoly;

rectangle::rectangle(void):startX(0),startY(0),stopX(0),stopY(0)
{
}


rectangle::~rectangle(void)
{
}

void rectangle::setStart(int x, int y)
{
	startX=x;
	startY=y;
}

void rectangle::setStop(int x, int y)
{
	stopX=x;
	stopY=y;
}

int rectangle::getStartX(void)
{
	return startX;
}

int rectangle::getStartY(void)
{
	return startY;
}
int rectangle::getStopX(void)
{
	return stopX;
}
int rectangle::getStopY(void)
{
	return stopY;
}

void rectangle::drawFromStartTo(int x, int y)
{
	static int prevx=startX;
	static int prevy=startY;

	if (x<prevx||y>prevy)
	{
		//glutPostRedisplay();
		//glClearColor(0,0,0,0);
  	glClear(GL_COLOR_BUFFER_BIT);
	myPoly.drawPol();
	glFlush();
	
	}
	
	glBegin( GL_QUADS );

		glColor3f(0,1,0);
		glVertex2i(startX, startY);
		glVertex2i(x, startY);
		glVertex2i(x, y);
		glVertex2i(startX, y);

	glEnd();
	glFlush();
	prevx=x;
	prevy=y;
}

void rectangle::draw()
{
	glBegin( GL_QUADS );

		glColor3f(0,1,0);
		glVertex2i(startX, startY);
		glVertex2i(stopX, startY);
		glVertex2i(stopX, stopY);
		glVertex2i(startX, stopY);

	glEnd();
	glFlush();
}