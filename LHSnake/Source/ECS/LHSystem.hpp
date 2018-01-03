//
//  LHSystem.hpp
//  LHSnake
//
//  Created by Victor Privalov on 3/7/17.
//  Copyright © 2017 Victor Privalov. All rights reserved.
//

#ifndef LHSystem_hpp
#define LHSystem_hpp

#include "LHNode.hpp"

namespace LH { namespace Entity {
    using namespace std;
    using namespace LH;
    
    class ISystem {
    public:
        virtual void start();
        virtual void update(time_t time);
        virtual void stop();
    };
    
    
    class MoveSystem: public ISystem {
        vector<Entity::Position> items;
        
        void start() override {
            
        }
        
        void update(time_t time) override {
            
            for (auto item :items) {
                
//                item.position.x += item.velocity.x * time;
//                item.position.y += item.velocity.y * time;
//                item.position.z += item.velocity.z * time;
                
            }
            
        }
        
        void stop() override {
            
        }
        
    };
    
    class RenderSystem: public ISystem {
        
        vector<Render::Figure> items;
        
        
    };
    
    
} }


#endif /* LHSystem_hpp */
