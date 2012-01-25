#include <iostream>
#include <GL/glut.h>

#include "polygon.h"
#include "rectangle.h"
#include "global.h"

using namespace std;

//struct tempVert
//{
//	int x,y;
//	struct tempVert *nxt;
//};
//
//struct tempVert *L=NULL, *R=NULL, *B=NULL, *T=NULL, *final=NULL,*l1=NULL;


//pros8hkh stoixeiou sto telos ths listas
//k lista eisodou L R B T
//p times x,y eisodou
void add(struct tempVert **k, struct tempVert *p )
{
	struct tempVert *l,*l1;
	

	l = new tempVert();

	l->nxt = NULL;
	l->x = p->x;
	l->y = p->y;
	if (*k==NULL)
	{
		*k=l;
	}
	else 
	{
		for (l1=*k;l1->nxt!=NULL;l1=l1->nxt){}
		l1->nxt=l;
	}
}


void S_H(polygon& poly, rectangle& rec)
{
	float lamda;
	struct tempVert s, e, tmp, *l;
	

	int i, tmplen=0;

	/*cout << "poly" << endl;
	for (i=0; i<poly.length; i++)
	{
		cout << poly.getVertex(i).x << " " << poly.getVertex(i).y << endl;
	
	}

	cout << "rec\n" << rec.getStartX() << " " << rec.getStartY() << "\n" << rec.getStopX() << " " << rec.getStopY() <<endl;
	*/

	//arxikopoihsh ths listas L
	for (i=0; i<poly.length; i++)
	{
		tmp.x = poly.getVertex(i).x;
		tmp.y = poly.getVertex(i).y;
		add(&L, &tmp);
		//if (inside(poly.getVertex(i).x, poly.getVertex(i).y, s) && inside(poly.getVertex(i).x, poly.getVertex(i).y, e)){}
	}

	//cout << endl << "list L:" << endl;
	//for (l=L; l!=NULL; l=l->nxt)
	//{
	//	cout << l->x << " " << l->y << endl;
	//}

	
				//lamda=(float)(L->y-l->y) / (float)(L->x-l->x);
			//cout << "lamda: " << lamda <<endl;
			//l->x < rec.getStartX() && l->nxt->x < rec.getStartX() NO OUT
			//l->x > rec.getStartX() && l->nxt->x > rec.getStartX() OUT l->nxt
			//l->x > rec.getStartX() && l->nxt->x < rec.getStartX() OUT rec.getStartX,Y=lamda...
			//l->x < rec.getStartX() && l->nxt->x > rec.getStartX() OUT (rec.startX,y=lamda...),(l->nxt)
			//lamda = (l->nxt->y-l->y) / (l->nxt->x-l->x)
			//y = lamda*rec.startX-lamda*l->x+l->y



	//diatreksi twn koryfwn tis ka8e listas kai elegxos gia in /out
	//Diatreksh L
	for (l=L; l!=NULL; l=l->nxt)
	{
		if (l->nxt!=NULL){
			if (l->x < rec.startX && l->nxt->x < rec.startX)
			{
				// no Ouput
			}
			else if (l->x > rec.startX && l->nxt->x > rec.startX)
			{
				add(&R,l->nxt);
			}
			else if (l->x > rec.startX && l->nxt->x < rec.startX)
			{
				tmp.x=rec.startX;
				lamda=(float)(l->nxt->y-l->y) / (float)(l->nxt->x-l->x);
				tmp.y=(int) (lamda*(float)rec.startX-lamda*(float)l->x+(float)l->y);
				add(&R,&tmp);
			}
			else if (l->x < rec.startX && l->nxt->x > rec.startX)
			{
				tmp.x=rec.startX;
				lamda=(float)(l->nxt->y-l->y) / (float)(l->nxt->x-l->x);
				tmp.y=(int) (lamda*(float)rec.startX-lamda*(float)l->x+(float)l->y);
				add(&R,&tmp);
				add(&R,l->nxt);
			}

		}
		else
		{//l->nxt==L

			if (l->x < rec.startX && L->x < rec.startX)
			{
				// no Ouput
			}
			else if (l->x > rec.startX && L->x > rec.startX)
			{
				add(&R,L);
			}
			else if (l->x > rec.startX && L->x < rec.startX)
			{
				tmp.x=rec.startX;
				lamda=(float)(L->y-l->y) / (float)(L->x-l->x);
				tmp.y=(int) (lamda*(float)rec.startX-lamda*(float)l->x+(float)l->y);
				add(&R,&tmp);
			}
			else if (l->x < rec.startX && L->x > rec.startX)
			{
				tmp.x=rec.startX;
				lamda=(float)(L->y-l->y) / (float)(L->x-l->x);
				tmp.y=(int) (lamda*(float)rec.startX-lamda*(float)l->x+(float)l->y);
				add(&R,&tmp);
				add(&R,L);
			}
		}

	}

	//cout << endl << "Lista R:" << endl;
	//for (l=R; l!=NULL; l=l->nxt)
	//{
	//	cout << l->x << " " << l->y << endl;
	//	//glPointSize(4);
	//	//glColor3f(1.0,0.0,0.0);
	//	//glBegin(GL_POINTS);
	//	//
	//	//
	//	//glVertex2i(l->x,l->y);
	//	//glEnd();
	//	//glFlush();
	//		
	//}


	//Diatreksh R
	for (l=R; l!=NULL; l=l->nxt)
	{
		if (l->nxt!=NULL){
			if (l->x > rec.stopX && l->nxt->x > rec.stopX)
			{
				// no Ouput
			}
			else if (l->x < rec.stopX && l->nxt->x < rec.stopX)
			{
				add(&B,l->nxt);
			}
			else if (l->x < rec.stopX && l->nxt->x > rec.stopX)
			{
				tmp.x=rec.stopX;
				lamda=(float)(l->nxt->y-l->y) / (float)(l->nxt->x-l->x);
				tmp.y=(int) (lamda*(float)rec.stopX-lamda*(float)l->x+(float)l->y);
				add(&B,&tmp);
			}
			else if (l->x > rec.stopX && l->nxt->x < rec.stopX)
			{
				tmp.x=rec.stopX;
				lamda=(float)(l->nxt->y-l->y) / (float)(l->nxt->x-l->x);
				tmp.y=(int) (lamda*(float)rec.stopX-lamda*(float)l->x+(float)l->y);
				add(&B,&tmp);
				add(&B,l->nxt);
			}

		}
		else
		{//l->nxt==R

			if (l->x > rec.stopX && R->x > rec.stopX)
			{
				// no Ouput
			}
			else if (l->x < rec.stopX && R->x < rec.stopX)
			{
				add(&B,R);
			}
			else if (l->x < rec.stopX && R->x > rec.stopX)
			{
				tmp.x=rec.stopX;
				lamda=(float)(R->y-l->y) / (float)(R->x-l->x);
				tmp.y=(int) (lamda*(float)rec.stopX-lamda*(float)l->x+(float)l->y);
				add(&B,&tmp);
			}
			else if (l->x > rec.stopX && R->x < rec.stopX)
			{
				tmp.x=rec.stopX;
				lamda=(float)(R->y-l->y) / (float)(R->x-l->x);
				tmp.y=(int) (lamda*(float)rec.stopX-lamda*(float)l->x+(float)l->y);
				add(&B,&tmp);
				add(&B,R);
			}
		}

	}
	//cout << endl << "Lista B:" << endl;
	//for (l=B; l!=NULL; l=l->nxt)
	//{
	//	cout << l->x << " " << l->y << endl;
	//	//glPointSize(4);
	//	//glColor3f(1.0,0.0,0.0);
	//	//glBegin(GL_POINTS);
	//	//
	//	//
	//	//glVertex2i(l->x,l->y);
	//	//glEnd();
	//	//glFlush();
	//		
	//}





	//Diatreksh B
	for (l=B; l!=NULL; l=l->nxt)
	{
		if (l->nxt!=NULL){
			if (l->y < rec.stopY && l->nxt->y < rec.stopY)
			{
				// no Ouput
			}
			else if (l->y > rec.stopY && l->nxt->y > rec.stopY)
			{
				add(&T,l->nxt);
			}
			else if (l->y > rec.stopY && l->nxt->y < rec.stopY)
			{
				tmp.y=rec.stopY;
				lamda=(float)(l->nxt->y-l->y) / (float)(l->nxt->x-l->x);
				tmp.x=(int) (((float)1/lamda)*(float)rec.stopY - ((float)1/lamda)*(float)l->y+ (float)l->x);
				add(&T,&tmp);
			}
			else if (l->y < rec.stopY && l->nxt->y > rec.stopY)
			{
				tmp.y=rec.stopY;
				lamda=(float)(l->nxt->y-l->y) / (float)(l->nxt->x-l->x);
				tmp.x=(int) (((float)1/lamda)*(float)rec.stopY - ((float)1/lamda)*(float)l->y+ (float)l->x);
				add(&T,&tmp);
				add(&T,l->nxt);
			}

		}
		else
		{//l->nxt==B

			if (l->y < rec.stopY && B->y < rec.stopY)
			{
				// no Ouput
			}
			else if (l->y > rec.stopY && B->y > rec.stopY)
			{
				add(&T,B);
			}
			else if (l->y > rec.stopY && B->y < rec.stopY)
			{
				tmp.y=rec.stopY;
				lamda=(float)(B->y-l->y) / (float)(B->x-l->x);
				tmp.x=(int) (((float)1/lamda)*(float)rec.stopY - ((float)1/lamda)*(float)l->y+ (float)l->x);
				add(&T,&tmp);
			}
			else if (l->y < rec.stopY && B->y > rec.stopY)
			{
				tmp.y=rec.stopY;
				lamda=(float)(B->y-l->y) / (float)(B->x-l->x);
				tmp.x=(int) (((float)1/lamda)*(float)rec.stopY - ((float)1/lamda)*(float)l->y+ (float)l->x);
				add(&T,&tmp);
				add(&T,B);
			}
		}

	}

	//cout << endl << "Lista T:" << endl;
	//for (l=T; l!=NULL; l=l->nxt)
	//{
	//	cout << l->x << " " << l->y << endl;
	//	glPointSize(6);
	//	glColor3f(1.0,0.4,0.0);
	//	glBegin(GL_POINTS);
	//	
	//	
	//	glVertex2i(l->x,l->y);
	//	glEnd();
	//	glFlush();
	//		
	//}

	//Diatreksh T
	for (l=T; l!=NULL; l=l->nxt)
	{
		if (l->nxt!=NULL){
			if (l->y > rec.startY && l->nxt->y > rec.startY)
			{
				// no Ouput
			}
			else if (l->y < rec.startY && l->nxt->y < rec.startY)
			{
				add(&final,l->nxt);
			}
			else if (l->y < rec.startY && l->nxt->y > rec.startY)
			{
				tmp.y=rec.startY;
				lamda=(float)(l->nxt->y-l->y) / (float)(l->nxt->x-l->x);
				tmp.x=(int) (((float)1/lamda)*(float)rec.startY - ((float)1/lamda)*(float)l->y+ (float)l->x);
				add(&final,&tmp);
			}
			else if (l->y > rec.startY && l->nxt->y < rec.startY)
			{
				tmp.y=rec.startY;
				lamda=(float)(l->nxt->y-l->y) / (float)(l->nxt->x-l->x);
				tmp.x=(int) (((float)1/lamda)*(float)rec.startY - ((float)1/lamda)*(float)l->y+ (float)l->x);
				add(&final,&tmp);
				add(&final,l->nxt);
			}

		}
		else
		{//l->nxt==T

			if (l->y > rec.startY && T->y > rec.startY)
			{
				// no Ouput
			}
			else if (l->y < rec.startY && T->y < rec.startY)
			{
				add(&final,T);
			}
			else if (l->y < rec.startY && T->y > rec.startY)
			{
				tmp.y=rec.startY;
				lamda=(float)(T->y-l->y) / (float)(T->x-l->x);
				tmp.x=(int) (((float)1/lamda)*(float)rec.startY - ((float)1/lamda)*(float)l->y+ (float)l->x);
				add(&final,&tmp);
			}
			else if (l->y > rec.startY && T->y < rec.startY)
			{
				tmp.y=rec.startY;
				lamda=(float)(T->y-l->y) / (float)(T->x-l->x);
				tmp.x=(int) (((float)1/lamda)*(float)rec.startY - ((float)1/lamda)*(float)l->y+ (float)l->x);
				add(&final,&tmp);
				add(&final,T);
			}
		}

	}

	//cout << endl << "Lista final:" << endl;
	//for (l=final; l!=NULL; l=l->nxt)
	//{
	//	cout << l->x << " " << l->y << endl;
	//	glPointSize(6);
	//	glColor3f(1.0,0.4,0.0);
	//	glBegin(GL_POINTS);
	//	
	//	
	//	glVertex2i(l->x,l->y);
	//	glEnd();
	//	glFlush();
	//		
	//}

}