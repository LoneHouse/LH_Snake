//
//  LHProgram.hpp
//  LHSnake
//
//  Created by Victor Privalov on 12/20/16.
//  Copyright © 2016 Victor Privalov. All rights reserved.
//

#ifndef LHProgram_hpp
#define LHProgram_hpp

#include <OpenGL/gl.h>
#include "LHShader.hpp"
#include "LHShaderLoader.hpp"


namespace Shaders
{
    
    class Program
    {
        static std::vector<GLuint> GetShaders_ids(std::vector<Shaders::Shader> shaders);
        
    public:
        GLuint id;
        
        std::string name;
        
        std::vector<Shaders::Shader> shaders;
        
        Program(std::string name, std::vector<Shaders::Shader> shaders);
        
        void deleteProgramm();
        
        ~Program() {
            //std::cout << "im a Programm " + name << ", And i Destroed" << "\n";
        }
        
    };
}

#endif /* LHProgram_hpp */
