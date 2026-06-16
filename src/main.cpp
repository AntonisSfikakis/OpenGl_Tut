#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main() {
  glfwInit();
  // we set the open gl profile , to a required version of open gl
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // set core profile -> access to subset of open gl features
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  // create a window object
  GLFWwindow *window = glfwCreateWindow(800, 600, "First window", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // load the address of OpenGL fuction pointers (os specific)
  //  Now we have context. If it was before window init it wouldnt load
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // tell OpenGl the size of the window and how to display it
  // first 2 args set the location of the left 2 corner the rest 2 the height
  // and width
  glViewport(0, 0, 800, 600);

  // whenever the window buffer changes , call frame_buffer_callback
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // render loop
  while (!glfwWindowShouldClose(window)) {
    // input
    processInput(window);

    // render 
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // check call events and swap front-back buffer
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
