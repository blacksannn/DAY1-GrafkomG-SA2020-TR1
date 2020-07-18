/*#include<stdlib.h>
#include<gl/glut.h>
float w = 480, h = 480;
float sudut = 0, sx = 0, sy = 0, sz = 0;
void cube() {
	glColor3d(0, 0, 1); glutWireCube(10);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -40);
	glRotatef(sudut, sx, sy, sz);
	cube();
	glutSwapBuffers();
}
void resize(int w1, int h1) {
	glViewport(0, 0, w1, h1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w1 / (float)h1,
		1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45., (GLdouble)w / (GLdouble)h, 1., 300.);
	glMatrixMode(GL_MODELVIEW);
}
void myKeyboard(unsigned char key, int x, int y) {
	if (key == 'x') {
		sx = 1;
		sy = 0;
		sz = 0;
		sudut += 10;
		glutPostRedisplay();
	}
	else if (key == 'y') {
		sx = 0;
		sy = 1;
		sz = 0;
		sudut += 10;
		glutPostRedisplay();
	}
	else if (key == 'z') {
		sx = 0;
		sy = 0;
		sz = 1;
		sudut += 10;
		glutPostRedisplay();
	}
}
void update(int value) {
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}
void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w, h);
	glutCreateWindow("Objek 3D");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
	glutTimerFunc(50, update, 0);
	glutKeyboardFunc(myKeyboard);
	glutMainLoop();
}*/


#include <windows.h>
#include <gl/glut.h>

float angle = 0.0f; // sudut transformasi kamera
float posX = 0.0f;// posisi kamera di sumbu X
float rotX = 0.0f;
float posY = 0.0f;// posisi kamera di sumbu Y
float rotY = 0.0f;
float posZ = 5.0f; // posisi kamera di sumbu Z
float rotZ = -1.0f;
float objectAngleX = 0.0f; // sudut tranformasi obyek di sumbu X
float objectAngleY = 0.0f; // sudut tranformasi obyek di sumbu Y
float objectAngleZ = 0.0f; // sudut tranformasi obyek di sumbu Z
float objectScaleX = 1.0f; // skala perbesaran obyek ke arah X
float objectScaleY = 1.0f; // skala perbesaran obyek ke arah Y
float objectScaleZ = 1.0f; // skala perbesaran obyek ke arah Z
float objectPositionX = 0.0f; // posisi obyek di sumbu X
float objectPositionY = 0.0f; // posisi obyek di sumbu Y
float objectPositionZ = 0.0f; // posisi obyek di sumbu Z

void utama()
{
	glPushMatrix();
	glTranslatef(objectPositionX, objectPositionY, objectPositionZ);
	glScalef(objectScaleX, objectScaleY, objectScaleZ);
	glRotatef(objectAngleY, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glRotatef(objectAngleX, 1.0f, 0.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);// Alas
	glColor3f(0.0f, 255.0f, 255.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);
	glEnd();

	/*glBegin(GL_POLYGON);// Depan
	glColor3f(1.0f, 0.0f, 0.0f);//merah
	glVertex3f(1.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);//kuning
	glVertex3f(-1.f, 1.0f, 0.0f);
	glColor3f(5.0f, 1.0f, 1.0f);//putih
	glVertex3f(1.0f, -1.0f, 1.0f);
	glColor3f(1.0f, 0.0f, 1.0f);//ungu
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();*/


	//glColor3f(0.0f, 1.0f, 0.0f);
	glPopMatrix();
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(posX, posY, posZ, posX + rotX, posY + rotY, posZ + rotZ, 0.0f, 1.0f, 0.0f);
	utama();
	glutSwapBuffers();
}

void init(void)
{
	glClearColor(0.1, 0.1, 0.1, 1.1);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}


void key(unsigned char key, int x, int y)
{
	float nilai = 0.5f;
	switch (key)
	{
		//proses translasi
	case 'w':// translasi ke atas
		objectAngleX -= nilai;
		glutPostRedisplay();
		break;

	case 's':// translasi ke bawah
		objectAngleX += nilai;
		glutPostRedisplay();
		break;

	case 'd':// translasi ke kanan
		objectAngleY += nilai;
		glutPostRedisplay();
		break;

	case 'a':// translasi ke kiri
		objectAngleY -= nilai;
		glutPostRedisplay();
		break;

		//proses skala
	case 'z':// translasi ke depan
		objectPositionZ += nilai;
		glutPostRedisplay();
		break;

	case 'c':// translasi ke belakang
		objectPositionZ -= nilai;
		glutPostRedisplay();
		break;


	case 'q':// zoom in
		posX += rotX * nilai;
		posZ += rotZ * nilai;
		glutPostRedisplay();
		break;


	case 'e':// zoom out
		posX -= rotX * nilai;
		posZ -= rotZ * nilai;
		glutPostRedisplay();
		break;
	}
}


void keyA(int key, int x, int y)
{
	float nilai = 0.1f;

	switch (key)
	{

	case GLUT_KEY_UP://jika menekan panah keatas
		objectPositionY += nilai;
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN://jika menekan panah kebawah
		objectPositionY -= nilai;
		glutPostRedisplay();
		break;

	case GLUT_KEY_LEFT://jika menekan panah kekiri
		objectPositionX -= nilai;
		glutPostRedisplay();
		break;

	case GLUT_KEY_RIGHT://jika menekan panah kekanan
		objectPositionX += nilai;
		glutPostRedisplay();
		break;

	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tugas 4 Grafkom");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyA);
	glutKeyboardFunc(key);
	glutMainLoop();

	return 0;

}