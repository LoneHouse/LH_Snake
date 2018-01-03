//
//  LHGame.cpp
//  LHSnake
//
//  Created by Victor Privalov on 12/10/16.
//  Copyright © 2016 Victor Privalov. All rights reserved.
//

#include "LHGame.hpp"
#include "LHWindow.hpp"

void LH::Game::loadShaders()
{
    Shaders::Shader vertex("Vertex", "Vertex.vertexshader", GL_VERTEX_SHADER);
    Shaders::Shader fragment("Fragment", "Fragment.fragmentshader", GL_FRAGMENT_SHADER);
    
    Shaders::Program program("Simple Drawer", {vertex, fragment});
    
    this->programs = { program };
    
}

void LH::Game::start()
{
    do {
        _window->clearWindow();
        _window->draw();
        _window->swapBuffers();
        
    } while(!_window->shouldClose());
}

LH::Game::~Game()
{
    delete _window;
    for (auto program: this->programs) {
        program.deleteProgramm();
    }
}

LH::Game::Game()
{
    _window = new Window();
    loadShaders();
    
    //            LHTools::LoadObjectFromFile("Cube.obj");
}

