#pragma region LIBRERÍAS
// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

// Se usan <> para librerías que ya trae el sistema.
// GLEW y GLFW dependen de estas dos librerías, por eso se ponen antes de llamar al GLEW_STATIC.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GLEW_STATIC

// Se usan "" para librerías personalizadas.
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;
#pragma endregion

#pragma region FUNCIONES PARA RUTINA DE DIBUJO
void dibujarTriangulos() {
	glBegin(GL_TRIANGLES);

	// 3f: 3 float
#pragma region Trifuerza
	glColor3f(0.8, 0.8, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);

	glColor3f(0, 0, 0);
	glVertex3f(0.5, 0, 0);
	glVertex3f(0, -1, 0);
	glVertex3f(-0.5, 0, 0);
#pragma endregion

#pragma region Cuadrado
	glColor3f(1, 0, 0);
	glVertex3f(-0.4, 0.5, 0);
	glColor3f(0, 1, 0);
	glVertex3f(-0.4, -0.5, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0.5, -0.4, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0.4, 0.5, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0.4, -0.5, 0);
	glColor3f(1, 0, 0);
	glVertex3f(-0.5, 0.4, 0);

	glColor3f(148.0f / 255.0f, 0, 211.0f / 255.0f);
	glVertex3f(-0.3, 0.3, 0);
	glVertex3f(-0.3, -0.3, 0);
	glVertex3f(0.3, -0.3, 0);

	glColor3f(148.0f / 255.0f, 0, 211.0f / 255.0f);
	glVertex3f(0.3, 0.3, 0);
	glVertex3f(0.3, -0.3, 0);
	glVertex3f(-0.3, 0.3, 0);
#pragma endregion

	glEnd();
}

void dibujarPuntos() {
	glBegin(GL_POINTS);

	glColor3f(0, 0, 0);
	glVertex3f(0.5f, 0.1f, 0.0f);

	glColor3f(1, 1, 1);
	glVertex3f(0.6f, 0.1f, 0.0f);

	glEnd();
}

void dibujarLineas() {
		glBegin(GL_LINES);

		glColor3f(1, 1, 1);
		glVertex3f(-0.2, 0.2, 0);
		glVertex3f(0.2, 0.2, 0);

		glVertex3f(-0.2, -0.1, 0);
		glVertex3f(0.2, -0.1, 0);

		glVertex3f(-0.2, 0.2, 0);
		glVertex3f(-0.2, -0.5, 0);

		glEnd();
}

void dibujarLineaContinua() {
	glBegin(GL_LINE_STRIP);

	glColor3f(1, 1, 1);
	glVertex3f(-0.2, 0.2, 0);
	glVertex3f(-0.2, -0.2, 0);
	glVertex3f(0.2, -0.2, 0);
	glVertex3f(0.2, 0.2, 0);

	glEnd();
}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1, 1, 0);
	glVertex3f(-0.8, -0.8, 0);
	glColor3f(0, 0, 0);
	glVertex3f(0, -0.8, 0);
	glColor3f(0, 0, 0);
	glVertex3f(-0.4, 0, 0);

	glColor3f(0, 0, 0);
	glVertex3f(0.4, 0, 0);

	glColor3f(1, 1, 0);
	glVertex3f(0, 0.8, 0);

	glColor3f(1, 1, 0);
	glVertex3f(0.8, -0.8, 0);

	glEnd();
}

void dibujarPoligono() {
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glVertex3f(-0.8, 0.7, 0);
	glColor3f(0, 0, 0);
	glVertex3f(-0.5, 0.5, 0);
	glColor3f(1, 1, 1);
	glVertex3f(0.5, 0.9, 0);
	glColor3f(0, 0, 0);
	glVertex3f(0, 0.5, 0);
	glColor3f(1, 1, 1);
	glVertex3f(0.2, -0.7, 0);

	glEnd();
}

void dibujar() {
	dibujarTriangulos();
	dibujarPuntos();
	dibujarLineas();
	dibujarLineaContinua();
	dibujarTrianguloContinuo();
	dibujarPoligono();
}
#pragma endregion

#pragma region CASITA FEA
void sol() {
	glBegin(GL_POLYGON);

	glColor3f(249.0f / 255.0f, 1.0f, 97.0f / 255.0f);
	for (int i = 0; i < 360; i++)
	{
		glVertex3f(0.16*cos((double)i*3.14159/180.0)-0.76, 
			0.2*sin((double)i*3.14159/180.0)+0.7, 0);
	}

	glEnd();
}

