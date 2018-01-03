//
//  LHProgram.cpp
//  LHSnake
//
//  Created by Victor Privalov on 12/20/16.
//  Copyright © 2016 Victor Privalov. All rights reserved.
//

#include "LHProgram.hpp"


std::vector<GLuint> Shaders::Program::GetShaders_ids(std::vector<Shaders::Shader> shaders)
{
    std::vector<GLuint> shader_ids;
    
    for (auto shader:shaders) {
        shader_ids.push_back(shader.id);
    }
    
    return shader_ids;
}

Shaders::Program::Program(std::string name, std::vector<Shaders::Shader> shaders):
                                                    name(name), shaders(shaders)
{
    this->id = Shaders::CreateProgram(GetShaders_ids(this->shaders));
}


void Shaders::Program::deleteProgramm() {
    Shaders::DeleteProgram(this->id, GetShaders_ids(this->shaders));
}
