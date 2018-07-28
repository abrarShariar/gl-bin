#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

float _angle_p1 = 0.0;
float _angle_p2 = 0.0;
float _angle_p3 = 0.0;

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
	glBegin(GL_LINES);
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


void drawSun(float radius){
	glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0, 0.0, 0.0);
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

void drawOrbit(float radius){
	glBegin(GL_LINES);
  glColor3f(1.0, 1.0, 1.0);
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

void drawPlanet(float radius){
  glBegin(GL_TRIANGLE_FAN);
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


void drawScene(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
  glLoadIdentity(); //Reset the drawing perspective
  glTranslatef(0.0, 0.0, -10.0); //Move forward 10 units

  //sun
  drawSun(0.7);
  //orbit
  drawOrbit(1.5);
  drawOrbit(2.4);
  drawOrbit(3.5);

  //planets
  glPushMatrix();
    glRotatef(_angle_p1, 0.0, 0.0, 1.0);
    glTranslatef(1.5, 0.0, 0.0);
    glColor3f(0.0, 1.5, 0.0);
    drawPlanet(0.2);
  glPopMatrix();

  glPushMatrix();
    glRotatef(_angle_p2, 0.0, 0.0, 1.0);
    glTranslatef(2.4, 0.0, 0.0);
    glColor3f(1.0, 1.5, 0.0);
    drawPlanet(0.4);
  glPopMatrix();

  glPushMatrix();
    glRotatef(_angle_p3, 0.0, 0.0, 1.0);
    glTranslatef(3.5, 0.0, 0.0);
    glColor3f(0.0, 1.5, 1.5);
    drawPlanet(0.5);
  glPopMatrix();

  glutSwapBuffers();
}

void updatePlanet3(int value) {
  _angle_p3 += 2.0f;

	if(_angle_p3 > 360) {
		_angle_p3 -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(40, updatePlanet3, 0);
}

void updatePlanet2(int value) {
  _angle_p2 += 2.0f;

	if(_angle_p2 > 360) {
		_angle_p2 -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(30, updatePlanet2, 0);
}

void updatePlanet1(int value) {
	_angle_p1 += 2.0f;

	if(_angle_p1 > 360) {
		_angle_p1 -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(10, updatePlanet1, 0);
}


int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500,1000);
	glutInitWindowPosition(200,100);

	//Create the window
	glutCreateWindow("Solar System");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(10, updatePlanet1, 0); //Add a timer
  glutTimerFunc(30, updatePlanet2, 0); //Add a timer
  glutTimerFunc(40, updatePlanet3, 0); //Add a timer

	glutMainLoop();
	return 0;
}
