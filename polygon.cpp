#include <iostream>
#include "polygon.h"
#include "global.h"

#include <gl/glut.h>

using namespace std;

polygon::polygon(void)
{
	length=0; //megethos pinaka koryfwn
}


polygon::~polygon(void)
{

}


/*
** h drawPolEdge zwgrafizei to polygwno
** metafrazontas to timesPushed tou pontikiou
** ston ari8mo koryfhs tou pinaka apo structs
*/
void polygon::drawPolEdge(int vertex)
{
	int tempx,tempy,tol=20;
	if (vertex==0)
	{
		glBegin(GL_POINTS);
		glColor3f(0,0,0);
		glVertex2i(coordinates[0].x,coordinates[1].y);

		glEnd();
	}
	else
	{
		tempx=coordinates[vertex].x;
		tempy=coordinates[vertex].y;
		//printf(" %d ",coordinates[vertex].y);
		//printf(" %d ",coordinates[0].y);

		//ennwsh ths teleftaias koryfhs me thn  prwth gia to sxhmatismo tou polygvnou
		if ((tempx > coordinates[0].x-tol)&& (tempy< coordinates[0].y + tol)&& (tempx < coordinates[0].x+tol)&& (tempy > coordinates[0].y-tol))
		{
			
			coordinates[vertex].x = coordinates[0].x;
			coordinates[vertex].y = coordinates[0].y;
			length=vertex;
			startXY=1; //start algorithm XY

		}
		glBegin(GL_LINES); //ennwsh twn grammwn analoga me tis syntetagmenes tou xrhsth pao to pontiki
		glColor3f(1,0,0);
		glVertex2i(coordinates[vertex-1].x,coordinates[vertex-1].y);
		glVertex2i(coordinates[vertex].x,coordinates[vertex].y);
		glEnd();

	
	}
	glFlush();
}

/*
** h addVertex
** pros8etei mia koryfh
** kai zwgrafizei tin plevra
*/

void polygon::addVertex(int x, int y)
{
	static int timesPushed=0;

	coordinates[timesPushed].x=x;
	coordinates[timesPushed].y=screenHeight - y; //apo8ikefsi ston pinaka se zevgh x,y

	drawPolEdge(timesPushed);
	if (timesPushed < 10)
	{
		timesPushed++;
	}
	else
	{
		cout << "\nERROR vertices > 10!!\n";
		exit(-1);
	}

}

polygon::polyCoordVertex polygon::getVertex(int i)
{
	return coordinates[i];
}

void polygon::drawPol()
{
	int i;
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.2,0.4);
	for (i=0; i<length; i++)
	{
		glVertex2i(coordinates[i].x, coordinates[i].y);
	}

	glEnd();
	glFlush();
}