void casa() {
	// Techo
	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
	glVertex3f(0.1, 0, 0);
	glVertex3f(0.9, 0, 0);
	glVertex3f(0.5, 0.5, 0);
	glEnd();

	// Pared
	glBegin(GL_POLYGON);
		glColor3f(225.0f / 255.0f, 209.0f / 255.0f, 165.0f / 255.0f);
	glVertex3f(0.2, 0, 0);
	glVertex3f(0.2, -0.8, 0);
	glVertex3f(0.8, -0.8, 0);
	glVertex3f(0.8, 0, 0);
	glEnd();

	// Puerta
	glBegin(GL_QUADS);
		glColor3f(0.56, 0.24, 0);
	glVertex3f(0.4, -0.8, 0);
	glVertex3f(0.4, -0.5, 0);
	glVertex3f(0.6, -0.5, 0);
	glVertex3f(0.6, -0.8, 0);
	glEnd();

	// Ventanas
	glBegin(GL_QUADS);
		glColor3f(0.47, 0.87, 1);
	glVertex3f(0.3, -0.35, 0);
	glVertex3f(0.3, -0.15, 0);
	glVertex3f(0.45, -0.15, 0);
	glVertex3f(0.45, -0.35, 0);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.47, 0.87, 1);
	glVertex3f(0.55, -0.35, 0);
	glVertex3f(0.55, -0.15, 0);
	glVertex3f(0.7, -0.15, 0);
	glVertex3f(0.7, -0.35, 0);
	glEnd();

}

void arbol() 
{
	// Tronco
	glBegin(GL_QUADS);
	glColor3f(0.54, 0.34, 0);
	glVertex3f(-0.6, -0.8, 0);
	glVertex3f(-0.4, -0.8, 0);
	glVertex3f(-0.4, -0.2, 0);
	glVertex3f(-0.6, -0.2, 0);
	glEnd();

	// Hojas
	glBegin(GL_POLYGON);
		glColor3f(0, 0.6, 0);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.2*cos((double)i*3.14159 / 180.0) -0.6, 0.2*sin((double)i*3.14159 / 180.0) -.17, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0, 0.6, 0);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.2*cos((double)i*3.14159 / 180.0) -0.4, 0.2*sin((double)i*3.14159 / 180.0) -.11, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0, 0.6, 0);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.2*cos((double)i*3.14159 / 180.0) -0.5, 0.2*sin((double)i*3.14159 / 180.0) +0.05, 0);
	}
	glEnd();
}

void nubes()
{
	// 1
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.2*cos((double)i*3.14159 / 180.0), 0.15*sin((double)i*3.14159 / 180.0) + .7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.2*cos((double)i*3.14159 / 180.0) - 0.2, 0.15*sin((double)i*3.14159 / 180.0) + .7, 0);
	}
	glEnd();

	// 2
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.7, 0.1*sin((double)i*3.14159 / 180.0) + .7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.6, 0.1*sin((double)i*3.14159 / 180.0) + .7, 0);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 360; i++) {
		glVertex3f(0.1*cos((double)i*3.14159 / 180.0) + 0.7, 0.1*sin((double)i*3.14159 / 180.0) + .7, 0);
	}
	glEnd();
}

void pasto()
{
	glBegin(GL_QUADS);
		glColor3f(0.26, 0.69, 0.23);
	glVertex3f(1, -0.8, 0);
	glVertex3f(1, -1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(-1, -0.8, 0);
	glEnd();
}

void picasso() {
	sol();
	casa();
	arbol();
	nubes();
	pasto();
}
#pragma endregion

// Se debe poner esta función siempre para las funciones con los GL_algo
void actualizar() {

}

int main()
{
#pragma region CREAR UN CONTEXTO
	// Un contexto es una ventana de un sistema operativo.
	// OpenGL no gestiona el uso de ventanas.

	// Declaramos apuntador de ventana.
	GLFWwindow * window;

	// Condicionamos en caso de no poder iniciar el GLFW.
	if (!glfwInit()) 
		exit(EXIT_FAILURE);

	// Si GLFW puede iniciar entonces inicia la ventana.
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	// Si puede iniciar GLFW pero no la ventana terminamos la ejecución.
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Establecemos el contexto, donde se mandarán los pixeles generados.
	glfwMakeContextCurrent(window);

	// Una vez establecido el contexto activamos funciones modernas.
	glewExperimental = true;
	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK)
	{
		cout << glewGetErrorString(errorGlew);
	}
#pragma endregion

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

#pragma region CICLO DE DIBUJO (DRAW LOOP)
	//El while establece que mientras la ventana esté abierta realice lo de su interior.
	while (!glfwWindowShouldClose(window)){
		// Establecemos región de dibujo.
		glViewport(0, 0, 1024, 768);
		// Establecemos color de borrado.
		glClearColor(65.0f/255.0f, 231.0f/255.0f, 252.0f/255.0f, 1);
		// Borramos.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Rutina de dibujo.
		//dibujar();
		picasso();
		actualizar();

		// Cambiar los buffers.
		glfwSwapBuffers(window);
		// Reconocer si hay entradas.
		glfwPollEvents();
	}

	// Para destruir ventana y borrarlo/liberarlo de la memoria.
	glfwDestroyWindow(window);
	glfwTerminate();
#pragma endregion

    return 0;
}

