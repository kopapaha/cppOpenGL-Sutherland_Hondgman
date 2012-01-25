#pragma once
#include "polygon.h"
class rectangle
{
private:
	int startX, startY, stopX, stopY;

public:
	rectangle(void);
	~rectangle(void);

	void setStart(int x, int y);
	void setStop(int x, int y);

	int getStartX(void);
	int getStartY(void);
	int getStopX(void);
	int getStopY(void);

	void drawFromStartTo(int x, int y);
	void draw();

	friend void S_H(polygon& poly, rectangle& rec);
};

