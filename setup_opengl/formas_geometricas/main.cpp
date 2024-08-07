#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void desenha_triangulo();
void desenha_triangulo_2();
void desenha_projetil();

void fecha_no_escape(GLFWwindow* window);
void inicializa_opengl();
void redimensiona_janela(GLFWwindow* window, int width, int height);
void processa_entrada(GLFWwindow* window);
void atualiza_projetil();

float angulo1 = 0.0f;
float angulo2 = 0.0f;
float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 5.0f;
float cameraSpeed = 0.05f;

// Variáveis do projétil
bool projetilAtivo = false;
float projetilX = 0.0f, projetilY = 0.0f, projetilZ = 0.0f;
float projetilSpeed = 0.1f;

int main() {
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "Ambiente 3D Interativo", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, redimensiona_janela);

    inicializa_opengl();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        processa_entrada(window);
        atualiza_projetil();

        angulo1 += 0.5f;
        if (angulo1 > 360.0f) {
            angulo1 -= 360.0f;
        }

        angulo2 -= 0.3f;
        if (angulo2 < -360.0f) {
            angulo2 += 360.0f;
        }

        glPushMatrix();
        glTranslatef(-cameraX, -cameraY, -cameraZ);

        // Primeiro triângulo
        glPushMatrix();
        glRotatef(angulo1, 0.0f, 1.0f, 0.0f);
        desenha_triangulo();
        glPopMatrix();

        // Segundo triângulo
        glPushMatrix();
        glRotatef(angulo2, 0.0f, 1.0f, 0.0f);
        desenha_triangulo_2();
        glPopMatrix();

        // Desenha o projétil se estiver ativo
        if (projetilAtivo) {
            desenha_projetil();
        }

        glPopMatrix();

        glfwSwapBuffers(window);
        glfwPollEvents();
        fecha_no_escape(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void desenha_triangulo() {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
}

void desenha_triangulo_2() {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
}

void desenha_projetil() {
    glPushMatrix();
    glTranslatef(projetilX, projetilY, projetilZ);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.1f, -0.1f, 0.0f);
    glVertex3f(0.1f, -0.1f, 0.0f);
    glVertex3f(0.1f, 0.1f, 0.0f);
    glVertex3f(-0.1f, 0.1f, 0.0f);
    glEnd();
    glPopMatrix();
}

void fecha_no_escape(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void inicializa_opengl() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 640.0 / 480.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void redimensiona_janela(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void processa_entrada(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraZ -= cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraZ += cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraX -= cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraX += cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        cameraY -= cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        cameraY += cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && !projetilAtivo) {
        // Dispara o projétil da posição da câmera
        projetilX = cameraX;
        projetilY = cameraY;
        projetilZ = -cameraZ;
        projetilAtivo = true;
    }
}

void atualiza_projetil() {
    if (projetilAtivo) {
        projetilZ -= projetilSpeed; // Move o projétil para frente
        if (projetilZ < -10.0f) { // Desativa o projétil se sair da visão
            projetilAtivo = false;
        }
    }
}
