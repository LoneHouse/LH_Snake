//
//  LHShader.cpp
//  LHSnake
//
//  Created by Victor Privalov on 12/14/16.
//  Copyright © 2016 Victor Privalov. All rights reserved.
//

#include "LHShader.hpp"
#include "LHShaderLoader.hpp"



bool Shaders::Shader::load() {
    auto result = Shaders::LoadShader(this->path, this->type);
    this->id = result;
    return (bool)result;
}



Shaders::Shader::Shader(std::string name, std::string path, GLenum type):
                                        name(name), path(path), type(type)
{
    if (!this->load()) {
        std::cout << "Failed to load Shader:" + name + "at Path:"+ path << "\n";
    }
}

