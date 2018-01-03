//
//  LHGame.hpp
//  LHSnake
//
//  Created by Victor Privalov on 12/10/16.
//  Copyright © 2016 Victor Privalov. All rights reserved.
//

#ifndef LHGame_hpp
#define LHGame_hpp

#include "glfw3.h"
#include <OpenGL/gl.h>

#include "LHProgram.hpp"
#include "LHTools.hpp"


namespace LH {
    class Window;
};

namespace LH {
    
    class Game {
        
        std::vector<Shaders::Program> programs;
        
        LH::Window* _window;
        
    public:
        
        const LH::Window &window() { return *_window; }
        
        ~Game();
        Game();
        
        void loadShaders();
        void start();
    };
}

#endif /* LHGame_hpp */
