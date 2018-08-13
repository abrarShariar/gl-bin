
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

int gameOn = 1;
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

void keyboard(unsigned char key, int x, int y)
{
    if(key=='p')
    {
        if(gameOn == 1){
            gameOn = 0;
        } else {
            gameOn = 1;
        }
        glutPostRedisplay();
    }
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

float car_move = 0.0;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(-.5, -.5, -7.0); //Move forward 5 units

    glPushMatrix();
    glRotatef(_angle, 0.0, 1.0, 0.0);
    //head
    glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glTranslatef(0.0, 2.0, 0.0);
        glutSolidCube(0.5);
     glPopMatrix();


    //body
     glPushMatrix();
        glColor3f(1.0,1.0,0.0);
        glTranslatef(0.0, 1.0, 0.0);
        glScalef(1.0, 1.5, 1.0);
        glutSolidCube(1.0);
     glPopMatrix();

     //shirt right
     glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(0.7, 1.55, 0.0);
        glScalef(-0.4, -0.5, -0.5);
        glutSolidCube(1.0);
     glPopMatrix();

    //shirt left
     glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-0.7, 1.55, 0.0);
        glScalef(-0.4, -0.5, -0.5);
        glutSolidCube(1.0);
     glPopMatrix();

    //hand left
     glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glTranslatef(-0.7, 0.83, 0.0);
        glScalef(-0.3, -0.95, -0.5);
        glutSolidCube(1.0);
     glPopMatrix();

      //hand right
     glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glTranslatef(0.7, 0.83, 0.0);
        glScalef(-0.3, -0.95, -0.5);
        glutSolidCube(1.0);
     glPopMatrix();

    //pant right
     glPushMatrix();
        glColor3f(0.0,0.0,1.0);
        glTranslatef(0.3, 0.0, 0.0);
        glScalef(-0.4, -.5, -1.0);
        glutSolidCube(1.0);
     glPopMatrix();

      //pant left
     glPushMatrix();
        glColor3f(0.0,0.0,1.0);
        glTranslatef(-0.3, 0.0, 0.0);
        glScalef(-0.4, -.5, -1.0);
        glutSolidCube(1.0);
     glPopMatrix();

      //leg right
     glPushMatrix();
        glColor3f(2.5,2.5,0.0);
        glTranslatef(0.3, -.5, 0.0);
        glScalef(-0.3, -.5, -1.0);
        glutSolidCube(1.0);
     glPopMatrix();

    //leg left
     glPushMatrix();
        glColor3f(2.5,2.5,0.0);
        glTranslatef(-0.3, -.5, 0.0);
        glScalef(-0.3, -.5, -1.0);
        glutSolidCube(1.0);
     glPopMatrix();


    glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
    if(gameOn == 1){
        _angle += 2.0f;
        if (_angle > 360) {
            _angle -= 360;
        }
    }

	    /*
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}
	*/

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(200,100);

	//Create the window
	glutCreateWindow("Rotation");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(20, update, 0); //Add a timer
    glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}

