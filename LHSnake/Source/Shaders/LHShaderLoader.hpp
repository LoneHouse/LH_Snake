//
//  LHShaderLoader.hpp
//  LHSnake
//
//  Created by Victor Privalov on 12/14/16.
//  Copyright © 2016 Victor Privalov. All rights reserved.
//

#ifndef LHShaderLoader_hpp
#define LHShaderLoader_hpp

#include <OpenGL/gl.h>


namespace Shaders {
    GLuint LoadShader(const std::string path, GLenum type);
    GLuint CreateProgram(const std::vector<GLenum> shadersID);
    void DeleteProgram(const GLuint programm_id, const std::vector<GLenum> shader_ids);
    bool LinkProgram(const GLenum programID, std::vector<GLenum> shadersID);
}

#endif /* LHShaderLoader_hpp */
