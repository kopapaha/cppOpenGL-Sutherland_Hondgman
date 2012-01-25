void mainDisplay(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();

}

void init(){
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0, 480); 
	glClearColor(0,0,0,0);
  	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	

}

