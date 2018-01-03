//
//  LHScene.hpp
//  LHSnake
//
//  Created by Victor Privalov on 6/10/17.
//  Copyright © 2017 Victor Privalov. All rights reserved.
//

#ifndef LHScene_hpp
#define LHScene_hpp

#include "LHFigure.hpp"

namespace LH { namespace Render {
    
    class Scene
    {
        
    public:
        std::vector<Figure> objects;
        
        Scene(Figure figure): objects({figure}) {}
        
        static Scene testScene() {
            return Scene(Figure::CubeFigure());
        }
        
    };
    
}}

#endif /* LHScene_hpp */
