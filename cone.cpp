#include <iostream>
#include <stdlib.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

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

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

float car_move = 0.0;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	//glRotatef(-4.5, 1.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

    /*
     glBegin(GL_LINES);
    //line 4
    glVertex3f(0.40, 1.0, 0.0);
    glVertex3f(0.70, 1.0, 0.0);
    glEnd();
    */

    glPushMatrix();
        glTranslatef(-0.9, 0.0, 0.0); //Move forward 5 units
        glRotatef(_angle, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)
        //glTranslatef(-3.0, 0.0, -7.0); //Move forward 5 units
        glColor3f(0.0, 0.0, 1.0);
        glutWireSphere(0.8, 20, 20);

    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 1.0);
        glTranslatef(-3.0, 0.0, -7.0); //Move forward 5 units
        glRotatef(-90, 1.0, 0.0, 0.0);
        glRotatef(_angle, 0.0, 0.0, 1.0);
        glutWireCone(1.0, 4, 30, 20);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-3.0, 3.0, -7.0); //Move forward 5 units
        glRotatef(-90, 1.0, 0.0, 0.0);
        glRotatef(_angle, 0.0, 0.0, 1.0);
        glutWireTorus(0.2, 0.9, 20, 20);

    glPopMatrix();



	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	    /*

	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}
	*/

    car_move += 0.01f;
    if(car_move > 5.0){
        car_move = -3.2;
    }

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200,100);

	//Create the window
	glutCreateWindow("Cone");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(20, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}





