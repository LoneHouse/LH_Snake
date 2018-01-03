//
//  LHWindow.cpp
//  LHSnake
//
//  Created by Victor Privalov on 5/28/17.
//  Copyright © 2017 Victor Privalov. All rights reserved.
//

#include "LHWindow.hpp"

void LH::Window::ErrorHandler(int error, const char* description)
{
    std::cout << "Error Code" << error << "Description: " << description << std::endl;
}

bool LH::Window::shouldClose()
{
    return !(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

LH::Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

LH::Window::Window()
{
    if(!glfwInit()) {
        std::cout << "Failed to init GLFW!";
        return;
    }
    
    //Setting up errors handling
    glfwSetErrorCallback(ErrorHandler);
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    this->window = glfwCreateWindow(1024, 768, "Snake", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to Create a Window!";
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(window);
    
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    //            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}


void LH::Window::clearWindow()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void LH::Window::draw()
{
    GLsizei width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

void LH::Window::swapBuffers()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
