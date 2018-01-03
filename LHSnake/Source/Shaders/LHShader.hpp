//
//  LHShader.hpp
//  LHSnake
//
//  Created by Victor Privalov on 12/14/16.
//  Copyright © 2016 Victor Privalov. All rights reserved.
//

#ifndef LHShader_hpp
#define LHShader_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <OpenGL/gl.h>

namespace Shaders
{
    class Shader
    {
        
    public:
        GLuint id;
        std::string name;
        std::string path;
        GLenum type;
        
        Shader(std::string name, std::string path, GLenum type);
        
        ~Shader() {
            //std::cout << "im a Shader " + name << ", And i Destroed" << "\n";
        }
        
        bool load();
    };
}

#endif /* LHShader_hpp */
