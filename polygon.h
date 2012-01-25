#pragma once

#define maxPolVertices 20

class polygon
{
private:

	//koryfes polygwnou
	struct polyVertices
	{
		int x;
		int y;
	};
	struct polyVertices coordinates[maxPolVertices];
	typedef struct polyVertices polyCoordVertex;

	/*
	** drawPolEdge(int vertex)
	** zwgrafizei to polygwno
	** metafrazontas to timesPushed tou pontikiou
	** ston ari8mo koryfhs tou pinaka apo structs
	*/
	void drawPolEdge(int vertex);



public:
	int length; //megethos pinaka koryfwn==#koryfwn-1
	
	polygon(void);
	~polygon(void);

	/*
	** addVertex(int x, int y)
	** pros8etei mia koryfh
	** kai zwgrafizei tin plevra
	*/
	void addVertex(int x, int y);
	polyCoordVertex getVertex(int i);
	void drawPol();
	


};
