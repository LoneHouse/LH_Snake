//
//  LHWindow.hpp
//  LHSnake
//
//  Created by Victor Privalov on 5/28/17.
//  Copyright © 2017 Victor Privalov. All rights reserved.
//

#ifndef LHWindow_hpp
#define LHWindow_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "glfw3.h"

namespace LH
{
    
    class Window
    {
        
        GLFWwindow *window;
        
        static void ErrorHandler(int error, const char* description);
        
    public:
        
        virtual ~Window();
        Window();
        
        const GLFWwindow &glfw_window() { return *window; }
        
        bool shouldClose();
    
        void clearWindow();
        
        void swapBuffers();
        
        void draw();
    };
}

#endif /* LHWindow_hpp */
