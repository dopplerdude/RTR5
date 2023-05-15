// Header files
#include<GL/freeglut.h>

// Global variable declarations
bool bIsFullScreen = false;

enum { TRIANGLE, QUAD, STAR, HOUSE, MAX_SHAPE};
unsigned char bSelectShape = TRIANGLE;

typedef struct
{
	float red;
	float green;
	float blue;
}color_t;

typedef struct
{
	float x;
	float y;
}vertex2f_t;

typedef struct
{
	color_t color;
	vertex2f_t coordinates;
}vertex_t;

typedef struct
{
	vertex_t vertexOne;
	vertex_t vertexTwo;
	vertex_t vertexThree;
}triangle_t;

typedef struct
{
	vertex_t vertexOne;
	vertex_t vertexTwo;
	vertex_t vertexThree;
	vertex_t vertexFour;
}quad_t;

// Entry-point function
int main(int argc, char* argv[])
{
	// Function declarations
	void initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);

	// code

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Switch Between Multiple Shapes");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	return(0);
}

void initialize(void)
{
	// code
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void resize(int width, int height)
{
	// code
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
	void drawTriangle(triangle_t);
	void drawQuad(quad_t);
	void drawStar(void);
	void drawHouse(void);
	// code
	triangle_t triangle;
	quad_t quad;

	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch (bSelectShape)
	{
	case TRIANGLE:
		triangle.vertexOne.color.red	= 0.0f;
		triangle.vertexOne.color.green	= 0.0f;
		triangle.vertexOne.color.blue	= 1.0f;
		triangle.vertexOne.coordinates.x = 0.0f;
		triangle.vertexOne.coordinates.y = 1.0f;

		triangle.vertexTwo.color.red	= 0.0f;
		triangle.vertexTwo.color.green	= 1.0f;
		triangle.vertexTwo.color.blue	= 0.0f;
		triangle.vertexTwo.coordinates.x = -1.0f;
		triangle.vertexTwo.coordinates.y = -1.0f;

		triangle.vertexThree.color.red = 1.0f;
		triangle.vertexThree.color.green = 0.0f;
		triangle.vertexThree.color.blue = 0.0f;
		triangle.vertexThree.coordinates.x = 1.0f;
		triangle.vertexThree.coordinates.y = -1.0f;

		drawTriangle(triangle);
		break;
	case QUAD:
		quad.vertexOne.color.red = 1.0f;
		quad.vertexOne.color.green = 0.5f;
		quad.vertexOne.color.blue = 0.0f;
		quad.vertexOne.coordinates.x = -0.75f;
		quad.vertexOne.coordinates.y = 0.75f;

		quad.vertexTwo.color.red = 0.5f;
		quad.vertexTwo.color.green = 0.0f;
		quad.vertexTwo.color.blue = 1.0f;
		quad.vertexTwo.coordinates.x = -0.75f;
		quad.vertexTwo.coordinates.y = -0.75f;

		quad.vertexThree.color.red = 1.0f;
		quad.vertexThree.color.green = 0.5f;
		quad.vertexThree.color.blue = 0.0f;
		quad.vertexThree.coordinates.x = 0.75f;
		quad.vertexThree.coordinates.y = -0.75f;

		quad.vertexFour.color.red = 0.5f;
		quad.vertexFour.color.green = 0.0f;
		quad.vertexFour.color.blue = 1.0f;
		quad.vertexFour.coordinates.x = 0.75f;
		quad.vertexFour.coordinates.y = 0.75f;

		drawQuad(quad);
		break;
	case HOUSE:
		drawHouse();
		break;
	case STAR:
	default:
		drawStar();
		break;
	}

	glutSwapBuffers();
}


void drawTriangle(triangle_t triangle)
{
	glBegin(GL_TRIANGLES);

	glColor3f(triangle.vertexOne.color.red, triangle.vertexOne.color.green, triangle.vertexOne.color.blue);
	glVertex2f(triangle.vertexOne.coordinates.x, triangle.vertexOne.coordinates.y);

	glColor3f(triangle.vertexTwo.color.red, triangle.vertexTwo.color.green, triangle.vertexTwo.color.blue);
	glVertex2f(triangle.vertexTwo.coordinates.x, triangle.vertexTwo.coordinates.y);

	glColor3f(triangle.vertexThree.color.red, triangle.vertexThree.color.green, triangle.vertexThree.color.blue);
	glVertex2f(triangle.vertexThree.coordinates.x, triangle.vertexThree.coordinates.y);

	glEnd();
}

void drawQuad(quad_t quad)
{
	glBegin(GL_QUADS);

	glColor3f(quad.vertexOne.color.red, quad.vertexOne.color.green, quad.vertexOne.color.blue);
	glVertex2f(quad.vertexOne.coordinates.x, quad.vertexOne.coordinates.y);

	glColor3f(quad.vertexTwo.color.red, quad.vertexTwo.color.green, quad.vertexTwo.color.blue);
	glVertex2f(quad.vertexTwo.coordinates.x, quad.vertexTwo.coordinates.y);

	glColor3f(quad.vertexThree.color.red, quad.vertexThree.color.green, quad.vertexThree.color.blue);
	glVertex2f(quad.vertexThree.coordinates.x, quad.vertexThree.coordinates.y);

	glColor3f(quad.vertexFour.color.red, quad.vertexFour.color.green, quad.vertexFour.color.blue);
	glVertex2f(quad.vertexFour.coordinates.x, quad.vertexFour.coordinates.y);

	glEnd();
}

void drawStar(void)
{
	triangle_t triangleOne, triangleTwo;

	triangleOne.vertexOne.color.red = 0.0f;
	triangleOne.vertexOne.color.green = 0.0f;
	triangleOne.vertexOne.color.blue = 1.0f;
	triangleOne.vertexOne.coordinates.x = 0.0f;
	triangleOne.vertexOne.coordinates.y = 0.4f;

	triangleOne.vertexTwo.color.red = 0.0f;
	triangleOne.vertexTwo.color.green = 1.0f;
	triangleOne.vertexTwo.color.blue = 0.0f;
	triangleOne.vertexTwo.coordinates.x = -0.4f;
	triangleOne.vertexTwo.coordinates.y = -0.4f;

	triangleOne.vertexThree.color.red = 1.0f;
	triangleOne.vertexThree.color.green = 0.0f;
	triangleOne.vertexThree.color.blue = 0.0f;
	triangleOne.vertexThree.coordinates.x = 0.4f;
	triangleOne.vertexThree.coordinates.y = -0.4f;

	drawTriangle(triangleOne);

	triangleTwo.vertexOne.color.red = 0.0f;
	triangleTwo.vertexOne.color.green = 0.0f;
	triangleTwo.vertexOne.color.blue = 1.0f;
	triangleTwo.vertexOne.coordinates.x = 0.0f;
	triangleTwo.vertexOne.coordinates.y = -0.6f;

	triangleTwo.vertexTwo.color.red = 0.0f;
	triangleTwo.vertexTwo.color.green = 1.0f;
	triangleTwo.vertexTwo.color.blue = 0.0f;
	triangleTwo.vertexTwo.coordinates.x = 0.4f;
	triangleTwo.vertexTwo.coordinates.y = 0.2f;

	triangleTwo.vertexThree.color.red = 1.0f;
	triangleTwo.vertexThree.color.green = 0.0f;
	triangleTwo.vertexThree.color.blue = 0.0f;
	triangleTwo.vertexThree.coordinates.x = -0.4f;
	triangleTwo.vertexThree.coordinates.y = 0.2f;

	drawTriangle(triangleTwo);
}

void drawHouse(void)
{
	triangle_t roof, doorKnob;
	quad_t walls;
	quad_t door;
	quad_t stairOne, stairTwo;

	roof.vertexOne.color.red = 0.75f;
	roof.vertexOne.color.green = 0.2f;
	roof.vertexOne.color.blue = 0.2f;
	roof.vertexOne.coordinates.x = 0.0f;
	roof.vertexOne.coordinates.y = 0.8f;

	roof.vertexTwo.color.red = 0.75f;
	roof.vertexTwo.color.green = 0.4f;
	roof.vertexTwo.color.blue = 0.25f;
	roof.vertexTwo.coordinates.x = -0.8f;
	roof.vertexTwo.coordinates.y = 0.4f;

	roof.vertexThree.color.red = 0.75f;
	roof.vertexThree.color.green = 0.4f;
	roof.vertexThree.color.blue = 0.2f;
	roof.vertexThree.coordinates.x = 0.8f;
	roof.vertexThree.coordinates.y = 0.4f;
	drawTriangle(roof);

	walls.vertexOne.color.red = 1.0f;
	walls.vertexOne.color.green = 0.5f;
	walls.vertexOne.color.blue = 0.0f;
	walls.vertexOne.coordinates.x = -0.6f;
	walls.vertexOne.coordinates.y = 0.4f;

	walls.vertexTwo.color.red = 0.5f;
	walls.vertexTwo.color.green = 0.0f;
	walls.vertexTwo.color.blue = 1.0f;
	walls.vertexTwo.coordinates.x = -0.6f;
	walls.vertexTwo.coordinates.y = -0.7f;

	walls.vertexThree.color.red = 1.0f;
	walls.vertexThree.color.green = 0.5f;
	walls.vertexThree.color.blue = 0.0f;
	walls.vertexThree.coordinates.x = 0.6f;
	walls.vertexThree.coordinates.y = -0.7f;
	
	walls.vertexFour.color.red = 0.5f;
	walls.vertexFour.color.green = 0.0f;
	walls.vertexFour.color.blue = 1.0f;
	walls.vertexFour.coordinates.x = 0.6f;
	walls.vertexFour.coordinates.y = 0.4f;

	drawQuad(walls);

	door.vertexOne.color.red = 1.0f;
	door.vertexOne.color.green = 0.0f;
	door.vertexOne.color.blue = 0.0f;
	door.vertexOne.coordinates.x = -0.2f;
	door.vertexOne.coordinates.y = 0.2f;

	door.vertexTwo.color.red = 0.0f;
	door.vertexTwo.color.green = 0.5f;
	door.vertexTwo.color.blue = 0.5f;
	door.vertexTwo.coordinates.x = -0.2f;
	door.vertexTwo.coordinates.y = -0.5f;

	door.vertexThree.color.red = 0.0f;
	door.vertexThree.color.green = 0.5f;
	door.vertexThree.color.blue = 0.5f;
	door.vertexThree.coordinates.x = 0.2f;
	door.vertexThree.coordinates.y = -0.5f;

	door.vertexFour.color.red = 1.0f;
	door.vertexFour.color.green = 0.0f;
	door.vertexFour.color.blue = 0.0f;
	door.vertexFour.coordinates.x = 0.2f;
	door.vertexFour.coordinates.y = 0.2f;

	drawQuad(door);

	stairOne.vertexOne.color.red = 1.0f;
	stairOne.vertexOne.color.green = 0.0f;
	stairOne.vertexOne.color.blue = 0.0f;
	stairOne.vertexOne.coordinates.x = -0.4f;
	stairOne.vertexOne.coordinates.y = -0.6f;

	stairOne.vertexTwo.color.red = 0.0f;
	stairOne.vertexTwo.color.green = 0.5f;
	stairOne.vertexTwo.color.blue = 0.5f;
	stairOne.vertexTwo.coordinates.x = -0.4f;
	stairOne.vertexTwo.coordinates.y = -0.7f;

	stairOne.vertexThree.color.red = 0.0f;
	stairOne.vertexThree.color.green = 0.5f;
	stairOne.vertexThree.color.blue = 0.5f;
	stairOne.vertexThree.coordinates.x = 0.4f;
	stairOne.vertexThree.coordinates.y = -0.7f;

	stairOne.vertexFour.color.red = 1.0f;
	stairOne.vertexFour.color.green = 0.0f;
	stairOne.vertexFour.color.blue = 0.0f;
	stairOne.vertexFour.coordinates.x = 0.4f;
	stairOne.vertexFour.coordinates.y = -0.6f;

	drawQuad(stairOne);

	stairTwo.vertexOne.color.red = 1.0f;
	stairTwo.vertexOne.color.green = 0.0f;
	stairTwo.vertexOne.color.blue = 0.0f;
	stairTwo.vertexOne.coordinates.x = -0.4f;
	stairTwo.vertexOne.coordinates.y = -0.5f;

	stairTwo.vertexTwo.color.red = 0.0f;
	stairTwo.vertexTwo.color.green = 0.5f;
	stairTwo.vertexTwo.color.blue = 0.5f;
	stairTwo.vertexTwo.coordinates.x = -0.4f;
	stairTwo.vertexTwo.coordinates.y = -0.6f;

	stairTwo.vertexThree.color.red = 0.0f;
	stairTwo.vertexThree.color.green = 0.5f;
	stairTwo.vertexThree.color.blue = 0.5f;
	stairTwo.vertexThree.coordinates.x = 0.4f;
	stairTwo.vertexThree.coordinates.y = -0.6f;

	stairTwo.vertexFour.color.red = 1.0f;
	stairTwo.vertexFour.color.green = 0.0f;
	stairTwo.vertexFour.color.blue = 0.0f;
	stairTwo.vertexFour.coordinates.x = 0.4f;
	stairTwo.vertexFour.coordinates.y = -0.5f;

	drawQuad(stairTwo);

	doorKnob.vertexOne.color.red = 0.0f;
	doorKnob.vertexOne.color.green = 0.0f;
	doorKnob.vertexOne.color.blue = 0.0f;
	doorKnob.vertexOne.coordinates.x = -0.1f;
	doorKnob.vertexOne.coordinates.y = -0.15f;

	doorKnob.vertexTwo.color.red = 0.0f;
	doorKnob.vertexTwo.color.green = 0.0f;
	doorKnob.vertexTwo.color.blue = 0.0f;
	doorKnob.vertexTwo.coordinates.x = -0.12f;
	doorKnob.vertexTwo.coordinates.y = -0.2f;

	doorKnob.vertexThree.color.red = 0.0f;
	doorKnob.vertexThree.color.green = 0.0f;
	doorKnob.vertexThree.color.blue = 0.0f;
	doorKnob.vertexThree.coordinates.x = -0.1f;
	doorKnob.vertexThree.coordinates.y = -0.25f;
	drawTriangle(doorKnob);

}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (bIsFullScreen == false)
		{
			glutFullScreen();
			bIsFullScreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			bIsFullScreen = false;
		}
		break;
	case 'N':
	case 'n':
		bSelectShape = ++bSelectShape % MAX_SHAPE;
		display();
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_RIGHT_BUTTON:
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}












