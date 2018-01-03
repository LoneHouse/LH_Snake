//
//  LHNode.hpp
//  LHSnake
//
//  Created by Victor Privalov on 3/7/17.
//  Copyright © 2017 Victor Privalov. All rights reserved.
//

#ifndef LHNode_hpp
#define LHNode_hpp

#include "LHGeometry.hpp"
#include "LHFigure.hpp"

namespace LH { namespace Entity {
    using namespace LH;
    
    struct INode {
        std::string name;
    };
    
    
    struct Node:INode {
        
    };
    
    struct Position: public INode {
//        Vector position;
//        Velocity velocity;
    };
    
    struct Figure: public INode {
        Render::Figure figure;
    };
    
    
} }

#endif /* LHNode_hpp */
