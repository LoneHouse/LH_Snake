//
//  LHFigure.hpp
//  LHSnake
//
//  Created by Victor Privalov on 1/17/17.
//  Copyright © 2017 Victor Privalov. All rights reserved.
//

#ifndef LHFigure_hpp
#define LHFigure_hpp


#endif /* LHFigure_hpp */



namespace LH
{
    namespace Render
    {
    
    struct Vertex
    {
        std::vector<float> coords()
        {
            return {x, y, z};
        }
        
        float x;
        float y;
        float z;
        
        Vertex(float x, float y, float z): x(x), y(y), z(z) {}
        
        Vertex(std::vector<float> vector): x(vector[0]), y(vector[1]), z(vector[2]) {}
        
        std::string to_Str()
        {
            return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z);
        }
    };
    
    struct Figure {
        
        std::string name;
        std::vector<Vertex> vertices;
        std::vector<Vertex> normales;
        std::vector<Vertex> faces;
        
        Figure(std::string name = "Unnamed",
               std::vector<Vertex> vertices = {},
               std::vector<Vertex> normales = {},
               std::vector<Vertex> faces    = {}): name(name), vertices(vertices), normales(normales), faces(faces) {}
        
        std::vector<float> to_array()
        {
        
            std::vector<float> result;
            
            for(auto vertex: vertices) {
                result.insert(result.end(), vertex.coords().begin(), vertex.coords().end());
            }
            
            return result;
        }
        
        
        static Figure TriAngleFigure()
        {
            std::vector<Vertex> v = {Vertex(-1, -1,0),
                                     Vertex(1, -1, 0),
                                     Vertex(0,  1, 0) };
            return Figure("Simple Triangle", v);
        }
        
        static Figure CubeFigure()
        {
            std::vector<Vertex> v ={Vertex(1, -1,-1),
                                    Vertex(1, -1, 1),
                                    Vertex(-1,-1, 1),
                                    Vertex(-1,-1,-1),
                                    Vertex(1 , 1,-1),
                                    Vertex(1 , 1, 1),
                                    Vertex(-1, 1, 1),
                                    Vertex(-1, 1,-1) };
            
            std::vector<Vertex>vn ={Vertex(0, -1, 0),
                                    Vertex(0,  1, 0),
                                    Vertex(1,  0, 0),
                                    Vertex(0,  0, 1),
                                    Vertex(1 , 0, 0),
                                    Vertex(0 , 0,-1) };
            
            std::vector<Vertex> f ={Vertex(1,  0, 1),
                                    Vertex(0,  1, 0),
                                    Vertex(1,  0, 0),
                                    Vertex(0,  0, 1),
                                    Vertex(1,  0, 0),
                                    Vertex(0,  0,-1) };
            
            return Figure("Simple Cube", v, vn, f);
        }
    };

} }
