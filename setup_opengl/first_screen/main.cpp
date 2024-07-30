#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void processa_inputs(GLFWwindow *window);

int main(){
    if (!glfwInit()){
        exit(EXIT_FAILURE);
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    // Loop principal
    while (!glfwWindowShouldClose(window)) {
        // Limpa a tela
        glClear(GL_COLOR_BUFFER_BIT);
        // Troca os buffers da janela
        glfwSwapBuffers(window);

        // Processa eventos
        processa_inputs(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void processa_inputs(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == 1){
        glfwSetWindowShouldClose(window, true);
    }
}
