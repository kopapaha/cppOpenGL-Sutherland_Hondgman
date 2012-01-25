#pragma once



extern int screenWidth;
extern int screenHeight;
extern int menu; // for menu creation
extern int sel; // for menu choices

extern int startXY;
//extern polygon myPoly;

struct tempVert
{
	int x,y;
	struct tempVert *nxt;
};
extern struct tempVert *L, *R, *B, *T, *final, *l1;
