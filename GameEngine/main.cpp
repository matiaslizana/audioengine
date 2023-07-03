#include<GL/glut.h>
#include<iostream>
#include<vector>

std::vector<std::pair<float, float>> emitters;

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Paint emitters
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	for (size_t i = 0; i < emitters.size(); i++)
	{
		glVertex2d(emitters[i].first, 480 - emitters[i].second);
	}

	//Paint listener
	glColor3f(0.0, 0.0, 1.0);
	glVertex2d(320,240);
	glEnd();

	glFlush();
}

void mouse_move(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		emitters.push_back(std::pair<float, float>{x, y});
		glutPostRedisplay();
		std::cout << "CLICK " << x << ", " << y << std::endl;
	}
}

void main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);
	glutMouseFunc(mouse_move);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
	glutMainLoop();
}