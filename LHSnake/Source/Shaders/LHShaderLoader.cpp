//
//  LHShaderLoader.cpp
//  LHSnake
//
//  Created by Victor Privalov on 12/14/16.
//  Copyright © 2016 Victor Privalov. All rights reserved.
//

#include "LHShaderLoader.hpp"

#include <iostream>
#include <fstream>


GLuint Shaders::LoadShader(const std::string path, GLenum type) {
    
    GLuint shaderId = glCreateShader(type);
    
    // Read the Shader code from the file
    std::string shaderCode;
    std::ifstream shaderStream(path, std::ios::in);
    
    std::cout << "Reading shader at Path: " + path << "\n";
    if (shaderStream.is_open()) {
        
        std::string line = "";
        
        while(getline(shaderStream, line)) {
            shaderCode += "\n" + line;
        }
        
        shaderStream.close();
        
    } else {
        std::cout << "Can't read shader at Path: " + path << "\n";
        return 0;
    }
    
    std::cout << "Compiling shader at Path: " + path << "\n";

    char const *shaderCodePointer = shaderCode.c_str();
    glShaderSource(shaderId, 1, &shaderCodePointer, NULL);
    glCompileShader(shaderId);
    
    GLint result = GL_FALSE;
    GLsizei infoLogLength;
    
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
    
    if ( infoLogLength > 0 ){
        char info[infoLogLength];
        glGetShaderInfoLog(shaderId, infoLogLength, NULL, info);
        std::cout << std::string(info) << "\n";
    }
    
    return shaderId;
}

bool Shaders::LinkProgram(const GLenum program_id, std::vector<GLenum> shadersID) {
    
    std::cout << "Linking program: " + std::to_string(program_id) << "\n";
    
    for (auto shader_id: shadersID) {
        glAttachShader(program_id, shader_id);
    }
    glLinkProgram(program_id);
    
    GLint result = GL_FALSE;
    GLsizei infoLogLength;
    
    glGetProgramiv(program_id, GL_LINK_STATUS, &result);
    glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &infoLogLength);
    
    if (infoLogLength > 0) {
        char info[infoLogLength];
        glGetProgramInfoLog(program_id, infoLogLength, NULL, info);
        std::cout << std::string(info) << "\n";
    }

    return result;
}

GLuint Shaders::CreateProgram(const std::vector<GLenum> shadersID) {
    GLuint program_id = glCreateProgram();
    if (!LinkProgram(program_id, shadersID)) {
        std::cout << "Error While Creating Program" << "\n";
        return -1;
    }
    std::cout << "Program created: " + std::to_string(program_id) << "\n";
    return program_id;
}

void Shaders::DeleteProgram(const GLuint program_id ,const std::vector<GLenum> shader_ids) {
    
    for (auto shader_id : shader_ids) {
        glDetachShader(program_id, shader_id);
        glDeleteShader(shader_id);
    }
    glDeleteProgram(program_id);
    
    std::cout << "Program deleted: " + std::to_string(program_id) << "\n";
}




