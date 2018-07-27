#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 45.0;

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void drawCircle(float radius){
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=radius;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
	glEnd();
}


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glTranslatef(0.0, 0.0, -10.0); //Move forward 10 units


	//clockwise
	glPushMatrix();
		glTranslatef(4.0, 0.0, 0.0);
		glRotatef(_angle, 0.0, 0.0, 1.0);
		glScalef(0.5,0.5,0.5);

		//quad 1
		glPushMatrix();
			glTranslatef(0.0, 3.2, 0.0);
			glScalef(1.0,1.0,1.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.40, -2.5, 0.0);
			glVertex3f(0.40, -2.5, 0.0);
			glVertex3f(0.40, 2.5, 0.0);
			glVertex3f(-0.40, 2.5, 0.0);
			glEnd();
		glPopMatrix();

		//quad 2
		glPushMatrix();
			glRotatef(130.0, 0.0, 0.0, 1.0);
			glTranslatef(0.0, 3.2, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.40, -2.5, 0.0);
			glVertex3f(0.40, -2.5, 0.0);
			glVertex3f(0.40, 2.5, 0.0);
			glVertex3f(-0.40, 2.5, 0.0);
			glEnd();
		glPopMatrix();

		//quad 3
		glPushMatrix();
			glRotatef(230.0, 0.0, 0.0, 1.0);
			glTranslatef(0.0, 3.2, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.40, -2.5, 0.0);
			glVertex3f(0.40, -2.5, 0.0);
			glVertex3f(0.40, 2.5, 0.0);
			glVertex3f(-0.40, 2.5, 0.0);
			glEnd();
		glPopMatrix();
	drawCircle(0.7);

	glPopMatrix();


	//anticlock wise
	glPushMatrix();
		glTranslatef(-4.0, 0.0, 0.0);
		glRotatef(-_angle, 0.0, 0.0, 1.0);
		glScalef(0.5,0.5,0.5);

		//quad 1
		glPushMatrix();
			glTranslatef(0.0, 3.2, 0.0);
			glScalef(1.0,1.0,1.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.40, -2.5, 0.0);
			glVertex3f(0.40, -2.5, 0.0);
			glVertex3f(0.40, 2.5, 0.0);
			glVertex3f(-0.40, 2.5, 0.0);
			glEnd();
		glPopMatrix();

		//quad 2
		glPushMatrix();
			glRotatef(130.0, 0.0, 0.0, 1.0);
			glTranslatef(0.0, 3.2, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.40, -2.5, 0.0);
			glVertex3f(0.40, -2.5, 0.0);
			glVertex3f(0.40, 2.5, 0.0);
			glVertex3f(-0.40, 2.5, 0.0);
			glEnd();
		glPopMatrix();

		//quad 3
		glPushMatrix();
			glRotatef(230.0, 0.0, 0.0, 1.0);
			glTranslatef(0.0, 3.2, 0.0);
			glBegin(GL_QUADS);
			glVertex3f(-0.40, -2.5, 0.0);
			glVertex3f(0.40, -2.5, 0.0);
			glVertex3f(0.40, 2.5, 0.0);
			glVertex3f(-0.40, 2.5, 0.0);
			glEnd();
		glPopMatrix();
	drawCircle(0.7);

	glPopMatrix();

	glutSwapBuffers();
}




void update(int value) {
	_angle += 2.0f;

	if(_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(5, update, 0);
}


int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 800);
	glutInitWindowPosition(200,100);

	//Create the window
	glutCreateWindow("FAN");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(5, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
