#include<GL/glut.h>

void main(int argc, char ** argv){
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,100);
	glutCreateWindow("HellO worlds");
	glutMainLoop();
	glLineWidth(2.5); 
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex3f(0.0, 0.0, 0.0);
glVertex3f(15, 0, 0);
glEnd();
}
